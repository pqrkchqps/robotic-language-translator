//Generated Machine.h for Box

#include "RunTime.h"

//Declaration of the State classes

class State_Init;
class State_MoveNorth;
class State_MoveEast;
class State_MoveSouth;
class State_MoveWest;

class Box_Machine {
	public: 
	Box_Machine ( int argc, char **argv ) ; 
	void go () ; 
	PositionalRobot *runTime ;

	// Machine states
	State_Init* state_Init;
	State_MoveNorth* state_MoveNorth;
	State_MoveEast* state_MoveEast;
	State_MoveSouth* state_MoveSouth;
	State_MoveWest* state_MoveWest;


	int Var_timesAround ;
} ;

class BoxState : public MachineState {
	public:
	Box_Machine *stateMachine ;
} ;

//Concrete machine states
class State_Init : public BoxState {
	public: 
	MachineState *enter () ;
	State_Init ( Box_Machine *m ) ; 
} ;

class State_MoveNorth : public BoxState {
	public: 
	MachineState *enter () ;
	State_MoveNorth ( Box_Machine *m ) ; 
} ;

class State_MoveEast : public BoxState {
	public: 
	MachineState *enter () ;
	State_MoveEast ( Box_Machine *m ) ; 
} ;

class State_MoveSouth : public BoxState {
	public: 
	MachineState *enter () ;
	State_MoveSouth ( Box_Machine *m ) ; 
} ;

class State_MoveWest : public BoxState {
	public: 
	MachineState *enter () ;
	State_MoveWest ( Box_Machine *m ) ; 
} ;

