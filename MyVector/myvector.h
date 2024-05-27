#ifndef MY_VECTOR_H
#define MY_VECTOR_H

namespace my
{
	template <typename T>
	class vector
	{
	private:
		int m_size;
		int m_cap;
		T* ptr;
	public:
		vector();
		int getSize();
		void push_back(T);
		bool is_empty();
		void print();
		~vector();
		T operator[](int);
	};
}


template <typename T>
my::vector<T>::vector() : m_size(0), m_cap(15)
{
	ptr = new T[m_cap];
}

template <typename T>
void my::vector<T>::push_back(T a)
{
	if (m_size < m_cap) {
		ptr[m_size++] = a;
	}
	else { 
		m_cap *= 2;
		T* tempptr = new int[m_cap];
		for (int i = 0; i < m_size; ++i)
		{
			tempptr[i] = ptr[i];
		}
		tempptr[m_size++] = a;
		delete[] ptr;
		ptr = tempptr;
		tempptr = nullptr;
	}
}

template <typename T>
int my::vector<T>::getSize()
{
	return m_size;
}

template <typename T>
my::vector<T>::~vector()
{
	delete[] ptr;
}

template<typename T>
T my::vector<T>::operator[](int i)
{
	return ptr[i];
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
			std::cout << ptr[i] << ' ';
		}
		std::cout << '\n';
	}
	else {
		std::cout << "The container is empty" << std::endl;
	}
}

#endif // !MY_VECTOR_H
