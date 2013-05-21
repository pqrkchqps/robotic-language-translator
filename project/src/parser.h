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
#include <typeinfo>

class ExtToken;
class ParseResult;
class Decl;

typedef enum {sExpr, nExpr, opExpr} exprType;

class ASTNode {
public:
    string lexeme;
    ASTNode* next;
    string name;
		bool isvar;
		ASTNode() {
			this->isvar = false;
		}
    virtual string cppCode_h(){return 0;}
    virtual string cppCode_cpp(Decl *d){return 0;}
};

class Type : public ASTNode{};

class Decl : public ASTNode{
public:
	Type *type;
};

class Expr : public ASTNode{ 
	public:
	exprType etype;
};

class SingleExpr : public Expr {
	public:
	bool isRuntime(Decl *d);
	SingleExpr() {
		this->etype = sExpr;
	};
	string cppCode_cpp(Decl *d) {
		stringstream s;
		if (isvar){
			s << "stateMachine->";
			if (!isRuntime(d))
				s << "Var_"+this->lexeme;
			else
				s << "runtime->"+this->lexeme;
		} else 
			s << this->lexeme;
		return s.str();
	};
};

class NestedExpr : public Expr {
	public:
	NestedExpr() {
		this->etype = nExpr;
	};
	Expr *expr;
	string cppCode_cpp(Decl *d) {
		return "( " + expr->cppCode_cpp(d) + " )";
	};
};

class OpExpr : public Expr {
	public:
		OpExpr() {
			this->etype = opExpr;
		};
		string op;
		Expr *left;
		Expr *right;
		string cppCode_cpp(Decl *d) {
			return "( " + left->cppCode_cpp(d) + op + right->cppCode_cpp(d) + " )";
		};
};

class Stmt : public ASTNode {
	public:
		Expr *expr;
		bool isRuntime(Decl *d);
		string cppCode_cpp(Decl *d) {
			stringstream s;
			s << "stateMachine->";
			if (!isRuntime(d))
				s << "Var_"+this->lexeme+" = " ;
			else
				s << "runtime->"+this->lexeme+" = " ;

			if (expr->etype == sExpr) {
				SingleExpr *exp=dynamic_cast<SingleExpr*>(expr);
				s << exp->cppCode_cpp(d);
			}
			if (expr->etype == nExpr) {
				NestedExpr *exp=dynamic_cast<NestedExpr*>(expr);
				s << exp->cppCode_cpp(d);
			}
			if (expr->etype == opExpr) {
				OpExpr *exp=dynamic_cast<OpExpr*>(expr);
				s << exp->cppCode_cpp(d);
			}
			s << " ;\n";
			return s.str();
		}
};


class Transition : public ASTNode {
	public:
	bool isGoto;  //destination state stored in lexeme
	Expr *conditional;
	Stmt *statement;
	string cppCode_cpp(Decl *d) {
		stringstream s;
		s << "if ( ";
		if (conditional->etype == sExpr) {
			SingleExpr *exp=dynamic_cast<SingleExpr*>(conditional);
			s << exp->cppCode_cpp(d);
		}
		if (conditional->etype == nExpr) {
			NestedExpr *exp=dynamic_cast<NestedExpr*>(conditional);
			s << exp->cppCode_cpp(d);
		}
		if (conditional->etype == opExpr) {
			OpExpr *exp=dynamic_cast<OpExpr*>(conditional);
			s << exp->cppCode_cpp(d);
		}
		s << " ) {\n";
		
		Stmt *currStatement = dynamic_cast<Stmt*>(statement);
		while (currStatement != NULL) {
			s << "\t\t"+currStatement->cppCode_cpp(d);
			currStatement = dynamic_cast<Stmt*>(currStatement->next);
		}
		if (isGoto)
			s << "\treturn stateMachine->state_"+lexeme+" ;\n\t}";
		else
			s << "\treturn NULL ;\n\t}";
		return s.str();
	};
};

class Platform : public ASTNode{};

class State : public ASTNode{
	public:
		bool initialState;
		Transition *transition;
};

class Program : public ASTNode {
	public:
	Platform *platform;
	Decl *decl;
	State *state;
	string getName();
	int getNumStates();
	int getNumVarDecls();
	int getNumVarUses();
	int varUse;
	string cppCode_h() {
		stringstream h;
		h << "//Generated Machine.h for " << lexeme << "\n\n";
		h << "#include \"runtime.h\"\n\n";
		h << "//declarations of the state classes\n";	
		State *currentState = state;
		while (currentState != NULL) {
			h << "class State_" << currentState->lexeme <<";\n\n";
			currentState = dynamic_cast<State*>(currentState->next);	
		}
		
		h << "class " << lexeme << "_Machine {\n";
		h << "\t public: \n"; 
		h << "\t" << lexeme << "_Machine";
		
		return h.str();
	};

	string cppCode_cpp() {
		stringstream cpp;
		cpp << "// Generated Machine.cpp code for "+getName()+"\n";
		cpp << "\n#include \"Machine.h\"\n";
		cpp << "using namespace std ;\n";
		cpp << getName()+"_Machine::"+getName()+"_Machine (int argc, char **argv) {";
		cpp << "\n\truntime = new "+platform->lexeme+"(argc, argv) ;\n";
		State *currState = state;
		while (currState != NULL) {
			cpp << "\tstate_"+currState->lexeme+" = new State_"+currState->lexeme+"(this) ;\n";
			currState = dynamic_cast<State*>(currState->next);
		}
		cpp << "}\n\n";
		cpp << "void " + getName()+"_Machine::go() {\n\trunTime->run( state_Init ); \n}\n\n";
		currState = state;
		while (currState != NULL) {
			cpp << "MachineState *State_"+currState->lexeme+"::enter() {";
			Transition *currTransition = currState->transition;
			while (currTransition != NULL) {
				cpp << "\n\t"+currTransition->cppCode_cpp(decl)+"\n";
				currTransition = dynamic_cast<Transition *>(currTransition->next);
			}
			cpp << "}\n\nState_"+currState->lexeme+"::State_"+currState->lexeme;
			cpp << " ( "+getName()+"_Machine *m ) {\n\tstatemachine = m ;\n}\n\n";
			currState = dynamic_cast<State*>(currState->next);
		}

		cpp << "\n\n\nint main (int argc, char **argv) {\n\t";
		cpp << getName()+"_Machine *"+getName()+" = new ";
		cpp << getName()+"_Machine (argc, argv) ;\n"+getName()+"->go() ;\n}";
		return cpp.str();
	};
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
    void match (tokenType tt);
    bool attemptMatch (tokenType tt);
    bool nextIs (tokenType tt);
    void nextToken ();

    std::string terminalDescription ( tokenType terminal ) ;
    std::string makeErrorMsg ( tokenType terminal ) ;
    std::string makeErrorMsgExpected ( tokenType terminal ) ;
    std::string makeErrorMsg ( const char *msg ) ;

    ExtToken *tokens;
    ExtToken *currToken;
    ExtToken *prevToken;
} ;

#endif /* PARSER_H */
