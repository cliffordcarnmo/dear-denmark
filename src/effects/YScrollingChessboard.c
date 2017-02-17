#include "YScrollingChessboard.h"

#include "../system/color.h"
#include "../system/graphics.h"
#include "../system/quad.h"

#include <math.h>

#define BOXAMOUNT 208

Box Boxes[BOXAMOUNT];

void createChessboard(Color frontColor, Color backColor){
	unsigned int x = 0;
	unsigned int y = 0;
	unsigned int c = 0;

	for(x = 1; x <= 16; x++){
		for(y = 1; y <= 13; y++){
			Boxes[c].x = -9.0f + (x * 1.0f);
			Boxes[c].y = 4.0f - (y * 1.0f);
			Boxes[c].z = -8.0f;
			Boxes[c].w = 1.0f;
			Boxes[c].h = 1.0f;

			if(c % 2 == 0){
				Boxes[c].color = frontColor;
			}else{
				Boxes[c].color = backColor;
			}
			c++;
		}
	}
}

void drawChessboard(float frameTime){
	static float timePassed = 0.0f;
	float zoomer;
	unsigned int c = 0;

	timePassed += frameTime;
	zoomer = sin(timePassed * 2.5) * 3.0;

	for(c = 0; c <= BOXAMOUNT; c++){
		drawQuad(Boxes[c].x, Boxes[c].y , Boxes[c].z + zoomer, Boxes[c].w, Boxes[c].h, Boxes[c].color.r, Boxes[c].color.g, Boxes[c].color.b, Boxes[c].color.a);
	}

	moveChessboard(frameTime);
}

void moveChessboard(float frameTime){
	unsigned int c = 0;

	for(c = 0; c <= BOXAMOUNT; c++){
		Boxes[c].y += frameTime * 8;

		if(Boxes[c].y >= 6.0f){
			Boxes[c].y = -6.0f;
		}

	}
}
