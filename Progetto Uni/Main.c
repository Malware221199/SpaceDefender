#include "Utility.h"

/*
----------------------------------------------------------------------
 Funzione 'Main'
----------------------------------------------------------------------
*/
int main(){
    while (1){
            				/* Descrittori pipe */
        int pidGA;   		/* Pid processo figlio 'Alieni' */
        int pidG;	      /* Pid processo figlio 'Giocatore' */

        initscr();			/* Inizializza schermo di output */
        noecho();				/* Imposta modalità della tastiera */
        curs_set(0);		/* Nasconde il cursore */
        pipe(p);    			/* Creazione pipe */
        int nnemici = 2;
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
        /* Creo il primo processo figlio 'Alieni' */
        pidGA = fork();
        /* Se il pid == 0 -> si tratta del processo 'Generatore processi Alieni' */
        if(pidGA==0) {
            
            /* ed eseguo quindi la relativa funzione di gestione */
            close(p[0]); /* chiusura del descrittore di lettura */
            
            Gen_alieni(p[1],nnemici); /* invocazione funzione alieni */
                
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
        /* Termino i processi Alieni e Giocatore */
        kill(pidGA,1);	
        kill(pidG,1);	

        /* Ripristino la modalità di funzionamento usuale */
        endwin();	    	

        /* Termino il gioco*/
        printf("\n\n\nGAME OVER\n\n\n");
    }
}



































