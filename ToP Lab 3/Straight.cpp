#include "Straight.h"

Straight::Straight()
{
	k = b = 0;
}

Straight::Straight(double x, double k, double b)						// ����������� � �����������
{																		
	this->b = b;														
	this->x = x;														
	this->k = k;														// ���� ������ ������� ����������� ���������� ������
}

Straight::Straight(const Straight& object)								// ����������� �����������
{
	this->x = object.x;
	this->k = object.k;
	this->b = object.b;
}

void Straight::print()													// ����� print()
{
	std::cout << "��� x = " << x << ", k = " << k << " � b = " << b << " [ Y = " << function_for_y() << " ]" << std::endl;
}
	
double Straight::function_for_y()										// ����� function_for_y()
{
	return k*x+b;
}

Straight& Straight::operator=(const Straight& object)					// ������������� �������� =
{
	this->x = object.x;
	this->k = object.k;
	this->b = object.b;
	return *this;
}
