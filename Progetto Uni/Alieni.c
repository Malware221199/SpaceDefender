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
if(id==0||id==1) Alieni.x= MAXX-(GSA+DA);
if(id==2||id==3) Alieni.x= MAXX-(GSA+DA)*2;
if(id==4||id==5) Alieni.x= MAXX-(GSA+DA)*3;
if(id==6||id==7) Alieni.x= MAXX-(GSA+DA)*4;
if(id==8||id==9) Alieni.x= MAXX-(GSA+DA)*5;
  if(id%2==0){
    Alieni.y=(MAXY/4);
    r++;
  }
  else if (id%2==1) Alieni.y=MAXY-(MAXY/4)-3;
  
  Alieni.c ='A';	/* Carattere identificativo */
  Alieni.id =id; /* Numero dell elemento */
  Alieni.pid= getpid();

  /* Comunico le coordinate iniziali al processo padre */
  write(pipeout,&Alieni,sizeof(Alieni));

  while(1){

    /* Movimento Y */
    /*Alieni.y += deltay;
    int ciao;
    ciao++;
    mvprintw(0,60,"ciao %d",ciao);
    

    if(ciao < 0 || ciao > 4){
      ciao = -ciao;
      deltay = -deltay;
    }*/
    
    /* Movimento X */
    Alieni.x -= deltax;

    /* Comunico le coordinate correnti al processo padre */
    write(pipeout,&Alieni,sizeof(Alieni));

		/* Inserisco una pausa per rallentare il movimento */
    usleep(difficolta);
  }
}