#include "pile_char.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int estPileVide ( Pile p ){
    if(!p){
        printf("LA PILE EST VIDE! \n");
        return 1;
    }
    return 0;
}

void empile ( Pile p , char* data ){
    Elem_pile* debut= malloc(sizeof(Pile));
    debut->data=data;                         
    debut->precedent= p;
                     
}
char* depile(Pile p){

    if (p == NULL){                        //si pas de sommet
        exit(EXIT_FAILURE);                     //le programme s'arrete
    }
    Elem_pile* elemSuiv=NULL;
    elemSuiv = p->precedent;                 //notre nouveau sommet va etre égale au prochain sommet de notre sommet courant          
    free(p);                               //on désalloue la memoire de notre ancien sommet

    return elemSuiv->data;
}
char* tetePile ( Pile p ){
    if(!p){
        exit(EXIT_FAILURE);
    }
    return p->data;
}