#include "Utility.h"
pthread_t tbulletg;
pthread_t tbulletn;
int idbg=0;     /* id proiettili giocatore*/
int idbn=0;     /* id proiettili nemici*/
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
    ida++;
    //pthread_mutex_unlock(&malieni);
    mvprintw(0,15,"%d",ida);
    mvprintw(0,30,"%d",nnemici);
    int deltax=1;		/* Spostamento orizzontale */
    int deltay=1;		/* Spostamento verticale */
    
    Alieni.c ='A';	/* Carattere identificativo */
    A[ida].id =ida; /* Numero dell elemento */

    pthread_mutex_lock(&malieni);
    if(ida==0||ida==1) A[ida].cord.x= MAXX-(GSA+DA);
    if(ida==2||ida==3) A[ida].cord.x= MAXX-(GSA+DA)*2;
    if(ida==4||ida==5) A[ida].cord.x= MAXX-(GSA+DA)*3;
    if(ida==6||ida==7) A[ida].cord.x= MAXX-(GSA+DA)*4;
    if(ida==8||ida==9) A[ida].cord.x= MAXX-(GSA+DA)*5;
    

    if(A[ida].id%2==0) A[ida].cord.y=(MAXY/4);
    else if (A[ida].id%2==1) A[ida].cord.y=MAXY-(MAXY/4)-3;
    pthread_mutex_unlock(&malieni);

    while(!collision){
        pthread_mutex_lock(&malieni);
        A[1].old_cord.x=A[1].cord.x;
        A[1].old_cord.y=A[1].cord.y;
        pthread_mutex_unlock(&malieni);

        pthread_mutex_lock(&malieni);
        A[2].cord.x-=1;
        
        pthread_mutex_unlock(&malieni);

        //if (random() < RAND_MAX/10){
        //idbn++;
        //bulletn;
        //}
    
        /* Inserisco una pausa per rallentare il movimento */
        usleep(DELAYM);
        }
}



/*
----------------------------------------------------------------------
 Funzione 'giocatore' - Movimento tramite i tasti cursore 
----------------------------------------------------------------------
*/
void *giocatore(void *arg)
{
   // pthread_mutex_unlock(&mgiocatore);
  int maxb=10; /*massimo proiettili disponibili*/

  pthread_mutex_lock(&mgiocatore);
  G.cord.x = 2;       /* Coordinata X iniziale */
  G.cord.y = MAXY/2-2;   /* Coordinata Y iniziale */
  G.id=1;   /* Numero dell elemento */
  pthread_mutex_unlock(&mgiocatore);

  
  
  while(!collision){
      pthread_mutex_lock(&mgiocatore);
      G.old_cord.x=G.cord.x;
      G.old_cord.y=G.cord.y;
      pthread_mutex_unlock(&mgiocatore);


    /* Lettura dei tasti cursore */
  	char c;
    c = getch();

    if (c==UP && G.cord.y > 0){
        pthread_mutex_lock(&mgiocatore);
        G.cord.y-=1;
        pthread_mutex_unlock(&mgiocatore);				
    }

    if(c==DW  && G.cord.y < MAXY - 1){
        pthread_mutex_lock(&mgiocatore);
        G.cord.y+=1;
        pthread_mutex_unlock(&mgiocatore);		
    }

    if(c==SPC){
        idbg++;
      /* Creo il thread bullet giocatore */
        //if(pthread_create(&tbulletg, NULL, bulletg, NULL)){
        //endwin();
        //exit;
        //}
        //idbg++;
      /* Creo il thread bullet giocatore */
        //if(pthread_create(&tbulletg, NULL, bulletg, NULL)){
        //endwin();
        //exit;
       // }

    }

  }
}

