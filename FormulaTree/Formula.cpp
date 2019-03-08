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
				assert(1==0);	//If no matching open bracket is found in stack
			operator_stack.pop();
			continue;
		}
		if(!spec.isVariable(cur_op)){
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

// bool formulaTree::compressTree(){
// 	assignSubtreeExpression(root);
// 	subtree_hash.clear();
// 	constructFormulaDAG(root);
// }
// bool formulaTree::assignSubtreeExpression(tree* cur){
// 	if(cur->c.size()==0){
// 		cur->subtree_expression = cur->value;
// 		return 1;
// 	}
// 	cur->subtree_expression = "( " + cur->c[0]->value;
// 	for(int i=1;i<cur->c.size();i++){
// 		cur->subtree_expression += " " + cur->value + " " + cur->c[i]->value;
// 	}
// 	cur->subtree_expression += " )";
// 	return 1;
// }
// bool formulaTree::constructFormulaDAG(tree* cur){
// 	if(cur->c.size()==0)
// 		return 1;
// 	for(int i = 0;i<cur->c.size();i++)
// 		constructFormulaDAG(cur->c[i]);
// 	string assgn_value;
// 	tree* temp;
// 	for(int i=0;i<cur->c.size();i++){
// 		if(subtree_hash.find(cur->c[i]->value)!=subtree_hash.end()){
// 			assgn_value = cur->c[i]->value;
// 			temp = cur->c[i];
// 			cur->c[i] = subtree_hash[assgn_value];
// 			delete temp;
// 		}
// 		else{
// 			subtree_hash[cur->c[i]->value] = cur->c[i];
// 		}
// 	}
// 	return 1;
// }
string formulaTree::printWalk(tree* cur){
	string s;
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