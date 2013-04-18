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
    
    std::string getLexeme() {return this->lexeme;};
    void setLexeme(std::string lexeme) {this->lexeme = lexeme;};
    tokenType getTerminal()  {return this->terminal;};
    void setTerminal(tokenType terminal) {this->terminal = terminal;};
    bool getOK() {return this->ok;};
    void setOK(bool ok) {this->ok = ok;};
    ParseResult* getNext() {return this->next;};
    void setNext(ParseResult* next) {this->next = next;};
      
    std::string errors ;
    std::string pp ;
    //Token *ast ;
    bool ok ;
  	 ParseResult* next;
private:
    tokenType terminal;
	 string lexeme;
} ;

class ExprResult : public ParseResult{
public:
	ExprResult(string lexeme);
};

class NullExprResult : public ParseResult{
public:
	NullExprResult();
};

class ExtendedExprResult : public ParseResult{
public:
	ExtendedExprResult(string lexeme);
};



#endif /* PARSER_RESULT_H */
