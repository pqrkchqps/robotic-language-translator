#ifndef SCANNER_H
#define SCANNER_H

#include <regex.h>
#include <string>

/* This enumerated type is used to keep track of what kind of
   construct was matched. 
*/

//create a new exception 
class InvalidToken : public runtime_error{
	public:
	InvalidToken(const char* m) : runtime_error(m) {}
}
using namespace std; 
enum tokenEnumType { 

    // Keywords
    nameKwd = 1, platformKwd, initialKwd, stateKwd, 
    gotoKwd, whenKwd, performingKwd, exitKwd,

    intKwd, floatKwd, booleanKwd, stringKwd, charKwd,

    trueKwd, falseKwd,

    // Constants
    intConst, floatConst, stringConst, charConst,

    // Names
    variableName ,

    // Punctuation
    leftParen, rightParen, 
    leftCurly, rightCurly, 

    leftAngle, rightAngle,
    colon, comma, semiColon, 
    assign, 

    plusSign, star, dash, forwardSlash,
    equalsEquals, lessThanEquals, greaterThanEquals, notEquals, 

    // Special terminal types
    endOfFile ,
    lexicalError
} ;
typedef enum tokenEnumType tokenType ;

// Below you need to write your class definitions for Token and Scanner.


class Token {
public:
//fields
	tokenType terminal;
	string lexeme;
	Token* next;

//constructor for Token 
	Token (tokenType terminal, string lexeme);

};

class Scanner {
public:
//methods
	Token *scan(const char *);
	
};




#endif /* SCANNER_H */
