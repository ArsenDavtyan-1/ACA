#include <iostream>
#include <cstdlib>
#include "knight.h"

Knight::Knight()
{
	m_color = 0;
	m_x = 2;
	m_y = 1;
}

Knight::Knight(int x, int y, bool color)
{
	m_color = color;
	m_x = x;
	m_y = y;
}

//bool Knight::valid_move(int x, int y) const
//{
//	if ((abs(x - m_x) == 2 && abs(y - m_y) == 1 && x <= 8 && x > 0 && y <= 8 && y > 0)
//		|| (abs(y - m_y) == 2 && abs(x - m_x) == 1 && x <= 8 && x > 0 && y <= 8 && y > 0))
//	{
//		return true;
//	}
//	std::cout << "invalid move,try again" << std::endl;
//	return false;
//}
//
//void Knight::move()
//{
//	int x, y;
//	do {
//		std::cout << "choose moves" << std::endl << " x = " << std::endl;
//		std::cin >> x;
//		std::cout << " y = " << std::endl;
//		std::cin >> y;
//	} while (valid_move(x, y));
//	m_x = x;
//	m_y = y;
//}
