#include <iostream>
#include "bishop.h"

Bishop::Bishop()
{
	m_x = 3;
	m_y = 1;
	m_color = 0;
}

Bishop::Bishop(int x, int y, bool color)
{
	m_x = x;
	m_y = y;
	m_color = color;
}

//void Bishop::move()
//{
//	int x, y;
//	do {
//		std::cout << "choose moves" << std::endl << " x = " << std::endl;
//		std::cin >> x;
//		std::cout << " y = " << std::endl;
//		std::cin >> y;
//	} while (valid_move(x,y));
//	m_x = x;
//	m_y = y;
//}
//
//bool Bishop::valid_move(int x, int y) const
//{
//	if ((x - m_x == y - m_y) && x <= 8 && x > 0 && y <= 8 && y > 0)
//	{
//		return true;
//	}
//	std::cout << "invalid move,try again" << std::endl;
//	return false;
//}