#include "Hyperbola.h"

Hyperbola::Hyperbola()														// ����������� ��� ����������
{
	a = 0;																	// �������� ��� ����
	b = 0;
}

Hyperbola::Hyperbola(double a, double b, double x)							// ����������� � �����������
{																			// ���� �� ������������ ����. ����� this, �� ���������� ����� ��� ���
																			// ������������� ��������� x ��������� �������� ������������� ��������� x
																			// (��� ����� ���, ���� ����� ���������, � ���� ������ ����� �������� ������� ������������� ��� this)
	this->x = x;															// ���� ������ ������� ����������� ���������� ������
	this->a = a;
	this->b = b;
}

Hyperbola::Hyperbola(const Hyperbola& object)								// ����������� �����������
{
	this->a = object.a;
	this->b = object.b;
	this->x = object.x;
}

void Hyperbola::print()														// ����� print()
{
	std::cout << "��� a = " << a << ", b = " << b << " � x = " << x << " [ Y = " << function_for_y() << " ]" << std::endl;
}

double Hyperbola::function_for_y()											// ����� function_for_y()
{
	return sqrt((pow(a, 2) * pow(b, 2) + pow(x, 2) * pow(b, 2)) / pow(a, 2));
}

Hyperbola& Hyperbola::operator=(const Hyperbola& object)					// ������������� �������� =
{
	this->a = object.a;
	this->b = object.b;
	this->x = object.x;
	return *this;
}
