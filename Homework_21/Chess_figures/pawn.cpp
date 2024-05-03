#include <iostream>
#include "pawn.h"

Pawn::Pawn()
{
	m_color = false;
	m_x = 2;
	m_y = 2;
}

Pawn::Pawn(int x, int y, bool color)
{
	m_color = color;
	m_x = x;
	m_y = y;
}

//void Pawn::promotion()
//{
//	
//}

//void Pawn::move()
//{
//	if (m_color == 0) {
//		if (m_y == 2)
//		{
//			int mov;
//			std::cout << " choose moves count " << std::endl;
//			std::cin >> mov;
//			if (mov == 1) {
//				m_y += 1;
//			}
//			else {
//				m_y += 2;
//			}
//		}
//		else if (m_y < 8) {
//			m_y += 1;
//		}
//		else if (m_y > 8 || m_y < 0) {
//			std::cout << "pawn is inaccesbile place y > 8 or y < 0" << std::endl;
//		}
//		if (m_y == 8)
//		{
//			promotion();
//		}
//	}
//	if (m_color == 1) {
//		if (m_y == 7)
//		{
//			int mov;
//			std::cout << " choose moves count " << std::endl;
//			std::cin >> mov;
//			if (mov == 1) {
//				m_y -= 1;
//			}
//			else {
//				m_y -= 2;
//			}
//		}
//		else if (m_y > 0) {
//			m_y -= 1;
//		}
//		else if (m_y > 8 || m_y < 0) {
//			std::cout << "pawn is inaccesbile place y > 8 or y < 0" << std::endl;
//		}
//		if (m_y == 1)
//		{
//			promotion();
//		}
//	}
//}