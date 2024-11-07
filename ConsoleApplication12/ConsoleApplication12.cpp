// ConsoleApplication12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;


template <class T> class Array {
	int size;
	T * mass;
public:
	Array();
	Array(int _size, T _mass);
	int getSize();
	void setSize(int size, int grow = 1);
	int getUpperBound();
	bool isEmpty();
	void removeAll();
	void setAt(int i, T value);
	T getAt(int i);
	void operator[](int i);
	Array add(T value);
	void append(Array& obj);
	void operator=(const Array& obj);
	T getData(int i);
	void insertAt(int i, T value);
	void removeAt(int i);
	~Array() { delete[]mass; };
};

int main()
{
}

template<class T>
Array<T>::Array()
{
	mass = nullptr;
	size = 0;
}

template<class T>
Array<T>::Array(int _size, T _mass)
{
	size = _size;
	mass = new T[size+1];
	strcpy_s(mass, size+1, _mass);
}

template<class T>
int Array<T>::getSize()
{
	return size;
}

template<class T>
void Array<T>::setSize(int size, int grow)
{
	if (this->size < size) {
		this->size += grow;
	}
	mass = new char[this->size];
	strcpy_s(mass, size + 1, mass);
}

template<class T>
int Array<T>::getUpperBound()
{
	for (int i = 0; i < size; i++)
	{
		if (mass[i] == nullptr) {
			return i;
			break;
		}
	}
}

template<class T>
bool Array<T>::isEmpty()
{
	if (mass == nullptr) {
		return true;
	}
	return false;
}

template<class T>
void Array<T>::removeAll()
{
	delete[]mass;
	delete size;
}

template<class T>
void Array<T>::setAt(int i, T value)
{
	mass[i] = value;
	return mass[i];
}

template<class T>
T Array<T>::getAt(int i)
{
	return mass[i];
}

template<class T>
void Array<T>::operator[](int i)
{
	if (i >= 0 and i <= size) {
		return mass[i];
	}
	cout << endl;
}

template<class T>
Array<T> Array<T>::add(T value)
{
	mass = new T[size + 1];
	mass[size + 1] = value;
	return mass;
}

template<class T>
void Array<T>::append(Array& obj)
{
	int ssize = this->size + obj.size;
	mass = new T[ssize];
	for (int i = size; i < ssize ; i++)
	{
		for (int j = 0; j < obj.size; j++)
		{
			mass[i] == obj.mass[j];
		}
	}
}

template<class T>
void Array<T>::operator=(const Array& obj)
{
	size = obj.size;
	if (mass != nullptr) {
		delete[]mass;
	}
	mass = new T[size];
	strcpy_s(mass, size, obj.mass);	
}

template<class T>
T Array<T>::getData(int i)
{
	return mass[i];
}

template<class T>
void Array<T>::insertAt(int i,T value)
{
	for (int _i = 0; _i < size; _i++)
	{
		if (mass[_i] != i) {
			return false;
		}
	}
	mass.insert(data[0], i, value);
}

template<class T>
void Array<T>::removeAt(int i)
{
	for (int _i = 0; _i < size; _i++)
	{
		if (mass[_i] != i) {
			return false;
		}
	}
	mass.erase(i);
}


