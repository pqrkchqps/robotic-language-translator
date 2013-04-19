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

ParseResult::ParseResult ( ) {
    this->setErrors("");
    this->setOK(true) ;
    this->ast = NULL ; 
};

/*this->astNode::this->astNode() {
    this->setTerminal(noMatch);
    this->setLexeme("");
    this->setNext(NULL);
};*/

ExprResult::ExprResult(string lexeme){
    this->setTerminal(expr);
	 this->setLexeme (lexeme);
	 this->setNext(NULL);
};

IntConst::IntConst(string lexeme){
    this->setTerminal(intConst);
	 this->setLexeme (lexeme);
	 this->setNext(NULL);
};


NullExprResult::NullExprResult(){
    this->setTerminal(nullExpr);
	 this->setLexeme("0");
	 this->setNext(NULL);
};

ExtendedExprResult::ExtendedExprResult(string lexeme){
    this->setTerminal(extendedExpr);
    this->setLexeme(lexeme);
    this->setNext(NULL);
};

Addition::Addition(){
    this->setTerminal(plusSign);
    this->setLexeme("+");
    this->setNext(NULL);
};

Subtraction::Subtraction(){
    this->setTerminal(dash);
    this->setLexeme("-");
    this->setNext(NULL);
};

Division::Division(){
    this->setTerminal(forwardSlash);
    this->setLexeme("/");
    this->setNext(NULL);
};

Multiplication::Multiplication(){
    this->setTerminal(star);
    this->setLexeme("*");
    this->setNext(NULL);
};

Platform::Platform (string var_name ) {
    this->setTerminal(platformKwd);
	 this->setLexeme(var_name);
	 this->setNext(NULL);
};

Decls::Decls(Decls* d){
    this->setTerminal(noMatch);
	 this->setLexeme("");
	 this->setNext(NULL);
};

State::State(){
    this->setTerminal(stateKwd);
	 this->setLexeme("");
	 this->setNext(NULL);
};

Program::Program(std::string name, Platform* p, Decls* d, State* s){
    this->setTerminal(noMatch);
	 this->setLexeme("");
	 this->setNext(NULL);
};
