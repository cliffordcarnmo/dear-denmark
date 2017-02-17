#pragma once

#include "../system/graphics.h"

typedef struct {
	float charWidth;
	float charHeight;
	GLuint texture;
	float textureWidth;
	float textureHeight;
	unsigned char lookup[255];
} font;

void createText();
void moveText(float);
void drawText(float);
