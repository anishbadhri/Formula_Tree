#include "Formula.h"


bool formulaTree::parse(string exp){	//Tree Construct Function
	if(unary_precedence.size()== 0 && binary_precedence.size() == 0)
		return 0;
	stack<tree*> formula_stack;
	stack<string> operator_stack;
	stringstream str(exp);
	string cur_op;
	while(str>>exp){

	}
	return 1;
}

bool formulaTree::addUnaryOperator(string s, int p){	//Operator,Precedence
	if(s=="(" || s==")" || s=="{" || s=="}" || s=="[" || s=="]")
		return 0;
	if(unary_precedence.find(s)==unary_precedence.end() && binary_precedence.find(s)==binary_precedence.end())
		unary_precedence[s] = p;
	else return 0;
	return 1;
}

bool formulaTree::addBinaryOperator(string s, int p){	//Operator,Precedence
	if(unary_precedence.find(s)==unary_precedence.end() && binary_precedence.find(s)==binary_precedence.end())
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

