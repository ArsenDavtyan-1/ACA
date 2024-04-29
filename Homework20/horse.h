#ifndef HORSE_H_
#define HORSE_H_
#include "animal.h"

class Horse : public Animal {
public:
	Horse()
	{}
	Horse(int weight, int price, std::string name, std::string color) : Animal(weight, price, name, color)
	{}
	void voice() override;
};



#endif
