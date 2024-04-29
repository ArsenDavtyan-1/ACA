#include "animal.h"

Animal::Animal(int weight, int price, std::string name, std::string color)
	: m_weight(weight),m_price(price),m_name(name),m_color(color)
{}
void Animal::voice()
{
	std::cout << "The animal voice" << std::endl;
}

void Animal::print()
{
	std::cout << "the weight - " << m_weight << std::endl;
	std::cout << "the color - " << m_color << std::endl;
	std::cout << "the name - " << m_name << std::endl;
	std::cout << "the price - " << m_price << std::endl;
}
