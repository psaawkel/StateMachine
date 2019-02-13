//============================================================================
// Name        : main.cpp
// Author      : Pawe³ Sak
// Version     :
//============================================================================

#include "..\test\ProbablyTheSimplestTestFramework.hpp"
#include "..\include\IState.hpp"
#include "..\include\IStateMachine.hpp"
#include "..\include\StateMachine.hpp"
#include "..\include\Message.hpp"
#include "..\include\State.hpp"

#include <iostream>
#include <vector>
using namespace std;

bool test_adding_values_to_transition_table(){
	StateMachine *someMachine = new StateMachine("Main");
	IState *someState = new State("StateOff");
	IState *someState2 = new State("StateOn");

	ASSERT_TRUE(someMachine->addTransitionTableEntry(someState, Message::POWER_ON, someState2));
	ASSERT_FALSE(someMachine->addTransitionTableEntry(someState, Message::POWER_ON, someState));
	ASSERT_TRUE(someMachine->addTransitionTableEntry(someState, Message::START_PLAYBACK, someState2));
	ASSERT_FALSE(someMachine->addTransitionTableEntry(someState, Message::START_PLAYBACK, someState2));

	SUCCESS;
}

bool test_simple_state_machine(){

	StateMachine *someMachine = new StateMachine("Main");
	IState *someState = new State("StateOff");
	IState *someState2 = new State("StateOn");

	someMachine->addTransitionTableEntry(someState, Message::POWER_ON, someState2);
	someMachine->addTransitionTableEntry(someState2, Message::POWER_OFF, someState);

	ASSERT_STRING_EQUAL(someMachine->getCurrentState()->getName(),"StateOff");
	someMachine->onMessage(Message::POWER_ON);
	ASSERT_STRING_EQUAL(someMachine->getCurrentState()->getName(),"StateOn");
	someMachine->onMessage(Message::POWER_ON);
	ASSERT_STRING_EQUAL(someMachine->getCurrentState()->getName(),"StateOn");
	someMachine->onMessage(Message::POWER_OFF);
	ASSERT_STRING_EQUAL(someMachine->getCurrentState()->getName(),"StateOff");

	SUCCESS;
}

