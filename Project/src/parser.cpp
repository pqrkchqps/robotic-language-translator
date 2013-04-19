/* A recursive descent parser with operator precedence.

   Author: Eric Van Wyk

   This algorithm is based on the work of Douglas Crockford in "Top
   Down Operator Precedence", a chapter in the book "Beautiful Code".
   Mr. Crockford describes in his chapter how his work is based on an
   algorithm described Vaughan Pratt in "Top Down Operator
   Precedence", presented at the ACM Symposium on Principles of
   Programming Languages.

   Douglas Crockford's chapter is available at 
    http://javascript.crockford.com/tdop/tdop.html

   Vaughan Pratt's paper is available at 
    http://portal.acm.org/citation.cfm?id=512931

   These are both quite interesting works and worth reading if you
   find the problem of parsing to be an interesting one.

   Last modified: March 5, 2013.
*/

#include "parser.h"
#include "scanner.h"
#include "extToken.h"

#include <assert.h>

using namespace std ;

int i; 

Parser::Parser ( ) { } 

ParseResult Parser::parse (const char *text) {
    assert (text != NULL) ;

    ParseResult pr ;
    try {
        Scanner *s = new Scanner() ;
        tokens = extendTokenList ( this, s->scan (text) ) ;

        assert (tokens != NULL) ;
        currToken = tokens ;
        pr = parseProgram( ) ;
    }
    catch (string errMsg) {
        pr.setOK(false);
        pr.setErrors(errMsg);
        pr.ast = NULL ;
    }
    return pr ;
}

/* 
 * parse methods for non-terminal symbols
 * --------------------------------------
 */


// Program
ParseResult Parser::parseProgram () {
    ParseResult pr ;

    // Program ::= nameKwd colon variableName semiColon Platform Decls States
    match(nameKwd) ;
    match(colon) ;

    match(variableName) ;
    string name( prevToken->lexeme ) ;

    match(semiColon) ;

    //ParseResult prPlatform = 
    parsePlatform() ;
    //Platform *p = NULL ;
    //if (prPlatform.ast) {
    //    p = dynamic_cast<Platform *>(prPlatform.ast) ;
    //    if ( ! p ) throw ( (string) "Bad cast of Platform in parseProgram" ) ;
    //}

    //ParseResult prDecls = 
    parseDecls() ;
    //Decls *d = NULL ;
    //if (prDecls.ast) {
    //    d = dynamic_cast<Decls *>(prDecls.ast) ;
    //    if ( ! d ) throw ( (string) "Bad cast of Decls in parseProgram" ) ;
    //}

    //ParseResult prStates = 
    parseStates() ;
    //State *s = NULL ;
    //if (prStates.ast) {
    //    s = dynamic_cast<State *>(prStates.ast) ;
    //    if ( ! s ) throw ( (string) "Bad cast of State in parseProgram" ) ;
    //}

    match(endOfFile) ;

    //pr.ast = new Program(name, p, d, s) ;
    //pr.setOK(true);
    return pr ;
}

// Platform
ParseResult Parser::parsePlatform () {
    ParseResult pr ;

    // Platform ::= platformKwd colon variableName semiColon
    match(platformKwd) ;
    match(colon) ;
    match(variableName) ;
    match(semiColon) ;

    return pr ;
}

// Decls
ParseResult Parser::parseDecls () {
    ParseResult pr ;

    if ( ! nextIs(initialKwd) && ! nextIs(stateKwd) ) {
        // Decls ::= Decl Decls
        parseDecl() ;
        parseDecls() ;
    }
    else {
        // Decls ::= 
        // nothing to match.
    }

    return pr ;
}


// Decl
ParseResult Parser::parseDecl () {
    ParseResult pr ;
    // Decl ::= Type variableName semiColon
    parseType() ;
    match(variableName) ;
    match(semiColon) ;
    return pr ;
}

// Type
ParseResult Parser::parseType () {
    ParseResult pr ;

    if ( attemptMatch(intKwd) ) {
        // Type ::= intKwd
    } 
    else if ( attemptMatch(floatKwd) ) {
        // Type ::= floatKwd
    }
    else if ( attemptMatch(booleanKwd) ) {
        // Type ::= booleanKwd
    }
    else if ( attemptMatch(stringKwd) ) {
        // Type ::= stringKwd
    }
    else {
        // Type ::= charKwd
        match(charKwd) ;
    }
    return pr ;
}


// States
ParseResult Parser::parseStates () {
    ParseResult pr ;

    if ( ! nextIs(endOfFile) ) {
        // States ::= State States
        parseState() ;
        parseStates() ;
    }
    else {
        // States ::= 
        // nothing to match.
    }
    return pr ;
}


