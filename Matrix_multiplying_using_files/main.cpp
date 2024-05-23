#include <iostream>
#include "Matrix.h"
#include <ctime>

int main()
{
	srand(time(nullptr));
	Matrix A(4, 5);
	A.fill();
	A.print();
	A.MatrixToFile("example1");
	Matrix B(5, 7);
	B.fill();
	std::cout << std::endl;
	B.print();
	B.MatrixToFile("example2");
	std::cout << std::endl;
	Matrix C = A + B;
	C.print();
	MatrixMultiplyFile("example1", "example2", "result");
}