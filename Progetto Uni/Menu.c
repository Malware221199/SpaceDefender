#include "Utility.h"

/*
----------------------------------------------------------------------
 Funzione 'Menu'
----------------------------------------------------------------------
*/
int Menu(int *nnemici,int *vproiettili){
  refresh();            /* refresho la pagina */
  
  char menu[3][7] = {"Gioca","Opzioni","Esci"};  /*stringa opzioni */
  char scelta;       /* variabile scelta */
  int altezza=0;    /* altezza cursore */                          
  bool esci;
  while(esci==false){
    
    int i;
    for(i=0;i<3;i++){
      mvprintw(i+1,1,menu[i]);
      if(i == altezza)
      //wattron(menuwin,A_REVERSE);
      //mvprintw(i+1,1,menu[i]);
      //wattroff(menuwin,A_REVERSE);*/  
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

 /* switch (menu[altezza]){
    
    case Gioca:
      return 1;
    break;

    case Opzioni:
      //opzioni(int &nnemici,int &vproiettili);
    break;

    case Esci:
      return 0;
    break;
  
    default:
    break;
  }*/

}