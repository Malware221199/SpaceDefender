#include "Grafica.h"

void stampasprite(int y,int x,char c,int n){
    if(c=='A'){
        int i;
        usleep(3000000);
        mvprintw(0,6,"N %d",n);
        for(i=0;i<3;i++)
            mvaddnstr(y+i,x,sprite_a[i],3);

    }


    else if(c=='G'){
        /* Visualizzo il giocatore*/
            int i;
            for(i=0;i<6;i++)
                mvaddnstr(y+i,x,sprite_g[i],6);

    }

}







void cancellasprite(int y,int x,char c,int n){
    int i,j;
        if(c=='A'){
            for(i=0;i<3;i++){
                for(j=0;j<3;j++){
                    
                    mvaddch(y+i,x+j,'o');
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
