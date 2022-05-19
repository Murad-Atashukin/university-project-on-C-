																// ������� ifndef ���������� ��� ����, ����� ������, ��������� �� �� ���� �������
#ifndef _ELLIPSE_H_												// ���� � ��� ������ ��� ���. ���� ��������� ����������, �� ���������� ���������� �� �����
#define _ELLIPSE_H_												// ���������� ��������� 

#include "Curves.h"

class Ellipses : public Curves									// �������� ����������� �� ������������ ������
{																// [��� ��������� ������������ ������� ������������ ������� � ������� � ����� 
private:														// �� ��������� ������ �� ���������� (public �������� public � ��)]
	double a, b;												

public:
	Ellipses();													// ����������� ��� ����������
	Ellipses(double a, double b, double x);						// ����������� � �����������
	Ellipses(const Ellipses& object);								// ����������� �����������
	~Ellipses() {};												// ����������

	void print() override;										// ��������������� ����� print()
	double function_for_y() override;							// ��������������� ����� volume()
	Ellipses& operator=(const Ellipses& object);					// ������������� �������� ������������
};
#endif // !_ELLIPSE_H_