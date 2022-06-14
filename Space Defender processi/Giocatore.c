#include "Utility.h" 
/*
----------------------------------------------------------------------
 Funzione 'giocatore' - Movimento tramite i tasti cursore 
----------------------------------------------------------------------
*/
void giocatore(int pipeout)
{
  int i,idb=0, maxb=10; /*ID proiettile,massimo proiettili disponibili*/
  
  G.x = 2;       /* Coordinata X iniziale */
  G.y = MAXY/2-2;   /* Coordinata Y iniziale */
  G.c='G';	    /* Carattere identificativo giocatore*/
  G.id=1;   /* Numero dell elemento */
  G.pid=getpid();  /*Pid processo*/
  G.alive=true;


  /* Comunico al processo padre le coordinate iniziali del giocatore */
  write(pipeout,&G,sizeof(G));
  
  /* Lettura dei tasti cursore */
  while(1)
  {
  		char c;
    c = getch();

    if (c==UP && G.y > 0){
      G.y-=1;				
    }

    if(c==DW  && G.y < MAXY - 5){
      G.y+=1;		
    }

    if(c==SPC){
      for(i=0;i<2;i++){
        pidBG=fork();
        idb++;
        if(pidBG==0) {
          BG[idb].x=G.x+7;
          BG[idb].y=G.y+2;
          BG[idb].id=idb;
          BG[idb].pid=getpid();

          bulletg(p[1],BG[idb]); /* invocazione funzione bullet */ 
        }
      }
    }

    /* Comunico al processo padre le coordinate del giocatore */
    write(pipeout,&G,sizeof(G)); 

  }
}