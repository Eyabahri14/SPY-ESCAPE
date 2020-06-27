/**
* @file main.c 
* @brief main file.
* @author Anarchy team
* @date june 12, 2019
*/
#include <stdio.h>
#include <stdlib.h>
//gcc main.c -o main `sdl-config --cflags --libs` -lSDL_image -lSDL_mixer 
#include <SDL/SDL.h>
#include "SDL/SDL_image.h"
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_getenv.h>
#include "SDL/SDL_mixer.h"
#define LARGEUR_FENETRE 800
#define HAUTEUR_FENETRE 600 
#include "jeu.h"
/************************************/

void initialisation(){
	IMG_Init(IMG_INIT_PNG |IMG_INIT_JPG );
Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,4096);
putenv("SDL_VIDEO_CENTERED=1");//centrer la fenetre
if (SDL_Init(SDL_INIT_VIDEO))
{fprintf(stderr,"ERROR:%s",SDL_GetError());}
  TTF_Init();
}
/************************************/

void upload_anim(SDL_Surface *load[122]){

	load[0]=IMG_Load("./Loading/Comp 1_00001.png");
	load[1]=IMG_Load("./Loading/Comp 1_00007.png");
	load[2]=IMG_Load("./Loading/Comp 1_00013.png");
	load[3]=IMG_Load("./Loading/Comp 1_00024.png");
	load[4]=IMG_Load("./Loading/Comp 1_00035.png");
	load[5]=IMG_Load("./Loading/Comp 1_00046.png");
	load[6]=IMG_Load("./Loading/Comp 1_00057.png");
	load[7]=IMG_Load("./Loading/Comp 1_00066.png");
	load[8]=IMG_Load("./Loading/Comp 1_00069.png");
	load[9]=IMG_Load("./Loading/Comp 1_00079.png");
	load[10]=IMG_Load("./Loading/Comp 1_00085.png");
	load[11]=IMG_Load("./Loading/Comp 1_00087.png");
	load[12]=IMG_Load("./Loading/Comp 1_00092.png");
	load[13]=IMG_Load("./Loading/Comp 1_000100.png");
	load[14]=IMG_Load("./Loading/Comp 1_000110.png");
	load[15]=IMG_Load("./Loading/Comp 1_000121.png");
}
/************************************/
/************************************/

void upload_effect(SDL_Surface *anim[10]){

anim[0] =IMG_Load("./EffetMenu/m1.png");
anim[1] =IMG_Load("./EffetMenu/m2.png");
anim[2] =IMG_Load("./EffetMenu/m3.png");
anim[3] =IMG_Load("./EffetMenu/m4.png");
anim[4] =IMG_Load("./EffetMenu/m5.png");
anim[5] =IMG_Load("./EffetMenu/m6.png");
anim[6] =IMG_Load("./EffetMenu/m7.png");
anim[7] =IMG_Load("./EffetMenu/m8.png");
anim[8] =IMG_Load("./EffetMenu/m9.png");
anim[9] =IMG_Load("./EffetMenu/m10.png");
anim[10] =IMG_Load("./EffetMenu/m11.png");
anim[11] =IMG_Load("./EffetMenu/m12.png");
anim[12] =IMG_Load("./EffetMenu/m13.png");
anim[13] =IMG_Load("./EffetMenu/m14.png");
anim[14] =IMG_Load("./EffetMenu/m15.png");
anim[15] =IMG_Load("./EffetMenu/m16.png");
anim[16] =IMG_Load("./EffetMenu/m17.png");
anim[17] =IMG_Load("./EffetMenu/m18.png");
anim[18] =IMG_Load("./EffetMenu/m19.png");
anim[19] =IMG_Load("./EffetMenu/m20.png");
anim[20] =IMG_Load("./EffetMenu/m21.png");
anim[21] =IMG_Load("./EffetMenu/m22.png");
anim[22] =IMG_Load("./EffetMenu/m23.png");
anim[23] =IMG_Load("./EffetMenu/m24.png");
anim[24] =IMG_Load("./EffetMenu/m25.png");
anim[25] =IMG_Load("./EffetMenu/m26.png");
anim[26] =IMG_Load("./EffetMenu/m27.png");
anim[27] =IMG_Load("./EffetMenu/m28.png");
}
/************************************/
/************************************/
void upload_EffetButton(SDL_Surface* EffectButton[4]){
	EffectButton[0]=IMG_Load("./EffetButton/play.png");
	EffectButton[1]=IMG_Load("./EffetButton/options.png");
	EffectButton[2]=IMG_Load("./EffetButton/credits.png");
	EffectButton[3]=IMG_Load("./EffetButton/exit.png");
	EffectButton[4]=NULL;
}

