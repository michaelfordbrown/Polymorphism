// CoercionPolymorphism.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

class A {
	int foo;
public:
	A(int ffoo) : foo(ffoo) {}
	void giggidy() { std::cout << foo << std::endl; }
};

void moo(A a) {
	a.giggidy();
}

class CrazyInt {
	int v;
public:
	CrazyInt(int i) : v(i) {}
	operator int() const { return v; } // conversion from CrazyInt to int
};

void print_int(int a) {
	std::cout << a << std::endl;
}

int main()
{
	std::cout << "Conversion of type via non explicit class constructor\n";
	moo(55);     // prints 55

	std::cout << "\nConversion operator can be used whereever type is expected\n";
	CrazyInt b = 55;
	print_int(999);    // prints 999
	print_int(b);      // prints 55

	getchar();

    return 0;
}

