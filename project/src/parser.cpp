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
#include <stdio.h>
#include <assert.h>

using namespace std ;

bool SingleExpr::isRuntime(Decl *d){
	Decl *dd = d;
	while (d != NULL){
		if (d->lexeme.compare(this->lexeme)==0){
			d = dd;
			return false;
		}
		d = dynamic_cast<Decl *>(d->next);
	}
	d = dd;
	return true;
}

bool Stmt::isRuntime(Decl *d){
	Decl *dd = d;
	while (d != NULL){
		if (d->lexeme.compare(this->lexeme)==0){
			d = dd;
			return false;
		}
		d = dynamic_cast<Decl *>(d->next);
	}
	d = dd;
	return true;
}
Parser::Parser ( ) { } 

ParseResult Parser::parse (const char *text) {
    assert (text != NULL) ;

    ParseResult pr ;
    try {
        Scanner *s = new Scanner() ;
        tokens = extendTokenList ( this, s->scan (text) ) ;

        assert (tokens != NULL) ;
        currToken = tokens ;
        varUse = 0;
        pr = parseProgram( ) ;
        dynamic_cast<Program*>(pr.ast)->varUse = varUse;
    }
    catch (string errMsg) {
        pr.ok = false ;
        pr.errors = errMsg ;
        pr.ast = NULL ;
    }
    return pr ;
}

//code generation methods




/* 
 * parse methods for non-terminal symbols
 * --------------------------------------
 */
ASTNode* next;
string Program::getName () {
	return lexeme;
}
int Program::getNumStates () {
	int count = 0;
	State *currentState = state;
	while(currentState != NULL) {
		count++;
		currentState = dynamic_cast<State*>(currentState->next);
	}
	return count;
}
int Program::getNumVarDecls () {
	int count = 0;
	Decl *currentDecl = decl;
	while(currentDecl != NULL) {
		count++;
		currentDecl = dynamic_cast<Decl*>(currentDecl->next);
	}
	return count;
}
int Program::getNumVarUses () {
	return varUse;
}
// Program
ParseResult Parser::parseProgram () {
    ParseResult pr ;
    Program *p = new Program();//make new program
    // Program ::= nameKwd colon variableName semiColon Platform Decls States
    match(nameKwd) ;
    match(colon) ;
    match(variableName) ;
    p->lexeme = prevToken->lexeme ; //get program name
    match(semiColon) ;
    
    pr = parsePlatform() ; //temporary pr
    if(pr.ast != NULL) {p->platform = dynamic_cast<Platform*>(pr.ast);} //assign pr.ast to platform
    
    pr = parseDecls() ;
    if(pr.ast != NULL) {p->decl = dynamic_cast<Decl*>(pr.ast);}
    
    pr = parseStates() ;
    if(pr.ast != NULL) {p->state = dynamic_cast<State*>(pr.ast);}
    
    match(endOfFile) ;
		pr.ast = dynamic_cast<ASTNode*>(p);
    return pr ;
}

// Platform
ParseResult Parser::parsePlatform () {
    ParseResult pr ;
		Platform *platform = new Platform();
    // Platform ::= platformKwd colon variableName semiColon
    match(platformKwd) ;
    match(colon) ;
    match(variableName) ;
    platform->lexeme = prevToken->lexeme;
    match(semiColon) ;
		pr.ast = dynamic_cast<ASTNode*>(platform);
    return pr ;
}

// Decls
ParseResult Parser::parseDecls () {
    ParseResult pr ;
	Decl *decl = new Decl();
	ParseResult temp;
    if ( ! nextIs(initialKwd) && ! nextIs(stateKwd) ) {
        // Decls ::= Decl Decls
        temp = parseDecl() ;
        if (temp.ast != NULL){decl = dynamic_cast<Decl*>(temp.ast);}
        
        temp = parseDecls() ;
        if (temp.ast != NULL){decl->next = dynamic_cast<Decl*>(temp.ast);}
        
        pr.ast = dynamic_cast<ASTNode*>(decl);
    }
    else {
        // Decls ::= 
        // nothing to match.
        pr.ast = NULL;
    }
    return pr ;
}


