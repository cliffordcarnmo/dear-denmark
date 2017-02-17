#include "infowriter.h"

#include <stdio.h>

void infoWriter(char* info, unsigned int currentState, float time, float timePassed, float frameTime){
	printf("%s state: %i, time: %f, effectTime: %f, frameTime: %f\r", info, currentState, time, timePassed, frameTime);
}
