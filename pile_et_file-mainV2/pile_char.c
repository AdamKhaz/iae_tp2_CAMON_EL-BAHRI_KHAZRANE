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
}
char* depile(Pile* p){

	if (estPileVide(*p) == 0){
		Pile copie = (*p);
		char* depile = malloc(sizeof(char*));
		strcpy(depile,(*p)->data);
		(*p) = copie->precedent;
		free(copie);
		return depile;
	}
	else{	
		printf("LA PILE EST VIDE! \n\n");
		return "-1";
	}
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
    while(affiche){               //tant que sommet non vide
        printf(" ---- \n");
        printf("| %s |\n",affiche->data); //affiche la valeur contenue dans le sommet
        affiche=affiche->precedent;             //incremente le sommet au sommet suivant
    }
    if (affiche==NULL && p==NULL){       //si pile vide
        printf(" ---- \n");
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
