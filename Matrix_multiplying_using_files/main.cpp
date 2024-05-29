#include <iostream>
#include "Matrix.h"
#include <ctime>


int main()
{
	srand(time(nullptr));
	Matrix<double> A(4, 5);
	A.fill();
	A.print();
	A.MatrixToFile("example1");
	Matrix<double> B(5, 7);
	B.fill();
	std::cout << std::endl;
	B.print();
	B.MatrixToFile("example2");
	std::cout << std::endl;
	Matrix<double> C = A + B;
	C.print();
	MatrixMultiplyFile<int>("example1", "example2", "result");
}