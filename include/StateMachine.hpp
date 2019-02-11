#ifndef STATEMACHINE_HPP_
#define STATEMACHINE_HPP_

#include "..\include\IStateMachine.hpp"
#include "..\include\IState.hpp"

class StateMachine : public IStateMachine, public IState
{
public:
	StateMachine(string name);
	StateMachine(IStateMachine *parent, string name);
	~StateMachine();
	void onMessage(Message message);
	bool addTransitionTableEntry(IState *current, Message, IState *next);
	IState* getCurrentState();
	void run();

};

#endif
