#include <iostream>


template <unsigned char h>
struct Fibonacci
{
	static const unsigned long long val = Fibonacci<h - 1>::val + Fibonacci<h - 2>::val;
};

template<> struct Fibonacci<0>
{
	static const unsigned long long val = 1;
};

template<> struct Fibonacci<1>
{
	static const unsigned long long val = 1;
};


int main()
{
	std::cout << Fibonacci<24>::val << std::endl;
}