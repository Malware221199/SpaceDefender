#include "Utility.h"
pthread_t tbulletg;
pthread_t tbulletn;
int ida=0;
int idbg=0;     /* id proiettili giocatore*/
int idbn=0;     /* id proiettili nemici*/
int startClock=0;
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
    
    pthread_mutex_lock(&initalieni);
    if(ida==nnemici)ida=0;
    myida=ida;
    killA[myida]=false;
    ida++;
    pthread_mutex_unlock(&initalieni);

    pthread_mutex_lock(&malieni);
    A[myida].cord.alive=true;
    if(myida==0||myida==1) A[myida].cord.x= MAXX-(GSA+DA);
    if(myida==2||myida==3) A[myida].cord.x= MAXX-(GSA+DA)*2;
    if(myida==4||myida==5) A[myida].cord.x= MAXX-(GSA+DA)*3;
    if(myida==6||myida==7) A[myida].cord.x= MAXX-(GSA+DA)*4;
    if(myida==8||myida==9) A[myida].cord.x= MAXX-(GSA+DA)*5;
    

    if(myida%2==0) A[myida].cord.y=(MAXY/4);
    else if (myida%2==1) A[myida].cord.y=MAXY-(MAXY/4)-3;
    pthread_mutex_unlock(&malieni);
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
        //A[myida].cord.alive=false;
}



