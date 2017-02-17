#include "image.h"

void drawImage(GLuint textureID, float x, float y, float z, float w, float h, float r, float g, float b, float a){
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureID);
	
	glPushMatrix();

	glColor4f(r, g, b, a);

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
