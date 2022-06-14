#include "Utility.h"
/*
----------------------------------------------------------------------
 Funzione 'Alieni'
---------------------------------------------------------------------- 
*/

void alieni(int pipeout,save n, int difficolta){
int idbn=0;
int deltax=1;		/* Spostamento orizzontale */
int deltay=1;		/* Spostamento verticale */

  
  A.c ='A';	/* Carattere identificativo */
  A.alive=true;
  A.liv=1;

  /* Comunico le coordinate iniziali al processo padre */
  write(pipeout,&A,sizeof(A));

  while(1){

    /* Movimento X */
    A.x -= deltax;
    
     /* if (random() < RAND_MAX/10){
        idbn++;
        pidBN=fork();
        if(pidBN==0) {
        BN[idbn].x = A.x-1;
        BN[idbn].y = A.y+1;
        BN[idbn].id=idbn;
        BN[idbn].pid=getpid();
        bulletn(p[1],BN[idbn]);
        }
      }*/
    

    /* Comunico le coordinate correnti al processo padre */
    write(pipeout,&A,sizeof(A));

		/* Inserisco una pausa per rallentare il movimento */
    usleep(difficolta/3);
  }
}