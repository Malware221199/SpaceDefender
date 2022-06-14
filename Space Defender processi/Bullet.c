#include "Utility.h"
/*
----------------------------------------------------------------------
 Funzione 'Bullet giocatore'
---------------------------------------------------------------------- 
*/
void bulletg(int pipeout,int id,int cgy,int cgx){
    save Bullet;
    int deltax=1;		/* Spostamento orizzontale */
    int deltay=1;		/* Spostamento verticale */
    Bullet.x = cgx+7;  /* Coordinata X iniziale */
    Bullet.y = cgy+2;  /* Coordinata Y iniziale */
    Bullet.c ='B';	/* Carattere identificativo */
    Bullet.id =id; /* Numero dell elemento */
    Bullet.pid=getpid(); /*Pid processo*/
    Bullet.alive=true;
    

    

    /* Comunico le coordinate iniziali al processo padre */
    write(pipeout,&Bullet,sizeof(Bullet));

    while(1){
        if(id%2==0){
            /* Movimento Y */
            Bullet.y += deltay;
            /* Se supero area Y schermo inverte il movimento */
            if(Bullet.y + deltay < 0 || Bullet.y + deltay > MAXY-1) deltay = -deltay;
            
        }
        else{
            /* Movimento Y */
            Bullet.y -= deltay;
            /* Se supero area Y schermo inverte il movimento */
            if(Bullet.y - deltay < 0 || Bullet.y - deltay > MAXY-1) deltay = -deltay;
            
        }
        
        
        /* Movimento X */
        Bullet.x += deltax;

        /* Comunico le coordinate correnti al processo padre */
        write(pipeout,&Bullet,sizeof(Bullet));

            /* Inserisco una pausa per rallentare il movimento */
        usleep(50000);
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
    

    

    /* Comunico le coordinate iniziali al processo padre */
        write(pipeout,&BN,sizeof(BN));

    while(1){
        /* Movimento X */
        BN.x -= deltax;

        /* Comunico le coordinate correnti al processo padre */
        write(pipeout,&BN,sizeof(BN));

            /* Inserisco una pausa per rallentare il movimento */
        usleep(50000);
    }
}