#ifndef BISHOP_H_
#define BISHOP_H_

class Bishop {
public:
	Bishop();
	Bishop(int, int, bool);
	//void move();
protected:
	//bool valid_move(int x, int y) const;
private:
	int m_x;
	int m_y;
	static const int s_value = 3;
	bool m_color;
};




#endif // BISHOP_H_