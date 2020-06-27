#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <time.h>
#include <unistd.h>
#include "scrolling.h"

SDL_Rect scrolling(int d,SDL_Rect camera,perso *pers,map *map)
{
int C;

if(camera.x<=0) camera.x=0;
if(camera.x>=6478) camera.x=6478;
if(d==1&&pers->position.x>=500)
{
camera.x=camera.x + pers->step;
}
if(d==2&&pers->position.x<=500 )
{
camera.x=camera.x - pers->step;
}

if(d==1 && pers->position.x>=1000){
map->stage++;
camera.x=0;
pers->position.x=100;
}


return camera ;
}

