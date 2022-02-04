#include "Utility.h"
/*
----------------------------------------------------------------------
 Funzione 'Alieni'
---------------------------------------------------------------------- 
*/

void alieni(int pipeout, int id,int nnemici){
struct position Alieni;
int deltax=1;		/* Spostamento orizzontale */
int deltay=1;		/* Spostamento verticale */
switch (nnemici){
case 1:
  Alieni.x = MAXX-DA-GSA;  /* Coordinata X iniziale */
  Alieni.y = MAXY/2-1;  /* Coordinata Y iniziale */
  break;
case 2:
  Alieni.x = MAXX-DA-GSA;  /* Coordinata X iniziale */
  switch(id){
    case 0:
    Alieni.y = (MAXY/2)-DA-(2*GSA);  /* Coordinata Y iniziale */
    break;
    case 1:
    Alieni.y = MAXY/2+DA;  /* Coordinata Y iniziale */
    break;
    default:
    break;
  }
break;
default:
  break;
}
  Alieni.c ='A';	/* Carattere identificativo */
  Alieni.id =id; /* Numero dell elemento */
  Alieni.pid= getpid();

  /* Comunico le coordinate iniziali al processo padre */
  write(pipeout,&Alieni,sizeof(Alieni));

  while(1){

    /* Movimento Y */
    Alieni.y += deltay;
    deltay++
    

    if(deltay < 1 || deltay > 3){
      deltay = -deltay;
    }
    
    /* Movimento X */
    Alieni.x -= deltax;

    /* Comunico le coordinate correnti al processo padre */
    write(pipeout,&Alieni,sizeof(Alieni));

		/* Inserisco una pausa per rallentare il movimento */
    usleep(DELAYV);
  }
}