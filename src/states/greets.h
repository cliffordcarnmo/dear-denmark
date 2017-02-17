#pragma once

typedef struct{
	float v1;
	float v2;
	float v3;
} Point2;

typedef struct{
	float x;
	float y;
	float z;
	Point2 p[3];
} Triangle2;

void greetsEnter(void);
void greetsUpdate(float);
void greetsExit(void);
