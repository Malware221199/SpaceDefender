#include "Utility.h"
/*
----------------------------------------------------------------------
 Funzione 'Bullet'
---------------------------------------------------------------------- 
*/
void bullet(int pipeout,int id){
    struct position Bullet;
    int deltax=1;		/* Spostamento orizzontale */
    int deltay=1;		/* Spostamento verticale */
    Bullet.x = 7;  /* Coordinata X iniziale */
    Bullet.y = (MAXY/2);  /* Coordinata Y iniziale */
    Bullet.c ='B';	/* Carattere identificativo */
    Bullet.id =id; /* Numero dell elemento */

    /* Comunico le coordinate iniziali al processo padre */
    write(pipeout,&Bullet,sizeof(Bullet));

    while(1){

        /* Movimento Y */
         Alieni.y += deltay;

        /* Se supero area X schermo inverte il movimento */
        //if(Alieni.x + deltax < 10 || Alieni.x + deltax > MAXX){
        //Alieni.x = MAXX-2;  /* Coordinata X iniziale */
        //Alieni.y = (MAXY/2)+(5*id);  /* Coordinata Y iniziale */
        //}
        //if(Alieni.y + deltay < 1 || Alieni.y + deltay > MAXY-3){
        //deltay = -deltay;
        //}
        
        /* Movimento X */
        Alieni.x -= deltax;

        /* Comunico le coordinate correnti al processo padre */
        write(pipeout,&Alieni,sizeof(Alieni));

            /* Inserisco una pausa per rallentare il movimento */
        usleep(DELAYL);
  }










}