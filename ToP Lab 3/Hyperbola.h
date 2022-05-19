// ������� ifndef ���������� ��� ����, ����� ������, ��������� �� �� ���� �������
#ifndef _HYPERBOLA_H_											// ���� � ��� ������ ��� ���. ���� ��������� ����������, �� ���������� ���������� �� �����
#define _HYPERBOLA_H_											// ���������� ��������� 

#include "Curves.h"

class Hyperbola : public Curves									// �������� ����������� �� ������������ ������
{																// [��� ��������� ������������ ������� ������������ ������� � ������� � ����� 
private:														// �� ��������� ������ �� ���������� (public �������� public � ��)]
	double a, b;

public:
	Hyperbola();												// ����������� ��� ����������
	Hyperbola(double a, double b, double x);					// ����������� � �����������
	Hyperbola(const Hyperbola& object);							// ����������� �����������
	~Hyperbola() {};											// ����������

	void print() override;										// ��������������� ����� print()
	double function_for_y() override;							// ��������������� ����� volume()
	Hyperbola& operator=(const Hyperbola& object);				// ������������� �������� ������������
};
#endif // !_HYPERBOLA_H_