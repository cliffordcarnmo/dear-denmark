#include "quad.h"
#include "graphics.h"

void drawQuad(float x, float y, float z, float w, float h, float r, float g, float b, float a){
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(x, y, z);

	glColor4f(r, g, b, a);

	glBegin(GL_QUADS);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f + h, 0.0f);
	glVertex3f(0.0f + w, 0.0f + h, 0.0f);
	glVertex3f(0.0f + w, 0.0f, 0.0f);
	glEnd();

	glPopMatrix();
}

void drawTexturedQuad(float x, float y, float z, float w, float h, float u1, float v1, float u2, float v2) {
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(x, y, z);

	glBegin(GL_QUADS);
	glTexCoord3f(u1, v1, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glTexCoord3f(u1, v2, 0.0f);
	glVertex3f(0.0f, 0.0f + h, 0.0f);
	glTexCoord3f(u1 + u2, v2, 0.0f);
	glVertex3f(0.0f + w, 0.0f + h, 0.0f);
	glTexCoord3f(u1 + u2, v1, 0.0f);
	glVertex3f(0.0f + w, 0.0f, 0.0f);

	glEnd();

	glPopMatrix();
}

void drawCube(float size, float trans){
	glBegin(GL_POLYGON);
	glColor4f( 0.0f, 0.0f, 0.0f,trans );
	glVertex3f(  size, -size, -size );      // P1 is red
	glVertex3f(  size,  size, -size );      // P2 is green
	glVertex3f( -size,  size, -size );      // P3 is blue
	glVertex3f( -size, -size, -size );      // P4 is purple
	glEnd();

	glBegin(GL_POLYGON);
	glColor4f( 0.0f, 0.0f, 0.0f,trans );
	glVertex3f(  size, -size, size );
	glVertex3f(  size,  size, size );
	glVertex3f( -size,  size, size );
	glVertex3f( -size, -size, size );
	glEnd();

	// Purple side - RIGHT
	glBegin(GL_POLYGON);
	glColor4f( 0.0f, 0.0f, 0.0f,trans );
	glVertex3f( size, -size, -size );
	glVertex3f( size,  size, -size );
	glVertex3f( size,  size,  size );
	glVertex3f( size, -size,  size );
	glEnd();

	// Green side - LEFT
	glBegin(GL_POLYGON);
	glColor4f( 0.0f, 0.0f, 0.0f,trans );
	glVertex3f( -size, -size,  size );
	glVertex3f( -size,  size,  size );
	glVertex3f( -size,  size, -size );
	glVertex3f( -size, -size, -size );
	glEnd();

	// Blue side - TOP
	glBegin(GL_POLYGON);
	glColor4f( 0.0f, 0.0f, 0.0f,trans );
	glVertex3f(  size,  size,  size );
	glVertex3f(  size,  size, -size );
	glVertex3f( -size,  size, -size );
	glVertex3f( -size,  size,  size );
	glEnd();

	// Red side - BOTTOM
	glBegin(GL_POLYGON);
	glColor4f( 0.0f, 0.0f, 0.0f,trans );
	glVertex3f(  size, -size, -size );
	glVertex3f(  size, -size,  size );
	glVertex3f( -size, -size,  size );
	glVertex3f( -size, -size, -size );
	glEnd();}
