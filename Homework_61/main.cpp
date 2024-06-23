#include <iostream>
#include <unordered_map>
#include "Car.h"



int main()
{
	std::unordered_map<int, Car> pt;
	
	Car A;
	Car B(240,190, "Mercedes");
	Car C(260, 220, "BMW");

	std::pair<int, Car> a(44, C);
	pt.insert(a);


	std::unordered_map<Car, double> car_map;
	car_map[A] = 44.3;
	car_map[C] = -99.1;
	
	std::cout << "car_map[A] = " << car_map[A] << std::endl;
	std::cout << "car_map[C] = " << car_map[C] << std::endl << std::endl << std::endl;

	std::unordered_map<Car, std::string> car_map_to_string;
	car_map_to_string[A] = "Asjdfh";
	car_map_to_string[B] = A.getName();
	car_map_to_string[C] = "salkhgj";

	std::cout << "car_map_to_string[A] = " << car_map_to_string[A] << std::endl;
	std::cout << "car_map_to_string[B] = " << car_map_to_string[B] << std::endl;
	std::cout << "car_map_to_string[C] = " << car_map_to_string[C] << std::endl;
}
