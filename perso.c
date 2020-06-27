#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <time.h>
#include <unistd.h>
#include "perso.h"

void initialiserperso(perso *perso){
perso->position.x = 100;
perso->position.y = 280;
perso->position.w = 218;
perso->position.h = 249;
perso->fond0 = IMG_Load("tfol0.png");
perso->fond1 = IMG_Load("p4.png");
perso->fond2 = IMG_Load("p1.png");
perso->fond3 = IMG_Load("p3.png");
perso->fonda = IMG_Load("runningbackward 4.png");
perso->fondb = IMG_Load("runningbackward 1.png");
perso->fondc = IMG_Load("runningbackward 3.png");
perso->coeur = IMG_Load("v1.png");
perso->score = 3;
perso->step = 20;
perso->vitesse = 0;
perso->jump = 0;
}

void initialiserperso2(perso *perso){
perso->position.x = 380;
perso->position.y = 280;
perso->position.w = 218;
perso->position.h = 249;
perso->fond0 = IMG_Load("tfol0.png");
perso->fond1 = IMG_Load("p4.png");
perso->fond2 = IMG_Load("p1.png");
perso->fond3 = IMG_Load("p3.png");
perso->fonda = IMG_Load("runningbackward 4.png");
perso->fondb = IMG_Load("runningbackward 1.png");
perso->fondc = IMG_Load("runningbackward 3.png");
perso->coeur = IMG_Load("v1.png");
perso->score = 3;
perso->step = 20;
perso->vitesse = 0;
perso->jump = 0;
}

int mouv(int d,int x)
{
switch (d)
{
case 0:
if(x>0&&x<5)
x=1;
if(x>4&&x<9)
x=5;
	break;
case 1:

switch(x)
{
case 0:
x=1;
	break;
case 1:
x=2;
	break;
case 2:
x=3;
	break;
case 3:
x=4;
	break;
case 4:
x=1;
	break;
default:
x=1;
}
	break ;

case 2 :
switch(x)
{
case 0:
x=5;
	break;
case 5:
x=6;
	break;
case 6:
x=7;
	break;
case 7:
x=8;
	break;
case 8:
x=5;
	break;
default:
x=5;
}
	break;
case 3 :
x=0;
	break ;
case 4 :
x=0;
	break ;
}	
return x ;
}

perso mouvement(perso * pers,SDL_Rect camera,int d, int * tempsPrecedent, int * tempsPrecendent_jump)
{
int tempsActuel = SDL_GetTicks();

if(d == 1 || d == 2){
	if ((tempsActuel - *tempsPrecedent > 50)&&(pers->vitesse < 50)){
		pers->vitesse++;
		*tempsPrecedent = tempsActuel;
	}
}
else
	pers->vitesse = 0;


if(d == 3){
	pers->jump = 20;
}


if(pers->vitesse < 50)
	pers->step = 20; 
else
	pers->step = 40;

//if(pers->position.x>=940)pers->position.x-=20;
if(pers->position.x<=0)pers->position.x+=20;
if((d==1 && pers->position.x<500) || (d==1 && camera.x>=6478))
{
pers->position.x=pers->position.x + pers->step;
}

if((d==2 && pers->position.x>500 )|| (d==2 && camera.x<=0))
{
pers->position.x=pers->position.x - pers->step;
}

if(pers->jump > 10){
	if (tempsActuel - *tempsPrecendent_jump > 20){
		pers->position.y -= 20;
		pers->jump--;
		*tempsPrecendent_jump = tempsActuel;
	}
}
else{
	if(pers->jump > 0){
		if (tempsActuel - *tempsPrecendent_jump > 20){
			pers->position.y += 20;
			pers->jump--;
			*tempsPrecendent_jump = tempsActuel;
		}
	}
}

if(d==4 && pers->position.y==175){
pers->position.y=350;
}

return *pers;
}


void afficherperso(perso perso,SDL_Surface *ecran,int x)
{
switch(x)
{
case 0:
SDL_BlitSurface(perso.fond0,NULL, ecran,&perso.position);
	break ;
case 1:
SDL_BlitSurface(perso.fond1,NULL, ecran,&perso.position);
	break ;
case 2:
SDL_BlitSurface(perso.fond2,NULL, ecran,&perso.position);
	break ;
case 3:
SDL_BlitSurface(perso.fond1,NULL, ecran,&perso.position);
	break ;
case 4:
SDL_BlitSurface(perso.fond3,NULL, ecran,&perso.position);
	break ;
case 5:
SDL_BlitSurface(perso.fonda,NULL, ecran,&perso.position);
	break ;
case 6:
SDL_BlitSurface(perso.fondb,NULL, ecran,&perso.position);
	break ;
case 7:
SDL_BlitSurface(perso.fonda,NULL, ecran,&perso.position);
	break ;
case 8:
SDL_BlitSurface(perso.fondc,NULL, ecran,&perso.position);
	break ;
}
}
