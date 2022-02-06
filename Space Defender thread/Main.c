#include "Utility.h"

int nnemici=2,i;
    int difficolta=DELAYM;

/*
----------------------------------------------------------------------
 Funzione 'Main'
----------------------------------------------------------------------
*/

int main(){
    pthread_t talieni;
    pthread_t tgiocatore;

    setlocale(LC_ALL, "");
    initscr();			/* Inizializza schermo di output */
    start_color();
    noecho();			/* Imposta modalità della tastiera */
    curs_set(0);		/* Nasconde il cursore */
    getmaxyx(stdscr, MAXY, MAXX);
    srand(time(NULL));
    //while (1){
    clear();
    refresh();
    bkgd(COLOR_PAIR(1));
    init_pair(1,COLOR_RED,COLOR_BLACK);  /* Colore vespa */
    init_pair(2,COLOR_GREEN,COLOR_BLACK);   /* Colore contadino */
    init_pair(3,COLOR_MAGENTA,COLOR_BLACK);   /* Colore trappola */
    init_pair(4,COLOR_WHITE,COLOR_BLACK);   /* Colore trappola */
    attron(COLOR_PAIR(4));
        
    /* Inizializzo mutex */
    pthread_mutex_init(&malieni, NULL); 
    pthread_mutex_init(&mgiocatore, NULL); 
    pthread_mutex_init(&mbulletg, NULL); 
    pthread_mutex_init(&mbulletn, NULL); 
    //pthread_mutex_init(&mstampa, NULL); 
    

        

    if ( menu(&nnemici,&difficolta) == 0){   /* Entro nella funzione Menu*/
        clear();
        refresh();
        return 0;        /*Esce dal programma se nella funzione 'Menu' si seleziona 'Esci'*/
    }
    clear();
    refresh();
        
    /* Creo il thread alieni */
    pthread_mutex_lock(&malieni);
    for(i=0;i<nnemici;i++){
        if(pthread_create(&talieni, NULL, alieni, NULL)){
            endwin();
            exit;
        }
    }
    pthread_mutex_unlock(&malieni);
     /* Creo il thread giocatore */
    if(pthread_create(&tgiocatore, NULL, giocatore, NULL)){
        endwin();
        exit;
    }

	/* Avvio la funzione Area */
    area();	

    /* Attendo la terminazione dei thread */
    pthread_join (talieni, NULL);		
	pthread_join (tgiocatore, NULL);	

	/* Elimino mutex */
    pthread_mutex_destroy (&malieni);
    pthread_mutex_destroy (&mgiocatore);
    pthread_mutex_destroy (&mbulletg); 
    pthread_mutex_destroy (&mbulletn); 				

    /* Ripristino la modalità di funzionamento usuale */
    endwin();
    //}
}



































