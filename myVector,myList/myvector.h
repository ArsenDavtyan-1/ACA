#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include "namespace.h"


template <typename T>
my::vector<T>::vector() : m_ptr(nullptr), m_size(0), m_cap(15)
{
	m_ptr = new T[m_cap];
}

template<typename T>
my::vector<T>::vector(std::initializer_list<T> init)
{
	m_size = init.size();
	m_cap = 15;
	while (m_cap < m_size)
		m_cap *= 2;
	m_ptr = new T[m_cap];
	int i = 0;
	for (const T& elem : init)
		m_ptr[i++] = elem;
}

template <typename T>
void my::vector<T>::push_back(T a)
{
	if (m_size < m_cap) {
		m_ptr[m_size++] = a;
	}
	else { 
		m_cap *= 2;
		T* tempptr = new T[m_cap];
		for (int i = 0; i < m_size; ++i)
		{
			tempptr[i] = m_ptr[i];
		}
		tempptr[m_size++] = a;
		delete[] m_ptr;
		m_ptr = tempptr;
		tempptr = nullptr;
	}
	return;
}

template <typename T>
void my::vector<T>::pop_back()
{
	if (is_empty())
		return;
	--m_size;
	if (m_size < (m_cap / 2) && m_cap > 15)
	{
		m_cap /= 2;
		T* new_ptr = new T[m_cap];
		for (int i = 0; i < m_size; ++i){
			new_ptr[i] = m_ptr[i];
		}
		delete[] m_ptr;
		m_ptr = new_ptr;
		new_ptr = nullptr;
	}
	return;
}

template <typename T>
void my::vector<T>::push_front(T value)
{
	if (m_size + 1 >= m_cap){
		T* new_ptr = new T[m_cap * 2];
		new_ptr[0] = value;
		for (int i = 0; i < m_size; ++i)
			new_ptr[i + 1] = m_ptr[i];
		delete[] m_ptr;
		m_ptr = new_ptr;
		new_ptr = nullptr;
	}
	else {
		for (int i = m_size - 1; i >= 0; --i)
			m_ptr[i + 1] = m_ptr[i];
		m_ptr[0] = value;
	}
	++m_size;
	return;
}

template <typename T>
void my::vector<T>::pop_front()
{
	if (m_size - 1 <= m_cap / 2 && m_cap > 15){
		T* new_ptr = new T[m_cap / 2];
		for (int i = 0; i < m_size - 1; ++i)
			new_ptr[i] = m_ptr[i + 1];
		m_cap /= 2;
		delete[] m_ptr;
		m_ptr = new_ptr;
		new_ptr = nullptr;
	}
	else {
		for (int i = 0; i < m_size - 1; i++)
			m_ptr[i] = m_ptr[i + 1];
	}
	--m_size;
	return;
}

template <typename T>
void my::vector<T>::insert(T value, int position)
{
	if (position < 0 || position > m_size){
		std::cout << "invalid position for insert" << std::endl;
		return;
	}
	if (m_size + 1 > m_cap)
	{
		m_cap *= 2;
		T* new_ptr = new T[m_cap];
		for (int i = 0; i < position; ++i)
			new_ptr[i] = m_ptr[i];
		new_ptr[position] = value;
		for(int i = position + 1;i < m_size + 1; ++i)
			new_ptr[i] = m_ptr[i - 1];
		delete[] m_ptr;
		m_ptr = new_ptr;
		new_ptr = nullptr;
	}
	else {
		for (int i = m_size; i > position; --i)
			m_ptr[i] = m_ptr[i - 1];
		m_ptr[position] = value;
	}

	++m_size;
	return;
}

template <typename T>
int my::vector<T>::getSize()
{
	return m_size;
}

template <typename T>
int my::vector<T>::getCapacity()
{
	return m_cap;
}

template <typename T>
my::vector<T>::~vector()
{
	delete[] m_ptr;
}

template<typename T>
T my::vector<T>::operator[](int i)
{
	return m_ptr[i];
}

template<typename T>
inline bool my::vector<T>::is_empty()
{
	return !m_size;
}

template<typename T>
void my::vector<T>::print()
{
	if (m_size) {
		for (int i = 0; i < m_size; ++i)
		{
			std::cout << m_ptr[i] << ' ';
		}
		std::cout << '\n';
	}
	else {
		std::cout << "The container is empty" << std::endl;
	}
}

#endif // !MY_VECTOR_H
