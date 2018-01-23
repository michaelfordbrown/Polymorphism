// RuntimePolymorphism.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include "cats.h"

void do_meowing(Felid *cat) {
	cat->meow();
}


int main()
{
	Cat cat;
	Tiger tiger;
	Ocelot ocelot;

	do_meowing(&cat);
	do_meowing(&tiger);
	do_meowing(&ocelot);

	getchar();
    return 0;
}

