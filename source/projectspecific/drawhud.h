void drawhud(){

	set2dcamera(0,screenh,0,screenw);

	if(showminimap)drawminimap();

	char temptext[256];
	//danyal
	if(showinfo){
		switch(lang){
		case 1:   //English
			sprintf_s(temptext,"%s","All rights reserved to Neuro BME, University of Manitoba");
			break;
		case 2:   //French
			sprintf(temptext,"%s","Tous droits reserves a BME Neuro de l'Universite du Manitoba");
			break;
		case 3:   //Spanish
			sprintf(temptext,"%s","Todos los derechos reservados BME Neuro, Universidad de Manitoba");
			break;
		case 4:   //German
			sprintf(temptext,"%s","Alle Rechte vorbehalten fur Neuro BME, Universitas Manitoba");
			break;
		}
		dashbutton(25,315,600,10,0,0,(char*)temptext);

		switch(lang){
		case 1:
			/*
			sprintf_s(temptext,"%s%i%s","Collectables: ",collectablesfound,"/1000");
			dashbutton(25,105,300,10,0,0,(char*)temptext);
			*/
			sprintf_s(temptext,"%s%1d%s%1d%s%1d%s%1d%s%1d","Stat: M=",usemouse," P=",showplayer, " E=", autoexit, " J=", usejoystick, " S=", start_motion);
			dashbutton(25,135,300,10,0,0,(char*)temptext);

			sprintf_s(temptext,"%s%3.f%s%3.f%s%3.f","P:X=",playerxpos," Y=",playerypos, " Z=", playerzpos);
			dashbutton(25,165,300,10,0,0,(char*)temptext);
			/*
			sprintf_s(temptext,"%s%d","Test=",test);
			dashbutton(25,165,200,10,0,0,(char*)temptext);
			*/
			
			//elapsed time
			sprintf(temptext,"%s%.2f","Elapsed time: ",elapsedtime/1000);
			dashbutton(25,225,300,10,0,0,(char *)temptext);
			
			sprintf_s(temptext,"%s%2.0f","FPS: ",dash_framerate);
			dashbutton(25,255,300,10,0,0,(char*)temptext);
			//...
		break;
		case 2:
			/*
			sprintf_s(temptext,"%s%i%s","Collectables: ",collectablesfound,"/1000");
			dashbutton(25,105,200,10,0,0,(char*)temptext);
			*/
			sprintf_s(temptext,"%s%1d%s%1d%s%1d%s%1d%s%1d","Stat: M=",usemouse," P=",showplayer, " E=", autoexit, " J=", usejoystick, " S=", start_motion);
			dashbutton(25,135,300,10,0,0,(char*)temptext);

			sprintf_s(temptext,"%s%3.f%s%3.f%s%3.f","P:X=",playerxpos," Y=",playerypos, " Z=", playerzpos);
			dashbutton(25,165,300,10,0,0,(char*)temptext);
			/*
			sprintf_s(temptext,"%s%d","Essai=",test);
			dashbutton(25,165,200,10,0,0,(char*)temptext);
			*/
			//elapsed time
			sprintf(temptext,"%s%.2f","Temps Parcouru: ",elapsedtime/1000);
			dashbutton(25,225,300,10,0,0,(char *)temptext);
			
			sprintf_s(temptext,"%s%2.0f","FPS: ",dash_framerate);
			dashbutton(25,255,300,10,0,0,(char*)temptext);
			//...
		break;
		case 3:
		break;
		case 4:
		break;
		}
		switch(lang){
		case 1:
			if(allocentric){
				sprintf_s(temptext,"%s","Allocentric mode");
			}
			else{
				sprintf_s(temptext,"%s","Egocentric mode");
			}
			dashbutton(25,345,300,10,0,0,(char*)temptext);

			sprintf_s(temptext,"%s%.2f","Traversed distance [m]: ",elapseddist);
			dashbutton(25,75,300,10,0,0,(char*)temptext);

			sprintf_s(temptext,"%s%.2f","Expected distance [m]: ",expectdist);
			dashbutton(25,105,300,10,0,0,(char*)temptext);

			sprintf_s(temptext,"%s%d%s%.1f","Intro turn:",start_motion," Motion Time:",motion_time);
			dashbutton(25,285,300,10,0,0,(char*)temptext);
			/*
			sprintf_s(temptext,"%s%.1f,%.1f,%.1f","Position:",playerxpos,playerypos,playerzpos);
			dashbutton(25,315,300,10,0,0,(char*)temptext);
			*/
			sprintf_s(temptext,"%s%.1f,%.1f,%.1f","Heading:",camxang*degreesinradian,camyang*degreesinradian,camzang*degreesinradian);
			dashbutton(25,195,300,10,0,0,(char*)temptext);
			/*
			if(!showplayer){
				sprintf(temptext,"%s%.1f","Player height [ft]: ",playerhight);
				dashbutton(25,435,300,10,0,0,(char*)temptext);
			}
			sprintf(temptext,"%s%s","Log file: ",logfilename);
			dashbutton(25,405,300,10,0,0,(char*)temptext);

			*/
			break;
		case 2:
			if(allocentric){
				sprintf_s(temptext,"%s","Mode Allocentrique");
				dashbutton(25,345,300,10,0,0,(char*)temptext);
			}
			sprintf_s(temptext,"%s%.2f","Distance Traversée [m]: ",elapseddist);
			dashbutton(25,75,300,10,0,0,(char*)temptext);

			sprintf_s(temptext,"%s%.2f","Distance Expectée [m]: ",expectdist);
			dashbutton(25,105,300,10,0,0,(char*)temptext);

			sprintf_s(temptext,"%s%d%s%.1f","Rotation Préliminaire:",start_motion," Temps Parcouru en Rotation:",motion_time);
			dashbutton(25,285,300,10,0,0,(char*)temptext);
			/*
			sprintf_s(temptext,"%s%.1f,%.1f,%.1f","Position:",playerxpos,playerypos,playerzpos);
			dashbutton(25,315,200,10,0,0,(char*)temptext);
			*/
			sprintf_s(temptext,"%s%.1f,%.1f,%.1f","Direction:",camxang*degreesinradian,camyang*degreesinradian,camzang*degreesinradian);
			dashbutton(25,195,300,10,0,0,(char*)temptext);
			/*
			if(!showplayer){
				sprintf(temptext,"%s%.1f","Taille du Joueur [ft]: ",playerhight);
				dashbutton(25,435,200,10,0,0,(char*)temptext);
			}
			sprintf(temptext,"%s%s","Journal: ",logfilename);
			dashbutton(25,405,200,10,0,0,(char*)temptext);

			*/
			break;
		case 3:
			break;
		case 4:
			break;
		}
	}
	//danyal added win_clue as a char...I hope that's ok!
			sprintf(temptext,"%c",win_clue);
			dashbutton(25,45,300,10,0,0,(char*)temptext);
	if(kidmode){
			switch(targetwin)
			{
				case 0:
					switch(lang){
						case 1:    //English
							sprintf_s(temptext,"%s%d%s","Trial number ",trial,": Go to the window with the Kitten");
							break;
						case 2:   //French
							sprintf_s(temptext,"%s%d%s","Numero d'essai ",trial,": Allez a la fenetre avec le Chat");
							break;
						case 3:   //Spanish
							sprintf_s(temptext,"%s%d%s","Prueba numero ",trial,": Vaya a la ventana con el Gato");
							break;
						case 4:   //German
							sprintf_s(temptext,"%s%d%s","Versuch Nummer ",trial,": Gehen Sie zu dem Fenster mit die Katze");
							break;
					}
				break;
				case 1:
					switch(lang){
						case 1:   //English
							sprintf_s(temptext,"%s%d%s","Trial number ",trial,": Go to the window with the Puppy");
							break;
						case 2:   //French
							sprintf_s(temptext,"%s%d%s","Numero d'essai ",trial,": Allez a la fenetre avec le Chein");
							break;
						case 3:   //Spanish
							sprintf_s(temptext,"%s%d%s","Prueba numero ",trial,": Vaya a la ventana con la Perro");
							break;
						case 4:   //German
							sprintf_s(temptext,"%s%d%s","Versuch Nummer ",trial,": Gehen Sie zu dem Fenster mit der Hund");
							break;
					}
				break;
				case 2:
					switch(lang){
						case 1:    //English
							sprintf_s(temptext,"%s%d%s","Trial number ",trial,": Go to the window with the Cow");
							break;
						case 2:   //French
							sprintf_s(temptext,"%s%d%s","Numero d'essai ",trial,": Allez a la fenetre avec le Vache");
							break;
						case 3:   //Spanish
							sprintf_s(temptext,"%s%d%s","Prueba numero ",trial,": Vaya a la ventana con el Vaca");
							break;
						case 4:   //German
							sprintf_s(temptext,"%s%d%s","Versuch Nummer ",trial,": Gehen Sie zu dem Fenster mit die Kuh");
							break;
					}
				break;
			}
		}
		else
		{
			switch(targetwin)
			{
				case 0:
					switch(lang){
						case 1:    //English
							sprintf_s(temptext,"%s%d%s","Trial number ",trial,": Go to the window with the circle");
							break;
						case 2:   //French
							sprintf_s(temptext,"%s%d%s","Numero d'essai ",trial,": Allez a la fenetre avec le cercle");
							break;
						case 3:   //Spanish
							sprintf_s(temptext,"%s%d%s","Prueba numero ",trial,": Vaya a la ventana con el circulo");
							break;
						case 4:   //German
							sprintf_s(temptext,"%s%d%s","Versuch Nummer ",trial,": Gehen Sie zu dem Fenster mit Kreis");
							break;
					}
				break;
				case 1:
					switch(lang){
						case 1:   //English
							sprintf_s(temptext,"%s%d%s","Trial number ",trial,": Go to the window with the X");
							break;
						case 2:   //French
							sprintf_s(temptext,"%s%d%s","Numero d'essai ",trial,": Allez a la fenetre avec le X");
							break;
						case 3:   //Spanish
							sprintf_s(temptext,"%s%d%s","Prueba numero ",trial,": Vaya a la ventana con la X");
							break;
						case 4:   //German
							sprintf_s(temptext,"%s%d%s","Versuch Nummer ",trial,": Gehen Sie zu dem Fenster mit X");
							break;
					}
				break;
				case 2:
					switch(lang){
						case 1:    //English
							sprintf_s(temptext,"%s%d%s","Trial number ",trial,": Go to the window with the triangle");
							break;
						case 2:   //French
							sprintf_s(temptext,"%s%d%s","Numero d'essai ",trial,": Allez a la fenetre avec le triangle");
							break;
						case 3:   //Spanish
							sprintf_s(temptext,"%s%d%s","Prueba numero ",trial,": Vaya a la ventana con el triangulo");
							break;
						case 4:   //German
							sprintf_s(temptext,"%s%d%s","Versuch Nummer ",trial,": Gehen Sie zu dem Fenster mit Dreieck");
							break;
					}
				break;
			}
		}
		dashbutton(25,15,600,10,0,0,(char*)temptext);


		//selecting the targetwin
		if(allocentric)
			targetwin=(trial-1)%3;
		else
			targetwin=rand()%3;
		
		//targetwin position
		switch(targetwin){
			case 0:
				target_x=(a_win_pos[0]*worldtilesize);
				target_y=(a_win_pos[1]*worldtilesize)-4;
				target_z=(a_win_pos[2]*worldtilesize);
				break;
			case 1:
				target_x=(b_win_pos[0]*worldtilesize);
				target_y=(b_win_pos[1]*worldtilesize)-4;
				target_z=(b_win_pos[2]*worldtilesize);
				break;
			case 2:
				target_x=(c_win_pos[0]*worldtilesize);
				target_y=(c_win_pos[1]*worldtilesize)-4;
				target_z=(c_win_pos[2]*worldtilesize);
				break;
			}

		if((target_x-target_offset<playerxpos)&&(target_x+target_offset>playerxpos)&&(target_y-target_offset<(playerypos))&&(target_y+target_offset>(playerypos))&&(target_z-target_offset<playerzpos)&&(target_z+target_offset>playerzpos)){
			switch(lang){
				case 1:   //English
					sprintf(temptext,"%s","Good Job! You reached the Goal");
					break;
				case 2:   //French
					sprintf(temptext,"%s","Bon travail! Objectif atteint");
					break;
				case 3:   //Spanish
					sprintf(temptext,"%s","Buen trabajo! Llego a la meta");
					break;
				case 4:   //German
					sprintf(temptext,"%s","Gut Gemacht! Ziel erreicht");
					break;
			}
			dashbutton(screenw/2,screenh/2,500,10,1,0,(char*)temptext);
			/*
			if(sound){ 
				if(kidmode){
					PlaySound((LPCSTR)"media/applause.wav", NULL, SND_FILENAME | SND_SYNC); sound = 0;
				}
				else{
					switch(lang){
						case 1:   //English
							PlaySound((LPCSTR)"media/goodjob.wav", NULL, SND_FILENAME | SND_SYNC); sound = 0;
							break;
						case 2:   //French
							PlaySound((LPCSTR)"media/bontravail.wav", NULL, SND_FILENAME | SND_SYNC); sound = 0;
							break;
						case 3:   //Spanish
							PlaySound((LPCSTR)"media/buentrabajo.wav", NULL, SND_FILENAME | SND_SYNC); sound = 0;
							break;
						case 4:   //German
							PlaySound((LPCSTR)"media/gutgemacht.wav", NULL, SND_FILENAME | SND_SYNC); sound = 0;
							break;
					}
				}
			}
			*/
			if(autoexit){Sleep(3000);exit(0);}
		}
		else sound = 1;
	/*
	if(kidmode&&animal_background_sound)
	{
		if(sound_delay)
			sound_delay--;
		else{
			sound_delay=200;
			switch(targetwin){
				case 0:
					PlaySound((LPCSTR)"media/cat.wav", NULL, SND_FILENAME | SND_ASYNC); sound = 0;
					break;
				case 1:
					PlaySound((LPCSTR)"media/dog.wav", NULL, SND_FILENAME | SND_ASYNC); sound = 0;
					break;
				case 2:
					PlaySound((LPCSTR)"media/cow.wav", NULL, SND_FILENAME | SND_ASYNC); sound = 0;
					break;
			}
		}
	}
	*/
	
}
	//danyal added
	/* We want to put in DirectX instead of this stuff
	float target_x=0,target_y=0,target_z=0;
	const int target_offset=3;
	if(allocentric){
			switch(targetwin){
			case 0:
				target_x=(a_win_pos[0]*worldtilesize);
				target_y=(a_win_pos[1]*worldtilesize)-4;
				target_z=(a_win_pos[2]*worldtilesize);
				break;
			case 1:
				target_x=(b_win_pos[0]*worldtilesize);
				target_y=(b_win_pos[1]*worldtilesize)-4;
				target_z=(b_win_pos[2]*worldtilesize);
				break;
			case 2:
				target_x=(c_win_pos[0]*worldtilesize);
				target_y=(c_win_pos[1]*worldtilesize)-4;
				target_z=(c_win_pos[2]*worldtilesize);
				break;
			}
		}
		else{
			target_x=(a_win_pos[0]*worldtilesize);
			target_y=(a_win_pos[1]*worldtilesize)-4;
			target_z=(a_win_pos[2]*worldtilesize);
		}
	if((target_x-target_offset<playerxpos)&&(target_x+target_offset>playerxpos)&&(target_y-target_offset<(playerypos))&&(target_y+target_offset>(playerypos))&&(target_z-target_offset<playerzpos)&&(target_z+target_offset>playerzpos)){
					PlaySound((LPCWSTR)"media/applause.wav", NULL, SND_FILENAME | SND_SYNC);//something is really messed up here
				}
	*/
