#ifndef ROOK_H_
#define ROOK_H_

class Rook {
public:
	Rook();
	Rook(int, int, bool);
	//void move();
protected:
	//bool valid_move(int x, int y) const;
private:
	int m_x;
	int m_y;
	static const int s_value = 5;
	bool m_color;
};




#endif // ROOK_H_