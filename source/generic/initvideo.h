SDL_Surface *screen;

float background_color[4]={0, 0.16, 0.35, 1};      // bakgournd sky color
float fog_color[4]={0, 0.16, 0.35, 0.1};			  // fog color	

void initopengl(){
    
    if (SDL_Init(SDL_INIT_VIDEO) < 0) exit(1);						//Initialize SDL
    
	SDL_WM_SetCaption( "TheKineticaEngin", NULL );				//Window Settings

	//enable anti aliasing
	if(antialiasing){
		SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
		SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4);
		glEnable(GL_MULTISAMPLE);
		glHint(GL_LINE_SMOOTH_HINT, GL_NICEST );
		glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST );
		glEnable(GL_LINE_SMOOTH);
		glEnable(GL_POLYGON_SMOOTH);
	}

	//Create Video Surface
	//there seems to be a problem with opengl plus a screen width or height of zero
	if(screenw==0 || screenh==0){
		screen = SDL_SetVideoMode((int)screenw,(int)screenh,screenbpp,SDL_DOUBLEBUF);
		screenw=(float)screen->w;
		screenh=(float)screen->h;
		screena = screenw/screenh;
		SDL_FreeSurface(screen);
	}

	if(fullscreen==1)
		screen = SDL_SetVideoMode((int)screenw,(int)screenh,screenbpp,SDL_OPENGL|SDL_FULLSCREEN);
		
	if(fullscreen==0)
		screen = SDL_SetVideoMode((int)screenw,(int)screenh,screenbpp,SDL_OPENGL);
	if (!screen) { SDL_Quit(); exit(3); }
	
	SDL_GL_SwapBuffers();

    //Size OpenGL to Video Surface
    glViewport(0, 0, (int)screenw, (int)screenh);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	gluPerspective(45.0,screena,1.0,1000.0);
    glMatrixMode(GL_MODELVIEW);

    //Set Pixel Format
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 5);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);


    //OpenGL Render Settings
	glClearColor(background_color[0],background_color[1],background_color[2],background_color[3]);							//background color  
    glClearDepth(1000.0);
    glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CCW);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glAlphaFunc(GL_GREATER,0.0f);

}

void initvideo(){

	//the setup
	initopengl();
	
	//get correct info about the screen
	screenw = (float)screen->w;
	screenh = (float)screen->h;
	screena = screenw/screenh;
	screenbpp = screen->format->BitsPerPixel;

	//show or hide the cursor
	SDL_ShowCursor(showcursor);

}