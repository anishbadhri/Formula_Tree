#include "FormulaSpec.h"

bool formulaSpec::addOperator(std::string s,int arity,int precedence){
	if(s=="(" || s==")" || s=="{" || s=="}" || s=="[" || s=="]")
		return 0;
	if(getArity(s)==-1){
		initialized_spec = true;
		operator_list[getHash(s)].arity = arity;
		operator_list[getHash(s)].precedence = precedence;
		operator_list_set.insert(s);
	}
	else return 0;
}