// State
ParseResult Parser::parseState () {
    ParseResult pr ;

    // State ::= stateKwd colon variableName 
    //           leftCurly Transitions rightCurly
    // State ::= initialKwd stateKwd colon variableName 
    //           leftCurly Transitions rightCurly

    bool isInitial ;
    if ( attemptMatch(initialKwd) ) {
        isInitial = true ;
    }
    else {
        isInitial = false ;
    }

    match(stateKwd) ;
    match(colon) ;
    match(variableName) ;
    match(leftCurly) ;
    parseTransitions() ;
    match(rightCurly) ;

    return pr ;

    /* Compare this function to parseTransition.  The productions
       parsed by both are similar in that they differ only in the
       parts that begin the right hand side.  That is, the productions
       parsed by each have common suffixes.  But parseState handles
       the differing initial part (the optional 'initiial' keyword)
       and the uses the same code to parse the common suffix.  The
       parseTransition function has duplicated code for parsing the
       common suffix.  Neither approach is always better than the
       other.  It depends primarily on what we want to do with the
       parsed code. We will see this in iteration 3 when we build
       abstract syntax trees. 
     */
}



// Transitions
ParseResult Parser::parseTransitions () {
    ParseResult pr ;

    if ( ! nextIs(rightCurly) ) {
        // Transitions ::= Transition Transitions
        parseTransition() ;
        parseTransitions() ;
    }
    else {
        // Transitions ::= 
        // nothing to match.
    }

    return pr ;
}


// Transition
ParseResult Parser::parseTransition () {
    ParseResult pr ;

    if ( nextIs(gotoKwd) ) {
        // Transition ::= gotoKwd variableName whenKwd Expr 
        //                performingKwd leftCurly Stmts rightCurly semiColon
        match(gotoKwd) ;
        match(variableName) ;
        match(whenKwd) ;
        parseExpr(0) ;
        match(performingKwd) ;
        match(leftCurly) ;
        parseStmts() ;
        match(rightCurly) ;
        match(semiColon) ;
    }
    else {
        // Transition ::= exitKwd whenKwd Expr 
        //                performingKwd leftCurly Stmts rightCurly semiColon
        match(exitKwd) ;
        match(whenKwd) ;
        parseExpr(0) ;
        match(performingKwd) ;
        match(leftCurly) ;
        parseStmts() ;
        match(rightCurly) ;
        match(semiColon) ;
    }

    return pr ;
}


// Stmts
ParseResult Parser::parseStmts () {
    ParseResult pr ;

    if ( ! nextIs(rightCurly) ) {
        // Stmts ::= Stmt Stmts
        parseStmt() ;
        parseStmts() ;
    }
    else {
        // Stmts ::= 
        // nothing to match.
    }
    return pr ;
}


// Stmt
ParseResult Parser::parseStmt () {
    ParseResult pr ;

    // Stmt ::= variableName assign Expr semiColon
    match(variableName) ;
    match(assign) ;
    parseExpr(0) ;
    match(semiColon) ;

    return pr ;
}

// Expr
ParseResult Parser::parseExpr (int rbp) {
    /* Examine current token, without consuming it, to call its
       associated parse methods.  The ExtToken objects have 'nud' and
       'led' methods that are dispatchers that call the appropriate
       parse methods.*/
       
    ParseResult left = currToken->nud() ;
    //if (prevToken->terminal == extendedExpr)
    //	  left = currToken->led(left) ;
    while (rbp < currToken->lbp() ) {
        left = currToken->led(left) ;
    }

    return left ;
}


/*
 * parse methods for Expr productions
 * ----------------------------------
 */

// Expr ::= trueKwd
ParseResult Parser::parseTrueKwd ( ) {
    ParseResult pr ;
    match ( trueKwd ) ;
    return pr ;
}

// Expr ::= falseKwd
ParseResult Parser::parseFalseKwd ( ) {
    ParseResult pr ;
    match ( falseKwd ) ;
    return pr ;
}

// Expr ::= intConst
ParseResult Parser::parseIntConst ( ) {
    ParseResult pr;
    match ( intConst ) ;
    pr.ast = new IntConstResult(prevToken->lexeme);
    //make and store a parseResult of type ExprToken 
    return pr;
}

// Expr ::= floatConst
ParseResult Parser::parseFloatConst ( ) {
    ParseResult pr ;
    match ( floatConst ) ;
    return pr ;
}

// Expr ::= stringConst
ParseResult Parser::parseStringConst ( ) {
    ParseResult pr ;
    match ( stringConst ) ;
    return pr ;
}

// Expr ::= charConst
ParseResult Parser::parseCharConst ( ) {
    ParseResult pr ;
    match ( charConst ) ;
    return pr ;
}

// Expr ::= variableName
ParseResult Parser::parseVariableName ( ) {
    ParseResult pr ;
    match ( variableName ) ;
    return pr ;
}

// Expr ::= leftParen Expr rightParen
ParseResult Parser::parseNestedExpr ( ) {
    ParseResult pr ;
    match ( leftParen ) ;
    parseExpr(0) ; 
    match(rightParen) ;
    return pr ;
}

