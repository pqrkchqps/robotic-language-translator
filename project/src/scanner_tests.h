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


//#include <tr1/tuple>

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

    bool exception_thrown;	
    //nameKwd
    void test_terminal_name ( ) {
     	Token *tk = new Token(nameKwd, "name");
    	TS_ASSERT(tk->terminal == nameKwd);  
    }


    void test_terminal_name_bad_lexeme ( ) {
	exception_thrown = false;
	try{
     		Token *tk = new Token(nameKwd, "notname");
	     	TS_ASSERT (tk != NULL) ;
     	}
   	catch (const InvalidToken& ex1){
	    	TS_ASSERT(!strcmp(ex1.what(),  ("lexeme is not the nameKwd")));  
		exception_thrown = true;
    	}
	TS_ASSERT(exception_thrown);
    }
      
    //platformKwd   
    void test_terminal_platform ( ) {
     	Token *tk = new Token(platformKwd, "platform");
    	TS_ASSERT (tk->terminal == platformKwd);  
    }
    void test_terminal_platform_bad_lexeme ( ) {
	exception_thrown = false;
	try{
     		Token *tk = new Token(platformKwd, "notplatformKwd");
	     	TS_ASSERT (tk != NULL) ;
     	}
   	catch (const InvalidToken& ex2){
    		TS_ASSERT(!strcmp(ex2.what(),  ("lexeme is not the platformKwd")));  
		exception_thrown = true;
    	}
	TS_ASSERT(exception_thrown);
    }
   
       
    //initialKwd   
    void test_terminal_initial ( ) {
     	Token *tk = new Token(initialKwd, "initial");
    	TS_ASSERT (tk->terminal == initialKwd);
    }
    void test_terminal_initial_bad_lexeme ( ) {
	exception_thrown = false;
	try{
	     	Token *tk = new Token(initialKwd, "notinitialKwd");
	     	TS_ASSERT (tk != NULL) ;
     	}
   	catch (const InvalidToken& ex3){
    		TS_ASSERT(!strcmp(ex3.what(),  ("lexeme is not the initialKwd")));  
		exception_thrown = true;
    	}
	TS_ASSERT(exception_thrown);
    }
    
    
    //stateKwd   
    void test_terminal_state ( ) {
     	Token *tk = new Token(stateKwd, "state");
    	TS_ASSERT (tk->terminal == stateKwd);  
    }
    void test_terminal_state_bad_lexeme ( ) {
	exception_thrown = false;
        try{
 	    	Token *tk = new Token(stateKwd, "notstateKwd");
     		TS_ASSERT (tk != NULL) ;
     	}
   	catch (const InvalidToken& ex4){
    		TS_ASSERT (!strcmp(ex4.what(),  ("lexeme is not the stateKwd")));  
		exception_thrown = true;
    	}
	TS_ASSERT(exception_thrown);
    }
    
    
    //gotoKwd   
    void test_terminal_goto ( ) {
     	Token *tk = new Token(gotoKwd, "goto");
    	TS_ASSERT (tk->terminal == gotoKwd);  
    }
    void test_terminal_goto_bad_lexeme ( ) {
	exception_thrown = false;
	try{
	     	Token *tk = new Token(gotoKwd, "notgotoKwd");
     		TS_ASSERT (tk != NULL) ;
     	}
   	catch (const InvalidToken& ex){
    		TS_ASSERT (!strcmp(ex.what(),  ("lexeme is not the gotoKwd")));  
		exception_thrown = true;
    	}
	TS_ASSERT(exception_thrown);
    }
 
    
    //whenKwd   
    void test_terminal_when ( ) {
     	Token *tk = new Token(whenKwd, "when");
    	TS_ASSERT (tk->terminal == whenKwd);  
    }
    void test_terminal_when_bad_lexeme ( ) {
	exception_thrown = false;
	try{
	     	Token *tk = new Token(whenKwd, "notwhenKwd");
     		TS_ASSERT (tk != NULL) ;
     	}
   	catch (const InvalidToken& ex){
	    	TS_ASSERT (!strcmp(ex.what(),  ("lexeme is not the whenKwd")));  
		exception_thrown = true;
    	}
	TS_ASSERT(exception_thrown);
    }
    
    
    //performingKwd   
    void test_terminal_performing ( ) {
     	Token *tk = new Token(performingKwd, "performing");
    	TS_ASSERT (tk->terminal == performingKwd);  
    }
    void test_terminal_performing_bad_lexeme ( ) {
	exception_thrown = false;
	try{
     		Token *tk = new Token(performingKwd, "notperformingKwd");
	     	TS_ASSERT (tk != NULL) ;
     	}
   	catch (const InvalidToken& ex){
    		TS_ASSERT (!strcmp(ex.what(),  ("lexeme is not the performingKwd")));  
		exception_thrown = true;
    	}
	TS_ASSERT(exception_thrown);
    }
    
    //exitKwd   
    void test_terminal_exit ( ) {
     	Token *tk = new Token(exitKwd, "exit");
    	TS_ASSERT (tk->terminal == exitKwd);  
    }
    void test_terminal_exit_bad_lexeme ( ) {
	exception_thrown = false;
	try{
     		Token *tk = new Token(exitKwd, "notexitKwd");
	     	TS_ASSERT (tk != NULL) ;
     	}
   	catch (const InvalidToken& ex){
    		TS_ASSERT (!strcmp(ex.what(),  ("lexeme is not the exitKwd")));  
		exception_thrown = true;
    	}
	TS_ASSERT(exception_thrown);
    }
    
    //intKwd   
    void test_terminal_int ( ) {
     	Token *tk = new Token(intKwd, "int");
    	TS_ASSERT (tk->terminal == intKwd);  
    }
    void xtest_terminal_int_bad_lexeme ( ) {
	exception_thrown = false;
	try{
	     	Token *tk = new Token(intKwd, "notintKwd");
	     	TS_ASSERT (tk != NULL) ;
     	}
   	catch (const InvalidToken& ex){
	    	TS_ASSERT (!strcmp(ex.what(),  ("lexeme is not the intKwd")));  
		exception_thrown = true;
    	}
	TS_ASSERT(exception_thrown);
    }
    
    
    //floatKwd   
    void xtest_terminal_float ( ) {
     	Token *tk = new Token(floatKwd, "float");
    	TS_ASSERT (tk->terminal == floatKwd);  
    }
    void xtest_terminal_float_bad_lexeme ( ) {
	exception_thrown = false;
	try{
	     	Token *tk = new Token(floatKwd, "notfloatKwd");
     		TS_ASSERT (tk != NULL) ;
     	}
   	catch (const InvalidToken& ex){
	    	TS_ASSERT (!strcmp(ex.what(),  ("lexeme is not the floatKwd")));  
		exception_thrown = true;
    	}
	TS_ASSERT(exception_thrown);
    }
    
    
    //booleanKwd   
    void test_terminal_boolean( ) {
     	Token *tk = new Token(booleanKwd, "boolean");
    	TS_ASSERT (tk->terminal == booleanKwd);  
    }
    void test_terminal_boolean_bad_lexeme ( ) {
	exception_thrown = false;
	try{
	     	Token *tk = new Token(booleanKwd, "notbooleanKwd");
	     	TS_ASSERT (tk != NULL) ;
     	}
   	catch (const InvalidToken& ex){
    		TS_ASSERT (!strcmp(ex.what(),  ("lexeme is not the booleanKwd")));  
		exception_thrown = true;
    	}
	TS_ASSERT(exception_thrown);
    }
    
    
    //stringKwd   
    void test_terminal_string ( ) {
     	Token *tk = new Token(stringKwd, "string");
    	TS_ASSERT (tk->terminal == stringKwd);  
    }
    void test_terminal_string_bad_lexeme ( ) {
	exception_thrown = false;
	try{
	     	Token *tk = new Token(stringKwd, "notstringKwd");
	     	TS_ASSERT (tk != NULL) ;
     	}
   	catch (const InvalidToken& ex){
	    	TS_ASSERT (!strcmp(ex.what(),  ("lexeme is not the stringKwd")));  
		exception_thrown = true;
    	}
	TS_ASSERT(exception_thrown);
    }
    
    
    //charKwd   
    void test_terminal_char ( ) {
     	Token *tk = new Token(charKwd, "char");
    	TS_ASSERT (tk->terminal == charKwd);  
    }
    void test_terminal_char_bad_lexeme ( ) {
	exception_thrown = false;
	try{
	     	Token *tk = new Token(charKwd, "notcharKwd");
	     	TS_ASSERT (tk != NULL) ;
     	}
   	catch (const InvalidToken& ex){
	    	TS_ASSERT (!strcmp(ex.what(),  ("lexeme is not the charKwd")));  
		exception_thrown = true;
    	}
	TS_ASSERT(exception_thrown);
    }
    
    
    //trueKwd   
    void test_terminal_true ( ) {
     	Token *tk = new Token(trueKwd, "true");
    	TS_ASSERT (tk->terminal == trueKwd);  
    }
    void test_terminal_true_bad_lexeme ( ) {
	exception_thrown = false;
	try{
	     	Token *tk = new Token(trueKwd, "nottrueKwd");
	     	TS_ASSERT (tk != NULL) ;
     	}
   	catch (const InvalidToken& ex){
	    	TS_ASSERT (!strcmp(ex.what(),  ("lexeme is not the trueKwd")));  
		exception_thrown = true;
    	}
	TS_ASSERT(exception_thrown);
    }
    
    
    //falseKwd   
    void test_terminal_false ( ) {
     	Token *tk = new Token(falseKwd, "false");
    	TS_ASSERT (tk->terminal == falseKwd);  
    }
    void test_terminal_false_bad_lexeme ( ) {
	exception_thrown = false;
	try{
     		Token *tk = new Token(falseKwd, "notfalseKwd");
	     	TS_ASSERT (tk != NULL) ;
     	}
   	catch (const InvalidToken& ex){
    		TS_ASSERT (!strcmp(ex.what(),  ("lexeme is not the falseKwd")));  
		exception_thrown = true;
    	}
	TS_ASSERT(exception_thrown);
    }
    
    
    //intConst   
    void test_terminal_intConst ( ) {
     	Token *tk = new Token(intConst, "234");
    	TS_ASSERT (tk->terminal ==intConst);  
    }
    void test_terminal_intConst_bad_lexeme ( ) {
	exception_thrown = false;
	try{
	     	Token *tk = new Token(intConst, "notintConst");
	     	TS_ASSERT (tk != NULL) ;
     	}
   	catch (const InvalidToken& ex){
    		TS_ASSERT (!strcmp(ex.what(),  ("lexeme is not the intConst")));  
		exception_thrown = true;
    	}
	TS_ASSERT(exception_thrown);
    }
    
    
    //floatConst   
    void test_terminal_floatConst ( ) {
     	Token *tk = new Token(floatConst, "199.99");
    	TS_ASSERT (tk->terminal == floatConst);  
    }
    void test_terminal_floatConst_bad_lexeme ( ) {
	exception_thrown = false;
	try{
	     	Token *tk = new Token(floatConst, "notfloatConst");
	     	TS_ASSERT (tk != NULL) ;
     	}
   	catch (const InvalidToken& ex){
	    	TS_ASSERT (!strcmp(ex.what(),  ("lexeme is not the floatConst")));  
		exception_thrown = true;
    	}
	TS_ASSERT(exception_thrown);
    }
    
    //stringConst   
    void test_terminal_stringConst ( ) {
     	Token *tk = new Token(stringConst, "\"string 1233232\"");
    	TS_ASSERT (tk->terminal == stringConst);  
    }
    void test_terminal_stringConst_bad_lexeme ( ) {
	exception_thrown = false;
	try{
	     	Token *tk = new Token(stringConst, "notstringConstant");
	     	TS_ASSERT (tk != NULL) ;
     	}
   	catch (const InvalidToken& ex){
	    	TS_ASSERT (!strcmp(ex.what(),  ("lexeme is not the stringConst")));  
		exception_thrown = true;
    	}
	TS_ASSERT(exception_thrown);
    }
      
    //charConst   
    void test_terminal_charConst ( ) {
     	Token *tk = new Token(charConst, "'c'");
    	TS_ASSERT (tk->terminal == charConst);  
    }
    void test_terminal_charConst_bad_lexeme ( ) {
	exception_thrown = false;
	try{
	     	Token *tk = new Token(charConst, "notcharConst");
	     	TS_ASSERT (tk != NULL) ;
     	}
   	catch (const InvalidToken& ex){
    		TS_ASSERT (!strcmp(ex.what(),  ("lexeme is not the charConst")));  
		exception_thrown = true;
    	}
	TS_ASSERT(exception_thrown);
    }
     
    //variableName   
    void test_terminal_variableName ( ) {
     	Token *tk = new Token(variableName, "var");
    	TS_ASSERT (tk->terminal == variableName);  
    }
    void test_terminal_variableName_bad_lexeme ( ) {
	exception_thrown = false;
	try{
	     	Token *tk = new Token(variableName, "6notvar");
     		TS_ASSERT (tk != NULL) ;
     	}
   	catch (const InvalidToken& ex){
    		TS_ASSERT (!strcmp(ex.what(),  ("lexeme is not the variableName")));  
		exception_thrown = true;
    	}
	TS_ASSERT(exception_thrown);
    }
    
    //leftParen   
    void test_terminal_leftParen ( ) {
     	Token *tk = new Token(leftParen, "(");
    	TS_ASSERT (tk->terminal == leftParen);  
    }
    void test_terminal_leftParen_bad_lexeme ( ) {
	exception_thrown = false;
	try{
	     	Token *tk = new Token(leftParen, "notleftParen");
     		TS_ASSERT (tk != NULL) ;
     	}
   	catch (const InvalidToken& ex){
	    	TS_ASSERT (!strcmp(ex.what(),  ("lexeme is not the leftParen")));  
		exception_thrown = true;
    	}
	TS_ASSERT(exception_thrown);
    }
    
    //rightParen   
    void test_terminal_rightParen ( ) {
     	Token *tk = new Token(rightParen, ")");
    	TS_ASSERT (tk->terminal == rightParen);  
    }
    void test_terminal_rightParen_bad_lexeme ( ) {
	exception_thrown = false;
	try{
	     	Token *tk = new Token(rightParen, "notrightParen");
	     	TS_ASSERT (tk != NULL) ;
     	}
   	catch (const InvalidToken& ex){
	    	TS_ASSERT (!strcmp(ex.what(),  ("lexeme is not the rightParen")));  
		exception_thrown = true;
    	}
	TS_ASSERT(exception_thrown);
    }
    
    
    //leftCurly   
    void test_terminal_leftCurly ( ) {
     	Token *tk = new Token(leftCurly, "{");
    	TS_ASSERT (tk->terminal == leftCurly);  
    }
    void test_terminal_leftCurly_bad_lexeme ( ) {
	exception_thrown = false;
	try{
	     	Token *tk = new Token(leftCurly, "notleftCurly");
	     	TS_ASSERT (tk != NULL) ;
     	}
   	catch (const InvalidToken& ex){
	    	TS_ASSERT (!strcmp(ex.what(),  ("lexeme is not the leftCurly")));  
		exception_thrown = true;
    	}
	TS_ASSERT(exception_thrown);
    }
    
    //rightCurly   
    void test_terminal_rightCurly ( ) {
     	Token *tk = new Token(rightCurly, "}");
    	TS_ASSERT (tk->terminal == rightCurly);  
    }
    void test_terminal_rightCurly_bad_lexeme ( ) {
	exception_thrown = false;
	try{
	     	Token *tk = new Token(rightCurly, "notrightCurly");
	     	TS_ASSERT (tk != NULL) ;
     	}
   	catch (const InvalidToken& ex){
	    	TS_ASSERT (!strcmp(ex.what(),  ("lexeme is not the rightCurly")));  
		exception_thrown = true;
    	}
	TS_ASSERT(exception_thrown);
    }
    
   
    //leftAngle
    void test_terminal_leftAngle ( ) {
	Token *tk = new Token(leftAngle, "<");
	TS_ASSERT(tk->terminal == leftAngle);
    }
    void test_terminal_leftAngle_bad_lexeme ( ) {
	exception_thrown = false;
	try{
	  	Token *tk = new Token(leftAngle, "notleftAngle");
     		TS_ASSERT (tk != NULL) ;
     	}
   	catch (const InvalidToken& ex){
	    	TS_ASSERT (!strcmp(ex.what(),  ("lexeme is not the leftAngle")));  
		exception_thrown = true;
    	}
	TS_ASSERT(exception_thrown);
    }

    //rightAngle
    void test_terminal_rightAngle ( ) {
	Token *tk = new Token(rightAngle, ">");
	TS_ASSERT(tk->terminal == rightAngle);
    }
    void test_terminal_rightAngle_bad_lexeme ( ) {
	exception_thrown = false;
	try{
	     	Token *tk = new Token(rightAngle, "notrightAngle");
     		TS_ASSERT (tk != NULL) ;
     	}
   	catch (const InvalidToken& ex){
	    	TS_ASSERT (!strcmp(ex.what(),  ("lexeme is not the rightAngle")));  
		exception_thrown = true;
    	}
	TS_ASSERT(exception_thrown);
    }


    //colon
    void test_terminal_colon ( ) {
	Token *tk = new Token(colon, ":");
	TS_ASSERT(tk->terminal == colon);
    }
    void test_terminal_colon_bad_lexeme ( ) {
	exception_thrown = false;
    	try{
	     	Token *tk = new Token(colon, "notcolon");
	     	TS_ASSERT (tk != NULL) ;
     	}
   	catch (const InvalidToken& ex){
	    	TS_ASSERT (!strcmp(ex.what(),  ("lexeme is not the colon")));  
		exception_thrown = true;
    	}
	TS_ASSERT(exception_thrown);
    }


    //comma
    void test_terminal_comma ( ) {
	Token *tk = new Token(comma, ",");
	TS_ASSERT(tk->terminal == comma);
    }
    void test_terminal_comma_bad_lexeme ( ) {
	exception_thrown = false;
    	try{
	     	Token *tk = new Token(comma, "notcomma");
	     	TS_ASSERT (tk != NULL) ;
     	}
   	catch (const InvalidToken& ex){
	    	TS_ASSERT (!strcmp(ex.what(),  ("lexeme is not the comma")));  
		exception_thrown = true;
    	}
	TS_ASSERT(exception_thrown);
    }


    //semiColon
    void test_terminal_semiColon ( ) {
	Token *tk = new Token(semiColon, ";");
	TS_ASSERT(tk->terminal == semiColon);
    }

    void test_terminal_semiColon_bad_lexeme ( ) {
	exception_thrown = false;
    	try{
     		Token *tk = new Token(semiColon, "notsemiColon");
	     	TS_ASSERT (tk != NULL) ;
     	}
   	catch (const InvalidToken& ex){
    		TS_ASSERT (!strcmp(ex.what(),  ("lexeme is not the semiColon")));  
		exception_thrown = true;
    	}
	TS_ASSERT(exception_thrown);
    }


    //assign
    void test_terminal_assign ( ) {
	Token *tk = new Token(assign, ":=");
	TS_ASSERT(tk->terminal == assign);
    }
    void test_terminal_assign_bad_lexeme ( ) {
	exception_thrown = false;
    	try{
	     	Token *tk = new Token(assign, "notassign");
	     	TS_ASSERT (tk != NULL) ;
     	}
   	catch (const InvalidToken& ex){
    		TS_ASSERT (!strcmp(ex.what(),  ("lexeme is not the assign")));  
		exception_thrown = true;
    	}
	TS_ASSERT(exception_thrown);
    }

    //plusSign
    void test_terminal_plusSign ( ) {
	Token *tk = new Token(plusSign, "+");
	TS_ASSERT(tk->terminal == plusSign);
    }
    void test_terminal_plusSign_bad_lexeme ( ) {
	exception_thrown = false;
    	try{
		Token *tk = new Token(plusSign, "notplusSign");
	     	TS_ASSERT (tk != NULL) ;
     	}
   	catch (const InvalidToken& ex){
	    	TS_ASSERT (!strcmp(ex.what(),  ("lexeme is not the plusSign")));  
		exception_thrown = true;
    	}
	TS_ASSERT(exception_thrown);
    }


    //star
    void test_terminal_star ( ) {
	Token *tk = new Token(star, "*");
	TS_ASSERT(tk->terminal == star);
    }
    void test_terminal_star_bad_lexeme ( ) {
	exception_thrown = false;
	try{
		Token *tk = new Token(star, "notstar");
	     	TS_ASSERT (tk != NULL) ;
     	}
   	catch (const InvalidToken& ex){
    		TS_ASSERT (!strcmp(ex.what(),  ("lexeme is not the star")));  
		exception_thrown = true;
    	}
	TS_ASSERT(exception_thrown);
    }


    // dash
    void test_terminal_dash ( ) {
	Token *tk = new Token(dash, "-");
	TS_ASSERT(tk->terminal == dash);
    }
    void test_terminal_dash_bad_lexeme ( ) {
	exception_thrown = false;
	try{
    	 	Token *tk = new Token(dash, "notdash");
	     	TS_ASSERT (tk != NULL) ;
     	}
   	catch (const InvalidToken& ex){
    		TS_ASSERT (!strcmp(ex.what(),  ("lexeme is not the dash")));  
		exception_thrown = true;
    	}
	TS_ASSERT(exception_thrown);
    }


    // forwardSlash
    void test_terminal_forwardSlash ( ) {
	Token *tk = new Token(forwardSlash, "/");
	TS_ASSERT(tk->terminal == forwardSlash);
    }
    void test_terminal_forwardSlash_bad_lexeme ( ) {
	exception_thrown = false;
	try{
	     	Token *tk = new Token(forwardSlash, "notforwardSlash");
	     	TS_ASSERT (tk != NULL) ;
     	}
   	catch (const InvalidToken& ex){
	    	TS_ASSERT (!strcmp(ex.what(),  ("lexeme is not the forwardSlash")));  
		exception_thrown = true;
    	}
	TS_ASSERT(exception_thrown);
    }


    // equalsEquals
    void test_terminal_equalsEquals ( ) {
		Token *tk = new Token(equalsEquals, "==");
		TS_ASSERT(tk->terminal == equalsEquals);
    }
    void test_terminal_equalsEquals_bad_lexeme ( ) {
	exception_thrown = false;
	try{
	     	Token *tk = new Token(equalsEquals, "notequalsEquals");
	     	TS_ASSERT (tk != NULL) ;
     	}
   	catch (const InvalidToken& ex){
    		TS_ASSERT (!strcmp(ex.what(),  ("lexeme is not the equalsEquals")));  
		exception_thrown = true;
    	}
	TS_ASSERT(exception_thrown);
    }


    // lessThanEquals
    void test_terminal_lessThanEquals ( ) {
	Token *tk = new Token(lessThanEquals, "<=");
	TS_ASSERT(tk->terminal == lessThanEquals);
    }

    void test_terminal_lessThanEquals_bad_lexeme ( ) {
	exception_thrown = false;
    	try{
     		Token *tk = new Token(lessThanEquals, "notlessThanEquals");
     		TS_ASSERT (tk != NULL) ;
	}
    	catch (const InvalidToken& ex){
    		TS_ASSERT (!strcmp(ex.what(),  ("lexeme is not the lessThanEquals")));  
		exception_thrown = true;
    	}
	TS_ASSERT(exception_thrown);
    }

    // greaterThanEquals
    void test_terminal_greaterThanEquals ( ) {
	Token *tk = new Token(greaterThanEquals, ">=");
	TS_ASSERT(tk->terminal == greaterThanEquals);
    }

    void test_terminal_greaterThanEquals_bad_lexeme ( ) {
	exception_thrown = false;
	try{
     		Token *tk = new Token(greaterThanEquals, "notgreaterThanEquals");
       		TS_ASSERT (tk != NULL) ;
     	}
	catch (const InvalidToken& ex){
    		TS_ASSERT (!strcmp(ex.what(),  ("lexeme is not the greaterThanEquals")));  
		exception_thrown = true;
    	}
	TS_ASSERT(exception_thrown);
    }


    // notEquals
    void test_terminal_notEquals ( ) {
	Token *tk = new Token(notEquals, "!=");
	TS_ASSERT(tk->terminal == notEquals);
    }
	
    void test_terminal_notEquals_bad_lexeme ( ) {
	exception_thrown = false;
	try{
     		Token *tk = new Token(notEquals, "notnotEquals");
	     	 TS_ASSERT (tk != NULL) ;
     	}
   	catch (const InvalidToken& ex){
	    	TS_ASSERT (!strcmp(ex.what(),  ("lexeme is not the notEquals")));  
		exception_thrown = true;
    	}
	TS_ASSERT(exception_thrown);
    }

    // endOfFile
    void test_terminal_endOfFile ( ) {
	Token *tk = new Token(endOfFile, "");
	TS_ASSERT(tk->terminal == endOfFile);
    }

    void test_terminal_endOfFile_bad_lexeme ( ) {
	exception_thrown = false;
	try{
	    Token *tk = new Token(endOfFile, "notnot");
     	}
   	catch (const InvalidToken& ex){
    	    TS_ASSERT (!strcmp(ex.what(),  ("lexeme is not the endOfFile")));
	    exception_thrown = true;
    	}
	TS_ASSERT(exception_thrown);
    }

    //lexical error
    void test_terminal_lexicalError ( ) {
	Token *tk = new Token(lexicalError, "&");
	TS_ASSERT(tk->terminal == lexicalError);
    }

    void test_terminal_lexicalError_bad_lexeme ( ) {
	exception_thrown = false;
	try {
	    Token *tk = new Token(lexicalError, "");
	}
	catch (const InvalidToken& ex){
		TS_ASSERT (!strcmp(ex.what(), ("lexeme is not a lexicalError")));
		exception_thrown = true;
       }
	TS_ASSERT(exception_thrown);
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
                return false ;
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
                return false ;
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
        char *text =  readInputFromFile ( filename )  ;
        TS_ASSERT (text) ;
        Token *tks = s->scan ( text ) ;
        TS_ASSERT (tks != NULL) ;
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
