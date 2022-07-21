#pragma once
#include "Header.h"
__declspec(selectany) bool gameOver = false;
class Snake
{
	int coordinateX[1000];
	int coordinateY[1000];
	int c;
	int lenght;
	int tailLenght;
public:
	Snake();
	void removeSnake();
	int getCoordinateX(int i);
	int getCoordinateY(int i);
	void changeMove();
	void move();
	void gameOverTail();
	void tail();
	void tailLenhgtUp();
	~Snake();
};

