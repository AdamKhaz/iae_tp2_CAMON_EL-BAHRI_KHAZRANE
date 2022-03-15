#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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
    Pile head = (*p);   //on définit un élément temporaire comme étant le sommet de la pile
	char* new_head = malloc(sizeof(char*));  //on crée dynamiquement un nouveau sommet
	strcpy(new_head,(*p)->data);   //on copie la valeur de la data du sommet de la pile dans le nouveau sommet
    (*p) = head->precedent;
	free(head);  //puis on free "l'ancien" sommet
	return new_head;
}

char* tetePile (Pile p){
    if (estPileVide(p)==1)  //retourne la valeur -1 si la pile est vide 
        exit(EXIT_FAILURE); //on ne peut pas return -1 vu que la fonction renvoit un char*

    return p->data;
}

void affichePile (Pile p){

    printf("PILE :\n");
    printf("------------------------\n");
    Elem_pile* elt_temp = p; //on définit un pointeur temporaire vers le haut de la pile afin de ne pas directement le faire avec le pointeur p
    while(elt_temp!=NULL){
        printf(" ---- \n");
        printf("| %s |\n",tetePile(elt_temp));
        elt_temp = elt_temp->precedent;
        //printf("%s\n",tetePile(elt_temp)); //affiche le dernier élément de la pile
    }
    if (elt_temp==NULL && p==NULL){
        printf(" ---- \n");
        printf("Pile dépilée !\n");
    }
}

void freePile(Pile p){
    while(p!=NULL){
        Pile elem = p;  //on crée un élément temporaire qui pointe sur le premier élément de la pile
        p = elem->precedent;  //on déplace donc le pointeur du premier élément de pile sur le second afin de libérer le premier
        free(elem);     //puis on libère le premier élément de la pile et ainsi de suite
    }
}
