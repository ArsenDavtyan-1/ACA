#include <iostream>

class Matrix
{
private:
	int** mat;
	int row;
	int column;
public:
	Matrix(int row_lenght, int column_lenght); // constructor
	Matrix(const Matrix& obj);      // copy constructor
	~Matrix();  // destructor
	void fill();
	void print();
	void rotate();
	Matrix& operator=(const Matrix& obj); // assignment operator
	Matrix operator+(const Matrix& obj); // addition operator
	Matrix(Matrix&& obj); // move constructor
	Matrix& operator=(Matrix&& obj); //move assignment operator
	Matrix& operator++();
	Matrix operator++(int);
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
	std::cout << "rows 2 = ";
	std::cin >> row;
	std::cout << "columns 2 = ";
	std::cin >> column;
	Matrix B(row, column);
	B.fill();
	B.print();
	std::cout << std::endl << std::endl;
	Matrix C(A + B);
	C.print();
	std::cout << std::endl << std::endl;
	C++;
	C.print();
}

Matrix::Matrix(int row_lenght, int column_lenght)
{
	std::cout << "Called constructor" << std::endl;
	row = row_lenght;
	column = column_lenght;
	mat = new int* [row];
	for (int i = 0; i < row; i++)
	{
		mat[i] = new int[column];
	}
}

Matrix::Matrix(const Matrix& obj)
{
	std::cout << "Called copy constructor" << std::endl;

	row = obj.row;
	column = obj.column;

	mat = new int* [row];
	for (int i = 0; i < row; i++)
		mat[i] = new int[column];

	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			mat[i][j] = obj.mat[i][j];
}

void Matrix::fill()
{
	//std::cout << "Called fill member function" << std::endl;
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
	//std::cout << "Called print member function" << std::endl;
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
	std::cout << "Called rotate member function" << std::endl;
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

Matrix& Matrix::operator=(const Matrix& obj)
{
	std::cout << "Called assignment operator" << std::endl;
	if (this != &obj) {
		for (int i = 0; i < row; i++)
			delete[] mat[i];
		delete[] mat;

		row = obj.row;
		column = obj.column;

		mat = new int* [row];
		for (int i = 0; i < row; i++)
			mat[i] = new int[column];

		for (int i = 0; i < row; i++)
			for (int j = 0; j < column; j++)
				mat[i][j] = obj.mat[i][j];
	}
	return *this;
}

Matrix Matrix::operator+(const Matrix& obj)
{
	if (row != obj.row || column != obj.column)
	{
		std::cout << "The sizes are incompatible,we can not add them" << std::endl;
		return Matrix(0, 0);
	}
	Matrix new_obj(row, column);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			new_obj.mat[i][j] = mat[i][j] + obj.mat[i][j];
		}
	}
	return new_obj;
}

Matrix::Matrix(Matrix&& obj)
{
	std::cout << "Move constructor called" << std::endl;
	mat = obj.mat;
	row = obj.row;
	column = obj.column;
	obj.row = 0;
	obj.column = 0;
	obj.mat = nullptr;
}

Matrix& Matrix::operator=(Matrix&& obj)
{
	std::cout << "move operator= called" << std::endl;
	if (this == &obj)
		return *this;
	for (int i = 0; i < row; i++)
		delete[] mat[i];
	delete[] mat;
	row = obj.row;
	column = obj.column;
	mat = new int*[row];
	for (int i = 0; i < row; i++)
		mat[i] = new int[column];
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			mat[i][j] = obj.mat[i][j];
	return *this;
}

Matrix& Matrix::operator++()
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			mat[i][j] += 3;
	return *this;
}

Matrix Matrix::operator++(int)
{
	Matrix temp(*this);
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			this->mat[i][j] += 3;
	return temp;
}

Matrix::~Matrix()
{
	std::cout << "Called destructor" << std::endl;
	for (int i = 0; i < row; i++)
	{
		delete[] mat[i];
	}
	delete[] mat;
}