#include "Hyperbola.h"
#include "Straight.h"
#include "Ellipse.h"

#include <fstream> /*fstream � ������������ ���� �� ����������� ���������� C++, ���������� ����� �������,
������� � �������, ������� ������������� ��������� ��� ������/������ ������ ��/� ����. 
��� ����������� � ������� ������ ������������ �������, ���������� �������� */
#include <string>
#include <conio.h>
#include <cstdint>																// ���������� � ������������� ��������� int
#include <typeinfo>
#include <Windows.h>

using namespace std;

void show(Curves** object, int16_t num_elem)									// ������� ������� ��� �������, ���������� � ������� ���������� �� ������� �����
{																				// �� ��� int �� ����� ����. ����������� (���-�� 2, ���-�� 4 �����),
																				// ����� ������������ ����. �� ����. stdint (�������� int16_t - ��� 2-�� �������� int)
	int16_t mode = 0;															// ��� �������
	int16_t count_elem = 0;														// ���������� ��������� ������������� ����
	string type[3] = { "������", "��������", "��������"};

	if (num_elem == 0)															// ���� ��� ���������
	{
		cout << "��� ����������� �����!" << endl;
		return;
	}

	for (int16_t i = 0; i < 3; i++, mode++)										// ���������� �� ������� 4 ����, �� � ��� 4 ������ ���� � ��� ��������
	{
		cout << "Y-�� " << type[i] << ":" << endl;
		for (int16_t j = 0; j < num_elem; j++)									// ������� ������
		{
			if (mode == 0)														// ���� ������ �� ���� ��� ������
			{
				if (typeid(*object[j]) == typeid(Straight))						// ���������� ��� i-�� ������� � ����� ������
				{
					object[j]->print();											// ���� ������� - �� �������
					count_elem++;
				}
			}
			else if (mode == 1)													// ���� ������ �� ���� ��� ��������
			{
				if (typeid(*object[j]) == typeid(Ellipses))						// ���������� ��� i-�� ������� � ����� ��������
				{
					object[j]->print();								
					count_elem++;
				}
			}
			else if (mode == 2)													// ���� ������ �� ���� ��� ��������
			{
				if (typeid(*object[j]) == typeid(Hyperbola))					// ���������� ��� i-�� ������� � ����� ��������
				{
					object[j]->print();
					count_elem++;
				}
			}
		}

		if (count_elem == 0)													// ���� �� ����������� �������� �������� ������� ����, �������
		{
			cout << "� ��� ��� " << type[i] << endl;
		}
		count_elem = 0;
		cout << endl;
	}
}

void write_to_file(Curves** object, int16_t num_elem, string path, int16_t mode)	// ������� ������ ��������� � ����
{
	ofstream fout;																// ������� ���������� ���������� ������
	fout.open(path);															// ��������� ����

	if (!fout.is_open())														// ���� ���� �������� � ������� ������� � ������
	{
		cout << "������ ��� �������� ����� �� ����" << path << endl;
		return;
	}

	for (int16_t i = 0; i < num_elem; i++)										// ����� ������� ������
	{
		if (mode == 0)															// ���� ������ �� ���� ��� ������ 
		{ 
			if (typeid(*object[i]) == typeid(Straight))							// ���������� ��� i-�� ������� � ����� ������
				fout.write((char*)&(*object[i]), sizeof(Straight));				// ��-������� ���������� � ���������� ���� Straight.txt
		}
		else if (mode == 1)														// ���������� � �������
		{
			if (typeid(*object[i]) == typeid(Ellipses))
				fout.write((char*)&(*object[i]), sizeof(Ellipses));
		}
		else if (mode == 2)
		{
			if (typeid(*object[i]) == typeid(Hyperbola))
				fout.write((char*)&(*object[i]), sizeof(Hyperbola));
		}
	}
	
	fout.close();																// ��������� ����
}

