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
	  if(isOpeningTag(s) && !strcmp(tag,"experience")){
	    exp = malloc(sizeof(experiment_t));
	  }
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
/*
void afficheExp(experiment_t * e){
  assert(e != NULL);
  printf("%s\n",e->name);
}
*/

void completeSchedule(char* filename){
	QueueS* filecourante = creerFileStruct();      //on crée notre file d'exp en cours
	QueueS* filedebut = scheduleStart(filename);   //on crée notre file de début des exp
	int heure;
	int minutes;

	heure=((filedebut->debut->data->time)/60);   //on affiche l'heure exacte de son début
	minutes=((filedebut->debut->data->time)%60);
	printf("début %dh%.2d ",heure, minutes);
	afficheExperiment(filedebut->debut->data);     //on affiche la première expérience
	enfileStruct(filecourante,filedebut->debut->data);  //on ajoute cette première expérience dans la file des expériences en cours
	defileStruct(filedebut);   //on retire la première expérence de la file 

	while((!estFileStructVide(*filedebut))&&(!estFileStructVide(*filecourante))){
		while(((filecourante->debut->data->time)+90 < filedebut->debut->data->time)){  //tant que la tête de file est une exp qui termine avant la suivante E
			
			heure=((filecourante->debut->data->time)+90)/60;   //on affiche l'heure exacte de fin (heure exacte debut + 90')
			minutes=((filecourante->debut->data->time)+90)%60;
			printf("fin %dh%.2d ",heure, minutes);
			afficheExperiment(filecourante->debut->data);     //on affiche la fin de l'exp courante
			defileStruct(filecourante);   //puis on la défile
		}
		//si l'on est arrivé ici c'est que la prochaine expérience à afficher est le début de la nième : on réitère donc l'opération du début
		
		heure=((filedebut->debut->data->time)/60);   //on met l'heure à jour
		minutes=((filedebut->debut->data->time)%60);
		printf("début %dh%.2d ",heure, minutes);
		afficheExperiment(filedebut->debut->data);   
		enfileStruct(filecourante,filedebut->debut->data);  //on ajoute cette première expérience dans la file des expériences en cours
		defileStruct(filedebut);   //on retire la première expérence de la file 

		while(estFileStructVide(*filedebut)&&(!estFileStructVide(*filecourante))){    //si l'on est arrivé à cette étape c'est que toutes les exp qui finissent plus tos que celles restant dans la file courante sont terminées
			
			heure=((filecourante->debut->data->time)+90)/60;   //on affiche l'heure exacte de fin (heure exacte debut + 90')
			minutes=((filecourante->debut->data->time)+90)%60;
			printf("fin %dh%.2d ",heure, minutes);
			afficheExperiment(filecourante->debut->data);     //on n'a alors plus qu'à afficher la fin des exp restantes
			defileStruct(filecourante);   //puis on la défile
		}
	}
	
}
