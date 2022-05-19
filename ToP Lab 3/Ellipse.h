																// Условие ifndef необходимо для того, чтобы узнать, добавляли ли мы этот участок
#ifndef _ELLIPSE_H_												// кода в наш проект или нет. Если константа определена, то повторного добавления не будет
#define _ELLIPSE_H_												// Определяем константу 

#include "Curves.h"

class Ellipses : public Curves									// Публично наследуемся от абстрактного класса
{																// [При публичном наследовании никакие модификаторы доступа у методов и полей 
private:														// от базоваого класса не изменяются (public остается public и тд)]
	double a, b;												

public:
	Ellipses();													// Конструктор без параметров
	Ellipses(double a, double b, double x);						// Конструктор с параметрами
	Ellipses(const Ellipses& object);								// Конструктор копирования
	~Ellipses() {};												// Деструктор

	void print() override;										// Переопределённый метод print()
	double function_for_y() override;							// Переопределённый метод volume()
	Ellipses& operator=(const Ellipses& object);					// Перегруженный оператор присваивания
};
#endif // !_ELLIPSE_H_