#include "Grafica.h"

void stampasprite(int larghezza,int altezza,char entita){
    if(entita=='A'){
       mvprintw(larghezza,altezza,"#");
    }

    else if(entita=='G'){
        /* Visualizzo il giocatore*/
            int i;
            i++;
            mvprintw(larghezza,altezza,"Giocatore %d",i);

    }

}







void cancellasprite(int larghezza,int altezza,char entita){
    int i,j;
        if(entita=='A'){
            for(i=0;i<larghezza+3;i++){
                for(j=0;j<altezza+3;j++){
                    mvaddch(altezza+3,altezza+3,'c');
                }
            }
        }

        else if(entita=='G'){
            for(i=0;i<larghezza+6;i++){
                for(j=0;j<altezza+6;j++){
                    mvaddch(altezza+6,altezza+6,'c');
                }
            }
        }

}
