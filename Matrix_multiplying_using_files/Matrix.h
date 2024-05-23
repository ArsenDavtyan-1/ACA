#ifndef MATRIX_H_
#define MATRIX_H_

#include <iostream>
#include <fstream>
#include <string>

int intMaker(std::string str);
void MatrixMultiplyFile(std::string txtFile1, std::string txtFile2, std::string destinationFile);

class Matrix
{
private:
	int** mat;
	int row;
	int column;
public:
	Matrix(int row_lenght, int column_lenght); // constructor
	Matrix(const Matrix& obj);      // copy constructor
	Matrix(std::string);            // constructed from file
	~Matrix();  // destructor
	void fill();
	void print() const;
	void rotate();
	Matrix& operator=(const Matrix& obj); // assignment operator
	Matrix operator+(const Matrix& obj); // addition operator
	Matrix(Matrix&& obj) noexcept; // move constructor
	Matrix& operator=(Matrix&& obj) noexcept; //move assignment operator
	Matrix& operator++();
	Matrix operator++(int);
	void MatrixToFile(std::string) const;
	Matrix operator*(const Matrix&) const;
};




#endif // !MATRIX_H_

