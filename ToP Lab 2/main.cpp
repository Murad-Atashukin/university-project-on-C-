#include "Real.h"
#include "Stack.h"
#include <conio.h>

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "rus");

	Real real;

	bool exit = 1;
	double value;
	char choose;
	int16_t choice;

	while (exit)
	{
		std::cout << "|---------------------------------|\n"
			"| 1.   Создать класс вещ. чисел   |\n"
			"| 2.	  Создать класс Стек      |\n"
			"| 3.		Выход             |\n"
			"|---------------------------------|\n";

		std::cout << "\nВыберите действие >> ";
		choose = _getch();

		if (choose == '1')
		{
			std::cout << "Вы выбрали 1-ое задание - создание класса вещ. чисел." << std::endl;
			system("pause");
			system("cls");

			try
			{
				std::cout << "Введите начальное число: ";
				std::cin >> value;
				std::cin.ignore(32767, '\n');
				if (std::cin.fail())
				{
					throw "Введенные символы не являются числом";
				}

				real.SetValue(value);
				system("cls");

				while (exit)
				{
					std::cout << "|-----------------------|\n"
						"| 1.       ++#          |\n"
						"| 2.       #++          |\n"
						"| 3.       --#          |\n"
						"| 4.       #--          |\n"
						"| 5.  Показать число    |\n"
						"| 6.	  Выход         |\n"
						"|-----------------------|\n";
					std::cout << "\nВыберите действие >> ";
					choose = _getch();

					switch (choose)
					{
					case '1':
						std::cout << "++#" << std::endl;
						std::cout << "Число: ";
						real.show();
						++real;
						std::cout << "Число после увеличения: ";
						real.show();
						break;

					case '2':
						std::cout << "#++" << std::endl;
						std::cout << "Число: ";
						real.show();
						real++;
						std::cout << "Число после увеличения: ";
						real.show();
						break;

					case '3':
						std::cout << "--#" << std::endl;
						std::cout << "Число: ";
						real.show();
						--real;
						std::cout << "Число после уменьшения: ";
						real.show();
						break;

					case '4':
						std::cout << "#--" << std::endl;
						std::cout << "Число: ";
						real.show();
						real--;
						std::cout << "Число после уменьшения: ";
						real.show();
						break;

					case '5':
						std::cout << "Показать число" << std::endl;
						std::cout << "Число: ";
						real.show();
						break;

					case '6':
						std::cout << "Выход\n" << std::endl;
						exit = 0;
						break;
					default:
						std::cout << "\nОшибка при выборе категории! Попробуйте снова! :(" << std::endl;
						break;
					}

					system("pause");
					system("cls");
				}

				exit = 1;
			}
			catch (const char* exc)
			{
				std::cout << exc << std::endl;
				std::cin.clear();
				std::cin.ignore(32767, '\n');
			}
			
		}
		else if (choose == '2')
		{
			int16_t size = 0;

			std::cout << "Вы выбрали 2-ое задание - создание класса Стек." << std::endl;
			std::cout << "Введите размер стека: ";
			std::cin >> size;
			try
			{
				std::cin.ignore(32767, '\n');
				if (std::cin.fail())
					throw "Введённые символы не являются числом!";

				if (size < 0)
					throw "Некорректная размерность стека!";
				
				Stack s(size);
				system("pause");
				system("cls");

				while (exit)
				{
					std::cout << "|---------------------|\n"
						"| 1.       +          |\n"
						"| 2.       -          |\n"
						"| 3.       *          |\n"
						"| 4.       =          |\n"
						"| 5.      +=          |\n"
						"| 6.      -=          |\n"
						"| 7.   Показать       |\n"
						"| 8.	 Выход        |\n"
						"|---------------------|\n";
					std::cout << "\nВыберите действие >> ";
					choose = _getch();

					switch (choose)
					{
					case '1':
						std::cout << "+" << std::endl;
						std::cout << "Стек s:\n" << s << std::endl;
						try
						{
							std::cout << "Введите число, которое хотите прибавить: ";
							std::cin >> value;
							std::cin.ignore(32767, '\n');
							if (std::cin.fail())
							{
								throw "Введенные символы не являются числом";
							}

							std::cout << "Результат сложения:\n" << (s + value) << std::endl;
						}
						catch (const char* exc)
						{
							std::cout << exc << std::endl;
							std::cin.clear();
							std::cin.ignore(32767, '\n');
						}
						break;

					case '2':
						std::cout << "-" << std::endl;
						std::cout << "Стек s:\n" << s << std::endl;

						try
						{
							std::cout << "Введите число, которое хотите отнять: ";
							std::cin >> value;
							std::cin.ignore(32767, '\n');
							if (std::cin.fail())
							{
								throw "Введенные символы не являются числом";
							}

							std::cout << "1] Отнять от элементов стека введённое число\n"
								"2] Отнять от введённого числа элементы стека\n|-->> ";
							std::cin >> choice;

							if (choice == 1)
							{
								std::cout << "Результат вычитания (стек - число):\n" << (s - value) << std::endl;
							}

							else if (choice == 2)
							{
								std::cout << "Результат вычитания (число - стек):\n" << (value - s) << std::endl;
							}

							else
							{
								std::cout << "Некорректный выбор!" << std::endl;
							}
						}
						catch (const char* exc)
						{
							std::cout << exc << std::endl;
							std::cin.clear();
							std::cin.ignore(32767, '\n');
						}
						break;

					case '3':
						std::cout << "*" << std::endl;
						std::cout << "Стек s:\n" << s << std::endl;
						try
						{
							std::cout << "Введите число, на которое хотите умножить: ";
							std::cin >> value;
							std::cin.ignore(32767, '\n');
							if (std::cin.fail())
							{
								throw "Введенные символы не являются числом";
							}

							std::cout << "Результат сложения:\n" << (s * value) << std::endl;
						}
						catch (const char* exc)
						{
							std::cout << exc << std::endl;
							std::cin.clear();
							std::cin.ignore(32767, '\n');
						}
						break;

					case'4':
						std::cout << "=" << std::endl;
						std::cout << "Стек s:\n" << s << std::endl;
						try
						{
							std::cout << "Введите число, к которому хотите приравнять все элементы стека: ";
							std::cin >> value;
							std::cin.ignore(32767, '\n');
							if (std::cin.fail())
							{
								throw "Введенные символы не являются числом";
							}

							s = value;
							std::cout << "Результат приравнивания:\n" << s << std::endl;
						}
						catch (const char* exc)
						{
							std::cout << exc << std::endl;
							std::cin.clear();
							std::cin.ignore(32767, '\n');
						}
						break;

					case '5':
						std::cout << "+=" << std::endl;
						std::cout << "Стек s:\n" << s << std::endl;
						try
						{
							std::cout << "Введите число, на которое хотите увеличить все элементы стека: ";
							std::cin >> value;
							std::cin.ignore(32767, '\n');
							if (std::cin.fail())
							{
								throw "Введенные символы не являются числом";
							}

							s += value;
							std::cout << "Результат:\n" << s << std::endl;
						}
						catch (const char* exc)
						{
							std::cout << exc << std::endl;
							std::cin.clear();
							std::cin.ignore(32767, '\n');
						}
						break;

					case '6':
						std::cout << "+=" << std::endl;
						std::cout << "Стек s:\n" << s << std::endl;
						try
						{
							std::cout << "Введите число, на которое хотите уменьшить все элементы стека: ";
							std::cin >> value;
							std::cin.ignore(32767, '\n');
							if (std::cin.fail())
							{
								throw "Введенные символы не являются числом";
							}

							s -= value;
							std::cout << "Результат:\n" << s << std::endl;
						}
						catch (const char* exc)
						{
							std::cout << exc << std::endl;
							std::cin.clear();
							std::cin.ignore(32767, '\n');
						}
						break;

					case '7':
						std::cout << "Показать стек" << std::endl;
						std::cout << "Стек s:\n" << s << std::endl;

						break;

					case '8':
						std::cout << "Выход\n" << std::endl;
						exit = 0;
						break;

					default:
						std::cout << "\nОшибка при выборе категории! Попробуйте снова! :(" << std::endl;
						break;
					}

					system("pause");
					system("cls");
				}

				exit = 1;
			}
			catch (const char* exc)
			{
				std::cout << exc << std::endl;
				std::cin.ignore(32767, '\n');
				std::cin.clear();
			}
		}

		else if (choose == '3')
		{
			std::cout << "Выход из программы\n" << std::endl;
			exit = 0;
		}
		else
		{
			std::cout << "Ошибка выбора! Попробуйте ещё раз." << std::endl;
			system("pause");
			system("cls");
		}
	}

	system("pause");
	return 0;
}