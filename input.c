#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <time.h>
#include <unistd.h>
#include "input.h"

int direction(SDL_Event event,int *continuer){
int d = 0;
SDL_PollEvent(&event);
switch(event.type)
    {
        case SDL_QUIT:
            *continuer = 0;
  		break;
	case SDL_KEYDOWN:

            switch (event.key.keysym.sym)
            {
 		case SDLK_ESCAPE:
		    continuer=0 ;
			break ;

		case SDLK_LEFT :
		d=2;	
                    	break ;

		case SDLK_RIGHT :
		d=1; 
			break ;

		case SDLK_UP :
		d=3;	
                    	break ;

		case SDLK_DOWN :
		d=4; 
			break ;
	    }
	break;
	case SDL_KEYUP:
		if(event.key.keysym.sym == SDLK_RIGHT || event.key.keysym.sym == SDLK_LEFT || event.key.keysym.sym == SDLK_UP || event.key.keysym.sym == SDLK_DOWN)
			d = 0;
	break;
    }
return d;
}

void direction2( int * d, int * d2, SDL_Event event, int *continuer ){
SDL_PollEvent(&event);
switch(event.type)
    {
        case SDL_QUIT:
            *continuer = 0;
  		break;
	
		case SDL_KEYDOWN:

			switch (event.key.keysym.sym){
				
				case SDLK_ESCAPE:
					continuer = 0;
				break;

				case SDLK_q :
					*d2 = 2;	
				break;

				case SDLK_d :
					*d2 = 1; 
				break;

				case SDLK_w:
					*d2 = 3;	
				break;

				case SDLK_s:
					*d2 = 4; 
				break;

				case SDLK_LEFT:
					*d=2;	
				break ;

				case SDLK_RIGHT:
					*d=1; 
				break ;

				case SDLK_UP:
					*d=3;	
				break ;

				case SDLK_DOWN:
					*d=4; 
				break ;
				
				}

		break;
		case SDL_KEYUP:
			if(event.key.keysym.sym == SDLK_q || event.key.keysym.sym == SDLK_d || event.key.keysym.sym == SDLK_z || event.key.keysym.sym == SDLK_s){
				*d = 0;
				*d2 = 0;
			}
		break;
    }
}
