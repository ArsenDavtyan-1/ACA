#include "Matrix.h"

template class Matrix<int>;
template class Matrix<double>;
template void MatrixMultiplyFile<int>(std::string, std::string, std::string);
template void MatrixMultiplyFile<double>(std::string, std::string, std::string);


template <typename T>
Matrix<T>::Matrix(int row_lenght, int column_lenght)
{
	//std::cout << "Called constructor" << std::endl;
	row = row_lenght;
	column = column_lenght;
	mat = new T* [row];
	for (int i = 0; i < row; i++)
	{
		mat[i] = new T[column];
	}

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < column; ++j)
		{
			mat[i][j] = 0;
		}
	}
}

template <typename T>
Matrix<T>::Matrix(std::string txtFile)
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
	
	mat = new T* [row];
	for (int i = 0; i < row; i++)
	{
		mat[i] = new T[column];
	}

	for(int i = 0; i < row; ++i)
	{
		for (int j = 0; j < column; j++)
		{
			(std::getline(inputFile, line, '\t'));
			if (line[0] != '\n') {
				mat[i][j] = doubleMaker(line);
				//std::cout << line << " - " << intMaker(line) << "|";
			}
			else {
				line.erase(0, 1);
				mat[i][j] = doubleMaker(line);
				//std::cout << line << " - " << intMaker(line) << "|";
			}
		}
	}

	inputFile.close();
}

template <typename T>
Matrix<T>::Matrix(const Matrix<T>& obj)
{
	//std::cout << "Called copy constructor" << std::endl;

	row = obj.row;
	column = obj.column;

	mat = new T* [row];
	for (int i = 0; i < row; i++)
		mat[i] = new T[column];

	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			mat[i][j] = obj.mat[i][j];
}

template <typename T>
void Matrix<T>::fill()
{
	//std::cout << "Called fill member function" << std::endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			mat[i][j] = (rand() % 1000) / T(56);
		}
	}
}

template <typename T>
void Matrix<T>::print() const
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

template <typename T>
void Matrix<T>::rotate()
{
	//std::cout << "Called rotate member function" << std::endl;
	T** mat_2;
	mat_2 = new T* [column];
	for (int i = 0; i < column; i++)
	{
		mat_2[i] = new T[row];
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


template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& obj)
{
	//std::cout << "Called assignment operator" << std::endl;
	if (this != &obj) {
		for (int i = 0; i < row; i++)
			delete[] mat[i];
		delete[] mat;

		row = obj.row;
		column = obj.column;

		mat = new T* [row];
		for (int i = 0; i < row; i++)
			mat[i] = new T[column];

		for (int i = 0; i < row; i++)
			for (int j = 0; j < column; j++)
				mat[i][j] = obj.mat[i][j];
	}
	return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& obj)
{
	if (row != obj.row || column != obj.column)
	{
		std::cout << "The sizes are incompatible,we can not add them" << std::endl;
		return Matrix<T>(0, 0);
	}
	Matrix<T> new_obj(row, column);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			new_obj.mat[i][j] = mat[i][j] + obj.mat[i][j];
		}
	}
	return new_obj;
}

template <typename T>
Matrix<T>::Matrix(Matrix<T>&& obj) noexcept
{
	//std::cout << "Move constructor called" << std::endl;
	mat = obj.mat;
	row = obj.row;
	column = obj.column;
	obj.row = 0;
	obj.column = 0;
	obj.mat = nullptr;
}

template <typename T>
Matrix<T>& Matrix<T>::operator=(Matrix<T>&& obj) noexcept
{
	//std::cout << "move operator= called" << std::endl;
	if (this == &obj)
		return *this;
	for (int i = 0; i < row; i++)
		delete[] mat[i];
	delete[] mat;
	row = obj.row;
	column = obj.column;
	mat = new T*[row];
	for (int i = 0; i < row; i++)
		mat[i] = new T[column];
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			mat[i][j] = obj.mat[i][j];
	return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::operator++()
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			mat[i][j] += 3;
	return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator++(int)
{
	Matrix<T> temp(*this);
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			this->mat[i][j] += 3;
	return temp;
}

template <typename T>
Matrix<T>::~Matrix<T>()
{
	//std::cout << "Called destructor" << std::endl;
	for (int i = 0; i < row; i++)
	{
		delete[] mat[i];
	}
	delete[] mat;
}

template <typename T>
void Matrix<T>::MatrixToFile(std::string fileName) const
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

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& obj) const
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

/*int intMaker(std::string str)
{
	int a = 0;
	int b;
	for (int i = 0; i < str.size(); i++)
	{
		b = str[i] - '0';
		a = a * 10 + b;
	}

	return a;
}*/

double doubleMaker(std::string str)
{
	double a = 0;
	double b;
	double afterComma = 0;
	double x = 1;
	int i = 0;
	while (str[i] != '.' && i < str.size())
	{
		b = str[i] - '0';
		a = a * 10 + b;

		++i;
	}
	++i;
	for (; i < str.size(); ++i)
	{
		b = str[i] - '0';
		afterComma = afterComma * 10 + b;
		x *= 10;
	}

	a = a + (afterComma / x);
	return a;
}


template<typename T>
void MatrixMultiplyFile(std::string fileName1, std::string fileName2, std::string destinationFile)
{
	Matrix<T> A(fileName1);
	Matrix<T> B(fileName2);
	Matrix<T> C = A * B;
	C.MatrixToFile(destinationFile);
}