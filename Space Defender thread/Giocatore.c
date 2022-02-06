#include "Utility.h" 
/*
----------------------------------------------------------------------
 Funzione 'giocatore' - Movimento tramite i tasti cursore 
----------------------------------------------------------------------
*/
void giocatore(void *arg)
{
  int maxb=10; /*massimo proiettili disponibili*/

  
  giocatore.x = 2;       /* Coordinata X iniziale */
  giocatore.y = MAXY/2-2;   /* Coordinata Y iniziale */
  giocatore.c='G';	    /* Carattere identificativo giocatore*/
  giocatore.id=1;   /* Numero dell elemento */

  
  /* Lettura dei tasti cursore */
  while(!collision){
    /* Blocco mutex, cancello ultimo carattere e sblocco mutex */
	  pthread_mutex_lock(&mtx);			
    cancellasprite(Alieni.y,Alieni.x,Alieni.c);
	  pthread_mutex_unlock(&mtx);


  		char c;
    c = getch();

    if (c==UP && giocatore.y > 0){
      giocatore.y-=1;				
    }

    if(c==DW  && giocatore.y < MAXY - 1){
      giocatore.y+=1;		
    }

    if(c==SPC){
      idb++;
        bulletg(); /* invocazione funzione bullet */
      idb++;
        bulletg(); /* invocazione funzione bullet */ 
      
    }

  /* Blocco mutex, disegno carattere, aggiorno schermo e sblocco mutex */
	pthread_mutex_lock(&mtx);			
  stampasprite(Alieni.y,Alieni.x,Alieni.c);
	refresh();																							
	pthread_mutex_unlock(&mtx); 

  }
}