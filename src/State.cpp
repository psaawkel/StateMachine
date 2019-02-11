/*
 * State.cpp
 *
 *  Created on: 11 lut 2019
 *      Author: Paul
 */

#include "..\include\State.hpp"

#include <iostream>
#include <string>

using namespace std;

State::State(string name):IState(name){

}

State::~State(){

}

void State::onMessage(Message message){

}

void State::run(){
	cout << this->getName() << " ignited!" << endl;
}
