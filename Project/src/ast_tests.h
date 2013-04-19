#include <cxxtest/TestSuite.h>

#include "readInput.h"
#include "scanner.h"
#include "extToken.h"
#include "parser.h"
#include "parseResult.h"
// One of the above has likely included the .h file with your
// definition of the Node and Program class.  It is not named 
// here so that you can name your files as you see fit.

using namespace std ;

class AstTestSuite : public CxxTest::TestSuite 
{
public:
    int DEBUG ;

    Scanner *s ;
    Parser *p ;
    void test_setup_code ( ) {
        s = new Scanner() ;
        p = new Parser() ;
        DEBUG = 0 ;
    }
     
    /*******************************************************************************************
    
		 We created a new token type parseExprToken and parseExtendedExprToken because 
		 we want to test functionality of parseResult, led and nud. We want to implement
		 them in 2 ways. One way we translate token into parseResult and another way we 
		 store property of parseResult. 
		 
		 The first method we used was to transform token and store the token as a parseResult.
		 This means each token is stored as a seperate parse result. We will be using 
		 polymorphic behavor, so we will need a general abstract interface to represent 
		 the common parts of the parse result's functionality.
		 
		 These test cases should be in order of top down design. 
		 
		 Question: Is there a way to implement Iteration 3 so that you do not need to implement 
		 all of the AST classes before you can write and your code can pass a test case?
		 That is, how can we develop this so that we do not need to implement the AST classes 
		 all at once? How can we start small, perhaps implementing just one class or related 
		 set of classes and then proceed from there?
		 
		 There is a way we can implement the AST classes without writting the entire parser. 
		 By following the recommendation given in the instruction, we can start with one 
		 none terminal such as expression and incrementaly test and write the code. We orgininally 
		 try to add small helper Tokens and helper functions to test the functionality of 
		 expression without writting all the expression. This proved that it was unhelpful, 
		 and testing the functionality of a single compound expression, addition, was far more 
		 effective and producing and testing good code. 
		 
		 To implement expression we experiment with the number of design, the most useful one 
		 all involved a list of parseResult. The first method for implementing polymorphic behavior 
		 used parseResult as a base class for newly implemented custom ParseResult types. 
		 This code did not work with the existing style presented in the code base. 
		 The implementation we finally used closely mimic the style of the sample code 
		 found online. Custom ASTNode(s) was stored on Parseresult in polymophic behavoir 
		 which used for type checking the ASTNode. 
		 
		 To test this functionality will be start with the addition testcase and precided to 
		 copy this style for all the subsequence expressions.   

		 To test the functionality of constant expressions we opted to just check the case
		 where one constant expression was handed to the parseExpr method.
		 The reason we did this is because the parser should fail if the sequence of
		 expressions are not valid.  The case where there are more than one expression was
		 commented out because it is not usefull for testing that constant expressions
		 evaluate correctly. The functionality that checks for bad expressions will likely
		 be tested in a one of the nonterminals higher in the AST.

		 Testing for trueKwd, falseKwd and variableName followed the same pattern as the 
		 other constant expressions. These terminals experienced no problems.
    
    
    *************************************************************************************/
    
    
    //test for Addition 
    void testAddition() {
            ParseResult pr ;
	    const char *text = "3+2";
	    p->tokens = extendTokenList ( p, s->scan (text) ) ;
	    TS_ASSERT(p->tokens != NULL) ;
	    p->currToken = p->tokens ;
	    pr = p->parseExpr(0);

  	    TS_ASSERT(pr.getNext() != NULL);
  	    TS_ASSERT(pr.getNext()->getNext() != NULL);
	    TS_ASSERT(pr.ast->getLexeme() == "3");
  	    TS_ASSERT(pr.getNext()->ast->getLexeme() == "+");
  	    TS_ASSERT(pr.getNext()->getNext()->ast->getLexeme() == "2");
  	    TS_ASSERT(pr.ast->getTerminal() == intConst);
  	    TS_ASSERT(pr.getNext()->ast->getTerminal() == plusSign);
  	    TS_ASSERT(pr.getNext()->getNext()->ast->getTerminal() == intConst);
    }

