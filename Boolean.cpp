#include "Boolean.h"


void booleanExpr::addOperators(){
	// setInitOp(true);
	spec.addBinaryOperator("^", 3);
	spec.addBinaryOperator("v", 3);
	spec.addUnaryOperator("!", 2);
}

expr booleanExpr::extract(tree* cur, context& ctx){
	if(spec.isVariable(cur->value)){
		if(name_table.find(cur->value)!=name_table.end()){
			return *name_table[cur->value];
		}
		name_table[cur->value]=new expr(ctx);
		*name_table[cur->value]=(ctx.bool_const((cur->value).c_str()));
		return *name_table[cur->value];

	}else if(spec.isUnary(cur->value)){
		expr x=extract(cur->c[0], ctx);
		return  (!x);
	}else{
		expr x=extract(cur->c[0], ctx);
		expr y=extract(cur->c[1], ctx);
		if(cur->value=="^") return (x && y);
		else return (x || y);
	}
}

expr booleanExpr::getZ3Expr(context& ctx){
	if(converted!=NULL) return *converted;
	converted=new expr(ctx);
	// name_table=new expr_vector(ctx);
	parse(expression);
	(*converted)=extract(root, ctx);
	return *converted;
}

int main(){

	context ctx;
	booleanExpr b("( a ^ ( ( ! b ) v c ) )");
	cout << b.getZ3Expr(ctx) << endl;
}