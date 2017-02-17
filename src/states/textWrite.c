#include "textWrite.h"

#include "../system/color.h"
#include "../system/graphics.h"
#include "../system/quad.h"
#include "../system/image.h"

#include "../effects/YScrollingChessboard.h"
#include "../effects/YScrollingImages.h"

#include <math.h>

extern unsigned char guy;
extern unsigned int guy_len;

extern unsigned char img1;
extern unsigned int img1_len;

extern unsigned char img2;
extern unsigned int img2_len;

extern unsigned char img3;
extern unsigned int img3_len;

extern unsigned char img4;
extern unsigned int img4_len;

extern unsigned char img5;
extern unsigned int img5_len;

extern unsigned char img6;
extern unsigned int img6_len;

extern unsigned char img7;
extern unsigned int img7_len;

extern unsigned char img8;
extern unsigned int img8_len;

extern unsigned char img9;
extern unsigned int img9_len;

extern unsigned char img10;
extern unsigned int img10_len;

extern unsigned char img11;
extern unsigned int img11_len;

extern unsigned char img12;
extern unsigned int img12_len;

extern unsigned char bg1;
extern unsigned int bg1_len;

extern unsigned char bg2;
extern unsigned int bg2_len;

extern unsigned char bg3;
extern unsigned int bg3_len;

extern unsigned char bg4;
extern unsigned int bg4_len;

extern unsigned char bg5;
extern unsigned int bg5_len;

extern unsigned char bg6;
extern unsigned int bg6_len;

extern unsigned char bg7;
extern unsigned int bg7_len;

extern unsigned char bg8;
extern unsigned int bg8_len;

extern unsigned char bg9;
extern unsigned int bg9_len;

extern unsigned char bg10;
extern unsigned int bg10_len;

extern unsigned char bg11;
extern unsigned int bg11_len;

extern unsigned char bg12;
extern unsigned int bg12_len;

extern int syncer;

float pusher;

GLuint logo;
GLuint logo2;
GLuint logo3;

static unsigned int call = 0;

Color front;

void textWriteEnter(){
	pusher = 0.0f;

	front.r = 1.0f;
	front.g = 1.0f;
	front.b = 1.0f;
	front.a = 1.0f;

	logo3 = loadTextureFromMemory(&guy, guy_len);

	if(call == 0){
		front.r = 1.0f;
		front.b = 0.4f;
		front.g = 0.2f;
		front.a = 1.0f;
		logo = loadTextureFromMemory(&img1, img1_len);
		logo2 = loadTextureFromMemory(&bg1, bg1_len);
	}else if(call == 1){
		front.r = 0.2f;
		front.b = 0.7f;
		front.g = 0.2f;
		front.a = 1.0f;
		logo = loadTextureFromMemory(&img2, img2_len);
		logo2 = loadTextureFromMemory(&bg2, bg2_len);
	}else if(call == 2){
		front.r = 0.7f;
		front.b = 0.2f;
		front.g = 0.2f;
		front.a = 1.0f;
		logo = loadTextureFromMemory(&img3, img3_len);
		logo2 = loadTextureFromMemory(&bg3, bg3_len);
	}else if(call == 3){
		front.r = 0.6f;
		front.b = 0.5f;
		front.g = 0.3f;
		front.a = 1.0f;
		logo = loadTextureFromMemory(&img4, img4_len);
		logo2 = loadTextureFromMemory(&bg4, bg4_len);
	}else if(call == 4){
		front.r = 0.2f;
		front.g = 0.3f;
		front.b = 0.8f;
		front.a = 1.0f;
		logo = loadTextureFromMemory(&img5, img5_len);
		logo2 = loadTextureFromMemory(&bg5, bg5_len);
	}else if(call == 5){
		front.r = 0.8f;
		front.g = 0.6f;
		front.b = 0.0f;
		front.a = 1.0f;
		logo = loadTextureFromMemory(&img6, img6_len);
		logo2 = loadTextureFromMemory(&bg6, bg6_len);
	}else if(call == 6){
		front.r = 0.4f;
		front.g = 0.2f;
		front.b = 0.1f;
		front.a = 1.0f;
		logo = loadTextureFromMemory(&img7, img7_len);
		logo2 = loadTextureFromMemory(&bg7, bg7_len);
	}else if(call == 7){
		front.r = 0.1f;
		front.g = 0.7f;
		front.b = 0.4f;
		front.a = 1.0f;
		logo = loadTextureFromMemory(&img8, img8_len);
		logo2 = loadTextureFromMemory(&bg8, bg8_len);
	}else if(call == 8){
		front.r = 0.7f;
		front.g = 0.3f;
		front.b = 0.6f;
		front.a = 1.0f;
		logo = loadTextureFromMemory(&img9, img9_len);
		logo2 = loadTextureFromMemory(&bg9, bg9_len);
	}else if(call == 9){
		front.r = 0.2f;
		front.g = 0.7f;
		front.b = 0.2f;
		front.a = 1.0f;
		logo = loadTextureFromMemory(&img10, img10_len);
		logo2 = loadTextureFromMemory(&bg10, bg10_len);
	}else if(call == 10){
		front.r = 0.6f;
		front.g = 0.0f;
		front.b = 0.0f;
		front.a = 1.0f;
		logo = loadTextureFromMemory(&img11, img11_len);
		logo2 = loadTextureFromMemory(&bg11, bg11_len);
	}else if(call == 11){
		front.r = 0.8f;
		front.g = 0.7f;
		front.b = 0.0f;
		front.a = 1.0f;
		logo = loadTextureFromMemory(&img12, img12_len);
		logo2 = loadTextureFromMemory(&bg12, bg12_len);
	}
	glClearColor(front.r, front.g, front.b, 1.0f);
	createImages();
	call++;
}

