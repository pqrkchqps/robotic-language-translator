/*******************************************************************
Thuy Nguyen 

John Creeps
********************************************************************/


#include <cxxtest/TestSuite.h>
#include <stdarg.h>
#include "readInput.h"
#include "scanner.h"
#include <typeinfo>
#include <cstring>

using namespace std;

class ScannerTestSuite : public CxxTest::TestSuite 
{
public:
    /* A Scanner object is created in the test_setup_code method.
       This is a test, beginning with "test_", so that it is executed
       by the testing framework.  The scanner is used in some tests of
       the method "scan".
     */

	
    Scanner *s ;
    void test_setup_code ( ){
        s = new Scanner();
    }

	void terminal_tester(tokenType Kwd, const char * correct_str, const char * incorrect_str, const char * error_msg){
      bool exception_thrown = false;
      Token *head = s->scan(correct_str);
    	TS_ASSERT(head->terminal == Kwd);
	}


	void test_all_terminals() {
		terminal_tester(nameKwd, "name", "notname", "lexeme is not the nameKwd");
		terminal_tester(platformKwd, "platform", "notplatformKwd", "lexeme is not the platformKwd");
		terminal_tester(initialKwd, "initial", "notinitialKwd", "lexeme is not the initialKwd");
		terminal_tester(stateKwd, "state", "notstateKwd", "lexeme is not the stateKwd");
		terminal_tester(gotoKwd, "goto", "notgotoKwd", "lexeme is not the gotoKwd");
		terminal_tester(whenKwd, "when", "notwhenKwd",  "lexeme is not the whenKwd");
		terminal_tester(performingKwd, "performing", "notperformingKwd", "lexeme is not the performingKwd");  
		terminal_tester(exitKwd, "exit", "notexitKwd", "lexeme is not the exitKwd"); 
		terminal_tester(intKwd, "int", "notintKwd", "lexeme is not the intKwd");
		terminal_tester(floatKwd, "float", "notfloatKwd", "lexeme is not the floatKwd");
		terminal_tester(booleanKwd, "boolean", "notbooleanKwd", "lexeme is not the booleanKwd");
		terminal_tester(stringKwd, "string", "notstringKwd", "lexeme is not the stringKwd");
		terminal_tester(charKwd, "char", "notcharKwd", "lexeme is not the charKwd");
		terminal_tester(trueKwd, "true", "nottrueKwd", "lexeme is not the trueKwd");  
		terminal_tester(falseKwd, "false", "notfalseKwd", "lexeme is not the falseKwd");
		terminal_tester(intConst, "234", "notintConst", "lexeme is not the intConst");
		terminal_tester(floatConst, "199.99", "notfloatConst", "lexeme is not the floatConst");
		terminal_tester(stringConst, "\"string 1233232\"", "notstringConstant", "lexeme is not the stringConst");
		terminal_tester(charConst, "'c'", "notcharConst", "lexeme is not the charConst");
		terminal_tester(variableName, "var", "6notvar", "lexeme is not the variableName");
		terminal_tester(leftParen, "(", "notleftParen", "lexeme is not the leftParen");
		terminal_tester(rightParen, ")", "notrightParen", "lexeme is not the rightParen");
		terminal_tester(leftCurly, "{", "notleftCurly", "lexeme is not the leftCurly");
		terminal_tester(rightCurly, "}", "notrightCurly", "lexeme is not the rightCurly");
		terminal_tester(leftAngle, "<", "notleftAngle", "lexeme is not the leftAngle");
		terminal_tester(rightAngle, ">", "notrightAngle", "lexeme is not the rightAngle");
		terminal_tester(colon, ":", "notcolon", "lexeme is not the colon");
		terminal_tester(comma, ",", "notcomma", "lexeme is not the comma");
		terminal_tester(semiColon, ";", "notsemiColon", "lexeme is not the semiColon");
		terminal_tester(assign, ":=", "notassign", "lexeme is not the assign");
		terminal_tester(plusSign, "+", "notplusSign", "lexeme is not the plusSign");
		terminal_tester(star, "*", "notstar", "lexeme is not the star");
		terminal_tester(dash, "-", "notdash", "lexeme is not the dash");
		terminal_tester(forwardSlash, "/", "notforwardSlash", "lexeme is not the forwardSlash");
		terminal_tester(equalsEquals, "==", "notequalsEquals", "lexeme is not the equalsEquals");
		terminal_tester(lessThanEquals, "<=", "notlessThanEquals", "lexeme is not the lessThanEquals");
		terminal_tester(greaterThanEquals, ">=", "notgreaterThanEquals", "lexeme is not the greaterThanEquals");
		terminal_tester(notEquals, "!=", "notnotEquals", "lexeme is not the notEquals");
		terminal_tester(endOfFile, "", "notnot", "lexeme is not the endOfFile");
		terminal_tester(lexicalError, "&", "", "lexeme is not a lexicalError");
	}

    // Tests for components and functions used by "scan"
    // --------------------------------------------------

    /* You may need to write several tests to adequately test the
       functions that are called from "scan".  Once you are confident
       that the components used by "scan" work properly, then you can
       run tests on the "scan" method itself.
    */

    // Here you should place tests for these other functions.


    /* Below is one of the tests for these components in the project
       solution created by your instructor..  It uses a helper
       function function called "tokenMaker_tester", which you have
       not been given.  You are expected to design your own components
       for "scan" and your own mechanisms for easily testing them.*/

	/*
        Note that this test is here named "xtest_Token..." The leading
        "x" is so that cxxTest doesn't scan the line above and think
        it is an actual test that isn't commented out.  cxxTest is
        very simple and doesn't even process block comments.
    */


