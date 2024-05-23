#include "Matrix.h"


Matrix::Matrix(int row_lenght, int column_lenght)
{
	//std::cout << "Called constructor" << std::endl;
	row = row_lenght;
	column = column_lenght;
	mat = new int* [row];
	for (int i = 0; i < row; i++)
	{
		mat[i] = new int[column];
	}

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < column; ++j)
		{
			mat[i][j] = 0;
		}
	}
}

Matrix::Matrix(std::string txtFile)
{
	std::ifstream inputFile;
	
	std::string line;
	row = 0;
	column = 0;
	mat = nullptr;
	inputFile.open(txtFile + ".txt");
	if (!inputFile.is_open()) {
		std::cerr << "There are problem with opening file for creating Matrix" << std::endl;
		return;
	}
	while (std::getline(inputFile, line))
	{
		++row;
	}
	inputFile.close();
	inputFile.open(txtFile + ".txt");
	while (std::getline(inputFile, line, '\t') && line[0] != '\n')
	{
		++column;
	}
	//std::cout << "row = " << row << std::endl;
	//std::cout << "column = " << column << std::endl;
	inputFile.close();

	inputFile.open(txtFile + ".txt");
	if (!inputFile.is_open()) {
		std::cerr << "There are problem with opening file for creating Matrix" << std::endl;
		return;
	}
	
	mat = new int* [row];
	for (int i = 0; i < row; i++)
	{
		mat[i] = new int[column];
	}

	for(int i = 0; i < row; ++i)
	{
		for (int j = 0; j < column; j++)
		{
			(std::getline(inputFile, line, '\t'));
			if (line[0] != '\n') {
				mat[i][j] = intMaker(line);
				//std::cout << line << " - " << intMaker(line) << "|";
			}
			else {
				line.erase(0, 1);
				mat[i][j] = intMaker(line);
				//std::cout << line << " - " << intMaker(line) << "|";
			}
		}
	}

	inputFile.close();
}

Matrix::Matrix(const Matrix& obj)
{
	//std::cout << "Called copy constructor" << std::endl;

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

void Matrix::print() const
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
	//std::cout << "Called rotate member function" << std::endl;
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
	//std::cout << "Called assignment operator" << std::endl;
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

Matrix::Matrix(Matrix&& obj) noexcept
{
	//std::cout << "Move constructor called" << std::endl;
	mat = obj.mat;
	row = obj.row;
	column = obj.column;
	obj.row = 0;
	obj.column = 0;
	obj.mat = nullptr;
}

Matrix& Matrix::operator=(Matrix&& obj) noexcept
{
	//std::cout << "move operator= called" << std::endl;
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
	//std::cout << "Called destructor" << std::endl;
	for (int i = 0; i < row; i++)
	{
		delete[] mat[i];
	}
	delete[] mat;
}

void Matrix::MatrixToFile(std::string fileName) const
{
	std::ofstream outputFile(fileName + ".txt");

	if (!outputFile.is_open()) {
		std::cout << "There are problem with opening file for output Matrix" << std::endl;
		return;
	}

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < column; ++j)
		{
			outputFile << mat[i][j] << '\t';
		}
		outputFile << '\n';
	}
	return;
}

Matrix Matrix::operator*(const Matrix& obj) const
{
	if (column != obj.row)
	{
		std::cout << "The sizes are incompatible,we can not multiply them" << std::endl;
		return Matrix(0, 0);
	}
	Matrix new_obj(row, obj.column);
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < obj.column; ++j)
		{
			for (int l = 0; l < column; ++l)
			{
				new_obj.mat[i][j] += mat[i][l] * obj.mat[l][j];
			}
		}
	}
	return new_obj;
}

int intMaker(std::string str)
{
	int a = 0;
	int b;
	for (int i = 0; i < str.size(); i++)
	{
		b = str[i] - '0';
		a = a * 10 + b;
	}

	return a;
}



void MatrixMultiplyFile(std::string fileName1, std::string fileName2, std::string destinationFile)
{
	Matrix A(fileName1);
	Matrix B(fileName2);
	Matrix C = A * B;
	C.MatrixToFile(destinationFile);
}