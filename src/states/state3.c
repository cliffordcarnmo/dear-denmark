#include "state3.h"

#include "../system/graphics.h"
#include "../system/image.h"

float zoomer;
float timePassed;

GLuint logo;

static unsigned int call = 0;

extern unsigned char flag;
extern unsigned int flag_len;

void state3Enter(void){
	setPerspective(45.0f);
	zoomer = 0.0f;
	timePassed = 0.0f;
	logo = loadTextureFromMemory(&flag, flag_len);

	if(call % 2 == 0){
		glClearColor(0.5f, 0.5f, 1.0f, 1.0f);
	}else{
		glClearColor(1.0f, 0.7f, 0.0f, 1.0f);
	}

	call++;
}	

void state3Update(float frameTime){
	timePassed += frameTime;
	zoomer = -20.0f + (timePassed * 20);

	float x = -0.5f;
	float y = -0.5f;
	float z = zoomer;
	float w = 1.0f;
	float h = 1.0f;

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, logo);


	glLoadIdentity();
	glPushMatrix();

	glRotatef(timePassed*350, 0.0f, 0.0f, -1.0f);

	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

	glBegin(GL_QUADS);
	glTexCoord3f(0.0f, 0.0f, z);
	glVertex3f(x, y, z);

	glTexCoord3f(0.0f, 0.0f + h, z);
	glVertex3f(x, y + h, z);

	glTexCoord3f(0.0f + w, 0.0f + h, z);
	glVertex3f(x + w, y + h, z);

	glTexCoord3f(0.0f + w, 0.0f, z);
	glVertex3f(x + w, y, z);
	glEnd();

	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
}

void state3Exit(void){
}
