/*
 * IStateMachine.hpp
 *
 *  Created on: 7 lut 2019
 *      Author: Paul
 */

#ifndef ISTATE_HPP_
#define ISTATE_HPP_

#include <string>
#include "..\include\Message.hpp"

using namespace std;

class IState{
public:
	IState(string name);
	virtual ~IState();
	virtual void onMessage(Message message)=0;
	string getName();
	virtual void run()=0;

protected:
	string name;
};

#endif /* ISTATE_HPP_ */
