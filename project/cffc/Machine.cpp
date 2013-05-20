//Generated Machine.cpp for Box

#include "Machine.h"

using namespace std ;

Box_Machine::Box_Machine ( int argc, char **argv ) { 
	runTime = new PositionalRobot ( argc, argv ); 
	//Creating state objects 
	state_Init = new State_Init(this);
	state_MoveNorth = new State_MoveNorth(this);
	state_MoveEast = new State_MoveEast(this);
	state_MoveSouth = new State_MoveSouth(this);
	state_MoveWest = new State_MoveWest(this);
} 

void Box_Machine::go() {
	runTime->run( state_Init ); 
} 

// Concrete machine states 
MachineState *State_Init::enter() {
	 if (conditions) {
		stateMachine->
		return stateMachine->state_Tests
} 
	 if ( true ) {stateMachine->AAAAAAAAAA = (stateMachine->AAAAAA->actuators + 0
		State_Init::State_Init ( Box_Machine *m ) {
		stateMachine = m ;
} 

MachineState *State_MoveNorth::enter() {
	 if (conditions) {
		stateMachine->
		return stateMachine->state_Tests
} 
	 if ( true ) {stateMachine->AAAAAAAAAA = (stateMachine->AAAAAA->actuators + 0
		State_MoveNorth::State_MoveNorth ( Box_Machine *m ) {
		stateMachine = m ;
} 

MachineState *State_MoveEast::enter() {
	 if (conditions) {
		stateMachine->
		return stateMachine->state_Tests
} 
	 if ( true ) {stateMachine->AAAAAAAAAA = (stateMachine->AAAAAA->actuators + 0
		State_MoveEast::State_MoveEast ( Box_Machine *m ) {
		stateMachine = m ;
} 

MachineState *State_MoveSouth::enter() {
	 if (conditions) {
		stateMachine->
		return stateMachine->state_Tests
} 
	 if ( true ) {stateMachine->AAAAAAAAAA = (stateMachine->AAAAAA->actuators + 0
		State_MoveSouth::State_MoveSouth ( Box_Machine *m ) {
		stateMachine = m ;
} 

MachineState *State_MoveWest::enter() {
	 if (conditions) {
		stateMachine->
		return stateMachine->state_Tests
} 
	 if ( true ) {stateMachine->AAAAAAAAAA = (stateMachine->AAAAAA->actuators + 0
		State_MoveWest::State_MoveWest ( Box_Machine *m ) {
		stateMachine = m ;
} 

//A 'main' program to run the state machine.
int main ( int argc, char **argv ) {
	Box_Machine *Box = new Box_Machine (argc, argv) ;
	Box->go() ;
} 

