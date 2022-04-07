#include "Stack.h"

Stack::Stack(int16_t size)
{
	this->size = size;
	data = new double[size];

	for (int16_t i = 0; i < size; i++)
	{
		data[i] = ((double)(rand() % 100) / (double)(1 + rand() % 100)) * (rand () % 7);
	}
}

Stack::Stack(const Stack& object)
{
	size = object.size;
	data = new double[size];

	for (int16_t i = 0; i < size; i++)
	{
		data[i] = object.data[i];
	}
}

Stack::~Stack()
{
	delete[] data;
}

void Stack::show()
{
	std::cout << std::fixed;
	for (int16_t i = 0; i < size; i++)
	{
		std::cout << std::setprecision(4) << data[i] << " ";
	}
	std::cout << std::endl;
}

void Stack::operator=(const double value)
{
	for (int16_t i = 0; i < size; i++)
	{
		data[i] = value;
	}
}

void Stack::operator+=(const double value)
{
	for (int16_t i = 0; i < size; i++)
	{
		data[i] += value;
	}
}

void Stack::operator-=(const double value)
{
	for (int16_t i = 0; i < size; i++)
	{
		data[i] -= value;
	}
}

std::ostream& operator<<(std::ostream& out, const Stack& object)
{
	std::cout << std::fixed;
	for (int16_t i = 0; i < object.size; i++)
	{
		out << std::setprecision(4) << object.data[i] << " ";
	}
	out << std::endl;

	return out;
}

Stack operator+(const Stack& object_1, const double value)
{
	Stack stack(object_1);

	for (int16_t i = 0; i < stack.size; i++)
	{
		stack.data[i] = object_1.data[i] + value;
	}

	return stack;
}

Stack operator+(const double value, const Stack& object_1)
{
	Stack stack(object_1);

	for (int16_t i = 0; i < stack.size; i++)
	{
		stack.data[i] = object_1.data[i] + value;
	}

	return stack;
}

Stack operator-(const Stack& object_1, const double value)
{
	Stack stack(object_1);

	for (int16_t i = 0; i < stack.size; i++)
	{
		stack.data[i] = object_1.data[i] - value;
	}

	return stack;
}

Stack operator-(const double value, const Stack& object_1)
{
	Stack stack(object_1);

	for (int16_t i = 0; i < stack.size; i++)
	{
		stack.data[i] = value - object_1.data[i];
	}

	return stack;
}

Stack operator*(const Stack& object_1, const double value)
{
	Stack stack(object_1);

	for (int16_t i = 0; i < stack.size; i++)
	{
		stack.data[i] = object_1.data[i] * value;
	}

	return stack;
}

Stack operator*(const double value, const Stack& object_1)
{
	Stack stack(object_1);

	for (int16_t i = 0; i < stack.size; i++)
	{
		stack.data[i] = object_1.data[i] * value;
	}

	return stack;
}
