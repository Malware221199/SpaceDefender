#include "Utility.h"

/*
----------------------------------------------------------------------
 Funzione 'Main'
----------------------------------------------------------------------
*/
int main(){
    while (1){
        int p[2];				/* Descrittori pipe */
        int pidA;   		/* Pid processo figlio 'Alieni' */
        int pidG;	      /* Pid processo figlio 'Giocatore' */

        initscr();			/* Inizializza schermo di output */
        noecho();				/* Imposta modalità della tastiera */
        curs_set(0);		/* Nasconde il cursore */
        pipe(p);				/* Creazione pipe */
        int nnemici = 5;
        int vproiettili = DELAYM;
        clear();
        refresh();
        if ( Menu(&nnemici,&vproiettili) == 0){
            clear();
            refresh();
            return 0;
            }
        clear();
        refresh();
        int i;
        //for(i=0;i<2;i++){
        /* Creo il primo processo figlio 'Alieni' */
        pidA = fork();
        //}
        /* Se il pid == 0 -> si tratta del processo 'Alieni' */
        if(pidA==0) {
            
            /* ed eseguo quindi la relativa funzione di gestione */
            close(p[0]); /* chiusura del descrittore di lettura */
            
            
                Alieni(p[1],i); /* invocazione funzione alieni */
                mvprintw(1,1,"contattore %d",i);
            
        }
        else {		
            /* Altrimenti sono ancora nel processo padre e creo il processo 'Giocatore' */
            pidG=fork();
                            
            /* Se il pid == 0 -> si tratta del processo 'Giocatore' */
            if(pidG==0) {

                /* ed eseguo quindi la relativa funzione di gestione */
                close(p[0]); /* chiusura del descrittore di lettura */
                Giocatore(p[1]); /* invocazione funzione contadino */  
            }
            else {
                /* Sono ancora nel processo padre */
                close(p[1]); /* chiusura del descrittore di scrittura */
                Area(p[0]);  /* invocazione funzione area di gioco */  
            }
        }
        /* Termino i processi Vespa e Contadino */
        kill(pidA,1);	
        kill(pidG,1);	

        /* Ripristino la modalità di funzionamento usuale */
        endwin();	    	

        /* Termino il gioco*/
        printf("\n\n\nGAME OVER\n\n\n");
    }
}



































