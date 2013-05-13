#ifndef SYNTAXDEFINITIONS_H
#define SYNTAXDEFINITIONS_H
#include "scanner.h"

bool f1(int numMatchedChars, string lexeme) { return (numMatchedChars == 4);};						
bool f2(int numMatchedChars, string lexeme) { return (numMatchedChars == 8);};
bool f3(int numMatchedChars, string lexeme) { return (numMatchedChars == 7);};
bool f4(int numMatchedChars, string lexeme) { return (numMatchedChars == 5);};
bool f5(int numMatchedChars, string lexeme) { return (numMatchedChars == 4);};
bool f6(int numMatchedChars, string lexeme) { return (numMatchedChars == 4);};
bool f7(int numMatchedChars, string lexeme) { return (numMatchedChars == 10);};
bool f8(int numMatchedChars, string lexeme) { return (numMatchedChars == 4);};
bool f9(int numMatchedChars, string lexeme) { return (numMatchedChars == 3);};
bool f10(int numMatchedChars, string lexeme) { return (numMatchedChars == 5);};
bool f11(int numMatchedChars, string lexeme) { return (numMatchedChars == 7);};
bool f12(int numMatchedChars, string lexeme) { return (numMatchedChars == 6);};
bool f13(int numMatchedChars, string lexeme) { return (numMatchedChars == 4);};
bool f14(int numMatchedChars, string lexeme) { return (numMatchedChars == 4);};
bool f15(int numMatchedChars, string lexeme) { return (numMatchedChars == 5);};
bool f16(int numMatchedChars, string lexeme) { return (numMatchedChars > 0);};
bool f17(int numMatchedChars, string lexeme) { return (numMatchedChars > 0);};
bool f18(int numMatchedChars, string lexeme) { return (numMatchedChars > 0);};
bool f19(int numMatchedChars, string lexeme) { return (numMatchedChars == 3 || numMatchedChars == 4 );};
bool f20(int numMatchedChars, string lexeme) { return (numMatchedChars > 0);};
bool f21(int numMatchedChars, string lexeme) { return (numMatchedChars == 1);};
bool f22(int numMatchedChars, string lexeme) { return (numMatchedChars == 1);};
bool f23(int numMatchedChars, string lexeme) { return (numMatchedChars == 1);};
bool f24(int numMatchedChars, string lexeme) { return (numMatchedChars == 1);};
bool f25(int numMatchedChars, string lexeme) { return (numMatchedChars == 1);};
bool f26(int numMatchedChars, string lexeme) { return (numMatchedChars == 1);};
bool f27(int numMatchedChars, string lexeme) { return (numMatchedChars == 1);};
bool f28(int numMatchedChars, string lexeme) { return (numMatchedChars == 1);};
bool f29(int numMatchedChars, string lexeme) { return (numMatchedChars == 1);};
bool f30(int numMatchedChars, string lexeme) { return (numMatchedChars == 2);};
bool f31(int numMatchedChars, string lexeme) { return (numMatchedChars == 1);};
bool f32(int numMatchedChars, string lexeme) { return (numMatchedChars == 1);};
bool f33(int numMatchedChars, string lexeme) { return (numMatchedChars == 1);};
bool f34(int numMatchedChars, string lexeme) { return (numMatchedChars == 1);};
bool f35(int numMatchedChars, string lexeme) { return (numMatchedChars == 2);};
bool f36(int numMatchedChars, string lexeme) { return (numMatchedChars == 2);};
bool f37(int numMatchedChars, string lexeme) { return (numMatchedChars == 2);};
bool f38(int numMatchedChars, string lexeme) { return (numMatchedChars == 2);};
bool f39(int numMatchedChars, string lexeme) { return lexeme.empty(); };
bool f40(int numMatchedChars, string lexeme) { return (numMatchedChars == 1);};

