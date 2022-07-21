#include "Fruit.h"
Fruit :: Fruit() : coordinateX(0), coordinateY(0)
{}
void Fruit::randFruit()
{
	coordinateX = rand() % width;
	coordinateY = rand() % height;
}
int Fruit:: getCoordinateX()
{
	return coordinateX;
}
int Fruit:: getCoordinateY()
{
	return coordinateY;
}
Fruit :: ~Fruit()
{}