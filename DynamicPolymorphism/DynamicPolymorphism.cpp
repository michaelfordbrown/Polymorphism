// DynamicPolymorphism.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <assert.h>

struct HelloInterface {
	virtual void outputMessage() = 0;
	virtual ~HelloInterface() {}
};

struct HelloCoutImpl : HelloInterface {
	void outputMessage() {
		std::cout << "Hello World\n";
	}
};

class HelloWorld {
	HelloInterface &hello;
public:
	// Constructor that initializes hello referance
	HelloWorld(HelloInterface& hello) :hello(hello) {}

	// Overload function operator, no parameters or return type
	void operator()() {
		hello.outputMessage();
	}
};

struct HelloTestImpl:HelloInterface {
	std::ostringstream os;
	void outputMessage() {
		os << "Hello World\n";
	}
};

void thisIsATest()
{
	HelloTestImpl forTest;
	HelloWorld doit(forTest);
	doit();
	assert(forTest.os.str().compare("Hello World\n") == 0);
}

int main()
{
	std::cout << "Dynamic Polymorphism\n";
	HelloCoutImpl toCout;
	HelloWorld doit(toCout);
	doit();

	std::cout << "Testing Dynamic Polymorphism\n";
	thisIsATest();

	getchar();
    return 0;
}

