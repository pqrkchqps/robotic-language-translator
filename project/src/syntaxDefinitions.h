#ifndef SYNTAXDEFINITIONS_H
#define SYNTAXDEFINITIONS_H
#include "scanner.h"

/*********************************************************************
syntaxDefinitions was created to allow the editing of the basic lexemes
without having to search through the scanner or the regex code.

the method buildSyntax is used by the scanner to construct all of the
variables needed for scan to match a lexeme and create a corresponding
token.

token_builders is the main variable created by buildSyntax.
In scan each of these TokenBuilders are accessed in sequence to see
if there is a corresponding match and to store the corresponding terminal
in the token created.  

**********************************************************************/

void Scanner::buildSyntax() {
// Create the compiled regular expressions.
this->whiteSpace = makeRegex ("^[\n\t\r ]+");
this->blockComment = makeRegex("^/\\*([^\\*]|\\*+[^\\*/])*\\*+/");
this->lineComment = makeRegex("^//([^\n])*");

// Keywords
this->token_builders = (TokenBuilder*)malloc(sizeof(TokenBuilder)*40);
this->token_builders[0] = *(new TokenBuilder(nameKwd, makeRegex("^name")));
this->token_builders[1] = *(new TokenBuilder(platformKwd, makeRegex("^platform")));
this->token_builders[2] = *(new TokenBuilder(initialKwd, makeRegex("^initial")));
this->token_builders[3] = *(new TokenBuilder(stateKwd, makeRegex("^state")));
this->token_builders[4] = *(new TokenBuilder(gotoKwd, makeRegex("^goto")));
this->token_builders[5] = *(new TokenBuilder(whenKwd, makeRegex("^when")));
this->token_builders[6] = *(new TokenBuilder(performingKwd, makeRegex("^performing")));
this->token_builders[7] = *(new TokenBuilder(exitKwd, makeRegex("^exit")));
this->token_builders[8] = *(new TokenBuilder(intKwd, makeRegex("^int")));
this->token_builders[9] = *(new TokenBuilder(floatKwd, makeRegex("^float")));
this->token_builders[10] = *(new TokenBuilder(booleanKwd, makeRegex("^boolean")));
this->token_builders[11] = *(new TokenBuilder(stringKwd, makeRegex("^string")));
this->token_builders[12] = *(new TokenBuilder(charKwd, makeRegex("^char")));
this->token_builders[13] = *(new TokenBuilder(trueKwd, makeRegex("^true")));
this->token_builders[14] = *(new TokenBuilder(falseKwd, makeRegex("^false")));
      
//Constants  
this->token_builders[15] = *(new TokenBuilder(intConst, makeRegex("^[0-9]+*")));
this->token_builders[16] = *(new TokenBuilder(floatConst, makeRegex("^[0-9]+*\\.[0-9]+*")));
this->token_builders[17] = *(new TokenBuilder(stringConst, makeRegex("^\"[^\"]*\"")));
this->token_builders[18] = *(new TokenBuilder(charConst, makeRegex("^'([\\])?[^'\n\t\r ]'")));
    
//Names
this->token_builders[19] = *(new TokenBuilder(variableName, makeRegex("^([_a-zA-Z][a-zA-Z_0-9]*)")));
    
//Punctuation    
this->token_builders[20] = *(new TokenBuilder(leftParen, makeRegex("^[(]")));
this->token_builders[21] = *(new TokenBuilder(rightParen, makeRegex("^[)]")));
this->token_builders[22] = *(new TokenBuilder(leftCurly, makeRegex("^[{]")));
this->token_builders[23] = *(new TokenBuilder(rightCurly, makeRegex("^[}]")));
this->token_builders[24] = *(new TokenBuilder(leftAngle, makeRegex("^[<]")));
this->token_builders[25] = *(new TokenBuilder(rightAngle, makeRegex("^[>]")));
this->token_builders[26] = *(new TokenBuilder(colon, makeRegex("^[:]")));
this->token_builders[27] = *(new TokenBuilder(comma, makeRegex("^[,]")));
this->token_builders[28] = *(new TokenBuilder(semiColon, makeRegex("^[;]")));
this->token_builders[29] = *(new TokenBuilder(assign, makeRegex("^:=")));
this->token_builders[30] = *(new TokenBuilder(plusSign, makeRegex("^[+]")));
this->token_builders[31] = *(new TokenBuilder(star, makeRegex("^[*]")));
this->token_builders[32] = *(new TokenBuilder(dash, makeRegex("^[-]")));
this->token_builders[33] = *(new TokenBuilder(forwardSlash, makeRegex("^[/]")));
this->token_builders[34] = *(new TokenBuilder(equalsEquals, makeRegex("^==")));
this->token_builders[35] = *(new TokenBuilder(lessThanEquals, makeRegex("^<=")));
this->token_builders[36] = *(new TokenBuilder(greaterThanEquals, makeRegex("^>=")));
this->token_builders[37] = *(new TokenBuilder(notEquals, makeRegex("^!=")));
this->token_builders[38] = *(new TokenBuilder(endOfFile, makeRegex("")));
this->token_builders[39] = *(new TokenBuilder(lexicalError, makeRegex("^.")));
this->syntax_size = 40;
//return token_builders;

}
#endif //SYNTAXDEFINITIONS_H
