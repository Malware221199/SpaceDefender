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
    

    int deltax=1;		/* Spostamento orizzontale */
    int deltay=1;		/* Spostamento verticale */
    int myida;
    pthread_mutex_lock(&initalieni);
    A[ida].id =ida; /* Numero dell elemento */
    myida=ida;
    ida++;
    pthread_mutex_unlock(&initalieni);

    pthread_mutex_lock(&malieni);
    if(myida==0||myida==1) A[myida].cord.x= MAXX-(GSA+DA);
    if(myida==2||myida==3) A[myida].cord.x= MAXX-(GSA+DA)*2;
    if(myida==4||myida==5) A[myida].cord.x= MAXX-(GSA+DA)*3;
    if(myida==6||myida==7) A[myida].cord.x= MAXX-(GSA+DA)*4;
    if(myida==8||myida==9) A[myida].cord.x= MAXX-(GSA+DA)*5;
    

    if(A[myida].id%2==0) A[myida].cord.y=(MAXY/4);
    else if (A[myida].id%2==1) A[myida].cord.y=MAXY-(MAXY/4)-3;
    pthread_mutex_unlock(&malieni);

    while(!collision){
        pthread_mutex_lock(&malieni);
        A[myida].cord.x-=1;
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

  int maxb=10; /*massimo proiettili disponibili*/

  pthread_mutex_lock(&mgiocatore);
  G.cord.x = 2;       /* Coordinata X iniziale */
  G.cord.y = MAXY/2-2;   /* Coordinata Y iniziale */
  G.id=1;   /* Numero dell elemento */
  pthread_mutex_unlock(&mgiocatore);
  

  
  
  while(!collision){
      
      


    /* Lettura dei tasti cursore */
  	char c;
    c = getch();
    pthread_mutex_lock(&mgiocatore);
    if (c==UP && G.cord.y > 0){
        G.cord.y-=1; 			
    }
    
    if(c==DW  && G.cord.y < MAXY - 1){
        G.cord.y+=1;		
    }
    pthread_mutex_unlock(&mgiocatore);

    if(c==SPC){
      /* Creo il thread bullet giocatore */
        if(pthread_create(&tbulletg, NULL, bulletg, NULL)){
            endwin();
            exit;
        }

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
    int myidbg;
    
    pthread_mutex_lock(&initbulletg);
    BG[idbg].id =idbg; /* Numero dell elemento */
    myidbg=idbg;
    idbg++;
    pthread_mutex_unlock(&initbulletg);
    pthread_mutex_lock(&mgiocatore);
    BG[myidbg].cord.x = G.cord.x+7;  /* Coordinata X iniziale */
    BG[myidbg].cord.y = G.cord.y+2;  /* Coordinata Y iniziale */
    pthread_mutex_unlock(&mgiocatore);
    
    

    while(!collision){
       

        pthread_mutex_lock(&mbulletg);
        if(BG[myidbg].id%2==0){
            /* Movimento Y */
            BG[myidbg].cord.y += deltay;
            /* Se supero area Y schermo inverte il movimento */
            if(BG[myidbg].cord.y + deltay < 0 || BG[myidbg].cord.y + deltay > MAXY-1) deltay = -deltay;
           
        }
        else{
            /* Movimento Y */
            BG[myidbg].cord.y -= deltay;
            /* Se supero area Y schermo inverte il movimento */
            if(BG[myidbg].cord.y - deltay < 0 || BG[myidbg].cord.y - deltay > MAXY-1) deltay = -deltay;
            
        }
        
        
        /* Movimento X */
        BG[myidbg].cord.x += deltax;
        pthread_mutex_unlock(&mbulletg);
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

        G.cord.x = 2;       /* Coordinata X iniziale */
        G.cord.y = MAXY/2-2;   /* Coordinata Y iniziale */
        G.id=1;   /* Numero dell elemento */

        do {
            
            /*Alieni*/
            for(i=0;i<nnemici;i++){
                cancellasprite(A[i].old_cord.y,A[i].old_cord.x,'A');
                pthread_mutex_lock(&malieni);
                stampasprite(A[i].cord.y,A[i].cord.x,'A');
                A[i].old_cord.x=A[i].cord.x;
                A[i].old_cord.y=A[i].cord.y;
                pthread_mutex_unlock(&malieni);
            }
            /*Giocatore*/
            cancellasprite(G.old_cord.y,G.old_cord.x,'G');
            pthread_mutex_lock(&mgiocatore);
            stampasprite(G.cord.y,G.cord.x,'G');
            G.old_cord.x=G.cord.x;
            G.old_cord.y=G.cord.y;
            pthread_mutex_unlock(&mgiocatore);


            /*Bullet giocatore*/
            cancellasprite(BG[Bulletg.id].old_cord.y,BG[Bulletg.id].old_cord.x,Bulletg.c);
            pthread_mutex_lock(&mbulletg);
            stampasprite(BG[Bulletg.id].cord.y,BG[Bulletg.id].cord.x,Bulletg.c);
            BG[myidbg].old_cord.x=Bulletg.x;
            BG[myidbg].old_cord.y=Bulletg.y;
            BG[myidbg].id=Bulletg.id;
            pthread_mutex_unlock(&mbulletg);

            /*Bullet nemici*/
            //cancellasprite(BN[Bulletn.id].old_cord.y,BN[Bulletn.id].old_cord.x,Bulletn.c);
            //stampasprite(BN[Bulletn.id].cord.y,BN[Bulletn.id].cord.x,Bulletn.c);

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
                //stampasprite(MAXY/2-2,MAXX/2-25,'O');
                refresh();
                usleep(4000000);
                pthread_join (tbulletg, NULL);
                pthread_join (tbulletn, NULL);	
            }

            if(alienimorti>=2) {
                collision=1;
                clear();
                //stampasprite(MAXY/2-2,MAXX/2-18,'W');
                refresh();
                usleep(4000000);
                pthread_join (tbulletg, NULL);
                pthread_join (tbulletn, NULL);	
            }



    /* Il ciclo si ripete finchè le vite del giocatore terminano o gli alieni terminano */
    } while(!collision);

}	