#pragma once

typedef void (*voidFunctionPointer)(void);
typedef void (*pFuncPtrFloat)(float);

typedef struct{
	float time;
	voidFunctionPointer enter;
	pFuncPtrFloat update;
	voidFunctionPointer exit;
} State;

void initStateMachine(void);
void createState(voidFunctionPointer, pFuncPtrFloat, voidFunctionPointer, float);
void setActiveState(unsigned int);
void updateState(float, float);
void removeState(void);
