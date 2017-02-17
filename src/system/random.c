#include "random.h"
#include <stdlib.h>

float getRandomFloat(float low, float high){
	return low + (float)rand()/((float)RAND_MAX/(high-low));
}

unsigned int getRandomInt(unsigned int low, unsigned int high){
	return low + (rand() % high);
}
