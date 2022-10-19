#pragma once
#include "Edition.h"
class Poet : public Edition {
	string years_of_life; //Ïðèìåð êàê ââîäèòü (ÃËÀÂÍÎÅ ÁÅÇ ÏÐÎÁÅËÎÂ): 1999-2000
public:
	Poet();
	Poet(const Poet& other);
	~Poet();
	void setFIO(string FIO) override { this->FIO = FIO; }
	string getFIO() override { return FIO; }
	friend ofstream& operator << (ofstream& fout, Poet& obj);
	friend ifstream& operator >> (ifstream& fin, Poet& obj);
	friend ostream& operator << (ostream& out, Poet& obj);
	friend istream& operator >> (istream& in, Poet& obj);
	Poet& operator =(const Poet& other);
};