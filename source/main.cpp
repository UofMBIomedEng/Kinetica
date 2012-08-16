bool shutdownprogram = 0;

#include "generic.h"
#include "settings.h"
#include "projectsetup.h"
#include "projectloop.h"

int main(int argc,char **argv){

	for(int i=1;i<argc;i++){
		if(!strcmp(argv[i],"/TEST")) test=atoi(argv[i+1]);
    }
	
	loadgenericsettings();									//load the generic settings

	loadsettings();											//load the project specific settings

	genericsetup();											//generic setup

	dashsetup();											//setup the dashboard

	projectsetup();											//setup for the project

	//game loop
	while(!shutdownprogram){

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	//clear the screen
		
		SDL_PumpEvents();									//get what events have occured
		
		updateinput();										//get controller input

		if(!dashonpercent)projectloop();					//update the game

		dashloop();											//update the dashboard

		//show the frame
		SDL_GL_SwapBuffers();

		//clear out left over events and shut down when appropriate
		SDL_Event event;
		while(SDL_PeepEvents(&event,1,SDL_GETEVENT,SDL_ALLEVENTS)>0)
			if(event.type==SDL_QUIT)shutdownprogram=1;
    }
    // Clean up
	SKYBOX_Finalize();
    SDL_Quit();
    return 0;
}
