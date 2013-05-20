/* ParseResult: a simple object for holding the result of a parse.

   Author: Eric Van Wyk

   Last modified: March 5, 2013.
*/

#ifndef PARSER_RESULT_H
#define PARSER_RESULT_H

#include "parser.h"


class ParseResult {
public:

    std::string errors;
    std::string pp;
    ASTNode *ast;
    //bool ok;

    ParseResult();

} ;

#endif /* PARSER_RESULT_H */