#include "Grafica.h"

void stampasprite(int y,int x,char c){
    if(c=='A'){
        int i;
        for(i=0;i<3;i++)
            mvaddstr(y+i,x,sprite_a[i]);

    }


    else if(c=='G'){
        /* Visualizzo il giocatore*/
            mvprintw(y,x,"Giocatore");

    }

}







void cancellasprite(int y,int x,char c){
    int i,j;
        if(c=='A'){
            for(i=0;i<y+3;i++){
                for(j=0;j<x+3;j++){
                    
                    mvaddch(y+3,x+3,'c');
                }
            }
        }

        else if(c=='G'){
            for(i=0;i<y+6;i++){
                for(j=0;j<x+6;j++){
                    mvaddch(y+6,x+6,'c');
                }
            }
        }

}
