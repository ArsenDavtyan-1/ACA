#ifndef CAR_INTERFACE_H_
#define CAR_INTERFACE_H_
#include <string>

class Car 
{
public:
	virtual int get_price() = 0;
	virtual std::string get_name() = 0;
	virtual void print() = 0;
	virtual int get_year() = 0;
	virtual int get_seats_count() = 0;
	virtual void set_transmission_gear() = 0;
	virtual int get_speed() = 0;
	virtual void speed_up(int) = 0;
	virtual void speed_low(int) = 0;
	virtual void switch_regime() = 0;
	virtual ~Car(){}
};


#endif // CAR_INTERFACE_H_