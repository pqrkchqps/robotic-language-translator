#include "parseResult.h"
#include "scanner.h"


class ParseResult;

class ASTNode {
public:
    ASTNode() {};
    std::string getLexeme() {return this->lexeme;};
    void setLexeme(std::string lexeme) {this->lexeme = lexeme;};
    tokenType getTerminal()  {return this->terminal;};
    void setTerminal(tokenType terminal) {this->terminal = terminal;};
    ASTNode* getNext() {return this->next;};
    void setNext(ASTNode* next) {this->next = next;};
    virtual ~ASTNode() {};

private:    
    tokenType terminal;
    string lexeme;
    ASTNode* next;
};

class ExprResult : public ASTNode{
public:
	ExprResult(string lexeme);
};

class TrueKwd : public ASTNode{
public:
	TrueKwd();
};

class FalseKwd : public ASTNode{
public:
	FalseKwd();
};

class IntConst : public ASTNode{
public:
	IntConst(string lexeme);
};

class FloatConst : public ASTNode{
public:
	FloatConst(string lexeme);
};

class StringConst : public ASTNode{
public:
	StringConst(string lexeme);
};

class CharConst : public ASTNode{
public:
	CharConst(string lexeme);
};

class VariableName : public ASTNode{
public:
	VariableName(string lexeme);
};

class LeftParen : public ASTNode {
public:
	LeftParen();
};

class RightParen : public ASTNode {
public:
	RightParen();
};

class NullExprResult : public ASTNode{
public:
	NullExprResult();
};

class ExtendedExprResult : public ASTNode{
public:
	ExtendedExprResult(string lexeme);
};

class Addition : public ASTNode{
public:
	Addition();
};

class Subtraction : public ASTNode{
public:
	Subtraction();
};

class Multiplication : public ASTNode{
public:
	Multiplication();
};

class Division : public ASTNode{
public:
	Division();
};

class Platform : public ASTNode{
public:
	Platform(std::string var_name);
};

class Decl : public ASTNode{
public:
	Decl();
};

class NullDecl : public ASTNode{
public:
	NullDecl();
};

class ConsDecl : public ASTNode{
public:
	ConsDecl();
};

class State : public ASTNode{
public:
	State();
};

class Program : public ASTNode{
public:
	Program(std::string name, Platform* p, ConsDecl* d, State* s);
};

