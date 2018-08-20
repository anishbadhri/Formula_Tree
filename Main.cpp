#include "Formula.h"
#include "FormulaSpec.h"

//Fully Paranthesized Input separated by spaces
//( ( a v c ) ^ ( ! b ) )

int main() {
	formulaSpec F;
	F.addBinaryOperator("^",3);
	F.addBinaryOperator("v",3);
	F.addUnaryOperator("!",2);
	formulaTree f(F);
        bool x = f.parse("( a ^ ( ( ! b ) v c ) )");
        cout<<x<<endl;
}

