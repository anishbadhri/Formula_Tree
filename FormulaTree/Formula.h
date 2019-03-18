#ifndef FORMULA_CLASS

#define matchingBrackets matchingParantheses
#define FORMULA_CLASS

#include <sstream>
#include <vector>
#include <algorithm>
#include <stack>
#include "FormulaSpec.h"
class formulaTree{
public:
	formulaTree(){}
	formulaTree(formulaSpec sp){
		spec=sp;
	}
	//Construction Operations
	static std::string matchingParantheses(std::string s);
	inline static bool openParantheses(std::string s){ return s=="("||s=="{"||s=="["; }
	inline static bool closeParantheses(std::string s){ return s==")"||s=="}"||s=="]"; };
	bool parse(std::string s);
	//Test Operations
	std::string printWalk(){ std::string s = printWalk(root); return s;};
protected:
	class tree{
	public:
		tree(std::string s){
			value = s;
			subtree_expression = s;
		}
		std::vector<tree*> c;
		std::string value;
		std::string subtree_expression;
	};
	tree *root;
	formulaSpec spec;
	std::string printWalk(tree* cur);
};

#endif