/************************************/
/************************************/
void upload_AfterPlayEffect(SDL_Surface* EffectAfterPlay[3]){
SDL_Rect pos;
		EffectAfterPlay[0]=IMG_Load("./AfterPlayClick/single.png");
		EffectAfterPlay[1]=IMG_Load("./AfterPlayClick/multi.png");
EffectAfterPlay[2]=NULL;

}
/************************************/
/************************************/
int main (int argc,char **argv)
{

	//surface  fenetre + menu + texte 
	SDL_Surface *fenetre = NULL, *menu= NULL,*texte= NULL,*EffectButton[5],*curseur=NULL,*anim[28],*load[16],*MenuAfterPlay=NULL,*EffectAfterPlay[3],*ecran=NULL,*image = NULL;;
    SDL_Rect positionmenu,positionclic,positionTxt,PositionEffect,PositionCursor,animRect ,animLoad,PosAfterPlayMenu,PosEffetAfterPlay,pos;
   
    
	PositionEffect.x= 13;
        PositionEffect.y= -10;
	positionmenu.x=0;positionmenu.y=0;
	animRect.x=0;animRect.y=0;
    animLoad.x=0;animLoad.y=0;
    PosAfterPlayMenu.x=0;PosAfterPlayMenu.y=0;
    PosEffetAfterPlay.x=0;PosEffetAfterPlay.y=0;
pos.x = 0;
pos.y = 0;
    
	TTF_Font *police = NULL;
    SDL_Color couleurNoire = {0, 0, 0};


//effet menu animé melloul+loading+menu ba3d play+effet boutton
upload_effect(anim);
upload_anim(load);
upload_EffetButton(EffectButton);
upload_AfterPlayEffect(EffectAfterPlay);
//initialistion image + video+son+texte
initialisation();


//Nommer fenetre ert chargement du menu
 SDL_WM_SetCaption("FREE WAVE GAME ", NULL);
menu = IMG_Load("./Curseur+Texte+Menu/menu22.png");
curseur=IMG_Load("./Curseur+Texte+Menu/curseur.png");
MenuAfterPlay=IMG_Load("./AfterPlayClick/menuPlay.png");

if(!menu) {
printf("IMG_Load: %s\n", IMG_GetError());}


 /* Chargement de la police */
    police = TTF_OpenFont("./Curseur+Texte+Menu/angelina.TTF",55);
 
	 SDL_BlitSurface(curseur,NULL,fenetre,&PositionCursor);

SDL_BlitSurface(menu,NULL,fenetre,&positionmenu);

SDL_Event event,event2;
   /*******************/
//declaration evenement + piste audio
 Mix_Music *adventure=Mix_LoadMUS("./SonEtEffet/adventure.mp3");
 Mix_Chunk *mouseEffect=Mix_LoadWAV("./SonEtEffet/effect.wav");

//volume de piste
 Mix_VolumeChunk(mouseEffect,128);
 Mix_VolumeMusic(75);
 Mix_PlayMusic(adventure,-1);
	/*********************/

int i,j=0,k=0,l=0;
char aa[44];
int timea = 0, timep = 0;




fenetre=SDL_SetVideoMode(1360,768,32,SDL_HWSURFACE|SDL_SWSURFACE |SDL_DOUBLEBUF | SDL_ANYFORMAT  );

for(i=0;i<16;i++){
	SDL_BlitSurface( load[i] , NULL , fenetre , &animLoad );
pos.x=0;
pos.y=0;
	 SDL_Flip(fenetre);
 SDL_Delay(500);
 
}

fenetre=SDL_SetVideoMode(1360,768,32,SDL_HWSURFACE|SDL_SWSURFACE |SDL_DOUBLEBUF | SDL_ANYFORMAT  );


	while(i<203){
		sprintf(aa,"3a/video%d",i);
		strcat(aa,".png");
		image = IMG_Load(aa);
		SDL_FillRect(fenetre,NULL,SDL_MapRGB(fenetre->format,255,255,255));
		SDL_BlitSurface(image,NULL,fenetre,&pos);
		
		i++;
		

	 SDL_Flip(fenetre);
 //SDL_Delay(500);
 	}
SDL_FreeSurface(image);
fenetre=SDL_SetVideoMode(1360,768,32,SDL_HWSURFACE|SDL_SWSURFACE |SDL_DOUBLEBUF | SDL_ANYFORMAT  );

while(event.key.keysym.sym!=SDLK_ESCAPE){
	 SDL_BlitSurface( anim[i] , NULL , fenetre , &animRect );
	 
	 i++;
	 if(i>=28)i=0;	 
		SDL_BlitSurface(EffectButton[k], NULL, fenetre, &PositionEffect); 

	 SDL_BlitSurface(curseur,NULL,fenetre,&PositionCursor);
	 SDL_Flip(fenetre);

	
while(SDL_PollEvent(&event)){

 switch (event.type)
{

case SDL_MOUSEMOTION :
SDL_ShowCursor(SDL_DISABLE);
	PositionCursor.x=event.button.x;
	PositionCursor.y=event.button.y;

	/*jouer*/if (event.button.x > 471 && event.button.x < 843 && event.button.y >246 && event.button.y < 296){
		k=0;
					break;
					}
	/*options*/else if (event.button.x > 471 && event.button.x < 843 && event.button.y >342 && event.button.y <391){
		k=1;
		break;}
	/*credits*/else if (event.button.x > 471 && event.button.x < 843 && event.button.y >436 && event.button.y <484){
		k=2;
		break;}
	/*exit*/else if (event.button.x > 471 && event.button.x < 843 && event.button.y >534 && event.button.y <583)  {
	k=3;
		break;}
k=4;
break;
case SDL_MOUSEBUTTONDOWN:

if (event.button.button==SDL_BUTTON_LEFT){
Mix_PlayChannel(-1,mouseEffect,0);
Mix_VolumeChunk(mouseEffect,128);
	
      /*jouer*/if (event.button.x > 471 && event.button.x < 843 && event.button.y >246 && event.button.y < 296){
		  
		  		ecran=SDL_SetVideoMode(LARGEUR_FENETRE,HAUTEUR_FENETRE,32,SDL_HWSURFACE|SDL_SWSURFACE |SDL_DOUBLEBUF | SDL_ANYFORMAT  );
				
		 while(event2.key.keysym.sym!=SDLK_SPACE){
			 SDL_BlitSurface( MenuAfterPlay, NULL , ecran , &PosAfterPlayMenu );
			 SDL_BlitSurface(EffectAfterPlay[l],NULL,ecran,&PosEffetAfterPlay);
				 SDL_BlitSurface(curseur,NULL,ecran,&PositionCursor);
				SDL_Flip(ecran);
			 	

			 while(SDL_PollEvent(&event2)){
				  switch (event2.type)
	{
				 		case SDL_MOUSEMOTION :
	SDL_ShowCursor(SDL_DISABLE);
	PositionCursor.x=event2.button.x;
	PositionCursor.y=event2.button.y;
	if (event2.button.x >114  && event2.button.x < 353 && event2.button.y >317 && event2.button.y < 363) {
		l=0;
		jeu();
		break;}
	else if (event2.button.x > 471 && event2.button.x < 691 && event2.button.y >317 && event2.button.y < 363) {
		jeu2();
		l=1;
    break;}
    l=2;
    break; 
   }
}
}
   fenetre=SDL_SetVideoMode(1360,768,32,SDL_HWSURFACE|SDL_SWSURFACE |SDL_DOUBLEBUF | SDL_ANYFORMAT  );


   }
   
   /************************/
      /*options*/else if (event.button.x > 471 && event.button.x < 843 && event.button.y >342 && event.button.y <391);
      /*credits*/else if (event.button.x > 471 && event.button.x < 843 && event.button.y >436 && event.button.y <484);
	/*exit*/else if (event.button.x > 471 && event.button.x < 843 && event.button.y >534 && event.button.y <583){exit(EXIT_FAILURE);}
	/*croix rouge */ else if (event.button.x > 712.33 && event.button.x < 795.67 && event.button.y >3.17 && event.button.y <16.17) {exit(EXIT_FAILURE);}
}
break;
case SDL_KEYUP :
switch(event.key.keysym.sym){
case SDLK_DOWN :

j=k;
j++;
if(j>4) j=0;
k=j;

break;
case SDLK_UP :
j=k;
j--;
if (j < 0) j=4;
k=j;

break;
}
}
}

}




//libérer la memoire
Mix_FreeMusic(adventure);
SDL_FreeSurface(curseur);
SDL_FreeSurface(menu);
SDL_FreeSurface(fenetre);
SDL_FreeSurface(ecran);
SDL_FreeSurface(MenuAfterPlay);
SDL_FreeSurface(EffectAfterPlay[2]);
SDL_FreeSurface(texte);
SDL_FreeSurface(anim[10]);
SDL_FreeSurface(EffectButton[4]);
return EXIT_SUCCESS;
}
