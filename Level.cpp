#include "Level.h"
Level :: Level()
{
	coordinate = new int* [width];
	for (int i = 0; i < width; i++)
		coordinate[i] = new int[height];
	difficult1();
}
void Level::difficult1()
{
	for (int i = 0; i < width; i++)
		for (int j = 0; j < height; j++)
		{
			if (i == 0 || i == width - 1)
				coordinate[i][j] = 1;
			else
			{
				coordinate[i][0] = 1;
				coordinate[i][height - 1] = 1;
			}
		}
}
int Level::getCoordinte(int i, int j)
{
	return coordinate[i][j];
}
Level ::~Level()
{
	for (int i = 0; i < width; i++)
		delete[]coordinate[i];
	delete[]coordinate;
}