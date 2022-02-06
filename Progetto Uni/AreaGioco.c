#include "Utility.h"

/*
----------------------------------------------------------------------
 Funzione 'Area Gioco'
---------------------------------------------------------------------- 
*/

void area(int pipein,int nnemici){

    struct position giocatore, dato_letto;
    save alieni[11];
    save bulletg[94];
    save bulletn[95];

    int i=0, j=0, k=0, vite=3, collision=0, alienimorti=0;

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
                cancellasprite(alieni[dato_letto.id].y,alieni[dato_letto.id].x,dato_letto.c);


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
                    cancellasprite(alieni[dato_letto.id].y,alieni[dato_letto.id].x,dato_letto.c);
                    alieni[dato_letto.id].y=DEADYA;
                    alieni[dato_letto.id].x=DEADXA;
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
                cancellasprite(giocatore.y,giocatore.x,giocatore.c);

                /* Aggiorno le coordinate relative alla nuova posizione */
                giocatore=dato_letto;

                /* Visualizzo il carattere dell'entità sulle nuove coordinate */
                stampasprite(dato_letto.y,dato_letto.x,dato_letto.c);

            }

             /*
            ----------------------------------------------------------------------
            Gesione proiettili giocatore
            ---------------------------------------------------------------------- 
            */
            else if(dato_letto.c=='B'){

                /* Cancello il precedente carattere visualizzato */
                cancellasprite(bulletg[dato_letto.id].y,bulletg[dato_letto.id].x,dato_letto.c);

                /* Aggiorno le coordinate relative alla nuova posizione */
                bulletg[dato_letto.id].id=dato_letto.id;
                bulletg[dato_letto.id].y=dato_letto.y;
                bulletg[dato_letto.id].x=dato_letto.x;
                bulletg[dato_letto.id].pid=dato_letto.pid;

                /* Visualizzo il carattere dell'entità sulle nuove coordinate */
                stampasprite(dato_letto.y,dato_letto.x,dato_letto.c);
            
                
                /* Collisioni proiettili con MAXX*/
                if (bulletg[dato_letto.id].x>MAXX){
                    kill(bulletg[dato_letto.id].pid,1);
                    cancellasprite(bulletg[dato_letto.id].y,bulletg[dato_letto.id].x,'B');
                    bulletg[dato_letto.id].x=DEADXB;
                    bulletg[dato_letto.id].y=DEADYB;
                }
                /* Collisioni proiettili con alieni*/
                int exit=0;
                for(i=0;i<11;i++){
                    for(j=0;j<GSA;j++){
                        for(k=0;k<GSA;k++){
                            if(bulletg[dato_letto.id].x == (alieni[i].x)+k && bulletg[dato_letto.id].y == (alieni[i].y)+j){
                                kill(bulletg[dato_letto.id].pid,1);
                                kill(alieni[alieni[i].id].pid,1);
                                cancellasprite(alieni[i].y,alieni[i].x,'A');
                                bulletg[dato_letto.id].y=DEADYB;
                                bulletg[dato_letto.id].x=DEADXB;
                                alieni[i].y=DEADYA;
                                alieni[i].x=DEADXA;
                                if(exit==0){
                                    alienimorti++;
                                    exit=1;
                                }      
                            }
                        }
                    }
                }
            }
             /*
            ----------------------------------------------------------------------
            Gesione proiettili nemico
            ---------------------------------------------------------------------- 
            */
            else if(dato_letto.c=='H'){
                /*Cancello il precedente carattere visualizzato */
                cancellasprite(bulletn[dato_letto.id].y,bulletn[dato_letto.id].x,dato_letto.c);
                
                /*Aggiorno le coordinate relative alla nuova posizione */
                bulletn[dato_letto.id].id=dato_letto.id;
                bulletn[dato_letto.id].y=dato_letto.y;
                bulletn[dato_letto.id].x=dato_letto.x;
                bulletn[dato_letto.id].pid=dato_letto.pid;

                /* Visualizzo il carattere dell'entità sulle nuove coordinate */
                stampasprite(dato_letto.y,dato_letto.x,dato_letto.c);
            }


            /* Visualizzo le vite rimaste al giocatore */
            cancellasprite(0,1,'V');
            for(i=0;i<vite;i++) mvaddstr(0,1+i,"❥");
            

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

            if(alienimorti>=nnemici) {
                collision=1;
                clear();
                stampasprite(MAXY/2-2,MAXX/2-18,'W');
                refresh();
                usleep(4000000);
            }



    /* Il ciclo si ripete finchè le vite del giocatore terminano o gli alieni terminano */
    } while(!collision);

}	