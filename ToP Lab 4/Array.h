#ifndef _ARRAY_H_
#define _ARRAY_H_

#include "Library.h"

template<typename T>
class Array
{
private:
    T* data;
    int16_t size;	
	bool full;

public:
    Array(int16_t size);
    Array(const Array& object);
    ~Array();

    void show();
	bool GetFull();
    int16_t GetSize();

    Array<T>& operator=(const Array& object);
    bool operator==(const Array& object);
    T& operator[](const int16_t index);

    template <typename T> friend std::ostream& operator<<(std::ostream& out, Array<T>& object);	// Перегруженный оператор вывода
    template <typename T> friend std::istream& operator>>(std::istream& in, Array<T>& object);	// Перегруженный оператор ввода

};

template<typename T>
inline Array<T>::Array(int16_t size) /* Inline функция избавляет процессор прыгать в ячейку, по адресу
									 которой начинается эта функция. Сам смысл inline состоит в том,
									 чтобы вместо вызова функции подставить ее тело (код функции) в место, где она
									 вызывается.*/
{
	full = 0;
	this->size = size;
	data = new T[size];

	for (int16_t i = 0; i < size; i++)
	{
		data[i] = 0;
	}
}

template<typename T>
inline Array<T>::Array(const Array& object)
{
	this->full = object.full;
	this->size = object.size;
	data = new T[size];

	for (int16_t i = 0; i < size; i++)
	{
		data[i] = object.data[i];
	}
}

template<typename T>
inline Array<T>::~Array()
{
	delete[] data;
}

template<typename T>
inline void Array<T>::show()
{
	if (size == 0)
	{
		std::cout << "Массив пуст!";
	}

	else
	{
		for (int16_t i = 0; i < size; i++)
		{
			std::cout << data[i] << " ";
		}
		std::cout << std::endl;
	}
}

template<typename T>
inline bool Array<T>::GetFull()
{
	return full;
}

template<typename T>
inline int16_t Array<T>::GetSize()
{
	return size;
}

template<typename T>
inline Array<T>& Array<T>::operator=(const Array& object)
{
	delete[] data;
	this->full = object.full;
	this->size = object.size;
	data = new T[size];

	for (int16_t i = 0; i < size; i++)
	{
		data[i] = object.data[i];
	}
	return *this;
}

template<typename T>
inline bool Array<T>::operator==(const Array& object)
{
	bool result = 0;

	result = (size == object.size) ? 1 : 0;
	return result;
}

template<typename T>
inline T& Array<T>::operator[](const int16_t index)
{
	if (index > size - 1 || index < 0)
		throw "Некорректный индекс элемента!";

	return data[index];
}

template<typename T>
std::ostream& operator<<(std::ostream& out, Array<T>& object)    // Оператор вывода
{
	if (object.size == 0)
	{
		out << "Массив пуст! ";
	}

	else                                                        // Если есть элементы
	{
		for (int16_t i = 0; i < object.size; i++)				
		{
			out << object[i] << " ";
		}
		out << std::endl;
	}
	return out;													// Возвращаем на нее ссылку
}

template<typename T>
std::istream& operator>>(std::istream& in, Array<T>& object)	// Оператор ввода
{
	T value;

	if (object.full == 0)
	{
		for (int16_t i = 0; i < object.size; i++)
		{
			in >> value;
			in.ignore(32767, '\n');
			object[i] = value;
		}
		object.full = 1;
	}

	else
	{
		T* temp = new T[object.size + 1];

		for (int16_t i = 0; i < object.size; i++)
		{
			temp[i] = object.data[i];
		}
		object.size++;
		delete[] object.data;
		object.data = temp;

		in >> value;
		in.ignore(32767, '\n');
		object[object.size - 1] = value;
	}

	return in;													// Возвращаем ссылку на переменную потокового ввода
}

#endif // !_ARRAY_H_