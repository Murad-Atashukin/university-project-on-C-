#ifndef _REAL_H_     /*���������, ������� ��������
�� ���������� ��������� ������������ ������, ����� �� ���� ��������������� ����� � ��� �� �������/�������.*/
#define _REAL_H_

#include "Library.h"

class Real
{
private:
	double value;

public:
	Real();
	Real(double value);

	void show();
	double GetValue();
	void SetValue(double value);
	double operator++();
	double operator--();

	friend double operator++(Real& object, int x);
	friend double operator--(Real& object, int x);

};

double operator++(Real& object, int x);
double operator--(Real& object, int x);
#endif // !_REAL_H_