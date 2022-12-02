#include "Second_task.h"
using namespace std;
int second_task() {
	string buffer;
	bool flag_sentence = false;
	char prev;
	system("pause");
	cout << endl;
	system("cls");
	try {
		ifstream fin("Text.txt", ios::in);
		if (!fin)
			throw exception("ERROR: Can't open file!");
		while (!fin.eof()) { 
			getline(fin, buffer);
			if (buffer.length() == 0)
				continue;
			buffer.resize(buffer.length() + 1); //Resize () изменяет размер одномерного массива Статический метод.
			prev = ' ';
			//Предыдущий символ строки
			for (int i = 0; i < buffer.length() - 2; ++i) {
				if (prev == ' ' && buffer[i] > '0' && buffer[i] <= '9' && buffer[i +
					1] >= '0' && buffer[i + 1] <= '9' && (buffer[i + 2] == ' ' || buffer[i + 2] == '\0' || buffer[i + 2] ==
						'.' || buffer[i + 2] == ',')) {
					flag_sentence = true;
					cout << buffer << endl << endl;
					break;
				}
				prev = buffer[i];
			}
		}
		if (!flag_sentence)
			cout << "No granted strings!" << endl << endl;
	}
	catch (exception& ex) {
		cout << ex.what() << endl << endl;
	}
	system("pause");
	return 0;
}