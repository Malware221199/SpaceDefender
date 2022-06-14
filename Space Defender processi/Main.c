#include "Utility.h"

bool quit=false;
int ida,i;
int nnemici=2;
int difficolta = DELAYM;

/*
----------------------------------------------------------------------
 Funzione 'Main'
----------------------------------------------------------------------
*/
int main(){
    
    setlocale(LC_ALL, "");
    initscr();			/* Inizializza schermo di output */
    start_color();
    noecho();			/* Imposta modalità della tastiera */
    curs_set(0);		/* Nasconde il cursore */
    getmaxyx(stdscr, MAXY, MAXX);
    srand(time(NULL));
    clear();
    refresh();
    pipe(p);    			/* Creazione pipe */
    bkgd(COLOR_PAIR(1));
    init_pair(1,COLOR_RED,COLOR_BLACK);  /* Colore vespa */
    init_pair(2,COLOR_GREEN,COLOR_BLACK);   /* Colore contadino */
    init_pair(3,COLOR_MAGENTA,COLOR_BLACK);   /* Colore trappola */
    init_pair(4,COLOR_WHITE,COLOR_BLACK);   /* Colore trappola */
    attron(COLOR_PAIR(4));
    

    do{
        quit=menu(&nnemici,&difficolta);
        if (!quit){   /* Entro nella funzione Menu*/
            clear();
            refresh();
            pidG=fork();           
            /* Se il pid == 0 -> si tratta del processo 'Giocatore' */
            if(pidG==0) {

                /* ed eseguo quindi la relativa funzione di gestione */
                close(p[0]); /* chiusura del descrittore di lettura */
                giocatore(p[1]); /* invocazione funzione giocatore */  
            }

            for(ida=0;ida<nnemici;ida++){

                pidA = fork();/* Creo il primo processo figlio 'Alieni' */
            
           
                /* Se il pid == 0 -> si tratta del processo 'Generatore processi Alieni' */
                if(pidA==0) {
                    
                    /* ed eseguo quindi la relativa funzione di gestione */
                    close(p[0]); /* chiusura del descrittore di lettura */
                    A[ida].id=ida;
                    
                    alieni(p[1],A[ida],difficolta); /* invocazione funzione alieni */
                
                }
            }

            /* Sono ancora nel processo padre */
            close(p[1]); /* chiusura del descrittore di scrittura */
            area(p[0],nnemici);  /* invocazione funzione area di gioco */  
        
            /*Termino i processi*/
            kill(pidG,1);
            for(i=0;i<11;i++)   if(A[i].alive) kill(A[i].pid,1);
            /* Ripristino la modalità di funzionamento usuale */
            endwin();
        }
    }while(!quit);
    /* Ripristino la modalità di funzionamento usuale */
    endwin();

}



































