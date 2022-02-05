#include "Grafica.h"

void stampasprite(int y,int x,char c){
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

        case 'B':/* Visualizzo il proiettile alleato*/
            attron(COLOR_PAIR(4));
            mvprintw(y,x,"O");
            attroff(COLOR_PAIR(4));
        break;

        case 'U':/* stampo sprite 'gioca' */
            for(i=0;i<2;i++)
                mvaddstr(y+i,x,sprite_gioca[i]);
        break;

        case 'Z':/* stampo sprite 'opzioni' */
            for(i=0;i<2;i++)
                mvaddstr(y+i,x,sprite_opzioni[i]);
        break;

        case 'E':/* stampo sprite 'esci' */
            for(i=0;i<2;i++)
                mvaddstr(y+i,x,sprite_esci[i]);
        break;

        case 'I':/* stampo sprite 'indietro' */
            for(i=0;i<2;i++)
                mvaddstr(y+i,x,sprite_indietro[i]);
        break;

        case 'N':/* stampo sprite 'nemici' */
            for(i=0;i<2;i++)
                mvaddstr(y+i,x,sprite_nemici[i]);
        break;

        case 'P':/* stampo sprite 'difficolta' */
            for(i=0;i<2;i++)
                mvaddstr(y+i,x,sprite_difficolta[i]);
        break;

        case 'S':/* stampo sprite 'space' */
            attron(COLOR_PAIR(1));
            for(i=0;i<7;i++)
                mvaddstr(y+i,x,sprite_space[i]);
            attroff(COLOR_PAIR(1));
        break;

        case 'D':/* stampo sprite 'defender' */
            attron(COLOR_PAIR(1));
            for(i=0;i<7;i++)
                mvaddstr(y+i,x,sprite_defender[i]);
            attroff(COLOR_PAIR(1));
        break;

        case 'O':/* stampo sprite 'game over' */
            attron(COLOR_PAIR(1));
            for(i=0;i<5;i++)
                mvaddstr(y+i,x,sprite_gameover[i]);
            attroff(COLOR_PAIR(1));
        break;

        case 'W':/* stampo sprite 'you win' */
            attron(COLOR_PAIR(2));
            for(i=0;i<5;i++)
                mvaddstr(y+i,x,sprite_youwin[i]);
            attroff(COLOR_PAIR(2));
        break;

        case 'Q':/* stampo sprite 'due' */
            attron(COLOR_PAIR(1));
            for(i=0;i<6;i++)
                mvaddstr(y+i,x,sprite_due[i]);
            attroff(COLOR_PAIR(1));
        break;

        case 'X':/* stampo sprite 'quattro' */
            attron(COLOR_PAIR(1));
            for(i=0;i<6;i++)
                mvaddstr(y+i,x,sprite_quattro[i]);
            attroff(COLOR_PAIR(1));
        break;

        case 'V':/* stampo sprite 'sei' */
            attron(COLOR_PAIR(1));
            for(i=0;i<6;i++)
                mvaddstr(y+i,x,sprite_sei[i]);
            attroff(COLOR_PAIR(1));
        break;

        case 'R':/* stampo sprite 'otto' */
            attron(COLOR_PAIR(1));
            for(i=0;i<6;i++)
                mvaddstr(y+i,x,sprite_otto[i]);
            attroff(COLOR_PAIR(1));
        break;

        case 'Y':/* stampo sprite 'dieci' */
            attron(COLOR_PAIR(1));
            for(i=0;i<6;i++)
                mvaddstr(y+i,x,sprite_dieci[i]);
            attroff(COLOR_PAIR(1));
        break;



        default:
        break;

    }
}







void cancellasprite(int y,int x,char c){
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
                for(j=0;j<7;j++){
                    mvaddch(y+i,x+j,' ');
                }
            }
        }

        else if(c=='B'){
            
            mvprintw(y,x," ");
        }

        else if(c=='V'){
            
            mvprintw(y,x," ");
        }


}
