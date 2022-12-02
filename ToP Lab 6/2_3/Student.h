#pragma once
#include "Disciplines.h"
class Student { 
	string surname; 
	string initials;
	string group; 
	Disciplines* head_disciplines; 
	int number_of_disciplines; 
	double average_mark; 
	Student* next_student;
public:
	Student(); 
	Student(string, string, string, Disciplines*);
	~Student();// деструктор
	void set_next_student(Student* next_student) {
		this->next_student = next_student; 
	} 
	Student* get_next_student() { 
		return next_student; 
	} 
	string get_surname() { 
		return surname;
	} 
	string get_initials() {
		return initials; 
	}
	string get_group() { 
		return group; 
	} 
	Disciplines* get_head_disciplines() { 
		return head_disciplines;
	}
	double get_average_mark() {
		return average_mark; 
	} 
	void push_disciplines(); 
	void delete_disciplines(string); 
	void show_data(); // вывод даннвых
	void change_data(); // изменение данных
	void average_score(); //  средний балл
	bool find_mark_two();}; // поиск оценки 2