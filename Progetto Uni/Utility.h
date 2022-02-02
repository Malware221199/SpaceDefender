#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <unistd.h>

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
#define DELAYV 	120000	    /* Ritardo nel movimento delle navicelle nemiche veloce */
#define DELAYM 	160000	    /* Ritardo nel movimento delle navicelle nemiche medio */
#define DELAYL 	500000	    /* Ritardo nel movimento delle navicelle nemiche lento */

/*
----------------------------------------------------------------------
 Variabili
----------------------------------------------------------------------
*/
int MAXX,MAXY;  /* Dimensione dello schermo di output (colonne) e (righe)  */
int p[2];				/* Descrittori pipe */  
int pidA;   		/* Pid processo figlio 'Alieni' */
int pidG;	      /* Pid processo figlio 'Giocatore' */
int pidB;	      /* Pid processo figlio 'Bullet' */

/*
----------------------------------------------------------------------
 Funzioni
----------------------------------------------------------------------
*/
void Alieni(int pipeout,int id);
void Giocatore(int pipeout);
void Bullet(int pipeout,int id);
void AreaGioco(int pipein);
int Menu(int *nnemici,int *difficolta);
void Opzioni(int *nnemici,int *difficolta);
int difficulty(int *difficolta);
int nemici();
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
};

typedef struct 
{
  int x;
  int y;
  int id;
}alien;

