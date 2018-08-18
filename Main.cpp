#include "Formula.h"

//Fully Paranthesized Input separated by spaces
//( ( a v c ) ^ ( ! b ) )

int main() {
	formulaTree F;
	F.addBinaryOperator("^",3);
	F.addBinaryOperator("v",3);
	F.addUnaryOperator("!",2);
}

