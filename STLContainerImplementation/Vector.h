#pragma once
#include <initializer_list>
template <typename T>
class Vector {
private:
	T* m_data;
	size_t m_capacity;
	size_t m_size;
public:
	// Constructor
	Vector();

	Vector(size_t n);

	Vector(std::initializer_list<T> list);
	
	//Copy constructor
	Vector(const Vector& rhs);

	// Destructor
	~Vector();

	Vector<T>& operator=(const Vector& rhs);

	// Assignment Operator
	//const Vector<T>& operator=(const T& rhsObject);
	
	//5. Move Constructor
	Vector(Vector<T>&& rhsObject) noexcept; 			//v1(createVector()); or v1(new Vector


	//Move Assignment	
	Vector& operator=(Vector&& rhsObject) noexcept;		//v1 = std::move(v2);
	
	T& operator [](const size_t index); // updating v[i]=x;
	const T& operator[](const size_t index) const; // accessing x=v[i];
	void reserve(const size_t newCapacity);
	void push_back(const T& value);//v.push_back(value);
	
	void pop();					//v.pop();
	//T& at(size_t index);		//v.at(index);	
	size_t size();				//v.size();
	size_t capacity();			//v.capacity();
	bool is_empty();			//v.is_empty();
	//void emplace_back(const T& object);// v.emplace_back(value);

	void display();

};

