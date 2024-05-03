#include "queen.h"
#include <iostream>

Queen::Queen(int x, int y, bool color)
{
	m_color = color;
	m_x = x;
	m_y = y;
}

Queen::Queen()
{
	m_color = 0;
	m_x = 4;
	m_y = 1;
}