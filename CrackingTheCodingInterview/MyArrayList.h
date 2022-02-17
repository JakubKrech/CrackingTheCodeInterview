#pragma once

#include "CommonIncludes.h"

template <typename T>
class MyArrayList
{
private:
	double m_resizeFactor = 2;
	size_t m_size = 2;
	T* _tab;

	size_t m_lastItemIndex = -1;

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
	_tab = new T[m_size];
}

template <typename T>
MyArrayList<T>::MyArrayList(size_t size)
{
	m_size = size;
	_tab = new T[m_size];
}

template <typename T>
MyArrayList<T>::MyArrayList(size_t size, T initialValue)
{
	m_size = size;
	_tab = new T[size];

	for (size_t i = 0; i < m_size; ++i)
	{
		_tab[i] = initialValue;
	}

	m_lastItemIndex = m_size - 1;
}

template<typename T>
inline void MyArrayList<T>::Resize()
{
	size_t newSize = size_t(m_size * m_resizeFactor);
	cout << "Resizing MyArrayList from size:" << m_size << " to new size: " << newSize << endl;

	T* temp = _tab;
	_tab = new T[newSize];

	for (size_t i = 0; i < m_size && i < newSize; ++i)
	{
		//cout << "Copying:" << temp[i] << endl;
		_tab[i] = temp[i];
	}

	delete[](temp);
	m_size = newSize;
}

template<typename T>
inline void MyArrayList<T>::Print()
{
	cout << ">> Printing ArrayList:" << endl;

	for (size_t i = 0; i < m_size; ++i)
	{
		cout << "[" << i << "] " << _tab[i] << endl;
	}

	cout << ">> The end" << endl;
}

template <typename T>
size_t MyArrayList<T>::GetSize()
{
	return m_size;
}

template <typename T>
void MyArrayList<T>::Append(T item)
{
	m_lastItemIndex += 1;

	if (m_lastItemIndex >= m_size)
	{
		Resize();
	}

	_tab[m_lastItemIndex] = item;
}
