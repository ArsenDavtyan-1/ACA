#include <iostream>
#include <thread>
#include <mutex>


std::mutex counter_mutex;

void fill(int** matrix, int rows_size, int column_size)
{
	for (int i = 0; i < rows_size; ++i)
		for (int j = 0; j < column_size; ++j)
			matrix[i][j] = rand() % 100;
	return;
}

void print(int** matrix, int rows_size, int column_size)
{
	for (int i = 0; i < rows_size; ++i)
	{
		for (int j = 0; j < column_size; ++j)
			std::cout << matrix[i][j] << "  ";
		std::cout << std::endl;
	}
	return;
}



void matrixLineSum(int** matrix, int line, int column_size, int& sum)
{
	for (int i = 0; i < column_size; ++i)
	{
		std::lock_guard<std::mutex> guard(counter_mutex);
		sum += matrix[line][i];
	}
}



int main()
{
	std::srand(time(nullptr));
	int sum = 0;
	int size1 = 4, size2 = 5;

	
	int** matrix = new int* [size1];
	for (int i = 0; i < size1; ++i)
		matrix[i] = new int[size2];

	fill(matrix, size1, size2);
	print(matrix, size1, size2);

	std::thread t1(matrixLineSum, matrix, 0, 5, std::ref(sum));
	std::thread t2(matrixLineSum, matrix, 1, 5, std::ref(sum));
	std::thread t3(matrixLineSum, matrix, 2, 5, std::ref(sum));
	std::thread t4(matrixLineSum, matrix, 3, 5, std::ref(sum));

	

	t1.join();
	t2.join();
	t3.join();
	t4.join();

	std::cout << std::endl << "The sum of all elements of the matrix is equal to = ";
	std::cout << sum << std::endl;

	for (int i = 0; i < size1; ++i)
		delete[] matrix[i];
	delete[] matrix;
}