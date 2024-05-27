#include <iostream>
#include "myvector.h"

int main()
{
	my::vector<int> A;
	std::cout << A.is_empty() << std::endl;
	for (int i = 0; i < 16; ++i)
	{
		A.push_back(rand() % 100);
	}
	A.print();
	std::cout << A[7] << std::endl;
}