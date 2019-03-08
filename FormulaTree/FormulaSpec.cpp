#include "FormulaSpec.h"

bool formulaSpec::addOperator(string s,int arity,int precedence,int associativity){
	if(s=="(" || s==")" || s=="{" || s=="}" || s=="[" || s=="]")
		return 0;
	if(getArity(s)==-1){
		operator_list[s[0]].arity = arity;
		operator_list[s[0]].precedence = precedence;	
		operator_list[s[0]].associativity = associativity;
		operator_list_set.insert(s);
	}
	else return 0;
}