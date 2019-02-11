/*
 * IState.cpp
 *
 *  Created on: 11 lut 2019
 *      Author: Paul
 */

#include "..\include\IState.hpp"

IState::IState(string name){
	this->name = name;
}

IState::~IState(){


}

string IState::getName(){
	return name;
}
