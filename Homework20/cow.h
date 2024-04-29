#ifndef COW_H_
#define COW_H_
#include "animal.h"

class Cow : public Animal {
public:
	Cow()
	{}
	Cow(int weight, int price, std::string name, std::string color) : Animal(weight, price, name, color)
	{}
	void voice() override;
};



#endif