#include "Grafica.h"

void stampasprite(int y,int x,char c,int n){
    int i;
    if(c=='A'){
        attron(COLOR_PAIR(1));
        for(i=0;i<3;i++)
            mvaddnstr(y+i,x,sprite_a[i],3);
        attroff(COLOR_PAIR(1));
    }


    else if(c=='G'){
        /* Visualizzo il giocatore*/
            attron(COLOR_PAIR(2));
            for(i=0;i<6;i++)
            mvaddnstr(y+i,x,sprite_g[i],6);
            attroff(COLOR_PAIR(2));

    }

    else if(c=='B'){
        /* Visualizzo il giocatore*/
            attron(COLOR_PAIR(4));
            mvprintw(y,x,"O");
            attroff(COLOR_PAIR(4));

    }



}







void cancellasprite(int y,int x,char c,int n){
    int i,j;
        if(c=='A'){
            for(i=0;i<3;i++){
                for(j=0;j<3;j++){
                    
                    mvaddch(y+i,x+j,' ');
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

        else if(c=='B'){
            
            mvprintw(y,x,".");
    

    }

}
