//hold off on writing the code for scanner.cpp until after we have write some test cases

#include "scanner.h"
#include <stdio.h>
#include <stdlib.h>
#include "regex.h"
#include "readInput.h"
#include <sys/stat.h>
#include <sys/types.h> 
#include <stdexcept>
#include <string.h>

using namespace std; 

int consumeWhiteSpaceAndComments (regex_t *whiteSpace, 
                                  regex_t *blockComment,
                                  const char *text) {
    int numMatchedChars = 0 ;
    int totalNumMatchedChars = 0 ;
    int stillConsumingWhiteSpace ;

    do {
        stillConsumingWhiteSpace = 0 ;  // exit loop if not reset by a match

        // Try to match white space
        numMatchedChars = matchRegex (whiteSpace, text) ;
        totalNumMatchedChars += numMatchedChars ;
        if (numMatchedChars > 0) {
            text = text + numMatchedChars ;
            stillConsumingWhiteSpace = 1 ;
        }

        // Try to match block comments
        numMatchedChars = matchRegex (blockComment, text) ;
        totalNumMatchedChars += numMatchedChars ;
        if (numMatchedChars > 0) {
            text = text + numMatchedChars ;
            stillConsumingWhiteSpace = 1 ;
        }

    }
    while ( stillConsumingWhiteSpace ) ;    

    return totalNumMatchedChars ;
}


;
 
