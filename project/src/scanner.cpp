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

int TokenType::checkMatch(const char* lexeme){
	int ret = matchRegex(this->lexeme_pattern, lexeme);
	return ret;
}

void TokenType::throwError(){
	throw InvalidToken(this->err_string);
}

TokenType::TokenType(regex_t *lexeme_pattern, tokenType terminal,
					bool (*err_checking_func)(int numMatchedChars,string lexeme), const char* err_string) {
	this->lexeme_pattern = lexeme_pattern;
	this->terminal = terminal;
	this->checkError = err_checking_func;
	this->err_string = err_string;
}

TokenType::TokenType(tokenType terminal, regex_t *lexeme_pattern, 
				bool (*err_checking_func)(int numMatchedChars,string lexeme), const char* err_string) {
	this->lexeme_pattern = lexeme_pattern;
	this->terminal = terminal;
	this->checkError = err_checking_func;
	this->err_string = err_string;
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
    Token *tail_token = new Token(endOfFile, "");
    tail_token->next = NULL;
    Token *head_token = new Token(endOfFile, "");
    head_token->next = tail_token;
    Token *temp_token = head_token;
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
    numMatchedChars = consumeWhiteSpaceAndComments(this->whiteSpace, this->blockComment, this->lineComment, text);
    text = text + numMatchedChars;

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
	  	for (int i = 0; i < this->syntax_size; i++) {
			  numMatchedChars = this->token_builders[i].checkMatch(text);
	        if (numMatchedChars > maxNumMatchedChars) {
   	         maxNumMatchedChars = numMatchedChars;
	        	   matchType = this->token_builders[i].terminal;
   	         if (!this->token_builders[i].checkError(numMatchedChars, lexeme))
   	         	this->token_builders[i].throwError();
   	     }
   	}
		    
		if (matchType != noMatch) {
		 	string buffer = string (text, maxNumMatchedChars);
		 	temp_token = new Token(string(buffer), matchType, tail_token); 
		 	back_token->next = temp_token;
		 	back_token = temp_token; 
		}
		// Consume the characters that were matched.
		text = text + maxNumMatchedChars;
    }

    return head_token->next;
}
