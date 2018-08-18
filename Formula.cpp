#include "Formula.h"
formula_tree::formula_tree(){

}
bool formula_tree::parse(string s){	//Tree Construct Function
	if(unary_precedence.size()== 0 && binary_precedence.size() == 0)
		return 0;

	return 1;
}
bool formula_tree::add_unary_operator(string s,int p){	//Operator,Precedence
	if(s=="(" || s==")" || s=="{" || s=="}" || s=="[" || s=="]")
		return 0;
	if(unary_precedence.find(s)==unary_precedence.end() && binary_precedence.find(s)==binary_precedence.end())
		unary_precedence[s] = p;
	else
		return 0;
	return 1;
}
bool formula_tree::add_binary_operator(string s,int p){	//Operator,Precedence
	if(unary_precedence.find(s)==unary_precedence.end() && binary_precedence.find(s)==binary_precedence.end())
		binary_precedence[s] = p;
	else
		return 0;
	return 1;
}
string formula_tree::matching_parantheses(string s){	//Ease for checking Matching Parantheses
	if(s=="(")
		return ")";
	if(s=="{")
		return "}";
	if(s=="[")
		return "]";
	if(s=="]")
		return "[";
	if(s=="}")
		return "{";
	if(s==")")
		return "(";
	return "";
}