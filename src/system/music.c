#include "music.h"

#include <windows.h>
#include <wtypes.h>
#include <stdio.h>

#include "../main.h"

#include "../../lib/bassmod.h"
#include "graphics.h"

extern unsigned char soundtrack;
extern unsigned int soundtrack_len;

extern int syncer;

void CALLBACK MySyncProc(HSYNC handle, DWORD data, DWORD user) {
	syncer = 1;
}

void startMusic(void){
	BASSMOD_Init(-1, 44100, 0);
	BASSMOD_MusicLoad(1, &soundtrack, 0, soundtrack_len, 4);
	BASSMOD_MusicSetSync(BASS_SYNC_MUSICFX, 1, &MySyncProc, 0);
	BASSMOD_MusicPlay();
}

void stopMusic(void){
	BASSMOD_MusicStop();
	BASSMOD_MusicFree();
	BASSMOD_Free();
}
