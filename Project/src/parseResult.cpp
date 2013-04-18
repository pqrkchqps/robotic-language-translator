/* ParseResult: a simple object for holding the result of a parse.

   Author: Eric Van Wyk

   Last modified: March 5, 2013.
*/

#include "parseResult.h"

using namespace std ;

ParseResult::ParseResult ( ) {
    this->setErrors("");
    this->setOK(true) ;
    this->ast = NULL ; 
};

this->astNode::this->astNode() {
    this->setTerminal(noMatch);
    this->setLexeme("");
    this->setNext(NULL);
    this->next = NULL;
};
ExprResult::ExprResult(string lexeme){
    this->setTerminal(expr);
	 this->setLexeme (lexeme);
	 this->setNext(NULL);
    this->next = NULL;
};

IntConstResult::IntConstResult(string lexeme){
    this->setTerminal(intConst);
	 this->setLexeme (lexeme);
	 this->setNext(NULL);
    this->next = NULL;
};


NullExprResult::NullExprResult(){
    this->setTerminal(nullExpr);
	 this->setLexeme("0");
	 this->setNext(NULL);
    this->next = NULL;
};

ExtendedExprResult::ExtendedExprResult(string lexeme){
    this->setTerminal(extendedExpr);
    this->setLexeme(lexeme);
    this->setNext(NULL);
    this->next = NULL;
};

AdditionExprResult::AdditionExprResult(){
    this->setTerminal(plusSign);
    this->setLexeme("+");
    this->setNext(NULL);
    this->next = NULL;
};

Platform::Platform (string var_name ) {
    this->setTerminal(platformKwd);
	 this->setLexeme(var_name);
	 this->setNext(NULL);
    this->next = NULL ; 
};

Decls::Decls(ParseResult left, ParseResult right){
    this->setTerminal(noMatch);
	 this->setLexeme("");
	 this->setNext(NULL);
    this->next = NULL ; 

};

States::States(){
    this->setTerminal(stateKwd);
	 this->setLexeme("");
	 this->setNext(NULL);
    this->next = NULL ; 
};

Program::Program(std::string name, Platform* p, Decls* d, States* s){
    this->setTerminal(noMatch);
	 this->setLexeme("");
	 this->setNext(NULL);
    this->next = NULL;
};
