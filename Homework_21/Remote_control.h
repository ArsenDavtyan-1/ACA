#ifndef REMOTE_CONTROL_H_
#define REMOTE_CONTROL_H_

class Remote_control
{
public:
	virtual void volume_up() = 0;
	virtual void volume_low() = 0;
	virtual int get_volume() = 0;
	virtual void move_to_next_channel() = 0;
	virtual void move_to_back_channel() = 0;
	virtual int get_channel() = 0;
	virtual void show_buttons() = 0;
	virtual void set_button_number(int button) = 0;
	virtual void turn_on_of(bool button) = 0;
	virtual void switch_to_HDMI(int HDMI_number) = 0;
	virtual void switch_to_tv() = 0;
	virtual void mute() = 0;
	virtual void unmute() = 0;

	virtual ~Remote_control() {};
};


#endif // REMOTE_CONTROL_H_