bool test_hierarchical_state_machine(){
	StateMachine *masterMachine = new StateMachine("Main");
	StateMachine *slaveMachine = new StateMachine(masterMachine, "StateOn");
	IState *idleState = new State("StateOff");

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

 	ASSERT_STRING_EQUAL(masterMachine->getCurrentState()->getName(), "StateOff");
 	ASSERT_STRING_EQUAL(slaveMachine->getCurrentState()->getName(), "StatePlayBackStopped");

	masterMachine->onMessage(Message::POWER_ON);
 	ASSERT_STRING_EQUAL(masterMachine->getCurrentState()->getName(), "StateOn");
 	ASSERT_STRING_EQUAL(slaveMachine->getCurrentState()->getName(), "StatePlayBackStopped");
	masterMachine->onMessage(Message::POWER_OFF);
 	ASSERT_STRING_EQUAL(masterMachine->getCurrentState()->getName(), "StateOff");
 	ASSERT_STRING_EQUAL(slaveMachine->getCurrentState()->getName(), "StatePlayBackStopped");
	masterMachine->onMessage(Message::POWER_OFF);
 	ASSERT_STRING_EQUAL(masterMachine->getCurrentState()->getName(), "StateOff");
 	ASSERT_STRING_EQUAL(slaveMachine->getCurrentState()->getName(), "StatePlayBackStopped");
	masterMachine->onMessage(Message::POWER_ON);
 	ASSERT_STRING_EQUAL(masterMachine->getCurrentState()->getName(), "StateOn");
 	ASSERT_STRING_EQUAL(slaveMachine->getCurrentState()->getName(), "StatePlayBackStopped");
	masterMachine->onMessage(Message::POWER_ON);
 	ASSERT_STRING_EQUAL(masterMachine->getCurrentState()->getName(), "StateOn");
 	ASSERT_STRING_EQUAL(slaveMachine->getCurrentState()->getName(), "StatePlayBackStopped");
	masterMachine->onMessage(Message::POWER_OFF);
 	ASSERT_STRING_EQUAL(masterMachine->getCurrentState()->getName(), "StateOff");
 	ASSERT_STRING_EQUAL(slaveMachine->getCurrentState()->getName(), "StatePlayBackStopped");

 	slaveMachine->onMessage(Message::POWER_ON);
 	ASSERT_STRING_EQUAL(masterMachine->getCurrentState()->getName(), "StateOn");
 	ASSERT_STRING_EQUAL(slaveMachine->getCurrentState()->getName(), "StatePlayBackStopped");
 	slaveMachine->onMessage(Message::POWER_OFF);
 	ASSERT_STRING_EQUAL(masterMachine->getCurrentState()->getName(), "StateOff");
 	ASSERT_STRING_EQUAL(slaveMachine->getCurrentState()->getName(), "StatePlayBackStopped");
 	slaveMachine->onMessage(Message::POWER_ON);
 	ASSERT_STRING_EQUAL(masterMachine->getCurrentState()->getName(), "StateOn");
 	ASSERT_STRING_EQUAL(slaveMachine->getCurrentState()->getName(), "StatePlayBackStopped");

 	slaveMachine->onMessage(Message::START_PLAYBACK);
 	ASSERT_STRING_EQUAL(masterMachine->getCurrentState()->getName(), "StateOn");
 	ASSERT_STRING_EQUAL(slaveMachine->getCurrentState()->getName(), "StatePlaying");
 	slaveMachine->onMessage(Message::START_PLAYBACK);
 	ASSERT_STRING_EQUAL(masterMachine->getCurrentState()->getName(), "StateOn");
 	ASSERT_STRING_EQUAL(slaveMachine->getCurrentState()->getName(), "StatePlaying");
 	slaveMachine->onMessage(Message::STOP_PLAYBACK);
 	ASSERT_STRING_EQUAL(masterMachine->getCurrentState()->getName(), "StateOn");
 	ASSERT_STRING_EQUAL(slaveMachine->getCurrentState()->getName(), "StatePlayBackStopped");
 	slaveMachine->onMessage(Message::START_PLAYBACK);
 	ASSERT_STRING_EQUAL(masterMachine->getCurrentState()->getName(), "StateOn");
 	ASSERT_STRING_EQUAL(slaveMachine->getCurrentState()->getName(), "StatePlaying");
 	slaveMachine->onMessage(Message::POWER_OFF);
 	ASSERT_STRING_EQUAL(masterMachine->getCurrentState()->getName(), "StateOff");
 	ASSERT_STRING_EQUAL(slaveMachine->getCurrentState()->getName(), "StatePlaying");
 	slaveMachine->onMessage(Message::POWER_ON);
 	ASSERT_STRING_EQUAL(masterMachine->getCurrentState()->getName(), "StateOn");
 	ASSERT_STRING_EQUAL(slaveMachine->getCurrentState()->getName(), "StatePlayBackStopped");
 	slaveMachine->onMessage(Message::START_PLAYBACK);
 	ASSERT_STRING_EQUAL(masterMachine->getCurrentState()->getName(), "StateOn");
 	ASSERT_STRING_EQUAL(slaveMachine->getCurrentState()->getName(), "StatePlaying");
 	slaveMachine->onMessage(Message::START_PLAYBACK);
 	ASSERT_STRING_EQUAL(masterMachine->getCurrentState()->getName(), "StateOn");
 	ASSERT_STRING_EQUAL(slaveMachine->getCurrentState()->getName(), "StatePlaying");
 	slaveMachine->onMessage(Message::STOP_PLAYBACK);
 	ASSERT_STRING_EQUAL(masterMachine->getCurrentState()->getName(), "StateOn");
 	ASSERT_STRING_EQUAL(slaveMachine->getCurrentState()->getName(), "StatePlayBackStopped");
 	slaveMachine->onMessage(Message::POWER_OFF);
 	ASSERT_STRING_EQUAL(masterMachine->getCurrentState()->getName(), "StateOff");
 	ASSERT_STRING_EQUAL(slaveMachine->getCurrentState()->getName(), "StatePlayBackStopped");

	SUCCESS;
}

bool test_4(){


	SUCCESS;
}

int main() {
	registerNewTest(test_adding_values_to_transition_table);
	registerNewTest(test_simple_state_machine);
	registerNewTest(test_hierarchical_state_machine);
	registerNewTest(test_4);

	if(runAllTests())
		return 0;
	else return -1;
}

