#ifndef CAT_H_
#define CAT_H_
#include "animal.h"

class Cat : public Animal {
public:
	Cat()
	{}
	Cat(int weight, int price, std::string name, std::string color) : Animal(weight, price, name, color)
	{}
	void voice() override;
};



#endif