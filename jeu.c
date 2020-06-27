/**
* @file IA 
* @brief jeu program.
* @author Eya Bahri
* @date june 12, 2019
*/
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
#include <unistd.h>
#include "map.h"
#include "perso.h"
#include "scrolling.h"
#include "input.h"
#include "map.h"
#include "perso.h"
#include "scrolling.h"
#include "input.h"
#include "fonction.h"
#include "enigme.h"
#include "minimap.h"
#include "roto.h"

void jeu()
{
perso perso ;
map map ;
SDL_Rect pos; 
int q,w=10;

pos.x=0;
pos.y=0;

SDL_Rect camera = { 0, 0, 1000, 600 };

camera.x=0;
camera.y=0;
SDL_Surface *ecran = NULL;

srand(time(NULL)) ;
TTF_Font *police;
int d=0,x=0,y=1;
int continuer = 1;

SDL_Event event;
    SDL_Init(SDL_INIT_EVERYTHING);
ecran = SDL_SetVideoMode(1000, 560, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);

initialiserperso(&perso);
initialiserfond(&map);


SDL_EnableKeyRepeat(300,10);
SDL_ShowCursor(SDL_DISABLE);
SDL_LockSurface;
Uint32 start;
const int FPS=15;

//ES init  
/* intialisation des es
es : medkit
es2 : ennemi */
ES es,es2;
initializeES(&es);
initializeES2(&es2);
int mvd=0,mvg=0,verif1=0,verif2=0,etat;

int ESState = 1;
int ES2State = 1;

int tempsp=0,tempsa=0;
int v=1;
int tempspb=0,tempsab=0;
int vb=1;

// TODO: rename these 
/* teba3 collison */
int xtemp=1;
int xbtemp=1;
SDL_Surface * circlea;

//Minimap init
minimap M;
initialiser_minimap(&M); 

//Acceleration & jump init
int tempsVitesse = 0;
int tempsSaut = 0;

while (continuer) 
{

start=SDL_GetTicks();
d=direction(event,&continuer);
x = mouv(d,x);
camera = scrolling(d,camera,&perso,&map);
perso=mouvement(&perso,camera,d,&tempsVitesse,&tempsSaut);
afficherfond(map,camera,ecran);
afficherperso(perso,ecran,x);

//collision check(on verifie si le joueur est en collision avc les es)
SDL_Rect pplayer;
pplayer.x = perso.position.x + camera.x;
pplayer.y = perso.position.y;
pplayer.h = perso.position.h;
pplayer.w = perso.position.w;

if(!collitrigo(perso.fond0,NULL,pplayer,es.espos) && ESState == 1){
    scorecount(&perso.score,&perso.coeur,0); //0 : damou m3ebi
    xtemp=1; 
    ESState = 2;
}

if(!collitrigo(perso.fond0,NULL,pplayer,es2.espos) && ES2State == 1){
    xbtemp=1;
    ES2State = 2;

    srand(time(NULL)); //mn 115 lel 125 code enigme
    int enigma_index=rand()%7;
    enigma(ecran,enigma_index);
    SDL_Flip(ecran);
    if(reponse(ecran,enigma_index)){
        ES2State = 2;
    }
    else{
        ES2State = 2;
        scorecount(&perso.score,&perso.coeur,1);
    }
}

// ES update(mise a jour des positions)
if(xtemp && ESState == 1)
    mves(&es.espos,&tempsp,&tempsa,&v); //mves: t9adem w twakher medkit ken actif
if(xbtemp && ES2State == 1)
    mves2(&es2.espos,&tempspb,&tempsab,&vb);

// Rotozoom section
double zoom = 1;
int tempsPrecedent = 0, tempsActuel = 0;

int TEMPS=30;

tempsActuel = SDL_GetTicks();
if(tempsActuel - tempsPrecedent > TEMPS){
    if(ES2State == 2){
        if(zoom > 0.95)//nsaghrou lin nouslou 0.991 
            zoom -= 0.01;

        es2.image = ESDeathAnimation(&zoom, es2.image); //ESDeathanimation :nsaghrou fl image 
        tempsPrecedent = tempsActuel;
    }
    else{
        if(zoom <= 0.991){//nsaghrou lin nouslou 0.991 w ki nakhltou twali zoom=1
            ES2State = 0;
            zoom = 1;
            tempsPrecedent = tempsActuel;
        }
    }

    if(ESState == 2){
        if(zoom > 0.95)
            zoom -= 0.01;

        es.image = ESDeathAnimation(&zoom, es.image);
        tempsPrecedent = tempsActuel;
    }
    else{
        if(zoom <= 0.981){
            ESState = 0;
            zoom = 1;
            tempsPrecedent = tempsActuel;
        }
    }
}

refreshfond(&map);
SDL_BlitSurface(es.image,NULL,map.fond, &es.espos);
SDL_BlitSurface(es2.image,NULL,map.fond, &es2.espos);
afficherperso(perso,ecran,x);
SDL_BlitSurface(perso.coeur,NULL,ecran, &map.position);

update_minimap(&M,ecran,pplayer.x,d,&perso);
SDL_BlitSurface(M.map,NULL,ecran,&M.mmposition);
SDL_BlitSurface(M.cursor,NULL,ecran,&M.cposition);

SDL_Flip(ecran);
if(1000/FPS>SDL_GetTicks()-start)
SDL_Delay(1000/FPS-(SDL_GetTicks()-start));

}
}

