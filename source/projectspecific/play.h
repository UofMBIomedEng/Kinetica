void play(float gamespeed){

		//decrease view range
		if(keystate[SDLK_1]==2){
			worldtileviewrange-=1;
			if(worldtileviewrange<1)worldtileviewrange=1;
		}
		//increase view range
		if(keystate[SDLK_2]==2){
			worldtileviewrange+=1;
			if(worldtileviewrange>60)worldtileviewrange=60;
		}


		//decrease view range
		if(keystate[SDLK_b]==2){
			test-=1;
			if(test<1)test=1;
			loadtiles();
		}
		//increase view range
		if(keystate[SDLK_n]==2){
			test+=1;
			if(test>60)test=60;
			loadtiles();
		}


		//textures on off
		if(keystate[SDLK_3]==2){
			if(usetextures){usetextures=0;}else{usetextures=1;}
		}
		//ghost mode on off
		if(keystate[SDLK_4]==2){
			if(ghostmode==1){ghostmode=0;}else{ghostmode=1;}
		}
		//previous tile
		if(keystate[SDLK_5]==2){
			worldgrid[playerxgridpos][playerygridpos][playerzgridpos][0]-=1;
			if(worldgrid[playerxgridpos][playerygridpos][playerzgridpos][0]<0)
				worldgrid[playerxgridpos][playerygridpos][playerzgridpos][0]+=worldtilecount;
		}
		//next tile
		if(keystate[SDLK_6]==2){
			worldgrid[playerxgridpos][playerygridpos][playerzgridpos][0]+=1;
			if(worldgrid[playerxgridpos][playerygridpos][playerzgridpos][0]>worldtilecount-1)
				worldgrid[playerxgridpos][playerygridpos][playerzgridpos][0]-=worldtilecount;
		}
		//rotate tile
		if(keystate[SDLK_7]==2){
			worldgrid[playerxgridpos][playerygridpos][playerzgridpos][1]+=1;
			if(worldgrid[playerxgridpos][playerygridpos][playerzgridpos][1]>3)
				worldgrid[playerxgridpos][playerygridpos][playerzgridpos][1]-=4;
		}
		//save everything
		if(keystate[SDLK_8]==2){
			saveworldgrid();
			save();
		}
		//load everything
		if(keystate[SDLK_9]==2){
			loadworldgrid();
			load();
		}


		//Mouse on off
		if(keystate[SDLK_m]==2){
			if(usemouse==1){usemouse=0;}else{usemouse=1;}
		}

		//Player on off
		if(keystate[SDLK_p]==2){
			if(showplayer==1){showplayer=0;}else{showplayer=1;}
		}

		//Autoexit on off
		if(keystate[SDLK_e]==2){
			if(autoexit==1){autoexit=0;}else{autoexit=1;}
		}

		//Joystick on off
		if(keystate[SDLK_j]==2){
			if(usejoystick==1){usejoystick=0;}else{usejoystick=1;}
		}

		//GPS Minimap on ff
		if(keystate[SDLK_g]==2){
			if(showminimap==1){showminimap=0;}else{showminimap=1;}
		}

		//Quit the game
		if(keystate[SDLK_q]==2)shutdownprogram=1;

	//update entities
	for(int x=highint(0,playerxgridpos-worldtileviewrange); x<lowint(worldgridsizex,playerxgridpos+worldtileviewrange+1); x++)
	for(int y=highint(0,playerygridpos-worldtileviewrange); y<lowint(worldgridsizey,playerygridpos+worldtileviewrange+1); y++)
	for(int z=highint(0,playerzgridpos-worldtileviewrange); z<lowint(worldgridsizez,playerzgridpos+worldtileviewrange+1); z++)
	for(int e=0; e<entitycount[x][y][z]; e++){
		if(entitylist[x][y][z][e]->type==entitytype_disccartridge){
			entitylist[x][y][z][e]->yang+=entitylist[x][y][z][e]->yangmov*gamespeed;
			if(dist3d(
				entitylist[x][y][z][e]->xpos,
				entitylist[x][y][z][e]->ypos,
				entitylist[x][y][z][e]->zpos,
				playerxpos,playerypos,playerzpos)<3.25f){
					delete entitylist[x][y][z][e];
					if(e<entitycount[x][y][z]-1)for(int b=e;b<entitycount[x][y][z];b++)entitylist[x][y][z][b]=entitylist[x][y][z][b+1];
					entitycount[x][y][z]-=1;
					e--;
					collectablesfound++;
					save();
			}
		}else if(entitylist[x][y][z][e]->type==entitytype_elevator){
			entitylist[x][y][z][e]->ypos+=entitylist[x][y][z][e]->yposmov*gamespeed;
			if(entitylist[x][y][z][e]->yposmov>0){
				if(x==playerxgridpos && z==playerzgridpos
				&& playerypos>entitylist[x][y][z][e]->ypos){
				if(worldgrid[x][y][z][0]==34 || worldgrid[x][y+1][z][0]==34)
					entitylist[x][y][z][e]->ypos-=entitylist[x][y][z][e]->yposmov*gamespeed;
				}
				if(worldgrid[x][y][z][0]==34
				&& entitylist[x][y][z][e]->ypos>y*worldtilesize){
					entitylist[x][y][z][e]->ypos=y*worldtilesize;
					entitylist[x][y][z][e]->yposmov*=-1;
				}
			}else{
				if(x==playerxgridpos && z==playerzgridpos
				&& playerypos<entitylist[x][y][z][e]->ypos-4.5f){
				if(worldgrid[x][y][z][0]==32 || worldgrid[x][y-1][z][0]==32)
					entitylist[x][y][z][e]->ypos-=entitylist[x][y][z][e]->yposmov*gamespeed;
				}
				if(worldgrid[x][y][z][0]==32
				&& entitylist[x][y][z][e]->ypos<y*worldtilesize){
					entitylist[x][y][z][e]->ypos=y*worldtilesize;
					entitylist[x][y][z][e]->yposmov*=-1;
				}
			}
		}
	}

	//update entity grid position
	for(int x=highint(0,playerxgridpos-worldtileviewrange); x<lowint(worldgridsizex,playerxgridpos+worldtileviewrange+1); x++)
	for(int y=highint(0,playerygridpos-worldtileviewrange); y<lowint(worldgridsizey,playerygridpos+worldtileviewrange+1); y++)
	for(int z=highint(0,playerzgridpos-worldtileviewrange); z<lowint(worldgridsizez,playerzgridpos+worldtileviewrange+1); z++)
	for(int e=0; e<entitycount[x][y][z]; e++){
		int xgridpos=(int)floor(entitylist[x][y][z][e]->xpos/worldtilesize+0.5f);
		int ygridpos=(int)floor(entitylist[x][y][z][e]->ypos/worldtilesize+0.5f);
		int zgridpos=(int)floor(entitylist[x][y][z][e]->zpos/worldtilesize+0.5f);
		if(x!=xgridpos || y!=ygridpos || z!=zgridpos)
		if(entitycount[xgridpos][ygridpos][zgridpos]<maxentities){
			entitylist[xgridpos][ygridpos][zgridpos][(int)entitycount[xgridpos][ygridpos][zgridpos]]=entitylist[x][y][z][e];
			entitycount[xgridpos][ygridpos][zgridpos]+=1;
			removeentityfromlist(x,y,z,e);
		}
	}

	//turn the camera

	//if(!mousestate[SDL_BUTTON_RIGHT])

	//remember where the player started
	float oldx=playerxpos;
	float oldy=playerypos;
	float oldz=playerzpos;

	if(usemouse){

		if(dashusecursor[0]){
			camyang += ((float)cursorx[0]*2.f-screenw)/screenw*0.05f*gamespeed;
			camxang -= ((float)cursory[0]*2.f-screenh)/screenh*0.04f*gamespeed;
		}
	
		//dont look too far up or down
		if(camxang<0-90*radiansindegree)camxang=0-90*radiansindegree;//looking down
		if(camxang>0+90*radiansindegree)camxang=0+90*radiansindegree;//looking up
	
		//move based on input
		float movespeed=0;
		float moveangle=0;
		bool up=0,down=0,left=0,right=0;
		if(keystate[SDLK_w]|keystate[SDLK_UP])up=1;
		if(keystate[SDLK_s]|keystate[SDLK_DOWN])down=1;
		if(keystate[SDLK_a]|keystate[SDLK_LEFT])left=1;
		if(keystate[SDLK_d]|keystate[SDLK_RIGHT])right=1;
		moveangle=atan2((float)right-(float)left,(float)up-(float)down);
		movespeed=dist2d((float)right-(float)left,(float)up-(float)down,0,0);
		if(movespeed>1)movespeed=1;
		if(movespeed>0.1){
			if(ghostmode)
				movein3dspace(playerxposmov,playeryposmov,playerzposmov,camyang,camxang,movespeed*0.2f*gamespeed);
			else{
				playerxposmov+=movespeed*cos(camyang+moveangle)*0.04f*gamespeed;
				playerzposmov+=movespeed*sin(camyang+moveangle)*0.04f*gamespeed;
			}
		}
	}
	else{

		//Arrow key control
		
		float movespeed=0;
		float moveangle=0;
		bool up=0,down=0;
		if(keystate[SDLK_UP])up=1;
		if(keystate[SDLK_DOWN])down=1;
		moveangle=atan2(0,(float)up-(float)down);
		movespeed=dist2d(0,(float)up-(float)down,0,0);
		if(movespeed>1)movespeed=1;
		if(movespeed>0.1){
			if(ghostmode)
				movein3dspace(playerxposmov,playeryposmov,playerzposmov,camyang,camxang,movespeed*0.2f*gamespeed);
			else{
				playerxposmov+=movespeed*cos(camyang+moveangle)*0.04f*gamespeed;
				playerzposmov+=movespeed*sin(camyang+moveangle)*0.04f*gamespeed;
			}
		}
	
		if(keystate[SDLK_LEFT])
			camyang-=0.01f*gamespeed;

		if(keystate[SDLK_RIGHT])
			camyang+=0.01f*gamespeed;
	}

	if(usejoystick){											//Joystick control	
		if(joyGetPos(0,&joystick))	usejoystick=0;				//obtain joystick value and check the presence
		else{
			
			if((32768-(float)joystick.wYpos>6500)||(32768-(float)joystick.wYpos<-6500)){
				playerxposmov+=(32768-(float)joystick.wYpos)*(0.03/32768)*gamespeed*cos(camxang)*cos(camyang);
				playeryposmov-=(32768-(float)joystick.wYpos)*(0.03/32768)*gamespeed*sin(camxang);
				playerzposmov+=(32768-(float)joystick.wYpos)*(0.03/32768)*gamespeed*cos(camxang)*sin(camyang);
			}

			//for turning
			if(((float)joystick.wXpos-32768>6500)||((float)joystick.wXpos-32768<-6500)) camyang+=((float)joystick.wXpos-32768)*(0.01/32768)*gamespeed;	

			//for tilting
			camxang=((float)joystick.wZpos-32768)*(45*radiansindegree/32768);	
		}
	}
	else
		camxang=0;

	//gravity and jumping
	if(ghostmode==0){
		if(playergrounded){
			playerjumping=0;
			playeryposmov-=0.01f*gamespeed;
			if(keystate[SDLK_SPACE]){
				playeryposmov=0.65f;
				playerjumping=1;
			}
		}else if(playerjumping){
			playeryposmov-=(0.03f-playeryposmov*0.08f)*gamespeed;
			
			if(keystate[SDLK_SPACE] && playeryposmov>0.1)
				playerjumping=1;
			else
				playerjumping=0;
			
		}else{
			playeryposmov-=0.035f*gamespeed;
		}
	}

	//movement takes effect
	playerxpos+=playerxposmov*gamespeed;
	playerypos+=playeryposmov*gamespeed;
	playerzpos+=playerzposmov*gamespeed;

	//bump into the world
	if(ghostmode==0){
		playerypos+=playerheight;
		int lowx=highint(playerxgridpos-2,0);
		int lowy=highint(playerygridpos-2,0);
		int lowz=highint(playerzgridpos-2,0);
		int highx=lowint(playerxgridpos+2+1,worldgridsizex);
		int highy=lowint(playerygridpos+2+1,worldgridsizey);
		int highz=lowint(playerzgridpos+2+1,worldgridsizez);
		for(int x=lowx; x<highx; x++)
		for(int y=lowy; y<highy; y++)
		for(int z=lowz; z<highz; z++){
			if(worldgrid[x][y][z][0]!=0)
				spherebumpmesh(playerxpos,playerypos,playerzpos,
				playerwidth,//playerwidth/playerheight,
				x*worldtilesize,y*worldtilesize,z*worldtilesize,0,
				worldtilecollisionmesh[(int)worldgrid[x][y][z][0]][(int)worldgrid[x][y][z][1]],
				1,0);
			for(int a=0; a<entitycount[x][y][z]; a++){
				if(entitytypesolid[entitylist[x][y][z][a]->type]==1){
					spherebumpmesh(playerxpos,playerypos,playerzpos,
					playerwidth,//playerwidth/playerheight,
					entitylist[x][y][z][a]->xpos,
					entitylist[x][y][z][a]->ypos,
					entitylist[x][y][z][a]->zpos,
					entitylist[x][y][z][a]->yang,
					entitycollisionmesh[entitylist[x][y][z][a]->type],1,0);
				}
			}
		}
		for(int x=lowx; x<highx; x++)
			for(int y=lowy; y<highy; y++)
				for(int z=lowz; z<highz; z++)
					if(worldgrid[x][y][z][0]){
						if(worldgrid[x][y][z][0]!=0)
							spherebumpmesh(playerxpos,playerypos,playerzpos,
							playerwidth,//playerwidth/playerheight,
							x*worldtilesize,y*worldtilesize,z*worldtilesize,0,
							worldtilecollisionmesh[(int)worldgrid[x][y][z][0]][(int)worldgrid[x][y][z][1]],
							0,1);
						for(int a=0; a<entitycount[x][y][z]; a++){
							if(entitytypesolid[entitylist[x][y][z][a]->type]==1){
								spherebumpmesh(playerxpos,playerypos,playerzpos,
								playerwidth,//playerwidth/playerheight,
								entitylist[x][y][z][a]->xpos,
								entitylist[x][y][z][a]->ypos,
								entitylist[x][y][z][a]->zpos,
								entitylist[x][y][z][a]->yang,
								entitycollisionmesh[entitylist[x][y][z][a]->type],0,1);
							}
						}
					}
		playerypos-=playerheight;
		if(playerypos>(float)(oldy+playeryposmov*gamespeed)+0.001){
			playergrounded=1;
		}else{
			playergrounded=0;
		}
	}
	//adjust momentum
	playerxposmov=(playerxpos-oldx)/gamespeed;
	playeryposmov=(playerypos-oldy)/gamespeed;
	playerzposmov=(playerzpos-oldz)/gamespeed;
	//lose momentum
	if(ghostmode){
		playerxposmov-=playerxposmov*0.1f*gamespeed;
		playeryposmov-=playeryposmov*0.1f*gamespeed;
		playerzposmov-=playerzposmov*0.1f*gamespeed;
	}else{
		playerxposmov-=playerxposmov*0.10f*gamespeed;
		playeryposmov-=playeryposmov*0.04f*gamespeed;
		playerzposmov-=playerzposmov*0.10f*gamespeed;
	}

	//update the players grid position
	playerxgridpos=(int)((playerxpos+worldtilesize*0.5)/worldtilesize);
	playerygridpos=(int)((playerypos+worldtilesize*0.5)/worldtilesize);
	playerzgridpos=(int)((playerzpos+worldtilesize*0.5)/worldtilesize);

	//position camera
	camxpos=playerxpos;
	camypos=playerypos+playerheadheight;
	camzpos=playerzpos;
	
}
