#include "Utility.h" 
/*
----------------------------------------------------------------------
 Funzione 'giocatore' - Movimento tramite i tasti cursore 
----------------------------------------------------------------------
*/
void giocatore(int pipeout)
{
  save giocatore;
  int idb=0, maxb=10; /*ID proiettile,massimo proiettili disponibili*/

  
  giocatore.x = 2;       /* Coordinata X iniziale */
  giocatore.y = MAXY/2-2;   /* Coordinata Y iniziale */
  giocatore.c='G';	    /* Carattere identificativo giocatore*/
  giocatore.id=1;   /* Numero dell elemento */
  giocatore.pid=getpid();  /*Pid processo*/
  giocatore.alive=true;


  /* Comunico al processo padre le coordinate iniziali del giocatore */
  write(pipeout,&giocatore,sizeof(giocatore));
  
  /* Lettura dei tasti cursore */
  while(1)
  {
  		char c;
    c = getch();

    if (c==UP && giocatore.y > 0){
      giocatore.y-=1;				
    }

    if(c==DW  && giocatore.y < MAXY - 5){
      giocatore.y+=1;		
    }

    if(c==SPC){
      idb++;
      pidB1=fork();
      
      if(pidB1==0) {
        close(p[0]); /* chiusura del descrittore di lettura */
        bulletg(p[1],idb,giocatore.y,giocatore.x); /* invocazione funzione bullet */
      }	
      idb++;
    
      pidB2=fork();
      
      if(pidB2==0) {
       
        close(p[0]); /* chiusura del descrittore di lettura */
        bulletg(p[1],idb,giocatore.y,giocatore.x); /* invocazione funzione bullet */ 
        }
      
    }

    /* Comunico al processo padre le coordinate del giocatore */
    write(pipeout,&giocatore,sizeof(giocatore)); 

  }
}