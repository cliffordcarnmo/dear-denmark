#include "graphics.h"
#include "../main.h"

#include <math.h>

void startGraphics(void){
	glfwInit();
	glfwSwapInterval(REFRESHRATE);
	glfwOpenWindowHint(WINDOWHINTS);
	glfwOpenWindow(WIDTH, HEIGHT, 8, 8, 8, 8, 24, 8, SCREENMODE);
	glfwSetWindowTitle(PRODNAME);
	
	#ifdef FULLSCREEN
	glfwDisable(GLFW_MOUSE_CURSOR);
	#endif

	glEnable(GL_BLEND);
	glEnable(GL_LINE_SMOOTH);

	/*
	 * GL_POLYGON_SMOOTH seems to produce visible triangles on some GPU cards
	 */

	//glEnable(GL_POLYGON_SMOOTH);
	glShadeModel(GL_SMOOTH);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void clearScreen(void){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void updateGraphics(void){
	glfwSwapBuffers();
}

void stopGraphics(void){
	glfwTerminate();
}

void setPerspective(float fov){
	glViewport(0, 0, WIDTH, HEIGHT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	newPerspective(fov, (float)WIDTH / (float)HEIGHT, 0.1f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
	glTranslatef(0.0f, 0.0f, 0.0f);
	glRotatef(0.0f, 0.0f, 0.0f, 0.0f);
}

void newPerspective(float fov, float aspect, float zmin, float zmax){
	float xmin, xmax, ymin, ymax;
	ymax = zmin * tan(fov * M_PI / 360.0);
	ymin = -ymax;
	xmin = ymin * aspect;
	xmax = ymax * aspect;
	glFrustum(xmin, xmax, ymin, ymax, zmin, zmax);
}
