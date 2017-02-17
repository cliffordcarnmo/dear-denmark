#pragma once

#include "../system/color.h"

typedef struct{
	float x;
	float y;
	float w;
	float h;
	Color color;
	int z;
} Box;

void createChessboard(Color, Color);
void moveChessboard(float);
void drawChessboard(float);
