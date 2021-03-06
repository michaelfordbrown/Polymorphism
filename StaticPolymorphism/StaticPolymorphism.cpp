// StaticPolymorphism.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <assert.h>

struct HelloCoutImpl {
	static void outputMessage() {
		std::cout << "Hello World\n";
	}
};

template <typename HelloInterface>
class HelloWorld {
public:
	void operator()() {
		HelloInterface::outputMessage();
	}
};

struct HelloTestImpl {
	static std::ostringstream os;
	static void outputMessage() {
		os << "Hello World\n";
	}
};

std::ostringstream HelloTestImpl::os;

void thisIsATest() {
	HelloWorld<HelloTestImpl> doit;
	doit();
	assert(HelloTestImpl::os.str().compare("Hello World\n") == 0);
}

int main()
{
	std::cout << "Static Polymorphism\n";
	HelloWorld<HelloCoutImpl> doit;
	doit();

	std::cout << "Testing Static Polymorphism\n";
	thisIsATest();

	getchar();
    return 0;
}

