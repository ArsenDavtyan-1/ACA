#ifndef BUNNY_H_
#define BUNNY_H_
#include "animal.h"

class Bunny : public Animal{
public:
	Bunny()
	{}
	Bunny(int weight, int price, std::string name, std::string color) : Animal(weight, price, name, color)
	{}
	void voice() override;
};



#endif
