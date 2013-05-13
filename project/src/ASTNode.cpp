#include "ASTNode.h"

using namespace std;

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
