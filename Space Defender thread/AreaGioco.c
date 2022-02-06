#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>
#include <pthread.h>

/*
----------------------------------------------------------------------
 Funzione 'Area Gioco'
---------------------------------------------------------------------- 
*/

void area(void){

    int i=0, j=0, k=0, vite=3, alienimorti=0;

        do {
            /* Collisioni Alieni*/
            if(Alieni.x<10){
                vite--;
                cancellasprite(Alieni.y,Alieni.x,Alieni.c);
                Alieni.y=DEADYA;
                Alieni.x=DEADXA;
                alienimorti++;
            }
                
            /* Collisioni proiettili con MAXX*/
            if (Bulletg.x>MAXX){
                cancellasprite(Bulletg.y,Bulletg.x,Bulletg.c);
                Bulletg.x=DEADXB;
                Bulletg.y=DEADYB;
            }
            /* Collisioni proiettili con alieni*/
            int exit=0;
            
                for(j=0;j<GSA;j++){
                    for(k=0;k<GSA;k++){
                        if(Bulletg.x == (Alieni.x)+k && Bulletg.y == (Alieni.y)+j){
                            cancellasprite(Alieni.y,Alieni.x,Alieni.c);
                            Bulletg.y=DEADYB;
                            Bulletg.x=DEADXB;
                            Alieni.y=DEADYA;
                            Alieni.x=DEADXA;
                            if(exit==0){
                                alienimorti++;
                                exit=1;
                            }      
                        }
                    }
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