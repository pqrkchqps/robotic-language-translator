#include <cxxtest/TestSuite.h>
#include "regex.h"

using namespace std ;

class RegexTestSuite : public CxxTest::TestSuite 
{
public:

    // Tests for makeRegex and matchRegex
    // --------------------------------------------------
    /* These tests ensure that the makeRegex and matchRegex work as
       expected.  These tests are independent from the scanner or
       WordCount application.
     */

    void test_make_matchRegex_match ( void ) {
        regex_t *re = makeRegex ("^[0-9]+") ;
        TS_ASSERT (re) ;
        int numMatchedChars = matchRegex (re, "123 ") ;
        TS_ASSERT (numMatchedChars == 3) ;
    }

    void test_make_matchRegex_no_match ( void ) {
        regex_t *re = makeRegex ("^[0-9]+") ;
        TS_ASSERT (re) ;
        int numMatchedChars = matchRegex (re, " 123 ") ;
        TS_ASSERT (numMatchedChars == 0) ;
    }

    void test_make_matchRegex_match_string_copy ( void ) {
        regex_t *re = makeRegex ("^[0-9]+") ;
        TS_ASSERT (re) ;
        const char *text = "123 ";
        int numMatchedChars = matchRegex (re, text) ;
        TS_ASSERT (numMatchedChars == 3) ;
        std::string lex(text, numMatchedChars) ;
        TS_ASSERT_EQUALS (lex, "123");
    }

//We removed the Code for testing if the lexeme is throwning an unusual error 
	//caused by the regular expression mapping the wrong number of chars
	//Consider adding these test cases back in as regex_tests
/*
    void terminal_tester(tokenType Kwd, const char * correct_str, const char * incorrect_str, const char * error_msg){
      //bool exception_thrown = false;
      Token *head = s->scan(correct_str);
    	TS_ASSERT(head->terminal == Kwd);
	}

	void ttest_all_terminals() {
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
*/
} ;