// Decl
ParseResult Parser::parseDecl () {
    ParseResult pr ;
    Decl *decl = new Decl();
    // Decl ::= Type variableName semiColon
    pr = parseType() ;
    if (pr.ast != NULL){decl->type = dynamic_cast<Type*>(pr.ast);}
    match(variableName) ;
    decl->lexeme = prevToken->lexeme;
    match(semiColon) ;
    pr.ast = dynamic_cast<ASTNode*>(decl);
    return pr ;
}

// Type
ParseResult Parser::parseType () {
    ParseResult pr ;
	Type *type = new Type();
    if ( attemptMatch(intKwd) ) {
        // Type ::= intKwd
        type->lexeme = "int";
    } 
    else if ( attemptMatch(floatKwd) ) {
        // Type ::= floatKwd
        type->lexeme = "float";
    }
    else if ( attemptMatch(booleanKwd) ) {
        // Type ::= booleanKwd
        type->lexeme = "bool";
    }
    else if ( attemptMatch(stringKwd) ) {
        // Type ::= stringKwd
        type->lexeme = "string";
    }
    else {
        // Type ::= charKwd
        match(charKwd) ;
        type->lexeme = "char";
    }
    pr.ast = dynamic_cast<ASTNode*>(type);
    return pr ;
}


// States
ParseResult Parser::parseStates () {
    ParseResult pr ;
	State *state = new State();
    if ( ! nextIs(endOfFile) ) {
        // States ::= State States
        pr = parseState() ;
        if (pr.ast != NULL){state = dynamic_cast<State*>(pr.ast);}
        pr = parseStates() ;
        if (pr.ast != NULL){state->next = dynamic_cast<State*>(pr.ast);}
        pr.ast = dynamic_cast<ASTNode*>(state);
    }
    else {
        // States ::= 
        // nothing to match.
        pr.ast = NULL;
    }
    return pr ;
}