Curves** read_from_file(Curves** object, int16_t& num_elem, string path, int16_t mode)	// ������� ������ �� �����
{
	int16_t i, j;																		// ��������
	size_t size = 0;																	// ������ ���� �������
	ifstream fin;
	fin.open(path);																		// ��������� ����
	Curves** obj = new Curves *[num_elem + 1];											// ������� ������ ���������� �� ������� ����� �� 1 ��������

	if (!fin.is_open())																	// ���� ���� �� ��������
	{
		cout << "������ ��� �������� ����� �� ����" << path << endl;					// ������� ������, ������� ������ ���������� � ������
		delete[] obj;
		return object;
	}

	for (i = 0; i < num_elem; i++)														// ����� �������� ��� �������� �� ����� ��������
	{																					// � �����
		obj[i] = object[i];
	}

	if (mode == 0) { obj[i] = new Straight; size = sizeof(Straight); }					// ������� ������ ������� ����, �������� �� ����,
	else if (mode == 1) { obj[i] = new Ellipses; size = sizeof(Ellipses); }				// � �������� ������������ ����������. (������ ���� 
	else if (mode == 2) { obj[i] = new Hyperbola; size = sizeof(Hyperbola); }			// �������� � ������ ������. �������� ��� Straight 
																						// �������� � Straight.txt � ��)

	while (fin.read((char*)&(*obj[i]), size))											// ��-������� ��������� (����� read, ���������� 
	{																					// true, ���� ������� �������, � false, ���� ���)
		if (object != nullptr)															// �������� �������� ������
		{
			delete[] object;
		}

		object = obj;																	// ����� ���������� �������� �������� 
		num_elem++;																		// ����������� ���. ��������� � ������� ����� �����
 		obj = new Curves * [num_elem + 1];

		for (i = 0; i < num_elem; i++)													// �������� ��� ��������� �� ��������� � ����� �����
		{
			obj[i] = object[i];
		}
		
		if (mode == 0) { obj[i] = new Straight; }											// ������� ������ ������� ����, �������� �� ����(�� ����)
		else if (mode == 1) { obj[i] = new Ellipses; }
		else if (mode == 2) { obj[i] = new Hyperbola; }
	}

	delete[] obj;																		// �������� �����

	//show(object, num_elem);

	fin.close();																		// ��������� ����
	return object;																		// ���������� �������� ������
}

