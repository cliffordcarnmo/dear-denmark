#include "creds.h"

#include "../system/graphics.h"
#include "../system/image.h"

#include <math.h>

static Triangle Triangles[7];

extern unsigned char credits;
extern unsigned int credits_len;

extern int syncer;

float pusher;

static GLuint logo;

void credsEnter(){
	unsigned int counter;
	float angle;
	float z = -10.0;
	float OBJECTSIZE = 18.0;

	pusher = 0.0f;

	logo = loadTextureFromMemory(&credits, credits_len);

	setPerspective(90.0f);
	glClearColor(0.3f, 0.7f, 0.8f, 1.0f);

	for(counter = 0; counter < 7; counter++){
		angle = counter * 2 * M_PI / 7;

		Triangles[counter].x = cos(angle);
		Triangles[counter].y = sin(angle);
		Triangles[counter].z = z;

		Triangles[counter].p[0].v1 = cos(angle) * OBJECTSIZE;
		Triangles[counter].p[0].v2 = sin(angle) * OBJECTSIZE;
		Triangles[counter].p[0].v3 = z;

		Triangles[counter].p[1].v1 = cos(angle + (-2 * M_PI / 3)) * OBJECTSIZE;
		Triangles[counter].p[1].v2 = sin(angle + (-2 * M_PI / 3)) * OBJECTSIZE;
		Triangles[counter].p[1].v3 = z;

		Triangles[counter].p[2].v1 = cos(angle + (-2 * M_PI / 3) * 2) * OBJECTSIZE;
		Triangles[counter].p[2].v2 = sin(angle + (-2 * M_PI / 3) * 2) * OBJECTSIZE;
		Triangles[counter].p[2].v3 = z;
	}

}

void credsUpdate(float frameTime){
	static float timePassed = 0.0f;

	static unsigned int counter;
	static unsigned int counter2;

	float z = -10.0;
	float z2 = -0.8f;

	timePassed += frameTime;

	if(syncer==1){
		pusher = -0.2f;
		syncer = 0;
	}

	pusher += frameTime * 0.3;

	for(counter = 0; counter < 7; counter++){
		glLoadIdentity();
		glTranslatef(0.0, 0.0, z);
		glRotatef(timePassed * 50, 0.0, 0.0, 1.0);
		glTranslatef(-0.0, -0.0, 0.0);

		glColor4f(0.2f, 0.5f, 0.8f, 1.0);

		glBegin(GL_TRIANGLES);

		for(counter2 = 0; counter2 < 3; counter2++){
			glVertex3f(Triangles[counter].p[counter2].v1, Triangles[counter].p[counter2].v2, Triangles[counter].p[counter2].v3);
		}

		glEnd();

		glLoadIdentity();
		glTranslatef(1.5, -1.5, -11.0);
		glRotatef(timePassed*50, 0.0, 0.0, 1.0);
		glTranslatef(-0.0, -0.0, 0.0);

		glColor4f(0.0f, 0.0f, 0.0f, 1.0);

		glBegin(GL_TRIANGLES);

		for(counter2 = 0; counter2 < 3; counter2++){
			glVertex3f(Triangles[counter].p[counter2].v1, Triangles[counter].p[counter2].v2, Triangles[counter].p[counter2].v3);
		}

		glEnd();

	}

	glLoadIdentity();
	drawImage(logo, -0.46f, -0.52f, z2-pusher, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.5f);
	drawImage(logo, -0.48f, -0.5f, z2-pusher, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
}

void credsExit(){

}
