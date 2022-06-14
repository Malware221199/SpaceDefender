#include "Utility.h"

/*
----------------------------------------------------------------------
 Funzione 'Main'
----------------------------------------------------------------------
*/
int main(){

    int p[2];				/* Descrittori pipe */ 
    bool quit=false;
    int ida,i;
    int nnemici=2;
    int difficolta = DELAYM;
    pid_t pidA,pidG;

    setlocale(LC_ALL, "");
    initscr();			/* Inizializza schermo di output */
    start_color();
    noecho();			/* Imposta modalità della tastiera */
    curs_set(0);		/* Nasconde il cursore */
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
    
    int x=0;
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

            //for(ida=0;ida<nnemici;ida++){

                pidA = fork();/* Creo il primo processo figlio 'Alieni' */
                

                /* Se il pid == 0 -> si tratta del processo 'Generatore processi Alieni' */
                if(pidA==0) {
                    
                    /* ed eseguo quindi la relativa funzione di gestione */
                    save new_alieno;
                    
                    close(p[0]); /* chiusura del descrittore di lettura */
                    if(x>=1) while(1) printf("ciao");
                    new_alieno.id=1;//ida;
                    new_alieno.pid= getpid();
                    new_alieno.x=70; //MAXX-(GSA+DA);
                    new_alieno.y=12;//(MAXY/4);
                    new_alieno.c ='A';	/* Carattere identificativo */
                    new_alieno.alive=true;
                    new_alieno.liv=1;
                    
                    alieni(p[1],new_alieno,difficolta); /* invocazione funzione alieni */
                
                }
            //}

            /* Sono ancora nel processo padre */
            close(p[1]); /* chiusura del descrittore di scrittura */
            x++;
            area(p[0],nnemici, x);  /* invocazione funzione area di gioco */  
        
            /*Termino i processi*/
            kill(pidG,1);
            kill(pidA,1);
        }
    }while(!quit);
    /* Ripristino la modalità di funzionamento usuale */
    endwin();

}



































