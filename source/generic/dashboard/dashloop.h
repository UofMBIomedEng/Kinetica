void dashloop(){

	//adjust the speed of the game based on the frame rate
	float dashspeed=60.f/dash_framerate;
	//if(dashspeed<0.2f)dashspeed=0.2f;
	//if(dashspeed>2.0f)dashspeed=2.0f;
	dashspeed=1.f;

	dashtime();
	dashonoff(dashspeed);
	if(dashonpercent!=0){
		dashbars();		
		dashmenu();
		dashcursors();
	}
	
	if(1){
		char temptext[256];
		sprintf_s(temptext,"%s%2.0f","FPS: ",dash_framerate);
		dashbutton(25,75,200,10,0,0,(char*)temptext);
	}

}