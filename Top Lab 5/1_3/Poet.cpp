#include "Poet.h"
Poet::Poet() {
	cout << "Вызван конструктор Poet" << endl << endl;
	FIO = "NaN";
	years_of_life = "NaN";
	head = NULL;
	countArtworks = 0;
}
Poet::Poet(const Poet& other) {
	cout << "Вызван конструктор копирования Poet" << endl << endl;
	this->countArtworks = 0;
	*this = other;
}
Poet::~Poet() {
	cout << "Вызван деструктор Poet" << endl << endl;
	Artworks* current = head;
	for (int i = 0; i < countArtworks; ++i) { //Удаляем элементы, начиная с начала списка
		head = head->nextArtworks;
		delete current;
		current = head;
	}
}
//Для записи и чтения из файла необходимо соблюдать особый порядок:
//Первым в файле лежит общее количество элементов
//Далее идут простые данные (главное соблюдать порядок при записи и чтении)
//В данном случае сначала ФИО, потом Годы жизни
//После лежит количество произведений, а за ним и сами произведения
ofstream& operator<<(ofstream& fout, Poet& obj) {//вывод данных в файл
	fout << obj.FIO << " " << obj.years_of_life << " " << obj.countArtworks << endl;
	Artworks* current = obj.head;
	for (int i = 0; i < obj.countArtworks; ++i) {
		fout << current->name << " ";
		current = current->nextArtworks;
	}
	return fout;
}
ifstream& operator >> (ifstream& fin, Poet& obj) {//ввод данных из файла
	int count; //Переменная, чтобы знать, сколько произведений добавлять
	fin >> obj.FIO >> obj.years_of_life >> count;
	string name;
	for (int i = 0; i < count; ++i) {
		fin >> name; //Считываем название произведения
		obj.addArtworks(name); //Добавляем произведение (счетчик кол-ва произвдений		наращивается в этой функции)
	}
	return fin;
}
ostream& operator<<(ostream& out, Poet& obj) {//вывод данных в консоль
	out << "ФИО: " << obj.FIO << endl;
	out << "Годы жизни: " << obj.years_of_life << endl;
	out << "Количество произведений: " << obj.countArtworks << endl;
	Artworks* current = obj.head;
	for (int i = 0; i < obj.countArtworks; ++i) {
		out << "Произведение " << i + 1 << " : " << current->name << endl;
		current = current->nextArtworks;
	}
	out << "--------------------------------------------------------------------------------";
	return out;
}
istream& operator >> (istream& in, Poet& obj) {
	cout << "Введите данные" << endl << endl;
	cout << "ФИО: ";
	cin >> obj.FIO;
	cout << "Годы жизни: ";
	cin >> obj.years_of_life;
	/*Перед вводом новых произведений очищаем список произведений, которые могли там	присутствовать
		Artworks* current = obj.head;
	for (int i = 0; i < obj.countArtworks; ++i) {
		obj.head = obj.head->nextArtworks;
		delete current;
		current = obj.head;
	}*/
	obj.countArtworks = 0; //Обнуляем кол-во произведений
						   //Добавляем новые произведения
	string name;
	int count;
	cout << "Количество произведений: ";
	cin >> count;
	for (int i = 0; i < count; ++i) {
		cout << "Введите " << i + 1 << " произведение: ";
		cin >> name;
		obj.addArtworks(name);
	}
	return in;
}
Poet& Poet::operator=(const Poet& other) {
	this->FIO = other.FIO;
	this->years_of_life = other.years_of_life;
	//Очищаем список произведений у объекта слева от знака
	Artworks* current = this->head;
	for (int i = 0; i < this->countArtworks; ++i) {
		head = head->nextArtworks;
		delete current;
		current = head;
	}
	this->countArtworks = 0;
	//Копируем нужное кол-во произведений из объекта справа от знака
	current = other.head;
	for (int i = 0; i < other.countArtworks; ++i) {
		this->addArtworks(current->name);
		current = current->nextArtworks;
	}
	return *this;
}