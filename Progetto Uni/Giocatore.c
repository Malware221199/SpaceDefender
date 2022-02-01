#include "Utility.h"
/*
----------------------------------------------------------------------
 Funzione 'Giocatore' - Movimento tramite i tasti cursore 
----------------------------------------------------------------------
*/
void Giocatore(int pipeout)
{
struct position giocatore;

  giocatore.x = 2;       /* Coordinata X iniziale */
  giocatore.y = MAXY/2;   /* Coordinata Y iniziale */
  giocatore.c='G';	    /* Carattere identificativo giocatore*/
  giocatore.id=1;   /* Numero dell elemento */


  /* Comunico al processo padre le coordinate iniziali del giocatore */
  write(pipeout,&giocatore,sizeof(giocatore));

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
        
    }

    /* Comunico al processo padre le coordinate del giocatore */
    write(pipeout,&giocatore,sizeof(giocatore)); 

  }
}