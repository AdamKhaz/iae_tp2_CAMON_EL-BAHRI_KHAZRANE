#include "pile_char.h"
#include "file_struct.h"



void test_pile() 
 { 
   // create  data 
   char s1[] = "1"; 
   char s2[] = "2"; 
   char s3[] = "3"; 
   char s4[] = "4"; 

   Pile p = NULL; 
   empile(&p,s1); 
   empile(&p,s2); 
   empile(&p,s3); 
   affichePile(p);
   printf("\n"); 
   char* d1 = depile(&p); //notre "vraie" ancienne tête de pile
   //depile(&p);                                          //^
                                                          //|
   empile(&p,s4);                                         //|
   affichePile(p);                                        //|
   printf("\n");                                          //|
                                                          //|
   //printf("old head %s new one %s\n",d,tetePile(p)); //si on met d ici, l'ancienne tête retournée ne sera pas la "vraie" ancienne : ce
                                                       //sera seulement celle qui l'a été après le dépilage de la pile, donc 2
                                                       //pour avoir la "vraie" ancienne tête (3), il faut donc changer l'appel dans le printf
   printf("old head %s new one %s\n",d1,tetePile(p));                                                    
   free(d1); 
   freePile(p); 
  
 } 




 void test_file_struct_experiment() 
 { 

   experiment_t  e1; 
   e1.time = 615; 
   strcpy(e1.name,"Experiment 1"); 
   experiment_t  e2; 
   e2.time = 680; 
   strcpy(e2.name,"Experiment 2"); 
   experiment_t  e3; 
   e3.time = 710; 
   strcpy(e3.name,"Experiment 3"); 
   experiment_t  e4; 
   e4.time = 750; 
   strcpy(e4.name,"Experiment 4"); 

   QueueS* q = creerFileStruct(); //cree la file
   enfileStruct(q,&e1); 
   enfileStruct(q,&e2); 
   enfileStruct(q,&e3); 
   afficheFileStruct(*q,afficheExperiment);
   printf("\n"); 
   experiment_t* d = defileStruct(q); 
   enfileStruct(q,&e4); 
   afficheFileStruct(*q,afficheExperiment); 
   printf(" old head : "); 
   afficheExperiment(d); 
   printf(" new head : "); 
   experiment_t old = teteFileStruct(*q); 
   afficheExperiment(&old); 
   free(d);
   freeFileStruct(q); 
   
 } 


int main()
{
  test_pile();
  printf("\n");
  test_file_struct_experiment ();
  return EXIT_SUCCESS;
}
