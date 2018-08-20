#ifndef BOOLEXPR_CLASS

#define BOOLEXPR_CLASS

#include <z3++.h>
#include "Formula.h"

using namespace z3;

class booleanExpr : public formulaTree{
	public:
		booleanExpr(){
			if(init_op==false){
				addOperators();
			}
			expression="";
			converted=NULL;
		}

		booleanExpr(string def){
			if(init_op==false){
				addOperators();
			}
			expression=def;
			converted=NULL;
		}

		inline static void setInitOp(bool value){ init_op=value; }
		expr getZ3Expr(context&);


	private:
		static bool init_op;
		string expression;
		expr *converted;
		map<string, expr*> name_table;

		void addOperators();
		expr extract(tree*, context&);

};

bool booleanExpr::init_op=false;

#endif

