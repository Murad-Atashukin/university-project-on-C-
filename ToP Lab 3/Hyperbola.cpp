#include "Hyperbola.h"

Hyperbola::Hyperbola()														// Конструктор без параметров
{
	a = 0;																	// Обнуляем все поля
	b = 0;
}

Hyperbola::Hyperbola(double a, double b, double x)							// Конструктор с параметрами
{																			// Если не использовать ключ. слово this, то компилятор поймёт это так
																			// Передаваемому параметру x присвоить значение передаваемого параметра x
																			// (Это будет так, если имена совпадают, в ином случае можно обойтись обычным присваиванием без this)
	this->x = x;															// Полю нашего объекта присваиваем полученные данные
	this->a = a;
	this->b = b;
}

Hyperbola::Hyperbola(const Hyperbola& object)								// Конструктор копирования
{
	this->a = object.a;
	this->b = object.b;
	this->x = object.x;
}

void Hyperbola::print()														// Метод print()
{
	std::cout << "При a = " << a << ", b = " << b << " и x = " << x << " [ Y = " << function_for_y() << " ]" << std::endl;
}

double Hyperbola::function_for_y()											// Метод function_for_y()
{
	return sqrt((pow(a, 2) * pow(b, 2) + pow(x, 2) * pow(b, 2)) / pow(a, 2));
}

Hyperbola& Hyperbola::operator=(const Hyperbola& object)					// Перегруженный оператор =
{
	this->a = object.a;
	this->b = object.b;
	this->x = object.x;
	return *this;
}
