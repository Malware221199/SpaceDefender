#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>
#include <pthread.h>
/*
----------------------------------------------------------------------
 Funzione 'Alieni'
---------------------------------------------------------------------- 
*/

void *alieni(void *arg){
int deltax=1;		/* Spostamento orizzontale */
int deltay=1;		/* Spostamento verticale */
if(Alieni.id==0||Alieni.id==1) Alieni.x= MAXX-(GSA+DA);
if(Alieni.id==2||Alieni.id==3) Alieni.x= MAXX-(GSA+DA)*2;
if(Alieni.id==4||Alieni.id==5) Alieni.x= MAXX-(GSA+DA)*3;
if(Alieni.id==6||Alieni.id==7) Alieni.x= MAXX-(GSA+DA)*4;
if(Alieni.id==8||Alieni.id==9) Alieni.x= MAXX-(GSA+DA)*5;
if(Alieni.id%2==0) Alieni.y=(MAXY/4);
else if (Alieni.id%2==1) Alieni.y=MAXY-(MAXY/4)-3;
  
Alieni.c ='A';	/* Carattere identificativo */
Alieni.id =ida; /* Numero dell elemento */

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
    bulletn;
    }
  
    
  /* Inserisco una pausa per rallentare il movimento */
  usleep(difficolta);
  }
}