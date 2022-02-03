#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>



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
#define MAXX 	  80    /* Distanza alieni*/
#define MAXY 	  25    /* Distanza alieni*/


#define DELAYL 	500000
#define DELAYV 	120000	    /* Ritardo nel movimento delle navicelle nemiche veloce */
#define DELAYM 	160000	    /* Ritardo nel movimento delle navicelle nemiche medio */
#define DELAYL 	500000	    /* Ritardo nel movimento delle navicelle nemiche lento */

/*
----------------------------------------------------------------------
 Variabili
----------------------------------------------------------------------
*/
//int MAXX,MAXY;  /* Dimensione dello schermo di output (colonne) e (righe)  */
int p[2];				/* Descrittori pipe */  
int pidA;   		/* Pid processo figlio 'Alieni' */
int pidG;	      /* Pid processo figlio 'Giocatore' */
int pidB1;	      /* Pid processo figlio 'Bullet uno' */
int pidB2;	      /* Pid processo figlio 'Bullet due' */
int idb;

/*
----------------------------------------------------------------------
 Funzioni
----------------------------------------------------------------------
*/
void alieni(int pipeout,int id,int nnemici);
void giocatore(int pipeout);
void bullet(int pipeout,int id,int cgy,int cgx);
void areaGioco(int pipein);
int menu(int *nnemici,int *difficolta);
void opzioni(int *nnemici,int *difficolta);
int difficulty(int *difficolta);
void nemici(int *nnemici);
void stampasprite(int y,int x,char c,int n);
void cancellasprite(int y,int x,char c,int n);

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
  int pid;  /*Pid processo*/
};
/* Struttura adoperata per salvare le coordinate*/
typedef struct 
{
  int x;    /* Coordinata X */
  int y;    /* Coordinata Y */
  int id;   /* Numero dell elemento */
  int pid;  /*Pid processo*/
}save;

