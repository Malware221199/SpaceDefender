#include "Utility.h"

/*
----------------------------------------------------------------------
 Funzione 'Main'
----------------------------------------------------------------------
*/
int main(){
    while (1){
        initscr();			/* Inizializza schermo di output */
        start_color();
        noecho();			/* Imposta modalità della tastiera */
        curs_set(0);		/* Nasconde il cursore */
        getmaxyx(stdscr, MAXY, MAXX);
        pipe(p);    			/* Creazione pipe */
        clear();
        refresh();
        bkgd(COLOR_PAIR(1));
        init_pair(1,COLOR_RED,COLOR_BLACK);  /* Colore vespa */
        init_pair(2,COLOR_GREEN,COLOR_BLACK);   /* Colore contadino */
        init_pair(3,COLOR_RED,COLOR_BLACK);   /* Colore trappola */
        init_pair(4,COLOR_WHITE,COLOR_BLACK);   /* Colore trappola */
        attron(COLOR_PAIR(4));
        int ida;
        int nnemici=5;
        int difficolta = DELAYM;
        if ( menu(&nnemici,&difficolta) == 0){
            clear();
            refresh();
            return 0;
            }
        clear();
        refresh();
        for(ida=0;ida<nnemici;ida++){
            /* Creo il primo processo figlio 'Alieni' */
            pidA = fork();
            if(!pidA)
                break; 
        }
        /* Se il pid == 0 -> si tratta del processo 'Generatore processi Alieni' */
        if(pidA==0) {
            
            /* ed eseguo quindi la relativa funzione di gestione */
            close(p[0]); /* chiusura del descrittore di lettura */
            
            alieni(p[1],ida); /* invocazione funzione alieni */

                
        }
        else {		
            /* Altrimenti sono ancora nel processo padre e creo il processo 'Giocatore' */
            pidG=fork();
                            
            /* Se il pid == 0 -> si tratta del processo 'Giocatore' */
            if(pidG==0) {

                /* ed eseguo quindi la relativa funzione di gestione */
                close(p[0]); /* chiusura del descrittore di lettura */
                giocatore(p[1]); /* invocazione funzione giocatore */  
            }
            else {
                /* Sono ancora nel processo padre */
                close(p[1]); /* chiusura del descrittore di scrittura */
                area(p[0]);  /* invocazione funzione area di gioco */  
            }
        }
        /* Termino i processi Alieni e Giocatore */
        kill(pidA,1);	
        kill(pidG,1);	

        /* Ripristino la modalità di funzionamento usuale */
        endwin();
    }
}



































