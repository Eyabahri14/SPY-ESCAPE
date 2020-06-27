#ifndef MINIMAP_H_INCLUDED
#define MINIMAP_H_INCLUDED

#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "perso.h"

typedef struct minimap{
    SDL_Rect mmposition;
    SDL_Rect cposition;
	SDL_Surface * map;
	SDL_Surface * cursor;
}minimap;

void initialiser_minimap(minimap * m);
void update_minimap(minimap * m, SDL_Surface * ecran, int x, int d, perso * pers);

#endif