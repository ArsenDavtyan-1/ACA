#ifndef DOG_H_
#define DOG_H_
#include "animal.h"

class Dog : public Animal {
public:
	Dog()
	{}
	Dog(int weight, int price, std::string name, std::string color) : Animal(weight, price, name, color)
	{}
	void voice() override;
};



#endif
