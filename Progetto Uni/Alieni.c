#include "Utility.h"

/*
----------------------------------------------------------------------
 Funzione 'Alieni'
---------------------------------------------------------------------- 
*/

void Alieni(int pipeout, int contatore)
{
struct position Alieni;
int deltax=1;		/* Spostamento orizzontale */
int deltay=1;		/* Spostamento verticale */
  if(contatore==0){
  Alieni.x = MAXX-2;  /* Coordinata X iniziale */
  Alieni.y = MAXY/2;  /* Coordinata Y iniziale */
  Alieni.c ='A';	/* Carattere identificativo */
  printf("hallo");
  }
  else if(contatore==1){
  Alieni.x = MAXX-2;  /* Coordinata X iniziale */
  Alieni.y = 1;  /* Coordinata Y iniziale */
  Alieni.c ='A';	/* Carattere identificativo */
  printf("ciao");
  }
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