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

void empile ( Pile* p , char* data ){
    Pile debut= malloc(sizeof(Elem_pile));
    debut->data=data;                         
    debut->precedent= *p;
    *p=debut;
    //printf("| %s |\n",p->data);
                     
}
char* depile(Pile* p){

    if (*p == NULL){                        //si pas de sommet
        exit(EXIT_FAILURE);                     //le programme s'arrete
    }
    Pile elemSuiv=NULL;
    elemSuiv = (*p)->precedent;                 //notre nouveau sommet va etre égale au prochain sommet de notre sommet courant          
    free(*p);                               //on désalloue la memoire de notre ancien sommet
    *p = elemSuiv;
    return (*p)->data;
}
char* tetePile ( Pile p ){
    if(!p){
        exit(EXIT_FAILURE);
    }
    return p->data;
}
void affichePile ( Pile  p ){

    Elem_pile* affiche = p;
    printf("La Pile est:\n");
    while(affiche){              //tant que sommet non vide
        printf(" ------- \n");
        printf("| %s |\n",affiche->data); //affiche la valeur contenue dans le sommet
        affiche=affiche->precedent;             //incremente le sommet au sommet suivant
    }
    if (affiche==NULL && p==NULL){       //si pile vide
        printf(" ------- \n");
        printf("LA PILE A BIEN ETE DEPILER GG!\n"); //preuve que la pile à bien été vidée
    }
}
void freePile( Pile p){

    while(p!=NULL){                //tant que le sommet n'est pas vide/nul
        Pile Copie = p;
		p = Copie->precedent;
        free(Copie);        //on dépile le sommet jusqu'à la fin de la pile
    }
}
