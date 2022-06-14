#include "Utility.h"
/*
----------------------------------------------------------------------
 Funzione 'Alieni'
---------------------------------------------------------------------- 
*/

void alieni(int pipeout,save new_alieno, int difficolta){
save BN[NMB];
int idbn=0;
int deltax=1;		/* Spostamento orizzontale */
int deltay=1;		/* Spostamento verticale */

  while(1){
    /* Comunico le coordinate correnti al processo padre */
    write(pipeout,&new_alieno,sizeof(new_alieno));

    /* Movimento X */
    new_alieno.x -= deltax;
    
    if (random() < RAND_MAX/10){
      idbn++;
      pidBN=fork();
      if(pidBN==0) {
      BN[idbn].x = new_alieno.x-1;
      BN[idbn].y = new_alieno.y+1;
      BN[idbn].id=idbn;
      BN[idbn].pid=getpid();
      bulletn(p[1],BN[idbn]);
      }
    }
    

    

		/* Inserisco una pausa per rallentare il movimento */
    usleep(difficolta/3);
  }
}