#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pile_char.h"
#include "file_struct.h"
#include "experiment.h"
#include "xmlReader.h"
#include "schedule.h"

void checkXML(char* filename)
{
  xmlFile_t * xmlFile = openXML(filename);
  char* s;
  char* balise=malloc(sizeof(s));
  Elem_pile* p = NULL;
  while ((s = nextString(xmlFile))!=NULL)
  {
    if(isOpeningTag(s))
    {
      strcpy(balise,s);
      empile(&p,balise);
    }
    else if(isClosingTag(s))
    { 
      
      if(p==NULL)
      {
        printf("Pas de balise ouvrante pour </%s>",tagName(s));
        break;
      }
      else
      {
        balise=depile(&p);
        if (strcmp(tagName(balise), tagName(s)))
        {
          printf("balise </%s> lue, mais </%s> attendue\n", tagName(s), tagName(balise));
          empile(&p,balise);
          continue;
        }
      }
    }
  }
  if(p!=NULL)
  {
    printf("Pas de balise fermante pour %s\n",tetePile(p));
  }
  else
    {printf("FICHIER OK.\n");}
  printf("\n");
  affichePile(p);
  freePile(p);
  closeXML(xmlFile);
}

void drawGraph(char* filename,FILE* out) {
}


void usage()
{
  printf("USAGE : ./xmlChecker filename.xml\n");
}

int main(int argc, char * argv[])
{
  if(argc <= 1)
  {
    usage();
    return EXIT_FAILURE;
  } 
  printf("\n--------EXERCICE 4---------\n");
  printf("\n");
  printf("Balises du fichier '%s':\n",argv[1]);
  fonctionXML(argv[1]); // fonctionXML(char* fichier) affiche toutes les balises du fichier avec tabulations.
  printf("\n");
  printf("Vérification du fichier '%s':\n\n",argv[1]);
  checkXML(argv[1]);
  printf("\n--------EXERCICE 5---------\n\n");
  completeSchedule(argv[1]);
  //drawGraph(argv[1],stdout);
  return EXIT_SUCCESS;
}