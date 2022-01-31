#include "Utility.h"
/*
----------------------------------------------------------------------
 Funzione 'Giocatore' - Movimento tramite i tasti cursore 
----------------------------------------------------------------------
*/
void Giocatore(int pipeout)
{
struct position gpos;

  gpos.x = 2;       /* Coordinata X iniziale */
  gpos.y = MAXY/2;   /* Coordinata Y iniziale */
  gpos.c='G';	    /* Carattere identificativo giocatore*/

  /* Comunico al processo padre le coordinate iniziali del giocatore */
  write(pipeout,&gpos,sizeof(gpos));

  /* Lettura dei tasti cursore */
  while(1)
  {
  		char c;
    c = getch();

    if (c==UP && gpos.y > 0){
      gpos.y-=1;				
    }

    if(c==DW  && gpos.y < MAXY - 1){
      gpos.y+=1;		
    }

    if(c==SPC){
        
    }
    usleep(100000);

    /* Comunico al processo padre le coordinate del giocatore */
    write(pipeout,&gpos,sizeof(gpos)); 

  }
}