#pragma once

#include "CommonIncludes.h"

template <typename T>
class MyArrayList
{
private:
	double _resizeFactor = 2;
	size_t _size = 2;
	T* _tab;

	size_t _lastItemIndex = -1;

public:
	MyArrayList();
	MyArrayList(size_t size);
	MyArrayList(size_t size, T initialValue);

	void Resize();
	void Print();

	size_t GetSize();
	void Append(T item);

	T& operator[](std::size_t idx) { return _tab[idx]; };

};

template <typename T>
MyArrayList<T>::MyArrayList()
{
	_tab = new T[_size];
}

template <typename T>
MyArrayList<T>::MyArrayList(size_t size)
{
	_size = size;
	_tab = new T[_size];
}

template <typename T>
MyArrayList<T>::MyArrayList(size_t size, T initialValue)
{
	_size = size;
	_tab = new T[size];

	for (size_t i = 0; i < _size; ++i)
	{
		_tab[i] = initialValue;
	}

	_lastItemIndex = _size - 1;
}

template<typename T>
inline void MyArrayList<T>::Resize()
{
	size_t newSize = size_t(_size * _resizeFactor);
	cout << "Resizing MyArrayList from size:" << _size << " to new size: " << newSize << endl;

	T* temp = _tab;
	_tab = new T[newSize];

	for (size_t i = 0; i < _size && i < newSize; ++i)
	{
		//cout << "Copying:" << temp[i] << endl;
		_tab[i] = temp[i];
	}

	delete[](temp);
	_size = newSize;
}

template<typename T>
inline void MyArrayList<T>::Print()
{
	cout << ">> Printing ArrayList:" << endl;

	for (size_t i = 0; i < _size; ++i)
	{
		cout << "[" << i << "] " << _tab[i] << endl;
	}

	cout << ">> The end" << endl;
}

template <typename T>
size_t MyArrayList<T>::GetSize()
{
	return _size;
}

template <typename T>
void MyArrayList<T>::Append(T item)
{
	_lastItemIndex += 1;

	if (_lastItemIndex >= _size)
	{
		Resize();
	}

	_tab[_lastItemIndex] = item;
}
