// CompileTimePolymorphisms.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>

template <class T>
T max(T a, T b) {
	return a > b ? a : b;
}

int main()
{
	std::cout << ::max(9, 5) << std::endl;     // 9

	std::string foo("foo"), bar("bar");
	std::cout << ::max(foo, bar) << std::endl; // "foo"

	getchar();
    return 0;
}

