#include "blank.h"

#include "../system/graphics.h"

void blankEnter(void){
	glClearColor(0.5f, 0.5f, 1.0f, 1.0f);
}

void blankUpdate(float frameTime){
	static float timePassed = 0.0f;
	static float fader = 1.0f;

	timePassed += frameTime;
	fader = timePassed * 0.5f;
	glClearColor(0.5f-fader, 0.5f-fader, 1.0f-fader, 1.0f);

}

void blankExit(void){
}
