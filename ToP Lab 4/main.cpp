#include "Array.h"
#include "Step_Swap_Function.h"
#include <conio.h>

using namespace std;

template<typename T>
T random_pulling(T* arr)
{
	if (typeid(T) == typeid(int16_t))
	{
		return rand() % 20;
	}

	else if (typeid(T) == typeid(float))
	{
		return (33 + rand() % 95) / (float)(rand() % 50);
	}

	else if (typeid(T) == typeid(double))
	{
		return (33 + rand() % 95) / (double)(rand() % 50);
	}

	else if (typeid(T) == typeid(char))
	{
		return 33 + rand() % 95;
	}
}

template<typename T>
void template_arr_swap(T* arr, int16_t step)
{
	int16_t size = 0;

	size = rand() % 20;

	arr = new T[size];

	cout << "�������� ������: " << endl;
	for (int16_t i = 0; i < size; i++)
	{
		arr[i] = random_pulling(arr);
		cout << arr[i] << "  ";
	}
	cout << "\n\n";

	swap_elem_of_array(arr, size, step);

	cout << "������ ����� ������������ � ����� " << step << ": " << endl;
	for (int16_t i = 0; i < size; i++)
	{
		cout << arr[i] << "  ";
	}
	cout << "\n\n";

	delete[] arr;
}

template<typename T>
void choose_array(Array<T>& a1, Array<T>& a2, int16_t size_1, int16_t size_2)
{
	bool exit = 1;
	char choose;
	int16_t choice;
	int16_t index;
	T value;

	while (exit)
	{
		cout << "1] �������� ��������\n2] �������� i-�� �������\n3] ���������� �������\n4] �������� �������\n"
			"5] �������� �������\n6] �����\n";
		cout << ">> ";
		choose = _getch();

		switch (choose)
		{
		case '1':
			cout << "�������� ��������" << endl;
			cout << "�������� ������ [1|2]: ";
			cin >> choice;

			try
			{
				if (choice == 1)
				{
					if (a1.GetFull() == 0)
					{
						cout << "������� �������� ����� Enter [" << size_1 << " ��]: " << endl;
					}
					else
					{
						cout << "������� �������� ������ ��������: ";
					}
						
					cin >> a1;
				}

				else if (choice == 2)
				{
					if (a2.GetFull() == 0)
					{
						cout << "������� �������� ����� Enter [" << size_2 << " ��]: " << endl;
					}
					else
					{
						cout << "������� �������� ������ ��������: ";
					}

					cin >> a2;
				}

				else
				{
					cout << "������������ �����!" << endl;
				}
			}
			catch (const char* exc)										// ���� ��� �������� ����������
			{
				cout << exc << endl;									// ������� ���
				cin.clear();											// ���. ������� ����� ����� 
				cin.ignore(32767, '\n');								// �������� �����
			}
			break;

		case '2':
			cout << "�������� i-�� �������" << endl;
			cout << "1]������ 1: ";
			a1.show();
			cout << "2]������ 2: ";
			a2.show();
			cout << "�������� ������: ";
			cin >> choice;
			
			try
			{
				cout << "������� ������ ��������: ";
				cin >> index;
				cin.ignore(32767, '\n');
				if (cin.fail())
				{
					throw "�������� ������ �� �������� ������";
				}

				cout << "������� ����� �������� ��������: ";
				cin >> value;
				cin.ignore(32767, '\n');
				if (cin.fail())
				{
					throw "�������� ������ �� ������������� ���� �������";
				}

				if (choice == 1)
				{
					a1[index] = value;
					cout << "������ " << choice << " ����� ���������: ";
					a1.show();
				}

				else if (choice == 2)
				{
					a2[index] = value;
					cout << "������ " << choice << " ����� ���������: ";
					a2.show();
				}

				else
				{
					cout << "������������ �����!" << endl;
				}
			}
			catch (const char* exc)										// ���� ��� �������� ����������
			{
				cout << exc << endl;									// ������� ���
				cin.clear();											// ���. ������� ����� ����� 
				cin.ignore(32767, '\n');								// �������� �����
			}
			
			break;

		case '3':
			cout << "���������� �������" << endl;
			cout << "1]������ 1: ";
			a1.show();
			cout << "2]������ 2: ";
			a2.show();
			cout << "��������:\n1] ������ 1 = ������ 2\n2] ������ 2 = ������ 1\n|-->> ";
			cin >> choice;

			if (choice == 1)
			{
				a1 = a2;
				cout << "������ " << choice << " ����� ���������: ";
				a1.show();
			}

			else if (choice == 2)
			{
				a2 = a1;
				cout << "������ " << choice << " ����� ���������: ";
				a2.show();
			}

			else
			{
				cout << "������������ �����!" << endl;
			}

			break;

		case '4':
			cout << "�������� �������" << endl;

			if (a1 == a2)
			{
				cout << "������� ����� ���������� �����." << endl;
			}

			else
			{
				cout << "������� ����� ������ �����." << endl;
			}

			break;

		case '5':
			cout << "�������� �������" << endl;
			cout << "1]������ 1: ";
			cout << a1 << endl;
			cout << "2]������ 2: ";
			cout << a2 << endl;
			
			break;

		case '6':
			cout << "�����" << endl;
			exit = 0;
			break;

		default:
			cout << "\n������ ��� ������ ���������! ���������� �����! :(" << endl;
			break;
		}

		system("pause");
		system("cls");
	}
}

