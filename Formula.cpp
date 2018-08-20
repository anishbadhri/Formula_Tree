#include "Formula.h"


bool formulaTree::parse(string exp){	//Tree Construct Function
	if(spec.isEmpty()) return 0;
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
				if(spec.isUnary(s)){	//Checking if top of stack is Unary Operator
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
		if(spec.isUnary(cur_op) || spec.isBinary(cur_op)){
			//Checking if Operator and Pushing into Operator Stack
			float cur_precedence;
			if(spec.isUnary(cur_op))
				cur_precedence = spec.getUPrecedence(cur_op) + 0.5; //Adding 0.5 as Unary has greater precedence than Binary. Can be removed is assuming equal precendence
			else
				cur_precedence = spec.getBPrecedence(cur_op);
			while(!operator_stack.empty()){
				string s = operator_stack.top();
				if(spec.isUnary(s)){
					if(spec.getUPrecedence(s) >= cur_precedence - 0.5){ //Subtracting 0.5 as comparison between two unary operators
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
					if(spec.getBPrecedence(s) >= cur_precedence){ 
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
	if(formula_stack.size()==1 && operator_stack.size()==0){
		root=formula_stack.top();
		formula_stack.pop();
		return 1;
	}
	return 0;
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

