#include <iostream>



class Car {
public:


public:
	enum engine_type { electro, dizel, petrol };
	Car() : price(10000), max_speed(180), weight(2500), number_of_seats(4), engine(electro)
	{}
	Car(unsigned int car_price, unsigned int speed, unsigned int car_weight, unsigned int seats, engine_type mode)
		:price(car_price), max_speed(speed), weight(car_weight), number_of_seats(seats), engine(mode)
	{};
	unsigned int get_price() const;
	unsigned int get_max_speed() const;
	unsigned int get_weight() const;
	unsigned int get_number_of_seats() const;
	void print_engine_type() const;
	void set_price(unsigned int value);
	void set_weight(unsigned int weight);
	void set_max_speed(unsigned int speed);
	void set_number_of_seats(unsigned int seats);
	void print();
private:

	unsigned int price;     // in dollars
	unsigned int max_speed;				// in km/h
	unsigned int weight;				// in kg
	unsigned int number_of_seats;
	engine_type engine;
};

unsigned int Car::get_price() const
{
	return price;
}
unsigned int Car::get_max_speed() const
{
	return max_speed;
}
unsigned int Car::get_weight() const
{
	return weight;
}
unsigned int Car::get_number_of_seats() const
{
	return number_of_seats;
}
void Car::set_price(unsigned int value)
{
	price = value;
}
void Car::set_weight(unsigned int weight)
{
	this->weight = weight;
}
void Car::set_max_speed(unsigned int speed)
{
	max_speed = speed;
}
void Car::set_number_of_seats(unsigned int seats)
{
	number_of_seats = seats;
}

void Car::print_engine_type() const
{
	switch (engine) {
	case 0:
		std::cout << "Electro" << std::endl;
		break;
	case 1:
		std::cout << "Dizel" << std::endl;
		break;
	case 2:
		std::cout << "Petrol" << std::endl;
		break;
	}
}
void Car::print()
{
	std::cout << "Car's price - " << price << "$" << std::endl;
	std::cout << "Car's weight - " << weight << "kg" << std::endl;
	std::cout << "Car's max speed - " << max_speed << "km/h" << std::endl;
	std::cout << "Car's seats count - " << number_of_seats << std::endl;
	std::cout << "Car's engine type - ";
	print_engine_type();
}

int main()
{
	Car a;
	a.print();
	Car b(45000, 300, 1750, 2, Car::engine_type::petrol);
	b.print();
}
