#include "Function.h"
int main() {
	setlocale(LC_ALL, "");
	Keeper<Poet> poet; //создание экземпляра класса (тип данных Poet), вызывается конструктор Keeper ()
	Keeper<Romanticist> romanticist;//создание экземпляра класса (тип данных romanticist), вызывается конструктор Keeper ()
	Keeper<Fantasist> fantasist;//создание экземпляра класса (тип данных fantasist), вызывается конструктор Keeper ()
	int button;
	bool flag = true;
	while (flag) {
		system("cls");
		cout << "Выберите писателя: " << endl << endl;
		cout << "1 - Поэт" << endl;
		cout << "2 - Романтист" << endl;
		cout << "3 - Фантаст" << endl;
		cout << "0 - Выход из программы" << endl << endl;
		cout << "Выберите команду: ";
		cin >> button;
		if (cin.fail()) {
			button = -1;
			cin.clear();
			cin.ignore(10000, '\n');
		}
		switch (button) {
		case 1: menuOfEdition(poet, "Poet.txt"); break; // шаблонная фция, поет - это и есть строчка
		case 2: menuOfEdition(romanticist, "Romanticist.txt"); break;
		case 3: menuOfEdition(fantasist, "Fantasist.txt"); break;
		case 0: flag = false; break;
		default: cout << endl << "Введена некорректная команда!" << endl << endl; system("pause");
			break;
		}
	}
	return 0;
}