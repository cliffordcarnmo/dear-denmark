#include "prodName.h"

#include "../system/graphics.h"
#include "../system/image.h"
#include "../system/quad.h"

#include <math.h>

extern unsigned char pe;
extern unsigned int pe_len;

static GLuint logo;

extern int syncer;

void prodNameEnter(void){
	setPerspective(50.0f);
	logo = loadTextureFromMemory(&pe, pe_len);
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
}

void prodNameUpdate(float frameTime){
	static float timePassed = 0.0f;
//	static float fader = 1.0f;
//	static float logoY = 0.0f;
	static float zoomer = -3.0f;
	static float pusher = 0.0f;

	timePassed += frameTime;

	if(syncer==1){
		pusher += 0.5f;
		syncer = 0;
	}

	if(zoomer <= 2.0f){
		zoomer = timePassed * 0.40;
	}

	drawImage(logo, -0.48f, -0.52f, -3.0f + zoomer - pusher, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.5f);
	drawImage(logo, -0.5f, -0.5f, -3.0f + zoomer - pusher, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);

	/*
	if(zoomer >= -1.0f){
		if(logoY <= 1.0f){
			logoY += frameTime * 2;
		}
		if(fader <= 1.0f){
			fader -= frameTime * 4;
		}
		drawImage(logo, -0.5f, -0.5f+logoY, -1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, fader);
	}else{
		drawImage(logo, -0.5f, -0.5f, zoomer, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
	}
	*/

}

void prodNameExit(void){
}
