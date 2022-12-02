#include "Student.h"
Student::Student() {
	cout << "Student class has been constructed" << endl << endl; // класс студент был построен
	cout << "Enter Surname: " << endl << ">"; // фамилия
	cin >> surname;
	cout << "Введите инициалы: "<< endl << ">";
	cin >> initials;
	cout << "Введите номер группы: " << endl << ">";
	cin >> group;
	number_of_disciplines = 0;
	average_mark = 0;
	head_disciplines = nullptr;
	next_student = nullptr;
}
Student::Student(string surname, string initials, string group, Disciplines* head_disciplines) {
	cout << "Student class has been constructed" << endl << endl; // класс студент был построен
	this->surname = surname;
	this->initials = initials;
	this->group = group;
	Disciplines* cur = head_disciplines;
	while (cur != NULL) {
			Disciplines* tmp = new Disciplines(cur->name, cur->mark);
			tmp->next_disciplines = nullptr;
		if (this->head_disciplines == nullptr) { //Если	первый элемент
				this->head_disciplines = tmp;
		}
		else {
			//Ищем конец списка и добавляем новый элемент туда
			Disciplines* current = this->head_disciplines;
			for (int i = 1; i < this->number_of_disciplines; ++i) {
				current = current->next_disciplines;
			}
			current->next_disciplines = tmp;
		}
		++this->number_of_disciplines;
		average_score(); //Пересчет среднего балла
		cur = cur->next_disciplines; //Передвигаем указатель во втором	списке
	}
}
Student::~Student() {
	cout << "Student class has been destructed" << endl << endl;
	Disciplines* current;
	for (int i = 0; i < number_of_disciplines; ++i) {
		current = head_disciplines;
		//Запоминаем первый элемент
		head_disciplines = head_disciplines->next_disciplines; //Переносим	указатель на начало списка на второй элемент
			delete current;
		//Удаляем первый элемент
	}
}
//Аналогично тому, как было в конструкторе с параметром, только ввод данных склавиатуры
void Student::push_disciplines() {
	Disciplines* tmp = new Disciplines;
	system("cls");
	cout << "Enter discipline: " << endl << ">";
	cin >> tmp->name;
	while (true) {
		cout << "Enter mark: ";
		cin >> tmp->mark;
		//Проверка на ввод букв вместо цифр
		if (cin.fail()) {
			cout << "ERROR: incorrect input!" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			continue;
		}
		//Проверка на вхождение в нужный диапозон (оценки могут быть: 2, 3, 4, 5)
		if (tmp->mark < 2 || tmp->mark > 5)
			cout << "ERROR: incorrect mark (2-5 needed)" << endl;
		else
			break; //Если все корректно введено, завершаем работу цикла по	вводу оценки
	}
	tmp->next_disciplines = nullptr;
	if (head_disciplines == nullptr) {
		head_disciplines = tmp;
	}
	else {
		Disciplines* current = head_disciplines;
		for (int i = 1; i < number_of_disciplines; ++i) {
			current = current->next_disciplines;
		}
		current->next_disciplines = tmp;
	}
	++number_of_disciplines;
	average_score();
	cout << "Discipline has been successfully added!" << endl << endl;
	system("pause");
}
void Student::delete_disciplines(string name) {
	Disciplines* current = head_disciplines;
	Disciplines* prev = head_disciplines;
	for (int i = 0; i < number_of_disciplines; ++i) {
		if (current->name == name) {
			//Ищем дисциплину с нужным названием
			if (current == head_disciplines) {
				//Если первый элемент
				head_disciplines = head_disciplines->next_disciplines;
				//Переносим начало на второй элемент
				delete current;
				//Удаляем певый элемент
			}
			else {
				prev->next_disciplines = current->next_disciplines;
				delete current;
			}
			--number_of_disciplines;
			cout << "Discipline has been removed!" << endl << endl;
			average_score();
			//Перерасчет среднего балла
			break;
		}
		if (i == number_of_disciplines - 1)
			cout << "ERROR: Wrong discipline!" << endl << endl;
		prev = current;
		current = current->next_disciplines;
	}
	system("pause");
}
void Student::show_data() {
	cout << "Surname and initials: " << surname << " " << initials << endl;
	cout << endl << "Group №: " << group;
	cout << endl << "Disciplines and marks" << endl;
	if (number_of_disciplines == 0)
		cout << "Empty disciplines list" << endl;
	else {
		Disciplines* current = head_disciplines;
		for (int i = 0; i < number_of_disciplines; ++i) {
			cout << current->name << " - " << current->mark << endl;
			current = current->next_disciplines;
		}
	}
	cout << endl << "Average score: " << average_mark << endl;
}
void Student::change_data() {
	int button;
	string name;
	bool flag = true;
	while (flag) {
		system("cls");
		show_data();
		cout << endl << "Choose what you want to change" << endl << endl;
		cout << "1: \tSurname" << endl;
		cout << "2: \tInitials" << endl;
		cout << "3: \tNumber of group" << endl;
		cout << "4: \tAdd discipline" << endl;
		cout << "5: \tRemove discipline" << endl;
		cout << "6: \tShow information" << endl;
		cout << "0: \tExit" << endl;
		cin >> button;
		if (cin.fail()) {
			button = -1;
			cin.clear();
			cin.ignore(10000, '\n');
		}
		switch (button) {
		case 1:
			cout << endl << "Enter new surname: " << endl << ">";
			cin >> surname;
			cout << endl << "Surname has been successfully changed!" << endl << endl;
			system("pause");
			break;
		case 2:
			cout << endl << "Enter new initials: " << endl << ">";
			cin >> initials;
			cout << endl << "Initials has been successfully changed!" << endl << endl;
			system("pause");
			break;
		case 3:
			cout << endl << "Enter new group number: " << endl << ">";
			cin >> group;
			cout << endl << "Group number has been successfully changed!" << endl << endl;
			system("pause");
			break;
		case 4:
			push_disciplines();
			break;
		case 5:
			cout << "Enter discipline: " << endl << ">";
			cin >> name;
			delete_disciplines(name);
			break;
		case 6:
			system("cls");
			show_data();
			system("pause");
			break;
		case 0:
			flag = false;
			break;
		default:
			cout << "ERROR: incorrect command" << endl << endl;
			system("pause");
		}
	}
}
bool Student::find_mark_two() {
	Disciplines* current = head_disciplines;
	for (int i = 0; i < number_of_disciplines; ++i) {
		if (current->mark == 2)
			return true;
		current = current->next_disciplines;
	}
	return false;
}
void Student::average_score() { //средний балл
	Disciplines* current = head_disciplines;
	int sum = 0;
	for (int i = 0; i < number_of_disciplines; ++i) {
		sum += current->mark;
		current = current->next_disciplines;
	}
	average_mark = static_cast<double>(sum) / number_of_disciplines;
}