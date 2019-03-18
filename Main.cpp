#include "FormulaTree/Formula.h"

//Fully Paranthesized Input separated by spaces
//( ( a v c ) ^ ( ! b ) )
using namespace std;
int main() {
	formulaSpec F;
	F.addOperator("^",2,3);
	F.addOperator("v",2,3);
	F.addOperator("!",1,2);
	F.addOperator("?",3,3);
	formulaTree f(F);

	bool x = f.parse("( ( ( a ^ c ) ^ ( ( b v c ) v d ) ) ? a d )");
	if(!x){
		cout<<"Failed Parsing\n";
		return 0;
	}
	//f.compressTree();
	cout<<f.printWalk()<<endl;
}

