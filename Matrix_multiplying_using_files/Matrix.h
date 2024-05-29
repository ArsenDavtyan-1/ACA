#ifndef MATRIX_H_
#define MATRIX_H_

#include <iostream>
#include <fstream>
#include <string>

int intMaker(std::string);
double doubleMaker(std::string str);
template <typename T>
void MatrixMultiplyFile(std::string txtFile1, std::string txtFile2, std::string destinationFile);

template <typename T>
class Matrix
{
private:
	T** mat;
	int row;
	int column;
public:
	Matrix<T>(int row_lenght, int column_lenght); // constructor
	Matrix<T>(const Matrix<T>& obj);      // copy constructor
	Matrix<T>(std::string);            // constructed from file
	~Matrix<T>();  // destructor
	void fill();
	void print() const;
	void rotate();
	Matrix<T>& operator=(const Matrix<T>& obj); // assignment operator
	Matrix<T> operator+(const Matrix<T>& obj); // addition operator
	Matrix<T>(Matrix<T>&& obj) noexcept; // move constructor
	Matrix<T>& operator=(Matrix<T>&& obj) noexcept; //move assignment operator
	Matrix<T>& operator++();
	Matrix<T> operator++(int);
	void MatrixToFile(std::string) const;
	Matrix<T> operator*(const Matrix<T>&) const;
};




#endif // !MATRIX_H_

