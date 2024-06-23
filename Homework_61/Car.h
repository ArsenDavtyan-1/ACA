#ifndef CAR_H_
#define CAR_H_
#include <iostream>
#include <string>



class Car
{
public:
	Car() : m_speed(180), m_hp(90), m_name("Opel")
	{}
	Car(const int& speed, const int& hp, const std::string& name)
		: m_speed(speed), m_hp(hp), m_name(name)
	{}

	int getSpeed() const
	{
		return m_speed;
	}
	int getHP() const
	{
		return m_hp;
	}
	std::string getName() const
	{
		return m_name;
	}
	bool operator==(const Car& obj) const;
	friend std::ostream& operator<<(std::ostream& out, Car& obj);
private:
	int m_speed;
	int m_hp;
	std::string m_name;
};


template <>
struct std::hash<Car>
{
	std::size_t operator()(const Car& obj) const
	{
		std::size_t a = std::hash<int>()(obj.getSpeed());
		std::size_t b = std::hash<int>()(obj.getHP());
		std::size_t c = std::hash<std::string>()(obj.getName());
		return (a ^ b ^ (c << 7));
	}
};



#endif // !CAR_H_
