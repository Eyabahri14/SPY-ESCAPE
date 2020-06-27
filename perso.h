#ifndef PERSO_H_INCLUDED
#define PERSO_H_INCLUDED

typedef struct perso
{
	SDL_Rect position;
	SDL_Surface * fond0;
	SDL_Surface * fond1;
	SDL_Surface * fond2;
	SDL_Surface * fond3;
	SDL_Surface * fonda;
	SDL_Surface * fondb;
	SDL_Surface * fondc;
	SDL_Surface * coeur;
	int score;
	int vitesse;
	int step;
	int jump;
}perso;

void initialiserperso(perso *perso);
void initialiserperso2(perso *perso);
int mouv(int d,int x);
perso mouvement(perso * pers,SDL_Rect camera,int d, int * tempsPrecedent, int * tempsPrecendent_jump);
void afficherperso(perso perso,SDL_Surface *ecran,int x);

#endif