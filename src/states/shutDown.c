#include "shutDown.h"

#include "../main.h"

#include "../system/graphics.h"
#include "../system/music.h"

void shutDownEnter(void){
	#ifdef MUSIC
	stopMusic();
	#endif

	stopGraphics();
}

void shutDownUpdate(float frameTime){
}

void shutDownExit(void){
}