/*
----------------------------------------------------------------------
 Funzione 'giocatore' - Movimento tramite i tasti cursore 
----------------------------------------------------------------------
*/
void *giocatore(void *arg)
{

    int maxb=10,i; /*massimo proiettili disponibili*/
    killG=false;

    pthread_mutex_lock(&mgiocatore);
    G.cord.alive=true;
    G.cord.x = 2;       /* Coordinata X iniziale */
    G.cord.y = MAXY/2-2;   /* Coordinata Y iniziale */
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

        if(c==SPC && clock()-startClock>TIMERMISSILE){
            
            for(i=0;i<2;i++)
            {
                /* Creo il thread bullet giocatore */
                if(pthread_create(&tbulletg, NULL, bulletg, NULL)){
                    endwin();
                    exit;
                }
                /* Inserisco una pausa per rallentare il movimento */
            }
            startClock=clock();
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
    int i;
    
    pthread_mutex_lock(&initbulletg);
    if(idbg>=NMB)idbg=0;
    myidbg=idbg;
    killBG[myidbg]=false;
    idbg++;
    pthread_mutex_unlock(&initbulletg);

    pthread_mutex_lock(&mgiocatore);
    BG[myidbg].cord.x = G.cord.x+7;  /* Coordinata X iniziale */
    BG[myidbg].cord.y = G.cord.y+2;  /* Coordinata Y iniziale */
    BG[myidbg].cord.alive=true;
    pthread_mutex_unlock(&mgiocatore);
    
    

    while(!killBG[myidbg]){
       

        pthread_mutex_lock(&mbulletg);
        if(myidbg%2==0){
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
    //BG[myidbg].cord.alive=false;
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
    int i;
    
    pthread_mutex_lock(&initbulletn);
    if(idbn>=NMB)idbn=0;
    myidbn=idbn;
    killBN[myidbn]=false;
    idbn++;
    pthread_mutex_unlock(&initbulletn);

    pthread_mutex_lock(&malieni);
    BN[myidbn].cord.x = A[ida].cord.x+3;  /* Coordinata X iniziale */
    BN[myidbn].cord.y = A[ida].cord.y+1;  /* Coordinata Y iniziale */
    BN[myidbn].cord.alive=true;
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
    //BN[myidbn].cord.alive=false;

    free(arg);
}






/*
----------------------------------------------------------------------
 Funzione 'Area Gioco'
---------------------------------------------------------------------- 
*/

void area(){

    int i=0, j=0, x=0;
    int collision=0,vite=3, alienimorti=0;
    clear();

    for(i=0;i<11;i++) A[i].old_cord.alive=false;
    for(i=0;i<11;i++) A[i].liv=1;
    for(i=0;i<NMB;i++) BG[i].old_cord.alive=false;
    for(i=0;i<NMB;i++) BN[i].old_cord.alive=false;
    G.old_cord.alive=false;

    do {
        /*
        ----------------------------------------------------------------------
        Gesione Alieni
        ---------------------------------------------------------------------- 
        */
        for(i=0;i<nnemici;i++){
            if(A[i].old_cord.alive) cancellasprite(A[i].old_cord.y,A[i].old_cord.x,'A');
            pthread_mutex_lock(&malieni);
            if(A[i].cord.alive && A[i].liv==1) stampasprite(A[i].cord.y,A[i].cord.x,'a');
            else if(A[i].cord.alive && A[i].liv==2) stampasprite(A[i].cord.y,A[i].cord.x,'A');
            A[i].old_cord=A[i].cord;
            pthread_mutex_unlock(&malieni);
        }
        /*
        ----------------------------------------------------------------------
        Gesione Giocatore
        ---------------------------------------------------------------------- 
        */
        if(G.old_cord.alive)cancellasprite(G.old_cord.y,G.old_cord.x,'G');
        pthread_mutex_lock(&mgiocatore);
        if(G.cord.alive)stampasprite(G.cord.y,G.cord.x,'G');
        G.old_cord=G.cord;
        pthread_mutex_unlock(&mgiocatore);


        /*
        ----------------------------------------------------------------------
        Gesione proiettili giocatore
        ---------------------------------------------------------------------- 
        */
        for(i=0;i<NMB;i++){
        if(BG[i].old_cord.alive) cancellasprite(BG[i].old_cord.y,BG[i].old_cord.x,'B');
        pthread_mutex_lock(&mbulletg);
        if(BG[i].cord.alive) stampasprite(BG[i].cord.y,BG[i].cord.x,'B');
        BG[i].old_cord=BG[i].cord;
        pthread_mutex_unlock(&mbulletg);
        }

        /*
        ----------------------------------------------------------------------
        Gesione proiettili nemico
        ---------------------------------------------------------------------- 
        */
        for(i=0;i<NMB;i++){
        if(BN[i].old_cord.alive) cancellasprite(BN[i].old_cord.y,BN[i].old_cord.x,'H');
        pthread_mutex_lock(&mbulletn);
        if(BN[i].cord.alive) stampasprite(BN[i].cord.y,BN[i].cord.x,'H');
        BN[i].old_cord=BN[i].cord;
        pthread_mutex_unlock(&mbulletn);
        }

        /*
        ----------------------------------------------------------------------
        Collisioni
        ---------------------------------------------------------------------- 
        */

        /*Collisioni Bullet giocatore con nemico*/
        for(i=0;i<11;i++){
            pthread_mutex_lock(&mbulletg);
            pthread_mutex_lock(&malieni);
            if(A[i].cord.alive){
                for(j=0;j<NMB;j++){
                    if(BG[j].cord.alive && collisione(BG[j].cord, DB, DB,A[i].cord,GSA,GSA) && A[i].liv==1)
                    {   
                        killBG[j]=true;
                        BG[j].cord.alive=false;
                        A[i].liv=2;
                    }
                    else if(BG[j].cord.alive && collisione(BG[j].cord, DB, DB,A[i].cord,GSA,GSA) && A[i].liv==2)
                    {
                        killBG[j]=true;
                        BG[j].cord.alive=false;
                        killA[i]=true;
                        A[i].cord.alive=false;
                        alienimorti++;
                    }
                    
                }
            }
            pthread_mutex_unlock(&mbulletg);
            pthread_mutex_unlock(&malieni);
        }
            
        
        /*Collisioni Bullet nemico con giocatore*/
        for(i=0;i<NMB;i++){
            pthread_mutex_lock(&mbulletn);
            pthread_mutex_lock(&mgiocatore);
            if(BN[i].cord.alive && collisione(G.cord,GSG,GSG-1,BN[i].cord, DB, DB)){
                
                killBN[i]=true;
                BN[i].cord.alive=false;
                vite--;  
            }
            pthread_mutex_unlock(&mbulletn);
            pthread_mutex_unlock(&mgiocatore);
        }
                    
            

        /*Collisioni Bullet giocatore con limite schermo*/
        for(i=0;i<NMB;i++){
            if(BG[i].cord.alive && fuorischermo(BG[i].cord,DB,DB))
            {
                killBG[i]=true;
                BG[i].cord.alive=false;
            }

        }

        /*Collisioni Bullet nemico con limite schermo*/
        for(i=0;i<NMB;i++){
            if(BN[i].cord.alive && fuorischermo(BN[i].cord,DB,DB))
            {
                killBN[i]=true;
                BN[i].cord.alive=false;
            }

        }

        /*Collisioni nemico con limite schermo*/
        for(i=0;i<11;i++){
            pthread_mutex_lock(&malieni);
            if(A[i].cord.alive && fuorischermo(A[i].cord, GSA, GSA))
            {
                vite=0;
            }
            pthread_mutex_unlock(&malieni);
        }
        
        /*Collisioni nemico con giocatore*/
        for(i=0;i<11;i++){
            pthread_mutex_lock(&malieni);
            pthread_mutex_lock(&mgiocatore);

            if(A[i].cord.alive && collisione(G.cord,GSG,GSG-1,A[i].cord, GSA, GSA))
            {
                vite=0;
            }
            pthread_mutex_unlock(&malieni);
            pthread_mutex_unlock(&mgiocatore);
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
            mvprintw(MAXY-3,MAXX/2-15,">Premi un tasto per continuare<");
            refresh();
        }

        if(alienimorti>=nnemici) {

            collision=1;
            clear();
            stampasprite(MAXY/2-2,MAXX/2-18,'W');
            mvprintw(MAXY-3,MAXX/2-15,">Premi un tasto per continuare<");
            refresh();
        }



    /* Il ciclo si ripete finchè le vite del giocatore terminano o gli alieni terminano */
    } while(!collision);

/* uccido i processi e imposto l'alive a false*/
for(i=0;i<11;i++) 
{
    killA[i]=true;
    A[i].cord.alive=false;

}
for(i=0;i<NMB;i++) 
{
    killBG[i]=true;
    BG[i].cord.alive=false;

}
 for(i=0;i<NMB;i++)
{
    killBN[i]=true;
    BN[i].cord.alive=false;

}
 killG=true;
 G.cord.alive=false;
 


}
bool collisione(cord c1,int lar1, int lun1,cord c2,int lar2,int lun2)
{
    return(
        c1.x < c2.x + lar2 &&
        c1.x + lar1 > c2.x &&
        c1.y < c2.y + lun2 &&
        c1.y + lun1 >c2.y
    );
}

bool fuorischermo(cord c, int lar, int lun)
{
    return(
        c.y + lun > MAXY || c.y < 0 || c.x + lar > MAXX || c.x < 0
    );

}	