int main()
{
	int16_t i;
	bool exit = 1;																		// ����� ��� ������������ ����
	char choice = 0;																	// �����
	double x, a, b, k;
	string path[3] = { "Straight.txt", "Ellipses.txt", "Hyperbola.txt"};
																			// !#! -�� � ��������� �� ������� ����� ����� ��������
																			// ����� �� ������ ��� ���������� ��� ���������� �������
																			// ������� ���������� �� ������� ����� ��� �������� ���� �������
	Curves** line, **temp;															// ��������� �� ������� ���������� �� ������� �����
	int16_t num_elem;																	// ���. ���������
		
	num_elem = 0;
	line = nullptr;
	x = a = b = k = 0;

	SetConsoleCP(1251);																	// ������ ��������� �� ���������
	SetConsoleOutputCP(1251);

	while (exit)																		// ��������, ���� �����
	{
		cout << "����� ��������:\n1] �������� ������\n2] �������� ������\n3] �������� ���������\n"
			"4] ������� �� ����� ��� Y\n5] ������� � �����\n6] �������� � ����\n7] �����\n" << endl;
		cout << "|->> ";
		choice = _getch();																// ��������� �����

		switch (choice)
		{
		case '1':
			try
			{
				cout << "�������� ������" << endl;
				cout << "������� x: ";
				cin >> x;
				cin.ignore(32767, '\n');												// �������� ����� �� ������ ����������, ��������� �������������
																						// ��������, 1.2�, ������ "�" ��������� ������ � ������, � ������ ������ � ����������, ������� ��������
				if (cin.fail())															// ���� ������������ ��� �����, �� ����� ����� ����.								
				{
					throw "��������� ������ [x] �� �������� ������!";					// ������� ���������� � ��� � catch
				}

				cout << "������� k: ";
				cin >> k;
				cin.ignore(32767, '\n');
				if (cin.fail())
				{
					throw "��������� ������ [k] �� �������� ������!";
				}

				cout << "������� b: ";
				cin >> b;
				cin.ignore(32767, '\n');
				if (cin.fail())
				{
					throw "��������� ������ [b] �� �������� ������!";
				}

				num_elem++;																// ����������� ���. ��������� 
				if (num_elem == 1)														// ���� ��� ������ ������� � ����� �������, ��
				{
					line = new Curves * [num_elem];										// ������ ������ ��� ������ ������� ����
					line[0] = new Straight(x, k, b);									// �������� ���� ��������
				}

				else																	// � ���� ������
				{
					temp = new Curves * [num_elem];										// ������� ����� ������ ����������

					for (i = 0; i < num_elem - 1; i++)									// �������� ��������� �� �������
					{
						temp[i] = line[i];
					}

					temp[i] = new Straight(x, k, b);									// ��������� ����� �������
					delete[] line;														// ������� ������ ������
					line = temp;														// ��������� �� ������ ������ ������ ��������� �� �����
					temp = nullptr;
				}
			}
			catch (const char* exc)
			{
				cout << exc << endl;													// ������� ���������� 
				cin.clear();															// ���. ����� �����
				cin.ignore(32767, '\n');												// �������� ��� �����
			}
			

			system("pause");
			system("cls");
			break;

		case '2':
			try
			{
				cout << "�������� ������" << endl;									// �� ���������� (�� ����)
				cout << "������� x: ";
				cin >> x;
				cin.ignore(32767, '\n');
				if (cin.fail())
				{
					throw "��������� ������ [x] �� �������� ������!";
				}

				cout << "������� a: ";
				cin >> a;
				cin.ignore(32767, '\n');
				if (cin.fail())
				{
					throw "��������� ������ [a] �� �������� ������!";
				}

				cout << "������� b: ";
				cin >> b;
				cin.ignore(32767, '\n');
				if (cin.fail())
				{
					throw "��������� ������ [b] �� �������� ������!";
				}

				num_elem++;
				if (num_elem == 1)
				{
					line = new Curves * [num_elem];
					line[0] = new Ellipses(a, b, x);
				}

				else
				{
					temp = new Curves * [num_elem];

					for (i = 0; i < num_elem - 1; i++)
					{
						temp[i] = line[i];
					}

					temp[i] = new Ellipses(a, b, x);
					delete[] line;
					line = temp;
					temp = nullptr;
				}
			}
			catch (const char* exc)
			{
				cout << exc << endl;
				cin.clear();
				cin.ignore(32767, '\n');
			}
			

			system("pause");
			system("cls");
			break;

		case '3':																		// �� ���������� (�� ����)
			try
			{
				cout << "�������� ���������" << endl;
				cout << "������� x: ";
				cin >> x;
				cin.ignore(32767, '\n');
				if (cin.fail())
				{
					throw "��������� ������ [x] �� �������� ������!";
				}

				cout << "������� a: ";
				cin >> a;
				cin.ignore(32767, '\n');
				if (cin.fail())
				{
					throw "��������� ������ [a] �� �������� ������!";
				}

				cout << "������� b: ";
				cin >> b;
				cin.ignore(32767, '\n');
				if (cin.fail())
				{
					throw "��������� ������ [b] �� �������� ������!";
				}

				num_elem++;
				if (num_elem == 1)
				{
					line = new Curves * [num_elem];
					line[0] = new Hyperbola(a, b, x);
				}

				else
				{
					temp = new Curves * [num_elem];

					for (i = 0; i < num_elem - 1; i++)
					{
						temp[i] = line[i];
					}

					temp[i] = new Hyperbola(a, b, x);
					delete[] line;
					line = temp;
					temp = nullptr;
				}
			}
			catch (const char* exc)
			{
				cout << exc << endl;
				cin.clear();
				cin.ignore(32767, '\n');
			}
			

			system("pause");
			system("cls");
			break;

		case '4':
			cout << "����� �� ����� ���� �������" << endl;

			cout << "\nY-��:" << endl;
			show(line, num_elem);												// �������� �-�� show(), ��������� �� ���������
			cout << endl;														// �� ������ ���������� �� ������� �����

			system("pause");
			system("cls");
			break;

		case '5':
			cout << "������� � �����" << endl;
			line = read_from_file(line, num_elem, path[0], 0);					// �������� �-�� show(), ��������� �� ���������
			line = read_from_file(line, num_elem, path[1], 1);					// �� ������ ���������� �� ������� �����, � ����������� 
			line = read_from_file(line, num_elem, path[2], 2);					// ����� ��������� ������������ ��������
																				// (������ ������ �� �����, �� � �-�� �� �������� ���������� ���������)

			system("pause");
			system("cls");
			break;

		case '6':
			cout << "�������� � ����" << endl;
			write_to_file(line, num_elem, path[0], 0);							// �������� �-�� show(), ��������� �� ���������
			write_to_file(line, num_elem, path[1], 1);							// �� ������ ���������� �� ������� �����
			write_to_file(line, num_elem, path[2], 2);

			system("pause");
			system("cls");
			break;

		case '7':
			cout << "�����" << endl;
			for (i = 0; i < num_elem; i++)										// �������� ��� ������, ������� �� �������� ��� �������
			{
				delete line[i];
			}	
			delete[] line;														// � ��� ������ ����������

			exit = 0;
			system("pause");
			break;

		default:
			cout << "������ ��� ������ ���������! ���������� ��� ���." << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	return 0;
}