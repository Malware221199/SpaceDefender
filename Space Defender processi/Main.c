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
    pid_t pidA[11],pidG;

    setlocale(LC_ALL, "");
    initscr();			/* Inizializza schermo di output */
    start_color();
    noecho();			/* Imposta modalità della tastiera */
    curs_set(0);		/* Nasconde il cursore */
    srand(time(NULL));
    clear();
    refresh();
    
    bkgd(COLOR_PAIR(1));
    init_pair(1,COLOR_RED,COLOR_BLACK);  /* Colore vespa */
    init_pair(2,COLOR_GREEN,COLOR_BLACK);   /* Colore contadino */
    init_pair(3,COLOR_MAGENTA,COLOR_BLACK);   /* Colore trappola */
    init_pair(4,COLOR_WHITE,COLOR_BLACK);   /* Colore trappola */
    attron(COLOR_PAIR(4));
    do{
        pipe(p);    			/* Creazione pipe */
        quit=menu(&nnemici,&difficolta);
        if (!quit){   /* Entro nella funzione Menu*/
            clear();
            refresh();
            pidG=fork();           
            /* Se il pid == 0 -> si tratta del processo 'Giocatore' */
            if(pidG==0) {
                
                //if(x>=1) while (1){printf("WOOW");};
                
                /* ed eseguo quindi la relativa funzione di gestione */
                close(p[0]); /* chiusura del descrittore di lettura */
                giocatore(p[1]); /* invocazione funzione giocatore */  
            }

            for(ida=0;ida<nnemici;ida++){

                pidA[ida] = fork();/* Creo il primo processo figlio 'Alieni' */
            
           
                /* Se il pid == 0 -> si tratta del processo 'Generatore processi Alieni' */
                if(pidA[ida]==0) {
                    
                    /* ed eseguo quindi la relativa funzione di gestione */
                    save new_alieno[11];

                    close(p[0]); /* chiusura del descrittore di lettura */
                    new_alieno[ida].id=ida;
                    new_alieno[ida].pid= getpid();
                    if(ida==0||ida==1) new_alieno[ida].x= MAXX-(GSA+DA);
                    else if(ida==2||ida==3) new_alieno[ida].x= MAXX-(GSA+DA)*2;
                    else if(ida==4||ida==5) new_alieno[ida].x= MAXX-(GSA+DA)*3;
                    else if(ida==6||ida==7) new_alieno[ida].x= MAXX-(GSA+DA)*4;
                    else if(ida==8||ida==9) new_alieno[ida].x= MAXX-(GSA+DA)*5;
                    if(ida%2==0) new_alieno[ida].y=(MAXY/4);
                    else if (ida%2==1) new_alieno[ida].y=MAXY-(MAXY/4)-3;
                    new_alieno[ida].c ='A';	/* Carattere identificativo */
                    new_alieno[ida].alive=true;
                    new_alieno[ida].liv=1;
                    
                    alieni(p[1],new_alieno[ida],difficolta); /* invocazione funzione alieni */
                
                }
            }

            /* Sono ancora nel processo padre */
            close(p[1]); /* chiusura del descrittore di scrittura */
            area(p[0],nnemici);  /* invocazione funzione area di gioco */  
        
            /*Termino i processi*/
            kill(pidG,1);
            for(i=0;i<nnemici;i++) kill(pidA[i],1);
        }
    }while(!quit);
    /* Ripristino la modalità di funzionamento usuale */
    endwin();

}


































