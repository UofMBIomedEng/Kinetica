void drawworld(){

	//set the draw distance for clipping and fog
	float camnear=0.1f;
	float camfar=worldtilesize*worldtileviewrange;

	//get cam view range
	int lowxview=highint(0,playerxgridpos-worldtileviewrange);
	int highxview=lowint(worldgridsizex,playerxgridpos+worldtileviewrange+1);
	int lowyview=highint(0,playerygridpos-worldtileviewrange);
	int highyview=lowint(worldgridsizey,playerygridpos+worldtileviewrange+1);
	int lowzview=highint(0,playerzgridpos-worldtileviewrange);
	int highzview=lowint(worldgridsizez,playerzgridpos+worldtileviewrange+1);

	//setup the camera
	set3dcamera(camxpos,camypos,camzpos,-camxang,camyang+90*radiansindegree,camzang,50,screena);

	//prep for drawing
	if(usetextures==1)glEnable(GL_TEXTURE_2D);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	//turn on lighting
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	GLfloat light_position0[] = {camxpos,camypos,camzpos,1.0};
	GLfloat light_ambient0[] = {1.0,1.0,1.0,1.0};
	GLfloat light_diffuse0[] = {1.0,1.0,1.0,1.0};
	GLfloat light_specular0[] = {1.0,1.0,1.0,1.0};
	glLightfv(GL_LIGHT0,GL_POSITION,light_position0);
	glLightfv(GL_LIGHT0,GL_AMBIENT,light_ambient0);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,light_diffuse0);
	glLightfv(GL_LIGHT0,GL_SPECULAR,light_specular0);
	glLightf(GL_LIGHT0,GL_LINEAR_ATTENUATION,0.0005f);
	glEnableClientState(GL_NORMAL_ARRAY);

	//turn on fog
	GLfloat fogColor[4]= {fog_color[0],fog_color[1],fog_color[2],fog_color[3]};             //fog color
	glFogi(GL_FOG_MODE,GL_LINEAR);
	glFogfv(GL_FOG_COLOR,fogColor);
	glFogf(GL_FOG_DENSITY,0.25f);
	glHint(GL_FOG_HINT,GL_DONT_CARE);
	glFogf(GL_FOG_START,0.1f);
	glFogf(GL_FOG_END,worldtilesize*worldtileviewrange);
	glEnable(GL_FOG);

	//draw the world tiles
	for(int x=lowxview; x<highxview; x++)
		for(int y=lowyview; y<highyview; y++)
			for(int z=lowzview; z<highzview; z++){
				int b=worldgrid[x][y][z][0];
				if(b>0){
					int c=worldgrid[x][y][z][1];
					glPushMatrix();
					glBindTexture(GL_TEXTURE_2D,worldtiletexture[b]);
					glTranslatef(x*worldtilesize,y*worldtilesize,z*worldtilesize);		
					draw3dtrianglemesh(worldtilevertexcount[b],	worldtilevertexarray[b][c],worldtiletexturearray[b],NULL,worldtilenormalarray[b][c]);
					glPopMatrix();
				}
			}

	/*
	//draw entities
	for(int x=lowxview; x<highxview; x++)
		for(int y=lowyview; y<highyview; y++)
			for(int z=lowzview; z<highzview; z++)
				for(int a=0; a<entitycount[x][y][z]; a++){
					int b=entitylist[x][y][z][a]->type;
					glPushMatrix();
					glTranslatef(entitylist[x][y][z][a]->xpos,entitylist[x][y][z][a]->ypos,entitylist[x][y][z][a]->zpos);
					glRotatef(entitylist[x][y][z][a]->yang*degreesinradian,0,1,0);
					draw3dtrianglemesh(entityvertexcount[b],entityvertexarray[b],entitytexturearray[b],NULL,entitynormalarray[b]);
					glPopMatrix();
				}
	*/

	//done drawing
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisable(GL_TEXTURE_2D);
	
	//turn off lighting
	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);

	//turn off fog
	glDisable(GL_FOG);

}
