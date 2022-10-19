#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <exception>
using namespace std;
template <class T> //можно через указатель на базовый класс (шаблон более универсален)
class Keeper {
	T* ptr_mas; //Указатель на элементы
	int size; //Размер контейнера
public:
	Keeper();
	Keeper(const Keeper&);
	~Keeper();
	void addElement(int index); //Добавление элемента
	void deleteElement(int index); //Удаление элемента по индексу
	void writeToFile(string); //Запись в файл
	void readFromFile(string); //Чтение из файла
	void displayData(); //Вывод данных на экран
	void dataChange(int index); //Изменение данных
};
template<class T>
Keeper<T>::Keeper() {
	cout << "Вызван конструктор по умолчанию Keeper" << endl << endl;
	ptr_mas = nullptr;
	size = 0;
}
template<class T>
Keeper<T>::Keeper(const Keeper& other) {
	this->ptr_mas = new T[other.size]; //Создаем массив в новом объекте
	this->size = other.size; //Копируем размер
	for (int i = 0; i < size; ++i) //Копируем каждый элемент в новый объект
		this->ptr_mas[i] = other.ptr_mas[i];
}
template<class T>
Keeper<T>::~Keeper() {
	cout << "Вызван деструктор Keeper" << endl << endl;
	delete[] ptr_mas;
}
template<class T>
void Keeper<T>::addElement(int index) {
	try {
		if (index < 0 || index > size)
			throw exception("Некорректный индекс!");
		T* tmp = new T[size + 1]; //Создаем новый массив на один элемент больше Вызывается Конструктор (Edition и Poet) столько раз, какой у нас размер будущего массива
		int j = 0;
		for (int i = 0; i < size; ++i) { //Копируем все элементы в новый массив
			if (index == i) //Если индекс равен введенному значению, то пропускаем это элемент в новом массиве
				j++;
			tmp[j++] = ptr_mas[i]; //сначала элемент переписывается потом индекс увеличивается
		}
		delete[] ptr_mas; //Удаляем старый массив Вызыываются деструкторы Edition и Poet столько раз, сколько элементов в существующем массиве
		ptr_mas = tmp; //ptr указывает на новый		массив
			cin >> ptr_mas[index]; //Вводим данные добавленного	элемента, который находится под индексом index
			++size; //Увеличиваем размер контейнера
			cout << endl << "Новый элемент успешно добавлен" << endl << endl;
	}
	catch (exception& ex) {
		cout << ex.what() << endl << endl;
	}
}
template<class T>
void Keeper<T>::deleteElement(int index) {
	try {
		if (size == 0) { //Пуст ли контейнер
			exception ex("Данных нет! Нечего удалять!");
			throw ex;
		}
		if (index < 0 || index >= size) { //Корректен ли индекс
			exception ex("Некоректный индекс!");
			throw ex;
		}
		T* tmp = new T[size - 1]; //Создаем новый массив на один элемент меньше Вызывается конструктор Edition и Poet столько раз, сколько в массиве -1
			int j = 0;
		for (int i = 0; i < size; ++i) { //Копируем все элементы, кроме удаляемого
			if (index != i)
				tmp[j++] = ptr_mas[i];
		}
		delete[] ptr_mas; //Удаляем старый массив Вызывается деструктор Poet и Edition
		ptr_mas = tmp; //ptr указывает на новый	массив
			--size; //Размер контейнера уменьшился
			cout << endl << endl << "Элемент удален" << endl << endl;
	}
	catch (exception& ex) {
		cout << ex.what() << endl << endl; //Вывод ошибки на экран
	}
}
template<class T>
void Keeper<T>::writeToFile(string s) {
	try {
		ofstream fout(s, ios::out);
		if (!fout) {
			exception ex("Не удалось открыть файл!");
			throw ex;
		}
		if (size == 0) { // если в программе нет данных для записи в файл
			exception ex("Данных для записи нет!");
			throw ex;
		}
		fout << size << endl; //Запись размера	контейнера
			for (int i = 0; i < size; ++i) { //Запись всех элементов контейнера
				fout << ptr_mas[i] << endl;
			}
		fout.close();
		cout << "Запись в файл прошла успешно" << endl << endl;
	}
	catch (exception& ex) {
		cout << ex.what() << endl;
	}
}
template<class T>
void Keeper<T>::readFromFile(string s) {
	try {
		ifstream fin(s, ios::in);
		if (!fin) {
			exception ex("Не удалось открыть файл!");
			throw ex;
		}
		delete[] ptr_mas; //Очищаем массив, так как	будут записаны данные из файла
			fin >> size; //Считываем размер контейнера в файле
			ptr_mas = new T[size]; //Создаем массив	размером контейнера в файле
			for (int i = 0; i < size; ++i) { //Считываем все элементы из файла
				fin >> ptr_mas[i];
			}
		fin.close();
		cout << "Чтение из файла прошло успешно" << endl << endl;
	}
	catch (exception& ex) {
		cout << ex.what() << endl;
	}
}
template<class T>
void Keeper<T>::displayData() {
	if (size == 0) { //Если контейнер пуст
		cout << "Данных нет!" << endl << endl;
	}
	else {
		for (int i = 0; i < size; ++i) { //Выводи все элементы контейнера на экран
			cout << ptr_mas[i] << endl;
		}
	}
}
template<class T>
void Keeper<T>::dataChange(int id) {
	try {
		if (size == 0) { //Если контейнер пуст
			exception ex("Данных нет!");
			throw ex;
		}
		if (id < 0 || id >= size) { //Некорректный индекс
			exception ex("Некорректный индекс!");
			throw ex;
		}
		cin >> ptr_mas[id]; //Вводим новые данные выбранного элемента
	}
	catch (exception& ex) {
		cout << ex.what() << endl << endl; //Вывод ошибки на экран
	}
}