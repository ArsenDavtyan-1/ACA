#ifndef KNIGHT_H_
#define KNIGHT_H_

class Knight {
public:
	Knight();
	Knight(int, int, bool);
	//void move();
private:
	//bool valid_move(int x,int y) const;
	int m_x;
	int m_y;
	static const int s_value = 3;
	bool m_color;
};




#endif // KNIGHT_H_
