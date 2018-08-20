#ifndef BOOLEXPR_CLASS

#define BOOLEXPR_CLASS

#include <z3++.h>
#include "Formula.cpp"

using namespace z3;

class booleanExpr : public formulaTree{
	public:

		// static bool init_op;
		
		booleanExpr(){
			// if(init_op==false){
				addOperators();
			// }
			expression="";
			converted=NULL;
		}

		booleanExpr(string def){
			// if(init_op==false){
				addOperators();
			// }
			expression=def;
			converted=NULL;
		}

		// inline static void setInitOp(bool value){ init_op=value; }
		expr getZ3Expr(context&);


	private:

		string expression;
		expr *converted;
		map<string, expr*> name_table;

		void addOperators();
		expr extract(tree*, context&);

};

#endif

