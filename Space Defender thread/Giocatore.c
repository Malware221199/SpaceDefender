#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>
#include <pthread.h>
/*
----------------------------------------------------------------------
 Funzione 'giocatore' - Movimento tramite i tasti cursore 
----------------------------------------------------------------------
*/
void *giocatore(void *arg)
{
  int maxb=10; /*massimo proiettili disponibili*/

  
  Giocatore.x = 2;       /* Coordinata X iniziale */
  Giocatore.y = MAXY/2-2;   /* Coordinata Y iniziale */
  Giocatore.c='G';	    /* Carattere identificativo giocatore*/
  Giocatore.id=1;   /* Numero dell elemento */

  
  /* Lettura dei tasti cursore */
  while(!collision){
    /* Blocco mutex, cancello ultimo carattere e sblocco mutex */
	  pthread_mutex_lock(&mtx);			
    cancellasprite(Giocatore.y,Giocatore.x,Giocatore.c);
	  pthread_mutex_unlock(&mtx);


  		char c;
    c = getch();

    if (c==UP && Giocatore.y > 0){
      Giocatore.y-=1;				
    }

    if(c==DW  && Giocatore.y < MAXY - 1){
      Giocatore.y+=1;		
    }

    if(c==SPC){
      idbg++;
        bulletg; /* invocazione funzione bullet */
      idbg++;
        bulletg; /* invocazione funzione bullet */ 
      
    }

  /* Blocco mutex, disegno carattere, aggiorno schermo e sblocco mutex */
	pthread_mutex_lock(&mtx);			
  stampasprite(Giocatore.y,Giocatore.x,Giocatore.c);
	refresh();																							
	pthread_mutex_unlock(&mtx); 

  }
}