#include <iostream>

class Matrix
{
private:
	int** mat;
	int row;
	int column;
public:
	Matrix(int row_lenght, int column_lenght);
	~Matrix();
	void fill();
	void print();
	void rotate();
};

int main()
{
	int row, column;
	std::cout << "rows = ";
	std::cin >> row;
	std::cout << "columns = ";
	std::cin >> column;
	Matrix A(row, column);
	A.fill();
	A.print();
	std::cout << std::endl << std::endl;
	A.rotate();
	A.print();
}

Matrix::Matrix(int row_lenght, int column_lenght)
{
	row = row_lenght;
	column = column_lenght;
	mat = new int* [row];
	for (int i = 0; i < row; i++)
	{
		mat[i] = new int[column];
	}
}

void Matrix::fill()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			mat[i][j] = rand() % 100;
		}
	}
}

void Matrix::print()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			std::cout << mat[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void Matrix::rotate()
{
	int** mat_2;
	mat_2 = new int* [column];
	for (int i = 0; i < column; i++)
	{
		mat_2[i] = new int[row];
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			mat_2[j][i] = mat[i][j];
		}
	}
	for (int i = 0; i < row; i++)
	{
		delete[] mat[i];
	}
	delete[] mat;
	mat = mat_2;
	int temp = row;
	row = column;
	column = temp;
}

Matrix::~Matrix()
{
	for (int i = 0; i < row; i++)
	{
		delete[] mat[i];
	}
	delete[] mat;
}
