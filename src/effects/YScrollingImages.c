#include "YScrollingImages.h"

#include "../system/graphics.h"
#include "../system/image.h"

#include <math.h>

extern GLuint logo2;

#define IMGAMOUNT 512

Image Images[IMGAMOUNT];

void createImages(){
	unsigned int x = 0;
	unsigned int y = 0;
	unsigned int c = 0;

	for(x = 1; x <= 32; x++){
		for(y = 1; y <= 16; y++){
			Images[c].x = -13.0f + (x * 1.0f);
			Images[c].y = 6.0f - (y * 1.0f);
			Images[c].z = -10.0f;
			Images[c].w = 1.0f;
			Images[c].h = 1.0f;
			c++;
		}
	}
}

void drawImages(float frameTime){
	static float timePassed = 0.0f;
	float zoomer;
	unsigned int c = 0;
	static float mover = 0.0f;

	mover = cos(timePassed*2) * 1.5;

	timePassed += frameTime;
	zoomer = -5.0f + sin(timePassed * 2.5) * 3.0;

	for(c = 0; c <= IMGAMOUNT; c++){
		drawImage(logo2, Images[c].x+sin(timePassed)*5+mover, Images[c].y, zoomer, Images[c].w, Images[c].h, 1.0f, 1.0f, 1.0f, 1.0f);
	}

	//moveImages(frameTime);
}

void moveImages(float frameTime){
	//unsigned int c = 0;

	//for(c = 0; c <= IMGAMOUNT; c++){
//		Images[c].y += frameTime * 4;
//
//		if(Images[c].y >= 10.0f){
//			Images[c].y = -10.0f;
//		}

	//}
}
