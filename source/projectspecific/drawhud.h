void drawhud(){

	set2dcamera(0,screenh,0,screenw);

	if(showminimap)drawminimap();

	char temptext[256];
	sprintf_s(temptext,"%s%i%s","Collectables: ",collectablesfound,"/1000");
	dashbutton(25,105,200,10,0,0,(char*)temptext);

	sprintf_s(temptext,"%s%1d%s%1d%s%1d%s%1d","Stat: M=",usemouse," P=",showplayer, " E=", autoexit, " J=", usejoystick);
	dashbutton(25,135,200,10,0,0,(char*)temptext);

	sprintf_s(temptext,"%s%3.f%s%3.f%s%3.f","P:X=",playerxpos," Y=",playerypos, " Z=", playerzpos);
	dashbutton(25,165,200,10,0,0,(char*)temptext);

	sprintf_s(temptext,"%s%d","Test=",test);
	dashbutton(25,195,200,10,0,0,(char*)temptext);

}