Token::Token (tokenType terminal, string lexeme) {
	
	regex_t *nameKwd;
    nameKwd = makeRegex("^name");
    regex_t *platformKwd;
    platformKwd = makeRegex("^platform");
    regex_t *initialKwd;
    initialKwd = makeRegex("^initial");
    regex_t *stateKwd;
    stateKwd = makeRegex("^state");
    regex_t *gotoKwd;
    gotoKwd = makeRegex("^goto");
    regex_t *whenKwd;
    whenKwd = makeRegex("^when");
    regex_t *performingKwd;
    performingKwd = makeRegex("^performing");
    regex_t *exitKwd;
    exitKwd = makeRegex("^exit");
    regex_t *intKwd;
    intKwd = makeRegex("^int");
    regex_t *floatKwd;
    floatKwd = makeRegex("^float");
    regex_t *booleanKwd;
    booleanKwd = makeRegex("^boolean");
    regex_t *stringKwd;
    stringKwd = makeRegex("^string");
    regex_t *charKwd;
    charKwd = makeRegex("^char");
    regex_t *trueKwd;
    trueKwd = makeRegex("^true");
    regex_t *falseKwd;
    falseKwd = makeRegex("^false");
    regex_t *intConst;
    intConst = makeRegex("^[0-9]+*");
    regex_t *floatConst;
    floatConst = makeRegex("^[0-9]+\\.?[0-9]*");
    regex_t *stringConst;
    stringConst = makeRegex("^'.*'");
    regex_t *charConst;
    charConst = makeRegex("^[a-zA-Z]");
    regex_t *variableName;
    variableName = makeRegex("^([a-zA-Z]+)");
    regex_t *leftParen;
    leftParen = makeRegex("^[(]");
    regex_t *rightParen;
    rightParen = makeRegex("^[)]");
    regex_t *leftCurly;
    leftCurly = makeRegex("^[{]");
    regex_t *rightCurly;
    rightCurly = makeRegex("^[}]");
    regex_t *leftAngle;
    leftAngle = makeRegex("^[<]");
    regex_t *rightAngle;
    rightAngle = makeRegex("^[>]");
    regex_t *colon;
    colon = makeRegex("^[:]");
    regex_t *comma;
    comma = makeRegex("^[,]");
    regex_t *semiColon;
    semiColon = makeRegex("^[;]");
    regex_t *assign;
    assign = makeRegex("^[=]");
    regex_t *plusSign;
    plusSign = makeRegex("^[+]");
    regex_t *star;
    star = makeRegex("^[*]");
    regex_t *dash;
    dash = makeRegex("^[-]");
   	regex_t *forwardSlash;
    forwardSlash = makeRegex("^[/]");
    regex_t *equalsEquals;
    equalsEquals = makeRegex("^==");
    regex_t *lessThanEquals;
    lessThanEquals = makeRegex("^<=");
    regex_t *greaterThanEquals;
    greaterThanEquals = makeRegex("^>=");
    regex_t *notEquals;
    notEquals = makeRegex("^!=");
    regex_t *endOfFile;
    endOfFile = makeRegex("\0");
    int numMatchedChars = 0;
    const char *cstring = lexeme.c_str();
    
	switch(terminal) {
		case 1://nameKwd:
				numMatchedChars = matchRegex (nameKwd, cstring  ) ;
		    if (numMatchedChars == 4)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the nameKwd"));
		    }
			
		case 2: //platformKwd:
				numMatchedChars = matchRegex (platformKwd, cstring  ) ;
		    if (numMatchedChars == 8)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the platformKwd"));
		    }
		    
		case 3: //initialKwd:
				numMatchedChars = matchRegex (initialKwd, cstring  ) ;
		    if (numMatchedChars == 7)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the initialKwd"));
		    }
		    
		case 4: //stateKwd:
				numMatchedChars = matchRegex (stateKwd, cstring  ) ;
		    if (numMatchedChars == 5)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the stateKwd"));
		    }
		    
		case 5: //gotoKwd:
				numMatchedChars = matchRegex (gotoKwd, cstring  ) ;
		    if (numMatchedChars == 4)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the gotoKwd"));
		    }
		case 6: //whenKwd:
				numMatchedChars = matchRegex (whenKwd, cstring  ) ;
		    if (numMatchedChars == 4)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the whenKwd"));
		    }
		    
		case 7: //performingKwd:
			numMatchedChars = matchRegex (performingKwd, cstring  ) ;
		    if (numMatchedChars == 10)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the performingKwd"));
		    }
		    
		case 8: //exitKwd:
			numMatchedChars = matchRegex (exitKwd, cstring  ) ;
		    if (numMatchedChars == 4)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the exitKwd"));
		    }
		    
		case 9: //intKwd:
			numMatchedChars = matchRegex (intKwd, cstring  ) ;
		    if (numMatchedChars == 3)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the intKwd"));
		    }
		    
		case 10: //floatKwd:
			numMatchedChars = matchRegex (floatKwd, cstring  ) ;
		    if (numMatchedChars == 5)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the floatKwd"));
		    }
		    
		case 11: //booleanKwd:
			numMatchedChars = matchRegex (booleanKwd, cstring  ) ;
		    if (numMatchedChars == 7)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the booleanKwd"));
		    }
		    
		case 12: //stringKwd:
			numMatchedChars = matchRegex (stringKwd, cstring  ) ;
		    if (numMatchedChars == 6)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the stringKwd"));
		    }
		    
		case 13: //charKwd:
			numMatchedChars = matchRegex (charKwd, cstring  ) ;
		    if (numMatchedChars == 4)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the charKwd"));
		    }
		    
		case 14: //trueKwd:
			numMatchedChars = matchRegex (trueKwd, cstring  ) ;
		    if (numMatchedChars == 4)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the trueKwd"));
		    }
		    
		case 15: //falseKwd:
			numMatchedChars = matchRegex (falseKwd, cstring  ) ;
		    if (numMatchedChars == 5)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the falseKwd"));
		    }
		   
		case 16: //intConst:
			numMatchedChars = matchRegex (intConst, cstring  ) ;
		    if (numMatchedChars > 0)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the intConst"));
		    }
		    
		case 17: //floatConst:
			numMatchedChars = matchRegex (floatConst, cstring  ) ;
		    if (numMatchedChars > 0)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the floatConst"));
		    }
		    
		case 18: //stringConst:
			numMatchedChars = matchRegex (stringConst, cstring  ) ;
		    if (numMatchedChars > 0)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the stringConst"));
		    }
		    
		case 19: //charConst:
			numMatchedChars = matchRegex (charConst, cstring) ;
		    if (numMatchedChars == 1 )
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the charConst"));
		    }
		    
		case 20: //variableName:
			numMatchedChars = matchRegex (variableName, cstring);
		    if (numMatchedChars > 0)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the variableName"));
		    }
		   
		case 21: //leftParen:
			numMatchedChars = matchRegex (leftParen, cstring); 
		    if (numMatchedChars == 1) 
		    	break; 
	    	else {	
	    		throw (InvalidToken("lexeme is not the leftParen"));
		    }
		    
		case 22: //rightParen:
			numMatchedChars = matchRegex (rightParen, cstring);
		    if (numMatchedChars == 1)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the rightParen"));
		    }
		    
		case 23: //leftCurly:
			numMatchedChars = matchRegex (leftCurly, cstring) ;
		    if (numMatchedChars == 1)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the leftCurly"));
		    }
		    
		case 24: //rightCurly: 
			numMatchedChars = matchRegex (rightCurly, cstring  ) ;
		    if (numMatchedChars == 1)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the rightCurly"));
		    }
		    
		case 25: //leftAngle:
			numMatchedChars = matchRegex (leftAngle, cstring  ) ;
		    if (numMatchedChars == 1)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the leftAngle"));
		    }
		    
		case 26: //rightAngle:
			numMatchedChars = matchRegex (rightAngle, cstring  ) ;
		    if (numMatchedChars == 1)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the rightAngle"));
		    }
	    
		case 27: //colon:
			numMatchedChars = matchRegex (colon, cstring  ) ;
		    if (numMatchedChars == 1)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the colon"));
		    }
		    
		case 28: //comma:
			numMatchedChars = matchRegex (comma, cstring  ) ;
		    if (numMatchedChars == 1)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the comma"));
		    }
		    
		case 29: //semiColon: 
			numMatchedChars = matchRegex (semiColon, cstring  ) ;
		    if (numMatchedChars == 1)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the semiColon"));
		    }
		    
		case 30: //assign: 
			numMatchedChars = matchRegex (assign, cstring  ) ;
		    if (numMatchedChars == 1)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the assign"));
		    }
		    
		case 31: //plusSign:
			numMatchedChars = matchRegex (plusSign, cstring  ) ;
		    if (numMatchedChars == 1)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the plusSign"));
		    }
		    
		case 32: //star:
			numMatchedChars = matchRegex (star, cstring  ) ;
		    if (numMatchedChars == 1)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the star"));
		    }
		    
		case 33: //dash:
			numMatchedChars = matchRegex (dash, cstring  ) ;
		    if (numMatchedChars == 1)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the dash"));
		    }
		    
		case 34: //forwardSlash:
			numMatchedChars = matchRegex (forwardSlash, cstring  ) ;
		    if (numMatchedChars == 1)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the forwardSlash"));
		    }
		    
		case 35:// equalsEquals:
			numMatchedChars = matchRegex (equalsEquals, cstring  ) ;
		    if (numMatchedChars == 2)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the equalsEquals"));
		    }
		    
		case 36: //lessThanEquals:
			numMatchedChars = matchRegex (lessThanEquals, cstring  ) ;
		    if (numMatchedChars == 2)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the lessThanEquals"));
		    }
		    
		case 37: //greaterThanEquals:
			numMatchedChars = matchRegex (greaterThanEquals, cstring  ) ;
		    if (numMatchedChars == 2)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the greaterThanEquals"));
		    }
		    
		case 38: //notEquals:
			numMatchedChars = matchRegex (notEquals, cstring  ) ;
		    if (numMatchedChars == 2)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the notEquals"));
		    }
		    
		case 39: //endOfFile:
			numMatchedChars = matchRegex (endOfFile, cstring  ) ;
		    if (numMatchedChars == 1)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the endOfFile"));
		    }
		    
		case 40: //lexicalError:
			throw (InvalidToken("lexicalError is not a valid token type"));
		    
		default:
			throw (InvalidToken("Terminal type is not supported"));
		
	}
	this->terminal = terminal;
	this->lexeme = lexeme;
}