void jeu2() //fonction jeu fl multiplayer w jeu1 fl single player
{
perso perso,perso2;
map map ;
SDL_Rect pos;
int q,w=10;

pos.x=0;
pos.y=0;

SDL_Rect camera = { 0, 0, 1000, 600 };

camera.x=0;
camera.y=0;

SDL_Surface *ecran = NULL;

srand(time(NULL));
TTF_Font *police;
int d=0,d2=0,x=0,x2=0,y=1;
int continuer = 1;

SDL_Event event;
    SDL_Init(SDL_INIT_EVERYTHING);
ecran = SDL_SetVideoMode(1000, 560, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);

initialiserperso(&perso);
initialiserperso2(&perso2);
initialiserfond(&map);


SDL_EnableKeyRepeat(300,10);
SDL_ShowCursor(SDL_DISABLE);
SDL_LockSurface;
Uint32 start;
const int FPS=15;

//ES init
ES es,es2;
initializeES(&es);
initializeES2(&es2);
int mvd=0,mvg=0,verif1=0,verif2=0,etat;

int ESState = 1;
int ES2State = 1;

int tempsp=0,tempsa=0;
int v=1;
int tempspb=0,tempsab=0;
int vb=1;

// TODO: rename these
int xtemp=1;
int xbtemp=1;
SDL_Surface * circlea;

//Minimap init
minimap M;
initialiser_minimap(&M); 

//Acceleration & jump init
int tempsVitesse = 0;
int tempsSaut = 0;
int tempsVitesse2 = 0;
int tempsSaut2 = 0;

while (continuer)
{

start=SDL_GetTicks();
direction2(&d,&d2,event,&continuer);

printf("d %d d2 %d\n",d,d2);
x = mouv(d,x);
x2 = mouv(d2,x2);
camera = scrolling(d,camera,&perso,&map);
perso = mouvement(&perso,camera,d,&tempsVitesse,&tempsSaut);
perso2 = mouvement(&perso2,camera,d2,&tempsVitesse2,&tempsSaut2);
afficherfond(map,camera,ecran);
afficherfond(map,camera,ecran);

//afficherperso(perso,ecran,x);
//afficherperso(perso2,ecran,x2);

//collision check
SDL_Rect pplayer;
pplayer.x = perso.position.x + camera.x;
pplayer.y = perso.position.y;
pplayer.h = perso.position.h;
pplayer.w = perso.position.w;

if(!collitrigo(perso.fond0,NULL,pplayer,es.espos) && ESState == 1){
    scorecount(&perso.score,&perso.coeur,0);
    xtemp=1;
    ESState = 2;
}

if(!collitrigo(perso.fond0,NULL,pplayer,es2.espos) && ES2State == 1){
    xbtemp=1;
    ES2State = 2;

    srand(time(NULL));
    int enigma_index=rand()%7;
    enigma(ecran,enigma_index);
    SDL_Flip(ecran);
    if(reponse(ecran,enigma_index)){
        ES2State = 2;
    }
    else{
        ES2State = 2;
        scorecount(&perso.score,&perso.coeur,1);
    }
}

// ES update
if(xtemp && ESState == 1)
    mves(&es.espos,&tempsp,&tempsa,&v);
if(xbtemp && ES2State == 1)
    mves2(&es2.espos,&tempspb,&tempsab,&vb);

// Rotozoom section
double zoom = 1;
int tempsPrecedent = 0, tempsActuel = 0;

int TEMPS=30;

tempsActuel = SDL_GetTicks();
if(tempsActuel - tempsPrecedent > TEMPS){
    if(ES2State == 2){
        if(zoom > 0.95)
            zoom -= 0.01;

        es2.image = ESDeathAnimation(&zoom, es2.image);
        tempsPrecedent = tempsActuel;
    }
    else{
        if(zoom <= 0.991){
            ES2State = 0;
            zoom = 1;
            tempsPrecedent = tempsActuel;
        }
    }

    if(ESState == 2){
        if(zoom > 0.95)
            zoom -= 0.01;

        es.image = ESDeathAnimation(&zoom, es.image);
        tempsPrecedent = tempsActuel;
    }
    else{
        if(zoom <= 0.981){
            ESState = 0;
            zoom = 1;
            tempsPrecedent = tempsActuel;
        }
    }
}

refreshfond(&map);
SDL_BlitSurface(es.image,NULL,map.fond, &es.espos);
SDL_BlitSurface(es2.image,NULL,map.fond, &es2.espos);
afficherperso(perso,ecran,x);
afficherperso(perso2,ecran,x2);
SDL_BlitSurface(perso.coeur,NULL,ecran, &map.position);

update_minimap(&M,ecran,pplayer.x,d,&perso);
SDL_BlitSurface(M.map,NULL,ecran,&M.mmposition);
SDL_BlitSurface(M.cursor,NULL,ecran,&M.cposition);

SDL_Flip(ecran);
if(1000/FPS>SDL_GetTicks()-start)
SDL_Delay(1000/FPS-(SDL_GetTicks()-start));

}
}