/*
----------------------------------------------------------------------
 Funzione 'Bullet giocatore'
---------------------------------------------------------------------- 
*/
void *bulletg(void *arg){
    //int deltax=1;		/* Spostamento orizzontale */
    //int deltay=1;		/* Spostamento verticale */
    //Bulletg.x = Giocatore.x+7;  /* Coordinata X iniziale */
    //Bulletg.y = Giocatore.y+2;  /* Coordinata Y iniziale */
    //Bulletg.c ='B';	/* Carattere identificativo */
    //Bulletg.id =idbg; /* Numero dell elemento */
    

    //while(!collision){
        //BG[Bulletg.id].old_cord.x=Bulletg.x;
        //BG[Bulletg.id].old_cord.y=Bulletg.y;
       // BG[Bulletg.id].id=Bulletg.id;

    
        //if(Bulletg.id%2==0){
            /* Movimento Y */
            //Bulletg.y += deltay;
            /* Se supero area Y schermo inverte il movimento */
            //if(Bulletg.y + deltay < 0 || Bulletg.y + deltay > MAXY-1) deltay = -deltay;
           
        //}
        //else{
            /* Movimento Y */
           // Bulletg.y -= deltay;
            /* Se supero area Y schermo inverte il movimento */
            //if(Bulletg.y - deltay < 0 || Bulletg.y - deltay > MAXY-1) deltay = -deltay;
            
        //}
        
        
        /* Movimento X */
        //Bulletg.x += deltax;

        /* Inserisco una pausa per rallentare il movimento */
        //usleep(50000);
    //}
}


/*
----------------------------------------------------------------------
 Funzione 'Bullet nemico'
---------------------------------------------------------------------- 
*/
void *bulletn(void *arg){
    //int deltax=1;		/* Spostamento orizzontale */
    //Bulletn.x = Alieni.x-1;  /* Coordinata X iniziale */
    //Bulletn.y = Alieni.y+1;  /* Coordinata Y iniziale */
    //Bulletn.c ='H';	/* Carattere identificativo */
    //Bulletn.id =idbn; /* Numero dell elemento */
    
    //while(!collision){
        //BN[Bulletg.id].old_cord.x=Bulletn.x;
        //BN[Bulletg.id].old_cord.y=Bulletn.y;
        //BN[Bulletg.id].id=Bulletn.id;

        /* Movimento X */
        //Bulletn.x -= deltax;

        /* Inserisco una pausa per rallentare il movimento */
        usleep(100000);
    //}
}






/*
----------------------------------------------------------------------
 Funzione 'Area Gioco'
---------------------------------------------------------------------- 
*/

void area(void){

    int i=0, j=0, k=0, vite=3, alienimorti=0;
        clear();
        do {
            
            /*Alieni*/
            pthread_mutex_lock(&malieni);
            for(i=0;i<nnemici;i++){
            //cancellasprite(A[0].old_cord.y,A[0].old_cord.x,'A');
            stampasprite(A[i].cord.y,A[i].cord.x,'A');
            pthread_mutex_unlock(&malieni);
            }
            /*Giocatore*/
            pthread_mutex_lock(&mgiocatore);
            cancellasprite(G.old_cord.y,G.old_cord.x,'G');
            stampasprite(G.cord.y,G.cord.x,'G');
            pthread_mutex_unlock(&mgiocatore);

            /*Bullet giocatore*/
            //pthread_mutex_lock(&mbulletg);
            //cancellasprite(BG[Bulletg.id].old_cord.y,BG[Bulletg.id].old_cord.x,Bulletg.c);
            //stampasprite(BG[Bulletg.id].cord.y,BG[Bulletg.id].cord.x,Bulletg.c);
            //pthread_mutex_unlock(&mbulletg);

            /*Bullet nemici*/
            //pthread_mutex_lock(&mbulletn);
            //cancellasprite(BN[Bulletn.id].old_cord.y,BN[Bulletn.id].old_cord.x,Bulletn.c);
            //stampasprite(BN[Bulletn.id].cord.y,BN[Bulletn.id].cord.x,Bulletn.c);
            //pthread_mutex_unlock(&mbulletn);

            /*
            ----------------------------------------------------------------------
            Collisioni
            ---------------------------------------------------------------------- 
            */

           
            
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
                pthread_join (tbulletg, NULL);
                pthread_join (tbulletn, NULL);	
            }

            if(alienimorti>=2) {
                collision=1;
                clear();
                stampasprite(MAXY/2-2,MAXX/2-18,'W');
                refresh();
                usleep(4000000);
                pthread_join (tbulletg, NULL);
                pthread_join (tbulletn, NULL);	
            }



    /* Il ciclo si ripete finchè le vite del giocatore terminano o gli alieni terminano */
    } while(!collision);

}	