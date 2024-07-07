#include <iostream>
#include "Matrix.h"



int main()
{
	Matrix A(6, 4);
	A.fill();
	A.print();

	//std::cout << A.at(4, 5) << std::endl;
	std::cout << A.at(1, 0) << std::endl;
	//std::cout << A.at(44, 44) << std::endl;
	std::cout << A.at(1, 3) << std::endl;
	//std::cout << A.at(-1, 0) << std::endl;
	std::cout << A.at(7, 2) << std::endl;
}




