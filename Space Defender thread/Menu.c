#include "Utility.h"

/*
----------------------------------------------------------------------
 Funzione 'Menu'
----------------------------------------------------------------------
*/
int menu(int *nnemici,int *difficolta){
  while(1){
  int menu[3] = {0,1,2};  /*stringa opzioni */
  char scelta;       /* variabile scelta */
  int altezza=0;    /* altezza cursore */                          
  bool esci=false;
  while(!esci){
    clear();
    refresh();
    int i;
    stampasprite(1,MAXX/2-20,'S');  /* stampo sprite 'space' */
    stampasprite(8,MAXX/2-29,'D');  /* stampo sprite 'defender' */
    
    for(i=0;i<3;i++){
      if(i==0){
        if(i == altezza){
        attron(COLOR_PAIR(1));
        stampasprite(MAXY-9,MAXX/2-8,'U');
        attroff(COLOR_PAIR(1));
        ;
        }
        else{
        attron(COLOR_PAIR(3));
        stampasprite(MAXY-9,MAXX/2-8,'U');
        attroff(COLOR_PAIR(3));
        }
      }

      if(i==1){
        if(i == altezza){
        attron(COLOR_PAIR(1));
        stampasprite(MAXY-6,MAXX/2-11,'Z');
        attroff(COLOR_PAIR(1));
        }
        else{
        attron(COLOR_PAIR(3));
        stampasprite(MAXY-6,MAXX/2-11,'Z');;
        attroff(COLOR_PAIR(3));
        }
      }

      if(i==2){
        if(i == altezza){
        attron(COLOR_PAIR(1));
        stampasprite(MAXY-3,MAXX/2-6,'E');
        attroff(COLOR_PAIR(1));
        }
        else{
        attron(COLOR_PAIR(3));
        stampasprite(MAXY-3,MAXX/2-6,'E');;
        attroff(COLOR_PAIR(3));
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

      default:
      break;
    }
      
  }

  switch (altezza){
    
    case 0: /*Gioca */
      return false;
    break;

    case 1: /*Opzioni*/
      opzioni(nnemici,difficolta);
    break;

    case 2: /*Esci*/
      return true;
    break;
  
    default:
    break;
  }
  }
}