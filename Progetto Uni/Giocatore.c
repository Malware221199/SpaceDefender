#include "Utility.h" 
/*
----------------------------------------------------------------------
 Funzione 'giocatore' - Movimento tramite i tasti cursore 
----------------------------------------------------------------------
*/
void giocatore(int pipeout)
{
  struct position giocatore;
  giocatore.x = 2;       /* Coordinata X iniziale */
  giocatore.y = MAXY/2;   /* Coordinata Y iniziale */
  giocatore.c='G';	    /* Carattere identificativo giocatore*/
  giocatore.id=1;   /* Numero dell elemento */


  /* Comunico al processo padre le coordinate iniziali del giocatore */
  write(pipeout,&giocatore,sizeof(giocatore));
  int idb=2;
  /* Lettura dei tasti cursore */
  while(1)
  {
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
      pidB1=fork();
      
      if(pidB1==0) {
        close(p[0]); /* chiusura del descrittore di lettura */
        bullet(p[1],idb,giocatore.y,giocatore.x); /* invocazione funzione bullet */
      }	
      idb++;
      /* Altrimenti sono ancora nel processo padre e creo il processo 'Giocatore' */
      pidB2=fork();
      /* Se il pid == 0 -> si tratta del processo 'Giocatore' */
      if(pidB2==0) {
        /* ed eseguo quindi la relativa funzione di gestione */
        close(p[0]); /* chiusura del descrittore di lettura */
        bullet(p[1],idb,giocatore.y,giocatore.x); /* invocazione funzione bullet */ 
        }
      
    }

    /* Comunico al processo padre le coordinate del giocatore */
    write(pipeout,&giocatore,sizeof(giocatore)); 

  }
}