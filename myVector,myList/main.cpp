#include <iostream>
#include "myList.h"
#include "myvector.h"
#include <initializer_list>

int main()
{
	//my::vector<int> A;
	//std::cout << A.is_empty() << std::endl;
	//for (int i = 0; i < 18; ++i)
	//{
	//	A.push_back(rand() % 100);
	//}
	//A.print();
	//A.insert(-77, 6);
	//A.print();
	//std::cout << std::endl << std::endl;

	//A.print();
	//std::cout << std::endl << std::endl;
	//A.insert(99, 3);
	//A.print();
	//std::cout << std::endl << std::endl;
	//A.insert(0, 0);
	//A.insert(1, 1);
	//A.insert(-9, 6);
	//A.print();
	//A.insert(11, 24);
	//A.insert(-97, 23);
	//A.print();


	//my::vector<int> C = { 4,0,5,-9,2,-99,45,12,84,54,12,5,4,7,-55,9,-9,1,54,0,3,55,8 };


	my::List<int> L;
	L.push_front(66);
	L.push_front(-7);
	L.push_front(0);
	L.push_front(51);
	L.print();
	L.pop_front();
	L.insert(11, 3);
	L.insert(1, 5);
	L.insert(-7, 4);
	L.print();
}