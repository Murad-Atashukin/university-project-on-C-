#pragma once
#include "Edition.h"
class Romanticist : public Edition {
	string years_of_life;
	string biography; //Следует писать без пробелов (пробелы можно 	заменить на нижнее подчеркивание "_")
public:
	Romanticist();
	Romanticist(const Romanticist& other);
	~Romanticist();
	void setFIO(string FIO) override { this->FIO = FIO; }
	string getFIO() override { return FIO; }
	friend ofstream& operator << (ofstream& fout, Romanticist& obj);
	friend ifstream& operator >> (ifstream& fin, Romanticist& obj);
	friend ostream& operator << (ostream& out, Romanticist& obj);
	friend istream& operator >> (istream& in, Romanticist& obj);
	Romanticist& operator =(const Romanticist& other);
};