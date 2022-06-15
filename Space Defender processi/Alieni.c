#include "Utility.h"
/*
----------------------------------------------------------------------
 Funzione 'Alieni'
---------------------------------------------------------------------- 
*/

void alieni(int pipeout,save new_alieno, int difficolta){
save BN;
srand(getpid());


int idbn=0;
int deltax=1;		/* Spostamento orizzontale */
int deltay=1;		/* Spostamento verticale */

  while(1){
    /* Comunico le coordinate correnti al processo padre */
    write(pipeout,&new_alieno,sizeof(new_alieno));

    /* Movimento X */
    new_alieno.x -= deltax;

    /* Movimento Y */   
    if(new_alieno.id%2==0){
        
        new_alieno.y -= deltay;
        /* Se supero area Y schermo inverte il movimento */
        if(new_alieno.y - deltay < 1 || new_alieno.y - deltay > MAXY/2-GSA) deltay *=-1;
        
    }
    else if(new_alieno.id%2==1){

        new_alieno.y += deltay;
        /* Se supero area Y schermo inverte il movimento */
        if(new_alieno.y + deltay < MAXY/2  || new_alieno.y + deltay > (MAXY-GSA-1)) deltay *=-1;
        
    }
    if (random() < RAND_MAX/15){
      BN.x = new_alieno.x-1;
      BN.y = new_alieno.y+1;
      BN.c='N';
    }
    

    

		/* Inserisco una pausa per rallentare il movimento */
    usleep(difficolta);
  }
}