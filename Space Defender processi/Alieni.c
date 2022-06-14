#include "Utility.h"
/*
----------------------------------------------------------------------
 Funzione 'Alieni'
---------------------------------------------------------------------- 
*/

void alieni(int pipeout,save A, int difficolta){
int idbn=0;
int deltax=1;		/* Spostamento orizzontale */
int deltay=1;		/* Spostamento verticale */
if(A.id==0||A.id==1) A.x= MAXX-(GSA+DA);
if(A.id==2||A.id==3) A.x= MAXX-(GSA+DA)*2;
if(A.id==4||A.id==5) A.x= MAXX-(GSA+DA)*3;
if(A.id==6||A.id==7) A.x= MAXX-(GSA+DA)*4;
if(A.id==8||A.id==9) A.x= MAXX-(GSA+DA)*5;
  if(A.id%2==0) A.y=(MAXY/4);
  else if (A.id%2==1) A.y=MAXY-(MAXY/4)-3;
  
  A.c ='A';	/* Carattere identificativo */
  A.pid= getpid();
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
        close(p[0]);
        bulletn(p[1],idbn,A.y,A.x);
        }
      }*/
    

    /* Comunico le coordinate correnti al processo padre */
    write(pipeout,&A,sizeof(A));

		/* Inserisco una pausa per rallentare il movimento */
    usleep(difficolta);
  }
}