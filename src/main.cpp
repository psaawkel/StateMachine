//============================================================================
// Name        : main.cpp
// Author      : Pawe³ Sak
// Version     :
//============================================================================

#include <iostream>
#include <vector>
#include "..\include\StateMachine.hpp"
using namespace std;

int main() {
	IStateMachine *machine = new StateMachine();
	IStateMachine *machine2 = new StateMachine(machine);



	for(int i = 0; i<5; i++){
	machine2->onMessage(5);
	}

	return 0;
}
