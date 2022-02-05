#include "Utility.h"
/*
----------------------------------------------------------------------
 Funzione 'Alieni'
---------------------------------------------------------------------- 
*/

void alieni(int pipeout, int id,int nnemici, int difficolta){
struct position Alieni;
int r=1;
int deltax=1;		/* Spostamento orizzontale */
int deltay=1;		/* Spostamento verticale */
  Alieni.x=MAXX-((2+3)*r);
  if(id%2==0){
    Alieni.y=MAXY/4;
    r++;
  }

  else Alieni.y=MAXY-(MAXY/4);
  
  Alieni.c ='A';	/* Carattere identificativo */
  Alieni.id =id; /* Numero dell elemento */
  Alieni.pid= getpid();

  /* Comunico le coordinate iniziali al processo padre */
  write(pipeout,&Alieni,sizeof(Alieni));

  while(1){

    /* Movimento Y */
    Alieni.y += deltay;
    int ciao;
    ciao++;
    mvprintw(0,60,"ciao %d",ciao);
    

    if(ciao < 0 || ciao > 4){
      ciao = -ciao;
      deltay = -deltay;
    }
    
    /* Movimento X */
    Alieni.x -= deltax;

    /* Comunico le coordinate correnti al processo padre */
    write(pipeout,&Alieni,sizeof(Alieni));

		/* Inserisco una pausa per rallentare il movimento */
    usleep(difficolta);
  }
}