    //test for Subtraction
    void testSubtraction() {
            ParseResult pr ;
	    const char *text = "3-2";
	    p->tokens = extendTokenList ( p, s->scan (text) ) ;
	    TS_ASSERT(p->tokens != NULL) ;
	    p->currToken = p->tokens ;
	    pr = p->parseExpr(0);

  	    TS_ASSERT(pr.getNext() != NULL);
  	    TS_ASSERT(pr.getNext()->getNext() != NULL);
	    TS_ASSERT(pr.ast->getLexeme() == "3");
  	    TS_ASSERT(pr.getNext()->ast->getLexeme() == "-");
  	    TS_ASSERT(pr.getNext()->getNext()->ast->getLexeme() == "2");
  	    TS_ASSERT(pr.ast->getTerminal() == intConst);
  	    TS_ASSERT(pr.getNext()->ast->getTerminal() == dash);
  	    TS_ASSERT(pr.getNext()->getNext()->ast->getTerminal() == intConst);
    }

    //test for Division 
    void testDivision() {
            ParseResult pr ;
	    const char *text = "3/2";
	    p->tokens = extendTokenList ( p, s->scan (text) ) ;
	    TS_ASSERT(p->tokens != NULL) ;
	    p->currToken = p->tokens ;
	    pr = p->parseExpr(0);    

  	    TS_ASSERT(pr.getNext() != NULL);
  	    TS_ASSERT(pr.getNext()->getNext() != NULL);
	    TS_ASSERT(pr.ast->getLexeme() == "3");
  	    TS_ASSERT(pr.getNext()->ast->getLexeme() == "/");
  	    TS_ASSERT(pr.getNext()->getNext()->ast->getLexeme() == "2");
  	    TS_ASSERT(pr.ast->getTerminal() == intConst);
  	    TS_ASSERT(pr.getNext()->ast->getTerminal() == forwardSlash);
  	    TS_ASSERT(pr.getNext()->getNext()->ast->getTerminal() == intConst);
    }

    //test for Multiplication
    void testMultiplication() {
            ParseResult pr ;
	    const char *text = "3*2";
	    p->tokens = extendTokenList ( p, s->scan (text) ) ;
	    TS_ASSERT(p->tokens != NULL) ;
	    p->currToken = p->tokens ;
	    pr = p->parseExpr(0);    

  	    TS_ASSERT(pr.getNext() != NULL);
  	    TS_ASSERT(pr.getNext()->getNext() != NULL);
	    TS_ASSERT(pr.ast->getLexeme() == "3");
  	    TS_ASSERT(pr.getNext()->ast->getLexeme() == "*");
  	    TS_ASSERT(pr.getNext()->getNext()->ast->getLexeme() == "2");
  	    TS_ASSERT(pr.ast->getTerminal() == intConst);
  	    TS_ASSERT(pr.getNext()->ast->getTerminal() == star);
  	    TS_ASSERT(pr.getNext()->getNext()->ast->getTerminal() == intConst);
    }
    
    //tests for Expressions 
    	//test for constant: string, float, char, int
    void testStringConstant() {
            ParseResult pr ;
	    const char *text = "\"3\" \"2\" \"1\"";
	    /*
	    p->tokens = extendTokenList ( p, s->scan (text) ) ;
	    TS_ASSERT(p->tokens != NULL) ;
	    p->currToken = p->tokens ;
	    pr = p->parseExpr(0);    
  	    TS_ASSERT(pr.getNext() != NULL);
  	    TS_ASSERT(pr.getNext()->getNext() != NULL);
	    TS_ASSERT(pr.ast->getLexeme() == "\"3\"");
  	    TS_ASSERT(pr.getNext()->ast->getLexeme() == "\"2\"");
  	    TS_ASSERT(pr.getNext()->getNext()->ast->getLexeme() == "\"1\"");
  	    TS_ASSERT(pr.ast->getTerminal() == stringConst);
  	    TS_ASSERT(pr.getNext()->ast->getTerminal() == stringConst);
  	    TS_ASSERT(pr.getNext()->getNext()->ast->getTerminal() == stringConst);
	    */

	    //test when just one string constant
	    text = "\"3\"";
	    p->tokens = extendTokenList ( p, s->scan (text) ) ;
	    TS_ASSERT(p->tokens != NULL) ;
	    p->currToken = p->tokens ;
	    pr = p->parseExpr(0);

	    TS_ASSERT(pr.ast->getLexeme() == "\"3\"");
  	    TS_ASSERT(pr.ast->getTerminal() == stringConst);
  	    TS_ASSERT(pr.getNext()->getNext() == NULL);

    }

