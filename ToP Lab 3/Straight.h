															// ������� ifndef ���������� ��� ����, ����� ������, ��������� �� �� ���� �������
#ifndef _STRAIGHT_H_										// ���� � ��� ������ ��� ���. ���� ��������� ����������, �� ���������� ���������� �� �����
#define _STRAIGHT_H_										// ���������� ��������� 

#include "Curves.h"

class Straight : public Curves								// �������� ����������� �� ������������ ������
{															// [��� ��������� ������������ ������� ������������ ������� � ������� � ����� 
															// �� ��������� ������ �� ���������� (public �������� public � ��)]
private:
	double k, b;

public:
	Straight();												// ����������� ��� ����������
	Straight(double x, double k, double b);					// ����������� � �����������
	Straight(const Straight& object);						// ����������� �����������
	~Straight() {};											// ����������

	void print() override;									/* ��������������� ����� print(), ��� �� ������� �����������
- ��� ��� ������� � ������� ������� ����, ��� ����������. (�� ������ - ������ ������) 
��� ����� ����� ���������� �� ����� ������� � ������� ��������� �� ��� ����� ������� � ������ �� �����*/


	double function_for_y() override;						// ��������������� ����� volume()
	Straight& operator=(const Straight& object);			// ������������� �������� ������������
};
#endif // !_STRAIGHT_H_