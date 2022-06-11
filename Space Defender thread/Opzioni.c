#include "Utility.h"
/*
----------------------------------------------------------------------
 Funzione 'Opzioni'
----------------------------------------------------------------------
*/
int opzioni(int *nnemici,int *difficolta){
  bool esci=false;
  while(!esci){
    clear();              /* cancello la pagina */
    refresh();            /* refresho la pagina */
    int Opzioni[3] = {0,1,2};  /*stringa opzioni */
    char scelta;       /* variabile scelta */
    int altezza=0;    /* altezza cursore */                          
    
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
          stampasprite(MAXY-9,MAXX/2-14,'I');
          attroff(COLOR_PAIR(1));
          }
          else{
          attron(COLOR_PAIR(3));
          stampasprite(MAXY-9,MAXX/2-14,'I');
          attroff(COLOR_PAIR(3));
          }
        }

        if(i==1){
          if(i == altezza){
          attron(COLOR_PAIR(1));
          stampasprite(MAXY-6,MAXX/2-11,'N');
          attroff(COLOR_PAIR(1));
          }
          else{
          attron(COLOR_PAIR(3));
          stampasprite(MAXY-6,MAXX/2-11,'N');
          attroff(COLOR_PAIR(3));
          }
        }

        if(i==2){
          if(i == altezza){
          attron(COLOR_PAIR(1));
          stampasprite(MAXY-3,MAXX/2-17,'P');
          attroff(COLOR_PAIR(1));
          }
          else{
          attron(COLOR_PAIR(3));
          stampasprite(MAXY-3,MAXX/2-17,'P');
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
      }
    }  
    

    switch (altezza){
      
    case 0: /*Indietro */
        return 1;
      break;

      case 1: /*Nemici*/
        nemici(nnemici);
        esci=false;

      break;

      case 2: /*Difficolta*/
        difficulty(difficolta);
        esci=false;
      break;
    
      default:
      break;
    }
  }
}
/*
----------------------------------------------------------------------
 Funzione 'Nemici'
----------------------------------------------------------------------
*/
void nemici(int *nnemici){
  int s,n=2;
  while(1){
    clear();              /* cancello la pagina */
    refresh();            /* refresho la pagina */
    stampasprite(8,MAXX/2-26,'C');
    
    switch(n){
      case 2:
        stampasprite(MAXY-9,MAXX/2-4,'Q');
      break;
      
      case 4:
        stampasprite(MAXY-9,MAXX/2-4,'X');
      break;
      
      case 6:
        stampasprite(MAXY-9,MAXX/2-4,'V');
      break;

      case 8:
        stampasprite(MAXY-9,MAXX/2-4,'R');
      break;
      
      case 10:
        stampasprite(MAXY-9,MAXX/2-8,'Y');
      break;
    }

    s = getch();
    switch(s){
      case DW:
        n-=2;

        if(n == 0)
          n = 2;
        break;
      case UP:
        n+=2;
        if(n == 12)
          n = 10;
        break;
      case ENTER:
        *nnemici=n;
        return;
      break;
    }
  }
}
/*
----------------------------------------------------------------------
 Funzione 'Difficolta'
----------------------------------------------------------------------
*/
void difficulty(int *difficolta) {
  clear();              /* cancello la pagina */
  refresh();            /* refresho la pagina */
  int proiettili[4] = {0,1,2};  /*stringa opzioni */
  char scelta;       /* variabile scelta */
  int i,altezza=0;    /* altezza cursore */                          
  bool esci=false;
  while(esci==false){
    stampasprite(1,MAXX/2-20,'S');  /* stampo sprite 'space' */
    stampasprite(8,MAXX/2-29,'D');  /* stampo sprite 'defender' */

    for(i=0;i<3;i++){

      if(i==0){
        if(i == altezza){
        attron(COLOR_PAIR(1));
        stampasprite(MAXY-9,MAXX/2-14,'L');
        attroff(COLOR_PAIR(1));
        }
        else{
        attron(COLOR_PAIR(3));
        stampasprite(MAXY-9,MAXX/2-14,'L');
        attroff(COLOR_PAIR(3));
        }
      }

      if(i==1){
        if(i == altezza){
        attron(COLOR_PAIR(1));
        stampasprite(MAXY-6,MAXX/2-11,'M');
        attroff(COLOR_PAIR(1));
        }
        else{
        attron(COLOR_PAIR(3));
        stampasprite(MAXY-6,MAXX/2-11,'M');
        attroff(COLOR_PAIR(3));
        }
      }

      if(i==2){
        if(i == altezza){
        attron(COLOR_PAIR(1));
        stampasprite(MAXY-3,MAXX/2-17,'F');
        attroff(COLOR_PAIR(1));
        }
        else{
        attron(COLOR_PAIR(3));
        stampasprite(MAXY-3,MAXX/2-17,'F');
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
    }
      
  }

  switch (altezza){

    case 0: /*Difficile*/
        *difficolta=DELAYV;
        esci=true;  
    break;

    case 1: /*Medio*/
        *difficolta=DELAYM;
        esci=true; 
    break;

    case 2: /*Facile*/
        *difficolta=DELAYL;
        esci=true; 
    break;
  
    default:
    break;
  }








}