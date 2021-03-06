#ifndef SCANNER_H
#define SCANNER_H

#include "regex.h"
#include <stdexcept>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h> 
#include <stdexcept>
#include <string.h>

using namespace std; 

//create a new exception 
class InvalidToken : public runtime_error {
	public:
	InvalidToken(const char* m) : runtime_error(m) {}
};

enum tokenEnumType {

    // Keywords
    nameKwd = 1, platformKwd = 2, initialKwd = 3, stateKwd = 4, 
    gotoKwd = 5, whenKwd, performingKwd, exitKwd,
    intKwd, floatKwd, booleanKwd = 11, stringKwd, charKwd,
    trueKwd, falseKwd,

    // Constants
    intConst, floatConst, stringConst, charConst,

    // Names
    variableName,

    // Punctuation
    leftParen, rightParen,
    leftCurly, rightCurly,

    leftAngle, rightAngle,
    colon, comma, semiColon, 
    assign, 

    plusSign, star, dash, forwardSlash,
    equalsEquals, lessThanEquals, greaterThanEquals, notEquals, 

    // Special terminal types
    endOfFile,
    lexicalError,
    noMatch
};

// Below you need to write your class definitions for Token and Scanner.
typedef enum tokenEnumType tokenType ;

class Token {
public:
	//constructors for Token 
	Token (string lexeme, tokenType terminal);
	Token (tokenType terminal, string lexeme);
	Token (string lexeme, tokenType terminal, Token* next);
	Token (const char* lexeme, tokenType terminal, Token* next);
	void init (string lexeme, tokenType terminal, Token* next);
	//accessors
	void set_next(Token* next);
	Token* get_next();
	tokenType get_terminal();
	string get_lexeme();
//private:
	tokenType terminal;
	string lexeme;
	Token* next;
};


class TokenBuilder {
public:
	//constructors
	TokenBuilder() {};
	TokenBuilder(regex_t* lexeme_pattern, tokenType terminal);	
	TokenBuilder(tokenType terminal, regex_t* lexeme_pattern);

	//methods
 	int checkMatch(const char* lexeme);
	Token makeTokenBuilder(const char* lexeme);
	bool (*checkError)(int,string);
	void throwError();
	//accessors
	tokenType get_terminal();
private:
	//fields
	const char* err_string;		
	regex_t* lexeme_pattern;
	tokenType terminal;
	int numMatchedChars;
};

class Scanner {
public:
	//methods
	Token *scan(const char *);
	Scanner();
	void buildSyntax();
private:
	TokenBuilder* token_builders;
	int syntax_size;
	regex_t* whiteSpace;
	regex_t* blockComment;
	regex_t* lineComment;
};

#endif /* SCANNER_H */
