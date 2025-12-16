#include <iostream>
#include <stdexcept>
template<typename T>
class Array {
private:
	T* m_Array;
	size_t m_size;
public:
	Array(size_t size): m_Array(new T[size]), m_size(size)
	{
		for (size_t i = 0; i < size; ++i)
		{
			m_Array[i] = 0; //Pointer arthemetic m_array { address+ (i* sizeof(T)) }
		}
		std::cout << "Default constructor called" << std::endl;

	}
	~Array()
	{
		delete[] m_Array;
	}
	//Copy constructor  Default copy constructor copies shallow. will cause double deletion error.
	Array(const Array& rhs)
	{
		std::cout << "CopyConstructor called" << std::endl;
		this->m_size = rhs.m_size;
		m_Array = new T[m_size];
		for (size_t i = 0; i < m_size; ++i)
			m_Array[i] = rhs.m_Array[i];
	}
	//Assignment operator a1=a2 deep copy
	Array& operator=(const Array& rhs)
	{
		std::cout << "Assignement called" << std::endl;

		if (this != &rhs)
		{
			delete[] m_Array;
			this->m_size = rhs.m_size;
			this->m_Array = new T[m_size];
			for (size_t i = 0; i < m_size; ++i)
				m_Array[i] = rhs.m_Array[i];


		}
		
		return *this;
	}

	//[] operator overloading for accessing element and updating 
	T& operator[](size_t index)
	{
		if(index >= m_size)
			throw std::out_of_range("Index out of bound");
		return m_Array[index];

	}
	
	size_t size()//const Array& input)
	{
		return this->m_size;
	}

	//4. Move Constructor 
	Array(Array&& rhs) noexcept
		:m_size(rhs.m_size),m_Array(rhs.m_Array)
	{
		std::cout << "Move constructor called" << std::endl;
		rhs.m_size = 0;
		rhs.m_Array = nullptr;


	}
	//5. Move Assignment
	Array& operator=(Array&& rhs) noexcept
	{
		std::cout << "Move Assignment called" << std::endl;

		if (this != &rhs)
		{
			delete[] m_Array;
			this->m_size = rhs.m_size;
			this->m_Array = rhs.m_Array;
			rhs.m_size = 0;
			rhs.m_Array = nullptr;

		}
		std::cout << "Move assignment called" << std::endl;
		return *this;

	}
	void display()
	{
		for (size_t i=0;i<this->m_size; i++)
			std::cout<<m_Array[i]<<"\t";
		std::cout<<std::endl;

	}

	void setValue(size_t index, T value)
	{
		m_Array[index] = value;
	}


};