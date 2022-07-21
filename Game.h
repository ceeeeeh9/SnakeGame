#pragma once
#include "Level.h"
#include "Fruit.h"
#include "Snake.h"

class Game
{
	int score, difficult, pause;
	Level l;
	Snake s;
	Fruit f;
	string name;
	bool next;
public:
	Game();
	int test_int();
	void main_menu();
	void difficult_menu();
	void game_process();
	void setCursorPosition(int x, int y);
	void print_level();
	void print_snake();
	void print_delete_snake();
	void print_fruit();
	void rand_fruit();
	void print_score();
	void logic();
	void set_record();
	void print_records();
	~Game();
};

