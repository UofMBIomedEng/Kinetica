void dashsavescreenshot(){
	char filename[256];
	ifstream test;
	int filenumber=1;
	sprintf_s(filename,"screenshot%d.bmp",filenumber);
	test.open(filename);test.close();
	if(!test.fail()){
		while(!test.fail()){
			filenumber=filenumber+1;
			sprintf_s(filename,"screenshot%d.bmp",filenumber);
			test.open(filename);test.close();
		}
	}
	SDL_SaveBMP(screenshot_sprite, (char*)filename);
	SDL_FreeSurface(screenshot_sprite);
	dashon=0;
}

int helpdashmenu(){
	int x=(int)screenw/2;
	int y=dashonslide((int)(screenh/2-125),(int)(screenh/2-125+screenh));
	switch(lang){
	case 1:	
		dashbutton(x,y,330,450,1,0,(char*)"");
		y-=180;
		dashtextcenter(x,y-51/2,"Help");
		y+=35;
		dashtext(x-150,y-51/2,"Use the following keys to:");
		y+=30;
		dashtext(x-150,y-51/2,"1 Decrease the view range");
		y+=20;
		dashtext(x-150,y-51/2,"2 Increase the view range");
		y+=20;
		dashtext(x-150,y-51/2,"3 Texture mode ON/OFF");
		y+=20;
		dashtext(x-150,y-51/2,"4 Ghost mode ON/OFF");
		y+=20;
		dashtext(x-150,y-51/2,"5 Previous tile");
		y+=20;
		dashtext(x-150,y-51/2,"6 Next tile");
		y+=20;
		dashtext(x-150,y-51/2,"7 Rotate tile");
		y+=20;
		dashtext(x-150,y-51/2,"8 Save everything");
		y+=20;
		dashtext(x-150,y-51/2,"9 Load everything");
		y+=20;
		dashtext(x-150,y-51/2,"M Use Mouse ON/OFF");
		y+=20;
		dashtext(x-150,y-51/2,"J Use Joystick ON/OFF");
		y+=20;
		dashtext(x-150,y-51/2,"E Auto-exit ON/OFF");
		y+=20;
		dashtext(x-150,y-51/2,"P First/Third Person toggle");
		y+=20;
		dashtext(x-150,y-51/2,"G GPS minimap ON/OFF");
		y+=20;
		dashtext(x-150,y-51/2,"Q Quit the game");
		y+=40;
		if(dashbutton(x,y,100,15,1,1,(char*)"Exit"))return 1;
		y+=40;
		return 14;
	break;
	case 2:
		dashbutton(x,y,330,450,1,0,(char*)"");
		y-=180;
		dashtextcenter(x,y-51/2,"Aide");
		y+=35;
		dashtext(x-150,y-51/2,"Utilizes les touches suivantes:");
		y+=30;
		dashtext(x-150,y-51/2,"1 Diminuer la ???");
		y+=20;
		dashtext(x-150,y-51/2,"2 Augmenter la ???");
		y+=20;
		dashtext(x-150,y-51/2,"3 Eliminer les textures");
		y+=20;
		dashtext(x-150,y-51/2,"4 Mode 'fantome' ACTIF/INACTIF");
		y+=20;
		dashtext(x-150,y-51/2,"5 Carreau precedent");
		y+=20;
		dashtext(x-150,y-51/2,"6 Prochaine carreau");
		y+=20;
		dashtext(x-150,y-51/2,"7 Pivoter le carreau");
		y+=20;
		dashtext(x-150,y-51/2,"8 Tout sauvegarder");
		y+=20;
		dashtext(x-150,y-51/2,"9 Tout charger");
		y+=20;
		dashtext(x-150,y-51/2,"M Souris ACTIF/INACTIF");
		y+=20;
		dashtext(x-150,y-51/2,"J Joystick ACTIF/INACTIF");
		y+=20;
		dashtext(x-150,y-51/2,"E Auto-fermature ACTIF/INACTIF");
		y+=20;
		dashtext(x-150,y-51/2,"P Premier/Troisieme personnage");
		y+=20;
		dashtext(x-150,y-51/2,"G GPS mini-carte ACTIF/INACTIF");
		y+=20;
		dashtext(x-150,y-51/2,"Q Quitter le jeu");
		y+=40;
		if(dashbutton(x,y,100,15,1,1,(char*)"Fermer"))return 1;
		y+=40;
		return 14;
	break;
	case 3:
		break;
	case 4:
		break;
	}
}

void dashmenu(){
	int x=(int)screenw/2;
		int y=dashonslide((int)(screenh/2-125),(int)(screenh/2-125+screenh));
	
	switch(lang){                                              //This needs to be switch(lang) but lang isn't identified here
	case 1:
		
		switch(menu_tree_par){
			case 1:
				if(dashbutton(x,y,200,15,1,1,(char*)"Resume"))dashon=0;
				y+=40;
				if(dashbutton(x,y,200,15,1,1,(char*)"Screenshot"))dashsavescreenshot();
				y+=40;
				if(dashbutton(x,y,200,15,1,1,(char*)"Help"))menu_tree_par=14;	
				y+=40;
				if(dashbutton(x,y,200,15,1,1,(char*)"Exit"))shutdownprogram=true;	
				y+=40;
				break;
			case 14:
				menu_tree_par=helpdashmenu();	
				break;
		}
		break;
	case 2:
	
		switch(menu_tree_par){
			case 1:
				if(dashbutton(x,y,200,15,1,1,(char*)"Reprendre"))dashon=0;
				y+=40;
				if(dashbutton(x,y,200,15,1,1,(char*)"Capture d'Ecran"))dashsavescreenshot();
				y+=40;
				if(dashbutton(x,y,200,15,1,1,(char*)"Aide"))menu_tree_par=14;	
				y+=40;
				if(dashbutton(x,y,200,15,1,1,(char*)"Fermer"))shutdownprogram=true;	
				y+=40;
				break;
			case 14:
				menu_tree_par=helpdashmenu();	
				break;
		}
		break;
	case 3:
		break;
	case 4:
		break;
	}
}