    /* You must have at least one separate test case for each terminal
       symbol.  Thus, you need a test that will pass or fail based
       solely on the regular expression (and its corresponding code)
       for each terminal symbol.

       This requires a test case for each element of the enumerated
       type tokenType.  This may look something like the sample test
       shown in the comment above.
    */


    // Tests for "scan"
    // --------------------------------------------------

    /* Below are some helper functions and sample tests for testing the 
       "scan" method on Scanner.
    */

    // Test that a list of tokens has no lexicalError tokens.
    bool noLexicalErrors (Token *tks) {
        Token *currentToken = tks ;
        while (currentToken != NULL) {
            if (currentToken->terminal == lexicalError) {
                return false;
            }
            else {
                currentToken = currentToken->next ;
            }
        }
        return true ;
    }

    /* A quick, but inaccurate, test for scanning files.  It only
       checks that no lexical errors occurred, not that the right
       tokens were returned. 
    */
    void scanFileNoLexicalErrors ( const char* filename ) {
        char *text =  readInputFromFile ( filename )  ;
        TS_ASSERT ( text ) ;
        Token *tks = s->scan ( text ) ;
        TS_ASSERT (tks != NULL) ;
        TS_ASSERT (noLexicalErrors(tks));
    }


    /* This function checks that the terminal fields in the list of
       tokens matches a list of terminals.
    */
    bool sameTerminals (Token *tks, int numTerms, tokenType *ts) {
        Token *currentToken = tks ;
        int termIndex = 0 ;
        while (currentToken != NULL && termIndex < numTerms ) {
            if (currentToken->terminal != ts[termIndex]) {
                return false;
            }
            else {
                ++ termIndex ;
                currentToken = currentToken->next;
            }
        }
        return true ;
    }

   
    /* Below are the provided test files that your code should also
       pass.

       You may initially want to rename these tests to "xtest_..." so
       that the CxxTest framework does not see it as a test and won't
       run it as one.  This way you can focus on the tests that you'll
       write above for the individual terminal types first. Then focus
       on these tests.

    */

    // The "endOfFile" token is always the last one in the list of tokens.
    void test_scan_empty ( ) {
        Token *tks = s->scan (" ");
        TS_ASSERT (tks != NULL);
        TS_ASSERT_EQUALS (tks->terminal, endOfFile);
        TS_ASSERT (tks->next == NULL);
    }

    void test_scan_empty_comment ( ) {
        Token *tks = s->scan (" /* a comment */ ") ;
        TS_ASSERT (tks != NULL) ;
        TS_ASSERT_EQUALS (tks->terminal, endOfFile) ;
        TS_ASSERT (tks->next == NULL) ;
    }

    // When a lexical error occurs, the scanner creates a token with a 
    // single-character lexeme and lexicalError as the terminal.
    void test_scan_lexicalErrors ( ) {
        Token *tks = s->scan ("$&1  ") ;
        TS_ASSERT (tks != NULL) ;
        TS_ASSERT_EQUALS (tks->terminal, lexicalError) ;
        TS_ASSERT_EQUALS (tks->lexeme, "$");
        tks = tks->next;
        TS_ASSERT (tks != NULL) ;
        TS_ASSERT_EQUALS (tks->terminal, lexicalError) ;
        TS_ASSERT_EQUALS (tks->lexeme, "&");
        tks = tks->next;
        TS_ASSERT (tks != NULL) ;
        TS_ASSERT_EQUALS (tks->terminal, intConst);
        TS_ASSERT_EQUALS (tks->lexeme, "1");
        tks = tks->next;
        TS_ASSERT (tks != NULL) ;
        TS_ASSERT_EQUALS (tks->terminal, endOfFile) ;
        TS_ASSERT (tks->next == NULL) ;
    }


    // A test for scanning numbers and a variable.
    void test_scan_nums_vars ( ) {
        Token *tks = s->scan (" 123 x 12.34 ") ;
        TS_ASSERT (tks != NULL) ;
        tokenType ts[] = { intConst, variableName, floatConst, endOfFile } ;
        TS_ASSERT ( sameTerminals ( tks, 4, ts ) ) ;
    }


    /* This test checks that the scanner returns a list of tokens with
       the correct terminal fields.  It doesn't check that the lexeme
       are correct.
     */
    void test_scan_bad_syntax_good_tokens ( ) {
        const char *filename = "../samples/bad_syntax_good_tokens.stm" ;
        char *text = readInputFromFile ( filename );
        TS_ASSERT (text);
        Token *tks = s->scan (text);
        TS_ASSERT (tks != NULL);
        tokenType ts[] = { 
            intConst, intConst, intConst, intConst,  
            stringConst, stringConst, stringConst,

            floatConst, floatConst, floatConst,
            charConst, charConst, charConst, charConst, 

            charConst, charConst, charConst, 
            trueKwd, falseKwd,

            colon, semiColon, comma, 
            leftCurly, leftParen, rightCurly, rightParen,

            plusSign, star, dash, forwardSlash, 

            rightAngle, leftAngle,
            equalsEquals, lessThanEquals, 

            greaterThanEquals, notEquals, 
            assign,

            variableName, variableName, variableName, variableName, 
            variableName, variableName, variableName,

            nameKwd, platformKwd, initialKwd, stateKwd, 
            gotoKwd, whenKwd, exitKwd, performingKwd,

            intKwd, floatKwd, booleanKwd, stringKwd, charKwd,

            endOfFile
        } ;
        int count = 58; 
        TS_ASSERT ( sameTerminals ( tks, count, ts ) ) ;
    }

    void test_scan_sample_abstar ( ) {
        scanFileNoLexicalErrors ("../samples/abstar.stm") ;
    }

} ;
