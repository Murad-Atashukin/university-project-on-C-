#include "Hyperbola.h"
#include "Straight.h"
#include "Ellipse.h"

#include <fstream> /*fstream — заголовочный файл из стандартной библиотеки C++, включающий набор классов,
методов и функций, которые предоставляют интерфейс для чтения/записи данных из/в файл. 
Для манипуляции с данными файлов используются объекты, называемые потоками */
#include <string>
#include <conio.h>
#include <cstdint>																// Библиотека с фиксированным значением int
#include <typeinfo>
#include <Windows.h>

using namespace std;

void show(Curves** object, int16_t num_elem)									// Функция выводит все объекты, хранящиеся в массиве указателей на базовый класс
{																				// Тк тип int не имеет фикс. размерности (где-то 2, где-то 4 байта),
																				// лучше использовать фикс. из библ. stdint (Например int16_t - это 2-ух байтовый int)
	int16_t mode = 0;															// Тип объекта
	int16_t count_elem = 0;														// Количество элементов определенного типа
	string type[3] = { "Прямых", "Эллипсов", "Гипербол"};

	if (num_elem == 0)															// Если нет элементов
	{
		cout << "Нет добавленных фигур!" << endl;
		return;
	}

	for (int16_t i = 0; i < 3; i++, mode++)										// Проходимся по массиву 4 раза, тк у нас 4 разных типа в нем хранится
	{
		cout << "Y-ки " << type[i] << ":" << endl;
		for (int16_t j = 0; j < num_elem; j++)									// Обходим массив
		{
			if (mode == 0)														// Если сейчас мы ищем тип Прямых
			{
				if (typeid(*object[j]) == typeid(Straight))						// Сравниваем тип i-го объекта с типом Прямых
				{
					object[j]->print();											// Если совпало - то выводим
					count_elem++;
				}
			}
			else if (mode == 1)													// Если сейчас мы ищем тип Эллипсов
			{
				if (typeid(*object[j]) == typeid(Ellipses))						// Сравниваем тип i-го объекта с типом Эллипсов
				{
					object[j]->print();								
					count_elem++;
				}
			}
			else if (mode == 2)													// Если сейчас мы ищем тип Гипербол
			{
				if (typeid(*object[j]) == typeid(Hyperbola))					// Сравниваем тип i-го объекта с типом Гипербол
				{
					object[j]->print();
					count_elem++;
				}
			}
		}

		if (count_elem == 0)													// Если не встретилось ниодного элемента данного типа, выводим
		{
			cout << "У вас нет " << type[i] << endl;
		}
		count_elem = 0;
		cout << endl;
	}
}