Token *Scanner::scan(const char *text) {
	size_t text_size = strlen(text);
	const char *text_start = text;
	
	//Token end = new Token(endOfFile, "\0");
	Token *current_token = new Token(endOfFile, '\0');
	current_token->next = NULL;
	Token *results = current_token; 
    // Create the compiled regular expressions.
    
    regex_t *whiteSpace;
    whiteSpace = makeRegex ("^[\n\t\r ]+");

    regex_t *blockComment ;
    blockComment = makeRegex("^/\\*([^\\*]|\\*+[^\\*/])*\\*+/");
    
        // Keywords
    
    regex_t *rnameKwd;
    rnameKwd = makeRegex("^name");
    
    regex_t *rplatformKwd;
    rplatformKwd = makeRegex("^platform");
    
    regex_t *rinitialKwd;
    rinitialKwd = makeRegex("^initial");
    
    regex_t *rstateKwd;
    rstateKwd = makeRegex("^state");
    
    regex_t *rgotoKwd;
    rgotoKwd = makeRegex("^goto");
    
    regex_t *rwhenKwd;
    rwhenKwd = makeRegex("^when");
    
    regex_t *rperformingKwd;
    rperformingKwd = makeRegex("^performing");
    
    regex_t *rexitKwd;
    rexitKwd = makeRegex("^exit");
    
    regex_t *rintKwd;
    rintKwd = makeRegex("^int");
    
    regex_t *rfloatKwd;
    rfloatKwd = makeRegex("^float");
    
    regex_t *rbooleanKwd;
    rbooleanKwd = makeRegex("^boolean");
    
    regex_t *rstringKwd;
    rstringKwd = makeRegex("^string");
    
    regex_t *rcharKwd;
    rcharKwd = makeRegex("^char");
    
    regex_t *rtrueKwd;
    rtrueKwd = makeRegex("^true");
    
    regex_t *rfalseKwd;
    rfalseKwd = makeRegex("^false");
    
    
    //Constants  
    regex_t *rintConst;
    rintConst = makeRegex("^[0-9]+*");
    
    regex_t *rfloatConst;
    rfloatConst = makeRegex("^[0-9]+\\.?[0-9]*");
    
    regex_t *rstringConst;
    rstringConst = makeRegex("^'.*'");
    
    regex_t *rcharConst;
    rcharConst = makeRegex("^[a-zA-Z]");
    
    
    //Names
    regex_t *rvariableName;
    rvariableName = makeRegex("^([a-zA-Z]+)");
    
    //Punctuation    
    regex_t *rleftParen;
    rleftParen = makeRegex("^[(]");
    
    regex_t *rrightParen;
    rrightParen = makeRegex("^[)]");
    
    regex_t *rleftCurly;
    rleftCurly = makeRegex("^[{]");
    
    regex_t *rrightCurly;
    rrightCurly = makeRegex("^[}]");
    
    regex_t *rleftAngle;
    rleftAngle = makeRegex("^[<]");
    
    regex_t *rrightAngle;
    rrightAngle = makeRegex("^[>]");
    
    regex_t *rcolon;
    rcolon = makeRegex("^[:]");
    
    regex_t *rcomma;
    rcomma = makeRegex("^[,]");
    
    regex_t *rsemiColon;
    rsemiColon = makeRegex("^[;]");
    
    regex_t *rassign;
    rassign = makeRegex("^[=]");
    
    regex_t *rplusSign;
    rplusSign = makeRegex("^[+]");
    
    regex_t *rstar;
    rstar = makeRegex("^[*]");
    
    regex_t *rdash;
    rdash = makeRegex("^[-]");
    
    
   	regex_t *rforwardSlash;
    rforwardSlash = makeRegex("^[/]");
    
    regex_t *requalsEquals;
    requalsEquals = makeRegex("^==");
    
    regex_t *rlessThanEquals;
    rlessThanEquals = makeRegex("^<=");
    
    regex_t *rgreaterThanEquals;
    rgreaterThanEquals = makeRegex("^>=");
    
    regex_t *rnotEquals;
    rnotEquals = makeRegex("^!=");
    
    regex_t *rendOfFile;
    rendOfFile = makeRegex("\0");
    
    
    
    /* This enumerated type is used to keep track of what kind of
       construct was matched. 
     */
	tokenEnumType matchType; 
    
    int numMatchedChars = 0;

    /* text is a character pointer that points to the current
       beginning of the array of characters in the input.  Adding an
       integer value to it advances the pointer that many elements in
       the array.  Thus, text is increased so that it points to the
       current location in the input. 
     */

    int maxNumMatchedChars = 0 ;
    int numnameKwd = 0, numplatformKwd = 0, numinitialKwd = 0, numstateKwd = 0, 
    numgotoKwd = 0, numwhenKwd = 0, numperformingKwd = 0, numexitKwd = 0,
    numintKwd = 0, numfloatKwd = 0, numbooleanKwd = 0, numstringKwd = 0, numcharKwd = 0,
    numtrueKwd = 0, numfalseKwd = 0,
    numintConst, numfloatConst, numstringConst, numcharConst,
    numvariableName = 0 ,
    numleftParen = 0, numrightParen = 0, 
    numleftCurly = 0, numrightCurly = 0, 
    numleftAngle = 0, numrightAngle = 0,
    numcolon = 0, numcomma = 0, numsemiColon = 0, 
    numassign = 0, 
    numplusSign = 0, numstar = 0, numdash = 0, numforwardSlash = 0,
    numequalsEquals = 0, numlessThanEquals = 0, numgreaterThanEquals = 0, numnotEquals = 0, 
    numendOfFile = 1;

    while ( text[0] != '\0' ) {
        maxNumMatchedChars = 0 ; matchType = lexicalError ;
        
        // Consume white space and comments before trying again for
        // another word or integer.
        numMatchedChars = consumeWhiteSpaceAndComments (whiteSpace, blockComment, 
                                                        text) ;
        text = text + numMatchedChars ;


        /* maxNumMatchedChars is used to ensure that the regular
           expression that matched the longest string is the one that
           we use.  

           The regexs for word and integerConst cannot match the
           same text, but if we extend this program to search for
           specific keywords, then the keyword regex and the
           word-regex may, in some cases, match the same input text.

           If two regexs match the same number of characters
           then the tie has to be broken.  To break the tie, priority
           is given to the first one that was tried.  Thus the
           comparison
              (numMatchedChars > maxNumMatchedChars) 
           is strictly greater than.  Not greater than or  equal to.
        */

        numMatchedChars = matchRegex (rnameKwd, text) ;
        if (numMatchedChars > maxNumMatchedChars) {
            maxNumMatchedChars = numMatchedChars ;
            matchType = nameKwd ;
        }

        numMatchedChars = matchRegex (rplatformKwd, text) ;
        if (numMatchedChars > maxNumMatchedChars) {
            maxNumMatchedChars = numMatchedChars ;
            matchType = platformKwd ;
        }

   
        numMatchedChars = matchRegex (rinitialKwd, text) ;
        if (numMatchedChars > maxNumMatchedChars) {
            maxNumMatchedChars = numMatchedChars ;
            matchType = initialKwd ;
        }
        
        numMatchedChars = matchRegex (rstateKwd, text) ;
        if (numMatchedChars > maxNumMatchedChars) {
            maxNumMatchedChars = numMatchedChars ;
            matchType = stateKwd ;
        }

        numMatchedChars = matchRegex (rgotoKwd, text) ;
        if (numMatchedChars > maxNumMatchedChars) {
            maxNumMatchedChars = numMatchedChars ;
            matchType = gotoKwd ;
        }

   
        numMatchedChars = matchRegex (rwhenKwd, text) ;
        if (numMatchedChars > maxNumMatchedChars) {
            maxNumMatchedChars = numMatchedChars ;
            matchType = whenKwd ;
        }
        
        numMatchedChars = matchRegex (rperformingKwd, text) ;
        if (numMatchedChars > maxNumMatchedChars) {
            maxNumMatchedChars = numMatchedChars ;
            matchType = performingKwd ;
        }

        numMatchedChars = matchRegex (rexitKwd, text) ;
        if (numMatchedChars > maxNumMatchedChars) {
            maxNumMatchedChars = numMatchedChars ;
            matchType = exitKwd ;
        }

   	    numMatchedChars = matchRegex (rfloatKwd, text) ;
        if (numMatchedChars > maxNumMatchedChars) {
            maxNumMatchedChars = numMatchedChars ;
            matchType = floatKwd ;
        }
        
        numMatchedChars = matchRegex (rintKwd, text) ;
        if (numMatchedChars > maxNumMatchedChars) {
            maxNumMatchedChars = numMatchedChars ;
            matchType = intKwd ;
        }
        

        numMatchedChars = matchRegex (rbooleanKwd, text) ;
        if (numMatchedChars > maxNumMatchedChars) {
            maxNumMatchedChars = numMatchedChars ;
            matchType = booleanKwd ;
        }

   
        numMatchedChars = matchRegex (rstringKwd, text) ;
        if (numMatchedChars > maxNumMatchedChars) {
            maxNumMatchedChars = numMatchedChars ;
            matchType = stringKwd ;
        }
        
        numMatchedChars = matchRegex (rcharKwd, text) ;
        if (numMatchedChars > maxNumMatchedChars) {
            maxNumMatchedChars = numMatchedChars ;
            matchType = charKwd ;
        }

        numMatchedChars = matchRegex (rtrueKwd, text) ;
        if (numMatchedChars > maxNumMatchedChars) {
            maxNumMatchedChars = numMatchedChars ;
            matchType = trueKwd ;
        }

   
        numMatchedChars = matchRegex (rfloatConst, text) ;
        if (numMatchedChars > maxNumMatchedChars) {
            maxNumMatchedChars = numMatchedChars ;
            matchType = floatConst ;
        }

		numMatchedChars = matchRegex (rintConst, text) ;
        if (numMatchedChars > maxNumMatchedChars) {
            maxNumMatchedChars = numMatchedChars ;
            matchType = intConst ;
        }
        
        numMatchedChars = matchRegex (rfalseKwd, text) ;
        if (numMatchedChars > maxNumMatchedChars) {
            maxNumMatchedChars = numMatchedChars ;
            matchType = falseKwd ;
        }
        
        numMatchedChars = matchRegex (rstringConst, text) ;
        if (numMatchedChars > maxNumMatchedChars) {
            maxNumMatchedChars = numMatchedChars ;
            matchType = stringConst ;
        }
        
        numMatchedChars = matchRegex (rcharConst, text) ;
        if (numMatchedChars > maxNumMatchedChars) {
            maxNumMatchedChars = numMatchedChars ;
            matchType = charConst ;
        }
        
        numMatchedChars = matchRegex (rvariableName, text) ;
        if (numMatchedChars > maxNumMatchedChars) {
            maxNumMatchedChars = numMatchedChars ;
            matchType = variableName ;
        }
        
        numMatchedChars = matchRegex (rleftParen, text) ;
        if (numMatchedChars > maxNumMatchedChars) {
            maxNumMatchedChars = numMatchedChars ;
            matchType = leftParen ;
        }
        
        numMatchedChars = matchRegex (rrightParen, text) ;
        if (numMatchedChars > maxNumMatchedChars) {
            maxNumMatchedChars = numMatchedChars ;
            matchType = rightParen ;
        }
        
        numMatchedChars = matchRegex (rleftCurly, text) ;
        if (numMatchedChars > maxNumMatchedChars) {
            maxNumMatchedChars = numMatchedChars ;
            matchType = leftCurly ;
        }
        
        numMatchedChars = matchRegex (rrightCurly, text) ;
        if (numMatchedChars > maxNumMatchedChars) {
            maxNumMatchedChars = numMatchedChars ;
            matchType = rightCurly ;
        }
        
        numMatchedChars = matchRegex (rleftAngle, text) ;
        if (numMatchedChars > maxNumMatchedChars) {
            maxNumMatchedChars = numMatchedChars ;
            matchType = leftAngle ;
        }
        
        numMatchedChars = matchRegex (rrightAngle, text) ;
        if (numMatchedChars > maxNumMatchedChars) {
            maxNumMatchedChars = numMatchedChars ;
            matchType = rightAngle ;
        }
        
        numMatchedChars = matchRegex (rcolon, text) ;
        if (numMatchedChars > maxNumMatchedChars) {
            maxNumMatchedChars = numMatchedChars ;
            matchType = colon ;
        }
        
        numMatchedChars = matchRegex (rcomma, text) ;
        if (numMatchedChars > maxNumMatchedChars) {
            maxNumMatchedChars = numMatchedChars ;
            matchType = comma ;
        }
        
        numMatchedChars = matchRegex (rsemiColon, text) ;
        if (numMatchedChars > maxNumMatchedChars) {
            maxNumMatchedChars = numMatchedChars ;
            matchType = semiColon ;
        }
        
        numMatchedChars = matchRegex (rassign, text) ;
        if (numMatchedChars > maxNumMatchedChars) {
            maxNumMatchedChars = numMatchedChars ;
            matchType = assign ;
        }
        
        numMatchedChars = matchRegex (rplusSign, text) ;
        if (numMatchedChars > maxNumMatchedChars) {
            maxNumMatchedChars = numMatchedChars ;
            matchType = plusSign ;
        }
        
        numMatchedChars = matchRegex (rstar, text) ;
        if (numMatchedChars > maxNumMatchedChars) {
            maxNumMatchedChars = numMatchedChars ;
            matchType = star ;
        }
        
        numMatchedChars = matchRegex (rdash, text) ;
        if (numMatchedChars > maxNumMatchedChars) {
            maxNumMatchedChars = numMatchedChars ;
            matchType = dash ;
        }
        
        numMatchedChars = matchRegex (rforwardSlash, text) ;
        if (numMatchedChars > maxNumMatchedChars) {
            maxNumMatchedChars = numMatchedChars ;
            matchType = forwardSlash ;
        }
        
        numMatchedChars = matchRegex (requalsEquals, text) ;
        if (numMatchedChars > maxNumMatchedChars) {
            maxNumMatchedChars = numMatchedChars ;
            matchType = equalsEquals ;
        }
        
        numMatchedChars = matchRegex (rlessThanEquals, text) ;
        if (numMatchedChars > maxNumMatchedChars) {
            maxNumMatchedChars = numMatchedChars ;
            matchType = lessThanEquals ;
        }
        
        numMatchedChars = matchRegex (rgreaterThanEquals, text) ;
        if (numMatchedChars > maxNumMatchedChars) {
            maxNumMatchedChars = numMatchedChars ;
            matchType = greaterThanEquals ;
        }
        
        numMatchedChars = matchRegex (rnotEquals, text) ;
        if (numMatchedChars > maxNumMatchedChars) {
            maxNumMatchedChars = numMatchedChars ;
            matchType = notEquals ;
        }    
        
		//buffer used to store input string        
        string buffer;
        switch (matchType) 
        {
		case 1://nameKwd: 
			++numnameKwd; 
			results = new Token(nameKwd, "name"); 
			results->next = current_token; 
			current_token = results; 			
			break;
			
		case 2://platformKwd: 
			++numplatformKwd; 
			results = new Token(platformKwd, "platform"); 
			results->next = current_token; 
			current_token = results; 			
			break;	
			
		case 3://initialKwd: 
			++numinitialKwd; 
			results = new Token(initialKwd, "initial"); 
			results->next = current_token; 
			current_token = results; 			
			break;
			
		case 4://stateKwd: 
			++numstateKwd; 
			results = new Token(stateKwd, "state"); 
			results-> next = current_token; 
			current_token = results; 			
			break;
			
		case 5://gotoKwd: 
			++numgotoKwd; 
			results = new Token(gotoKwd, "goto"); 
			results->next = current_token; 
			current_token = results; 			
			break;
			
		case 6://whenKwd: 
			++numwhenKwd; 
			results = new Token(whenKwd, "when"); 
			results->next = current_token; 
			current_token = results; 			
			break;
			
		case 7://performingKwd: 
			++numperformingKwd; 
			results = new Token(performingKwd, "performing"); 
			results->next = current_token; 
			current_token = results; 			
			break;
			
		case 8://exitKwd: 
			++numexitKwd; 
			results = new Token(exitKwd, "exit"); 
			results->next = current_token; 
			current_token = results; 			
			break;
			
		case 9://intKwd: 
			++numintKwd; 
			results = new Token(intKwd, "int"); 
			results->next = current_token; 
			current_token = results; 			
			break;
			
		case 10://floatKwd: 
			++numfloatKwd; 
			results = new Token(floatKwd, "float"); 
			results->next = current_token; 
			current_token = results; 			
			break;
			
		case 11://booleanKwd: 
			++numbooleanKwd; 
			results = new Token(booleanKwd, "boolean"); 
			results->next = current_token; 
			current_token = results; 			
			break;
			
		case 12://stringKwd: 
			++numstringKwd; 
			results = new Token(stringKwd, "string"); 
			results->next = current_token; 
			current_token = results; 			
			break;
			
        case 13://charKwd: 
			++numcharKwd; 
			results = new Token(charKwd, "char"); 
			results->next = current_token; 
			current_token = results; 			
			break;
			
		case 14://trueKwd: 
			++numtrueKwd; 
			results = new Token(trueKwd, "true"); 
			results->next = current_token; 
			current_token = results; 			
			break;
			
		case 15://falseKwd: 
			++numfalseKwd; 
			results = new Token(falseKwd, "false"); 
			results->next = current_token; 
			current_token = results; 			
			break;
			
		case 16://intConst: 
			++numintConst; 
			buffer = string(text, maxNumMatchedChars);
			results = new Token(intConst, buffer); 
			results->next = current_token; 
			current_token = results; 			
			break;
			
		case 17://floatConst: 
			++numfloatConst; 
			buffer = string (text, maxNumMatchedChars);
			results = new Token(floatConst, buffer); 
			results->next = current_token; 
			current_token = results; 			
			break;
			
		case 18://stringConst: 
			++numstringConst;
			buffer = string (text, maxNumMatchedChars);
			results = new Token(stringConst, buffer); 
			results->next = current_token; 
			current_token = results; 			
			break;
			
		case 19://charConst: 
			++numcharConst;
			buffer = string (text, 1);
			results = new Token(charConst, buffer); 
			results->next = current_token; 
			current_token = results; 			
			break;
			
		case 20://variableName: 
			++numvariableName;
			buffer = string (text, maxNumMatchedChars);
			results = new Token(variableName, buffer); 
			results->next = current_token; 
			current_token = results; 			
			break;
			
		case 21://leftParen: 
			++numleftParen; 
			results = new Token(leftParen, "("); 
			results->next = current_token; 
			current_token = results; 			
			break;
			
		case 22://rightParen: 
			++numrightParen; 
			results = new Token(rightParen, ")"); 
			results->next = current_token; 
			current_token = results; 			
			break;
		
		case 23://leftCurly: 
			++numleftCurly; 
			results = new Token(leftCurly, "{"); 
			results->next = current_token; 
			current_token = results; 			
			break;
			
		case 24://rightCurly: 
			++numrightCurly; 
			results = new Token(rightCurly, "}"); 
			results->next = current_token; 
			current_token = results; 			
			break;
			
		case 25://leftAngle: 
			++numleftAngle; 
			results = new Token(leftAngle, "<"); 
			results->next = current_token; 
			current_token = results; 			
			break;
			
		case 26://rightAngle: 
			++numrightAngle; 
			results = new Token(rightAngle, ">"); 
			results->next = current_token; 
			current_token = results; 			
			break;
			
		case 27://colon: 
			++numcolon; 
			results = new Token(colon, ":"); 
			results->next = current_token; 
			current_token = results; 			
			break;
			
		case 28://comma: 
			++numcomma;
			results = new Token(comma, ","); 
			results->next = current_token; 
			current_token = results; 			
			break;
			
		case 29://semiColon: 
			++numsemiColon; 
			results = new Token(semiColon, ";"); 
			results->next = current_token; 
			current_token = results; 			
			break;
			
		case 30://assign: 
			++numassign; 
			results = new Token(assign, "="); 
			results->next = current_token; 
			current_token = results; 			
			break;
			
		case 31://plusSign: 
			++numplusSign; 
			results = new Token(plusSign, "+"); 
			results->next = current_token; 
			current_token = results; 			
			break;
			
		case 32://star: 
			++numstar; 
			results = new Token(star, "*"); 
			results->next = current_token; 
			current_token = results; 			
			break;
			
		case 33://dash: 
			++numdash; 
			results = new Token(dash, "-"); 
			results->next = current_token; 
			current_token = results; 			
			break;
			
		case 34://forwardSlash: 
			++numforwardSlash; 
			results = new Token(forwardSlash, "/"); 
			results->next = current_token; 
			current_token = results; 			
			break;
			
		case 35://equalsEquals: 
			++numequalsEquals; 
			results = new Token(equalsEquals, "=="); 
			results->next = current_token; 
			current_token = results; 			
			break;
			
		case 36://lessThanEquals: 
			++numlessThanEquals; 
			results = new Token(lessThanEquals, "<="); 
			results->next = current_token; 
			current_token = results; 			
			break;
		
		case 37://greaterThanEquals: 
			++numgreaterThanEquals; 
			results = new Token(greaterThanEquals, ">="); 
			results->next = current_token; 
			current_token = results; 			
			break;
			
		case 38://notEquals: 
			++numnotEquals; 
			results = new Token(notEquals, "!="); 
			results->next = current_token; 
			current_token = results; 			
			break;

        if (matchType == lexicalError) {
        	//if at the end of the text
        	if (text == (text_start+text_size-1) && text[0] != '\0') {
 				buffer = string (text, 1);
        		results = new Token(lexicalError, buffer);
        		results->next = current_token;
        		return results;
        	}
        }
        else {
            // Consume the characters that were matched.
            text = text + maxNumMatchedChars ;
        }
    }

    /* In this application the only information we collect is the
       number of words and number of integer constants.  In a scanner
       we would need to accumulate the list of tokens. */
    
    return results;

    /* You will add another printf statement to print the number of
       "Foo" keywords.  All of these numbers should be on separate
       lines.  In assessing your work we will require that your output
       exactly match ours: no extra spaces and each number on a
       separate line. */
	}
}
