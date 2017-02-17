#include "stateMachine.h"

#include "../main.h"

#include "graphics.h"
#include "infoWriter.h"

static unsigned int stateCounter;
static unsigned int currentState;
static State states[64];

void initStateMachine(){
	stateCounter = 0;
	currentState = 0;
}

void createState(voidFunctionPointer enter, pFuncPtrFloat update, voidFunctionPointer exit, float time){
	states[stateCounter].enter = enter;
	states[stateCounter].update = update;
	states[stateCounter].exit = exit;
	states[stateCounter].time = time;

	stateCounter++;
}

void setActiveState(unsigned int stateIndex){
	if(currentState > 0 && states[currentState].exit != 0){
		states[currentState].exit();
	}
	
	currentState = stateIndex;
	
	if (states[currentState].enter != 0){
		states[currentState].enter();
	}
}

void updateState(float frameTime, float time){
	static float effectTime = 0.0f;
	effectTime += frameTime;
	
	if (currentState < stateCounter - 1){
		if (effectTime >= states[currentState].time){
			setActiveState(currentState + 1);
			effectTime = 0;
		}
	}
	
	clearScreen();
	states[currentState].update(frameTime);
	updateGraphics();

	#ifdef VERBOSE
	infoWriter("[PROTOS]", currentState, time, effectTime, frameTime);
	#endif
}

void removeState(void){
	states[stateCounter - 1].enter = 0;
	states[stateCounter - 1].update = 0;
	states[stateCounter - 1].exit = 0;
	stateCounter--;
}
