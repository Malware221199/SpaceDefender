#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>
#include <time.h>



/*
----------------------------------------------------------------------
 Costanti
----------------------------------------------------------------------
*/
#define	UP			65		/* Cursore sopra */
#define DW			66		/* Cursore sotto */
#define	SX 			68		/* Cursore sinistra */
#define DX			67		/* Cursore destra */
#define SPC			32		/* Cursore spazio */
#define ENTER		10	  /* Cursore invio */
#define GSA 	  3     /* Grandezza sprite alieno*/
#define GSG 	  6     /* Grandezza sprite giocatore*/
#define DA 	    2     /* Distanza alieni*/
#define DB 	    1     /* Dimensione bullet*/
#define NMB	30              /* Numero massimo proiettili */
#define DEADYA 	-10         /*Coordinata morta y alieno*/
#define DEADXA 	-10         /*Coordinata morta x alieno*/
#define DEADYB 	-15        /*Coordinata morta y proiettile*/
#define DEADXB 	-15         /*Coordinata morta x proiettile */
#define DELAYV 	200000	    /* Ritardo nel movimento delle navicelle nemiche veloce */
#define DELAYM 	400000	    /* Ritardo nel movimento delle navicelle nemiche medio */
#define DELAYL 	500000	    /* Ritardo nel movimento delle navicelle nemiche lento */
#define MAXX 80
#define MAXY 24
#define TIMERMISSILE	    50

/*
----------------------------------------------------------------------
 Variabili
----------------------------------------------------------------------
*/

/*
----------------------------------------------------------------------
 Strutture
----------------------------------------------------------------------
*/
/* Struttura adoperata per salvare le coordinate*/
typedef struct 
{
  char c;    /* Identificatore dell'entità che invia i dati */
  int x;    /* Coordinata X */
  int y;    /* Coordinata Y */
  int id;   /* Numero dell elemento */
  pid_t pid;  /*Pid processo*/
  bool alive; 
  int liv;
}save;

/*
----------------------------------------------------------------------
 Funzioni
----------------------------------------------------------------------
*/
void alieni(int pipeout,save A,int difficolta);
void giocatore(int pipeout);
void bulletg(int pipeout,save BG);
void bulletn(int pipeout,save BN);
void area(int pipein,int pipeout,int nnemici);
bool menu(int *nnemici,int *difficolta);
int opzioni(int *nnemici,int *difficolta);
void difficulty(int *difficolta);
void nemici(int *nnemici);
void stampasprite(int y,int x,char c);
void cancellasprite(int y,int x,char c);
bool collisione(save c1,int lar1, int lun1,save c2,int lar2,int lun2);
bool fuorischermo(save c, int lar, int lun);



