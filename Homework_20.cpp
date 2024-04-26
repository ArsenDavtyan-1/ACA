#include <iostream>

class Car
{
public:
	Car() : m_price(10000), m_hp(150), m_max_speed(200), m_marca("Reno"), m_color("grey")
	{}
	Car(int price,int hp,int speed,std::string name,std::string color)
		: m_price(price), m_hp(hp),m_max_speed(speed), m_marca(name), m_color(color)
	{}
	virtual void print()
	{
		std::cout << "Marca - " << m_marca << std::endl;
		std::cout << "Color - " << m_color << std::endl;
		std::cout << "Max speed = " << m_max_speed << std::endl;
		std::cout << "HP = " << m_hp << std::endl;
		std::cout << "Price = " << m_price << std::endl;
	}
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
	void set_marca(std::string name)
	{
		m_marca = name;
	}
	void set_hp(int hp)
	{
		m_hp = hp;
	}
	int get_price() const
	{
		return m_price;
	}
	int get_max_speed() const
	{
		return m_max_speed;
	}
	int get_hp() const
	{
		return m_hp;
	}
	std::string get_marca() const
	{
		return m_marca;
	}
	std::string get_color() const
	{
		return m_color;
	}
private:
	int m_price;
	int m_hp;
	int m_max_speed;
	std::string m_marca;
	std::string m_color;
};

class Truck : public Car
{
public:
	Truck() : Car(), m_capacity(2000)
	{}
	Truck(int price, int hp, int speed, std::string name, std::string color,int capacity)
		: Car(price,hp,speed,name,color),m_capacity(capacity)
	{}
	void print()
	{
		Car::print();
		std::cout << "Capacity = " << m_capacity << std::endl;
	}
	void set_capacity(int cap)
	{
		m_capacity = cap;
	}
	int get_capacity() const
	{
		return m_capacity;
	}
private:
	int m_capacity;
};

class Sportcar : public Car
{
public:
	Sportcar() : Car(),m_RPM(650)
	{}
	Sportcar(int price, int hp, int speed, std::string name, std::string color, int RPM)
		: Car(price, hp, speed, name, color), m_RPM(RPM)
	{}
	void print()
	{
		Car::print();
		std::cout << "RPM = " << m_RPM << std::endl;
	}
	void set_RPM(int RPM)
	{
		m_RPM = RPM;
	}
	int get_RPM() const
	{
		return m_RPM;
	}
private:
	int m_RPM;
};

class Sedan : public Car
{
public:
	Sedan() : Car(), m_seats_number(4)
	{}
	Sedan(int price, int hp, int speed, std::string name, std::string color, int seats_number)
		: Car(price, hp, speed, name, color), m_seats_number(seats_number)
	{}
	void print()
	{
		Car::print();
		std::cout << "Seats number = " << m_seats_number << std::endl;
	}
	void set_seats_number(int seats_number)
	{
		m_seats_number = seats_number;
	}
	int get_seats_number() const
	{
		return m_seats_number;
	}
private:
	int m_seats_number;
};

class Porsche : public Sportcar
{
public:
	Porsche() : Sportcar()
	{
		Sportcar::set_marca("Porsche");
	}
	Porsche(int price, int hp, int speed, std::string name, std::string color, int RPM)
		: Sportcar(price, hp, speed, name, color,RPM)
	{
		Sportcar::set_marca("Porshce " + name);
	}
};

class Ferrari : public Sportcar
{
public:
	Ferrari() : Sportcar()
	{
		Sportcar::set_marca("Ferrari");
	}
	Ferrari(int price, int hp, int speed, std::string name, std::string color, int RPM)
		: Sportcar(price, hp, speed, name, color, RPM)
	{
		Sportcar::set_marca("Ferrari " + name);
	}
};

class Buggati : public Sportcar
{
public:
	Buggati() : Sportcar()
	{
		Sportcar::set_marca("Buggati");
	}
	Buggati(int price, int hp, int speed, std::string name, std::string color, int RPM)
		: Sportcar(price, hp, speed, name, color, RPM)
	{
		Sportcar::set_marca("Buggati " + name);
	}
};

class Honda : public Sedan
{
public:
	Honda() : Sedan()
	{
		Sedan::set_marca("Honda");
	}
	Honda(int price, int hp, int speed, std::string name, std::string color, int seats_number)
		: Sedan(price, hp, speed, name, color, seats_number)
	{
		Sedan::set_marca("Honda " + name);
	}
};

class Toyota : public Sedan
{
public:
	Toyota() : Sedan()
	{
		Sedan::set_marca("Toyota");
	}
	Toyota(int price, int hp, int speed, std::string name, std::string color, int seats_number)
		: Sedan(price, hp, speed, name, color, seats_number)
	{
		Sedan::set_marca("Toyota " + name);
	}
};

class Hyundai : public Sedan
{
public:
	Hyundai() : Sedan()
	{
		Sedan::set_marca("Hyundai");
	}
	Hyundai(int price, int hp, int speed, std::string name, std::string color, int seats_number)
		: Sedan(price, hp, speed, name, color, seats_number)
	{
		Sedan::set_marca("Hyundai " + name);
	}
};

class Man : public Truck
{
public:
	Man() : Truck()
	{
		Truck::set_marca("Man");
	}
	Man(int price, int hp, int speed, std::string name, std::string color, int capacity)
		: Truck(price, hp, speed, name, color, capacity)
	{
		Truck::set_marca("Man " + name);
	}
};

class Kamaz : public Truck
{
public:
	Kamaz() : Truck()
	{
		Truck::set_marca("Kamaz");
	}
	Kamaz(int price, int hp, int speed, std::string name, std::string color, int capacity)
		: Truck(price, hp, speed, name, color, capacity)
	{
		Truck::set_marca("Kamaz " + name);
	}
};

class Bellaz : public Truck
{
public:
	Bellaz() : Truck()
	{
		Truck::set_marca("Bellaz");
	}
	Bellaz(int price, int hp, int speed, std::string name, std::string color, int capacity)
		: Truck(price, hp, speed, name, color, capacity)
	{
		Truck::set_marca("Bellaz " + name);
	}
};

int main()
{
	Buggati A(1000000, 1100, 420, "Chirron", "Black", 1700);
	A.print();
	std::cout << std::endl;
	Man B(80000, 350, 220, "W12", "Grey", 5000);
	B.print();
	std::cout << std::endl;
	Toyota C(20000, 250, 260, "Corolla", "White", 4);
	C.print();
	std::cout << std::endl;
}