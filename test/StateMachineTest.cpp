//============================================================================
// Name        : StateMachineTest.cpp
// Author      : Pawe� Sak
// Version     :
//============================================================================

#include <iostream>
#include "..\include\StateMachine.hpp"
using namespace std;

#define BOOST_TEST_MODULE MyTest
#include <boost/test/included/unit_test.hpp\> //single-header
#include <string>

BOOST_AUTO_TEST_CASE(my_boost_test)
{
    std::string expected_value = "Bill";

    // assume MyClass is defined in MyClass.h
    // and get_value() has public accessibility
    MyClass mc;
    BOOST_CHECK(expected_value == mc.get_value());
}
