#include "Game.h"
#include "Snake.h"
Game::Game() : score(0), difficult(0), pause(0), next(false)
{
	main_menu();
}
int Game::test_int()
{
	int res, i;
	do
	{
		res = scanf_s("%d", &i);
		while (getchar() != '\n');
	} while (res != 1);
	return i;
}
void Game::main_menu()
{
	bool exit = false;
	while (!exit)
	{
		system("cls");
		cout << "1: Начать игру\n"
			<< "2: Продолжить игру\n"
			<< "3: Просмотр рекордов\n"
			<< "4: управление\n"
			<< "5: Выход\n";
		int choise;
		choise = test_int();
		switch (choise)
		{
		case 1:difficult_menu(); break;
		case 2:next = true; difficult_menu(); break;
		case 3:print_records(); system("pause"); break;
		case 4:cout << " w вверх\n s вниз\n a влево\n d вправо\n x сохранить прогресс и выйти\n играть только на английской раскладке"; system("pause"); break;
		case 5:exit = true; cout << "Программа завершена." << endl; system("pause");
		}
	}
}
void Game::difficult_menu()
{
    gameOver = false;
	cout << "Выбирите сложность\n"
		<< "1: Легко\n"
		<< "2: Средне\n"
		<< "3: Тяжело\n";
	int choise;
	choise = test_int();
	switch (choise)
	{
	case 1:difficult = choise; pause = 50000000; break;
	case 2:difficult = choise; pause = 25000000; break;
	case 3:difficult = choise; pause = 10000000; break;
	}
	score = 0;
	game_process();
	setCursorPosition(width + 2, height + 2);
	set_record();
	s.removeSnake();
}
void Game::game_process()
{
	print_level();
	int tail = 0;
	if (next == true)
	{
		setCursorPosition(1, 30);
		ifstream fin;
		fin.open("progress.txt");
		if (fin.is_open())
		{
			fin >> tail;
		}
		else cout << "Ошибка\n";
		cout << tail;
		fin.close();
	}
	rand_fruit();
	int t = 0;
	while (!gameOver)
	{
		if (t % pause == 0)
		{
			int n = 0;
			print_delete_snake();
			s.gameOverTail();
			s.tail();
			if (_kbhit())
			{
				s.changeMove();
				n++;
			}
			s.move();
			logic();
			print_snake();
			print_fruit();
			print_score();
			if (tail > 0 && n > 0)
			{
				s.tailLenhgtUp();
				tail--;
			}
		}
		t++;
		if (t == 20000000000)
			t = 0;
	}
}
void Game::setCursorPosition(int x, int y)
{
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();
	COORD coord = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(hOut, coord);
}
void Game::print_level()
{
	for (int i = 0; i < width; i++)
		for (int j = 0; j < height; j++)
		{
			if (l.getCoordinte(i, j) == 1)
			{
				setCursorPosition(i, j);
				cout << 'X';
			}
			else
			{
				setCursorPosition(i, j);
				cout << ' ';
			}
		}
	setCursorPosition(width / 2 - 1, height / 2 - 1);
	cout << '0';
}
void Game::print_snake()
{
	int i = 0;
	while (s.getCoordinateX(i) != -1)
	{
		setCursorPosition(s.getCoordinateX(i), s.getCoordinateY(i));
		cout << '0';
		i++;
	}
}
void Game::print_delete_snake()
{
	int i = 0;
	while (s.getCoordinateX(i) != -1)
	{
		setCursorPosition(s.getCoordinateX(i), s.getCoordinateY(i));
		cout << ' ';

		i++;
	}
}
void Game::print_fruit()
{
	setCursorPosition(f.getCoordinateX(), f.getCoordinateY());
	cout << '@';
}
void Game::rand_fruit()
{
	bool t = true;
	while (t)
	{
		f.~Fruit();
		t = false;
		f.randFruit();
		for (int i = 0; i < 100; i++)
			if (f.getCoordinateX() == s.getCoordinateX(i) && f.getCoordinateY() == s.getCoordinateY(i))
				t = true;
		if (l.getCoordinte(f.getCoordinateX(), f.getCoordinateY()) == 1)
			t = true;
	}
}
void Game::print_score()
{
	setCursorPosition(width + 10, 1);
	cout << "Ваш счёт " << score;
}
void Game::logic()
{
	if (f.getCoordinateX() == s.getCoordinateX(0) && f.getCoordinateY() == s.getCoordinateY(0))
	{
		rand_fruit();
		s.tailLenhgtUp();
		switch (difficult)
		{
		case 1: score += 25; break;
		case 2: score += 50; break;
		case 3: score += 100; break;
		}

	}

}
void Game::set_record()
{
	cout << "Введите своё имя\n";
	cin >> name;
	ofstream fout;
	fout.open("records.txt", ofstream::app);
	if (fout.is_open())
		fout << score << ' ' << name << '\n';
	fout.close();
}
void Game::print_records()
{
	ifstream fin;
	fin.open("records.txt");
	int num_r = 0;
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			char n[300];
			fin.getline(n, 300);
			num_r++;
		}
	}
	else cout << "Ошибка открытия файла\n";
	num_r--;
	fin.close();
	fin.open("records.txt");
	if (num_r > 0)
	{
		for (int i = 0; i < num_r; i++)
		{
			fin >> score;
			fin >> name;
			cout << score << ' ' << name << '\n';
		}
	}
	else cout << "Рекордов ещё нет\n";
	fin.close();
}
Game::~Game()
{
	setCursorPosition(width + 2, height + 10);
}
