#ifndef ANIMAL_H_
#define ANIMAL_H_
#include <iostream>
#include <string>

class Animal {
	int m_weight;
	std::string m_name;
	std::string m_color;
	int m_price;
public:
	Animal() : m_weight(15), m_name("Js"), m_color("white"), m_price(100)
	{}
	Animal(int, int, std::string, std::string);
	virtual ~Ainmal()
	{}
	virtual void voice();
	void print();
};



#endif
