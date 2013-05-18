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
    this means each token is stored as a separate parse result.
    We will be using polymorphic behavior, so we will need a general abstract interface
    to represent the common parts of the parse result's functionality.
    
    These test cases should be in order of top down design. 
    
    Is there a way to implement Iteration 3 so that you do not need to implement all of 
    the AST classes before you can write and your code can pass a test case?
    That is, how can we develop this so that we do not need to implement the AST classes all at once?
	 How can we start small, perhaps implementing just one class or related set of classes and then proceed from there?
	 
    --> There is a way we can implement the AST classes without writing the entire parser. 
    By following the recommendation given in the instruction, we can start with one none terminal 
    such as expression and incremental test and write the code. We originally try to add small
    helper Tokens and helper functions to test the functionality of expression without
    writing all the expression. This proved unhelpful, and testing the functionality of a single
    compound expression, addition, was far more effective and producing and testing good code. 
    
    To implement expression we experiment with the number of design, the most useful one all involved
    a list of ParseResult. The first method for implementing polymorphic behavior used ParseResult
    as a base class for newly implemented custom ParseResult types. This code did not work with 
    the existing style presented in the code base. The implementation we finally used closely 
    mimic the style of the sample code found online. Custom ASTNode(s) was stored on ParseResult 
    in polymorphic behavior which used for type checking the ASTNode. 
    
    To test this functionality will be start with the addition test case and preceded to 
    copy this style for all the subsequence expressions.   


/////

    To test the functionality of constant expressions we opted to just check the case
    where one constant expression was handed to the parseExpr method.
    The reason we did this is because the parser should fail if the sequence of
    expressions are not valid.  The case where there are more than one expression was
    commented out because it is not useful for testing that constant expressions
    evaluate correctly.  The functionality that checks for bad expressions will likely
    be tested in a one of the nonterminals higher in the AST.

    Testing for trueKwd, falseKwd and variableName followed the same pattern as the 
    other constant expressions.  These terminals experienced no problems.

    
/////
    Decided to implement a functional style for the decl, decls.
    This will involve an interface that has a ConsDecl with a car to the left and a cdr to the right
    Both of these should return a ParseResult. The car should return a Decl.
    The cdr should return either another ConsDecl or a NullDecl.

    Tests were added for these interfaces.

////

