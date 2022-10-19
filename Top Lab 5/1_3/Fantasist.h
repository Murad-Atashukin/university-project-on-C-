#pragma once
#include "Edition.h"
class Fantasist : public Edition {
	string films; //Есть или нет
public:
	Fantasist();
	Fantasist(const Fantasist& other);
	~Fantasist();
	void setFIO(string FIO) override { this->FIO = FIO; }
	string getFIO() override { return FIO; }
	friend ofstream& operator << (ofstream& fout, Fantasist& obj);
	friend ifstream& operator >> (ifstream& fin, Fantasist& obj);
	friend ostream& operator << (ostream& out, Fantasist& obj);
	friend istream& operator >> (istream& in, Fantasist& obj);
	Fantasist& operator =(const Fantasist& other);
};