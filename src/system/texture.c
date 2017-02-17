#include "texture.h"

GLuint loadTextureFromMemory(unsigned char *pointerToTexture, unsigned int textureSize){
	GLuint newTexture = 0;
	glGenTextures(1, &newTexture);
	glBindTexture(GL_TEXTURE_2D, newTexture);

	glfwLoadMemoryTexture2D(pointerToTexture, textureSize, GLFW_BUILD_MIPMAPS_BIT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);	
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	return newTexture;
}
