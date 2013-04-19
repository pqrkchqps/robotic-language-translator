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
     
    /************************************************************************************
    
    We created a new token type parseExprToken and parseExtendedExprToken because 
    we want to test functionality of parseResult, led and nud. We want to implement
    them in 2 ways. One way we translate token into parseResult and another way we store 
    property of parseResult. 
    
    The first method we used was to transform token and store the token as a parseResult  
    this means each token is stored as a seperate parse result.
    We will be using polymorphic behavor, so we will need a general abstract interface
    to represent the common parts of the parse result's functionality.
    
    These test cases should be in order of top down design. 
    
    Is there a way to implement Iteration 3 so that you do not need to implement all of 
    the AST classes before you can write and your code can pass a test case?
    That is, how can we develop this so that we do not need to implement the AST classes all at once?
	 How can we start small, perhaps implementing just one class or related set of classes and then proceed from there?
	 
    --> There is a way we can implement the AST classes without writting the entire parser. 
    By following the recommendation given in the instruction, we can start with one none terminal 
    such as expression and incrementaly test and write the code. We orgininally try to add small
    helper Tokens and helper functions to test the functionality of expression without
    writting all the expression. This proved unhelpful, and testing the functionality of a single
    compound expression, addition, was far more effective and producing and testing good code. 
    
    To implement expression we experiment with the number of design, the most useful one all involved
    a list of parseResult. The first method for implementing polymophic behavior used parseResult
    as a base class for newly implemented custom ParseResult types. This code did not work with 
    the exsinting style presented in the code base. The implementation we finally used closely 
    mimic the style of the sample code found online. Custom ASTNode(s) was stored on Parseresult 
    in polymophic behavoir which used for type checking the ASTNode. 
    
    To test this functionality will be start with the addition testcase and precided to 
    copy this style for all the subsequence expressions.   
    
    
    
    
    *************************************************************************************/
    
    
	//test for Addition 
    void testAddition() {
            ParseResult pr ;
	    const char *text = "3+2";
	    p->tokens = extendTokenList ( p, s->scan (text) ) ;
	    TS_ASSERT(p->tokens != NULL) ;
	    p->currToken = p->tokens ;
	    pr = p->parseExpr(0);
	    TS_ASSERT(pr.getLexeme() == "3");
  	    TS_ASSERT(pr.getNext()->getLexeme() == "+");
  	    TS_ASSERT(pr.getNext()->getNext()->getLexeme() == "2");
  	    TS_ASSERT(pr.getTerminal() == intConst);
  	    TS_ASSERT(pr.getNext()->getTerminal() == plusSign);
  	    TS_ASSERT(pr.getNext()->getNext()->getTerminal() == intConst);
    }
    
    //test for Subtraction 
      void testSubtraction() {
            ParseResult pr ;
	    const char *text = "3-2";
	    p->tokens = extendTokenList ( p, s->scan (text) ) ;
	    TS_ASSERT(p->tokens != NULL) ;
	    p->currToken = p->tokens ;
	    pr = p->parseExpr(0);
	    TS_ASSERT(pr.getLexeme() == "3");
  	    TS_ASSERT(pr.getNext()->getLexeme() == "-");
  	    TS_ASSERT(pr.getNext()->getNext()->getLexeme() == "2");
  	    TS_ASSERT(pr.getTerminal() == intConst);
  	    TS_ASSERT(pr.getNext()->getTerminal() == dash);
  	    TS_ASSERT(pr.getNext()->getNext()->getTerminal() == intConst);
    }
    
    //test for Multiplication
    
    //test for Division 
    
    //test for Expression 
    	//test for constant: string, float, char, int
    	//test for kwd: true, false
    	//test for variableName
    	
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
