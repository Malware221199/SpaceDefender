#include "Utility.h"

/*
----------------------------------------------------------------------
 Funzione 'Menu'
----------------------------------------------------------------------
*/
int menu(int *nnemici,int *vproiettili){
  WINDOWS * menuwin = (6,MAXX,MAXY,5);  /* creo finestra */
  box(menuwin,0,0);
  refresh();                            /* refresho la pagina */
  wrefresh(menuwin);
  
  string menu[3] = {"Gioca","Opzioni","Esci"};  /*stringa opzioni */
  int scelta;       /* variabile scelta */
  int altezza=0;    /* altezza cursore */                          

  while(1){
    for(int i=0;i<3;i++){

      if(i == altezza)
        wattron(menuwin,A_REVERSE);
      mvwprintw(menuwin, i+1,1,menu[i].c_str());
      wattroff(menuwin,A_REVERSE);  
    }
    scelta = wgetch(menuwin);

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
      default:
      break;  
    }
    if(scelta == ENTER)
      break;
  }

  switch (menu[altezza]){
    
    case Gioca:
      return 1;
    break;

    case Opzioni:
      opzioni(int &nnemici,int &vproiettili);
    break;

    case Esci:
      return 0;
    break;
  
    default:
    break;
  }

}