#pragma once
#include "Keeper.h"
#include "Poet.h"
#include "Fantasist.h"
#include "Romanticist.h"
#include <iostream>
using namespace std; /*сообщает компилятору, что мы хотим использовать всё, что находится в пространстве имен std,
					 так что,если компилятор найдет имя, которое не сможет распознать, он будет проверять
					 его наличие в пространстве имен std*/
template <typename T>
void menuOfEdition(T& obj, string s) { //передаем строчку, которая содержит в себе имя файла (ориентир на нужный файл)
	int button;
	int id;
	bool flag = true;
	while (flag) {
		system("cls");
		cout << "Выберите действие: " << endl << endl;
		cout << "1 - Добавить объект" << endl;
		cout << "2 - Удалить объект" << endl;
		cout << "3 - Вывод данных из объектов" << endl;
		cout << "4 - Изменение данных" << endl;
		cout << "5 - Сохранение в файл" << endl;
		cout << "6 - Восстонавление из файла" << endl;
		cout << "0 - Выход в основное меню" << endl << endl;
		cout << "Выберите команду: ";
		cin >> button;
		if (cin.fail()) {
			button = -1;
			cin.clear();
			cin.ignore(10000, '\n');
		}
		system("cls");
		switch (button) {
		case 1: obj.displayData(); cout << "На какое место вставить новый элемент: "; cin >> id;
			obj.addElement(id); system("pause"); break;
		case 2: obj.displayData(); cout << "Какой элемент удалить: "; cin >> id; obj.deleteElement(id);
			system("pause"); break;
		case 3: obj.displayData(); system("pause"); break;
		case 4: obj.displayData(); cout << "Какой элемент изменить: "; cin >> id; obj.dataChange(id);
			system("pause"); break;
		case 5: obj.writeToFile(s); system("pause"); break;
		case 6: obj.readFromFile(s); system("pause"); break;
		case 0: flag = false; break;
		default: cout << "Введена некорректная команда!" << endl << endl; system("pause"); break;
		}
	}
}