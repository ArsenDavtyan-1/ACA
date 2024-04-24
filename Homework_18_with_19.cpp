#include <iostream>

class Engine {
public:
	enum mode { electro, diesel, petrol };
	Engine() : m_hp(100), m_RPM(1500), m_fuel_consumption(2.2), m_type(petrol)
	{}
	Engine(int hp, double fuel_per_100km, int RPM, mode type);
	void print() const;

	void set_hp(int new_hp)
	{
		m_hp = new_hp;
	}
	void set_RPM(int RPM)
	{
		m_RPM = RPM;
	}
	void set_fuel_consumtion(double fc)
	{
		m_fuel_consumption = fc;
	}
	void set_mode();
	int get_hp() const
	{
		return m_hp;
	}
	int get_RPM() const
	{
		return m_RPM;
	}
	double get_fuel_consumtion() const
	{
		return m_fuel_consumption;
	}
	mode get_mode() const
	{
		return m_type;
	}

private:
	int m_hp;
	double m_fuel_consumption;         // per 100km
	int m_RPM;
	mode m_type;
};

class Car {
public:
	Car() : m_price(10000), m_max_speed(220), m_color("black"), m_name("Honda"), m_engine()
	{}
	Car(std::string name, std::string color, int price, int max_speed, const Engine& engine);
	void print() const;
	void set_price(int price)
	{
		m_price = price;
	}
	void set_color(std::string color)
	{
		m_color = color;
	}
	void set_max_speed(int max_speed)
	{
		m_max_speed = max_speed;
	}
	void set_new_engine(Engine& engine)
	{
		m_engine = engine;
	}
	int get_price() const
	{
		return m_price;
	}
	int get_max_speed() const
	{
		return m_max_speed;
	}
	std::string get_marca() const
	{
		return m_name;
	}
	std::string get_color() const
	{
		return m_color;
	}
	Engine get_engine() const
	{
		return m_engine;
	}
private:
	int m_price;
	int m_max_speed;
	std::string m_color;
	std::string m_name;
	Engine m_engine;
};


class Parking {
public:
	Parking()
	{
		m_size = 0;
		m_park = nullptr;
	}
	Parking(int size)
	{
		m_size = size;
		m_park = new Car * [m_size];
	}
	~Parking()
	{
		delete[] m_park;
	}
	bool is_full()
	{
		if (next_free_position >= m_size)
			return true;

		return false;
	}

	void adding_Car(Car& Parking)
	{
		if (!is_full()) {
			m_park[next_free_position] = &Parking;
			next_free_position++;
			return;
		}
		else {
			std::cout << "There are no free place" << std::endl;
			return;
		}
	}
	Car get_Car(int position)
	{
		if (position >= next_free_position) {
			std::cout << "Error, in that position there are no car" << std::endl;
		}
		return *m_park[position];
	}
	int get_next_free_position()
	{
		if (next_free_position >= m_size)
			return 0;
		return next_free_position;
	}
	void print()
	{
		for (int i = 0; i < next_free_position; i++)
		{
			std::cout << std::endl;
			m_park[i]->print();
		}
	}
private:
	int next_free_position = 0;
	Car** m_park;
	int m_size;
};

int main()
{
	Engine A(750, 5.5, 600, Engine::mode::petrol);
	A.print();
	A.set_mode();
	A.set_hp(800);
	A.set_RPM(650);
	A.print();
	std::cout << std::endl;
	Car Mercedes("Mercedes E200", "white", 100000, 280, A);
	Mercedes.print();
	std::cout << std::endl;
	Mercedes.set_color("yelow");
	A.set_hp(A.get_hp() + 50);
	A.set_RPM(A.get_RPM() + 100);
	Mercedes.set_new_engine(A);
	Mercedes.set_price(120000);
	Mercedes.set_max_speed(320);
	Mercedes.print();
	std::cout << std::endl;
	Engine B(600, 6.2, 780, Engine::mode::diesel);
	Car BMW("BMW M5", "Black", 80000, 290, B);
	std::cout << std::endl;
	BMW.print();
	std::cout << std::endl;
	Parking park(5);
	park.adding_Car(Mercedes);
	park.adding_Car(BMW);
	std::cout << std::boolalpha;
	std::cout << "is full - " << park.is_full() << std::endl;
	park.print();
	std::cout << "next free position - " << park.get_next_free_position() << std::endl;
}

Engine::Engine(int hp, double fuel_per_100km, int RPM, mode type)
{
	m_hp = hp;
	m_fuel_consumption = fuel_per_100km;
	m_RPM = RPM;
	m_type = type;
}

void Engine::print() const
{
	std::cout << "HP = " << m_hp << std::endl;
	std::cout << "fuel consumption per 100km = " << m_fuel_consumption << std::endl;
	std::cout << "RPM = " << m_RPM << std::endl;
	std::cout << "engine type = ";
	switch (m_type) {
	case 0:
		std::cout << "electro" << std::endl;
		break;
	case 1:
		std::cout << "diesel" << std::endl;
		break;
	case 2:
		std::cout << "petrol" << std::endl;
		break;
	}
}

void Engine::set_mode()
{
	std::cout << std::endl;
	std::cout << "Set the new mode for engine:" << std::endl;
	std::cout << "0 - electro" << std::endl;
	std::cout << "1 - diesel" << std::endl;
	std::cout << "2 - petrol" << std::endl;
	int n;
	std::cin >> n;
	switch (n)
	{
	case 0:
		m_type = electro;
		break;
	case 1:
		m_type = diesel;
		break;
	case 2:
		m_type = petrol;
		break;
	default:
		m_type = petrol;
	}
}

Car::Car(std::string name, std::string color, int price, int max_speed, const Engine& engine)
{
	m_name = name;
	m_color = color;
	m_price = price;
	m_max_speed = max_speed;
	m_engine = engine;
}

void Car::print() const
{
	std::cout << "Marca = " << m_name << std::endl;
	std::cout << "color = " << m_color << std::endl;
	std::cout << "price = " << m_price << std::endl;
	std::cout << "maximal speed = " << m_max_speed << std::endl;
	m_engine.print();
}
