#include "FormulaSpec.h"

bool formulaSpec::addUnaryOperator(string s, int p){	//Operator,Precedence
	if(s=="(" || s==")" || s=="{" || s=="}" || s=="[" || s=="]")
		return 0;
	if(!isUnary(s) && !isBinary(s))
		unary_precedence[s] = p;
	else return 0;
	return 1;
}

bool formulaSpec::addBinaryOperator(string s, int p){	//Operator,Precedence
	if(s=="(" || s==")" || s=="{" || s=="}" || s=="[" || s=="]")
		return 0;
	if(!isUnary(s) && !isBinary(s))
		binary_precedence[s] = p;
	else return 0;
	return 1;
}