#include "Q1.h"
#include "Q2.h"
#include "Q3.h"
using namespace std;
int main() {
	setlocale(LC_ALL, "ru");
	int choice;

	cout << "Выберите тип наследования" << endl << "1 - Public" << endl << "2 - Protected" << endl
		<< "3 - Private" << endl;

	Q1 queue = Q1();

	while (1) {

		system("cls");
		cout << "1 - Добавление нового элемента" << endl << "2 - Извлечение выбранного элемента " << endl
			<< "3 - Вывод очереди на экран" << endl << "4 - Вычисление искомого значения" << endl
			<< "5 - Создание копии очереди" << endl << "6 - Слияние очередей" << endl
			<< "7 - Выход из программы" << endl;
		cin >> choice;
		system("cls");
		switch (choice) {
		case 1:
			int elem;
			cout << "Введите новый элемент" << endl;
			cin >> elem;
			queue.push(elem);
			cout << "Элемент " << elem << " введен" << endl;
			system("pause");
			break;
		case 2:
			cout << "Элемент извлечен " << queue.pop() << endl;
			system("pause");
			break;
		case 3:
			queue.Qprint();
			system("pause");
			break;
		case 4:
			cout << "Размах равен " << queue.fun() << endl;
			system("pause");
			break;
		case 5:
			cout << "Очередь скопирована" << endl;
			queue.copy();
			system("pause");
			break;
		case 6:
			Q * a = queue.copy();
			Q* b = queue.copy();
			queue.merge(a, b);
			system("pause");
			break;
		}
		if (choice == 7)
			break;
	}
}