// Expr ::= Expr plusSign Expr
ParseResult Parser::parseAddition ( ParseResult left ) {
    // parser has already matched left expression
    ParseResult pr;
    //make and store a parseResult of type ExprToken 
    match ( plusSign ) ;
    pr.ast = new AdditionExprResult();
    //make and store a parseResult of type ExprToken 

    ParseResult right = parseExpr( prevToken->lbp() ); 
    
    left.setNext(&pr);
    pr.setNext(&right);
    return left;
}

// Expr ::= Expr star Expr
ParseResult Parser::parseMultiplication ( ParseResult left ) {
    // parser has already matched left expression 
    ParseResult pr ;

    match ( star ) ;
    parseExpr( prevToken->lbp() ); 

    return pr ;
}

// Expr ::= Expr dash Expr
ParseResult Parser::parseSubtraction ( ParseResult left ) {
    // parser has already matched left expression 
    ParseResult pr ;

    match ( dash ) ;
    parseExpr( prevToken->lbp() ); 

    return pr ;
}

// Expr ::= Expr forwardSlash Expr
ParseResult Parser::parseDivision ( ParseResult left ) {
    // parser has already matched left expression 
    ParseResult pr ;

    match ( forwardSlash ) ;
    parseExpr( prevToken->lbp() ); 

    return pr ;
}

/***********************************************************************************

	New implement: New adding tests functionality of parseResult, led and nud. 
	We want to impliment in 2 ways. One way we translate token into parseResult
	and another way we store property of parseResult. 
	
***********************************************************************************/ 

ParseResult Parser::parseExprToken () {
    match (lexicalError) ;
    ExprResult* pr = new ExprResult(prevToken->lexeme);
    //make and store a parseResult of type ExprToken 

    ParseResult *ret = dynamic_cast<ParseResult*>(pr);
    return *ret;
}

ParseResult Parser::parseNullExprToken ( ) {
    match (endOfFile) ;
    NullExprResult* pr = new NullExprResult();
     //make and store a parseResult of type NullExprToken 
    //pr = currToken->nud(); 
    ParseResult *ret = dynamic_cast<ParseResult*>(pr);
    return *ret;
}

ParseResult Parser::parseNullExprToken (ParseResult left ) {
    match (endOfFile) ;
    NullExprResult* pr = new NullExprResult();
     //make and store a parseResult of type NullExprToken 
    //pr = currToken->nud(); 
    ParseResult *ret = dynamic_cast<ParseResult*>(pr);
    left.setNext(ret);
    return left;
}

ParseResult Parser::parseExtendedExprToken (ParseResult left) {
	 //parse has already matched left expression 
    match(lexicalError) ;
    ExtendedExprResult* pr = new ExtendedExprResult( prevToken->lexeme ) ;
        
    // just advance token, since examining it in parseExpr caused
    // this method being called.
    ParseResult right = parseExpr( prevToken->lbp() ); 
    
    ParseResult* par = dynamic_cast<ParseResult*>(pr);
    
    left.setNext(par);
    par->setNext(&right);

    return left;
}





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
ParseResult Parser::parseRelationalExpr ( ParseResult left ) {
    // parser has already matched left expression 
    ParseResult pr ;

    nextToken( ) ;
    // just advance token, since examining it in parseExpr caused
    // this method being called.
    parseExpr( prevToken->lbp() ); 

    return pr ;
}


// Helper function used by the parser.

void Parser::match (tokenType tt) {
    if (! attemptMatch(tt)) {
        throw ( makeErrorMsgExpected ( tt ) ) ;
    }
}

bool Parser::attemptMatch (tokenType tt) {
    if (currToken->terminal == tt) { 
        nextToken() ;
        return true ;
    }
    return false ;
}

bool Parser::nextIs (tokenType tt) {
    return currToken->terminal == tt ;
}

void Parser::nextToken () {
    if (currToken->terminal == endOfFile && currToken->next == NULL) {
        prevToken = currToken ;
    } else if (currToken->terminal != endOfFile && currToken->next == NULL) {
        throw ( makeErrorMsg ( "Error: tokens end with endOfFile" ) ) ;
    } else {
        prevToken = currToken ;
        currToken = currToken->next ;
    }
}

string Parser::terminalDescription ( tokenType terminal ) {
    Token *dummyToken = new Token ("",terminal, NULL) ;
    ExtToken *dummyExtToken = extendToken (this, dummyToken) ;
    string s = dummyExtToken->description() ;
    delete dummyToken ;
    delete dummyExtToken ;
    return s ;
}

string Parser::makeErrorMsgExpected ( tokenType terminal ) {
    string s = (string) "Expected " + terminalDescription (terminal) +
        " but found " + currToken->description() ;
    return s ;
}

string Parser::makeErrorMsg ( tokenType terminal ) {
    string s = "Unexpected symbol " + terminalDescription (terminal) ;
    return s ;
}

string Parser::makeErrorMsg ( const char *msg ) {
    return msg ;
}
