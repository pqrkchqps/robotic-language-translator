#ifndef SCANNER_H
#define SCANNER_H

#include <regex.h>
#include <string>

class Token ;

/* This enumerated type is used to keep track of what kind of
   construct was matched. 
*/
enum tokenEnumType { 

    // Keywords
    nameKwd, platformKwd, initialKwd, stateKwd, 
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


#endif /* SCANNER_H */
