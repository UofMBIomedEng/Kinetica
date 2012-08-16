struct tm *dash_time;
const char* edash_wday[]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};

const char* fdash_wday[]={"dimanche","lundi","mardi","mercredi","jeudi","vendredi","samdi"};
const char* sdash_wday[]={"Domingo","Lunes","Martes","Miercoles","Jueves","Viernes","Sabado"};
const char* gdash_wday[]={"Sonntag","Montag","Dienstag","Mittwoch","Donnerstag","Freitag","Samstag"};
const char* edash_month[]={"January","February","March","April","May","June","July","August","September","October","November","December"};
const char* fdash_month[]={"janvier","fevrier","mars","avril","mai","juin","juillet","aout","septembre","octobre","novembre","decembre"};
const char* sdash_month[]={"Enero","Febrero","Marzo","Abril","Mayo","Junio","​​Julio","Septiembre","Octubre","Noviembre","Diciembre"};
const char* gdash_month[]={"Januar","Februar","Marz","April","Mai","Juni","Juli","August","September","Oktober","November","Dezember"};
const char* dash_day[]={"1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24","25","26","27","28","29","30","31"};
char dash_composedtext_date[256];
char dash_composedtext_time[256];

int dash_gametime=0;
int dash_timehaspast=0;
float dash_framerate=0;
float dash_framecap=60;

void dashtime(){

	//get how much time has passed
	dash_timehaspast=SDL_GetTicks()-dash_gametime;
	

	//throttle the frame rate
	if(dash_framecap){
		if(dash_timehaspast<(int)(1000.f/dash_framecap)){
			int delay=(int)(1000.f/dash_framecap)-dash_timehaspast;
			SDL_Delay(delay);
			dash_timehaspast+=delay;
		}
	}

	//calculate the new time
	dash_gametime+=dash_timehaspast;

	//calculate the frame rate
	dash_framerate=1000.f/(float)dash_timehaspast;

	//get the time and date
	time_t now;
	now = time(NULL);
	dash_time = localtime(&now);

	//get the date in a char array text format
	switch(lang){
	case 1:
		sprintf_s(dash_composedtext_date,"%s%s%s%s%s%s%d",
				edash_wday[dash_time->tm_wday],
				" ",
				dash_day[dash_time->tm_mday-1],
				" ",
				edash_month[dash_time->tm_mon],
				" ",
				1900+dash_time->tm_year
				);
		break;
		
	case 2:
		sprintf_s(dash_composedtext_date,"%s%s%s%s%s%s%d",
				fdash_wday[dash_time->tm_wday],
				" ",
				dash_day[dash_time->tm_mday-1],
				" ",
				fdash_month[dash_time->tm_mon],
				" ",
				1900+dash_time->tm_year
				);
		break;
	case 3:
		sprintf_s(dash_composedtext_date,"%s%s%s%s%s%s%d",
				sdash_wday[dash_time->tm_wday],
				" ",
				dash_day[dash_time->tm_mday-1],
				" ",
				sdash_month[dash_time->tm_mon],
				" ",
				1900+dash_time->tm_year
				);
		break;
	case 4:
		sprintf_s(dash_composedtext_date,"%s%s%s%s%s%s%d",
				gdash_wday[dash_time->tm_wday],
				" ",
				dash_day[dash_time->tm_mday-1],
				" ",
				gdash_month[dash_time->tm_mon],
				" ",
				1900+dash_time->tm_year
				);
		break;
		
	}
	//get the time in a char array text format

	strcpy_s(dash_composedtext_time,"");
	switch(lang){
	case 1:
		if(dash_time->tm_hour>12){
			sprintf_s(dash_composedtext_time,"%s%d",dash_composedtext_time,dash_time->tm_hour-12);
		}else{
			if(dash_time->tm_hour==0){
				sprintf_s(dash_composedtext_time,"%s%d",dash_composedtext_time,12);
			}else{
				sprintf_s(dash_composedtext_time,"%s%d",dash_composedtext_time,dash_time->tm_hour);
			}
		}
		strcat_s(dash_composedtext_time,":");
		if(dash_time->tm_min<10)
			strcat_s(dash_composedtext_time,"0");
		sprintf_s(dash_composedtext_time,"%s%d",dash_composedtext_time,dash_time->tm_min);
		strcat_s(dash_composedtext_time,":");
		if(dash_time->tm_sec<10)
			strcat_s(dash_composedtext_time,"0");
		sprintf_s(dash_composedtext_time,"%s%d",dash_composedtext_time,dash_time->tm_sec);
		if(dash_time->tm_hour>11){
			strcat_s(dash_composedtext_time," PM");
		}else{
			strcat_s(dash_composedtext_time," AM");
		}
		break;
	case 2:
		sprintf_s(dash_composedtext_time,"%s%d",dash_composedtext_time,dash_time->tm_hour);
		strcat_s(dash_composedtext_time,":");
		if(dash_time->tm_min<10)
			strcat_s(dash_composedtext_time,"0");
		sprintf_s(dash_composedtext_time,"%s%d",dash_composedtext_time,dash_time->tm_min);
		strcat_s(dash_composedtext_time,":");
		if(dash_time->tm_sec<10)
			strcat_s(dash_composedtext_time,"0");
		sprintf_s(dash_composedtext_time,"%s%d",dash_composedtext_time,dash_time->tm_sec);
		break;
	case 3:
		sprintf_s(dash_composedtext_time,"%s%d",dash_composedtext_time,dash_time->tm_hour);
		strcat_s(dash_composedtext_time,":");
		if(dash_time->tm_min<10)
			strcat_s(dash_composedtext_time,"0");
		sprintf_s(dash_composedtext_time,"%s%d",dash_composedtext_time,dash_time->tm_min);
		strcat_s(dash_composedtext_time,":");
		if(dash_time->tm_sec<10)
			strcat_s(dash_composedtext_time,"0");
		sprintf_s(dash_composedtext_time,"%s%d",dash_composedtext_time,dash_time->tm_sec);
		break;
	case 4:
		sprintf_s(dash_composedtext_time,"%s%d",dash_composedtext_time,dash_time->tm_hour);
		strcat_s(dash_composedtext_time,":");
		if(dash_time->tm_min<10)
			strcat_s(dash_composedtext_time,"0");
		sprintf_s(dash_composedtext_time,"%s%d",dash_composedtext_time,dash_time->tm_min);
		strcat_s(dash_composedtext_time,":");
		if(dash_time->tm_sec<10)
			strcat_s(dash_composedtext_time,"0");
		sprintf_s(dash_composedtext_time,"%s%d",dash_composedtext_time,dash_time->tm_sec);
		break;
	}
}
