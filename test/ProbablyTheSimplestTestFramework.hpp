/*
 * ProbablyTheSimplestTestFramework.hpp
 *
 *  Created on: 7 lut 2019
 *      Author: Paul
 */

#ifndef PROBABLYTHESIMPLESTTESTFRAMEWORK_HPP_
#define PROBABLYTHESIMPLESTTESTFRAMEWORK_HPP_

#define ASSERT_TRUE(booleanVal) if(!booleanVal) {cout<<"Testcase: "<< __FUNCTION__ << "(); failed in "<< __FILE__ << " on line: " <<__LINE__<< endl ;return false;}
#define ASSERT_FALSE(booleanVal) if(booleanVal) {cout<<"Testcase: "<< __FUNCTION__ << "(); failed in "<< __FILE__ << " on line: " <<__LINE__<< endl ;return false;}
#define ASSERT_STRING_EQUAL(str1,str2) ASSERT_TRUE(((string)str1).compare(str2)==0)

#define SUCCESS cout<<"Testcase: "<< __FUNCTION__ << "(); passed!" << endl ; return true;

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Test{
	bool (*function)();
};

vector<Test> tests;

void registerNewTest(bool (*foo)()){
	Test test;
	test.function = foo;
	tests.push_back(test);
}

bool runAllTests(){
	int passed = 0;

	for(Test test : tests)
		if(test.function())
			passed++;
	cout<<"Tests passed: "<<passed<<endl<<"Executed: "<<tests.size()<<endl;
	if(passed==(int)tests.size()){
		cout<<"All test passed!";
		return true;
	}else return false;

}

#endif /* PROBABLYTHESIMPLESTTESTFRAMEWORK_HPP_ */
