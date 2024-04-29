#include <iostream>
#include "animal.h"
#include "cat.h"
#include "dog.h"
#include "horse.h"
#include "bunny.h"
#include "cow.h"

int main()
{
	Cat A(4, 100, "Cato", "black");
	Dog B;
	Horse C(150, 5000, "Hor", "grey");
	Cow D(200, 2000, "Cow", "white");
	Bunny E(2, 50, "Bax", "grey");

	Animal* ptr[5];
	ptr[0] = &A;
	ptr[1] = &B;
	ptr[2] = &C;
	ptr[3] = &D;
	ptr[4] = &E;

	for (int i = 0; i < 5; i++)
	{
		ptr[i]->voice();
		ptr[i]->print();
		std::cout << std::endl;
	}


}