// State
ParseResult Parser::parseState () {
    ParseResult pr ;
	State *state = new State();
    // State ::= stateKwd colon variableName 
    //           leftCurly Transitions rightCurly
    // State ::= initialKwd stateKwd colon variableName 
    //           leftCurly Transitions rightCurly
    
    if ( attemptMatch(initialKwd) ) {
        state->initialState = true ;
    }
    else {
        state->initialState = false ;
    }

    match(stateKwd) ;
    match(colon) ;
    match(variableName) ;
    state->lexeme = prevToken->lexeme;
    match(leftCurly) ;
    pr = parseTransitions() ;
    if (pr.ast != NULL){state->transition = dynamic_cast<Transition*>(pr.ast);}
    match(rightCurly) ;
	pr.ast = dynamic_cast<ASTNode*>(state);
    return pr ;

    /* Compare this function to parseTransition.  The productions
       parsed by both are similar in that they differ only in the
       parts that begin the right hand side.  That is, the productions
       parsed by each have common suffixes.  But parseState handles
       the differing initial part (the optional 'initial' keyword)
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
	Transition *transition = new Transition();
    if ( ! nextIs(rightCurly) ) {
        // Transitions ::= Transition Transitions
        pr = parseTransition() ;
        if(pr.ast != NULL){transition = dynamic_cast<Transition*>(pr.ast);}
        pr = parseTransitions() ;
        if(pr.ast != NULL){transition->next = dynamic_cast<Transition*>(pr.ast);}
        pr.ast = dynamic_cast<ASTNode*>(transition);
    }
    else {
        // Transitions ::= 
        // nothing to match.
        pr.ast = NULL;
    }

    return pr ;
}


// Transition
ParseResult Parser::parseTransition () {
    ParseResult pr ;
	Transition *transition = new Transition();
    if ( nextIs(gotoKwd) ) {
        // Transition ::= gotoKwd variableName whenKwd Expr 
        //                performingKwd leftCurly Stmts rightCurly semiColon
        transition->isGoto = true;
        match(gotoKwd) ;
        match(variableName) ;
        transition->lexeme = prevToken->lexeme;
        match(whenKwd) ;
        pr = parseExpr(0) ;
        if (pr.ast != NULL){transition->conditional = dynamic_cast<Expr*>(pr.ast);}
        match(performingKwd) ;
        match(leftCurly) ;
        pr = parseStmts() ;
        if (pr.ast != NULL){transition->statement = dynamic_cast<Stmt*>(pr.ast);}
        match(rightCurly) ;
        match(semiColon) ;
    }
    else {
        // Transition ::= exitKwd whenKwd Expr 
        //                performingKwd leftCurly Stmts rightCurly semiColon
        transition->isGoto = false;
        match(exitKwd) ;
        match(whenKwd) ;
        pr = parseExpr(0) ;
        if (pr.ast != NULL){transition->conditional = dynamic_cast<Expr*>(pr.ast);}
        match(performingKwd) ;
        match(leftCurly) ;
        pr = parseStmts() ;
        if (pr.ast != NULL){transition->statement = dynamic_cast<Stmt*>(pr.ast);}
        match(rightCurly) ;
        match(semiColon) ;
    }
	pr.ast = dynamic_cast<ASTNode*>(transition);
    return pr ;
}


// Stmts
ParseResult Parser::parseStmts () {
    ParseResult pr ;
	Stmt *stmt = new Stmt();
    if (! nextIs(rightCurly) ) {
        // Stmts ::= Stmt Stmts
        pr = parseStmt() ;
        if (pr.ast != NULL){stmt = dynamic_cast<Stmt*>(pr.ast);}
        pr = parseStmts() ;
        if (pr.ast != NULL){stmt->next = dynamic_cast<Stmt*>(pr.ast);}
	pr.ast = dynamic_cast<ASTNode*>(stmt);
   }
    else {
        // Stmts ::= 
        // nothing to match.
        pr.ast = NULL;
    }
    return pr ;
}


// Stmt
ParseResult Parser::parseStmt () {
    ParseResult pr ;
    Stmt *stmt = new Stmt();
    // Stmt ::= variableName assign Expr semiColon
    match(variableName) ;
    stmt->lexeme = prevToken->lexeme;
    varUse++;
    match(assign);
    pr = parseExpr(0);
    if (pr.ast != NULL){stmt->expr = dynamic_cast<Expr*>(pr.ast);}
    match(semiColon);
    pr.ast = dynamic_cast<ASTNode*>(stmt);
    return pr ;
}

// Expr
ParseResult Parser::parseExpr (int rbp) {
    /* Examine current token, without consuming it, to call its
       associated parse methods.  The ExtToken objects have 'nud' and
       'led' methods that are dispatchers that call the appropriate
       parse methods.*/
    ParseResult left = currToken->nud() ;
   
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
    SingleExpr *expr = new SingleExpr();
    match ( trueKwd ) ;
    expr->lexeme = prevToken->lexeme;
    pr.ast = dynamic_cast<ASTNode*>(expr);
    return pr ;
}

// Expr ::= falseKwd
ParseResult Parser::parseFalseKwd ( ) {
    ParseResult pr ;
    SingleExpr *expr = new SingleExpr();
    match ( falseKwd ) ;
    expr->lexeme = prevToken->lexeme;
    pr.ast = dynamic_cast<ASTNode*>(expr);
    return pr ;
}

// Expr ::= intConst
ParseResult Parser::parseIntConst ( ) {
    ParseResult pr ;
    SingleExpr *expr = new SingleExpr();
    match ( intConst ) ;
    expr->lexeme = prevToken->lexeme;
    pr.ast = dynamic_cast<ASTNode*>(expr);
    return pr ;
}

// Expr ::= floatConst
ParseResult Parser::parseFloatConst ( ) {
    ParseResult pr ;
    SingleExpr *expr = new SingleExpr();
    match ( floatConst ) ;
    expr->lexeme = prevToken->lexeme;
    pr.ast = dynamic_cast<ASTNode*>(expr);
    return pr ;
}

// Expr ::= stringConst
ParseResult Parser::parseStringConst ( ) {
    ParseResult pr ;
    SingleExpr *expr = new SingleExpr();
    match ( stringConst ) ;
    expr->lexeme = prevToken->lexeme;
    pr.ast = dynamic_cast<ASTNode*>(expr);
    return pr ;
}

