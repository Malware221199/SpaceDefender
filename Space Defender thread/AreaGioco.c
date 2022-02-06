#include "Utility.h"

/*
----------------------------------------------------------------------
 Funzione 'Alieni'
---------------------------------------------------------------------- 
*/

void *alieni(void *arg){
int deltax=1;		/* Spostamento orizzontale */
int deltay=1;		/* Spostamento verticale */
if(Alieni.id==0||Alieni.id==1) Alieni.x= MAXX-(GSA+DA);
if(Alieni.id==2||Alieni.id==3) Alieni.x= MAXX-(GSA+DA)*2;
if(Alieni.id==4||Alieni.id==5) Alieni.x= MAXX-(GSA+DA)*3;
if(Alieni.id==6||Alieni.id==7) Alieni.x= MAXX-(GSA+DA)*4;
if(Alieni.id==8||Alieni.id==9) Alieni.x= MAXX-(GSA+DA)*5;
if(Alieni.id%2==0) Alieni.y=(MAXY/4);
else if (Alieni.id%2==1) Alieni.y=MAXY-(MAXY/4)-3;
  
Alieni.c ='A';	/* Carattere identificativo */
Alieni.id =ida; /* Numero dell elemento */

while(!collision){
  /* Blocco mutex, cancello ultimo carattere e sblocco mutex */
	pthread_mutex_lock(&mcancella);			
  cancellasprite(Alieni.y,Alieni.x,Alieni.c);
	pthread_mutex_unlock(&mcancella);
    
  /* Movimento X */
  Alieni.x -= deltax;

  /* Blocco mutex, disegno carattere, aggiorno schermo e sblocco mutex */
	pthread_mutex_lock(&mstampa);			
  stampasprite(Alieni.y,Alieni.x,Alieni.c);
	refresh();																							
	pthread_mutex_unlock(&mstampa); 

    
  if (random() < RAND_MAX/10){
    idbn++;
    bulletn;
    }
  
    
  /* Inserisco una pausa per rallentare il movimento */
  usleep(difficolta);
  }
}



/*
----------------------------------------------------------------------
 Funzione 'giocatore' - Movimento tramite i tasti cursore 
----------------------------------------------------------------------
*/
void *giocatore(void *arg)
{
  int maxb=10; /*massimo proiettili disponibili*/

  
  Giocatore.x = 2;       /* Coordinata X iniziale */
  Giocatore.y = MAXY/2-2;   /* Coordinata Y iniziale */
  Giocatore.c='G';	    /* Carattere identificativo giocatore*/
  Giocatore.id=1;   /* Numero dell elemento */

  
  /* Lettura dei tasti cursore */
  while(!collision){
    /* Blocco mutex, cancello ultimo carattere e sblocco mutex */
	  pthread_mutex_lock(&mtx);			
    cancellasprite(Giocatore.y,Giocatore.x,Giocatore.c);
	  pthread_mutex_unlock(&mtx);


  		char c;
    c = getch();

    if (c==UP && Giocatore.y > 0){
      Giocatore.y-=1;				
    }

    if(c==DW  && Giocatore.y < MAXY - 1){
      Giocatore.y+=1;		
    }

    if(c==SPC){
      idbg++;
        bulletg; /* invocazione funzione bullet */
      idbg++;
        bulletg; /* invocazione funzione bullet */ 
      
    }

  /* Blocco mutex, disegno carattere, aggiorno schermo e sblocco mutex */
	pthread_mutex_lock(&mtx);			
  stampasprite(Giocatore.y,Giocatore.x,Giocatore.c);
	refresh();																							
	pthread_mutex_unlock(&mtx); 

  }
}

