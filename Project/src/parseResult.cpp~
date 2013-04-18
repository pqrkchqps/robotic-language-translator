/* ParseResult: a simple object for holding the result of a parse.

   Author: Eric Van Wyk

   Last modified: March 5, 2013.
*/

#include "parseResult.h"

using namespace std ;

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
