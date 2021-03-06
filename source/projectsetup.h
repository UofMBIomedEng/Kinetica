int worldtileviewrange=60;
bool usetextures=1;
bool ghostmode=0;
bool showminimap=0;

//danyal added

int stairtype=3;   //1=stairs at 180degrees, 2=stairs at 90 degrees, 3=ramp at 180degrees, 4=ramp at 90 degrees
bool allocentric=1;
bool kidmode=1;
bool animal_background_sound=1;
bool wheelchairmode=0;
float target_x=0,target_y=0,target_z=0;
const int target_offset=3;
bool sound=1;
int sound_delay=10;
//...

bool usemouse=0;
bool showplayer=0;
bool autoexit=0;
bool start_motion=0;
bool usejoystick=0;

JOYINFO joystick;

int collectablesfound=0;

const float playerwidth=1.25;
const float playerheight=2.25;
const float playerheadheight=(float)3.8;

float playerxpos=0,playerypos=0,playerzpos=0;
float playerxposmov=0,playeryposmov=0,playerzposmov=0;
bool playergrounded=0;
bool playerjumping=0;

int playerxgridpos=0;
int playerygridpos=0;
int playerzgridpos=0;

float camxpos=0,camypos=0,camzpos=0;
float camxang=0,camyang=0,camzang=0,tmpcamyang=0;
float nav_camxang=0,nav_camyang=0,nav_camzang=0;
float mouse_camxang=0,mouse_camyang=0,mouse_camzang=0;


//set up the foundation of the house
const int house_low_z = 18;
const int house_high_z = 30;
const int house_low_x = 18;
const int house_high_x = 30;

double elapsedtime=0;
double elapseddist=0;
double expectdist=0;
double starttime=0;
double start_time=0;
double motion_time=0;
bool starttimeflag=1;
int countdownjoystickstart=0;

int a_win_pos[4],b_win_pos[4],c_win_pos[4],d_win_pos[4];
int rand_sel;

int trial=1;
int win_clue;
int targetwin=0;

int test=24;

//danyal
const char mediadir[] = "Media/";
float *playervertexarray;
float *playertexturearray;
float *playernormalarray;
int playervertexcount;
GLuint playertexture;
//...

#include "tilenames.h"
#include "projectspecific/tiles.h"
#include "projectspecific/genworldgrid.h"

#include "projectspecific/entities.h"
#include "projectspecific/genentities.h"

#include "projectspecific/saveandload.h"

#include "projectspecific/minimap.h"

#include "projectspecific/play.h"
#include "projectspecific/drawworld.h"
#include "projectspecific/drawhud.h"

void projectsetup(){

	//feed info to the dashboard
	sprintf_s(dash_bars_gamename,"%s","The Virtual House");


//	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
//	glViewport(0,0,(GLsizei)screenw,(GLsizei)screenh);

	 glViewport(0, 0, (int)screenw, (int)screenh);
    glMatrixMode(GL_PROJECTION);




	//load world tiles
	loadtiles();

	//load entities
	//loadentities();

	//clean up
	genworldgrid_cleanup();

	//island streets and sidewalks
	genworldgrid_street();

	//side walk
	genworldgrid_sidewalk();

	//buildings
	genworldgrid_building();

	//danyal
	//load player mesh
	//generic reusable char array for filenames
	char filename[256];
	sprintf(filename,"%s%s",mediadir,"player.ms3d");
	loadms3d(filename,
		playerms3dmodel,
		playervertexarray,
		playertexturearray,
		playernormalarray,
		playervertexcount,1.0);

	//rig the texture coordinates
	for(int b=0; b<playervertexcount/3; b++){
		playertexturearray[b*3*2+0]=0;
		playertexturearray[b*3*2+1]=0;
		playertexturearray[b*3*2+2]=1;
		playertexturearray[b*3*2+3]=0;
		playertexturearray[b*3*2+4]=0;
		playertexturearray[b*3*2+5]=1;
	}
	//reset the player and entities if their status or the world couldnt be loaded
	//if(!loadedgamesave || !loadedworldgridgamesave){
		worldtileviewrange=45;
		usetextures=1;
		ghostmode=0;
		//collectablesfound=0;

		//setup the player and camera start position
		int x=worldgridsizex/6;
		int y=streetlevel;
		int z=worldgridsizez/2;
		
		playerxpos=x*worldtilesize;
		playerypos=y*worldtilesize;
		playerzpos=z*worldtilesize;	
		playerxposmov=0;
		playeryposmov=0;
		playerzposmov=0;
		playergrounded=0;
		playerjumping=0;
		playerxgridpos=x;
		playerygridpos=y;
		playerzgridpos=z;
		camxpos=playerxpos;
		camypos=playerypos;
		camzpos=playerzpos;
		camxang=0;
		camyang=0;
		camzang=0;
		//place entities
		//genentities();
		//save it
		//save();
	//}

	genminimap();

}
