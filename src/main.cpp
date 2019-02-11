//============================================================================
// Name        : main.cpp
// Author      : Pawe³ Sak
// Version     :
//============================================================================

#include <iostream>
#include <vector>
#include "..\include\StateMachine.hpp"
#include "..\include\Message.hpp"
#include "..\include\State.hpp"

using namespace std;

int main() {

	StateMachine *masterMachine = new StateMachine("Main");
	StateMachine *slaveMachine = new StateMachine(masterMachine, "StateOn");
	IState *idleState = new State("StateOff");

	masterMachine->addTransitionTableEntry(idleState, Message::POWER_ON, (IState*)slaveMachine);
	masterMachine->addTransitionTableEntry(idleState, Message::POWER_ON, (IState*)slaveMachine);
	masterMachine->addTransitionTableEntry(idleState, Message::POWER_ON, (IState*)slaveMachine);
	masterMachine->addTransitionTableEntry((IState*)slaveMachine, Message::POWER_OFF, idleState);
	masterMachine->addTransitionTableEntry(idleState, Message::POWER_OFF, idleState);
	masterMachine->addTransitionTableEntry((IState*)slaveMachine, Message::POWER_ON, (IState*)slaveMachine);

	IState *stoppedState = new State("StatePlayBackStopped");
	IState *playingState = new State("StatePlaying");
 	slaveMachine->addTransitionTableEntry(stoppedState, Message::START_PLAYBACK, playingState);
 	slaveMachine->addTransitionTableEntry(playingState, Message::STOP_PLAYBACK, stoppedState);
 	slaveMachine->addTransitionTableEntry(stoppedState, Message::STOP_PLAYBACK, stoppedState);
 	slaveMachine->addTransitionTableEntry(playingState, Message::START_PLAYBACK, playingState);


	masterMachine->onMessage(Message::POWER_ON);
	masterMachine->onMessage(Message::POWER_OFF);
	masterMachine->onMessage(Message::POWER_OFF);
	masterMachine->onMessage(Message::POWER_OFF);
	masterMachine->onMessage(Message::POWER_ON);
	masterMachine->onMessage(Message::POWER_ON);
	masterMachine->onMessage(Message::POWER_ON);
	masterMachine->onMessage(Message::POWER_OFF);

 	slaveMachine->onMessage(Message::POWER_ON);
 	slaveMachine->onMessage(Message::POWER_ON);
 	slaveMachine->onMessage(Message::POWER_ON);
 	slaveMachine->onMessage(Message::START_PLAYBACK);
 	slaveMachine->onMessage(Message::START_PLAYBACK);
 	slaveMachine->onMessage(Message::START_PLAYBACK);
 	slaveMachine->onMessage(Message::START_PLAYBACK);
 	slaveMachine->onMessage(Message::STOP_PLAYBACK);
 	slaveMachine->onMessage(Message::STOP_PLAYBACK);
 	slaveMachine->onMessage(Message::START_PLAYBACK);
 	slaveMachine->onMessage(Message::POWER_OFF);
 	slaveMachine->onMessage(Message::POWER_ON);
 	slaveMachine->onMessage(Message::START_PLAYBACK);
 	slaveMachine->onMessage(Message::START_PLAYBACK);
 	slaveMachine->onMessage(Message::STOP_PLAYBACK);
 	slaveMachine->onMessage(Message::POWER_OFF);


//
//	IStateMachine *machine = new StateMachine("odtwarzacz");
//	IState *state1 = new State("gra");
//	IState *state2 = new State("nie gra");
//
//	machine->addTransitionTableEntry(state2,Message::PLAY,state1);
//	machine->addTransitionTableEntry(state1,Message::STOP,state2);
//
//	machine->onMessage(Message::PLAY);
//	machine->onMessage(Message::PLAY);
//	machine->onMessage(Message::STOP);
//	machine->onMessage(Message::PLAY);
//	machine->onMessage(Message::STOP);



	return 0;
}
