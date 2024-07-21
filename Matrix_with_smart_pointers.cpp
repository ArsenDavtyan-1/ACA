#include <iostream>
#include <memory>


int main()
{
	int n;
	std::cout << "n = ";
	std::cin >> n;
	std::shared_ptr<std::shared_ptr<int[]>[]> Matrix(new std::shared_ptr<int[]>[n]);
	

	for (int i = 0; i < n; ++i)
	{
		std::unique_ptr<int[]> ptr(new int[n]);
		Matrix[i] = std::move(ptr);
	}

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			Matrix[i][j] = rand() % 100;


	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			std::cout << Matrix[i][j] << "  ";
		}
		std::cout << std::endl;
	}
}
