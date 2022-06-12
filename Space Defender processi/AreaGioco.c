#include "Utility.h"

/*
----------------------------------------------------------------------
 Funzione 'Area Gioco'
---------------------------------------------------------------------- 
*/

void area(int pipein,int nnemici){

    save A[11];
    save BG[30];
    save BN[30];
    save G;
    save dato_letto;

    int i=0, j=0, k=0, vite=3, collision=0, alienimorti=0;

        do {
            /* Leggo dalla pipe */
            read(pipein,&dato_letto,sizeof(dato_letto));

            /*
            ----------------------------------------------------------------------
            Gesione Alieni
            ---------------------------------------------------------------------- 
            */
            if(dato_letto.c=='A') {

                /* Cancello il precedente carattere visualizzato */
                cancellasprite(A[dato_letto.id].y,A[dato_letto.id].x,dato_letto.c);


                /* Aggiorno le coordinate relative alla nuova posizione */
                A[dato_letto.id]=dato_letto;
                mvprintw(0,40,"%d",A[dato_letto.id].liv);
                /* Visualizzo il carattere dell'entità sulle nuove coordinate */
                if(A[dato_letto.id].alive && A[dato_letto.id].liv==1) stampasprite(dato_letto.y,dato_letto.x,'a');
                else if(A[dato_letto.id].alive && A[dato_letto.id].liv==2) stampasprite(dato_letto.y,dato_letto.x,'A');

                /* Collisioni Alieni*/
                if(A[dato_letto.id].x<10){
                    vite--;
                    kill(A[dato_letto.id].pid,1);
                    cancellasprite(A[dato_letto.id].y,A[dato_letto.id].x,dato_letto.c);
                    A[dato_letto.id].y=DEADYA;
                    A[dato_letto.id].x=DEADXA;
                    alienimorti++;
                    
                    
                }
            }

             /*
            ----------------------------------------------------------------------
            Gesione Giocatore
            ---------------------------------------------------------------------- 
            */
            else if(dato_letto.c=='G'){
                /* Cancello il precedente sprite visualizzato */
                cancellasprite(G.y,G.x,G.c);

                /* Aggiorno le coordinate relative alla nuova posizione */
                G=dato_letto;

                /* Visualizzo il carattere dell'entità sulle nuove coordinate */
                stampasprite(dato_letto.y,dato_letto.x,dato_letto.c);

            }

             /*
            ----------------------------------------------------------------------
            Gesione proiettili giocatore
            ---------------------------------------------------------------------- 
            */
            else if(dato_letto.c=='B'){

                /* Cancello il precedente carattere visualizzato */
                cancellasprite(BG[dato_letto.id].y,BG[dato_letto.id].x,dato_letto.c);

                /* Aggiorno le coordinate relative alla nuova posizione */
                BG[dato_letto.id]=dato_letto;
                
                /* Visualizzo il carattere dell'entità sulle nuove coordinate */
                stampasprite(dato_letto.y,dato_letto.x,dato_letto.c);
            
                
                /* Collisioni proiettili con MAXX*/
                if (BG[dato_letto.id].x>MAXX){
                    kill(BG[dato_letto.id].pid,1);
                    cancellasprite(BG[dato_letto.id].y,BG[dato_letto.id].x,'B');
                    BG[dato_letto.id].x=DEADXB;
                    BG[dato_letto.id].y=DEADYB;
                }
                /* Collisioni proiettili con alieni*/
                 for(i=0;i<11;i++){
                    
                    
                    if(A[i].alive){
                       
                        if(BG[dato_letto.id].alive && collisione(BG[dato_letto.id], DB, DB,A[i],GSA,GSA) && A[i].liv==1)
                        {   
                            BG[dato_letto.id].alive=false;
                            kill(BG[dato_letto.id].pid,1);
                            A[i].liv=2;
                        }
                        else if(BG[dato_letto.id].alive && collisione(BG[dato_letto.id], DB, DB,A[i],GSA,GSA) && A[i].liv==2)
                        {
                            BG[dato_letto.id].alive=false;
                            kill(BG[dato_letto.id].pid,1);
                            A[i].alive=false;
                            kill(A[i].pid,1);
                            alienimorti++;
                        }
                            
                        
                    }
                }
            }
             /*
            ----------------------------------------------------------------------
            Gesione proiettili nemico
            ---------------------------------------------------------------------- 
            */
            else if(dato_letto.c=='H'){
                /*Cancello il precedente carattere visualizzato */
                cancellasprite(BN[dato_letto.id].y,BN[dato_letto.id].x,dato_letto.c);
                
                /*Aggiorno le coordinate relative alla nuova posizione */
                BN[dato_letto.id]=dato_letto;

                /* Visualizzo il carattere dell'entità sulle nuove coordinate */
                stampasprite(dato_letto.y,dato_letto.x,dato_letto.c);
            }


            /* Visualizzo le vite rimaste al giocatore */
            cancellasprite(0,1,'V');
            for(i=0;i<vite;i++) mvaddstr(0,1+i,"❥");
            //mvprintw(0,40,"%d",alienimorti);
            

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

    /* Termino i processi Alieni e Giocatore
            kill(G.pid,1);
            for(i=0;i<11;i++) kill(A[i].pid,1);
            for(i=0;i<30;i++) kill(BG[i].pid,1);
            for(i=0;i<30;i++) kill(BN[i].pid,1);
    */
}

bool collisione(save c1,int lar1, int lun1,save c2,int lar2,int lun2)
{
    return(
        c1.x < c2.x + lar2 &&
        c1.x + lar1 > c2.x &&
        c1.y < c2.y + lun2 &&
        c1.y + lun1 >c2.y
    );
}

bool fuorischermo(save c, int lar, int lun)
{
    return(
        c.y + lun > MAXY || c.y < 0 || c.x + lar > MAXX || c.x < 0
    );

}		