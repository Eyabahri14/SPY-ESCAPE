#include <stdio.h>
#include <SDL/SDL.h>
#include <stdlib.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "fonction.h"
#include <SDL/SDL_ttf.h>



int collitrigo(SDL_Surface *  box,SDL_Surface *circle,SDL_Rect boxpos,SDL_Rect circlepos)
{

float a,b,r,x;

a=circlepos.x+(circlepos.w/2);
b=circlepos.y+(circlepos.h/2);
r=(circlepos.w/2)*(circlepos.w/2);//rayon carre 

   if( ( ( (boxpos.x+boxpos.w)<a || boxpos.x>a) || (((b-boxpos.y)*(b-boxpos.y)) > r) )
      &&( ( (boxpos.x+boxpos.w)<a || boxpos.x>a) || (((b-(boxpos.y+boxpos.h))*(b-(boxpos.y+boxpos.h))) > r) )
      &&(( ( ( (boxpos.x-a)*(boxpos.x-a))+(((boxpos.y+boxpos.h)-b)*((boxpos.y+boxpos.h)-b))) )>r)
      &&(( ((boxpos.x-a)*(boxpos.x-a))+((boxpos.y-b)*(boxpos.y-b)))>r)
      &&( ( (boxpos.y+boxpos.h)<b || boxpos.y>b) || ( ( (a-boxpos.x)*(a-boxpos.x)) > r) )
      &&(( ( ( ((boxpos.x+boxpos.w)-a)*((boxpos.x+boxpos.w)-a))+(((boxpos.y+boxpos.h)-b)*((boxpos.y+boxpos.h)-b))) )>r)
     &&(( (((boxpos.x+boxpos.w)-a)*((boxpos.x+boxpos.w)-a))+((boxpos.y-b)*(boxpos.y-b)))>r) 
       && ( ( (boxpos.y+boxpos.h)<b || boxpos.y>b) || ( ( (a-(boxpos.x+boxpos.w))*(a-(boxpos.x+boxpos.w))) > r) )
      )
return 1;
else return 0;
}

void scorecount(int* score , SDL_Surface ** coeur, int etat )
{

if (etat)
(*score)--;
else
(*score)++;
if (*score<0)
*score=0;
if(*score>3)
*score=3;
if (*score==0)
*coeur= IMG_Load("v4.png");
if (*score==1)
*coeur= IMG_Load("v3.png");
if (*score==2)
*coeur= IMG_Load("v2.png");
if (*score==3)
*coeur= IMG_Load("v1.png");




}




void initializeES(ES* es)
{
	SDL_Surface* tmp  ;
         tmp = IMG_Load("circlea.jpg");
	es->image = tmp;


	SDL_Rect pos;
	pos.x=4000;
	pos.y=330;
	es->espos=pos;
	
}


void initializeES2(ES* es)
{
	SDL_Surface* tmp  ;
         tmp = IMG_Load("circleb.png");
	es->image = tmp;


	SDL_Rect pos;
	pos.x=800;
	pos.y=280;
	es->espos=pos;
	
}

void mves(SDL_Rect* pos,int* tempsp, int* tempsa, int* v)
{

*tempsa=SDL_GetTicks();
if(*tempsa-*tempsp>20)
{
if(pos->x<=4400&&*v==1)
{
pos->x+=15;
if(pos->x>=4400)
*v=2;
}
if (*v==2)
{pos->x-=15;
if(pos->x<=4000)
*v=1;
}
*tempsp=*tempsa;
}
}
void mves2(SDL_Rect* pos,int* tempsp, int* tempsa, int* v)
{

*tempsa=SDL_GetTicks();
if(*tempsa-*tempsp>20)
{
if(pos->x<=1600&&*v==1)
{
pos->x+=15;
if(pos->x>=1600)
*v=2;
}
if (*v==2)
{pos->x-=15;
if(pos->x<=1)
*v=1;
}
*tempsp=*tempsa;
}
}
