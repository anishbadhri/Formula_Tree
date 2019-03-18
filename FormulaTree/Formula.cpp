#include "Formula.h"
// using namespace std;
bool formulaTree::parse(std::string exp){	//Tree Construct Function
	if(spec.isEmpty()){ return 0; }
	std::stack<tree*> formula_stack;
	std::stack<std::string> operator_stack;
	std::stringstream str(exp);
	std::string cur_op;
	while(str>>cur_op){
		if(openParantheses(cur_op)){	//Pushing Open Parantheses
			operator_stack.push(cur_op);
			continue;
		}
		if(closeParantheses(cur_op)){	//Pop Operators and construct tree here
			while(!operator_stack.empty() && operator_stack.top() != matchingParantheses(cur_op)){
				std::string s = operator_stack.top();
				int cur_arity = spec.getArity(s);
				operator_stack.pop();
				assert(formula_stack.size()>=cur_arity);
				tree* node = new tree(s);
				for(int i=0;i<cur_arity;i++){
					tree* cur_formula = formula_stack.top();
					node->c.push_back(cur_formula);
					formula_stack.pop();
				}
				reverse(node->c.begin(),node->c.end());
				formula_stack.push(node);
			}
			if(operator_stack.empty())
				return 0;	//If no matching open bracket is found in stack
			operator_stack.pop();
			continue;
		}
		if(!spec.isVariable(cur_op)){
			operator_stack.push(cur_op);
			continue;
		}
		//For all other cases(Current std::string is a variable)
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

std::string formulaTree::matchingParantheses(std::string s){	//Ease for checking Matching Parantheses
	if(s=="(") return ")";
	if(s=="{") return "}";
	if(s=="[") return "]";
	if(s=="]") return "[";
	if(s=="}") return "{";
	if(s==")") return "(";
	return "";
}

std::string formulaTree::printWalk(tree* cur){
	std::string s;
	if(cur->c.size() == 0)
		return cur->value;
	s = cur->value;
	for(int i=0;i<cur->c.size();i++){
		s +=" ";
		s += printWalk(cur->c[i]);
		s += " " + cur->value;
	}
	return s;
}