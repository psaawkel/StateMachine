/*
 * StateMachine.cpp
 *
 *  Created on: 7 lut 2019
 *      Author: Paul
 */

#include "..\include\IStateMachine.hpp"
#include "..\include\StateMachine.hpp"
#include <iostream>
using namespace std;

StateMachine::StateMachine(){
	cout << "StateMachine created" << endl;
}

StateMachine::StateMachine(IStateMachine *parent){
	this->parent = parent;
}

StateMachine::~StateMachine(){

}

void StateMachine::onMessage(int number){

	switch(number){
	case 0:
		cout << "message 0" << endl;
		break;

	case 1:
		cout << "message 0" << endl;
		break;

	default:
		cout << "default" << endl;
		if(parent!=nullptr) {
			cout << "throwing to parent" << endl;
			parent->onMessage(number);
		}
		break;
	}
}
