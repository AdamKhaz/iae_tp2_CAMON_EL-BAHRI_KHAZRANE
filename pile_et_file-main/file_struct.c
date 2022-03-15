#include "file_struct.h"



QueueS* creerFileStruct()
{
    QueueS* file = malloc(sizeof(QueueS));
    file->debut=NULL;
    file->fin=NULL;   //on crée la file en faisait les liens pour les pointeurs vers le début et la fin de cette-ci 
    return file;
}

int estFileStructVide(QueueS p)
{
    if (p.debut!=NULL) {
        //printf("La file n'est pas vide\n");
        return 0;    //on return 0 si la file n'est pas vide
    }
    else {
        //printf("La file est vide\n");
        return 1;    //on return 1 si la file est vide
    }
}

void enfileStruct(QueueS* p, struct_t* data)
{
    Elem_FileStruct* dernier = malloc(sizeof(Elem_FileStruct));
    dernier->data = malloc(sizeof(struct_t));
    *dernier->data=*data;
    if (estFileStructVide(*p)==1) //si la file est vide, alors on définit l'élement que l'on y ajoute comme son premier et aussi son dernier
    {
        p->debut=dernier;
        p->fin=dernier;
    }
    else 
    { 
        dernier->precedent=p->fin;   //si non on définit l'ancien dernier élément comme le précédent du nouveau dernier
        p->fin=dernier;     //puis on met à jour le pointeur actuel de fin de la file 
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
    return tete_file->data;
}

struct_t teteFileStruct(QueueS p)
{
    if(estFileStructVide(p)==1)   //si la file est vide la fonction renvoit 1
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
    printf("FILE :\n");
    printf("------------------------\n");
    if(estFileStructVide(p)==1)
    {
        printf("La file est vide\n");
        return;
    }
    Elem_FileStruct* element=p.fin;
    while(element->precedent!=NULL)
    {
        printf("NOM : %s | TIME : %d\n",element->data->name,element->data->time);
        element=element->precedent;
    }
    printf("NOM : %s | TIME : %d\n",element->data->name,element->data->time);
}

void freeFileStruct(QueueS* p)
{
    Elem_FileStruct* premier = p->debut;   //le dernier (ou plutot le premier à sortir) élément de la file est le temporaire
    while(premier!=NULL){   //tant qu'il a toujours un précédent
        p->debut=premier->precedent;        //on positionne le pointeur de la file sur le prochain à sortir (après dernier)
        free(premier);            //on libère le dernier
        premier=p->debut;    //le prochain à sortir est son précédent
    }
}