    void testFloatConstant() {
            ParseResult pr ;
	    const char *text = "3.0 2.0 1.0";
	    /*
	    p->tokens = extendTokenList ( p, s->scan (text) ) ;
	    TS_ASSERT(p->tokens != NULL) ;
	    p->currToken = p->tokens ;
	    pr = p->parseExpr(0);    

  	    TS_ASSERT(pr.getNext() != NULL);
  	    TS_ASSERT(pr.getNext()->getNext() != NULL);
	    TS_ASSERT(pr.ast->getLexeme() == "3.0");
  	    TS_ASSERT(pr.getNext()->ast->getLexeme() == "2.0");
  	    TS_ASSERT(pr.getNext()->getNext()->ast->getLexeme() == "1.0");
  	    TS_ASSERT(pr.ast->getTerminal() == floatConst);
  	    TS_ASSERT(pr.getNext()->ast->getTerminal() == floatConst);
  	    TS_ASSERT(pr.getNext()->getNext()->ast->getTerminal() == floatConst);
	    */

	    //test when just one float constant
	    text = "3.0";
	    p->tokens = extendTokenList ( p, s->scan (text) ) ;
	    TS_ASSERT(p->tokens != NULL) ;
	    p->currToken = p->tokens ;
	    pr = p->parseExpr(0);

	    TS_ASSERT(pr.ast->getLexeme() == "3.0");
  	    TS_ASSERT(pr.ast->getTerminal() == floatConst);
  	    TS_ASSERT(pr.getNext()->getNext() == NULL);
    }

    void testCharConstant() {
            ParseResult pr ;
	    const char *text = "'c' 'b' 'a'";
	    /*
	    p->tokens = extendTokenList ( p, s->scan (text) ) ;
	    TS_ASSERT(p->tokens != NULL) ;
	    p->currToken = p->tokens ;
	    pr = p->parseExpr(0);    

  	    TS_ASSERT(pr.getNext() != NULL);
  	    TS_ASSERT(pr.getNext()->getNext() != NULL);
	    TS_ASSERT(pr.ast->getLexeme() == "'c'");
  	    TS_ASSERT(pr.getNext()->ast->getLexeme() == "'b'");
  	    TS_ASSERT(pr.getNext()->getNext()->ast->getLexeme() == "'a'");
  	    TS_ASSERT(pr.ast->getTerminal() == charConst);
  	    TS_ASSERT(pr.getNext()->ast->getTerminal() == charConst);
  	    TS_ASSERT(pr.getNext()->getNext()->ast->getTerminal() == charConst);
	    */

	    //test when just one char constant
	    text = "'c'";
	    p->tokens = extendTokenList ( p, s->scan (text) ) ;
	    TS_ASSERT(p->tokens != NULL) ;
	    p->currToken = p->tokens ;
	    pr = p->parseExpr(0);

	    TS_ASSERT(pr.ast->getLexeme() == "'c'");
  	    TS_ASSERT(pr.ast->getTerminal() == charConst);
  	    TS_ASSERT(pr.getNext()->getNext() == NULL);
    }

    void testIntConstant() {
            ParseResult pr ;
	    const char *text = "3 2 1";
	    /*
	    p->tokens = extendTokenList ( p, s->scan (text) ) ;
	    TS_ASSERT(p->tokens != NULL) ;
	    p->currToken = p->tokens ;
	    pr = p->parseExpr(0);    

  	    TS_ASSERT(pr.getNext() != NULL);
  	    TS_ASSERT(pr.getNext()->getNext() != NULL);
	    TS_ASSERT(pr.ast->getLexeme() == "3");
  	    TS_ASSERT(pr.getNext()->ast->getLexeme() == "2");
  	    TS_ASSERT(pr.getNext()->getNext()->ast->getLexeme() == "1");
  	    TS_ASSERT(pr.ast->getTerminal() == intConst);
  	    TS_ASSERT(pr.getNext()->ast->getTerminal() == intConst);
  	    TS_ASSERT(pr.getNext()->getNext()->ast->getTerminal() == intConst);
	    */

	    //test when just one int constant
	    text = "3";
	    p->tokens = extendTokenList ( p, s->scan (text) ) ;
	    TS_ASSERT(p->tokens != NULL) ;
	    p->currToken = p->tokens ;
	    pr = p->parseExpr(0);

	    TS_ASSERT(pr.ast->getLexeme() == "3");
  	    TS_ASSERT(pr.ast->getTerminal() == intConst);
  	    TS_ASSERT(pr.getNext()->getNext() == NULL);
    }
    	//test for kwd: true, false  
    void testTrueKwd() {
            ParseResult pr ;
	    const char *text = "true";
	    p->tokens = extendTokenList ( p, s->scan (text) ) ;
	    TS_ASSERT(p->tokens != NULL) ;
	    p->currToken = p->tokens ;
	    pr = p->parseExpr(0);

	    TS_ASSERT(pr.ast->getLexeme() == "true");
  	    TS_ASSERT(pr.ast->getTerminal() == trueKwd);
  	    TS_ASSERT(pr.getNext()->getNext() == NULL);
    }

