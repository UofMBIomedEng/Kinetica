void projectloop(){
	
	//adjust the speed of the game based on the frame rate
	float gamespeed=60.f/dash_framerate;
	if(gamespeed<0.2f)gamespeed=0.2f;
	if(gamespeed>2.0f)gamespeed=2.0f;

	//elapsed time
	elapsedtime=(double)SDL_GetTicks()-starttime;

	//play
	play(gamespeed);

	//draw
	drawworld();
	drawhud();

}
