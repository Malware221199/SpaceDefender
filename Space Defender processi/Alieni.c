#include "Utility.h"
/*
----------------------------------------------------------------------
 Funzione 'Alieni'
---------------------------------------------------------------------- 
*/

void alieni(int pipeout,save new_alieno, int difficolta){
save BN[NMB];
pid_t pidBN[NMB];


int idbn=0;
int deltax=1;		/* Spostamento orizzontale */
int deltay=1;		/* Spostamento verticale */

  while(1){
    /* Comunico le coordinate correnti al processo padre */
    write(pipeout,&new_alieno,sizeof(new_alieno));

    /* Movimento X */
    new_alieno.x -= deltax;

    /* Movimento Y */   
    if(myida%2==0){
        
        A[myida].cord.y -= deltay;
        /* Se supero area Y schermo inverte il movimento */
        if(A[myida].cord.y - deltay < 1 || A[myida].cord.y - deltay > MAXY/2-GSA) deltay *=-1;
        
    }
    else if(myida%2==1){

        A[myida].cord.y += deltay;
        /* Se supero area Y schermo inverte il movimento */
        if(A[myida].cord.y + deltay < MAXY/2  || A[myida].cord.y + deltay > (MAXY-GSA-1)) deltay *=-1;
        
    }
    
    if (random() < RAND_MAX/10){
      idbn++;
      pidBN[idbn]=fork();
      if(pidBN[idbn]==0) {
      BN[idbn].x = new_alieno.x-1;
      BN[idbn].y = new_alieno.y+1;
      BN[idbn].id=idbn;
      BN[idbn].pid=getpid();
      bulletn(pipeout,BN[idbn]);
      }
    }
    

    

		/* Inserisco una pausa per rallentare il movimento */
    usleep(difficolta/3);
  }
}