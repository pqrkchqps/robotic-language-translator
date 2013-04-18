/* ParseResult: a simple object for holding the result of a parse.

   Author: Eric Van Wyk

   Last modified: March 5, 2013.
*/

#ifndef PARSER_RESULT_H
#define PARSER_RESULT_H

// #include "AST.h"
#include "scanner.h"
//#include "extToken.h"

#include <string>


class ParseResult {
public:
    ParseResult() ;
    std::string getErrors() {return this->errors;};
    void setErrors(std::string errors) {this->errors = errors;};
    std::string getPP() {return this->pp;};
    void setPP(std::string pp) {this->pp = pp;};
    
    bool getOK() {return this->ok;};
    void setOK(bool ok) {this->ok = ok;};
    ParseResult* getNext() {return this->next;};
    void setNext(ParseResult* next) {this->next = next;};
      
    std::string errors ;
    std::string pp ;
    ASTNode *ast ;
    bool ok ;
    ParseResult* next;
} ;

class ASTNode {
    ASTNode() ;
    std::string getLexeme() {return this->lexeme;};
    void setLexeme(std::string lexeme) {this->lexeme = lexeme;};
    tokenType getTerminal()  {return this->terminal;};
    void setTerminal(tokenType terminal) {this->terminal = terminal;};
    ASTNode* getNext() {return this->next;};
    void setNext(ASTNode* next) {this->next = next;};

private:
    tokenType terminal;
    string lexeme;
    ASTNode* next;
};

class ExprResult : public ASTNode{
public:
	ExprResult(string lexeme);
};

class IntConstResult : public ASTNode{
public:
	IntConstResult(string lexeme);
};

class NullExprResult : public ASTNode{
public:
	NullExprResult();
};

class ExtendedExprResult : public ASTNode{
public:
	ExtendedExprResult(string lexeme);
};

class AdditionExprResult : public ASTNode{
public:
	AdditionExprResult();
};

class Platform : public ASTNode{
public:
	Platform(std::string var_name);
};

class Decls : public ASTNode{
public:
	Decls(ASTNode left, ASTNode right);
};

class States : public ASTNode{
public:
	States();
};

class Program : public ASTNode{
public:
	Program(std::string name, Platform* p, Decls* d, States* s);
};


#endif /* PARSER_RESULT_H */
