#include "Utility.h"
/*
----------------------------------------------------------------------
 Funzione 'Generatore Alieni'
---------------------------------------------------------------------- 
*/void Gen_alieni(int pipeout,int nnemici){
      do{
        int p[2];
        pipe(p);
        int pidA;
        pidA = fork();
        if(pidA==0){
            
            Alieni(p[1],nnemici); /* invocazione funzione alieni */
            nnemici--;    
        }
      }while(nnemici>0);
}

/*
----------------------------------------------------------------------
 Funzione 'Alieni'
---------------------------------------------------------------------- 
*/

void Alieni(int pipeout, int nnemici){
struct position Alieni;
int deltax=1;		/* Spostamento orizzontale */
int deltay=1;		/* Spostamento verticale */

  Alieni.x = MAXX-2;  /* Coordinata X iniziale */
  Alieni.y = MAXX/2;  /* Coordinata Y iniziale */
  Alieni.c ='A';	/* Carattere identificativo */
  Alieni.n =nnemici; /* Numero dell elemento */
  
   /* Comunico le coordinate iniziali al processo padre */
  write(pipeout,&Alieni,sizeof(Alieni));

  while(1){

    /* Movimento Y */
    //Alieni.y += deltay;

    /* Se supero area X schermo inverte il movimento */
    if(Alieni.x + deltax < 1 || Alieni.x + deltax > MAXX){
      Alieni.x = MAXX-2;  /* Coordinata X iniziale */
      Alieni.y = MAXY/2;  /* Coordinata Y iniziale */
      }
    
    /* Movimento X */
    Alieni.x -= deltax;

    /* Comunico le coordinate correnti al processo padre */
    write(pipeout,&Alieni,sizeof(Alieni));

		/* Inserisco una pausa per rallentare il movimento */
    usleep(DELAYL);
  }
}