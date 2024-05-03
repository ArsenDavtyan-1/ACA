#ifndef PAWN_H_
#define PAWN_H_

class Pawn {
public:
	Pawn();
	Pawn(int, int, bool);
    //void move();
	//void take();
	//void promotion();
private:
	int m_x;
	int m_y;
	const static int s_value = 1;
	bool m_color;    // if 0 - white, 1 - black
};





#endif // PAWN_H_
