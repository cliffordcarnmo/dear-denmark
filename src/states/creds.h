#pragma once

typedef struct{
	float v1;
	float v2;
	float v3;
} Point;

typedef struct{
	float x;
	float y;
	float z;
	Point p[3];
} Triangle;

void credsEnter(void);
void credsUpdate(float);
void credsExit(void);
