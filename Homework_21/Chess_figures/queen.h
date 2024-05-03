#ifndef QUEEN_H_
#define QUEEN_H_


class Queen  
{
public:
	Queen();
	Queen(int, int, bool);
	//void move();
	//bool valid_move(int x, int y) const;
private:
	int m_x;
	int m_y;
	static const int s_value = 9;
	bool m_color;
};




#endif // QUEEN_H_