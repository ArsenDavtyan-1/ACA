#include <iostream>
#include "Algorithms.h"
#include "Quicksort.h"



int main()
{
	int a[15] = { 17,12,15,-7,5,-99,3,-77,1110,-3,711,45,-7,6,2 };
	//BubbleSort(a, 15);
	MergeSort(a, 0, 14);


	for (int i = 0; i < 15; ++i)
	{
		std::cout << a[i] << ' ';
	}
	std::cout << std::endl;



	int array[25];
	for (int& elem : array)
		elem = rand() % 200;

	int brray[25];
	for (int& elem : brray)
		elem = rand() % 100;

	MergeSort(array, 0, 24);
	for (int& elem : array)
		std::cout << elem << ' ';

	std::cout << std::endl;
	std::cout << std::endl;

	Quicksort(brray,0, 24);
	for (int& elem : brray)
		std::cout << elem << ' ';

	int crray[25];
	for (int i = 0;i < 25; ++i)
	{
		if(i % 3 == 0) 
			crray[i] = (rand() % 1000) * (-1);
		else
			crray[i] = rand() % 1000;

	}
	std::cout << std::endl;
	std::cout << std::endl;

	Quicksort(crray, 0, 24);
	for (int& elem : crray)
		std::cout << elem << ' ';
}