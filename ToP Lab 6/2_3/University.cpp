#include "University.h"
University::University() {
	cout << "University class has been constructed" << endl << endl;
	head_student = nullptr;
	number_of_student = 0;
}
University::University(const University& other) {
	cout << "University class has been copied" << endl << endl;
	Student* cur = other.head_student;
	for (int i = 0; i < other.number_of_student; ++i) {
			Student* tmp = new Student(cur->get_surname(), cur->get_initials(), cur->get_group(), cur->get_head_disciplines());
		++this->number_of_student;
		
		if (this->head_student == nullptr) {
			this->head_student = tmp;
		}
		else {
			tmp->set_next_student(this->head_student); 
				this->head_student = tmp; 
		}
		cur = cur->get_next_student();
	}
}
University::~University() {
	cout << "University class has been destructed" << endl << endl;
	Student* current;
	for (int i = 0; i < number_of_student; ++i) {
		current = head_student;
		head_student = head_student->get_next_student();
		delete current;
	}
}
istream& operator >> (istream& in, University& obj) {
	system("cls");
	Student* tmp = new Student; 
		++obj.number_of_student; 
		if (obj.head_student == nullptr) { 
				obj.head_student = tmp;
		}
		else {
			tmp->set_next_student(obj.head_student); //Следующим становится	первый элемент
				obj.head_student = tmp; //Новый	первый элемент
		}
		cout << "Student has been added!" << endl << endl;
		system("pause");
		return in;
}
ostream& operator<<(ostream& out, University& obj) {
	Student* current = obj.head_student; //указатель на голову
	try {
		if (obj.number_of_student == 0)
			throw exception("Empty students list!");
		for (int i = 0; i < obj.number_of_student; ++i) {
			current->show_data(); //вывод данных
			out << "------------------------------------------------------" << endl;
			current = current->get_next_student();//переход на след студента
		}
	}
	catch (exception& ex) {
		out << ex.what() << endl << endl;
	}
	return out;
}
void University::delete_student() {
	system("cls");
	try {
		if (get_number_of_student() == 0)
			throw exception("Empty students list!");
		string surname;
		string initials;
		cout << "Enter surname: " << endl << ">";
		//Ввод фамилии студента
		cin >> surname;
		cout << "Enter initials: " << endl << ">";
		//Ввод инициалов студента
		cin >> initials;
		Student* current = head_student;
		//Указатель на текущий элемент
		Student* prev = head_student;
		//Указатель на предыдущий элемент
		for (int i = 0; i < number_of_student; ++i) {
			if (current->get_surname() == surname && current->get_initials() ==
				initials) { //Ищем подходящего студента
				if (current == head_student) {
					//Если удаляемый элемент первый
					head_student = head_student->get_next_student();
					//Передвигаем указатель на начало списка на второй	элемент
						delete current;
					//Удаляем первый элемент
					--number_of_student;
					//Уменьшаем количество элементов
				}
				else {
					//Если не первый
					prev->set_next_student(current->get_next_student());
					//Предыдущий указываетн на следующий элемент
					delete current;
					//Удаляем текущий элемент
					--number_of_student;
					//Уменьшаем количество элементов
				}
				cout << "Student has been removed!" << endl << endl;
				break;
				//Если нашли и	удалили, то искать дальше нет смысла
			}
			if (i == number_of_student - 1)
				//Если мы дошли до последнего	элемента, но так и не нашли нужного студента
				cout << "ERROR: can't find student!" << endl << endl;
			prev = current;
			//Запоминаем элемент как предыдущий
				current = current->get_next_student();
			//Передвигаем указатель
		}
		system("pause");
	}
	catch (exception& ex) {
		system("cls");
		cout << ex.what() << endl << endl;
		system("pause");
	}
}
void University::show_student_two() {
	system("cls");
	Student* current = head_student;
	bool flag = false; //Флаг для определения нахождения нужного нам студента
		cout << "List of students with mark 2" << endl << endl;
	try {
		if (number_of_student == 0)
			throw exception("Empty students list!");
		for (int i = 0; i < number_of_student; ++i) {
			if (current->find_mark_two()) {
				flag = true;
				current->show_data();
				cout << "------------------------------------------------------" << endl <<
					endl;
			}
			current = current->get_next_student();
		}
		if (!flag) //Если нужного студента	нет, то выводим об этом сообщение
			cout << "No students with mark 2!" << endl << endl;
	}
	catch (exception& ex) {
		cout << ex.what() << endl << endl;
	}
	system("pause");
}
void University::sort_student() { //алгоритм сортировка, сложность n^2
	for (int i = 0; i < number_of_student - 1; ++i) {
		Student* current = head_student;
		//Текущий элемент
		Student* prev = head_student;
		//Предыдущий элемент
		while (current->get_next_student() != nullptr) {
			//Идем, пока существует следующий элемент
			if (current->get_average_mark() > current->get_next_student()->get_average_mark()) { //Сравнение среднего балла
				Student* next = current->get_next_student();
				//Следующий элемент
				if (current == head_student) {
					//Если текущий элемент первый
					head_student = next;
					//Начало списка теперь второй элемент
					current->set_next_student(next->get_next_student());
					//Первый элемент теперm указывает на третий элемент
					next->set_next_student(current);
					//Второй элемент теперь указывает на первый элемент
					current = head_student; //Сохраняем позицию указателя чтобы после сравнения 1 и 2, мы сравнили 2 и 3
				}
				else {
					prev->set_next_student(next);
					//Предыдущий указывает на следующий элемент
					current->set_next_student(next->get_next_student());
					//Текущий указывает на элемент после следующго
					next->set_next_student(current);
					//Следующий указывает на текущий элемент
					current = next;
					// Сохраняем позицию указателя (на элемент назад сдвигаем)
				}
			}
			prev = current;
			//Иначе просто передвигаем указатели
			current = current->get_next_student();
		}
	}
}
//Ищем студента, если находим, то возвращаем указатель на него
Student* University::find_student(string surname, string initials) {
	Student* current = head_student;
	for (int i = 0; i < number_of_student; ++i) {
		if (current->get_surname() == surname && current->get_initials() == initials)
			return current; //Возвращаем указатель,	функция заканчивается
			current = current->get_next_student();
	}
	return nullptr;
}