#include "end.h"

#include "../system/graphics.h"
#include "../system/image.h"

#include <math.h>

extern unsigned char bye;
extern unsigned int bye_len;

static GLuint logo;
float zoomer;

void endEnter(void){
	setPerspective(50.0f);
	logo = loadTextureFromMemory(&bye, bye_len);
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
}

void endUpdate(float frameTime){
	static float timePassed = 0.0f;

	timePassed += frameTime;
	zoomer = -4.0f + (timePassed * 0.45);

	drawImage(logo, -0.48f, -0.52f, zoomer, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.5f);
	drawImage(logo, -0.5f, -0.5f, zoomer, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
}

void endExit(void){
}
