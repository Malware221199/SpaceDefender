#include "Utility.h"

/*
----------------------------------------------------------------------
 Funzione 'Area Gioco'
---------------------------------------------------------------------- 
*/

void Area(int pipein){

    struct position alieni, giocatore, dato_letto;
    int i=0, vite=3, collision=0;

    /* Visualizzo le vite iniziali del Giocatore */
        mvprintw(0,1,"Vite %d",vite);

        do {
            /* Leggo dalla pipe */
        read(pipein,&dato_letto,sizeof(dato_letto));

            /* Alieni */
            if(dato_letto.c=='A') {

                /* Cancello il precedente carattere visualizzato */
                cancellasprite(alieni.y,alieni.x);

                /* Aggiorno le coordinate relative alla nuova posizione */
                alieni=dato_letto;

                /* Visualizzo il carattere dell'entità sulle nuove coordinate */
                stampasprite(dato_letto.y,dato_letto.x,dato_letto.c);
            }

            /* Giocatore */
            else if(dato_letto.c=='G'){
                /* Cancello il precedente sprite visualizzato */
                cancellasprite(giocatore.y,giocatore.x);

                /* Aggiorno le coordinate relative alla nuova posizione */
                giocatore=dato_letto;

                /* Visualizzo il carattere dell'entità sulle nuove coordinate */
                stampasprite(dato_letto.y,dato_letto.x,dato_letto.c);

            }
            
            /* Segnalo collisione e tipo*/
            if(giocatore.x == alieni.x && giocatore.y == alieni.y) vite--;

            /* Visualizzo le vite rimaste al contadino */
            mvprintw(0,1,"Vite %d",vite);

            /* Aggiorno lo schermo di output per visualizzare le modifiche */
            refresh();

            /* Esce quando terminano le vite del Giocatore */
            if(vite < 1) collision=1; 

    /* Il ciclo si ripete finchè le vite del contadino terminano */
    } while(!collision);

}	