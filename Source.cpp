#include "Game.h"
#include "Header.h"



int main()
{
	setlocale(LC_ALL, "Russian");

	string userName;
	string userPassword;
	int loginAttempt = 0;

	while (loginAttempt < 5)
	{
		cout << "������� �����: ";
		cin >> userName;
		cout << "������� ������: ";
		cin >> userPassword;

		if (userName == "User" && userPassword == "User")
		{
			cout << "� ������������, User!\n";
			system("pause");
			break;
		}
		else if (userName == "Admin" && userPassword == "Admin")
		{
			cout << "����� ����������, Admin!\n";
			system("pause");
			break;
		}
		else
		{
			cout << "�������! ���������� ��� ���.\n" << '\n';
			loginAttempt++;
		}
	}
	if (loginAttempt == 5)
	{
		cout << "������� ����� �������! ��������� ���������.";
		return 0;
	}
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Game g;
	return 0;
}