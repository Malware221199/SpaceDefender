#include "Grafica.h"

void stampasprite(int larghezza,int altezza,int entita){
    /*if(entita=='A'){
        int i;
        for(i=0;i<altezza;i++){
        mvaddstr(i,larghezza,sprite.a[i])
        }
    }

    else if(entita=='G'){

    }*/
    int i;
    i=0;

}






void cancellasprite(int larghezza,int altezza){
    int i,j;
    for(i=0;i<larghezza;i++){
        for(j=0;j<altezza;j++){
            mvaddch(j,i,' ');
        }
    }
}