// Program
ParseResult Parser::parseProgram () {

// Platform
// Platform should store the name of the platform along with standard info
ParseResult Parser::parsePlatform () {

// Decls
ParseResult Parser::parseDecls () {

// Decl
// Platform should store the name of the platform along with standard info
ParseResult Parser::parseDecl () {

// Type
// Return TypeResult that store the type in the ASTNode's terminal and lexeme 
ParseResult Parser::parseType () {

// States
// This functions identically to Decls
ParseResult Parser::parseStates () {

// State
//State has a bool that says where the State is the initial State, and stores the variableName lexeme.
ParseResult Parser::parseState () {

// Transitions
// Transitions work the same as the Decls
ParseResult Parser::parseTransitions () {

// Transition
//Store the iterator for Expression on the TransitionResult,
//Store the vairableName in the Token lexeme and 
//Store ConsStmtResult with car pointing to the first statement and cdr pointing to the rest
//store if Transition is to an exit as a bool variable on TransitionResult
ParseResult Parser::parseTransition () {

// Stmts
//This works the same as Decls
    	//test for left stmt, and right stmt
ParseResult Parser::parseStmts () {

// Stmt
//Store the variableName in the ASTNode's lexeme
//Store the iterator for Expression on StmtResult,
//The iterator should point to the front of the Expression list
ParseResult Parser::parseStmt () {
     
// Expr ::= Expr equalEquals Expr
// Expr ::= Expr lessThanEquals Expr
// Expr ::= Expr greaterThanEquals Expr
// Expr ::= Expr notEquals Expr
// Expr ::= Expr leftAngle Expr
// Expr ::= Expr rightAngle Expr
/* Notice that for relational operators we use just one parse
   function.  This shows another possible means for implementing
   expressions, as opposed to the method used for arithmetic
   expressions in which each operation has its own parse method.  It
   will depend on what we do in iteration 3 in building an abstract
   syntax tree to decide which method is better.
 */   
//Functionality works the same as parseExpr
//Store the in one ASTNode called RealtionalExpr
//Save the lexeme and terminal from the token just parsed to the ASTNode
//Save the whole Expression as an iterator
//Refactor to use iterator design pattern
    
    
/*************************************************************************************/
    
    
    //test for Addition 
    void testAddition() {
            ParseResult pr ;
	    const char *text = "3+2";
	    p->tokens = extendTokenList ( p, s->scan (text) ) ;
	    TS_ASSERT(p->tokens != NULL) ;
	    p->currToken = p->tokens ;
	    pr = p->parseExpr(0);
	    string lexemes[] = { "3", "2", "1"};
	    //for (iterator

  	    TS_ASSERT(pr.getNext() != NULL);
  	    TS_ASSERT(pr.getNext()->getNext() != NULL);
	    TS_ASSERT(pr.ast->getLexeme() == "3");
  	    /*TS_ASSERT(pr.getNext()->ast->getLexeme() == "+");
  	    TS_ASSERT(pr.getNext()->getNext()->ast->getLexeme() == "2");
  	    TS_ASSERT(pr.ast->getTerminal() == intConst);
  	    TS_ASSERT(pr.getNext()->ast->getTerminal() == plusSign);
  	    TS_ASSERT(pr.getNext()->getNext()->ast->getTerminal() == intConst);*/
    }/*

    //test for Subtraction
    void ttestSubtraction() {
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
    void ttestDivision() {
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
    void ttestMultiplication() {
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
    void ttestStringConstant() {
            ParseResult pr ;
	    const char *text = "\"3\"";
	    p->tokens = extendTokenList ( p, s->scan (text) ) ;
	    TS_ASSERT(p->tokens != NULL) ;
	    p->currToken = p->tokens ;
	    pr = p->parseExpr(0);

	    TS_ASSERT(pr.ast->getLexeme() == "\"3\"");
  	    TS_ASSERT(pr.ast->getTerminal() == stringConst);
  	    TS_ASSERT(pr.getNext()->getNext() == NULL);

    }

    void ttestFloatConstant() {
            ParseResult pr ;
	    const char *text = "3.0";
	    p->tokens = extendTokenList ( p, s->scan (text) ) ;
	    TS_ASSERT(p->tokens != NULL) ;
	    p->currToken = p->tokens ;
	    pr = p->parseExpr(0);

	    TS_ASSERT(pr.ast->getLexeme() == "3.0");
  	    TS_ASSERT(pr.ast->getTerminal() == floatConst);
  	    TS_ASSERT(pr.getNext()->getNext() == NULL);
    }

    void ttestCharConstant() {
            ParseResult pr ;
	    const char *text = "'c'";
	    p->tokens = extendTokenList ( p, s->scan (text) ) ;
	    TS_ASSERT(p->tokens != NULL) ;
	    p->currToken = p->tokens ;
	    pr = p->parseExpr(0);

	    TS_ASSERT(pr.ast->getLexeme() == "'c'");
  	    TS_ASSERT(pr.ast->getTerminal() == charConst);
  	    TS_ASSERT(pr.getNext()->getNext() == NULL);
    }

    void ttestIntConstant() {
            ParseResult pr ;
	    const char *text = "3";
	    p->tokens = extendTokenList ( p, s->scan (text) ) ;
	    TS_ASSERT(p->tokens != NULL) ;
	    p->currToken = p->tokens ;
	    pr = p->parseExpr(0);

	    TS_ASSERT(pr.ast->getLexeme() == "3");
  	    TS_ASSERT(pr.ast->getTerminal() == intConst);
  	    TS_ASSERT(pr.getNext()->getNext() == NULL);
    }
    	//test for kwd: true, false  
    void ttestTrueKwd() {
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

    void ttestFalseKwd() {
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
    void ttestVariableName() {
            ParseResult pr ;
	    const char *text = "varname";
	    p->tokens = extendTokenList ( p, s->scan (text) ) ;
	    TS_ASSERT(p->tokens != NULL) ;
	    p->currToken = p->tokens ;
	    pr = (ParseResult)(p->parseExpr(0));

	    TS_ASSERT(pr.ast->getLexeme() == "varname");
  	    TS_ASSERT(pr.ast->getTerminal() == variableName);
  	    TS_ASSERT(pr.getNext()->getNext() == NULL);
    }
*/

/*
    void ttestConsDecl() {
	    const char *text = "initial x : 5";
	    p->tokens = extendTokenList ( p, s->scan (text) ) ;
	    TS_ASSERT(p->tokens != NULL) ;
	    p->currToken = p->tokens ;
            ParseResult pr = p->parseDecls();
	    ConsDeclResult *ptr = static_cast<ConsDeclResult*>(&pr);
	    TS_ASSERT(ptr->ast != NULL);
	    TS_ASSERT(ptr->car()->ast != NULL);
  	    TS_ASSERT(ptr->car()->ast->getTerminal() == declsToken);
  	    TS_ASSERT(ptr->cdr()->car()->ast == NULL);
    	    TS_ASSERT(ptr->ast->getLexeme() == "ConsDecl");
  	    TS_ASSERT(ptr->ast->getTerminal() == consDeclToken);
  	    TS_ASSERT(ptr.getNext() == NULL);
    }

    //test for Nested Expressin
    // Refactor to use the iterator design pattern
    void ttestNestedExpression() {
            ParseResult pr ;
	    //Check one simple nested expression
	    const char *text = "(3)";
	    p->tokens = extendTokenList ( p, s->scan (text) ) ;
	    TS_ASSERT(p->tokens != NULL) ;
	    p->currToken = p->tokens ;
	    pr = p->parseExpr(0);    

  	    TS_ASSERT(pr.getNext() != NULL);
  	    TS_ASSERT(pr.getNext()->getNext() != NULL);
	    TS_ASSERT(pr.ast->getLexeme() == "(");
	    TS_ASSERT(pr.getNext()->ast->getLexeme() == "3");
  	    TS_ASSERT(pr.getNext()->getNext()->ast->getLexeme() == ")");
  	    TS_ASSERT(pr.ast->getTerminal() == leftParen);
  	    TS_ASSERT(pr.getNext()->ast->getTerminal() == intConst);
  	    TS_ASSERT(pr.getNext()->getNext()->ast->getTerminal() == rightParen);

	    //Check one complex nested expression
	    text = "(3*2)";
	    p->tokens = extendTokenList ( p, s->scan (text) ) ;
	    TS_ASSERT(p->tokens != NULL) ;
	    p->currToken = p->tokens ;
	    pr = p->parseExpr(0);    

  	    //TS_ASSERT(pr.getNext() != NULL);
  	    //TS_ASSERT(pr.getNext()->getNext() != NULL);
  	    //TS_ASSERT(pr.getNext()->getNext()->getNext() != NULL);
  	    //TS_ASSERT(pr.getNext()->getNext()->getNext()->getNext() != NULL);
	    //TS_ASSERT(pr.ast->getLexeme() == "(");
	    //TS_ASSERT(pr.getNext()->ast->getLexeme() == "3");
  	    //TS_ASSERT(pr.getNext()->getNext()->ast->getLexeme() == "*");
  	    //TS_ASSERT(pr.getNext()->getNext()->getNext()->ast->getLexeme() == "2");
  	    //TS_ASSERT(pr.getNext()->getNext()->getNext()->getNext()->ast->getLexeme() == ")");
  	    //TS_ASSERT(pr.ast->getTerminal() == leftParen);
  	    //TS_ASSERT(pr.getNext()->ast->getTerminal() == intConst);
  	    //TS_ASSERT(pr.getNext()->getNext()->ast->getTerminal() == star);
  	    //TS_ASSERT(pr.getNext()->getNext()->getNext()->ast->getTerminal() == intConst);
  	    //TS_ASSERT(pr.getNext()->getNext()->getNext()->getNext()->ast->getTerminal() == rightParen);

	    //Check three nested expression
	    /*text = "((3+33)*(2+22))";
	    p->tokens = extendTokenList ( p, s->scan (text) ) ;
	    TS_ASSERT(p->tokens != NULL) ;
	    p->currToken = p->tokens ;
	    pr = p->parseExpr(0);    

		//Check for nulls
  	    TS_ASSERT(pr.getNext() != NULL);
  	    TS_ASSERT(pr.getNext()->getNext() != NULL);
  	    TS_ASSERT(pr.getNext()->getNext()->getNext() != NULL);
  	    TS_ASSERT(pr.getNext()->getNext()->getNext()->getNext() != NULL);
  	    TS_ASSERT(pr.getNext()->getNext()->getNext()->getNext()->getNext() != NULL);
  	    TS_ASSERT(pr.getNext()->getNext()->getNext()->getNext()->getNext()->getNext() != NULL);
  	    TS_ASSERT(pr.getNext()->getNext()->getNext()->getNext()->getNext()->getNext()->
				getNext() != NULL);
  	    TS_ASSERT(pr.getNext()->getNext()->getNext()->getNext()->getNext()->getNext()->
				getNext()->getNext() != NULL);
  	    TS_ASSERT(pr.getNext()->getNext()->getNext()->getNext()->getNext()->getNext()->
				getNext()->getNext()->getNext() != NULL);
  	    TS_ASSERT(pr.getNext()->getNext()->getNext()->getNext()->getNext()->getNext()->
				getNext()->getNext()->getNext()->getNext() != NULL);
  	    TS_ASSERT(pr.getNext()->getNext()->getNext()->getNext()->getNext()->getNext()->
				getNext()->getNext()->getNext()->getNext()->getNext() != NULL);
  	    TS_ASSERT(pr.getNext()->getNext()->getNext()->getNext()->getNext()->getNext()->
				getNext()->getNext()->getNext()->getNext()->getNext()->getNext() != NULL);
  	    TS_ASSERT(pr.getNext()->getNext()->getNext()->getNext()->getNext()->getNext()->
				getNext()->getNext()->getNext()->getNext()->getNext()->getNext() != NULL);

		//Check lexemes
  	    TS_ASSERT(pr.getNext()->ast->getLexeme() == "(");
  	    TS_ASSERT(pr.getNext()->getNext()->ast->getLexeme() == "(");
  	    TS_ASSERT(pr.getNext()->getNext()->getNext()->ast->getLexeme() == "3");
  	    TS_ASSERT(pr.getNext()->getNext()->getNext()->getNext()->ast->getLexeme() == "+");
  	    TS_ASSERT(pr.getNext()->getNext()->getNext()->getNext()->getNext()->ast->getLexeme() == "33");
  	    TS_ASSERT(pr.getNext()->getNext()->getNext()->getNext()->getNext()->getNext()->ast->getLexeme() == ")");
  	    TS_ASSERT(pr.getNext()->getNext()->getNext()->getNext()->getNext()->getNext()->
				getNext()->ast->getLexeme() == "*");
  	    TS_ASSERT(pr.getNext()->getNext()->getNext()->getNext()->getNext()->getNext()->
				getNext()->getNext()->ast->getLexeme() == "(");
  	    TS_ASSERT(pr.getNext()->getNext()->getNext()->getNext()->getNext()->getNext()->
				getNext()->getNext()->getNext()->ast->getLexeme() == "2");
  	    TS_ASSERT(pr.getNext()->getNext()->getNext()->getNext()->getNext()->getNext()->
				getNext()->getNext()->getNext()->getNext()->ast->getLexeme() == "+");
  	    TS_ASSERT(pr.getNext()->getNext()->getNext()->getNext()->getNext()->getNext()->
				getNext()->getNext()->getNext()->getNext()->getNext()->ast->getLexeme() == "22");
  	    TS_ASSERT(pr.getNext()->getNext()->getNext()->getNext()->getNext()->getNext()->
				getNext()->getNext()->getNext()->getNext()->getNext()->
					getNext()->ast->getLexeme() == ")");
  	    TS_ASSERT(pr.getNext()->getNext()->getNext()->getNext()->getNext()->getNext()->
				getNext()->getNext()->getNext()->getNext()->getNext()->
					getNext()->getNext()->ast->getLexeme() == ")");

		//Check for terminals
  	    TS_ASSERT(pr.getNext()->ast->getTerminal() == leftParen);
  	    TS_ASSERT(pr.getNext()->getNext()->ast->getTerminal() == leftParen);
  	    TS_ASSERT(pr.getNext()->getNext()->getNext()->ast->getTerminal() == intConst);
  	    TS_ASSERT(pr.getNext()->getNext()->getNext()->getNext()->ast->getTerminal() == plusSign);
  	    TS_ASSERT(pr.getNext()->getNext()->getNext()->getNext()->getNext()->ast->getTerminal() == intConst);
  	    TS_ASSERT(pr.getNext()->getNext()->getNext()->getNext()->getNext()->getNext()->ast->getTerminal() == rightParen);
  	    TS_ASSERT(pr.getNext()->getNext()->getNext()->getNext()->getNext()->getNext()->
				getNext()->ast->getTerminal() == star);
  	    TS_ASSERT(pr.getNext()->getNext()->getNext()->getNext()->getNext()->getNext()->
				getNext()->getNext()->ast->getTerminal() == leftParen);
  	    TS_ASSERT(pr.getNext()->getNext()->getNext()->getNext()->getNext()->getNext()->
				getNext()->getNext()->getNext()->ast->getTerminal() == intConst);
  	    TS_ASSERT(pr.getNext()->getNext()->getNext()->getNext()->getNext()->getNext()->
				getNext()->getNext()->getNext()->getNext()->ast->getTerminal() == plusSign);
  	    TS_ASSERT(pr.getNext()->getNext()->getNext()->getNext()->getNext()->getNext()->
				getNext()->getNext()->getNext()->getNext()->getNext()->ast->getTerminal() == intConst);
  	    TS_ASSERT(pr.getNext()->getNext()->getNext()->getNext()->getNext()->getNext()->
				getNext()->getNext()->getNext()->getNext()->getNext()->
					getNext()->ast->getTerminal() == rightParen);
  	    TS_ASSERT(pr.getNext()->getNext()->getNext()->getNext()->getNext()->getNext()->
				getNext()->getNext()->getNext()->getNext()->getNext()->
					getNext()->getNext()->ast->getTerminal() == rightParen);
	    */
    //}
    	
/*
// Program
ParseResult Parser::parseProgram () {


// Platform
// Platform should store the name of the platform along with standard info
ParseResult Parser::parsePlatform () {


// Decls
ParseResult Parser::parseDecls () {


// Decl
// Platform should store the name of the platform along with standard info
ParseResult Parser::parseDecl () {


// Type
// Return TypeResult that store the type in the ASTNode's terminal and lexeme 
ParseResult Parser::parseType () {


// States
// This functions identically to Decls
ParseResult Parser::parseStates () {


// State
//State has a bool that says where the State is the initial State, and stores the variableName lexeme.
ParseResult Parser::parseState () {


// Transitions
// Transitions work the same as the Decls
ParseResult Parser::parseTransitions () {


// Transition
//Store the iterator for Expression on the TransitionResult,
//Store the vairableName in the Token lexeme and 
//Store ConsStmtResult with car pointing to the first statement and cdr pointing to the rest
//store if Transition is to an exit as a bool variable on TransitionResult
ParseResult Parser::parseTransition () {


// Stmts
//This works the same as Decls
    	//test for left stmt, and right stmt
ParseResult Parser::parseStmts () {


// Stmt
//Store the variableName in the ASTNode's lexeme
//Store the iterator for Expression on StmtResult,
//The iterator should point to the front of the Expression list
ParseResult Parser::parseStmt () {
     


//Functionality works the same as parseExpr
//Store the in one ASTNode called RealtionalExpr
//Save the lexeme and terminal from the token just parsed to the ASTNode
//Save the whole Expression as an iterator
//Refactor to use iterator design pattern
	void ttestRelationalExpr () {
            ParseResult pr ;
	    const char *text = "3==2";
	    p->tokens = extendTokenList ( p, s->scan (text) ) ;
	    TS_ASSERT(p->tokens != NULL) ;
	    p->currToken = p->tokens ;
	    pr = p->parseExpr(0);
  	    TS_ASSERT(pr.getNext() != NULL);
  	    TS_ASSERT(pr.getNext()->getNext() != NULL);
	    TS_ASSERT(pr.ast->getLexeme() == "3");
  	    TS_ASSERT(pr.getNext()->ast->getLexeme() == "==");
  	    TS_ASSERT(pr.getNext()->getNext()->ast->getLexeme() == "2");
  	    TS_ASSERT(pr.ast->getTerminal() == intConst);
  	    TS_ASSERT(pr.getNext()->ast->getTerminal() == equalEquals);
  	    TS_ASSERT(pr.getNext()->getNext()->ast->getTerminal() == intConst);
            ParseResult pr ;
	    const char *text = "3<=2";
	    p->tokens = extendTokenList ( p, s->scan (text) ) ;
	    TS_ASSERT(p->tokens != NULL) ;
	    p->currToken = p->tokens ;
	    pr = p->parseExpr(0);
  	    TS_ASSERT(pr.getNext() != NULL);
  	    TS_ASSERT(pr.getNext()->getNext() != NULL);
	    TS_ASSERT(pr.ast->getLexeme() == "3");
  	    TS_ASSERT(pr.getNext()->ast->getLexeme() == "<=");
  	    TS_ASSERT(pr.getNext()->getNext()->ast->getLexeme() == "2");
  	    TS_ASSERT(pr.ast->getTerminal() == intConst);
  	    TS_ASSERT(pr.getNext()->ast->getTerminal() == lessThanEquals);
  	    TS_ASSERT(pr.getNext()->getNext()->ast->getTerminal() == intConst);
            ParseResult pr ;
	    const char *text = "3>=2";
	    p->tokens = extendTokenList ( p, s->scan (text) ) ;
	    TS_ASSERT(p->tokens != NULL) ;
	    p->currToken = p->tokens ;
	    pr = p->parseExpr(0);
  	    TS_ASSERT(pr.getNext() != NULL);
  	    TS_ASSERT(pr.getNext()->getNext() != NULL);
	    TS_ASSERT(pr.ast->getLexeme() == "3");
  	    TS_ASSERT(pr.getNext()->ast->getLexeme() == ">=");
  	    TS_ASSERT(pr.getNext()->getNext()->ast->getLexeme() == "2");
  	    TS_ASSERT(pr.ast->getTerminal() == intConst);
  	    TS_ASSERT(pr.getNext()->ast->getTerminal() == greaterThanEquals);
  	    TS_ASSERT(pr.getNext()->getNext()->ast->getTerminal() == intConst);
            ParseResult pr ;
	    const char *text = "3!=2";
	    p->tokens = extendTokenList ( p, s->scan (text) ) ;
	    TS_ASSERT(p->tokens != NULL) ;
	    p->currToken = p->tokens ;
	    pr = p->parseExpr(0);
  	    TS_ASSERT(pr.getNext() != NULL);
  	    TS_ASSERT(pr.getNext()->getNext() != NULL);
	    TS_ASSERT(pr.ast->getLexeme() == "3");
  	    TS_ASSERT(pr.getNext()->ast->getLexeme() == "!=");
  	    TS_ASSERT(pr.getNext()->getNext()->ast->getLexeme() == "2");
  	    TS_ASSERT(pr.ast->getTerminal() == intConst);
  	    TS_ASSERT(pr.getNext()->ast->getTerminal() == notEquals);
  	    TS_ASSERT(pr.getNext()->getNext()->ast->getTerminal() == intConst);
            ParseResult pr ;
	    const char *text = "3<2";
	    p->tokens = extendTokenList ( p, s->scan (text) ) ;
	    TS_ASSERT(p->tokens != NULL) ;
	    p->currToken = p->tokens ;
	    pr = p->parseExpr(0);
  	    TS_ASSERT(pr.getNext() != NULL);
  	    TS_ASSERT(pr.getNext()->getNext() != NULL);
	    TS_ASSERT(pr.ast->getLexeme() == "3");
  	    TS_ASSERT(pr.getNext()->ast->getLexeme() == "<");
  	    TS_ASSERT(pr.getNext()->getNext()->ast->getLexeme() == "2");
  	    TS_ASSERT(pr.ast->getTerminal() == intConst);
  	    TS_ASSERT(pr.getNext()->ast->getTerminal() == leftAngle);
  	    TS_ASSERT(pr.getNext()->getNext()->ast->getTerminal() == intConst);
            ParseResult pr ;
	    const char *text = "3>2";
	    p->tokens = extendTokenList ( p, s->scan (text) ) ;
	    TS_ASSERT(p->tokens != NULL) ;
	    p->currToken = p->tokens ;
	    pr = p->parseExpr(0);
  	    TS_ASSERT(pr.getNext() != NULL);
  	    TS_ASSERT(pr.getNext()->getNext() != NULL);
	    TS_ASSERT(pr.ast->getLexeme() == "3");
  	    TS_ASSERT(pr.getNext()->ast->getLexeme() == ">");
  	    TS_ASSERT(pr.getNext()->getNext()->ast->getLexeme() == "2");
  	    TS_ASSERT(pr.ast->getTerminal() == intConst);
  	    TS_ASSERT(pr.getNext()->ast->getTerminal() == rightAngle);
  	    TS_ASSERT(pr.getNext()->getNext()->ast->getTerminal() == intConst);
	}

    void ttest_ast_squareMapper ( ) {
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


	void ttest_ast_abstar() {
	        string file = "../samples/abstar.cff" ;
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
                            p->getName(), "ABStar" ) ;

	        // 5. Verify that the correct number of states.
	        TSM_ASSERT_EQUALS ( "file \"" + file + 
                            "\" returned wrong number of states" ,
                            p->getNumStates(), 3 ) ;

	        // 6. Verify that the correct number variable declarations.
	        TSM_ASSERT_EQUALS ( "file \"" + file + 
                            "\" returned wrong number of variable declarations" ,
                            p->getNumVarDecls(), 0 ) ;

	        // 7. Verify that the correct number variable uses.
	        TSM_ASSERT_EQUALS ( "file \"" + file + 
                            "\" returned wrong number of variable uses" ,
                            p->getNumVarUses(), 16 ) ;
	}

	void ttest_ast_box (){
	        string file = "../samples/box.cff" ;
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
                            p->getName(), "Box" ) ;

	        // 5. Verify that the correct number of states.
	        TSM_ASSERT_EQUALS ( "file \"" + file + 
                            "\" returned wrong number of states" ,
                            p->getNumStates(), 5 ) ;

	        // 6. Verify that the correct number variable declarations.
	        TSM_ASSERT_EQUALS ( "file \"" + file + 
                            "\" returned wrong number of variable declarations" ,
                            p->getNumVarDecls(), 1 ) ;

	        // 7. Verify that the correct number variable uses.
	        TSM_ASSERT_EQUALS ( "file \"" + file + 
                            "\" returned wrong number of variable uses" ,
                            p->getNumVarUses(), 18 ) ;
	}

	void ttest_ast_sumOfSquares is written correctly.{
	        string file = "../samples/sumOfSquares.cff" ;
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
                            p->getName(), "SumOfSquares" ) ;

	        // 5. Verify that the correct number of states.
	        TSM_ASSERT_EQUALS ( "file \"" + file + 
                            "\" returned wrong number of states" ,
                            p->getNumStates(), 2 ) ;

	        // 6. Verify that the correct number variable declarations.
	        TSM_ASSERT_EQUALS ( "file \"" + file + 
                            "\" returned wrong number of variable declarations" ,
                            p->getNumVarDecls(), 2 ) ;

	        // 7. Verify that the correct number variable uses.
	        TSM_ASSERT_EQUALS ( "file \"" + file + 
                            "\" returned wrong number of variable uses" ,
                            p->getNumVarUses(), 12 ) ;
	}
*/
} ;
