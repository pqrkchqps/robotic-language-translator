/* A recursive descent parser with operator precedence.

   Author: Eric Van Wyk

   This algorithms is based on the work of Douglas Crockford in "Top
   Down Operator Precedence", a chapter in the book "Beautiful Code".
   Mr. Crockford describes in his chapter how his work comes from that
   of Based on algorithms described Vaughan Pratt in "Top Down Operator
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

#ifndef PARSER_H
#define PARSER_H

#include "scanner.h"
#include "parseResult.h"

#include <string>
#include <sstream>
class ExtToken ;
class ParseResult ;

class ASTNode {
public:
    string lexeme;
    ASTNode* next;
    string name;
    virtual string cppCode_h(){return 0;}
    virtual string cppCode_cpp(){return 0;}
};

class Expr : public ASTNode{};

class SingleExpr : public ASTNode{};

class NestedExpr : public ASTNode{
	public:
		Expr *expr;
};

class OpExpr : public ASTNode{
	public:
		string op;
		Expr *left;
		Expr *right;
};

class Stmt : public ASTNode{
	public:
		Expr *expr;
};

class Transition : public ASTNode{
	public:
		bool isGoto;//destination state stored in lexeme
		Expr *conditional;
		Stmt *statement;

};

class Platform : public ASTNode{};

class Type : public ASTNode{};

class Decl : public ASTNode{
public:
	Type *type;
};

class State : public ASTNode{
	public:
		bool initialState;
		Transition *transition;
};

class Program : public ASTNode{
	public:
		Platform *platform;
		Decl *decl;
		State *state;
		string getName();
		int getNumStates();
		int getNumVarDecls();
		int getNumVarUses();
		int varUse;
		string cppCode_h(){
		stringstream h;
		h << "//Generated Machine.h for " << name << "\n\n";
		h << "#include \"runtime.h\"\n\n";
		h << "//declarations of the state classes\n";
			
		State *currentState = state;
		while(currentState != NULL) {	
			h << "class State_" << currentState->name <<";\n\n"; //dereference of currentState
			currentState = dynamic_cast<State*>(currentState->next);	
		}
		
		h << "class " << name << "_Machine {\n";
		h << "\t public: \n"; 
		h << "\t" << name << "_Machine";
		 
		
	
		
		
		
		return h.str();

		}
		string cppCode_cpp(){
		return "Generated .cpp code";

		}
};

class Parser {

public:
    Parser() ;

    ParseResult parse (const char *text) ;

    // Parser methods for the nonterminals:
    // Program, Platform, Decls, Decl, States, State,
    // Transitions, Transition, Stmts, Stmt, Expr

    ParseResult parseProgram () ;
    ParseResult parsePlatform () ;
    ParseResult parseDecls () ;
    ParseResult parseDecl () ;
    ParseResult parseType () ;
    ParseResult parseStates () ;
    ParseResult parseState () ;
    ParseResult parseTransitions () ;
    ParseResult parseTransition () ;
    ParseResult parseStmts () ;
    ParseResult parseStmt () ;
    ParseResult parseExpr (int rbp) ;

    // methods for parsing productions for Expr
    ParseResult parseTrueKwd () ;
    ParseResult parseFalseKwd () ;
    ParseResult parseIntConst () ;
    ParseResult parseFloatConst () ;
    ParseResult parseStringConst () ;
    ParseResult parseCharConst () ;
    ParseResult parseVariableName () ;

    ParseResult parseNestedExpr () ;

    ParseResult parseAddition ( ParseResult left ) ;
    ParseResult parseMultiplication ( ParseResult left ) ;
    ParseResult parseSubtraction ( ParseResult left ) ;
    ParseResult parseDivision ( ParseResult left ) ;

    ParseResult parseRelationalExpr ( ParseResult left ) ;
	int varUse;
    // Helper function used by the parser.
    void match (tokenType tt) ;
    bool attemptMatch (tokenType tt) ;
    bool nextIs (tokenType tt) ;
    void nextToken () ;

    std::string terminalDescription ( tokenType terminal ) ;
    std::string makeErrorMsg ( tokenType terminal ) ;
    std::string makeErrorMsgExpected ( tokenType terminal ) ;
    std::string makeErrorMsg ( const char *msg ) ;

    ExtToken *tokens ;
    ExtToken *currToken ;
    ExtToken *prevToken ;

} ;

#endif /* PARSER_H */
