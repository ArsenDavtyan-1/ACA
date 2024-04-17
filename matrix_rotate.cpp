#include <iostream>                                   // rotating square matrix without using additional space and with malloc

void fill_matrix(int* matrix, int size);
void print_matrix(int* matrix, int size);
void* operator new(size_t size);
void rotate_matrix(int* matrix, int size);

int main()
{
	int* matrix;
	int size;
	std::cout << "size = ";
	std::cin >> size;

	matrix = new int[size];
	std::cout << std::endl;
	fill_matrix(matrix, size);
	print_matrix(matrix, size);
	rotate_matrix(matrix, size);
	std::cout << std::endl;

	print_matrix(matrix, size);



	std::cout << std::endl;
	delete[] matrix;
}


void* operator new(size_t size)
{
	std::cout << "called overloaded operator new" << std::endl;
	void* ptr = malloc(size * size);
	if (ptr == NULL)
	{
		std::cout << "memory overflow" << std::endl;
	}
	return ptr;
}

void operator delete[](void* ptr)
{
	std::cout << "called overloaded operator delete" << std::endl;
	free(ptr);
}


void fill_matrix(int* matrix, int size)
{
	for (int i = 0; i < size * size; i++)
	{
		matrix[i] = rand() % 100;
	}
}

void print_matrix(int* matrix, int size)
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
		{
			std::cout << matrix[i * size + j] << " ";
		}
		std::cout << std::endl;
	}
}


void rotate_matrix(int* matrix, int size)
{
	int k = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = k; j < size; j++)
		{
			int temp = matrix[i * size + j];
			matrix[i * size + j] = matrix[j * size + i];
			matrix[j * size + i] = temp;
		}
		k++;
	}
}