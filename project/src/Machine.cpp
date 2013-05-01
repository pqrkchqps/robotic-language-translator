// Generated Machine.cpp for ABStar

#include "Machine.h"
using namespace std ;
ABStar_Machine::ABStar_Machine (int argc, char **argv) { 
   runTime = new RegexRecognizer(argc, argv) ; 
   // Creating state objects 
   state_Final = new State_Final(this) ; 
   state_NeedB = new State_NeedB(this) ; 
   state_Error = new State_Error(this) ; 
} 

void ABStar_Machine::go() { 
   runTime->run( state_Final ); 
} 

// Concrete machine states
MachineState *State_Final::enter() {
   if ( (stateMachine->runTime->nextChar == 'a') ) { 
      stateMachine->runTime->outputBuffer = "In Final, found A" ;

      return stateMachine->state_NeedB ; 
   } 

   if ( (stateMachine->runTime->nextChar != '\0') ) { 
      stateMachine->runTime->outputBuffer = "In Final, found something other than B" ;

      return stateMachine->state_Error ; 
   } 

   if ( (stateMachine->runTime->nextChar == '\0') ) { 
      stateMachine->runTime->outputBuffer = "In Final, exiting." ;

      return NULL ;   } 

}

State_Final::State_Final ( ABStar_Machine *m ) {
   stateMachine = m ; 
}


MachineState *State_NeedB::enter() {
   if ( (stateMachine->runTime->nextChar == 'b') ) { 
      stateMachine->runTime->outputBuffer = "In NeedB, found B" ;

      return stateMachine->state_Final ; 
   } 

   if ( (stateMachine->runTime->nextChar != '\0') ) { 
      stateMachine->runTime->outputBuffer = "In NeedB, found something other than B" ;

      return stateMachine->state_Error ; 
   } 

   if ( (stateMachine->runTime->nextChar == '\0') ) { 
      stateMachine->runTime->outputBuffer = "In NeeDB, exiting." ;

      return NULL ;   } 

}

State_NeedB::State_NeedB ( ABStar_Machine *m ) {
   stateMachine = m ; 
}


MachineState *State_Error::enter() {
   if ( (stateMachine->runTime->nextChar != '\0') ) { 
      stateMachine->runTime->outputBuffer = "In Error" ;

      return stateMachine->state_Error ; 
   } 

   if ( (stateMachine->runTime->nextChar == '\0') ) { 
      stateMachine->runTime->outputBuffer = "In Error, exiting." ;

      return NULL ;   } 

}

State_Error::State_Error ( ABStar_Machine *m ) {
   stateMachine = m ; 
}




// A 'main' program to run the state machine.
int main (int argc, char **argv) { 
  ABStar_Machine *ABStar = new ABStar_Machine (argc, argv) ; 
  ABStar->go() ; 
} 

