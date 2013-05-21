// Generated Machine.cpp code for Box

#include "Machine.h"
using namespace std ;
Box_Machine::Box_Machine (int argc, char **argv) {
	runTime = new PositionalRobot(argc, argv) ;
	state_Init = new State_Init(this) ;
	state_MoveNorth = new State_MoveNorth(this) ;
	state_MoveEast = new State_MoveEast(this) ;
	state_MoveSouth = new State_MoveSouth(this) ;
	state_MoveWest = new State_MoveWest(this) ;
}

void Box_Machine::go() {
	runTime->run( state_Init ); 
}

MachineState *State_Init::enter() {
	if ( true ) {
		stateMachine->Var_timesAround = 0 ;
		stateMachine->runTime->xPos = 0.0 ;
		stateMachine->runTime->yPos = 0.0 ;
	return stateMachine->state_MoveNorth ;
	}
}

State_Init::State_Init ( Box_Machine *m ) {
	stateMachine = m ;
}

MachineState *State_MoveNorth::enter() {
	if ( ( stateMachine->Var_timesAround==4 ) ) {
	return NULL ;
	}

	if ( ( stateMachine->runTime->yPos>=100 ) ) {
	return stateMachine->state_MoveEast ;
	}

	if ( true ) {
		stateMachine->runTime->yPos = ( stateMachine->runTime->yPos+1.0 ) ;
	return stateMachine->state_MoveNorth ;
	}
}

State_MoveNorth::State_MoveNorth ( Box_Machine *m ) {
	stateMachine = m ;
}

MachineState *State_MoveEast::enter() {
	if ( ( stateMachine->runTime->xPos>=100 ) ) {
	return stateMachine->state_MoveSouth ;
	}

	if ( true ) {
		stateMachine->runTime->xPos = ( stateMachine->runTime->xPos+1.0 ) ;
	return stateMachine->state_MoveEast ;
	}
}

State_MoveEast::State_MoveEast ( Box_Machine *m ) {
	stateMachine = m ;
}

MachineState *State_MoveSouth::enter() {
	if ( ( stateMachine->runTime->yPos<=0.0 ) ) {
	return stateMachine->state_MoveWest ;
	}

	if ( true ) {
		stateMachine->runTime->yPos = ( stateMachine->runTime->yPos-1.0 ) ;
	return stateMachine->state_MoveSouth ;
	}
}

State_MoveSouth::State_MoveSouth ( Box_Machine *m ) {
	stateMachine = m ;
}

MachineState *State_MoveWest::enter() {
	if ( ( stateMachine->runTime->xPos<=0.0 ) ) {
		stateMachine->Var_timesAround = ( stateMachine->Var_timesAround+1 ) ;
	return stateMachine->state_MoveNorth ;
	}

	if ( true ) {
		stateMachine->runTime->xPos = ( stateMachine->runTime->xPos-1.0 ) ;
	return stateMachine->state_MoveWest ;
	}
}

State_MoveWest::State_MoveWest ( Box_Machine *m ) {
	stateMachine = m ;
}




int main (int argc, char **argv) {
	Box_Machine *Box = new Box_Machine (argc, argv) ;
Box->go() ;
}