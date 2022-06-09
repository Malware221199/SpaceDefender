#include "Utility.h"
pthread_t tbulletg;
pthread_t tbulletn;
int ida=0;
int idbg=0;     /* id proiettili giocatore*/
int idbn=0;     /* id proiettili nemici*/
int collision=0;
bool killA[11],killG,killBG[NMB],killBN[NMB];
save A[11];
save BG[NMB];
save BN[NMB];
save G;

/*
----------------------------------------------------------------------
 Funzione 'Alieni'
---------------------------------------------------------------------- 
*/

void *alieni(void *arg){
    
    int i;
    int deltax=1;		/* Spostamento orizzontale */
    int deltay=1;		/* Spostamento verticale */
    int myida;
    for(i=0;i<=11;i++) killA[i]=false;
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
    while(1)printf("%d",killA[myida]);
    while(!killA[myida]){
        pthread_mutex_lock(&malieni);
        /* Movimento X */
        A[myida].cord.x-=1;
        /* Movimento Y */
        
        if(myida%2==0){
            
            A[myida].cord.y -= deltay;
            /* Se supero area Y schermo inverte il movimento */
            if(A[myida].cord.y - deltay < 1 || A[myida].cord.y - deltay > MAXY/2-GSA) deltay *=-1;
           
        }
        else if(myida%2==1){

            A[myida].cord.y += deltay;
            /* Se supero area Y schermo inverte il movimento */
            if(A[myida].cord.y + deltay < MAXY/2  || A[myida].cord.y + deltay > (MAXY-GSA-1)) deltay *=-1;
            
        }
            
        pthread_mutex_unlock(&malieni);

        if (random() < RAND_MAX/10){
            int *i= malloc(sizeof(*i));
            *i=myida;
            if(pthread_create(&tbulletn, NULL, bulletn, (void *)i)){
                endwin();
                exit;
            }
        }
    
        /* Inserisco una pausa per rallentare il movimento */
        usleep(difficolta);
        }
        killA[myida]=false;
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
  

  
  
  while(!killG){
      
      


    /* Lettura dei tasti cursore */
  	char c;
    c = getch();
    pthread_mutex_lock(&mgiocatore);
    if (c==UP && G.cord.y > 0){
        G.cord.y-=1; 			
    }
    
    if(c==DW  && G.cord.y < MAXY - 5){
        G.cord.y+=1;		
    }
    pthread_mutex_unlock(&mgiocatore);

    if(c==SPC){
        int i;
        for(i=0;i<2;i++)
        {
            /* Creo il thread bullet giocatore */
            if(pthread_create(&tbulletg, NULL, bulletg, NULL)){
                endwin();
                exit;
            }
             /* Inserisco una pausa per rallentare il movimento */
        }
    }
  }
killG=false;
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
    if(idbg>=NMB)idbg=0;
    BG[idbg].id =idbg; /* Numero dell elemento */
    myidbg=idbg;
    idbg++;
    pthread_mutex_unlock(&initbulletg);
    pthread_mutex_lock(&mgiocatore);
    BG[myidbg].cord.x = G.cord.x+7;  /* Coordinata X iniziale */
    BG[myidbg].cord.y = G.cord.y+2;  /* Coordinata Y iniziale */
    pthread_mutex_unlock(&mgiocatore);
    
    

    while(!killBG[myidbg]){
       

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
    killBG[myidbg]=false;
}


/*
----------------------------------------------------------------------
 Funzione 'Bullet nemico'
---------------------------------------------------------------------- 
*/
void *bulletn(void *arg){
    int ida=*((int *)arg);
    int deltax=1;		/* Spostamento orizzontale */
    int myidbn;
    
    pthread_mutex_lock(&initbulletn);
    if(idbn>=NMB)idbn=0;
    BN[idbn].id =idbn; /* Numero dell elemento */
    myidbn=idbn;
    idbn++;
    pthread_mutex_unlock(&initbulletn);
    pthread_mutex_lock(&malieni);
    BN[myidbn].cord.x = A[ida].cord.x+3;  /* Coordinata X iniziale */
    BN[myidbn].cord.y = A[ida].cord.y+1;  /* Coordinata Y iniziale */
    pthread_mutex_unlock(&malieni);
    
    

    while(!killBN[myidbn]){
       

        pthread_mutex_lock(&mbulletn);
        /* Movimento X */
        BN[myidbn].cord.x -= deltax;
        pthread_mutex_unlock(&mbulletn);
        /* Inserisco una pausa per rallentare il movimento */
        usleep(50000);
    }
    killBN[myidbn]=false;
    free(arg);
}






/*
----------------------------------------------------------------------
 Funzione 'Area Gioco'
---------------------------------------------------------------------- 
*/

void area(void){

    int i=0, j=0, k=0, x=0, vite=3, alienimorti=0;
        clear();

        G.cord.x = 2;       /* Coordinata X iniziale */
        G.cord.y = MAXY/2-2;   /* Coordinata Y iniziale */
        G.id=1;   /* Numero dell elemento */
        for(i=0;i<=11;i++) killA[i]=false;
        for(i=0;i<NMB;i++) killBG[i]=false;
        for(i=0;i<NMB;i++) killBN[i]=false;
        killG=false;

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
            for(i=0;i<30;i++){
            cancellasprite(BG[i].old_cord.y,BG[i].old_cord.x,'B');
            pthread_mutex_lock(&mbulletg);
            stampasprite(BG[i].cord.y,BG[i].cord.x,'B');
            BG[i].old_cord.x=BG[i].cord.x;
            BG[i].old_cord.y=BG[i].cord.y;
            pthread_mutex_unlock(&mbulletg);
            }

            /*Bullet nemici*/
            for(i=0;i<30;i++){
            cancellasprite(BN[i].old_cord.y,BN[i].old_cord.x,'H');
            pthread_mutex_lock(&mbulletn);
            stampasprite(BN[i].cord.y,BN[i].cord.x,'H');
            BN[i].old_cord.x=BN[i].cord.x;
            BN[i].old_cord.y=BN[i].cord.y;
            pthread_mutex_unlock(&mbulletn);
            }

            /*
            ----------------------------------------------------------------------
            Collisioni
            ---------------------------------------------------------------------- 
            */
           
            /*Collisioni Bullet giocatore*/
            int exit=0;
                for(i=0;i<11;i++){
                    for(x=0;x<30;x++){
                        for(j=0;j<GSA;j++){
                            for(k=0;k<GSA;k++){
                                if(BG[x].cord.x == (A[i].cord.x)+k && BG[x].cord.y == (A[i].cord.y)+j){
                                    
                                    //cancellasprite(A[i].cord.y,A[i].cord.x,'A');
                                    BG[x].cord.y=DEADYB;
                                    BG[x].cord.x=DEADXB;
                                    killBG[x]=true;
                                    A[i].cord.y=DEADYA;
                                    A[i].cord.x=DEADXA;
                                    killA[i]=true;
                                    if(exit==0){
                                        alienimorti++;
                                        exit=1;
                                    }      
                                }
                            }
                        }
                    }
                }
           
            /*Collisioni Bullet nemico*/
                exit=0;
                for(i=0;i<30;i++){
                    for(j=0;j<6;j++){
                            for(k=0;k<6;k++){
                                if(BN[i].cord.x == (G.cord.x)-k && BN[i].cord.y == (G.cord.y)+j){
                                    BN[i].cord.y=DEADYA;
                                    BN[i].cord.x=DEADXA;
                                    if(exit==0){
                                        vite--;
                                        exit=1;
                                    }      
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
                pthread_join (tbulletg, NULL);
                pthread_join (tbulletn, NULL);	
            }

            if(alienimorti>nnemici) {

                collision=1;
                clear();
                stampasprite(MAXY/2-2,MAXX/2-18,'W');
                refresh();
                usleep(400000);
                pthread_join (tbulletg, NULL);
                pthread_join (tbulletn, NULL);	
            }



    /* Il ciclo si ripete finchè le vite del giocatore terminano o gli alieni terminano */
    } while(!collision);

}	