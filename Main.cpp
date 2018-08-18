#include "Formula.h"
//Fully Paranthesized Input separated by spaces
//( ( a v c ) ^ ( ! b ) )
int main(){
	formula_tree F;
	F.add_binary_operator("^",3);
	F.add_binary_operator("v",3);
	F.add_unary_operator("!",2);
}