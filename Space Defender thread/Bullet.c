#include "Utility.h"
/*
----------------------------------------------------------------------
 Funzione 'Bullet giocatore'
---------------------------------------------------------------------- 
*/
void *bulletg(void *arg){
    int deltax=1;		/* Spostamento orizzontale */
    int deltay=1;		/* Spostamento verticale */
    Bulletg.x = giocatore.x+7;  /* Coordinata X iniziale */
    Bulletg.y = giocatore.y+2;  /* Coordinata Y iniziale */
    Bulletg.c ='B';	/* Carattere identificativo */
    Bulletg.id =idb; /* Numero dell elemento */
    

    while(!collision){
        /* Cancello il precedente carattere visualizzato */
        cancellasprite(Bulletg.y,Bulletg.x,Bulletg.c);

        if(Bulletg.id%2==0){
            /* Movimento Y */
            Bulletg.y += deltay;
            /* Se supero area Y schermo inverte il movimento */
            if(Bulletg.y + deltay < 0 || Bulletg.y + deltay > MAXY-1) deltay = -deltay;
            
        }
        else{
            /* Movimento Y */
            Bulletg.y -= deltay;
            /* Se supero area Y schermo inverte il movimento */
            if(Bulletg.y - deltay < 0 || Bulletg.y - deltay > MAXY-1) deltay = -deltay;
            
        }
        
        
        /* Movimento X */
        Bulletg.x += deltax;

        /* Visualizzo il carattere dell'entità sulle nuove coordinate */
        stampasprite(Bulletg.y,Bulletg.x,Bulletg.c);
            

        /* Inserisco una pausa per rallentare il movimento */
        usleep(50000);
    }
}
/*
----------------------------------------------------------------------
 Funzione 'Bullet nemico'
---------------------------------------------------------------------- 
*/
void *bulletn(void *arg){
    int deltax=1;		/* Spostamento orizzontale */
    Bulletn.x = Alieni.x-1;  /* Coordinata X iniziale */
    Bulletn.y = Alieni.y+1;  /* Coordinata Y iniziale */
    Bulletn.c ='H';	/* Carattere identificativo */
    Bulletn.id =idbn; /* Numero dell elemento */
    
    while(!collision){
        /* Cancello il precedente carattere visualizzato */
        cancellasprite(Bulletn.y,Bulletn.x,Bulletn.c);

        /* Movimento X */
        Bulletn.x -= deltax;

        /* Visualizzo il carattere dell'entità sulle nuove coordinate */
        stampasprite(Bulletn.y,Bulletn.x,Bulletn.c);

        /* Inserisco una pausa per rallentare il movimento */
        usleep(100000);
    }
}