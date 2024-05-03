#include <iostream>
#include "king.h"

King::King()
{
	m_color = 0;
	m_x = 5;
	m_y = 1;
}

King::King(int x, int y, bool color)
{
	m_color = color;
	m_x = x;
	m_y = y;
}

