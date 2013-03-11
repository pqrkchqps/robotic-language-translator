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
				  regex_t *lineComment,
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

	//Check for line comment
        numMatchedChars = matchRegex (lineComment, text) ;
        totalNumMatchedChars += numMatchedChars ;
        if (numMatchedChars > 0) {
            text = text + numMatchedChars ;
            stillConsumingWhiteSpace = 1 ;
        }
	
    }
    while ( stillConsumingWhiteSpace ) ;    

    return totalNumMatchedChars ;
};
 
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
    intConst = makeRegex("^[0-9]+");
    regex_t *floatConst;
    floatConst = makeRegex("^[0-9]+[.][0-9]+");
    regex_t *stringConst;
    stringConst = makeRegex("^\"[^\"]*\"");
    regex_t *charConst;
    charConst = makeRegex("^'([\\])?[^'\n\t\r ]'");
    regex_t *variableName;
    variableName = makeRegex("^([_a-zA-Z][a-zA-Z_0-9]*)");
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
    assign = makeRegex("^:=");
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
    regex_t *lexicalError;
    lexicalError = makeRegex("^.");  
    int numMatchedChars = 0;
    const char *cstring = lexeme.c_str();
    
	switch(terminal) {
		case 1: //nameKwd:
			numMatchedChars = matchRegex (nameKwd, cstring  );
		    if (numMatchedChars == 4)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the nameKwd"));
		    }
			
		case 2: //platformKwd:
			numMatchedChars = matchRegex (platformKwd, cstring  );
		    if (numMatchedChars == 8)
		   	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the platformKwd"));
		    }
		    
		case 3: //initialKwd:
			numMatchedChars = matchRegex (initialKwd, cstring  );
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
			numMatchedChars = matchRegex (performingKwd, cstring);
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
		    if (numMatchedChars == 3 || numMatchedChars == 4 )
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
			numMatchedChars = matchRegex (rightCurly, cstring);
		    if (numMatchedChars == 1)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the rightCurly"));
		    }
		    
		case 25: //leftAngle:
			numMatchedChars = matchRegex (leftAngle, cstring);
		    if (numMatchedChars == 1)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the leftAngle"));
		    }
		    
		case 26: //rightAngle:
			numMatchedChars = matchRegex (rightAngle, cstring);
		    if (numMatchedChars == 1)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the rightAngle"));
		    }
	    
		case 27: //colon:
			numMatchedChars = matchRegex (colon, cstring);
		    if (numMatchedChars == 1)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the colon"));
		    }
		    
		case 28: //comma:
			numMatchedChars = matchRegex (comma, cstring);
		    if (numMatchedChars == 1)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the comma"));
		    }
		    
		case 29: //semiColon: 
			numMatchedChars = matchRegex (semiColon, cstring);
		    if (numMatchedChars == 1)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the semiColon"));
		    }
		    
		case 30: //assign: 
			numMatchedChars = matchRegex (assign, cstring);
		    if (numMatchedChars == 2)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the assign"));
		    }
		    
		case 31: //plusSign:
			numMatchedChars = matchRegex (plusSign, cstring);
		    if (numMatchedChars == 1)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the plusSign"));
		    }
		    
		case 32: //star:
			numMatchedChars = matchRegex (star, cstring);
		    if (numMatchedChars == 1)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the star"));
		    }
		    
		case 33: //dash:
			numMatchedChars = matchRegex (dash, cstring);
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
		    
		case 35: //equalsEquals:
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
		    if ( lexeme.empty() )
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the endOfFile"));
		    }
		    
		case 40: //lexicalError:
			numMatchedChars = matchRegex (lexicalError, cstring) ;
			if (numMatchedChars == 1)
				break;
		else {
			throw (InvalidToken("lexeme is not a lexicalError"));
			}
		    
		default:
			throw (InvalidToken("Terminal type is not supported"));
		
	}
	this->terminal = terminal;
	this->lexeme = lexeme;
}


