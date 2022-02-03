#include "Grafica.h"

void stampasprite(int y,int x,char c,int n){//da trasformare in switch case
    int i;
    switch(c){
        case 'A':
            attron(COLOR_PAIR(1));
            for(i=0;i<3;i++)
                mvaddnstr(y+i,x,sprite_alieno[i],3);
            attroff(COLOR_PAIR(1));
    


        case 'G':/* Visualizzo il giocatore*/
            attron(COLOR_PAIR(2));
            for(i=0;i<6;i++)
                mvaddnstr(y+i,x,sprite_giocatore[i],6);
            attroff(COLOR_PAIR(2));

    

        case 'B':/* Visualizzo il proiettile*/
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
            
            mvprintw(y,x," ");
    

    }

}
