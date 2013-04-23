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


DeclResult::DeclResult(std::string type, std::string name){
    this->setErrors("");
    this->setOK(true) ;
    this->ast = NULL ; 
};
DeclResult::DeclResult(std::string type, std::string name, std::string value){
    this->setErrors("");
    this->setOK(true) ;
    this->ast = new Decl(); 
    this->type = type;
    this->name = name;
    this->value = "NULL";
};

Decl::Decl() {
    this->setTerminal(declToken);
    this->setLexeme ("Decl");
    this->setNext(NULL);
};

ConsDeclResult::ConsDeclResult(ParseResult car, ParseResult cdr){
    this->setErrors("");
    this->setOK(true) ;
    this->ast = new ConsDecl(); 
    this->left = car;
    this->right = cdr;
};

ParseResult ConsDeclResult::car() {
    return this->left;
};

ParseResult ConsDeclResult::cdr() {
    return this->right;
};

ConsDecl::ConsDecl(){
    this->setTerminal(consDeclToken);
    this->setLexeme ("ConsDecl");
    this->setNext(NULL);
};

NullDeclResult::NullDeclResult() {
    this->setErrors("");
    this->setOK(true);
    this->ast = new NullDecl();
};

NullDecl::NullDecl(){
    this->setTerminal(nullDeclToken);
    this->setLexeme ("NULLDecl");
    this->setNext(NULL);
};

ExprResult::ExprResult(string lexeme){
    this->setTerminal(expr);
    this->setLexeme (lexeme);
    this->setNext(NULL);
};

TrueKwd::TrueKwd(){
    this->setTerminal(trueKwd);
    this->setLexeme ("true");
    this->setNext(NULL);
};

FalseKwd::FalseKwd(){
    this->setTerminal(falseKwd);
    this->setLexeme ("false");
    this->setNext(NULL);
};

IntConst::IntConst(string lexeme){
    this->setTerminal(intConst);
    this->setLexeme (lexeme);
    this->setNext(NULL);
};

FloatConst::FloatConst(string lexeme){
    this->setTerminal(floatConst);
	 this->setLexeme (lexeme);
	 this->setNext(NULL);
};

StringConst::StringConst(string lexeme){
    this->setTerminal(stringConst);
	 this->setLexeme (lexeme);
	 this->setNext(NULL);
};

CharConst::CharConst(string lexeme){
    this->setTerminal(charConst);
	 this->setLexeme (lexeme);
	 this->setNext(NULL);
};

VariableName::VariableName(string lexeme){
    this->setTerminal(variableName);
    this->setLexeme (lexeme);
    this->setNext(NULL);
};

LeftParen::LeftParen(){
    this->setTerminal(leftParen);
    this->setLexeme("(");
    this->setNext(NULL);
};

RightParen::RightParen(){
    this->setTerminal(rightParen);
    this->setLexeme(")");
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

State::State(){
    this->setTerminal(stateKwd);
    this->setLexeme("");
    this->setNext(NULL);
};

Program::Program(std::string name, Platform* p, ConsDecl* d, State* s){
    this->setTerminal(noMatch);
    this->setLexeme("");
    this->setNext(NULL);
};