void textWriteUpdate(float frameTime){
	static float timePassed = 0.0f;
	float z = -1.5f;
	float x;

	if(call % 2 == 0){
		x = -0.9f;
	}else{
		x = -0.2f;
	}

	timePassed += frameTime;

	if(syncer == 1){
		pusher = -0.2f;
		syncer = 0;
	}

	if(pusher <= 0.4f){
		pusher += frameTime * 0.3;
	}

	setPerspective(45.0f);

	glPushMatrix();

	glRotatef(timePassed * 50.f, 0.0f, 0.0f, 1.0f);

	drawImages(frameTime);
	glPopMatrix();

	drawImage(logo, x+0.02f, -0.52f+sin(timePassed*5) * 0.1, z-pusher, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.5f);
	drawImage(logo, x, -0.5f+sin(timePassed*5) * 0.1, z-pusher, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);

	if(call % 2 == 0){
		drawQuad(0.5f, -1.0f, -2.0f, 1.0f, 2.0f, front.r-0.2f, front.g-0.2f, front.b-0.2f, 0.6f);
		drawImage(logo3, 0.5f, -1.12f, -2.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);

		glLoadIdentity();
		glTranslatef(0.95f,0.1f,-2.0f);
		glRotatef(timePassed*150,1.0f,1.0f,sin(timePassed));
		drawCube(0.2f,0.5f);
		glRotatef(timePassed*100,1.0f,1.0f,cos(timePassed));
		drawCube(0.22f,0.5f);
		glRotatef(timePassed*150,-1.0f,-1.0f,sin(timePassed));
		drawCube(0.19f,0.5f);
		glLoadIdentity();
	}else{
		drawQuad(-1.5f, -1.0f, -2.0f, 1.0f, 2.0f, front.r-0.2f, front.g-0.2f, front.b-0.2f, 0.6f);
		drawImage(logo3, -1.5f, -1.12f, -2.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);

		glLoadIdentity();
		glTranslatef(-0.95f,0.1f,-2.0f);
		glRotatef(timePassed*150,-1.0f,1.0f,-sin(timePassed));
		drawCube(0.2f,0.5f);
		glRotatef(timePassed*100,1.0f,1.0f,cos(timePassed));
		drawCube(0.22f,0.5f);
		glRotatef(timePassed*150,-1.0f,-1.0f,sin(timePassed));
		drawCube(0.19f,0.5f);
		glLoadIdentity();
	}
}

void textWriteExit(){
}
