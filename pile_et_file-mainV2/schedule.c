#include "schedule.h"

QueueS* scheduleStart(char* filename)
{
  xmlFile_t * xmlFile = openXML(filename);
  char * s, *tag;
  int prev_state = IDLE;
  experiment_t* exp;
  QueueS *q = creerFileStruct();
  while ((s = nextString(xmlFile))!= NULL )
    {
      if(prev_state == DEBUT)
	{
	  exp->time = atoi(s);
	  prev_state = IDLE;
	}
      else{
	if(prev_state == NOM)
	  {
	    strcpy(exp->name,s);
	    prev_state = IDLE;     
	  }
      }
      if(isTag(s))
	{
	  tag = tagName(s);
	  if(isOpeningTag(s) && !strcmp(tag,"experience"))
	    exp = malloc(sizeof(experiment_t));
	  else{
	    if(isOpeningTag(s) && !strcmp(tag,"debut")) 
	      prev_state = DEBUT;
	    if(isOpeningTag(s) && !strcmp(tag,"nom")) 
	      prev_state = NOM;
	    if(isClosingTag(s) && !strcmp(tag,"experience"))
	      {
		enfileStruct(q,exp);
		free(exp);
	      }
	  }
	  free(tag);
	}
    }
  closeXML(xmlFile);
  return q;
}

void completeSchedule(char * filename){
	QueueS* fileactuelle= creerFileStruct();
	QueueS* filedepart= scheduleStart(filename);
	int h;
	int min;
	
	h=((filedepart->debut->data->time)/60);
	min=((filedepart->debut->data->time)%60);
	printf("début %dh%.2d ",h, min);
	afficheExperiment(filedepart->debut->data);
	enfileStruct(fileactuelle,filedepart->debut->data);
	defileStruct (filedepart); 

	while(!estFileStructVide(*filedepart)){
		while(!estFileStructVide(*fileactuelle)){
			while(((fileactuelle->debut->data->time)+90) < (filedepart->debut->data->time)){

				h=((fileactuelle->debut->data->time)+90)/60;
				min=((fileactuelle->debut->data->time)+90)%60;
				printf("fin %dh%.2d ",h, min);
				afficheExperiment(fileactuelle->debut->data);
				defileStruct (fileactuelle);
			}
			h=((filedepart->debut->data->time)/60);
			min=((filedepart->debut->data->time)%60);
			printf("début %dh%.2d ",h, min);
			afficheExperiment(filedepart->debut->data);
			enfileStruct(fileactuelle,filedepart->debut->data);
			defileStruct (filedepart); 

			while(estFileStructVide(*filedepart)&&(!estFileStructVide(*fileactuelle))){
				h=((fileactuelle->debut->data->time)+90)/60;
				min=((fileactuelle->debut->data->time)+90)%60;
				printf("fin %dh%.2d ",h, min);
				afficheExperiment(fileactuelle->debut->data);
				defileStruct (fileactuelle);
			}
		}
	}
}
