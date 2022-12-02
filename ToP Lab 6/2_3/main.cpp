#include "University.h"
#include "Second_task.h"
#include <iostream>
#include <fstream>
#include <string>
#include <exception>
using namespace std;
int main() {

	setlocale(LC_ALL, "");
	University Univer; //объект университет
	Student *ptr; //указатель на студента
	string surname; //для поиска
	string initials;
	int choose; //выбор пользователя
	bool flag = true;
	while (flag) {

		system("cls");
		cout << "LAB № 2" << endl << endl ;
		cout << "Choose your option:" << endl;
		cout << "1: \tAdd new student (no marks)" << endl;
		cout << "2: \tRemove student" << endl;
		cout << "3: \tShow students" << endl;
		cout << "4: \tShow students with mark 2" << endl;
		cout << "5: \tAverage score sorting" << endl;
		cout << "6: \tEdit student (add disciplines and marks)" << endl;
		cout << "0: \tGo to second task ->" << endl;
		cout << ">";
		cin >> choose;
		if (cin.fail()) {
			choose = -1;
			cin.clear();
			cin.ignore(10000, '\n');
		}
		switch (choose) {
		case 1:
			cin >> Univer; //ввод студента
			break;
		case 2:
			Univer.delete_student();//удаление студента
			break;
		case 3:
			system("cls");
			cout << Univer; //вывод студента
			system("pause");
			break;
		case 4:
			Univer.show_student_two();//просмотр студента с 2
			break;
		case 5:
			system("cls");
			cout << "\t| Unsorted list |" << endl;
			cout << "\t-----------------" << endl << endl << Univer << endl << endl;
			Univer.sort_student(); //сортировка по сред баллу
			cout << "\t| Sorted list|" << endl;
			cout << "\t--------------" << endl << endl << Univer << endl << endl;
			system("pause");
			break;
		case 6:
			if (Univer.get_number_of_student() == 0) { //если нет студентов
				system("cls");
				cout << "Empty students list!" << endl << endl;
				system("pause");
			}
			else {//если есть студенты
				cout << "Enter surname: " << endl << ">";
				cin >> surname;
				cout << "Enter initials: "<< endl << ">";
				cin >> initials;
				ptr = Univer.find_student(surname, initials); //найти студента
				if (ptr == nullptr) {//если указатель пуст
					cout << "ERROR: Student not found!" << endl << endl;
					system("pause");
				}
				else {
					ptr->change_data(); //изменить данные студента по указателю 
				}
			}
			break;
		case 0:
			flag = false;
			break;
		default:
			cout << "ERROR: incorrect command" << endl << endl;
			system("pause");
		}
	}
	system("cls");
	cout << "Second task..." << endl << endl;
	second_task();

	return 0;
}
