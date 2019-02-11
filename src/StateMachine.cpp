/*
 * StateMachine.cpp
 *
 *  Created on: 7 lut 2019
 *      Author: Paul
 */

#include "..\include\StateMachine.hpp"
#include "..\include\TransitionEntry.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

StateMachine::StateMachine(string name):IState(name){
}

StateMachine::StateMachine(IStateMachine *parent, string name):IState(name){
	this->parent = parent;
}

StateMachine::~StateMachine(){
}

void StateMachine::onMessage(Message message){

	for(TransitionEntry entry : transitionList){
		if(entry.currentState==currentState&&entry.message==message){
			currentState=entry.nextState;
			cout << "changing " << entry.currentState->getName() << " ---> " << entry.nextState->getName()<< endl;
			currentState->run();
			return;
		}
	}

	cout<< "message not recognized" << endl;
	if(parent!=nullptr) {
		cout<<"throwing message to parent"<<endl;
		parent->onMessage(message);
	}

}

bool StateMachine::addTransitionTableEntry(IState *current, Message message, IState *next){
	TransitionEntry entry;

	for(TransitionEntry entry : transitionList){
		if(entry.currentState==current&&entry.message==message){
			cout<<"adding transition table entry failed - this event from this state is arleady on the list" << endl;
			return false;
		}
	}
	if(transitionList.size()==0) currentState = current;
	entry.currentState=current;
	entry.message=message;
	entry.nextState=next;
	transitionList.push_back(entry);
	return true;
}

IState* StateMachine::getCurrentState(){
	return currentState;
}

void StateMachine::run(){
	currentState=transitionList[0].currentState;
	currentState->run();
}
