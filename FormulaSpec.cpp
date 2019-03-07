#include "FormulaSpec.h"

bool formulaSpec::addUnaryOperator(string s, int p,int a){	//Operator,Precedence
	if(s=="(" || s==")" || s=="{" || s=="}" || s=="[" || s=="]")
		return 0;
	if(!isUnary(s) && !isBinary(s)){
		operator_list[s[0]].arity = 1;
    operator_list[s[0]].precedence = p;
    operator_list[s[0]].associativity = a;
    operator_list_set.insert(s);
  }
	else return 0;
	return 1;
}

bool formulaSpec::addBinaryOperator(string s, int p,int a){	//Operator,Precedence
	if(s=="(" || s==")" || s=="{" || s=="}" || s=="[" || s=="]")
		return 0;
	if(!isUnary(s) && !isBinary(s)){
    operator_list[s[0]].arity = 2;
    operator_list[s[0]].precedence = p;
    operator_list[s[0]].associativity = a;	
    operator_list_set.insert(s);
  }
	else return 0;
	return 1;
}

