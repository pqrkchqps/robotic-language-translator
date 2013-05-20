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
    string lexeme; //lexeme : a sequence of characters
    ASTNode* next;
    string name;
    string type;
    ASTNode* current;
    virtual string cppCode_h(){return 0;}
    virtual string cppCode_cpp(){return 0;}
};

class Expr : public ASTNode{};

class SingleExpr : public ASTNode{
	string cppCode_cpp() {return lexeme;}
	};

class NestedExpr : public ASTNode{
	public:		
		Expr *expr;
		string cppCode_cpp() {return "(" + expr->cppCode_cpp() + ")";}
};

class OpExpr : public ASTNode{
	public:
		string op;
		Expr *left;
		Expr *right;
		string cppCode_cpp() {
			stringstream s;
			s << left->cppCode_cpp() << op << right->cppCode_cpp();
			return s.str();
		}
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
		h << "#include \"RunTime.h\"\n\n";
			
		State *currentState = state;
		h << "//Declaration of the State classes\n\n" ; 
		
		while(currentState != NULL) {	
			h << "class State_" << currentState->name <<";" <<"\n"; //dereference of currentState
			currentState = dynamic_cast<State*>(currentState->next);	
		}
		
		
		h << "\nclass " << name << "_Machine {\n";
		h << "\tpublic: \n"; 
		h << "\t" << name << "_Machine ( int argc, char **argv ) ; \n";		
		h << "\tvoid go () ; \n"; 
		h << "\t" << platform->name << " *runTime ;\n\n" ; 		 
		h << "\t// Machine states\n";
		
		State *curState = state; 
		while(curState != NULL) {	
			h << "\tState_" << curState->name << "* state_" << curState->name << ";\n"; 
			curState = dynamic_cast<State*>(curState->next);	
		}		
		h << "\n";
	
		Decl * curDecl = decl; 
		while(curDecl != NULL) {
			h << "\n\t" << curDecl->type << curDecl->name << "; \n";
			curDecl = dynamic_cast<Decl*>(curDecl->next);	
		}
		
		
	    h << "} ;\n\n";
	    
	    h << "class " << name << "State : public MachineState {\n";
	    h << "\tpublic:\n"; 
	    h << "\t" << name << "_Machine *stateMachine ;\n";
        h << "} ;\n\n";
		
		
		h << "//Concrete machine states\n"; 
		
		State *concreteState = state;
		while(concreteState != NULL) {
			h << "class State_" <<concreteState->name << " : public" << name << "State {\n";
			h << "\tpublic:\n";
			h << "\t" << name << "State *enter () ;\n" ; 
			h << "\tState_" << concreteState->name << " ( " << name << "_Machine *m ) ; \n"; 
			h << "} ;\n\n";
			concreteState = dynamic_cast<State*>(concreteState->next);	
		}	
			
		
		return h.str();
		}
		
		

		string cppCode_cpp(){
		stringstream cpp; 
		cpp << "//Generated Machine.cpp for " << name << "\n\n";
		cpp << "#include \"Machine.h\"\n\n";
		cpp << "using namespace std ;\n\n";
		cpp << name << "_Machine::" << name << "_Machine ( int argc, char **argv ) { \n";
		cpp << "\trunTime = new " << platform->name << " ( argc, argv ); \n"; 

		State *currentState = state;
		cpp << "\t//Creating state objects \n"; 
		while(currentState != NULL) {	
			cpp << "\tstate_" << currentState->name << " = new State_" 
				<< currentState->name << "(this)" << ";\n"; 
			currentState = dynamic_cast<State*>(currentState->next);	
		}
		cpp << "} \n\n"; 
		cpp << "void " << name << "_Machine::go() {\n"; 
		State *getIntialState = state;
		while (getIntialState != NULL) {
		 	cpp << "\trunTime->run( state_"<<getIntialState->name << " ); \n";
		 	getIntialState = dynamic_cast<State*>(getIntialState->current);	
		 }
	    cpp << "} \n\n";
	    
	 
	    
		cpp << "// Concrete machine states \n";	
		State *currState = state; 
		while (currState != NULL) {
			int i = 0.0; 
			cpp << "MachineState *State_" << currState->name << "::enter() {\n";
			
			
			cpp << "\t if (" <<"conditions" <<") {\n";
			cpp << "\t\tstateMachine->\n" ;
			cpp << "\t\treturn " << "stateMachine->state_" << "Tests\n";
			cpp << "} \n";	
			
			cpp << "\t if ( true ) {" ;
			cpp << "stateMachine->" <<"AAAAAAAAAA" << " = (stateMachine->" << "AAAAAA"
				<< "->" << "actuators"<< " + " << i;
					
			cpp << "\n\t\tState_" << currState->name << "::State_" << currState->name 
				<< " ( " << name << "_Machine *m ) {\n";
			cpp << "\t\tstateMachine = m ;\n";
			cpp << "} \n\n";
			currState = dynamic_cast<State*>(currState->next);
		}
		
		
		
		cpp << "//A 'main' program to run the state machine.\n"; 
		cpp << "int main ( int argc, char **argv ) {\n" ;
		cpp << "\t" << name << "_Machine *" << name << " = new " << name 
			<< "_Machine (argc, argv) ;\n";
		cpp << "\t" << name << "->go() ;\n";
		cpp << "} \n\n";
		
		
		return cpp.str();
	
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
