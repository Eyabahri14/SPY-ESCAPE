#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED
typedef struct map
{
	SDL_Rect position;
	SDL_Surface * fond;
	SDL_Surface * initial_fond;
	SDL_Surface * fondt;
	int stage;
}map;


void initialiserfond(map *map);
void refreshfond(map * map);
void afficherfond(map map,SDL_Rect camera,SDL_Surface *ecran);
#endif 
