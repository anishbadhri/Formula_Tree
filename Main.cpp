#include "Formula.h"

//Fully Paranthesized Input separated by spaces
//( ( a v c ) ^ ( ! b ) )

int main() {
	formulaSpec F;
	F.addBinaryOperator("^",3,0);
	F.addBinaryOperator("v",3,0);
	F.addUnaryOperator("!",2,0);
	formulaTree f(F);
	bool x = f.parse("( ( a ^ c ) ^ ( ( b v c ) v d ) )");
	cout<<f.inOrder()<<endl;
	cout<<f.preOrder()<<endl;
	cout<<f.postOrder()<<endl;
}

