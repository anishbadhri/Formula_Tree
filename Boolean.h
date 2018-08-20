#ifndef BOOLEXPR_CLASS

#define BOOLEXPR_CLASS

#include "Formula.h"

class booleanExpr : public formulaTree{
	public:
		booleanExpr(){
			if(init_op==false){
				addOperators();
			}
			expression="";
		}

		booleanExpr(string def){
			if(init_op==false){
				addOperators();
			}
			expression=def;			
		}




	protected:

	private:
		string expression;
		static bool init_op;
		void addOperators();

};

#endif