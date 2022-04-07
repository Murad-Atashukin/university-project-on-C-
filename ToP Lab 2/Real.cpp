#include "Real.h"

Real::Real()
{
	value = 0;
}

Real::Real(double value)
{
	this->value = value;
}

void Real::show()
{
	std::cout << std::setprecision(4) << value << std::endl;
}

double Real::GetValue()
{
	return value;
}

void Real::SetValue(double value)
{
	this->value = value;
}

double Real::operator++()
{
	value += 0.5;
	return value;
}

double Real::operator--()
{
	value -= 0.1;
	return value;
}

double operator++(Real& object, int x)
{
	object.value += 2.5;
	return object.value;
}

double operator--(Real& object, int x)
{
	object.value -= 0.2;
	return object.value;
}