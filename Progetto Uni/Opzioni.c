#include "Utility.h"
/*
----------------------------------------------------------------------
 Funzione 'Opzioni'
----------------------------------------------------------------------
*/
void opzioni(int *nnemici,int *difficolta){
  clear();              /* cancello la pagina */
  refresh();            /* refresho la pagina */
  int Opzioni[3] = {0,1,2};  /*stringa opzioni */
  char scelta;       /* variabile scelta */
  int altezza=0;    /* altezza cursore */                          
  bool esci;
  while(esci==false){
    int i;
    mvprintw(0,10,"Numero nemici:");
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
        mvprintw(i+MAXY/2,MAXX/2,"Nemici");
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
      return;
    break;

    case 1: /*Nemici*/
      nemici(nnemici);
    break;

    case 2: /*Proiettili*/
      difficulty(difficolta);
    break;
  
    default:
    break;
  }

}
/*
----------------------------------------------------------------------
 Funzione 'Nemici'
----------------------------------------------------------------------
*/
void nemici(int *nnemici){
  int s,n=5;
  while(1){
    clear();              /* cancello la pagina */
    refresh();            /* refresho la pagina */
    mvprintw(MAXY/2,MAXX/2,"Numero nemici: %d",n);
    s = getch();
    switch(s){
      case DW:
        n--;
        if(n == 0)
          n = 1;
        break;
      case UP:
        n++;
        if(n == 11)
          n = 10;
        break;
      case ENTER:
        *nnemici=n;
      break;
    }


  }

}
/*
----------------------------------------------------------------------
 Funzione 'Difficolta'
----------------------------------------------------------------------
*/
int difficulty(int *difficolta) {
  clear();              /* cancello la pagina */
  refresh();            /* refresho la pagina */
  int proiettili[4] = {0,1,2,4};  /*stringa opzioni */
  char scelta;       /* variabile scelta */
  int i,altezza=0;    /* altezza cursore */                          
  bool esci;
  while(esci==false){
    for(i=0;i<4;i++){
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
        mvprintw(i+MAXY/2,MAXX/2,"Difficile");
        attroff(A_REVERSE);
        }
        else{
        mvprintw(i+MAXY/2,MAXX/2,"Difficile");
        }
      }

      if(i==2){
        if(i == altezza){
        attron(A_REVERSE);
        mvprintw(i+MAXY/2,MAXX/2,"Medio");
        attroff(A_REVERSE);
        }
        else{
        mvprintw(i+MAXY/2,MAXX/2,"Medio");
        }
      }

      if(i==3){
        if(i == altezza){
        attron(A_REVERSE);
        mvprintw(i+MAXY/2,MAXX/2,"Facile");
        attroff(A_REVERSE);
        }
        else{
        mvprintw(i+MAXY/2,MAXX/2,"Facile");
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
        if(altezza == 4)
          altezza = 2;
        break;
      case ENTER:
        esci=true;
      break;
    }
      
  }

  switch (altezza){
    
    case 0: /*Indietro */
      return;
    break;

    case 1: /*Difficile*/
        //*difficolta=DELAYV;  
    break;

    case 2: /*Medio*/
        //*difficolta=DELAYM; 
    break;

    case 3: /*Facile*/
        //*difficolta=DELAYL; 
    break;
  
    default:
    break;
  }








}