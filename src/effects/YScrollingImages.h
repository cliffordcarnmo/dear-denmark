#pragma once

#include "../system/graphics.h"

typedef struct{
	float x;
	float y;
	float w;
	float h;
	float z;
} Image;

void createImages();
void moveImages(float);
void drawImages(float);
