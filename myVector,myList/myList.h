#ifndef MY_LIST_H
#define MY_LIST_H

#include "namespace.h"

template <typename T>
my::List<T>::List()
{
	head = nullptr;
}

template <typename T>
my::List<T>::List(T value)
{
	head = new Node(value);
}

template <typename T>
void my::List<T>::push_front(T value)
{
	Node<T>* temp = new Node<T>(value);
	temp->m_next = head;
	head = temp;
}

template <typename T>
void my::List<T>::pop_front()
{
	if (head == nullptr)
	{
		std::cout << "The list are empty, there are nothing to pop" << std::endl;
		return;
	}
	Node<T>* temp = head;
	head = head->m_next;
	delete temp;
}

template <typename T>
void my::List<T>::print()
{
	if (head == nullptr)
	{
		std::cout << "The list are empty" << std::endl;
		return;
	}
	Node<T>* temp = head;
	while (temp != nullptr)
	{
		std::cout << temp->m_value << ' ';
		temp = temp->m_next;
	}
	std::cout << std::endl;
}

template <typename T>
void my::List<T>::insert(T value, int position)
{
	if (position < 0)
	{
		std::cout << "Invalid position" << std::endl;
		return;
	}
	Node<T>* temp = head;
	for (int i = 0; i < position - 1; ++i)
	{
		temp = temp->m_next;
		if (temp == nullptr )
		{
			std::cout << "Invalid position" << std::endl;
			return;
		}
	}
	Node<T>* obj = new Node<T>(value);
	obj->m_next = temp->m_next;
	temp->m_next = obj;
	return;
}

template <typename T>
my::List<T>::~List()
{
	Node<T>* temp;
	while (head != nullptr)
	{
		temp = head;
		head = head->m_next;
		delete temp;
	}
}

#endif // ! MY_LIST_H
