int worldtileviewrange=60;
bool usetextures=1;
bool ghostmode=0;
bool showminimap=0;

bool usemouse=0;
bool showplayer=0;
bool autoexit=0;
bool showinfo=1;
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
float camxang=0,camyang=0,camzang=0;

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

	playerxpos=(worldtilesize*worldgridsizex/2)-((worldtilesize*worldgridsizex/3));     //Player startpoint
	playerypos=(streetlevel-0.45)*worldtilesize;
	playerzpos=(worldtilesize*worldgridsizex/2);

	//feed info to the dashboard
	sprintf_s(dash_bars_gamename,"%s","The Virtual Cross Section");

	//load world tiles
	loadtiles();

	//load entities
	loadentities();
	
	//load the game saves
	bool loadedgamesave=load();
	bool loadedworldgridgamesave=loadworldgrid();

	//generate a new world if one couldnt be loaded
	if(!loadedworldgridgamesave){

		//clean up
		genworldgrid_cleanup();

		//island streets and sidewalks
		genworldgrid_street();

		//side walk
		genworldgrid_sidewalk();

		//buildings
		genworldgrid_building();

		// box test
//		genworldgrid_box();

		//catacombs
		//genworldgrid_part4();
		//skywalks
		//genworldgrid_part5();
		//doors and elevators
		//genworldgrid_part6();
		//everything else
		//genworldgrid_part7();
		//save it
		//saveworldgrid();				//temporary to refresh the map for each time runnig
	}

	//reset the player and entities if their status or the world couldnt be loaded
	//if(!loadedgamesave || !loadedworldgridgamesave){
		worldtileviewrange=45;
		usetextures=1;
		ghostmode=0;
		collectablesfound=0;
		//setup the player and camera
		int x=worldgridsizex/2;
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
		genentities();
		//save it
		//save();
	//}

	genminimap();

}
