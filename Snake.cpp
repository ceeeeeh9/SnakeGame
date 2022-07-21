#include "Snake.h"
Snake :: Snake() : lenght(1), c(0), tailLenght(0)
{
	for (int i = 0; i < 100; i++)
	{
		coordinateX[i] = -1;
		coordinateY[i] = -1;
	}
	coordinateX[0] = width / 2 - 1;
	coordinateY[0] = height / 2 - 1;
}
void Snake::removeSnake()
{
	c = 0;
	lenght = 1;
	tailLenght = 0;
	for (int i = 0; i < 100; i++)
	{
		coordinateX[i] = -1;
		coordinateY[i] = -1;
	}
	coordinateX[0] = width / 2 - 1;
	coordinateY[0] = height / 2 - 1;
}
int Snake::getCoordinateX(int i)
{
	return coordinateX[i];
}
int Snake::getCoordinateY(int i)
{
	return coordinateY[i];
}
void Snake::changeMove()
{
	switch (_getch())
	{
	case 'a': if (c != 2) c = 1; break;
	case 'd': if (c != 1) c = 2; break;
	case 'w': if (c != 4) c = 3; break;
	case 's': if (c != 3) c = 4; break;
	case 'x':
	{
		ofstream fout;
		fout.open("progress.txt");
		fout << tailLenght;
		fout.close();
		gameOver = true;
	} break;
	default: c = 0; break;
	}
}
void Snake:: move()
{
	switch (c)
	{
	case 1: coordinateX[0]--; break;
	case 2: coordinateX[0]++; break;
	case 3: coordinateY[0]--; break;
	case 4: coordinateY[0]++; break;
	default: break;
	}
	if (coordinateX[0] > width - 2 || coordinateY[0] > height - 2 || coordinateX[0] < 1 || coordinateY[0] < 1)
		gameOver = true;

}
void Snake::gameOverTail()
{
	for (int i = 1; i < 100; i++)
		if (coordinateX[0] == coordinateX[i] && coordinateY[0] == coordinateY[i])
			gameOver = true;
}
void Snake::tail()
{
	for (int i = tailLenght; i > 0; i--)
	{
		coordinateX[i] = coordinateX[i - 1];
		coordinateY[i] = coordinateY[i - 1];
	}
}
void Snake::tailLenhgtUp()
{
	tailLenght++;
}
Snake::~Snake()
{}
