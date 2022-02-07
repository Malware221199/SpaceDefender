#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>
#include <pthread.h>




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
#define DA 	    2     /* Distanza alieni*/
#define MAXX	    80
#define MAXY 	    24


#define DEADYA 	-10         /*Coordinata morta y alieno*/
#define DEADXA 	-10         /*Coordinata morta x alieno*/
#define DEADYB 	-15        /*Coordinata morta y proiettile*/
#define DEADXB 	-15         /*Coordinata morta x proiettile */
#define DELAYV 	200000	    /* Ritardo nel movimento delle navicelle nemiche veloce */
#define DELAYM 	400000	    /* Ritardo nel movimento delle navicelle nemiche medio */
#define DELAYL 	500000	    /* Ritardo nel movimento delle navicelle nemiche lento */

/*
----------------------------------------------------------------------
 Variabili
----------------------------------------------------------------------
*/
//int MAXX,MAXY;  /* Dimensione dello schermo di output (colonne) e (righe)  */
extern int nnemici;
extern int difficolta;
extern ida;


/*
----------------------------------------------------------------------
 Funzioni
----------------------------------------------------------------------
*/
void *alieni(void *arg);
void *giocatore(void *arg);
void *bulletg(void *arg);
void *bulletn(void *arg);
void areaGioco(void *arg);
int menu(int *nnemici,int *difficolta);
int opzioni(int *nnemici,int *difficolta);
void difficulty(int *difficolta);
void nemici(int *nnemici);
void stampasprite(int y,int x,char c);
void cancellasprite(int y,int x,char c);

/*
----------------------------------------------------------------------
 Strutture
----------------------------------------------------------------------
*/
/* Struttura adoperata per veicolare le coordinate*/
struct position {
  char c; 	/* Identificatore dell'entità che invia i dati */
  int  x;	 /* Coordinata X */
  int  y;	 /* Coordinata Y */
  int  id;  /* Numero dell elemento */
  
};
typedef struct 
{
  int x;    /* Coordinata X */
  int y;    /* Coordinata Y */
}cord;
typedef struct 
{
  cord cord;
  cord old_cord;
  int id;   /* Numero dell elemento */
}save;

struct position Alieni;
struct position Giocatore;
struct position Bulletg;
struct position Bulletn;

/* Mutex per la gestione dei thread */
pthread_mutex_t	malieni;
pthread_mutex_t	mgiocatore;
pthread_mutex_t	mbulletg;
pthread_mutex_t	mbulletn;
