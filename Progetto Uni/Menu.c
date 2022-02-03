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
  bool esci;
  while(esci==false){
    int i;
    attron(COLOR_PAIR(1));
    stampasprite(1,MAXX/2-20,'S',76);
    attroff(COLOR_PAIR(1));
    for(i=0;i<3;i++){
      if(i==0){
        if(i == altezza){
        attron(COLOR_PAIR(1));
        stampasprite(MAXY/2,MAXX/2-13,'S',26);
        attroff(COLOR_PAIR(1));
        ;
        }
        else{
        attron(COLOR_PAIR(2));
        stampasprite(MAXY-14,MAXX/2-13,'S',26);;
        attroff(COLOR_PAIR(2));
        }
      }

      if(i==1){
        if(i == altezza){
        attron(COLOR_PAIR(1));
        stampasprite(MAXY-9,MAXX/2-18,'S',37);
        attroff(COLOR_PAIR(1));
        }
        else{
        attron(COLOR_PAIR(2));
        stampasprite(MAXY-9,MAXX/2-18,'S',37);;
        attroff(COLOR_PAIR(2));
        }
      }

      if(i==2){
        if(i == altezza){
        attron(COLOR_PAIR(1));
        stampasprite(MAXY-4,MAXX/2-10,'S',21);
        attroff(COLOR_PAIR(1));
        }
        else{
        attron(COLOR_PAIR(2));
        stampasprite(MAXY-4,MAXX/2-10,'S',21);;
        attroff(COLOR_PAIR(2));
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
      opzioni(nnemici,difficolta);
    break;

    case 2: /*Esci*/
      return 0;
    break;
  
    default:
    break;
  }
  }
}