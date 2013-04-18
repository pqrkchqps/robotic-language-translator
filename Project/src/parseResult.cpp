/* ParseResult: a simple object for holding the result of a parse.

   Author: Eric Van Wyk

   Last modified: March 5, 2013.
*/

#include "parseResult.h"

using namespace std ;

/*********************************************************************
	
	We modifed ParseResult and created ExprResult, NullExprResult, 
	and ExtendedExprResult to make an interface for them. The purpose
	of making an interface was to make the function easier to implement. 

*********************************************************************/

ParseResult::ParseResult ( ) {
    this->setErrors("");
    this->setOK(true) ;
    this->setTerminal(noMatch);
	 this->setLexeme("");
	 this->setNext(NULL);
    // ast = NULL ; 
}

ExprResult::ExprResult(string lexeme){
    this->setErrors ("") ;
    this->setOK(true);
    this->setTerminal(expr);
	 this->setLexeme (lexeme);
	 this->setNext(NULL);
}

NullExprResult::NullExprResult(){
    this->setErrors("") ;
    this->setOK(true) ;
    this->setTerminal(nullExpr);
	 this->setLexeme("0");
	 this->setNext(NULL);
}

ExtendedExprResult::ExtendedExprResult(string lexeme){
    this->setErrors("");
    this->setOK(true);
    this->setTerminal(extendedExpr);
	 this->setLexeme(lexeme);
	 this->setNext(NULL);
}
