#include "scanner.h"
#include <stdio.h>
#include <stdlib.h>
#include "readInput.h"
#include <sys/stat.h>
#include <sys/types.h> 
#include <stdexcept>
#include <string.h>
#include "syntaxDefinitions.h"

using namespace std; 

int consumeWhiteSpaceAndComments (regex_t *whiteSpace, 
                                  regex_t *blockComment,
				  regex_t *lineComment,
                                  const char *text) {
    int numMatchedChars = 0 ;
    int totalNumMatchedChars = 0 ;
    int stillConsumingWhiteSpace ;

    do {
        stillConsumingWhiteSpace = 0 ;  
        // exit loop if not reset by a match

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
    int numMatchedChars = 0;
    const char *cstring = lexeme.c_str();
    
	switch(terminal) {
		case 1: //rnameKwd:
			numMatchedChars = matchRegex (rnameKwd, cstring  );
		    if (numMatchedChars == 4)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the nameKwd"));
		    }
			
		case 2: //rplatformKwd:
			numMatchedChars = matchRegex (rplatformKwd, cstring  );
		    if (numMatchedChars == 8)
		   	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the platformKwd"));
		    }
		    
		case 3: //rinitialKwd:
			numMatchedChars = matchRegex (rinitialKwd, cstring  );
		    if (numMatchedChars == 7)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the initialKwd"));
		    }
		    
		case 4: //rstateKwd:
			numMatchedChars = matchRegex (rstateKwd, cstring  ) ;
		    if (numMatchedChars == 5)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the stateKwd"));
		    }
		    
		case 5: //rgotoKwd:
			numMatchedChars = matchRegex (rgotoKwd, cstring  ) ;
		    if (numMatchedChars == 4)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the gotoKwd"));
		    }
		case 6: //whenKwd:
			numMatchedChars = matchRegex (rwhenKwd, cstring  ) ;
		    if (numMatchedChars == 4)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the whenKwd"));
		    }
		    
		case 7: //performingKwd:
			numMatchedChars = matchRegex (rperformingKwd, cstring);
		    if (numMatchedChars == 10)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the performingKwd"));
		    }
		    
		case 8: //exitKwd:
			numMatchedChars = matchRegex (rexitKwd, cstring  ) ;
		    if (numMatchedChars == 4)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the exitKwd"));
		    }
		    
		case 9: //intKwd:
			numMatchedChars = matchRegex (rintKwd, cstring  ) ;
		    if (numMatchedChars == 3)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the intKwd"));
		    }
		    
		case 10: //floatKwd:
			numMatchedChars = matchRegex (rfloatKwd, cstring  ) ;
		    if (numMatchedChars == 5)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the floatKwd"));
		    }
		    
		case 11: //booleanKwd:
			numMatchedChars = matchRegex (rbooleanKwd, cstring  ) ;
		    if (numMatchedChars == 7)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the booleanKwd"));
		    }
		    
		case 12: //stringKwd:
			numMatchedChars = matchRegex (rstringKwd, cstring  ) ;
		    if (numMatchedChars == 6)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the stringKwd"));
		    }
		    
		case 13: //charKwd:
			numMatchedChars = matchRegex (rcharKwd, cstring  ) ;
		    if (numMatchedChars == 4)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the charKwd"));
		    }
		    
		case 14: //trueKwd:
			numMatchedChars = matchRegex (rtrueKwd, cstring  ) ;
		    if (numMatchedChars == 4)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the trueKwd"));
		    }
		    
		case 15: //falseKwd:
			numMatchedChars = matchRegex (rfalseKwd, cstring  ) ;
		    if (numMatchedChars == 5)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the falseKwd"));
		    }
		   
		case 16: //intConst:
			numMatchedChars = matchRegex (rintConst, cstring  ) ;
		    if (numMatchedChars > 0)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the intConst"));
		    }
		    
		case 17: //floatConst:
			numMatchedChars = matchRegex (rfloatConst, cstring  ) ;
		    if (numMatchedChars > 0)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the floatConst"));
		    }
		    
		case 18: //stringConst:
			numMatchedChars = matchRegex (rstringConst, cstring  ) ;
		    if (numMatchedChars > 0)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the stringConst"));
		    }
		    
		case 19: //charConst:
			numMatchedChars = matchRegex (rcharConst, cstring) ;
		    if (numMatchedChars == 3 || numMatchedChars == 4 )
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the charConst"));
		    }
		    
		case 20: //variableName:
			numMatchedChars = matchRegex (rvariableName, cstring);
		    if (numMatchedChars > 0)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the variableName"));
		    }
		   
		case 21: //leftParen:
			numMatchedChars = matchRegex (rleftParen, cstring); 
		    if (numMatchedChars == 1) 
		    	break; 
	    	else {	
	    		throw (InvalidToken("lexeme is not the leftParen"));
		    }
		    
		case 22: //rightParen:
			numMatchedChars = matchRegex (rrightParen, cstring);
		    if (numMatchedChars == 1)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the rightParen"));
		    }
		    
		case 23: //leftCurly:
			numMatchedChars = matchRegex (rleftCurly, cstring) ;
		    if (numMatchedChars == 1)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the leftCurly"));
		    }
		    
		case 24: //rightCurly: 
			numMatchedChars = matchRegex (rrightCurly, cstring);
		    if (numMatchedChars == 1)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the rightCurly"));
		    }
		    
		case 25: //leftAngle:
			numMatchedChars = matchRegex (rleftAngle, cstring);
		    if (numMatchedChars == 1)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the leftAngle"));
		    }
		    
		case 26: //rightAngle:
			numMatchedChars = matchRegex (rrightAngle, cstring);
		    if (numMatchedChars == 1)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the rightAngle"));
		    }
	    
		case 27: //colon:
			numMatchedChars = matchRegex (rcolon, cstring);
		    if (numMatchedChars == 1)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the colon"));
		    }
		    
		case 28: //comma:
			numMatchedChars = matchRegex (rcomma, cstring);
		    if (numMatchedChars == 1)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the comma"));
		    }
		    
		case 29: //semiColon: 
			numMatchedChars = matchRegex (rsemiColon, cstring);
		    if (numMatchedChars == 1)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the semiColon"));
		    }
		    
		case 30: //assign: 
			numMatchedChars = matchRegex (rassign, cstring);
		    if (numMatchedChars == 2)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the assign"));
		    }
		    
		case 31: //plusSign:
			numMatchedChars = matchRegex (rplusSign, cstring);
		    if (numMatchedChars == 1)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the plusSign"));
		    }
		    
		case 32: //star:
			numMatchedChars = matchRegex (rstar, cstring);
		    if (numMatchedChars == 1)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the star"));
		    }
		    
		case 33: //dash:
			numMatchedChars = matchRegex (rdash, cstring);
		    if (numMatchedChars == 1)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the dash"));
		    }
		    
		case 34: //forwardSlash:
			numMatchedChars = matchRegex (rforwardSlash, cstring  ) ;
		    if (numMatchedChars == 1)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the forwardSlash"));
		    }
		    
		case 35: //equalsEquals:
			numMatchedChars = matchRegex (requalsEquals, cstring  ) ;
		    if (numMatchedChars == 2)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the equalsEquals"));
		    }
		    
		case 36: //lessThanEquals:
			numMatchedChars = matchRegex (rlessThanEquals, cstring  ) ;
		    if (numMatchedChars == 2)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the lessThanEquals"));
		    }
		    
		case 37: //greaterThanEquals:
			numMatchedChars = matchRegex (rgreaterThanEquals, cstring  ) ;
		    if (numMatchedChars == 2)
		    	break;
	    	else {		
	    		throw (InvalidToken("lexeme is not the greaterThanEquals"));
		    }
		    
		case 38: //notEquals:
			numMatchedChars = matchRegex (rnotEquals, cstring  ) ;
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
			numMatchedChars = matchRegex (rlexicalError, cstring) ;
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
    Token *cabous_token = head_token;
    
     
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

    return head_token->next;
}
