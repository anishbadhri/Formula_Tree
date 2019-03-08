#include "FormulaTree/Formula.h"

//Fully Paranthesized Input separated by spaces
//( ( a v c ) ^ ( ! b ) )

int main() {
	formulaSpec F;
	F.addOperator("^",2,3,0);
	F.addOperator("v",2,3,0);
	F.addOperator("!",1,2,0);
	F.addOperator("?",3,3,0);
	formulaTree f(F);

	bool x = f.parse("( ( ( a ^ c ) ^ ( ( b v c ) v d ) ) ? a d )");
	//f.compressTree();
	cout<<f.printWalk()<<endl;
}

