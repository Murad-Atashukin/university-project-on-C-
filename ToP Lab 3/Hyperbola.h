// Условие ifndef необходимо для того, чтобы узнать, добавляли ли мы этот участок
#ifndef _HYPERBOLA_H_											// кода в наш проект или нет. Если константа определена, то повторного добавления не будет
#define _HYPERBOLA_H_											// Определяем константу 

#include "Curves.h"

class Hyperbola : public Curves									// Публично наследуемся от абстрактного класса
{																// [При публичном наследовании никакие модификаторы доступа у методов и полей 
private:														// от базоваого класса не изменяются (public остается public и тд)]
	double a, b;

public:
	Hyperbola();												// Конструктор без параметров
	Hyperbola(double a, double b, double x);					// Конструктор с параметрами
	Hyperbola(const Hyperbola& object);							// Конструктор копирования
	~Hyperbola() {};											// Деструктор

	void print() override;										// Переопределённый метод print()
	double function_for_y() override;							// Переопределённый метод volume()
	Hyperbola& operator=(const Hyperbola& object);				// Перегруженный оператор присваивания
};
#endif // !_HYPERBOLA_H_