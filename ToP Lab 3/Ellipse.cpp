#include "Ellipse.h"

Ellipses::Ellipses()														// ����������� ��� ����������
{
	a = 0;																	// �������� ��� ����
	b = 0;
}

Ellipses::Ellipses(double a, double b, double x)							// ����������� � �����������
{																			// ���� �� ������������ ����. ����� this, �� ���������� ����� ��� ���
																			// ������������� ��������� x ��������� �������� ������������� ��������� x
																			// (��� ����� ���, ���� ����� ���������, � ���� ������ ����� �������� ������� ������������� ��� this)
	this->x = x;															// ���� ������ ������� ����������� ���������� ������
	this->a = a;
	this->b = b;
}

Ellipses::Ellipses(const Ellipses& object)									// ����������� �����������
{
	this->a = object.a;
	this->b = object.b;
	this->x = object.x;
}

void Ellipses::print()														// ����� print()
{
	std::cout << "��� a = " << a << ", b = " << b << " � x = " << x << " [ Y = " << function_for_y() << " ]" << std::endl;
}

double Ellipses::function_for_y()											// ����� function_for_y()
{
	return sqrt((pow(a,2)*pow(b,2) - pow(x,2)*pow(b,2))/pow(a,2));
}

Ellipses& Ellipses::operator=(const Ellipses& object)						// ������������� �������� =
{
	this->a = object.a;
	this->b = object.b;
	this->x = object.x;
	return *this;
}
