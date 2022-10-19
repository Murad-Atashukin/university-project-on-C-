#include "Romanticist.h"
Romanticist::Romanticist() {
	cout << "Вызван конструктор Romanticist" << endl << endl;
	FIO = "NaN";
	biography = "NaN";
	years_of_life = "NaN";
	head = NULL;
	countArtworks = 0;
}
Romanticist::Romanticist(const Romanticist& other) {
	cout << "Вызван конструктор копирования Romanticist" << endl << endl;
	this->countArtworks = 0;
	*this = other;
}
Romanticist::~Romanticist() {
	cout << "Вызван деструктор Romanticist" << endl << endl;
	Artworks* current = head;
	for (int i = 0; i < countArtworks; ++i) {
		head = head->nextArtworks;
		delete current;
		current = head;
	}
}
ofstream& operator<<(ofstream& fout, Romanticist& obj) { //переггрузка запись в файл (перегружается в	каждом классе наследнике)
	fout << obj.FIO << " " << obj.years_of_life << " " << obj.biography << " " << obj.countArtworks << endl;
	Artworks* current = obj.head;
	for (int i = 0; i < obj.countArtworks; ++i) {
		fout << current->name << " ";
		current = current->nextArtworks;
	}
	return fout;
}
ifstream& operator >> (ifstream& fin, Romanticist& obj) { //перегрузка чтения из файла
	int count;
	fin >> obj.FIO >> obj.years_of_life >> obj.biography >> count;
	string name;
	for (int i = 0; i < count; ++i) {
		fin >> name;
		obj.addArtworks(name);
	}
	return fin;
}
ostream& operator<<(ostream& out, Romanticist& obj) { //перегрузка вывода на консоль
	out << "ФИО: " << obj.FIO << endl;
	out << "Годы жизни: " << obj.years_of_life << endl;
	out << "Краткая биография: " << obj.biography << endl;
	out << "Количество произведений: " << obj.countArtworks << endl;
	Artworks* current = obj.head;
	for (int i = 0; i < obj.countArtworks; ++i) {
		out << "Произведение " << i + 1 << " : " << current->name << endl;
		current = current->nextArtworks;
	}
	out << "--------------------------------------------------------------------------------";
	return out;
}
istream& operator >> (istream& in, Romanticist& obj) { //перегрузка чтения с клавиатуры
	cout << "Введите данные" << endl << endl;
	cout << "ФИО: ";
	cin >> obj.FIO;
	cout << "Годы жизни: ";
	cin >> obj.years_of_life;
	cout << "Краткую биографию: ";
	cin >> obj.biography;
	Artworks* current = obj.head;
	for (int i = 0; i < obj.countArtworks; ++i) {
		obj.head = obj.head->nextArtworks;
		delete current;
		current = obj.head;
	}
	obj.countArtworks = 0;
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
Romanticist& Romanticist::operator=(const Romanticist& other) { //перегрузка оператора присваивания
	this->FIO = other.FIO;
	this->years_of_life = other.years_of_life;
	this->biography = other.biography;
	Artworks* current = this->head; //указатель на список произведений объекта a (удаление списка	произв)
	for (int i = 0; i < this->countArtworks; ++i) {
		head = head->nextArtworks;
		delete current;
		current = head;
	}
	this->countArtworks = 0; //обнуляем список
	current = other.head;
	for (int i = 0; i < other.countArtworks; ++i) {
		this->addArtworks(current->name);
		current = current->nextArtworks;
	}
	return *this;
}