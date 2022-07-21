#pragma once
#include "Header.h"
class Level
{
	int** coordinate;
	int widthL, heightL;
public:
	Level();
	void difficult1();
	int getCoordinte(int i, int j);
	~Level();
};

