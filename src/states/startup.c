#include "startup.h"

#include "../main.h"

#include "../system/graphics.h"
#include "../system/music.h"

void startupEnter(void){
	startGraphics();

	#ifdef MUSIC
	startMusic();
	#endif
}

void startupUpdate(float frameTime){
}

void startupExit(void){
}
