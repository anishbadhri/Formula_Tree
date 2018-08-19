#include "Formula.h"


bool formulaTree::parse(string exp){	//Tree Construct Function
	if(unary_precedence.size()== 0 && binary_precedence.size() == 0)
		return 0;
	stack<tree*> formula_stack;
	stack<string> operator_stack;
	stringstream str(exp);
	string cur_op;
	while(str>>cur_op){
		if(openParantheses(cur_op)){	//Pushing Open Parantheses
			operator_stack.push(cur_op);
			continue;
		}
		if(closeParantheses(cur_op)){	//Pop Operators and construct tree here
			while(!operator_stack.empty() && operator_stack.top() != matchingParantheses(cur_op)){
				string s = operator_stack.top();
				if(isUnary(s)){	//Checking if top of stack is Unary Operator
					operator_stack.pop();
					if(formula_stack.size()<1)
						return 0;
					tree* cur_formula = formula_stack.top();
					formula_stack.pop();	//Extracting only one formula if top of stack is unary
					tree* node = new tree(s);
					node->c.push_back(cur_formula);
					formula_stack.push(node);
				}
				else{	//Top of stack is binary
					operator_stack.pop();
					if(formula_stack.size()<2)
						return 0;
					tree* cur_formula_1 = formula_stack.top();
					formula_stack.pop();
					tree* cur_formula_2 = formula_stack.top(); 
					formula_stack.pop(); //Extracting two formula if top of stack is binary
					tree* node = new tree(s);
					node->c.push_back(cur_formula_2);
					node->c.push_back(cur_formula_1);
					formula_stack.push(node);
				}
			}
			if(operator_stack.empty())
				return 0;	//If no matching open bracket is found in stacks
			operator_stack.pop();
			continue;
		}
		if(isUnary(cur_op) || isBinary(cur_op)){
			//Checking if Operator and Pushing into Operator Stack
			float cur_precedence;
			if(isUnary(cur_op))
				cur_precedence = unary_precedence[cur_op] + 0.5; //Adding 0.5 as Unary has greater precedence than Binary. Can be removed is assuming equal precendence
			else
				cur_precedence = binary_precedence[cur_op];
			while(!operator_stack.empty()){
				string s = operator_stack.top();
				if(isUnary(s)){
					if(unary_precedence[s] >= cur_precedence - 0.5){ //Subtracting 0.5 as comparison between two unary operators
						operator_stack.pop();
						if(formula_stack.size()<1)
							return 0;
						tree* cur_formula = formula_stack.top();
						formula_stack.pop();
						tree* node = new tree(s);
						node->c.push_back(cur_formula);
						formula_stack.push(node);
					}
					else
						break;
				}
				else{
					if(binary_precedence[s] >= cur_precedence){ 
						operator_stack.pop();
						if(formula_stack.size()<2)
							return 0;
						tree* cur_formula_1 = formula_stack.top();
						formula_stack.pop();
						tree* cur_formula_2 = formula_stack.top();
						formula_stack.pop();
						tree* node = new tree(s);
						node->c.push_back(cur_formula_2);
						node->c.push_back(cur_formula_1);
						formula_stack.push(node);
					}
					else
						break;
				}
			}
			operator_stack.push(cur_op);
			continue;
		}
		//For all other cases(Current string is a variable)
		tree* node = new tree(cur_op);
		formula_stack.push(node);
	}
	if(formula_stack.size()==1 && operator_stack.size()==0)
		return 1;
	return 0;
}

bool formulaTree::addUnaryOperator(string s, int p){	//Operator,Precedence
	if(s=="(" || s==")" || s=="{" || s=="}" || s=="[" || s=="]")
		return 0;
	if(!isUnary(s) && !isBinary(s))
		unary_precedence[s] = p;
	else return 0;
	return 1;
}

bool formulaTree::addBinaryOperator(string s, int p){	//Operator,Precedence
	if(s=="(" || s==")" || s=="{" || s=="}" || s=="[" || s=="]")
		return 0;
	if(!isUnary(s) && !isBinary(s))
		binary_precedence[s] = p;
	else return 0;
	return 1;
}

string formulaTree::matchingParantheses(string s){	//Ease for checking Matching Parantheses
	if(s=="(") return ")";
	if(s=="{") return "}";
	if(s=="[") return "]";
	if(s=="]") return "[";
	if(s=="}") return "{";
	if(s==")") return "(";
	return "";
}

