#ifndef STATEMACHINE_HPP_
#define STATEMACHINE_HPP_

#include "..\include\IStateMachine.hpp"

class StateMachine : public IStateMachine
{
public:
	StateMachine();
	StateMachine(IStateMachine *parent);
	~StateMachine();
	void onMessage(int number);
};

#endif