int main()
{
	bool exit = 1;
	bool mode = 0;
	char choose;
	int16_t step = 0;
	int16_t size_1 = 0;
	int16_t size_2 = 0;
	string temp_str;

	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	while (exit)
	{
		std::cout << "|--------------------------------------|\n"
			"| 1.   ������������ ��������� � �����  |\n"
			"| 2.          ��������� ������         |\n"
			"| 3.	           �����               |\n"
			"|--------------------------------------|\n";
		std::cout << "\n�������� �������� >> ";
		choose = _getch();

		if (choose == '1')
		{
			cout << "������������ ��������� � �����" << endl;
			try
			{
				cout << "������� ���: ";
				cin >> step;
				cin.ignore(32767, '\n');
				if (cin.fail())
				{
					throw "�������� ������ [step] �� �������� ������!";
				}

				cout << "�������� ���:\n1] int16_t\n2] float\n3] double\n4] char\n";
				cout << "\n>> ";
				choose = _getch();

				if (choose == '1')
				{
					cout << "int16_t" << endl;
					int16_t* arr_int = nullptr;
					template_arr_swap(arr_int, step);
				}

				else if (choose == '2')
				{
					cout << "float" << endl;
					float* arr_float = nullptr;
					template_arr_swap(arr_float, step);
				}

				else if (choose == '3')
				{
					cout << "double" << endl;
					double* arr_double = nullptr;
					template_arr_swap(arr_double, step);
				}

				else if (choose == '4')
				{
					cout << "char" << endl;
					char* arr_char = nullptr;
					template_arr_swap(arr_char, step);
				}

				else
				{
					cout << "\n������ ��� ������ ���������! ���������� �����! :(" << endl;
				}
			}
			catch (const char* exc)										// ���� ��� �������� ����������
			{
				cout << exc << endl;									// ������� ���
				cin.clear();											// ���. ������� ����� ����� 
				cin.ignore(32767, '\n');								// �������� �����
			}
		}

		else if (choose == '2')
		{
			cout << "��������� ������" << endl;
			try
			{
				cout << "������� ����������� ������� �������: ";
				cin >> size_1;
				cin.ignore(32767, '\n');
				if (cin.fail())
				{
					throw "�������� ������ [size_1] �� �������� ������!";
				}

				cout << "������� ����������� ������� �������: ";
				cin >> size_2;
				cin.ignore(32767, '\n');
				if (cin.fail())
				{
					throw "�������� ������ [size_2] �� �������� ������!";
				}

				cout << "�������� ���:\n1] int16_t\n2] float\n3] double\n";
				cout << "\n>> ";
				choose = _getch();

				if (choose == '1')
				{
					cout << "int16_t" << endl;
					system("pause");
					system("cls");

					Array<int16_t> a1(size_1), a2(size_2);

					choose_array(a1, a2, size_1, size_2);
				}

				else if (choose == '2')
				{
					cout << "float" << endl;
					system("pause");
					system("cls");

					Array<float> a1(size_1), a2(size_2);

					choose_array(a1, a2, size_1, size_2);
				}

				else if (choose == '3')
				{
					cout << "double" << endl;
					system("pause");
					system("cls");

					Array<double> a1(size_1), a2(size_2);

					choose_array(a1, a2, size_1, size_2);
				}

				else
				{
					cout << "\n������ ��� ������ ���������! ���������� �����! :(" << endl;
				}

			}
			catch (const char* exc)										// ���� ��� �������� ����������
			{
				cout << exc << endl;									// ������� ���
				cin.clear();											// ���. ������� ����� ����� 
				cin.ignore(32767, '\n');								// �������� �����
			}
		}

		else if (choose == '3')
		{
			cout << "����� �� ���������" << endl;
			exit = 0;
		}

		else
		{
			cout << "\n������ ��� ������ ���������! ���������� �����! :(" << endl;
		}

		system("pause");
		system("cls");
	}

	return 0;
}