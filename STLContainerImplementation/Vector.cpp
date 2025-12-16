#include "vector.h"
#include <stdexcept>
#include <iostream>

template<typename T>
inline Vector<T>::Vector()
	: m_data(nullptr),m_size(0),m_capacity(0)
{
}

template<typename T>
inline Vector<T>::Vector(size_t n)
	:m_data(new T[n]), m_size(n), m_capacity(n)
{
	std::cout << "Default Constructor"<<std::endl;

}
template<typename T>
Vector<T>::Vector(std::initializer_list<T> list)
	:m_data(new T[list.size()]),m_size(list.size()), m_capacity(list.size())
{
	size_t i = 0;
	for (auto &element : list)
		m_data[i++] = element;


	std::cout << "Initializer list" << std::endl;

}

template<typename T>
Vector<T>::Vector(const Vector& rhs)
	:m_data(new T[rhs.m_capacity]),m_size(rhs.m_size),m_capacity(rhs.m_capacity)
{
	for (int i = 0; i < m_size; i++)
		m_data[i] = rhs.m_data[i];


	std::cout << "Copy Constructor" << std::endl;

}

template<typename T>
Vector<T>::~Vector(){
	delete[] m_data;

}

//Assignment Operator v1=v2;

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector& rhs)
{
	if (this != &rhs)
	{
		delete[] m_data;
		m_size = rhs.m_size;
		m_capacity = rhs.m_capacity;
		m_data = new T[m_capacity];
		for (size_t i = 0; i < m_size; i++)
			this->m_data[i] = rhs.m_data[i];

	}
	std::cout << "Copy Assignment" << std::endl;

	return *this;

}

template<typename T>
Vector<T>::Vector(Vector<T>&& rhsObject) noexcept
	:m_size(rhsObject.m_size),m_capacity(rhsObject.m_capacity), m_data(rhsObject.m_data)
{
	//tranfer of ownership
	rhsObject.m_size = 0;
	rhsObject.m_capacity = 0;
	rhsObject.m_data = nullptr;
	std::cout << "Move Constructor" << std::endl;


}

template<typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& rhsObject) noexcept
{
	if (this != &rhsObject)
	{
		delete[] m_data;
		m_data = rhsObject.m_data;
		m_size = rhsObject.m_size;
		m_capacity = rhsObject.m_capacity;
		rhsObject.m_data = nullptr;
		rhsObject.m_size = 0;
		rhsObject.m_capacity = 0;
	}
	std::cout << "Move Assignment" << std::endl;


	return *this;
}
//v[i]=10;
template<typename T>
T& Vector<T>::operator[](const size_t index)
{
	if (index >= m_size)
		throw std::out_of_range("Index out of range");
	return m_data[index];

}

//x=v[i]
template<typename T>
const T& Vector<T>::operator[](const size_t index) const
{
	if (index >= m_size)
		throw std::out_of_range("Index out of range");
	return m_data[index];
}

template<typename T>
void Vector<T>::reserve(const size_t newCapacity)
{
	if (newCapacity <= m_capacity)
		return;
	std::cout << "Reserving new capacity" << newCapacity << std::endl;
	//not moving entire vector just the elments thats the functionality of reserve function

	T* newData = new T[newCapacity];
	for (size_t i = 0; i < m_size; i++)
		newData[i] = std::move(m_data[i]);
	delete[] m_data;
	m_data = newData;
	m_capacity = newCapacity;

}

template<typename T>
void Vector<T>::push_back(const T& value)
{
	if (m_size == m_capacity)
		reserve(m_capacity == 0? 1: 2 * m_capacity);
	m_data[m_size++] = value;

}

template<typename T>
void Vector<T>::pop() 
{
	if (m_size == 0)
		throw std::out_of_range("Vector is empty");
	m_data[m_size - 1].~T();// = 0;
	m_size--;

}
template<typename T>
size_t Vector<T>::size()
{
	return m_size;
}
template<typename T>
size_t Vector<T>::capacity()
{
	return m_capacity;
}

template<typename T>
bool Vector<T>::is_empty()
{
	return m_size == 0;
	//return (m_size > 0):false : true;
}

template<typename T>
void Vector<T>::display()
{
	for (size_t i = 0; i < m_size; i++)
		std::cout << m_data[i] << "\t";
	std::cout << std::endl;
	
}