//============================================================================
// Name        : StateMachineTest.cpp
// Author      : Pawe³ Sak
// Version     :
//============================================================================

#include <iostream>
#include "..\include\StateMachine.hpp"
using namespace std;

int main() {
	StateMachine *machine = new StateMachine();

	for(int i = 0; i<50; i++)
	machine->printSomething(i*2);

	return 0;
}
