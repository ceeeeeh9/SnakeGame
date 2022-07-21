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
		cout << "Введите логин: ";
		cin >> userName;
		cout << "Введите пароль: ";
		cin >> userPassword;

		if (userName == "User" && userPassword == "User")
		{
			cout << "С возвращением, User!\n";
			system("pause");
			break;
		}
		else if (userName == "Admin" && userPassword == "Admin")
		{
			cout << "Добро пожаловать, Admin!\n";
			system("pause");
			break;
		}
		else
		{
			cout << "Неверно! Попробуйте еще раз.\n" << '\n';
			loginAttempt++;
		}
	}
	if (loginAttempt == 5)
	{
		cout << "Слишком много попыток! Программа завершена.";
		return 0;
	}
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Game g;
	return 0;
}