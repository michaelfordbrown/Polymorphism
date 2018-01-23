// AdHocPolymorphism.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

int add(int a, int b) {
	return a + b;
}

std::string add(const char *a, const char *b) {
	std::string result(a);
	result += b;
	return result;
}

int main()
{
	std::cout << add(5, 9) << std::endl;
	std::cout << add("hello ", "world") << std::endl;

	getchar();
    return 0;
}

