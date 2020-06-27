#include "roto.h"

SDL_Surface * ESDeathAnimation(double * zoom, SDL_Surface * image){
    //if(*zoom > 0.95)
    //    *zoom -= 0.001;

    return rotozoomSurface(image, 0, *zoom, 1);
}