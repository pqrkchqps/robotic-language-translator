#include <cxxtest/TestSuite.h>

#include "readInput.h"
#include "scanner.h"
#include "extToken.h"
#include "parser.h"
#include "parseResult.h"
#include <stdio.h>
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

    /* In this file you will add 3 additional tests like the one for
       squareMapper below.

       You will also add a number of tests that demonstrate how you
       incrementally developed and tested your implementation, as
       described in the specifications for Iteration 3.  This will
       also include the appropriate documentation of that effort.
    */

    void test_ast_squareMapper ( ) {
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
    }

  
} ;
