#ifndef MY_LIST_H
#define MY_LIST_H
#include <stack>
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


template <typename T>
void my::List<T>::reverse()
{
	std::stack<T> st;
	while (head != nullptr)
	{
		st.push(head -> m_value);
		Node<T>* temp = head;
		head = head->m_next;
		delete temp;
	}
	
	if (!st.empty())
	{
		head = new Node<T>(st.top());
		st.pop();
		Node<T>* temp = head;
		while (!st.empty())
		{
			temp -> m_next = new Node<T>(st.top());
			temp = temp -> m_next;
			st.pop();
		}
		temp -> m_next = nullptr;
	}
}

template <typename T>
void my::List<T>::last_Nth(int position)
{
	if (position < 0)
	{
		std::cout << "invalid position" << std::endl;
		return;
	}
	int i = 0;
	Node<T>* temp1 = head;
	Node<T>* temp2 = head;
	while (i < position && temp1 != nullptr)
	{
		temp1 = temp1->m_next;
		++i;
	}
	if (i < (position - 1) || temp1 == nullptr)
	{
		std::cout << "There are not n-th element counted from the last" << std::endl;
		return;
	}

	while (temp1->m_next != nullptr)
	{
		temp1 = temp1->m_next;
		temp2 = temp2->m_next;
	}
	std::cout << "The " << position <<"-th element from the last is - " << temp2->m_value << std::endl;
}

//template <typename A>
//bool is_cycle(my::List<A>& list)
//{
//	if (list.head == nullptr)
//	{
//		std::cout << "The list are empty" << std::endl;
//		return false;
//	}
//	my::Node<A>* temp = list.head->m_next;
//	while (temp != list.head || temp != nullptr)
//		temp = temp->m_next;
//
//	return !(temp == nullptr);
//}



#endif // ! MY_LIST_H
