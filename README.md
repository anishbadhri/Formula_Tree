# Formula Tree
A class which constructs a Formula Tree from a given expression for custom Unary and Binary Operator

## Running the File
In your Main.cpp<br>
Include the header<br>
```
#include "FormulaTree/Formula.h"
```
Compile the files with<br>
```
g++ FormulaTree/FormulaSpec.cpp FormulaTree/Formula.cpp Main.cpp
```

## Expression Requirements
* Fully paranthesized expression
* Spaces between any 2 tokens

## Types and Functions
### formulaSpec
* **int getArity(string operator)**  
Returns arity of operator (1 if unary, 2 if binary)  
* **int getPrecedence(string operator)**  
Returns precedence of operator  
* **bool isEmpty()**  
Returns TRUE if no operator has been defined for given instance of formulaSpec  
* **bool isVariable(string s)**  
Returns TRUE if input string is not an operator  
* **bool addOperator(string operator,int arity,int precedence,int associativity)**  
Adds operator to formulaSpec and returns true on success  
* **int getHash(string operator)**
Returns a string hash of operator which lies in the range 0 to 100002
### formulaTree  
* **formulaTree(formulaSpec spec)**  
Initializes formulaTree with the given formulaSpec  
* **string matchingParantheses(string parantheses)**  
Returns corresponding matching parantheses  
* **bool openParantheses(string parantheses)**  
Returns TRUE if the input is an opening parantheses  
* **bool closeParantheses(string parantheses)**  
Returns TRUE if the input is a closing parantheses  
* **bool parse(string expression)**  
Parses input expression and constructs tree. Returns TRUE if parsing is successful  
* **string printWalk()**  
Prints Euler Walk of the tree from root  