#ifndef MATRIX_H_
#define MATRIX_H_
#include <exception>


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
	int& at(int x, int y);
};



class badAccess : public std::exception
{
	const char* msg = nullptr;
public:
	badAccess(const char*);
	const char* what() const override;
};






#endif // !MATRIX_H_
