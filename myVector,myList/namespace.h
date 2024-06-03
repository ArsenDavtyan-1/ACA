#ifndef NAMESPACE_H_
#define NAMESPACE_H_


namespace my
{
	template <typename T>
	class vector
	{
	private:
		int m_size;
		int m_cap;
		T* m_ptr;
	public:
		vector();
		vector(std::initializer_list<T> init);
		int getSize();
		int getCapacity();
		void push_back(T);
		void pop_back();
		void push_front(T);
		void pop_front();
		void insert(T value, int position);
		bool is_empty();
		void print();
		~vector();
		T operator[](int);

	};

	template <typename T>
	class Node
	{
	public:
		T m_value;
		Node* m_next;
		Node()
		{
			m_next = nullptr;
		}
		Node(T value) : m_value(value), m_next(nullptr)
		{}

		~Node()
		{
			m_next = nullptr;
		}
	};

	template <typename T>
	class List
	{

	private:
		Node<T>* head;


	public:
		List();
		List(T value);
		void push_front(T value);
		void pop_front();
		void print();
		void insert(T value, int position);
		~List();
	};


}


#endif // !NAMESPACE_H_ 

