//Generated Machine.h for SumOfSquares

#include "RunTime.h"

//Declaration of the State classes

class State_Start;
class State_Compute;

class SumOfSquares_Machine {
	public: 
	SumOfSquares_Machine ( int argc, char **argv ) ; 
	void go () ; 
	IntegerComputer *runTime ;

	// Machine states
	State_Start* state_Start;
	State_Compute* state_Compute;


	int Var_i ;

	int Var_s ;
} ;

class SumOfSquaresState : public MachineState {
	public:
	SumOfSquares_Machine *stateMachine ;
} ;

//Concrete machine states
class State_Start : public SumOfSquaresState {
	public: 
	MachineState *enter () ;
	State_Start ( SumOfSquares_Machine *m ) ; 
} ;

class State_Compute : public SumOfSquaresState {
	public: 
	MachineState *enter () ;
	State_Compute ( SumOfSquares_Machine *m ) ; 
} ;

