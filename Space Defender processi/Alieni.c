#include "Utility.h"
/*
----------------------------------------------------------------------
 Funzione 'Alieni'
---------------------------------------------------------------------- 
*/

void alieni(int pipeout,save new_alieno, int difficolta){
int idbn=0;
int deltax=1;		/* Spostamento orizzontale */
int deltay=1;		/* Spostamento verticale */


  /* Comunico le coordinate iniziali al processo padre */
  write(pipeout,&new_alieno,sizeof(new_alieno));

  while(1){

    /* Movimento X */
    new_alieno.x -= deltax;
    
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
    write(pipeout,&new_alieno,sizeof(new_alieno));

		/* Inserisco una pausa per rallentare il movimento */
    usleep(difficolta/3);
  }
}