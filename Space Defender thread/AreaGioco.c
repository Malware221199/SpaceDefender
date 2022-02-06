#include "Utility.h"
int idbg=0;     /* id proiettili giocatore*/
int idbn=0;     /* id proiettili nemici*/
int ida=0;
int nnemici=2;
int difficolta=DELAYM;
int collision=0;
save A[11];
save BG[30];
save BN[95];
save G;
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
    A[Alieni.id].x=Alieni.x;
    A[Alieni.id].y=Alieni.y;
    A[Alieni.id].id=Alieni.id;

    /* Movimento X */
    Alieni.x -= deltax;
	
    //if (random() < RAND_MAX/10){
    //idbn++;
    //bulletn;
    //}
  
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

  
  
  while(!collision){
      G.x=Giocatore.x;
      G.y=Giocatore.y;
      G.id=Giocatore.id;


    /* Lettura dei tasti cursore */
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
        //bulletg; /* invocazione funzione bullet */
      idbg++;
        //bulletg; /* invocazione funzione bullet */ 
      
    }

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
        BG[Bulletg.id].x=Bulletg.x;
        BG[Bulletg.id].y=Bulletg.y;
        BG[Bulletg.id].id=Bulletg.id;


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
        BN[Bulletg.id].x=Bulletn.x;
        BN[Bulletg.id].y=Bulletn.y;
        BN[Bulletg.id].id=Bulletn.id;

        /* Movimento X */
        Bulletn.x -= deltax;

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
            /*Alieni*/
            cancellasprite(A[Alieni.id].y,A[Alieni.id].x,Alieni.c);
            stampasprite(Alieni.y,Alieni.x,Alieni.c);

            /*Giocatore*/
            cancellasprite(G.y,G.x,Giocatore.c);
            stampasprite(Giocatore.y,Giocatore.x,Giocatore.c);

            /*Bullet giocatore*/
            cancellasprite(BG[Bulletg.id].x,BG[Bulletg.id].y,Bulletg.c);
            stampasprite(Bulletg.y,Bulletg.x,Bulletg.c);

            /*Bullet nemici*/
            cancellasprite(BN[Bulletn.id].x,BN[Bulletn.id].x,Bulletn.c);
            stampasprite(Bulletn.y,Bulletn.x,Bulletn.c);








            
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