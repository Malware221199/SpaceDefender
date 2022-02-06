#include "Utility.h"
/*
----------------------------------------------------------------------
 Funzione 'Alieni'
---------------------------------------------------------------------- 
*/

void *alieni(void *arg){
int deltax=1;		/* Spostamento orizzontale */
int deltay=1;		/* Spostamento verticale */
if(id==0||id==1) Alieni.x= MAXX-(GSA+DA);
if(id==2||id==3) Alieni.x= MAXX-(GSA+DA)*2;
if(id==4||id==5) Alieni.x= MAXX-(GSA+DA)*3;
if(id==6||id==7) Alieni.x= MAXX-(GSA+DA)*4;
if(id==8||id==9) Alieni.x= MAXX-(GSA+DA)*5;
  if(id%2==0) Alieni.y=(MAXY/4);
  else if (id%2==1) Alieni.y=MAXY-(MAXY/4)-3;
  
Alieni.c ='A';	/* Carattere identificativo */
Alieni.id =id; /* Numero dell elemento */

while(!collision){
  /* Blocco mutex, cancello ultimo carattere e sblocco mutex */
	pthread_mutex_lock(&mtx);			
  cancellasprite(Alieni.y,Alieni.x,Alieni.c);
	pthread_mutex_unlock(&mtx);
    
  /* Movimento X */
  Alieni.x -= deltax;

  /* Blocco mutex, disegno carattere, aggiorno schermo e sblocco mutex */
	pthread_mutex_lock(&mtx);			
  stampasprite(Alieni.y,Alieni.x,Alieni.c);
	refresh();																							
	pthread_mutex_unlock(&mtx); 

    
  if (random() < RAND_MAX/10){
    idbn++;
    pidBN=fork();
    if(pidBN==0) {
    close(p[0]);
    bulletn(p[1],idbn,Alieni.y,Alieni.x);
    }
  }
    
  /* Inserisco una pausa per rallentare il movimento */
  usleep(difficolta);
  }
}