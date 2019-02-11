/*
 * IStateMachine.hpp
 *
 *  Created on: 7 lut 2019
 *      Author: Paul
 */

#ifndef ISTATEMACHINE_HPP_
#define ISTATEMACHINE_HPP_

#include <vector>
#include "..\include\IState.hpp"
#include "..\include\Message.hpp"
#include "..\include\TransitionEntry.hpp"

using namespace std;

class IStateMachine{
public:
	virtual ~IStateMachine();
	virtual void onMessage(Message message)=0;
	virtual bool addTransitionTableEntry(IState *current, Message, IState *next)=0;
	virtual IState* getCurrentState() = 0;

protected:
	IStateMachine *parent = nullptr;
	IState *currentState = nullptr;
	std::vector<TransitionEntry> transitionList;
};



#endif /* ISTATEMACHINE_HPP_ */
