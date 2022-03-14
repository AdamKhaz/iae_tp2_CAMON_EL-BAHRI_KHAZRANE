#include <stdlib.h>
#include <stdio.h>
#include "pile_char.h"

int estPileVide(Pile p){
    if (p == NULL){
        return 1;
    }
    return 0;
}

void empile (Pile* p ,char* data){
    Elem_pile* sommet = malloc(sizeof(Elem_pile));
    //on fait les liaisons
    sommet->data = data;
    sommet->precedent = *p;
    *p = sommet;
}

char* depile (Pile* p){
    if (estPileVide(*p)==1)  //retourne la valeur -1 si la pile est vide 
        exit(EXIT_FAILURE);
    Pile elt_suiv = malloc(sizeof(Elem_pile));
    elt_suiv = (*p)->precedent;              //on définit un élément temporaire comme étant le sommet de la pile
    free(*p);                       //puis on free "l'ancien" sommet
    *p = elt_suiv;
    return (*p)->data;
}

char* tetePile (Pile p){
    if (estPileVide(p)==1)  //retourne la valeur -1 si la pile est vide 
        exit(EXIT_FAILURE); //on ne peut pas return -1 vu que la fonction renvoit un char*

    return p->data;
}

void affichePile (Pile p){

    printf("Pile :\n");
    Elem_pile* elt_temp = p; //on définit un pointeur temporaire vers le haut de la pile afin de ne pas directement le faire avec le pointeur p
    while(elt_temp!=NULL){
        printf("%s\n",tetePile(elt_temp));
        elt_temp = elt_temp->precedent;
        //printf("%s\n",tetePile(elt_temp)); //affiche le dernier élément de la pile
    }
    if (elt_temp==NULL && p==NULL){
        printf("Pile dépilée !\n");
    }
}

void freePile(Pile p){
    while(p!=NULL){
        Pile temp = p;
        p = temp->precedent;
        free(temp);
    }
}