void Scanner::buildSyntax() {
// Create the compiled regular expressions.
this->whiteSpace = makeRegex ("^[\n\t\r ]+");
this->blockComment = makeRegex("^/\\*([^\\*]|\\*+[^\\*/])*\\*+/");
this->lineComment = makeRegex("^//([^\n])*");

//Please see TokenType declaration in scanner.h
//error checking function pointers are linked to the token_builders array
//These functions are called in scanner to ensure there is no unexpected behaviour
bool (* err_check_func_ptrs[40])(int,string);
err_check_func_ptrs[0] = (bool (*)(int,string))f1;
err_check_func_ptrs[1] = (bool (*)(int,string))f2;
err_check_func_ptrs[2] = (bool (*)(int,string))f3;
err_check_func_ptrs[3] = (bool (*)(int,string))f4;
err_check_func_ptrs[4] = (bool (*)(int,string))f5;
err_check_func_ptrs[5] = (bool (*)(int,string))f6;
err_check_func_ptrs[6] = (bool (*)(int,string))f7;
err_check_func_ptrs[7] = (bool (*)(int,string))f8;
err_check_func_ptrs[8] = (bool (*)(int,string))f9;
err_check_func_ptrs[9] = (bool (*)(int,string))f10;
err_check_func_ptrs[10] = (bool (*)(int,string))f11;
err_check_func_ptrs[11] = (bool (*)(int,string))f12;
err_check_func_ptrs[12] = (bool (*)(int,string))f13;
err_check_func_ptrs[13] = (bool (*)(int,string))f14;
err_check_func_ptrs[14] = (bool (*)(int,string))f15;
err_check_func_ptrs[15] = (bool (*)(int,string))f16;
err_check_func_ptrs[16] = (bool (*)(int,string))f17;
err_check_func_ptrs[17] = (bool (*)(int,string))f18;
err_check_func_ptrs[18] = (bool (*)(int,string))f19;
err_check_func_ptrs[19] = (bool (*)(int,string))f20;
err_check_func_ptrs[20] = (bool (*)(int,string))f21;
err_check_func_ptrs[21] = (bool (*)(int,string))f22;
err_check_func_ptrs[22] = (bool (*)(int,string))f23;
err_check_func_ptrs[23] = (bool (*)(int,string))f24;
err_check_func_ptrs[24] = (bool (*)(int,string))f25;
err_check_func_ptrs[25] = (bool (*)(int,string))f26;
err_check_func_ptrs[26] = (bool (*)(int,string))f27;
err_check_func_ptrs[27] = (bool (*)(int,string))f28;
err_check_func_ptrs[28] = (bool (*)(int,string))f29;
err_check_func_ptrs[29] = (bool (*)(int,string))f30;
err_check_func_ptrs[30] = (bool (*)(int,string))f31;
err_check_func_ptrs[31] = (bool (*)(int,string))f32;
err_check_func_ptrs[32] = (bool (*)(int,string))f33;
err_check_func_ptrs[33] = (bool (*)(int,string))f34;
err_check_func_ptrs[34] = (bool (*)(int,string))f35;
err_check_func_ptrs[35] = (bool (*)(int,string))f36;
err_check_func_ptrs[36] = (bool (*)(int,string))f37;
err_check_func_ptrs[37] = (bool (*)(int,string))f38;
err_check_func_ptrs[38] = (bool (*)(int,string))f39;
err_check_func_ptrs[39] = (bool (*)(int,string))f40;


char ** err_strings;
err_strings = (char **)malloc(sizeof(char **)*40);
err_strings[0] =	(char *)"lexeme is not the nameKwd";
err_strings[1] =	(char *)"lexeme is not the platformKwd";
err_strings[2] =	(char *)"lexeme is not the initialKwd";
err_strings[3] =	(char *)"lexeme is not the stateKwd";
err_strings[4] =	(char *)"lexeme is not the gotoKwd";
err_strings[5] =	(char *)"lexeme is not the whenKwd";
err_strings[6] =	(char *)"lexeme is not the performigKwd";
err_strings[7] =	(char *)"lexeme is not the exitKwd";
err_strings[8] =	(char *)"lexeme is not the intKwd";
err_strings[9] =	(char *)"lexeme is not the floatKwd";
err_strings[10] =	(char *)"lexeme is not the booleanKwd";
err_strings[11] =	(char *)"lexeme is not the stringKwd";
err_strings[12] =	(char *)"lexeme is not the charKwd";
err_strings[13] =	(char *)"lexeme is not the trueKwd";
err_strings[14] =	(char *)"lexeme is not the falseKwd";
err_strings[15] =	(char *)"lexeme is not the intConst";
err_strings[16] =	(char *)"lexeme is not the floatConst";
err_strings[17] =	(char *)"lexeme is not the stringConst";
err_strings[18] =	(char *)"lexeme is not the charConst";
err_strings[19] =	(char *)"lexeme is not the variableName";
err_strings[20] =	(char *)"lexeme is not the leftParen";
err_strings[21] =	(char *)"lexeme is not the rightParen";
err_strings[22] =	(char *)"lexeme is not the leftCurly";
err_strings[23] =	(char *)"lexeme is not the rightCurly";
err_strings[24] =	(char *)"lexeme is not the leftAngle";
err_strings[25] =	(char *)"lexeme is not the rightAngle";
err_strings[26] =	(char *)"lexeme is not the colon";
err_strings[27] =	(char *)"lexeme is not the comma";
err_strings[28] =	(char *)"lexeme is not the semiColon";
err_strings[29] =	(char *)"lexeme is not the assign";
err_strings[30] =	(char *)"lexeme is not the plusSign";
err_strings[31] =	(char *)"lexeme is not the star";
err_strings[32] =	(char *)"lexeme is not the dash";
err_strings[33] =	(char *)"lexeme is not the forwardSlash";
err_strings[34] =	(char *)"lexeme is not the equalsEquals";
err_strings[35] =	(char *)"lexeme is not the lessThanEquals";
err_strings[36] =	(char *)"lexeme is not the greaterThanEquals";
err_strings[37] =	(char *)"lexeme is not the notEquals";
err_strings[38] =	(char *)"lexeme is not the endOfFile";
err_strings[39] =	(char *)"lexeme is not a lexicalError";


// Keywords
this->token_builders = (TokenType*)malloc(sizeof(TokenType)*40);
this->token_builders[0] = *(new TokenType(nameKwd, makeRegex("^name"), err_check_func_ptrs[0], err_strings[0]));
this->token_builders[1] = *(new TokenType(platformKwd, makeRegex("^platform"), err_check_func_ptrs[1], err_strings[1]));
this->token_builders[2] = *(new TokenType(initialKwd, makeRegex("^initial"), err_check_func_ptrs[2], err_strings[2]));
this->token_builders[3] = *(new TokenType(stateKwd, makeRegex("^state"), err_check_func_ptrs[3], err_strings[3]));
this->token_builders[4] = *(new TokenType(gotoKwd, makeRegex("^goto"), err_check_func_ptrs[4], err_strings[4]));
this->token_builders[5] = *(new TokenType(whenKwd, makeRegex("^when"), err_check_func_ptrs[5], err_strings[5]));
this->token_builders[6] = *(new TokenType(performingKwd, makeRegex("^performing"), err_check_func_ptrs[6], err_strings[6]));
this->token_builders[7] = *(new TokenType(exitKwd, makeRegex("^exit"), err_check_func_ptrs[7], err_strings[7]));
this->token_builders[8] = *(new TokenType(intKwd, makeRegex("^int"), err_check_func_ptrs[8], err_strings[8]));
this->token_builders[9] = *(new TokenType(floatKwd, makeRegex("^float"), err_check_func_ptrs[9], err_strings[9]));
this->token_builders[10] = *(new TokenType(booleanKwd, makeRegex("^boolean"), err_check_func_ptrs[10], err_strings[10]));
this->token_builders[11] = *(new TokenType(stringKwd, makeRegex("^string"), err_check_func_ptrs[11], err_strings[11]));
this->token_builders[12] = *(new TokenType(charKwd, makeRegex("^char"), err_check_func_ptrs[12], err_strings[12]));
this->token_builders[13] = *(new TokenType(trueKwd, makeRegex("^true"), err_check_func_ptrs[13], err_strings[13]));
this->token_builders[14] = *(new TokenType(falseKwd, makeRegex("^false"), err_check_func_ptrs[14], err_strings[14]));
      
//Constants  
this->token_builders[15] = *(new TokenType(intConst, makeRegex("^[0-9]+*"), err_check_func_ptrs[15], err_strings[15]));
this->token_builders[16] = *(new TokenType(floatConst, makeRegex("^[0-9]+*\\.[0-9]+*"), err_check_func_ptrs[16], err_strings[16]));
this->token_builders[17] = *(new TokenType(stringConst, makeRegex("^\"[^\"]*\""), err_check_func_ptrs[17], err_strings[17]));
this->token_builders[18] = *(new TokenType(charConst, makeRegex("^'([\\])?[^'\n\t\r ]'"), err_check_func_ptrs[18], err_strings[18]));
    
//Names
this->token_builders[19] = *(new TokenType(variableName, makeRegex("^([_a-zA-Z][a-zA-Z_0-9]*)"),err_check_func_ptrs[19],err_strings[19]));
    
//Punctuation    
this->token_builders[20] = *(new TokenType(leftParen, makeRegex("^[(]"), err_check_func_ptrs[20], err_strings[20]));
this->token_builders[21] = *(new TokenType(rightParen, makeRegex("^[)]"), err_check_func_ptrs[21], err_strings[21]));
this->token_builders[22] = *(new TokenType(leftCurly, makeRegex("^[{]"), err_check_func_ptrs[22], err_strings[22]));
this->token_builders[23] = *(new TokenType(rightCurly, makeRegex("^[}]"), err_check_func_ptrs[23], err_strings[23]));
this->token_builders[24] = *(new TokenType(leftAngle, makeRegex("^[<]"), err_check_func_ptrs[24], err_strings[24]));
this->token_builders[25] = *(new TokenType(rightAngle, makeRegex("^[>]"), err_check_func_ptrs[25], err_strings[25]));
this->token_builders[26] = *(new TokenType(colon, makeRegex("^[:]"), err_check_func_ptrs[26], err_strings[26]));
this->token_builders[27] = *(new TokenType(comma, makeRegex("^[,]"), err_check_func_ptrs[27], err_strings[27]));
this->token_builders[28] = *(new TokenType(semiColon, makeRegex("^[;]"), err_check_func_ptrs[28], err_strings[28]));
this->token_builders[29] = *(new TokenType(assign, makeRegex("^:="), err_check_func_ptrs[29], err_strings[29]));
this->token_builders[30] = *(new TokenType(plusSign, makeRegex("^[+]"), err_check_func_ptrs[30], err_strings[30]));
this->token_builders[31] = *(new TokenType(star, makeRegex("^[*]"), err_check_func_ptrs[31], err_strings[31]));
this->token_builders[32] = *(new TokenType(dash, makeRegex("^[-]"), err_check_func_ptrs[32], err_strings[32]));
this->token_builders[33] = *(new TokenType(forwardSlash, makeRegex("^[/]"), err_check_func_ptrs[33], err_strings[33]));
this->token_builders[34] = *(new TokenType(equalsEquals, makeRegex("^=="), err_check_func_ptrs[34], err_strings[34]));
this->token_builders[35] = *(new TokenType(lessThanEquals, makeRegex("^<="), err_check_func_ptrs[35], err_strings[35]));
this->token_builders[36] = *(new TokenType(greaterThanEquals, makeRegex("^>="), err_check_func_ptrs[36], err_strings[36]));
this->token_builders[37] = *(new TokenType(notEquals, makeRegex("^!="), err_check_func_ptrs[37], err_strings[37]));
this->token_builders[38] = *(new TokenType(endOfFile, makeRegex(""), err_check_func_ptrs[38], err_strings[38]));
this->token_builders[39] = *(new TokenType(lexicalError, makeRegex("^."), err_check_func_ptrs[39], err_strings[39]));
this->syntax_size = 40;
//return token_builders;

}
#endif //SYNTAXDEFINITIONS_H
