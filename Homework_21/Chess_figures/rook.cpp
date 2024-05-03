#include <iostream>
#include <cstdlib>
#include "rook.h"

Rook::Rook()
{
	m_color = 0;
	m_x = 1;
	m_y = 1;
}

Rook::Rook(int x, int y, bool color)
{
	m_color = color;
	m_x = x;
	m_y = y;
}

//void Rook::move()
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
//
//bool Rook::valid_move(int x, int y) const
//{
//	if ((x == m_x && y <= 8 && y > 0) || (y == m_y && x <= 8 && x > 0))
//	{
//		return true;
//	}
//	std::cout << "invalid move,try again" << std::endl;
//	return false;
//}