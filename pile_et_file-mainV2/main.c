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
  char *s;
  int indent = 0;
  int i;
  Elem_pile* p = malloc(sizeof(Elem_pile));
  while ((s = nextString(xmlFile)) != NULL)
  {
    if(isTag(s))
	  {
	    if(isClosingTag(s))
	      indent--;
	    for(i = 0; i< indent; i++)
	      printf(" ");
	    printf("%s\n",s);
      //COMPLETER LA FONCTION ICI
      empile(p, s);

	    if(isOpeningTag(s))
	      indent++;
	  }
  }
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
 
  fonctionXML(argv[1]); // fonctionXML(char* fichier) affiche toutes les balises du fichier avec tabulations.
  //checkXML(argv[1]);
  //completeSchedule(argv[1]);
  //drawGraph(argv[1],stdout);
  return EXIT_SUCCESS;
}
