/* ParseResult: a simple object for holding the result of a parse.

   Author: Eric Van Wyk

   Last modified: March 5, 2013.
*/

#ifndef PARSER_RESULT_H
#define PARSER_RESULT_H

#include <string>
#include "ASTNode.h"


class ParseResult {
public:
    std::string getErrors() {return this->errors;};
    void setErrors(std::string errors) {this->errors = errors;};
    std::string getPP() {return this->pp;};
    void setPP(std::string pp) {this->pp = pp;};
    
    bool getOK() {return this->ok;};
    void setOK(bool ok) {this->ok = ok;};
    ParseResult* getNext() {return this->next;};
    void setNext(ParseResult* next) {this->next = next;};
      
    std::string errors;
    std::string pp;
    ASTNode *ast;
    bool ok;

    ParseResult();
    virtual ~ParseResult() {};
private:
    ParseResult* next;
} ;

#endif /* PARSER_RESULT_H */