/*
----------------------------------------------------------------------
 Funzione 'Bullet giocatore'
---------------------------------------------------------------------- 
*/
void *bulletg(void *arg){
    int deltax=1;		/* Spostamento orizzontale */
    int deltay=1;		/* Spostamento verticale */
    Bulletg.x = Giocatore.x+7;  /* Coordinata X iniziale */
    Bulletg.y = Giocatore.y+2;  /* Coordinata Y iniziale */
    Bulletg.c ='B';	/* Carattere identificativo */
    Bulletg.id =idbg; /* Numero dell elemento */
    

    while(!collision){
        /* Cancello il precedente carattere visualizzato */
        cancellasprite(Bulletg.y,Bulletg.x,Bulletg.c);

        if(Bulletg.id%2==0){
            /* Movimento Y */
            Bulletg.y += deltay;
            /* Se supero area Y schermo inverte il movimento */
            if(Bulletg.y + deltay < 0 || Bulletg.y + deltay > MAXY-1) deltay = -deltay;
            
        }
        else{
            /* Movimento Y */
            Bulletg.y -= deltay;
            /* Se supero area Y schermo inverte il movimento */
            if(Bulletg.y - deltay < 0 || Bulletg.y - deltay > MAXY-1) deltay = -deltay;
            
        }
        
        
        /* Movimento X */
        Bulletg.x += deltax;

        /* Visualizzo il carattere dell'entità sulle nuove coordinate */
        stampasprite(Bulletg.y,Bulletg.x,Bulletg.c);
            

        /* Inserisco una pausa per rallentare il movimento */
        usleep(50000);
    }
}


/*
----------------------------------------------------------------------
 Funzione 'Bullet nemico'
---------------------------------------------------------------------- 
*/
void *bulletn(void *arg){
    int deltax=1;		/* Spostamento orizzontale */
    Bulletn.x = Alieni.x-1;  /* Coordinata X iniziale */
    Bulletn.y = Alieni.y+1;  /* Coordinata Y iniziale */
    Bulletn.c ='H';	/* Carattere identificativo */
    Bulletn.id =idbn; /* Numero dell elemento */
    
    while(!collision){
        /* Cancello il precedente carattere visualizzato */
        cancellasprite(Bulletn.y,Bulletn.x,Bulletn.c);

        /* Movimento X */
        Bulletn.x -= deltax;

        /* Visualizzo il carattere dell'entità sulle nuove coordinate */
        stampasprite(Bulletn.y,Bulletn.x,Bulletn.c);

        /* Inserisco una pausa per rallentare il movimento */
        usleep(100000);
    }
}






/*
----------------------------------------------------------------------
 Funzione 'Area Gioco'
---------------------------------------------------------------------- 
*/

void area(void){

    int i=0, j=0, k=0, vite=3, alienimorti=0;

        do {
            /* Collisioni Alieni*/
            if(Alieni.x<10){
                vite--;
                cancellasprite(Alieni.y,Alieni.x,Alieni.c);
                Alieni.y=DEADYA;
                Alieni.x=DEADXA;
                alienimorti++;
            }
                
            /* Collisioni proiettili con MAXX*/
            if (Bulletg.x>MAXX){
                cancellasprite(Bulletg.y,Bulletg.x,Bulletg.c);
                Bulletg.x=DEADXB;
                Bulletg.y=DEADYB;
            }
            /* Collisioni proiettili con alieni*/
            int exit=0;
            
                for(j=0;j<GSA;j++){
                    for(k=0;k<GSA;k++){
                        if(Bulletg.x == (Alieni.x)+k && Bulletg.y == (Alieni.y)+j){
                            cancellasprite(Alieni.y,Alieni.x,Alieni.c);
                            Bulletg.y=DEADYB;
                            Bulletg.x=DEADXB;
                            Alieni.y=DEADYA;
                            Alieni.x=DEADXA;
                            if(exit==0){
                                alienimorti++;
                                exit=1;
                            }      
                        }
                    }
                }
            
            /* Visualizzo le vite rimaste al giocatore */
            cancellasprite(0,1,'V');
            for(i=0;i<vite;i++) mvaddstr(0,1+i,"❥");
            

            /* Aggiorno lo schermo di output per visualizzare le modifiche */
            refresh();

            /* Esce quando terminano le vite del Giocatore */
            if(vite < 1) {
                collision=1;
                clear();
                stampasprite(MAXY/2-2,MAXX/2-25,'O');
                refresh();
                usleep(4000000);
            }

            if(alienimorti>=nnemici) {
                collision=1;
                clear();
                stampasprite(MAXY/2-2,MAXX/2-18,'W');
                refresh();
                usleep(4000000);
            }



    /* Il ciclo si ripete finchè le vite del giocatore terminano o gli alieni terminano */
    } while(!collision);

}	