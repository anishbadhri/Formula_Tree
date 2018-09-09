#include "Boolean.h"


void booleanExpr::addOperators(){
	setInitOp(true);
	spec.addBinaryOperator("^", 3);
	spec.addBinaryOperator("v", 3);
	spec.addUnaryOperator("!", 2);
}

expr booleanExpr::extract(tree* cur, context& ctx){
	if(spec.isVariable(cur->value)){
		// Variable in the tree -> leaf													
		if(name_table.find(cur->value)!=name_table.end()){
			// if variable is already declared in the context
			return *name_table[cur->value];
		}
		// making new variable in this context
		name_table[cur->value]=new expr(ctx);
		*name_table[cur->value]=(ctx.bool_const((cur->value).c_str()));
		return *name_table[cur->value];

	}else if(spec.isUnary(cur->value)){
		// unary operator (only one)
		expr x=extract(cur->c[0], ctx);
		return  (!x);
	}else{
		// binary (two possiblities)
		expr x=extract(cur->c[0], ctx);
		expr y=extract(cur->c[1], ctx);
		if(cur->value=="^") return (x && y);
		else return (x || y);
	}
}

expr booleanExpr::getZ3Expr(context& ctx){
	if(converted!=NULL) return *converted;
	converted=new expr(ctx);
	parse(expression);
	(*converted)=extract(root, ctx);
	return *converted;
}

// int main(){

// 	context ctx;
// 	booleanExpr b("( a ^ ( ( ! b ) v c ) )");
// 	cout << b.getZ3Expr(ctx) << endl;
// }