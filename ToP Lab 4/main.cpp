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

	cout << "Исходный массив: " << endl;
	for (int16_t i = 0; i < size; i++)
	{
		arr[i] = random_pulling(arr);
		cout << arr[i] << "  ";
	}
	cout << "\n\n";

	swap_elem_of_array(arr, size, step);

	cout << "Массив после перестановки с шагом " << step << ": " << endl;
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
		cout << "1] Добавить элементы\n2] Изменить i-ый элемент\n3] Приравнять массивы\n4] Сравнить массивы\n"
			"5] Показать массивы\n6] Выход\n";
		cout << ">> ";
		choose = _getch();

		switch (choose)
		{
		case '1':
			cout << "Добавить элементы" << endl;
			cout << "Выберете массив [1|2]: ";
			cin >> choice;

			try
			{
				if (choice == 1)
				{
					if (a1.GetFull() == 0)
					{
						cout << "Введите значения через Enter [" << size_1 << " шт]: " << endl;
					}
					else
					{
						cout << "Введите значение нового элемента: ";
					}
						
					cin >> a1;
				}

				else if (choice == 2)
				{
					if (a2.GetFull() == 0)
					{
						cout << "Введите значения через Enter [" << size_2 << " шт]: " << endl;
					}
					else
					{
						cout << "Введите значение нового элемента: ";
					}

					cin >> a2;
				}

				else
				{
					cout << "Некорректный выбор!" << endl;
				}
			}
			catch (const char* exc)										// Если нам попалось исключение
			{
				cout << exc << endl;									// Выводим его
				cin.clear();											// Вкл. обратно поток ввода 
				cin.ignore(32767, '\n');								// Отчищаем буфер
			}
			break;

		case '2':
			cout << "Изменить i-ый элемент" << endl;
			cout << "1]Массив 1: ";
			a1.show();
			cout << "2]Массив 2: ";
			a2.show();
			cout << "Выберете массив: ";
			cin >> choice;
			
			try
			{
				cout << "Введите индекс элемента: ";
				cin >> index;
				cin.ignore(32767, '\n');
				if (cin.fail())
				{
					throw "Введённый символ не является числом";
				}

				cout << "Введите новое значение элемента: ";
				cin >> value;
				cin.ignore(32767, '\n');
				if (cin.fail())
				{
					throw "Введённый символ не соответствует типу массива";
				}

				if (choice == 1)
				{
					a1[index] = value;
					cout << "Массив " << choice << " после изменения: ";
					a1.show();
				}

				else if (choice == 2)
				{
					a2[index] = value;
					cout << "Массив " << choice << " после изменения: ";
					a2.show();
				}

				else
				{
					cout << "Некорректный выбор!" << endl;
				}
			}
			catch (const char* exc)										// Если нам попалось исключение
			{
				cout << exc << endl;									// Выводим его
				cin.clear();											// Вкл. обратно поток ввода 
				cin.ignore(32767, '\n');								// Отчищаем буфер
			}
			
			break;

		case '3':
			cout << "Приравнять массивы" << endl;
			cout << "1]Массив 1: ";
			a1.show();
			cout << "2]Массив 2: ";
			a2.show();
			cout << "Выберете:\n1] Массив 1 = Массив 2\n2] Массив 2 = Массив 1\n|-->> ";
			cin >> choice;

			if (choice == 1)
			{
				a1 = a2;
				cout << "Массив " << choice << " после изменения: ";
				a1.show();
			}

			else if (choice == 2)
			{
				a2 = a1;
				cout << "Массив " << choice << " после изменения: ";
				a2.show();
			}

			else
			{
				cout << "Некорректный выбор!" << endl;
			}

			break;

		case '4':
			cout << "Сравнить массивы" << endl;

			if (a1 == a2)
			{
				cout << "Массивы имеют одинаковую длину." << endl;
			}

			else
			{
				cout << "Массивы имеют разную длину." << endl;
			}

			break;

		case '5':
			cout << "Показать массивы" << endl;
			cout << "1]Массив 1: ";
			cout << a1 << endl;
			cout << "2]Массив 2: ";
			cout << a2 << endl;
			
			break;

		case '6':
			cout << "Выход" << endl;
			exit = 0;
			break;

		default:
			cout << "\nОшибка при выборе категории! Попробуйте снова! :(" << endl;
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
			"| 1.   Перестановка элементов с шагом  |\n"
			"| 2.          Шаблонный Массив         |\n"
			"| 3.	           Выход               |\n"
			"|--------------------------------------|\n";
		std::cout << "\nВыберете действие >> ";
		choose = _getch();

		if (choose == '1')
		{
			cout << "Перестановка элементов с шагом" << endl;
			try
			{
				cout << "Введите шаг: ";
				cin >> step;
				cin.ignore(32767, '\n');
				if (cin.fail())
				{
					throw "Введённый символ [step] не является числом!";
				}

				cout << "Выберете тип:\n1] int16_t\n2] float\n3] double\n4] char\n";
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
					cout << "\nОшибка при выборе категории! Попробуйте снова! :(" << endl;
				}
			}
			catch (const char* exc)										// Если нам попалось исключение
			{
				cout << exc << endl;									// Выводим его
				cin.clear();											// Вкл. обратно поток ввода 
				cin.ignore(32767, '\n');								// Отчищаем буфер
			}
		}

		else if (choose == '2')
		{
			cout << "Шаблонный массив" << endl;
			try
			{
				cout << "Введите размерность первого массива: ";
				cin >> size_1;
				cin.ignore(32767, '\n');
				if (cin.fail())
				{
					throw "Введённый символ [size_1] не является числом!";
				}

				cout << "Введите размерность второго массива: ";
				cin >> size_2;
				cin.ignore(32767, '\n');
				if (cin.fail())
				{
					throw "Введённый символ [size_2] не является числом!";
				}

				cout << "Выберете тип:\n1] int16_t\n2] float\n3] double\n";
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
					cout << "\nОшибка при выборе категории! Попробуйте снова! :(" << endl;
				}

			}
			catch (const char* exc)										// Если нам попалось исключение
			{
				cout << exc << endl;									// Выводим его
				cin.clear();											// Вкл. обратно поток ввода 
				cin.ignore(32767, '\n');								// Отчищаем буфер
			}
		}

		else if (choose == '3')
		{
			cout << "Выход из программы" << endl;
			exit = 0;
		}

		else
		{
			cout << "\nОшибка при выборе категории! Попробуйте снова! :(" << endl;
		}

		system("pause");
		system("cls");
	}

	return 0;
}