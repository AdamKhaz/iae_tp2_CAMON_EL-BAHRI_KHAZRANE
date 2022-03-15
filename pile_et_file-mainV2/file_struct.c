#include "file_struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


QueueS* creerFileStruct()
{
    QueueS* file = malloc(sizeof(QueueS));
    file->debut=NULL;
    file->fin=NULL;
    return file;
}

int estFileStructVide(QueueS p)
{
    if (p.debut==NULL) {
       // printf("La file est vide\n");
        return 1;
    }
    else {
        //printf("La file n'est pas vide\n");
        return 0;
    }
}

void enfileStruct(QueueS* p, struct_t* data)
{   
    Elem_FileStruct* element = malloc(sizeof(Elem_FileStruct));
    if (p->debut==NULL)
    {
        element->data=data;
        element->precedent=NULL;
        p->debut=element;
        p->fin=element;
    }
    else 
    {
        element->data=data;
        element->precedent=p->fin;
        p->fin=element;
    }
}

struct_t* defileStruct(QueueS* p)
{   
    if(estFileStructVide(*p)==1)
        return NULL;
    Elem_FileStruct* element=p->fin;
    while (element->precedent!=p->debut)
    {
        element = element->precedent;
    }
    p->debut=element;
    Elem_FileStruct* tete_file = element->precedent;
    p->debut->precedent=NULL;
    printf("Tete de file supprimee\n");
    return tete_file->data;
}

struct_t teteFileStruct(QueueS p)
{
    if(estFileStructVide(p)==1)
    {
        printf("La file est vide\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        return *(p.debut->data);
    }
}

void afficheFileStruct(QueueS p, void (*f)(struct_t*))
{
    if(estFileStructVide(p)==1)
    {
        printf("La file est vide\n");
        return;
    }
    Elem_FileStruct* element=p.fin;
    //int position_file=0;
    while(element->precedent!=NULL)
    {
        printf("NOM : %s | TIME : %d\n",element->data->name,element->data->time);
        element=element->precedent;
    }
    printf("NOM : %s | TIME : %d\n",element->data->name,element->data->time);
}

void freeFileStruct(QueueS* p)
{
    Elem_FileStruct* Copie=p->debut;
	while(Copie!=NULL){
		p->debut=Copie->precedent;
		//free(Copie->data);
		free(Copie);
		Copie=p->debut;
	}
	free(p);
}