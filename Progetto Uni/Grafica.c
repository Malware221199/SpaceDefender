#include "Grafica.h"

void stampasprite(int y,int x,char c){
    if(c=='A'){
        int i;
        for(i=0;i<3;i++)
            mvaddstr(y+i,x,sprite_a[i]);

    }


    else if(c=='G'){
        /* Visualizzo il giocatore*/
            int i;
            for(i=0;i<6;i++)
                mvaddstr(y+i,x,sprite_g[i]);

    }

}







void cancellasprite(int y,int x,char c){
    int i,j;
        if(c=='A'){
            for(i=0;i<3;i++){
                for(j+0;j<3;j++){
                    
                    mvaddch(y=i,x+j,' ');
                }
            }
        }

        else if(c=='G'){
            for(i=0;i<6;i++){
                for(j=0;j<6;j++){
                    mvaddch(y+i,x+j,' ');
                }
            }
        }

}
