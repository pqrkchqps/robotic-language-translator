#include "regex.h"

// Create the compiled regular expressions.
regex_t *whiteSpace = makeRegex ("^[\n\t\r ]+");
regex_t *blockComment = makeRegex("^/\\*([^\\*]|\\*+[^\\*/])*\\*+/");
regex_t *lineComment = makeRegex("^//([^\n])*");
    
// Keywords
regex_t *rnameKwd = makeRegex("^name");
regex_t *rplatformKwd = makeRegex("^platform");
regex_t *rinitialKwd = makeRegex("^initial");
regex_t *rstateKwd = makeRegex("^state");
regex_t *rgotoKwd = makeRegex("^goto");
regex_t *rwhenKwd = makeRegex("^when");
regex_t *rperformingKwd = makeRegex("^performing");
regex_t *rexitKwd = makeRegex("^exit");
regex_t *rintKwd = makeRegex("^int");
regex_t *rfloatKwd = makeRegex("^float");
regex_t *rbooleanKwd = makeRegex("^boolean");
regex_t *rstringKwd = makeRegex("^string");
regex_t *rcharKwd = makeRegex("^char");
regex_t *rtrueKwd = makeRegex("^true");
regex_t *rfalseKwd = makeRegex("^false");
      
//Constants  
regex_t *rintConst = makeRegex("^[0-9]+*");
regex_t *rfloatConst = makeRegex("^[0-9]+*\\.[0-9]+*");
regex_t *rstringConst = makeRegex("^\"[^\"]*\"");
regex_t *rcharConst = makeRegex("^'([\\])?[^'\n\t\r ]'");
       
//Names
regex_t *rvariableName = makeRegex("^([_a-zA-Z][a-zA-Z_0-9]*)");
    
//Punctuation    
regex_t *rleftParen = makeRegex("^[(]");
regex_t *rrightParen = makeRegex("^[)]");
regex_t *rleftCurly = makeRegex("^[{]");
regex_t *rrightCurly = makeRegex("^[}]");
regex_t *rleftAngle = makeRegex("^[<]");
regex_t *rrightAngle = makeRegex("^[>]");
regex_t *rcolon = makeRegex("^[:]");
regex_t *rcomma = makeRegex("^[,]");
regex_t *rsemiColon = makeRegex("^[;]");
regex_t *rassign = makeRegex("^:=");
regex_t *rplusSign = makeRegex("^[+]");
regex_t *rstar = makeRegex("^[*]");
regex_t *rdash = makeRegex("^[-]");
regex_t *rforwardSlash = makeRegex("^[/]");
regex_t *requalsEquals = makeRegex("^==");
regex_t *rlessThanEquals = makeRegex("^<=");
regex_t *rgreaterThanEquals = makeRegex("^>=");
regex_t *rnotEquals = makeRegex("^!=");
regex_t *rlexicalError = makeRegex("^.");  
