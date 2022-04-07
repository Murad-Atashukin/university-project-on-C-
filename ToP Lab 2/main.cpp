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
			"| 1.   ������� ����� ���. �����   |\n"
			"| 2.	  ������� ����� ����      |\n"
			"| 3.		�����             |\n"
			"|---------------------------------|\n";

		std::cout << "\n�������� �������� >> ";
		choose = _getch();

		if (choose == '1')
		{
			std::cout << "�� ������� 1-�� ������� - �������� ������ ���. �����." << std::endl;
			system("pause");
			system("cls");

			try
			{
				std::cout << "������� ��������� �����: ";
				std::cin >> value;
				std::cin.ignore(32767, '\n');
				if (std::cin.fail())
				{
					throw "��������� ������� �� �������� ������";
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
						"| 5.  �������� �����    |\n"
						"| 6.	  �����         |\n"
						"|-----------------------|\n";
					std::cout << "\n�������� �������� >> ";
					choose = _getch();

					switch (choose)
					{
					case '1':
						std::cout << "++#" << std::endl;
						std::cout << "�����: ";
						real.show();
						++real;
						std::cout << "����� ����� ����������: ";
						real.show();
						break;

					case '2':
						std::cout << "#++" << std::endl;
						std::cout << "�����: ";
						real.show();
						real++;
						std::cout << "����� ����� ����������: ";
						real.show();
						break;

					case '3':
						std::cout << "--#" << std::endl;
						std::cout << "�����: ";
						real.show();
						--real;
						std::cout << "����� ����� ����������: ";
						real.show();
						break;

					case '4':
						std::cout << "#--" << std::endl;
						std::cout << "�����: ";
						real.show();
						real--;
						std::cout << "����� ����� ����������: ";
						real.show();
						break;

					case '5':
						std::cout << "�������� �����" << std::endl;
						std::cout << "�����: ";
						real.show();
						break;

					case '6':
						std::cout << "�����\n" << std::endl;
						exit = 0;
						break;
					default:
						std::cout << "\n������ ��� ������ ���������! ���������� �����! :(" << std::endl;
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

			std::cout << "�� ������� 2-�� ������� - �������� ������ ����." << std::endl;
			std::cout << "������� ������ �����: ";
			std::cin >> size;
			try
			{
				std::cin.ignore(32767, '\n');
				if (std::cin.fail())
					throw "�������� ������� �� �������� ������!";

				if (size < 0)
					throw "������������ ����������� �����!";
				
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
						"| 7.   ��������       |\n"
						"| 8.	 �����        |\n"
						"|---------------------|\n";
					std::cout << "\n�������� �������� >> ";
					choose = _getch();

					switch (choose)
					{
					case '1':
						std::cout << "+" << std::endl;
						std::cout << "���� s:\n" << s << std::endl;
						try
						{
							std::cout << "������� �����, ������� ������ ���������: ";
							std::cin >> value;
							std::cin.ignore(32767, '\n');
							if (std::cin.fail())
							{
								throw "��������� ������� �� �������� ������";
							}

							std::cout << "��������� ��������:\n" << (s + value) << std::endl;
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
						std::cout << "���� s:\n" << s << std::endl;

						try
						{
							std::cout << "������� �����, ������� ������ ������: ";
							std::cin >> value;
							std::cin.ignore(32767, '\n');
							if (std::cin.fail())
							{
								throw "��������� ������� �� �������� ������";
							}

							std::cout << "1] ������ �� ��������� ����� �������� �����\n"
								"2] ������ �� ��������� ����� �������� �����\n|-->> ";
							std::cin >> choice;

							if (choice == 1)
							{
								std::cout << "��������� ��������� (���� - �����):\n" << (s - value) << std::endl;
							}

							else if (choice == 2)
							{
								std::cout << "��������� ��������� (����� - ����):\n" << (value - s) << std::endl;
							}

							else
							{
								std::cout << "������������ �����!" << std::endl;
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
						std::cout << "���� s:\n" << s << std::endl;
						try
						{
							std::cout << "������� �����, �� ������� ������ ��������: ";
							std::cin >> value;
							std::cin.ignore(32767, '\n');
							if (std::cin.fail())
							{
								throw "��������� ������� �� �������� ������";
							}

							std::cout << "��������� ��������:\n" << (s * value) << std::endl;
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
						std::cout << "���� s:\n" << s << std::endl;
						try
						{
							std::cout << "������� �����, � �������� ������ ���������� ��� �������� �����: ";
							std::cin >> value;
							std::cin.ignore(32767, '\n');
							if (std::cin.fail())
							{
								throw "��������� ������� �� �������� ������";
							}

							s = value;
							std::cout << "��������� �������������:\n" << s << std::endl;
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
						std::cout << "���� s:\n" << s << std::endl;
						try
						{
							std::cout << "������� �����, �� ������� ������ ��������� ��� �������� �����: ";
							std::cin >> value;
							std::cin.ignore(32767, '\n');
							if (std::cin.fail())
							{
								throw "��������� ������� �� �������� ������";
							}

							s += value;
							std::cout << "���������:\n" << s << std::endl;
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
						std::cout << "���� s:\n" << s << std::endl;
						try
						{
							std::cout << "������� �����, �� ������� ������ ��������� ��� �������� �����: ";
							std::cin >> value;
							std::cin.ignore(32767, '\n');
							if (std::cin.fail())
							{
								throw "��������� ������� �� �������� ������";
							}

							s -= value;
							std::cout << "���������:\n" << s << std::endl;
						}
						catch (const char* exc)
						{
							std::cout << exc << std::endl;
							std::cin.clear();
							std::cin.ignore(32767, '\n');
						}
						break;

					case '7':
						std::cout << "�������� ����" << std::endl;
						std::cout << "���� s:\n" << s << std::endl;

						break;

					case '8':
						std::cout << "�����\n" << std::endl;
						exit = 0;
						break;

					default:
						std::cout << "\n������ ��� ������ ���������! ���������� �����! :(" << std::endl;
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
			std::cout << "����� �� ���������\n" << std::endl;
			exit = 0;
		}
		else
		{
			std::cout << "������ ������! ���������� ��� ���." << std::endl;
			system("pause");
			system("cls");
		}
	}

	system("pause");
	return 0;
}