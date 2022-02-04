#include "Grafica.h"

void stampasprite(int y,int x,char c,int n){//da trasformare in switch case
    int i;
    switch(c){
        case 'A':
            attron(COLOR_PAIR(1));
            for(i=0;i<3;i++)
                mvaddstr(y+i,x,sprite_alieno[i]);
            attroff(COLOR_PAIR(1));
        break;
    


        case 'G':/* Visualizzo il giocatore*/
            attron(COLOR_PAIR(2));
            for(i=0;i<6;i++)
                mvaddstr(y+i,x,sprite_giocatore[i]);
            attroff(COLOR_PAIR(2));
        break;

    

        case 'B':/* Visualizzo il proiettile*/
            attron(COLOR_PAIR(4));
            mvprintw(y,x,"O");
            attroff(COLOR_PAIR(4));
        break;

        case 'S':/* Visualizzo il giocatore*/
            switch (n){
                case 26:
                    for(i=0;i<2;i++)
                    mvaddstr(y+i,x,sprite_gioca[i]);
                break;
                case 37:
                    for(i=0;i<4;i++)
                    mvaddstr(y+i,x,sprite_opzioni[i]);
                break;
                case 21:
                    for(i=0;i<4;i++)
                    mvaddstr(y+i,x,sprite_esci[i]);
                break;
                case 76:
                    for(i=0;i<7;i++)
                    mvaddstr(y+i,x,sprite_space[i]);
                break;
                case 5:
                    for(i=0;i<7;i++)
                    mvaddstr(y+i,x,sprite_defender[i]);
                break;
                case 2:
                    for(i=0;i<5;i++)
                    mvaddstr(y+i,x,sprite_gameover[i]);
                break;

            }
        break;

        default:
        break;

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

        else if(c=='B'){
            
            mvprintw(y,x," ");
    

    }

}
