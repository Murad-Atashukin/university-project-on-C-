#include "Straight.h"

Straight::Straight()
{
	k = b = 0;
}

Straight::Straight(double x, double k, double b)						// Конструктор с параметрами
{																		
	this->b = b;														
	this->x = x;														
	this->k = k;														// Полю нашего объекта присваиваем полученные данные
}

Straight::Straight(const Straight& object)								// Конструктор копирования
{
	this->x = object.x;
	this->k = object.k;
	this->b = object.b;
}

void Straight::print()													// Метод print()
{
	std::cout << "При x = " << x << ", k = " << k << " и b = " << b << " [ Y = " << function_for_y() << " ]" << std::endl;
}
	
double Straight::function_for_y()										// Метод function_for_y()
{
	return k*x+b;
}

Straight& Straight::operator=(const Straight& object)					// Перегруженный оператор =
{
	this->x = object.x;
	this->k = object.k;
	this->b = object.b;
	return *this;
}
