//super ultra mega generic includes
#include <windows.h>
#include <sdl.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <sdl_opengl.h>
#include <time.h>

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <vector>

#include <iostream>
using std::cerr;
using std::cout;
using std::endl;
#include <fstream>
using std::ofstream;
using std::ifstream;
#include <cstdlib>
#include <string>

#include <stdlib.h>
#include <string.h>
#include <malloc.h>

//to read the joystick playing wave clips 
#include <Windows.h>
#include <MMSystem.h>
#pragma comment(lib,"Winmm.lib")

//super generic
#include "genericmath.h"
#include "readinifiles.h"
#include "genericsettings.h"
#include "dirlist.h"
#include "initvideo.h"
#include "input.h"
#include "bresenham.h"
#include "3dfunctions.h"
//3DMath.h is already included from within spherebumpmesh.h
//#include "3DMath.h"
#include "spherebumpmesh.h"
#include "loadobj.h"
#include "lodepng.h"
#include "loadbmp.h"
#include "loadms3d.h"

//specific to SDL surfaces

#include "sdldraw/loadanddrawsurfaces.h"
#include "sdldraw/getputpixel.h"
#include "sdldraw/drawcircle.h"
#include "sdldraw/drawline.h"
#include "sdldraw/drawpolygon.h"
#include "sdldraw/drawhexagon.h"
#include "sdldraw/filtersurface.h"
#include "sdldraw/rotoscale.h"
#include "sdldraw/savesurface.h"


//specific to OpenGL
#include "opengl/loadtexture.h"

int lang=1;   // 1=English 2=French 3=Spanish 4=German

//the dashboard and related functions
#include "dashboard/dashsetup.h"
#include "dashboard/dashloop.h"


void genericsetup(){
	//seed the random number generator
	srand((int)time(NULL));

	//setup the screen or window
	initvideo();

	//setup for the controller input

	setupinput();
}