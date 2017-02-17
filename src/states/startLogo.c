#include "startLogo.h"

#include "../system/graphics.h"
#include "../system/image.h"
#include "../system/quad.h"

#include <math.h>

extern unsigned char dd;
extern unsigned int dd_len;

static GLuint logo;
float zoomer;

void startLogoEnter(void){
	setPerspective(50.0f);
	logo = loadTextureFromMemory(&dd, dd_len);
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
}

void startLogoUpdate(float frameTime){
	static float timePassed = 0.0f;
	static float fader = 1.0f;
	static float logoY = 0.0f;

	timePassed += frameTime;
	zoomer = -3.0f + (timePassed * 0.35);

	if(zoomer >= -0.9f){
		if(logoY <= 1.0f){
			logoY += frameTime * 2;
		}
		if(fader <= 1.0f){
			fader -= frameTime * 4;
		}
		drawImage(logo, -0.5f, -0.5f+logoY, zoomer, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, fader);
	}else{
		drawImage(logo, -0.48f, -0.52f, zoomer, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.5f);
		drawImage(logo, -0.5f, -0.5f, zoomer, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
	}

//	if(zoomer >= -1.0f){
//		if(fader <= 1.0f){
//			fader += 0.05f;
//		}
//		//drawQuad(-0.5f, -1.0f, -1.0f, 1.0f, 2.0f, 0.0f, 0.0f, 0.0f, fader);
//	}
}

void startLogoExit(void){
}
