#include <iostream>                                    // 66
#include <vector>
#include <algorithm>


int main()
{
	std::vector<int> vec = { 45,5,1,3,4,78,12,87,6,456,7,16,16,7,9,17,1354,78,45,1,119,32,54,31 };


	for (int i = 0; i < vec.size(); ++i)
		std::cout << vec[i] << "   ";
	std::cout << std::endl <<  "size of vec = " << vec.size() << std::endl;


	vec.erase(std::remove_if(vec.begin(), vec.end(), [=](int x)->bool { if (x == 1) return false;
		int n = 2; while (n * n <= x) { if ((x % n) == 0) return false; ++n; }return true; }) , vec.end());


	for (int i = 0; i < vec.size(); ++i)
		std::cout << vec[i] << "   ";
	std::cout << std::endl << "size of vec = " << vec.size() << std::endl;

}