void write_to_file(Curves** object, int16_t num_elem, string path, int16_t mode)	// Функция записи элементов в файл
{
	ofstream fout;																// Создаем переменную потокового вывода
	fout.open(path);															// Открываем файл

	if (!fout.is_open())														// Если файл открылся с ошибков выводим и уходим
	{
		cout << "Ошибка при открытии файла по пути" << path << endl;
		return;
	}

	for (int16_t i = 0; i < num_elem; i++)										// Иначе обходим массив
	{
		if (mode == 0)															// Если сейчас мы ищем тип Прямая 
		{ 
			if (typeid(*object[i]) == typeid(Straight))							// Сравниваем тип i-го объекта с типом Прямая
				fout.write((char*)&(*object[i]), sizeof(Straight));				// По-байтого записываем в отведенный файл Straight.txt
		}
		else if (mode == 1)														// Аналогично с другими
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
	
	fout.close();																// Закрываем файл
}

Curves** read_from_file(Curves** object, int16_t& num_elem, string path, int16_t mode)	// Функция чтения из файла
{
	int16_t i, j;																		// Счётчики
	size_t size = 0;																	// Размер типа объекта
	ifstream fin;
	fin.open(path);																		// Открываем файл
	Curves** obj = new Curves *[num_elem + 1];											// Создаем массив указателей на базовый класс из 1 элемента

	if (!fin.is_open())																	// Если файл не открылся
	{
		cout << "Ошибка при открытии файла по пути" << path << endl;					// Выводим ошибку, удаляем массив указателей и уходим
		delete[] obj;
		return object;
	}

	for (i = 0; i < num_elem; i++)														// Иначе копируем все введённые до этого элементы
	{																					// в буфер
		obj[i] = object[i];
	}

	if (mode == 0) { obj[i] = new Straight; size = sizeof(Straight); }					// Создаем объект нужного типа, опираясь на файл,
	else if (mode == 1) { obj[i] = new Ellipses; size = sizeof(Ellipses); }				// с которого произвадится считывание. (Разные типы 
	else if (mode == 2) { obj[i] = new Hyperbola; size = sizeof(Hyperbola); }			// хранятся в разных файлах. Например тип Straight 
																						// хранится в Straight.txt и тд)

	while (fin.read((char*)&(*obj[i]), size))											// По-байтого считываем (метод read, возвращает 
	{																					// true, если удалось считать, и false, если нет)
		if (object != nullptr)															// Отчищаем основной массив
		{
			delete[] object;
		}

		object = obj;																	// Буфер становится основным массивом 
		num_elem++;																		// Увеличиваем кол. элементов и создаем новый буфер
 		obj = new Curves * [num_elem + 1];

		for (i = 0; i < num_elem; i++)													// Копируем все указатели из основного в новый буфер
		{
			obj[i] = object[i];
		}
		
		if (mode == 0) { obj[i] = new Straight; }											// Создаем объект нужного типа, опираясь на файл(см выше)
		else if (mode == 1) { obj[i] = new Ellipses; }
		else if (mode == 2) { obj[i] = new Hyperbola; }
	}

	delete[] obj;																		// Отчищаем буфер

	//show(object, num_elem);

	fin.close();																		// Закрываем файл
	return object;																		// Возвращаем основной массив
}

int main()
{
	int16_t i;
	bool exit = 1;																		// Нужно для бесконечного цика
	char choice = 0;																	// Выбор
	double x, a, b, k;
	string path[3] = { "Straight.txt", "Ellipses.txt", "Hyperbola.txt"};
																			// !#! -Тк в указателе на базовый класс может хранится
																			// адрес на любого его наследника нам достаточно массива
																			// массива указателей на базовый класс для хранения всех обектов
	Curves** line, **temp;															// Указатели на массивы указателей на базовый класс
	int16_t num_elem;																	// Кол. элементов
		
	num_elem = 0;
	line = nullptr;
	x = a = b = k = 0;

	SetConsoleCP(1251);																	// Меняем кодировку на кириллицу
	SetConsoleOutputCP(1251);

	while (exit)																		// Крутимся, пока верно
	{
		cout << "Выбор действия:\n1] Добавить Прямую\n2] Добавить Эллипс\n3] Добавить Гиперболу\n"
			"4] Вывести на экран все Y\n5] Считать с файла\n6] Записать в файл\n7] Выход\n" << endl;
		cout << "|->> ";
		choice = _getch();																// Считываем выбор

		switch (choice)
		{
		case '1':
			try
			{
				cout << "Добавить Прямую" << endl;
				cout << "Введите x: ";
				cin >> x;
				cin.ignore(32767, '\n');												// Отчищаем буфер от лишней информации, введенный пользователем
																						// Например, 1.2а, символ "а" останется висеть в буфере, и создат ошибки в дальнейшем, поэтому отчищаем
				if (cin.fail())															// Если пользователь ввёл букву, то поток ввода выкл.								
				{
					throw "Введенный символ [x] не является числом!";					// Создаем исключение и идёт в catch
				}

				cout << "Введите k: ";
				cin >> k;
				cin.ignore(32767, '\n');
				if (cin.fail())
				{
					throw "Введенный символ [k] не является числом!";
				}

				cout << "Введите b: ";
				cin >> b;
				cin.ignore(32767, '\n');
				if (cin.fail())
				{
					throw "Введенный символ [b] не является числом!";
				}

				num_elem++;																// Увеличиваем кол. элементов 
				if (num_elem == 1)														// Если это первый элемент в нашем массиве, то
				{
					line = new Curves * [num_elem];										// Создаём нужный нам объект нужного типа
					line[0] = new Straight(x, k, b);									// передаем тыда значение
				}

				else																	// В ином случае
				{
					temp = new Curves * [num_elem];										// Создаем новый массив указателей

					for (i = 0; i < num_elem - 1; i++)									// Копируем указатели из старого
					{
						temp[i] = line[i];
					}

					temp[i] = new Straight(x, k, b);									// Добавляем новый элемент
					delete[] line;														// Удаляем старый массив
					line = temp;														// Указатель на старый массив теперь указывает на новый
					temp = nullptr;
				}
			}
			catch (const char* exc)
			{
				cout << exc << endl;													// Выводим исключение 
				cin.clear();															// Вкл. поток ввода
				cin.ignore(32767, '\n');												// Отчищаем его буфер
			}
			

			system("pause");
			system("cls");
			break;

		case '2':
			try
			{
				cout << "Добавить Эллипс" << endl;									// Всё аналогично (см выше)
				cout << "Введите x: ";
				cin >> x;
				cin.ignore(32767, '\n');
				if (cin.fail())
				{
					throw "Введенный символ [x] не является числом!";
				}

				cout << "Введите a: ";
				cin >> a;
				cin.ignore(32767, '\n');
				if (cin.fail())
				{
					throw "Введенный символ [a] не является числом!";
				}

				cout << "Введите b: ";
				cin >> b;
				cin.ignore(32767, '\n');
				if (cin.fail())
				{
					throw "Введенный символ [b] не является числом!";
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

		case '3':																		// Всё аналогично (см выше)
			try
			{
				cout << "Добавить Гиперболу" << endl;
				cout << "Введите x: ";
				cin >> x;
				cin.ignore(32767, '\n');
				if (cin.fail())
				{
					throw "Введенный символ [x] не является числом!";
				}

				cout << "Введите a: ";
				cin >> a;
				cin.ignore(32767, '\n');
				if (cin.fail())
				{
					throw "Введенный символ [a] не является числом!";
				}

				cout << "Введите b: ";
				cin >> b;
				cin.ignore(32767, '\n');
				if (cin.fail())
				{
					throw "Введенный символ [b] не является числом!";
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
			cout << "Вывод на экран всех объемов" << endl;

			cout << "\nY-ки:" << endl;
			show(line, num_elem);												// Вызываем ф-ию show(), передавая ей указатель
			cout << endl;														// на массив указателей на базовый класс

			system("pause");
			system("cls");
			break;

		case '5':
			cout << "Считать с файла" << endl;
			line = read_from_file(line, num_elem, path[0], 0);					// Вызываем ф-ию show(), передавая ей указатель
			line = read_from_file(line, num_elem, path[1], 1);					// на массив указателей на базовый класс, и присваиваем 
			line = read_from_file(line, num_elem, path[2], 2);					// этому указателю возвращаемое значение
																				// (Утечки памяти не будет, тк в ф-ии мы отчищаем предыдущее выделение)

			system("pause");
			system("cls");
			break;

		case '6':
			cout << "Записать в файл" << endl;
			write_to_file(line, num_elem, path[0], 0);							// Вызываем ф-ию show(), передавая ей указатель
			write_to_file(line, num_elem, path[1], 1);							// на массив указателей на базовый класс
			write_to_file(line, num_elem, path[2], 2);

			system("pause");
			system("cls");
			break;

		case '7':
			cout << "Выход" << endl;
			for (i = 0; i < num_elem; i++)										// Отчищаем всю память, которую мы выделяли под объекты
			{
				delete line[i];
			}	
			delete[] line;														// И под массив указателей

			exit = 0;
			system("pause");
			break;

		default:
			cout << "Ошибка при выборе категории! Попробуйте ещё раз." << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	return 0;
}