#include "Grafica.h"

void stampasprite(int larghezza,int altezza,char entita){
    if(entita=='A'){
        //int i;
        //for(i=0;i<altezza;i++){
        //mvaddstr(i,larghezza,sprite.a[i])
        //}
        /* Visualizzo l'alieno*/
        mvprintw(MAXY/2,MAXX/2,"#");
    }

    else if(entita=='G'){
        /* Visualizzo il giocatore*/
            mvprintw(MAXY/2,MAXX/2,"G");

    }

}







void cancellasprite(int larghezza,int altezza){
    int i,j;
    for(i=0;i<larghezza;i++){
        for(j=0;j<altezza;j++){
            mvaddch(j,i,' ');
        }
    }
}
