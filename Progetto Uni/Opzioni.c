#include "Utility.h"

void Opzioni(int *nnemici,int *vproiettili){
    int Opzioni[3] = {0,1,2};  /*stringa opzioni */
  char scelta;       /* variabile scelta */
  int altezza=0;    /* altezza cursore */                          
  bool esci;
  while(esci==false){
    int i;
    for(i=0;i<3;i++){
      if(i==0){
        if(i == altezza){
        attron(A_REVERSE);
        mvprintw(i+MAXY/2,MAXX/2,"Indietro");
        attroff(A_REVERSE);
        }
        else{
        mvprintw(i+MAXY/2,MAXX/2,"Indietro");
        }
      }

      if(i==1){
        if(i == altezza){
        attron(A_REVERSE);
        mvprintw(i+MAXY/2,MAXX/2,"Nemicio");
        attroff(A_REVERSE);
        }
        else{
        mvprintw(i+MAXY/2,MAXX/2,"Nemici");
        }
      }

      if(i==2){
        if(i == altezza){
        attron(A_REVERSE);
        mvprintw(i+MAXY/2,MAXX/2,"Proiettili");
        attroff(A_REVERSE);
        }
        else{
        mvprintw(i+MAXY/2,MAXX/2,"Proiettili");
        }
      }
    }
    scelta = getch();

    switch(scelta){

      case UP:
        altezza--;
        if(altezza == -1)
          altezza = 0;
        break;
      case DW:
        altezza++;
        if(altezza == 3)
          altezza = 2;
        break;
      case ENTER:
        esci=true;
      break;
    }
      
  }

  switch (altezza){
    
    case 0: /*Indietro */
      return ;
    break;

    case 1: /*Nemici*/
      
    break;

    case 2: /*Proiettili*/
      
    break;
  
    default:
    break;
  }

}