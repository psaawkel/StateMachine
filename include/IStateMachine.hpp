/*
 * IStateMachine.hpp
 *
 *  Created on: 7 lut 2019
 *      Author: Paul
 */

#ifndef ISTATEMACHINE_HPP_
#define ISTATEMACHINE_HPP_

#include<vector>
using namespace std;

class IStateMachine{
public:
	virtual ~IStateMachine();
	virtual void onMessage(int number)=0;

protected:
	IStateMachine *parent=nullptr;
	//std::vector<int> *list = new std::vector<int>;

};



#endif /* ISTATEMACHINE_HPP_ */
