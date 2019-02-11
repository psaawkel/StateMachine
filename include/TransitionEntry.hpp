/*
 * TransitionEntry.hpp
 *
 *  Created on: 7 lut 2019
 *      Author: Paul
 */

#ifndef TRANSITIONENTRY_HPP_
#define TRANSITIONENTRY_HPP_

#include "..\include\IState.hpp"
#include "..\include\Message.hpp"

struct TransitionEntry{
	IState *currentState;
	Message message;
	IState *nextState;
};

#endif /* TRANSITIONENTRY_HPP_ */
