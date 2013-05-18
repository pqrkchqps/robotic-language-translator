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

	

    /*
	We added the code to test the default cases for all the terminals
	These test cases were placed with the scanner tests because
	we use the scanner to test the creation of tokens. 
    */
    Scanner *s ;
    void test_setup_code ( ){
        s = new Scanner();
    }

    void terminal_tester(tokenType Kwd, const char* str){
    	Token *head = s->scan(str);
    	TS_ASSERT(head->get_terminal() == Kwd);
    }
    void test_nameKwd(){
	terminal_tester(nameKwd, "name");
    }
    void test_platformKwd(){
	terminal_tester(platformKwd, "platform");
    }
    void test_initialKwd(){
	terminal_tester(initialKwd, "initial");
    }
    void test_stateKwd(){
	terminal_tester(stateKwd, "state");
    }
    void test_gotoKwd(){
	terminal_tester(gotoKwd, "goto");
    }
    void test_whenKwd(){
	terminal_tester(whenKwd, "when");
    }
    void test_performingKwd(){
	terminal_tester(performingKwd, "performing");
    }
    void test_exitKwd(){
	terminal_tester(exitKwd, "exit");
    }
    void test_intKwd(){
	terminal_tester(intKwd, "int");
    }
    void test_floatKwd(){
	terminal_tester(floatKwd, "float");
    }
    void test_booleanKwd(){
	terminal_tester(booleanKwd, "boolean");
    }
    void test_stringKwd(){
	terminal_tester(stringKwd, "string");
    }
    void test_charKwd(){
	terminal_tester(charKwd, "char");
    }
    void test_trueKwd(){
	terminal_tester(trueKwd, "true");
    }
    void test_falseKwd(){
	terminal_tester(falseKwd, "false");
    }
    void test_intConst(){
	terminal_tester(intConst, "234");
    }
    void test_floatConst(){
	terminal_tester(floatConst, "199.99");
    }
    void test_stringConst(){
	terminal_tester(stringConst, "\"string 1233232\"");
    }
    void test_charConst(){
	terminal_tester(charConst, "'c'");
    }
    void test_variableName(){
	terminal_tester(variableName, "var");
    }
    void test_leftParen(){
	terminal_tester(leftParen, "(");
    }
    void test_rightParen(){
	terminal_tester(rightParen, ")");
    }
    void test_leftCurly(){
	terminal_tester(leftCurly, "{");
    }
    void test_rightCurly(){
	terminal_tester(rightCurly, "}");
    }
    void test_leftAngle(){
	terminal_tester(leftAngle, "<");
    }
    void test_rightAngle(){
	terminal_tester(rightAngle, ">");
    }
    void test_colon(){
	terminal_tester(colon, ":");
    }
    void test_comma(){
	terminal_tester(comma, ",");
    }
    void test_semiColon(){
	terminal_tester(semiColon, ";");
    }
    void test_assign(){
	terminal_tester(assign, ":=");
    }
    void test_plusSign(){
	terminal_tester(plusSign, "+");
    }
    void test_star(){
	terminal_tester(star, "*");
    }
    void test_dash(){
	terminal_tester(dash, "-");
    }
    void test_forwardSlash(){
	terminal_tester(forwardSlash, "/");
    }
    void test_equalsEquals(){
	terminal_tester(equalsEquals, "==");
    }
    void test_lessThanEquals(){
	terminal_tester(lessThanEquals, "<=");
    }
    void test_greaterThanEquals(){
	terminal_tester(greaterThanEquals, ">=");
    }
    void test_notEquals(){
	terminal_tester(notEquals, "!=");
    }
    void test_endOfFile(){
	terminal_tester(endOfFile, "");
    }
    void test_lexicalError(){
	terminal_tester(lexicalError, "&");
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
            if (currentToken->get_terminal() == lexicalError) {
                return false;
            }
            else {
                currentToken = currentToken->get_next() ;
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
            if (currentToken->get_terminal() != ts[termIndex]) {
                return false;
            }
            else {
                ++ termIndex ;
                currentToken = currentToken->get_next();
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
        TS_ASSERT_EQUALS (tks->get_terminal(), endOfFile);
        TS_ASSERT (tks->get_next() == NULL);
    }

    void test_scan_empty_comment ( ) {
        Token *tks = s->scan (" /* a comment */ ") ;
        TS_ASSERT (tks != NULL) ;
        TS_ASSERT_EQUALS (tks->get_terminal(), endOfFile) ;
        TS_ASSERT (tks->get_next() == NULL) ;
    }

    // When a lexical error occurs, the scanner creates a token with a 
    // single-character lexeme and lexicalError as the terminal.
    void test_scan_lexicalErrors ( ) {
        Token *tks = s->scan ("$&1  ") ;
        TS_ASSERT (tks != NULL) ;
        TS_ASSERT_EQUALS (tks->get_terminal(), lexicalError) ;
        TS_ASSERT_EQUALS (tks->get_lexeme(), "$");
        tks = tks->get_next();
        TS_ASSERT (tks != NULL) ;
        TS_ASSERT_EQUALS (tks->get_terminal(), lexicalError) ;
        TS_ASSERT_EQUALS (tks->get_lexeme(), "&");
        tks = tks->get_next();
        TS_ASSERT (tks != NULL) ;
        TS_ASSERT_EQUALS (tks->get_terminal(), intConst);
        TS_ASSERT_EQUALS (tks->get_lexeme(), "1");
        tks = tks->get_next();
        TS_ASSERT (tks != NULL) ;
        TS_ASSERT_EQUALS (tks->get_terminal(), endOfFile) ;
        TS_ASSERT (tks->get_next() == NULL) ;
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
        const char *filename = "../samples/bad_syntax_good_tokens.cff" ;
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
        scanFileNoLexicalErrors ("../samples/abstar.cff") ;
    }

} ;
