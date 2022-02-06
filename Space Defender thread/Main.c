#include "Utility.h"



/*
----------------------------------------------------------------------
 Funzione 'Main'
----------------------------------------------------------------------
*/


int main(){
    pthread_t talieni;
    pthread_t tgiocatore;
    pthread_t tbulletg;
    pthread_t tbulletn;
    setlocale(LC_ALL, "");
    initscr();			/* Inizializza schermo di output */
    start_color();
    noecho();			/* Imposta modalità della tastiera */
    curs_set(0);		/* Nasconde il cursore */
    getmaxyx(stdscr, MAXY, MAXX);
    srand(time(NULL));
    int ida;
    int nnemici=2;
    int difficolta = DELAYM;
    while (1){
    clear();
    refresh();
    bkgd(COLOR_PAIR(1));
    init_pair(1,COLOR_RED,COLOR_BLACK);  /* Colore vespa */
    init_pair(2,COLOR_GREEN,COLOR_BLACK);   /* Colore contadino */
    init_pair(3,COLOR_MAGENTA,COLOR_BLACK);   /* Colore trappola */
    init_pair(4,COLOR_WHITE,COLOR_BLACK);   /* Colore trappola */
    attron(COLOR_PAIR(4));
        
    /* Inizializzo mutex */
    pthread_mutex_init(&mtx, NULL); 

        

    if ( menu(&nnemici,&difficolta) == 0){   /* Entro nella funzione Menu*/
        clear();
        refresh();
        return 0;        /*Esce dal programma se nella funzione 'Menu' si seleziona 'Esci'*/
    }
    clear();
    refresh();
        
    /* Creo il thread alieni */
    if(pthread_create(&talieni, NULL, alieni, NULL)){
        endwin();
        exit;
    }

     /* Creo il thread giocatore */
    if(pthread_create(&tcontadino, NULL, giocatore, NULL)){
        endwin();
        exit;
    }

     /* Creo il thread bullet giocatore */
    if(pthread_create(&tbulletg, NULL, bulletg, NULL)){
        endwin();
        exit;
    }

     /* Creo il thread bullet nemici */
    if(pthread_create(&tbulletn, NULL, bulletn, NULL)){
        endwin();
        exit;
    }

	/* Avvio la funzione Area */
    area();	

    /* Attendo la terminazione dei thread */
    pthread_join (talieni, NULL);		
	pthread_join (tgiocatore, NULL);
    pthread_join (tbulletg, NULL);
    pthread_join (tbulletn, NULL);		

	/* Elimino mutex */
    pthread_mutex_destroy (&mtx);		

    /* Ripristino la modalità di funzionamento usuale */
    endwin();
    }
}



































