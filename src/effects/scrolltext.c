#include "scrolltext.h"

#include "../system/graphics.h"
#include "../system/image.h"

#include <math.h>

extern unsigned char img1;
extern unsigned int img1_len;

static GLuint texture;

void createText(){
	texture = loadTextureFromMemory(&img1, img1_len);
}

void drawText(float frameTime){
	static float timePassed = 0.0f;
	timePassed += frameTime;
	int i;
	float x,y,z,w,h,r,g,b,a;

	glPushMatrix();

	glTranslatef(-1.0f,-0.5f,-2.0f);
	glRotatef((float) glfwGetTime() * 50.f, 0.0f, -1.0f, 0.0f);
	glTranslatef(1.0f,0.5f,2.0f);

	for(i = 0; i <= 25; i++){
		x = -1.3f + sin(5*timePassed+i) * 0.1f;
		y = -1.0f + i * 0.1;
		z = -2.0f;
		r = 1.0f;
		g = 1.0f;
		b = 1.0f;
		a = 1.0f;
		w = 0.5f;
		h = 0.4f;


//		glLoadIdentity();
//		glTranslatef(-0.0f,-0.0f,0.0f);
//		glRotatef(timePassed*50,0.0f,1.0f,0.0f);
//		glTranslatef(0.0f,0.0f,0.0f);

		drawImage(texture,x,y,z,w,h,r,g,b,a);
	}
	glPopMatrix();
}

void moveText(float frameTime){
}
