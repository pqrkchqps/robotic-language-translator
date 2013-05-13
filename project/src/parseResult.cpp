/* ParseResult: a simple object for holding the result of a parse.

   Author: Eric Van Wyk

   Last modified: March 5, 2013.
*/

#include "parseResult.h"

using namespace std ;

/*********************************************************************
	
	We modifed ParseResult and created ExprResult, IntConstResult,
	NullExprResult, ExtendedExprResult, AdditionExprResult, Platform, 
	Decls, State, Program to make an interface for them. The purpose
	of making an interface was to make the function easier to implement. 

*********************************************************************/
ParseResult::ParseResult(){
    this->setErrors("");
    this->setOK(true) ;
    this->ast = NULL ; 
};
