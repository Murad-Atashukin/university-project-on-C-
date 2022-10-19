#include "Fantasist.h"
Fantasist::Fantasist() {
	cout << "Вызван конструктор Fantasist" << endl << endl;
	FIO = "NaN";
	films = "NaN";
	head = NULL;
	countArtworks = 0;
}
Fantasist::Fantasist(const Fantasist& other) {
	cout << "Вызван конструктор копирования Fantasist" << endl << endl;
	this->countArtworks = 0;
	*this = other;
}
Fantasist::~Fantasist() {
	cout << "Вызван деструктор Fantasist" << endl << endl;
	Artworks* current = head;
	for (int i = 0; i < countArtworks; ++i) {
		head = head->nextArtworks;
		delete current;
		current = head;
	}
}
ofstream& operator<<(ofstream& fout, Fantasist& obj) {
	fout << obj.FIO << " " << obj.films << " " << obj.countArtworks << endl;
	Artworks* current = obj.head;
	for (int i = 0; i < obj.countArtworks; ++i) {
		fout << current->name << " ";
		current = current->nextArtworks;
	}
	return fout;
}
ifstream& operator >> (ifstream& fin, Fantasist& obj) {
	int count;
	fin >> obj.FIO >> obj.films >> count;
	string name;
	for (int i = 0; i < count; ++i) {
		fin >> name;
		obj.addArtworks(name);
	}
	return fin;
}
ostream& operator<<(ostream& out, Fantasist& obj) {
	out << "ФИО: " << obj.FIO << endl;
	out << "Фильмы по книгам: " << obj.films << endl;
	out << "Количество произведений: " << obj.countArtworks << endl;
	Artworks* current = obj.head;
	for (int i = 0; i < obj.countArtworks; ++i) {
		out << "Произведение " << i + 1 << " : " << current->name << endl;
		current = current->nextArtworks;
	}
	out << "--------------------------------------------------------------------------------";
	return out;
}
istream& operator >> (istream& in, Fantasist& obj) {
	cout << "Введите данные" << endl << endl;
	cout << "ФИО: ";
	cin >> obj.FIO;
	cout << "Есть ли фильмы по книгам: ";
	cin >> obj.films;
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
Fantasist& Fantasist::operator=(const Fantasist& other) {
	this->FIO = other.FIO;
	this->films = other.films;
	Artworks* current = this->head;
	for (int i = 0; i < this->countArtworks; ++i) {
		head = head->nextArtworks;
		delete current;
		current = head;
	}
	this->countArtworks = 0;
	current = other.head;
	for (int i = 0; i < other.countArtworks; ++i) {
		this->addArtworks(current->name);
		current = current->nextArtworks;
	}
	return *this;
}