#include "Utility.h"

/*
----------------------------------------------------------------------
 Funzione 'Menu'
----------------------------------------------------------------------
*/
int Menu(int *nnemici,int *vproiettili){
  refresh();            /* refresho la pagina */
  
  int menu[3] = {0,1,2};  /*stringa opzioni */
  char scelta;       /* variabile scelta */
  int altezza=0;    /* altezza cursore */                          
  bool esci;
  while(esci==false){
    
    int i;
    for(i=0;i<3;i++){
      if(i==0){
        if(i == altezza){
        attron(A_REVERSE);
        mvprintw(i+1,MAXX/2,"Gioca");
        attroff(A_REVERSE);
        }
        else{
        mvprintw(i+1,MAXX/2,"Gioca");
        }
      }

      if(i==1){
        if(i == altezza){
        attron(A_REVERSE);
        mvprintw(i+1,MAXX/2,"Opzioni");
        attroff(A_REVERSE);
        }
        else{
        mvprintw(i+1,MAXX/2,"Opzioni");
        }
      }

      if(i==2){
        if(i == altezza){
        attron(A_REVERSE);
        mvprintw(i+1,MAXX/2,"Esci");
        attroff(A_REVERSE);
        }
        else{
        mvprintw(i+1,MAXX/2,"Esci");
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
    
    case 0: /*Gioca */
      return 1;
    break;

    case 1: /*Opzioni*/
      //opzioni(int &nnemici,int &vproiettili);
    break;

    case 2: /*Esci*/
      return 0;
    break;
  
    default:
    break;
  }

}