/*
 * State.hpp
 *
 *  Created on: 7 lut 2019
 *      Author: Paul
 */

#ifndef STATE_HPP_
#define STATE_HPP_

#include <string>
#include "..\include\IState.hpp"

using namespace std;

class State:public IState{
public:
	State(string name);
	~State();
	void onMessage(Message message);
	void run();

protected:
	string name;
};

#endif /* STATE_HPP_ */