// Expr ::= charConst
ParseResult Parser::parseCharConst ( ) {
    ParseResult pr ;
    SingleExpr *expr = new SingleExpr();
    match ( charConst ) ;
    expr->lexeme = prevToken->lexeme;
    pr.ast = dynamic_cast<ASTNode*>(expr);
    return pr ;
}

// Expr ::= variableName
ParseResult Parser::parseVariableName ( ) {
    ParseResult pr ;
    SingleExpr *expr = new SingleExpr();
    match ( variableName ) ;
    varUse++;
		expr->isvar = true;
    expr->lexeme = prevToken->lexeme;
    pr.ast = dynamic_cast<ASTNode*>(expr);
    return pr ;
}


// Expr ::= leftParen Expr rightParen
ParseResult Parser::parseNestedExpr ( ) {
    ParseResult pr ;
    NestedExpr *expr = new NestedExpr();
    match ( leftParen ) ;
    pr = parseExpr(0) ; 
    if (pr.ast != NULL){expr->expr = dynamic_cast<Expr*>(pr.ast);}
    match(rightParen) ;
    pr.ast = dynamic_cast<ASTNode*>(expr);
    return pr ;
}

// Expr ::= Expr plusSign Expr
ParseResult Parser::parseAddition ( ParseResult left ) {
    // parser has already matched left expression 
    ParseResult pr ;
	OpExpr *expr = new OpExpr();
    match ( plusSign ) ;
    expr->op = prevToken->lexeme;
    pr = parseExpr( prevToken->lbp() ); 
	if (pr.ast != NULL){expr->right = dynamic_cast<Expr*>(pr.ast);}
	if (left.ast != NULL){expr->left = dynamic_cast<Expr*>(left.ast);}
	pr.ast = dynamic_cast<ASTNode*>(expr);
    return pr ;
}

// Expr ::= Expr star Expr
ParseResult Parser::parseMultiplication ( ParseResult left ) {
    // parser has already matched left expression 
    ParseResult pr ;
	OpExpr *expr = new OpExpr();
    match ( star ) ;
    expr->op = prevToken->lexeme;
    pr = parseExpr( prevToken->lbp() ); 
	if (pr.ast != NULL){expr->right = dynamic_cast<Expr*>(pr.ast);}
	if (left.ast != NULL){expr->left = dynamic_cast<Expr*>(left.ast);}
	pr.ast = dynamic_cast<ASTNode*>(expr);
    return pr ;
}

// Expr ::= Expr dash Expr
ParseResult Parser::parseSubtraction ( ParseResult left ) {
    // parser has already matched left expression 
    ParseResult pr ;
	OpExpr *expr = new OpExpr();
    match ( dash ) ;
    expr->op = prevToken->lexeme;
    pr = parseExpr( prevToken->lbp() ); 
	if (pr.ast != NULL){expr->right = dynamic_cast<Expr*>(pr.ast);}
	if (left.ast != NULL){expr->left = dynamic_cast<Expr*>(left.ast);}
	pr.ast = dynamic_cast<ASTNode*>(expr);
    return pr ;
}

// Expr ::= Expr forwardSlash Expr
ParseResult Parser::parseDivision ( ParseResult left ) {
    // parser has already matched left expression 
    ParseResult pr ;
	OpExpr *expr = new OpExpr();
    match ( forwardSlash ) ;
    expr->op = prevToken->lexeme;
    pr = parseExpr( prevToken->lbp() ); 
	if (pr.ast != NULL){expr->right = dynamic_cast<Expr*>(pr.ast);}
	if (left.ast != NULL){expr->left = dynamic_cast<Expr*>(left.ast);}
	pr.ast = dynamic_cast<ASTNode*>(expr);
    return pr ;
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
	OpExpr *expr = new OpExpr;
    nextToken( ) ;
    expr->op = prevToken->lexeme;
    // just advance token, since examining it in parseExpr caused
    // this method being called.
    pr = parseExpr( prevToken->lbp() );
	if (pr.ast != NULL){expr->right = dynamic_cast<Expr*>(pr.ast);}
	if (left.ast != NULL){expr->left = dynamic_cast<Expr*>(left.ast);}     
	pr.ast = dynamic_cast<ASTNode*>(expr);
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

