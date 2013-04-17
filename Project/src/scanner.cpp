#include "readInput.h"
#include "regex.h"

using namespace std; 
#include "scanner.h"
#include "syntaxDefinitions.h"

Token::Token (tokenType terminal, string lexeme) {
   init (lexeme, terminal, NULL);
}

Token::Token (string lexeme, tokenType terminal) {
   init (lexeme, terminal, NULL);
}

Token::Token (string lexeme, tokenType terminal, Token* next) {
   init(lexeme, terminal, next);
}

Token::Token (const char* lexeme, tokenType terminal, Token* next){
   string s = lexeme;
   init(s, terminal, next);
}

void Token::init(string lexeme, tokenType terminal, Token* next) {
	this->terminal = terminal;
	this->lexeme = lexeme;
	this->next = next;
}

tokenType Token::get_terminal() {return this->terminal;};
string Token::get_lexeme() {return this->lexeme;};
Token* Token::get_next() {return this->next;};
void Token::set_next(Token* next){
	this->next = next;
}

tokenType TokenBuilder::get_terminal() {return this->terminal;};

int TokenBuilder::checkMatch(const char* lexeme){
	int ret = matchRegex(this->lexeme_pattern, lexeme);
	return ret;
}

void TokenBuilder::throwError(){
	throw InvalidToken(this->err_string);
}

TokenBuilder::TokenBuilder(regex_t *lexeme_pattern, tokenType terminal) {
	this->lexeme_pattern = lexeme_pattern;
	this->terminal = terminal;
}

TokenBuilder::TokenBuilder(tokenType terminal, regex_t *lexeme_pattern) {
	this->lexeme_pattern = lexeme_pattern;
	this->terminal = terminal;
}

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

Scanner::Scanner() {
	this->buildSyntax();
}



Token *Scanner::scan(const char *text) {   	
    //The tail token is always an endOfFile	
    Token *tail_token = new Token(endOfFile, "");
    //The tail token's next is always null
    tail_token->set_next(NULL);

    //head is junk used to keep track of the front of the list
    Token *head_token = new Token(endOfFile, "");
    head_token->set_next(tail_token);

    //temp is a swap variable
    Token *temp_token = head_token;

    //back keeps track of the token before tail
    Token *back_token = head_token;
    
    int numMatchedChars = 0;
    tokenType matchType;

    /* text is a character pointer that points to the current
       beginning of the array of characters in the input.  Adding an
       integer value to it advances the pointer that many elements in
       the array.  Thus, text is increased so that it points to the
       current location in the input. 
     */

    int maxNumMatchedChars = 0 ;

    //consume whitespace to ensure there are no tokens in the text
    numMatchedChars = consumeWhiteSpaceAndComments(this->whiteSpace, this->blockComment, this->lineComment, text);
    text = text + numMatchedChars;

    //Search until end of file
    while ( text[0] != '\0' ) {
        maxNumMatchedChars = 0 ; 
        
        // Consume white space and comments before trying again for
        // another word or integer.
        numMatchedChars = consumeWhiteSpaceAndComments(this->whiteSpace, this->blockComment, this->lineComment, text);
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

	matchType = noMatch;
	string lexeme(text);
	//Iterates through all lexemes to check for a match
  	for (int i = 0; i < this->syntax_size; i++) {
		  numMatchedChars = this->token_builders[i].checkMatch(text);
        	if (numMatchedChars > maxNumMatchedChars) {
        	    maxNumMatchedChars = numMatchedChars;
          	    matchType = this->token_builders[i].get_terminal();
	   	}
   	}

	//check that a match is found before storing	    
	if (matchType != noMatch) {
	 	string buffer = string (text, maxNumMatchedChars);
	 	temp_token = new Token(string(buffer), matchType, tail_token); 
	 	back_token->set_next(temp_token);
	 	back_token = temp_token; 
	}
		// Consume the characters that were matched.
		text = text + maxNumMatchedChars;
    }
    return head_token->get_next();
}
