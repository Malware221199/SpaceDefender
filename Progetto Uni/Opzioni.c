#include "Utility.h"

void Opzioni(int *nnemici,int *vproiettili){
  clear();              /* cancello la pagina */
  refresh();            /* refresho la pagina */
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
    mvprintw(0,10,"Numero nemici: %d",*nnemici);
      *nnemici=nemici();
    break;

    case 2: /*Proiettili*/
      
    break;
  
    default:
    break;
  }

}

int nemici(){
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
        return n;
      break;
    }


  }

}


int proiettili() {
  clear();              /* cancello la pagina */
  refresh();            /* refresho la pagina */








}