    void testFalseKwd() {
            ParseResult pr ;
	    const char *text = "false";
	    p->tokens = extendTokenList ( p, s->scan (text) ) ;
	    TS_ASSERT(p->tokens != NULL) ;
	    p->currToken = p->tokens ;
	    pr = p->parseExpr(0);

	    TS_ASSERT(pr.ast->getLexeme() == "false");
  	    TS_ASSERT(pr.ast->getTerminal() == falseKwd);
  	    TS_ASSERT(pr.getNext()->getNext() == NULL);
    }
    	//test for variableName
    void testVariableName() {
            ParseResult pr ;
	    const char *text = "varname";
	    p->tokens = extendTokenList ( p, s->scan (text) ) ;
	    TS_ASSERT(p->tokens != NULL) ;
	    p->currToken = p->tokens ;
	    pr = p->parseExpr(0);

	    TS_ASSERT(pr.ast->getLexeme() == "varname");
  	    TS_ASSERT(pr.ast->getTerminal() == variableName);
  	    TS_ASSERT(pr.getNext()->getNext() == NULL);
    }
    	
    //test for Stmt
    	//test for left stmt, and right stmt
    
    //test for Transition
    
    //test for Type 
       
    //test for Decl
    
    //test for State
    
    //test for Platform
    
    //test for Program
     
    
    
     

    /* In this file you will add 3 additional tests like the one for
       squareMapper below.

       You will also add a number of tests that demonstrate how you
       incrementally developed and tested your implementation, as
       described in the specifications for Iteration 3.  This will
       also include the appropriate documentation of that effort.
    */

    /*void ttest_ast_squareMapper ( ) {
        string file = "../samples/squareMapper.cff" ;
        const char *text =  readInputFromFile ( file.c_str() )  ;
        TS_ASSERT ( text ) ;

        // 1. Test that the file can be parsed.
        ParseResult pr = p->parse ( text ) ;
        TSM_ASSERT ( "file \"" + file + "\" failed to parse. " + 
                     "It had errors: " + pr.errors, pr.ok ) ;

        // 2. Verify that the ast field is not null
        TSM_ASSERT ( "\"" + file + "\" failed to generate an AST.",
                     pr.ast != NULL );

        // 3. Verify that the parser AST is an Expr.
        Program *p = dynamic_cast<Program *>(pr.ast) ;
        TSM_ASSERT ( "file \"" + file + 
                     "\" parser failed to return a Program AST", p ) ;

        // 4. Verify that the correct name is reported.
        TSM_ASSERT_EQUALS ( "file \"" + file + 
                            "\" returned wrong name" ,
                            p->getName(), "SquareMapper" ) ;

        // 5. Verify that the correct number of states.
        TSM_ASSERT_EQUALS ( "file \"" + file + 
                            "\" returned wrong number of states" ,
                            p->getNumStates(), 1 ) ;

        // 6. Verify that the correct number variable declarations.
        TSM_ASSERT_EQUALS ( "file \"" + file + 
                            "\" returned wrong number of variable declarations" ,
                            p->getNumVarDecls(), 0 ) ;

        // 7. Verify that the correct number variable uses.
        TSM_ASSERT_EQUALS ( "file \"" + file + 
                            "\" returned wrong number of variable uses" ,
                            p->getNumVarUses(), 3 ) ;
    }*/

  
} ;
