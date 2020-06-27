/**
* @file minimap.c
* @brief minimap file.
* @author Eya Bahri
* @date june 12, 2019
*/
#include "minimap.h"

void initialiser_minimap(minimap * m){
    m->map = IMG_Load("minimap.png");
    m->cursor = IMG_Load("cursor.png");
    m->mmposition.x = 0;
    m->mmposition.y = 0;
    m->cposition.x = 0;
    m->cposition.y = 20;
}

void update_minimap(minimap * m, SDL_Surface * ecran, int x, int d, perso * pers){
    if(x <= 8000){
        if(x % 100 == 0 && d == 1){
            m->cposition.x += pers->step/2;
        }
        if(x % 100 == 0 && d == 2){
            m->cposition.x -= pers->step/2;
        }
    }
    if(pers->jump != 0){    
        if(pers->jump > 14)
            m->cposition.y = 15;
        else
            if(pers->jump > 9)
                m->cposition.y = 10;
            else
                m->cposition.y = 15;
    }
    else
        m->cposition.y = 20;
}

/*8000: taille de la map(pixels)
x%100(echelle) : kol 100 pixels condition tekhdem (kol 5 pas (khatoua=20 pixels)
pers->step : khatoua mta3 joueur( i9adem 20/2=10)
d : direction 1: imin /2:isar/


/* si yejri step=40 et 40 devient 20 sur minimap*/





