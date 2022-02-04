#include "Utility.h"

/*
----------------------------------------------------------------------
 Funzione 'Area Gioco'
---------------------------------------------------------------------- 
*/

void area(int pipein,int nnemici){

    struct position giocatore, dato_letto;
    save alieni[11];
    save bullet[99];
    int i=0, j=0, k=0, vite=3, collision=0, alienimorti=0;

    /* Visualizzo le vite iniziali del Giocatore */
        mvprintw(0,1,"Vite %d",vite);

        do {
            /* Leggo dalla pipe */
            read(pipein,&dato_letto,sizeof(dato_letto));

            /*
            ----------------------------------------------------------------------
            Gesione Alieni
            ---------------------------------------------------------------------- 
            */
            if(dato_letto.c=='A') {

                /* Cancello il precedente carattere visualizzato */
                cancellasprite(alieni[dato_letto.id].y,alieni[dato_letto.id].x,dato_letto.c,alieni[dato_letto.id].id);


                /* Aggiorno le coordinate relative alla nuova posizione */
                alieni[dato_letto.id].id=dato_letto.id;
                alieni[dato_letto.id].y=dato_letto.y;
                alieni[dato_letto.id].x=dato_letto.x;
                alieni[dato_letto.id].pid=dato_letto.pid;

                /* Visualizzo il carattere dell'entità sulle nuove coordinate */
                stampasprite(dato_letto.y,dato_letto.x,dato_letto.c);

                /* Collisioni Alieni*/
                if(alieni[dato_letto.id].x<10){
                    vite--;
                    kill(alieni[dato_letto.id].pid,1);
                    cancellasprite(alieni[dato_letto.id].y,alieni[dato_letto.id].x,dato_letto.c,alieni[dato_letto.id].id);
                    alieni[dato_letto.id].y=DEADY;
                    alieni[dato_letto.id].x=DEADX;
                    alienimorti++;
                    
                    
                }
            }

             /*
            ----------------------------------------------------------------------
            Gesione Giocatore
            ---------------------------------------------------------------------- 
            */
            else if(dato_letto.c=='G'){
                /* Cancello il precedente sprite visualizzato */
                cancellasprite(giocatore.y,giocatore.x,giocatore.c,giocatore.id);

                /* Aggiorno le coordinate relative alla nuova posizione */
                giocatore=dato_letto;

                /* Visualizzo il carattere dell'entità sulle nuove coordinate */
                stampasprite(dato_letto.y,dato_letto.x,dato_letto.c);

            }

             /*
            ----------------------------------------------------------------------
            Gesione Proiettili
            ---------------------------------------------------------------------- 
            */
            else if(dato_letto.c=='B'){

                /* Cancello il precedente carattere visualizzato */
                cancellasprite(bullet[dato_letto.id].y,bullet[dato_letto.id].x,dato_letto.c,bullet[dato_letto.id].id);

                /* Aggiorno le coordinate relative alla nuova posizione */
                bullet[dato_letto.id].id=dato_letto.id;
                bullet[dato_letto.id].y=dato_letto.y;
                bullet[dato_letto.id].x=dato_letto.x;
                bullet[dato_letto.id].pid=dato_letto.pid;

                /* Visualizzo il carattere dell'entità sulle nuove coordinate */
                stampasprite(dato_letto.y,dato_letto.x,dato_letto.c);
            
                
                /* Collisioni proiettili con MAXX*/
                if (bullet[dato_letto.id].x>MAXX){
                    kill(bullet[dato_letto.id].pid,1);
                    cancellasprite(bullet[dato_letto.id].y,bullet[dato_letto.id].x,'A',bullet[dato_letto.id].id);
                    bullet[dato_letto.id].x=DEADX;
                    bullet[dato_letto.id].y=DEADY;
                }
                /* Collisioni proiettili con alieni*/
                for(i=0;i<11;i++){
                    for(j=0;j<3;j++){
                        for(k=0;k<3;k++){
                            if(bullet[dato_letto.id].x == (alieni[i].x)+k && bullet[dato_letto.id].y == (alieni[i].y)+j){
                                kill(bullet[dato_letto.id].pid,1);
                                kill(alieni[alieni[i].id].pid,1);
                                cancellasprite(alieni[i].y,alieni[i].x,'A',alieni[i].id);
                                bullet[dato_letto.id].y=DEADY;
                                bullet[dato_letto.id].x=DEADX;
                                alieni[i].y=DEADY;
                                alieni[i].x=DEADX;
                                alienimorti++;
                            }
                        }
                    }
                }
            }
            
            /* Visualizzo le vite rimaste al contadino */
            mvprintw(0,1,"Vite %d",vite);

            /* Aggiorno lo schermo di output per visualizzare le modifiche */
            refresh();

            /* Esce quando terminano le vite del Giocatore */
            if(vite < 1) {
                collision=1;
                clear();
                stampasprite(MAXY/2-2,MAXX/2-25,'O');
                refresh();
                usleep(4000000);
            }

            if(alienimorti==nnemici) {
                collision=1;
                clear();
                stampasprite(MAXY/2-2,MAXX/2-25,'W');
                refresh();
                usleep(4000000);
            }



    /* Il ciclo si ripete finchè le vite del contadino terminano */
    } while(!collision);

}	