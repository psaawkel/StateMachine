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

	return 0;
}
