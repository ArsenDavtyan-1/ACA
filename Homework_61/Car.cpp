#include "Car.h"
#include <functional>


std::ostream& operator<<(std::ostream& out, Car& obj)
{
	out << "The car's name is - " << obj.m_name << std::endl;
	out << "The speed is - " << obj.m_speed << " km/h" << std::endl;
	out << "The horse power is - " << obj.m_hp << " hp" << std::endl;
	return out;
}

 
bool Car::operator==(const Car& obj) const
{
	return m_name == obj.m_name && m_hp == obj.m_hp && m_speed == obj.m_speed;
}


