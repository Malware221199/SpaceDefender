#include "Utility.h"
/*
----------------------------------------------------------------------
 Funzione 'Bullet giocatore'
---------------------------------------------------------------------- 
*/
void bulletg(int pipeout,save BG){
    int deltax=1;		/* Spostamento orizzontale */
    int deltay=1;		/* Spostamento verticale */
    BG.c ='B';	/* Carattere identificativo */
    BG.alive=true;

    /* Comunico le coordinate iniziali al processo padre */
    write(pipeout,&BG,sizeof(BG));

    while(1){
        if(BG.id%2==0){
            /* Movimento Y */
            BG.y += deltay;
            /* Se supero area Y schermo inverte il movimento */
            if(BG.y + deltay < 0 || BG.y + deltay > MAXY-1) deltay = -deltay;
            
        }
        else{
            /* Movimento Y */
            BG.y -= deltay;
            /* Se supero area Y schermo inverte il movimento */
            if(BG.y - deltay < 0 || BG.y - deltay > MAXY-1) deltay = -deltay;
            
        }
        
        
        /* Movimento X */
        BG.x += deltax;

        /* Comunico le coordinate correnti al processo padre */
        write(pipeout,&BG,sizeof(BG));

            /* Inserisco una pausa per rallentare il movimento */
        //usleep(50000);
    }
}
/*
----------------------------------------------------------------------
 Funzione 'Bullet nemico'
---------------------------------------------------------------------- 
*/
void bulletn(int pipeout,save BN){
    int deltax=1;		/* Spostamento orizzontale */
    BN.c ='H';	/* Carattere identificativo */
    BN.alive=true;

    while(1){
         /* Comunico le coordinate correnti al processo padre */
        write(pipeout,&BN,sizeof(BN));

        /* Movimento X */
        BN.x -= deltax;

        /* Inserisco una pausa per rallentare il movimento */
        //usleep(50000);
    }
}