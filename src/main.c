#include "main.h"

#include "system/graphics.h"
#include "system/music.h"
#include "system/stateMachine.h"

#include "states/startup.h"
#include "states/startLogo.h"
#include "states/prodName.h"
#include "states/textWrite.h"
#include "states/state3.h"
#include "states/creds.h"
#include "states/greets.h"
#include "states/end.h"
#include "states/blank.h"
#include "states/shutDown.h"

#include <windows.h>

int syncer = 0;

int main(){
	double frameTime = 0.0;
	double time = 0.0;

	SetPriorityClass(GetCurrentProcess(), HIGH_PRIORITY_CLASS);
	SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_HIGHEST);

	initStateMachine();
	createState(startupEnter, startupUpdate, startupExit, 0.01f);

	createState(startLogoEnter, startLogoUpdate, startLogoExit, 6.56f);  //Dear Denmark
	createState(prodNameEnter, prodNameUpdate, prodNameExit,    6.56f);  //This is why we come back
	createState(textWriteEnter, textWriteUpdate, textWriteExit, 5.56f); //Pölse
	createState(state3Enter, state3Update, state3Exit,          1.0f);  //Flag
	createState(textWriteEnter, textWriteUpdate, textWriteExit, 5.56f); //Chair
	createState(state3Enter, state3Update, state3Exit,          1.0f);  //Flag
	createState(textWriteEnter, textWriteUpdate, textWriteExit, 5.56f); //Danish
	createState(state3Enter, state3Update, state3Exit,          1.0f);  //Flag
	createState(textWriteEnter, textWriteUpdate, textWriteExit, 5.56f); //Skatecop
	createState(state3Enter, state3Update, state3Exit,          1.0f);  //Flag
	createState(textWriteEnter, textWriteUpdate, textWriteExit, 5.56f); //Faxe Kondi
	createState(state3Enter, state3Update, state3Exit,          1.0f);  //Flag
	createState(textWriteEnter, textWriteUpdate, textWriteExit, 5.56f); //Bum
	createState(state3Enter, state3Update, state3Exit,          1.0f);  //Flag
	createState(credsEnter, credsUpdate, credsExit,             5.56f); //Credits
	createState(state3Enter, state3Update, state3Exit,          1.0f);  //Flag
	createState(greetsEnter, greetsUpdate, greetsExit,          5.56f); //Greets
	createState(state3Enter, state3Update, state3Exit,          1.0f);  //Flag
	createState(textWriteEnter, textWriteUpdate, textWriteExit, 5.56f); //Heels warning
	createState(state3Enter, state3Update, state3Exit,          1.0f);  //Flag
	createState(textWriteEnter, textWriteUpdate, textWriteExit, 5.56f); //Queen
	createState(state3Enter, state3Update, state3Exit,          1.0f);  //Flag
	createState(textWriteEnter, textWriteUpdate, textWriteExit, 5.56f); //Pants off
	createState(state3Enter, state3Update, state3Exit,          1.0f);  //Flag
	createState(textWriteEnter, textWriteUpdate, textWriteExit, 5.56f); //Cheese
	createState(state3Enter, state3Update, state3Exit,          1.0f);  //Flag
	createState(textWriteEnter, textWriteUpdate, textWriteExit, 5.56f); //Cheese
	createState(state3Enter, state3Update, state3Exit,          1.0f);  //Flag
	createState(textWriteEnter, textWriteUpdate, textWriteExit, 5.56f); //Cheese
	createState(state3Enter, state3Update, state3Exit,          1.0f);  //Flag
	createState(endEnter, endUpdate, endExit,                   6.56f);  //Sincerely, Sweden
	createState(state3Enter, state3Update, state3Exit,          1.0f);  //Flag
	createState(blankEnter, blankUpdate, blankExit, 2.0f);  			//Dear Denmark

	createState(shutDownEnter, shutDownUpdate, shutDownExit, 1.0f);
	setActiveState(0);

	while(!glfwGetKey(GLFW_KEY_ESC) && glfwGetWindowParam(GLFW_OPENED)){
		time = glfwGetTime();
		updateState(frameTime, time);
		frameTime = glfwGetTime() - time;
	}

	return 0;
}
