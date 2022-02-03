#include "Utility.h"

/*
----------------------------------------------------------------------
 Funzione 'Area Gioco'
---------------------------------------------------------------------- 
*/

void area(int pipein){

    struct position giocatore, dato_letto;
    save alieni[11];
    save bullet[99];
    int i=0, vite=3, collision=0;

    /* Visualizzo le vite iniziali del Giocatore */
        mvprintw(0,1,"Vite %d",vite);

        do {
            /* Leggo dalla pipe */
        read(pipein,&dato_letto,sizeof(dato_letto));

            /* Alieni */
            if(dato_letto.c=='A') {

                /* Cancello il precedente carattere visualizzato */
                cancellasprite(alieni[dato_letto.id].y,alieni[dato_letto.id].x,dato_letto.c,alieni[dato_letto.id].id);

                /* Aggiorno le coordinate relative alla nuova posizione */
                alieni[dato_letto.id].id=dato_letto.id;
                alieni[dato_letto.id].y=dato_letto.y;
                alieni[dato_letto.id].x=dato_letto.x;
                alieni[dato_letto.id].pid=dato_letto.pid;

                /* Visualizzo il carattere dell'entità sulle nuove coordinate */
                stampasprite(dato_letto.y,dato_letto.x,dato_letto.c,dato_letto.id);
            }

            /* Giocatore */
            else if(dato_letto.c=='G'){
                /* Cancello il precedente sprite visualizzato */
                cancellasprite(giocatore.y,giocatore.x,giocatore.c,giocatore.id);

                /* Aggiorno le coordinate relative alla nuova posizione */
                giocatore=dato_letto;

                /* Visualizzo il carattere dell'entità sulle nuove coordinate */
                stampasprite(dato_letto.y,dato_letto.x,dato_letto.c,dato_letto.id);

            }

            /* Bullet */
            else if(dato_letto.c=='B'){

                /* Cancello il precedente carattere visualizzato */
                cancellasprite(bullet[dato_letto.id].y,bullet[dato_letto.id].x,dato_letto.c,bullet[dato_letto.id].id);

                /* Aggiorno le coordinate relative alla nuova posizione */
                bullet[dato_letto.id].id=dato_letto.id;
                bullet[dato_letto.id].y=dato_letto.y;
                bullet[dato_letto.id].x=dato_letto.x;
                bullet[dato_letto.id].pid=dato_letto.pid;

                /* Visualizzo il carattere dell'entità sulle nuove coordinate */
                stampasprite(dato_letto.y,dato_letto.x,dato_letto.c,dato_letto.id);
            }

            /*
            ----------------------------------------------------------------------
            Collisioni
            ---------------------------------------------------------------------- 
            */  

            
            /* Segnalo collisione e tipo*/
            int i,j,k;
            for(i=0;i<11;i++){
                for(j=0;j<3;j++){
                    for(k=0;k<3;k++){
                        if(bullet[dato_letto.id].x == (alieni[i].x)+k && bullet[dato_letto.id].y == (alieni[i].y)+j){
                            kill(bullet[dato_letto.id].pid,1);
                            kill(alieni[alieni[i].id].pid,1);
                            

                             
                        }

                    }
                }
            }
            

            /* Visualizzo le vite rimaste al contadino */
            mvprintw(0,1,"Vite %d",vite);

            /* Aggiorno lo schermo di output per visualizzare le modifiche */
            refresh();

            /* Esce quando terminano le vite del Giocatore */
            if(vite < 1) collision=1; 

    /* Il ciclo si ripete finchè le vite del contadino terminano */
    } while(!collision);

}	