Token *Scanner::scan(const char *text) {
	size_t text_size = strlen(text);
	const char *text_start = text;
	
	Token *tail_token = new Token(endOfFile, "");
	tail_token->next = NULL;
	Token *head_token = new Token(endOfFile, "");
	head_token->next = tail_token;
	Token *temp_token = head_token;
	Token *cabous_token =head_token;
    	// Create the compiled regular expressions.
    
    regex_t *whiteSpace;
    whiteSpace = makeRegex ("^[\n\t\r ]+");

    regex_t *blockComment ;
    blockComment = makeRegex("^/\\*([^\\*]|\\*+[^\\*/])*\\*+/");

    regex_t *lineComment;
    lineComment = makeRegex("^//([^\n])*");
    
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
    rfloatConst = makeRegex("^[0-9]+*\\.[0-9]+*");
    
    regex_t *rstringConst;
    rstringConst = makeRegex("^\"[^\"]*\"");
    
    regex_t *rcharConst;
    rcharConst = makeRegex("^'([\\])?[^'\n\t\r ]'");
       
    //Names
    regex_t *rvariableName;
    rvariableName = makeRegex("^([_a-zA-Z][a-zA-Z_0-9]*)");
    
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
    rassign = makeRegex("^:=");
    
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
    numendOfFile = 1, numlexicalError = 0;

    while ( text[0] != '\0' ) {
        maxNumMatchedChars = 0 ; matchType = lexicalError ;
        
        // Consume white space and comments before trying again for
        // another word or integer.
        numMatchedChars = consumeWhiteSpaceAndComments(whiteSpace, blockComment, lineComment, text);
        text = text + numMatchedChars;


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
            maxNumMatchedChars = numMatchedChars;
            matchType = stringConst ;
        }
  
        numMatchedChars = matchRegex (rcharConst, text) ;
        if (numMatchedChars > maxNumMatchedChars) {
            maxNumMatchedChars = numMatchedChars;
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
       
	string buffer;  
        switch (matchType) 
        {
		case 1://nameKwd: 
			++numnameKwd; 
			temp_token = new Token(nameKwd, "name"); 
			cabous_token->next = temp_token;
			temp_token->next = tail_token;
			cabous_token = temp_token; 			
			break;
			
		case 2://platformKwd: 
			++numplatformKwd; 
			temp_token = new Token(platformKwd, "platform"); 
			cabous_token->next = temp_token;	 
			temp_token-> next = tail_token; 
			cabous_token = temp_token; 
			break;	
			
		case 3://initialKwd: 
			++numinitialKwd; 
			temp_token = new Token(initialKwd, "initial"); 
			cabous_token->next = temp_token;	 
			temp_token->next = tail_token; 
			cabous_token = temp_token; 
			break;
			
		case 4://stateKwd: 
			++numstateKwd; 
			temp_token = new Token(stateKwd, "state"); 
			cabous_token->next = temp_token;	 
			temp_token->next = tail_token; 
			cabous_token = temp_token; 
			break;
			
		case 5://gotoKwd: 
			++numgotoKwd; 
			temp_token = new Token(gotoKwd, "goto"); 
			cabous_token->next = temp_token;	 
			temp_token->next = tail_token; 
			cabous_token = temp_token; 
			break;
			
		case 6://whenKwd: 
			++numwhenKwd; 
			temp_token = new Token(whenKwd, "when"); 
			cabous_token->next = temp_token; 
			temp_token->next = tail_token; 
			cabous_token = temp_token; 
			break;
			
		case 7://performingKwd: 
			++numperformingKwd; 
			temp_token = new Token(performingKwd, "performing"); 
			cabous_token->next = temp_token; 
			temp_token->next = tail_token; 
			cabous_token =temp_token; 
			break;
			
		case 8://exitKwd: 
			++numexitKwd; 
			temp_token = new Token(exitKwd, "exit"); 
			cabous_token->next = temp_token; 
			temp_token->next = tail_token; 
			cabous_token =temp_token; 
			break;
			
		case 9://intKwd: 
			++numintKwd; 
			temp_token = new Token(intKwd, "int"); 
			cabous_token->next = temp_token;	 
			temp_token->next = tail_token; 
			cabous_token =temp_token; 
			break;
			
		case 10://floatKwd: 
			++numfloatKwd; 
			temp_token = new Token(floatKwd, "float"); 
			cabous_token->next = temp_token;	 
			temp_token->next = tail_token; 
			cabous_token =temp_token; 
			break;
			
		case 11://booleanKwd: 
			++numbooleanKwd; 
			temp_token = new Token(booleanKwd, "boolean"); 
			cabous_token->next = temp_token;	 
			temp_token->next = tail_token; 
			cabous_token =temp_token; 
			break;
			
		case 12://stringKwd: 
			++numstringKwd; 
			temp_token = new Token(stringKwd, "string"); 
			cabous_token->next = temp_token; 
			temp_token->next = tail_token; 
			cabous_token =temp_token; 
			break;
			
        	case 13://charKwd: 
			++numcharKwd; 
			temp_token = new Token(charKwd, "char"); 
			cabous_token->next = temp_token;	 
			temp_token->next = tail_token;
			cabous_token =temp_token; 
			break;
			
		case 14://trueKwd: 
			++numtrueKwd; 
			temp_token = new Token(trueKwd, "true"); 
			cabous_token->next = temp_token;
		 	temp_token->next = tail_token; 
			cabous_token =temp_token; 
			break;
			
		case 15://falseKwd: 
			++numfalseKwd; 
			temp_token = new Token(falseKwd, "false"); 
			cabous_token->next = temp_token;	 
			temp_token->next = tail_token; 
			cabous_token =temp_token; 
			break;
			
		case 16://intConst: 
			++numintConst; 
			buffer = string(text, maxNumMatchedChars);
			temp_token = new Token(intConst, buffer); 
			cabous_token->next = temp_token; 
			temp_token->next = tail_token; 
			cabous_token =temp_token; 
			break;
			
		case 17://floatConst: 
			++numfloatConst; 
			buffer = string (text, maxNumMatchedChars);
			temp_token = new Token(floatConst, buffer); 
			cabous_token->next = temp_token; 
			temp_token->next = tail_token; 
			cabous_token =temp_token; 
			break;
			
		case 18://stringConst: 
			++numstringConst;
			buffer = string (text, maxNumMatchedChars);
			temp_token = new Token(stringConst, buffer); 
			cabous_token->next = temp_token; 
			temp_token->next = tail_token; 
			cabous_token =temp_token; 
			break;
			
		case 19://charConst: 
			++numcharConst;
			buffer = string (text, maxNumMatchedChars);
			temp_token = new Token(charConst, buffer); 
			cabous_token->next = temp_token;	 
			temp_token->next = tail_token; 
			cabous_token = temp_token; 
			break;
			
		case 20://variableName: 
			++numvariableName;
			buffer = string (text, maxNumMatchedChars);
			temp_token = new Token(variableName, buffer); 
			cabous_token->next = temp_token; 
			temp_token->next = tail_token; 
			cabous_token =temp_token; 
			break;
			
		case 21://leftParen: 
			++numleftParen; 
			temp_token = new Token(leftParen, "("); 
			cabous_token->next = temp_token; 
			temp_token->next = tail_token; 
			cabous_token =temp_token; 
			break;
			
		case 22://rightParen: 
			++numrightParen; 
			temp_token = new Token(rightParen, ")"); 
			cabous_token->next = temp_token; 
			temp_token->next = tail_token; 
			cabous_token =temp_token; 
			break;
		
		case 23://leftCurly: 
			++numleftCurly; 
			temp_token = new Token(leftCurly, "{"); 
			cabous_token->next = temp_token; 
			temp_token->next = tail_token; 
			cabous_token =temp_token; 
			break;
			
		case 24://rightCurly: 
			++numrightCurly; 
			temp_token = new Token(rightCurly, "}"); 
			cabous_token->next = temp_token; 
			temp_token->next = tail_token; 
			cabous_token =temp_token; 
			break;
			
		case 25://leftAngle: 
			++numleftAngle; 
			temp_token = new Token(leftAngle, "<"); 
			cabous_token->next = temp_token; 
			temp_token->next = tail_token; 
			cabous_token =temp_token; 
			break;
			
		case 26://rightAngle: 
			++numrightAngle; 
			temp_token = new Token(rightAngle, ">"); 
			cabous_token->next = temp_token; 
			temp_token->next = tail_token; 
			cabous_token =temp_token; 
			break;
			
		case 27://colon: 
			++numcolon; 
			temp_token = new Token(colon, ":"); 
			cabous_token->next = temp_token; 
			temp_token->next = tail_token; 
			cabous_token =temp_token; 
			break;
			
		case 28://comma: 
			++numcomma;
			temp_token = new Token(comma, ","); 
			cabous_token->next = temp_token; 
			temp_token->next = tail_token; 
			cabous_token =temp_token; 
			break;
			
		case 29://semiColon: 
			++numsemiColon; 
			temp_token = new Token(semiColon, ";"); 
			cabous_token->next = temp_token; 
			temp_token->next = tail_token; 
			cabous_token =temp_token; 
			break;
			
		case 30://assign: 
			++numassign; 
			temp_token = new Token(assign, ":="); 
			cabous_token->next = temp_token; 
			temp_token->next = tail_token; 
			cabous_token =temp_token; 
			break;
			
		case 31://plusSign: 
			++numplusSign; 
			temp_token = new Token(plusSign, "+"); 
			cabous_token->next = temp_token; 
			temp_token->next = tail_token; 
			cabous_token =temp_token; 
			break;
			
		case 32://star: 
			++numstar; 
			temp_token = new Token(star, "*"); 
			cabous_token->next = temp_token; 
			temp_token->next = tail_token; 
			cabous_token =temp_token; 
			break;
			
		case 33://dash: 
			++numdash; 
			temp_token = new Token(dash, "-"); 
			cabous_token->next = temp_token;
			temp_token->next = tail_token; 
			cabous_token =temp_token; 
			break;
			
		case 34://forwardSlash: 
			++numforwardSlash; 
			temp_token = new Token(forwardSlash, "/"); 
			cabous_token->next = temp_token; 
			temp_token->next = tail_token; 
			cabous_token = temp_token; 
			break;
			
		case 35://equalsEquals: 
			++numequalsEquals; 
			temp_token = new Token(equalsEquals, "=="); 
			cabous_token->next = temp_token; 
			temp_token->next = tail_token; 
			cabous_token = temp_token; 
			break;
			
		case 36://lessThanEquals: 
			++numlessThanEquals; 
			temp_token = new Token(lessThanEquals, "<="); 
			cabous_token->next = temp_token; 
			temp_token->next = tail_token; 
			cabous_token = temp_token; 
			break;
		
		case 37://greaterThanEquals: 
			++numgreaterThanEquals; 
			temp_token = new Token(greaterThanEquals, ">="); 
			cabous_token->next = temp_token; 
			temp_token->next = tail_token; 
			cabous_token = temp_token; 
			break;
			
		case 38://notEquals: 
			++numnotEquals; 
			temp_token = new Token(notEquals, "!="); 
			cabous_token->next = temp_token; 
			temp_token->next = tail_token; 
			cabous_token = temp_token; 
			break;

		default: 
			if( text[0] != '\0') {
				++numlexicalError;
				buffer = string(text, 1); 
				temp_token = new Token(lexicalError, buffer); 
				cabous_token->next = temp_token; 
				temp_token->next = tail_token; 
				cabous_token = temp_token; 
				maxNumMatchedChars = 1; 
			}			

        }
            // Consume the characters that were matched.
            text = text + maxNumMatchedChars ;
    }

    /* In this application the only information we collect is the
       number of words and number of integer constants.  In a scanner
       we would need to accumulate the list of tokens. */
    
    return head_token->next;

    /* You will add another printf statement to print the number of
       "Foo" keywords.  All of these numbers should be on separate
       lines.  In assessing your work we will require that your output
       exactly match ours: no extra spaces and each number on a
       separate line. */
  
}
