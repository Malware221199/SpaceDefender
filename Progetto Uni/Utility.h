#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <unistd.h>



#define	UP			65		/* Cursore sopra */
#define DW			66		/* Cursore sotto */
#define	SX 			68		/* Cursore sinistra */
#define DX			67		/* Cursore destra */
#define SPC			32		/* Cursore spazio */
#define ENTER		10	  /* Cursore invio */
#define	MAXX		80		/* Dimensione dello schermo di output (colonne) */
#define MAXY		25		/* Dimensione dello schermo di output (righe)   */
#define DELAYV 	120000	    /* Ritardo nel movimento delle navicelle nemiche veloce */
#define DELAYM 	160000	    /* Ritardo nel movimento delle navicelle nemiche medio */
#define DELAYL 	200000	    /* Ritardo nel movimento delle navicelle nemiche lento */

int p[2];				/* Descrittori pipe */
/*Funzioni adoperate */
void Alieni(int pipeout,int nn);
void Gen_alieni(int pipeout,int nnemici);
void Giocatore(int pipeout);
void AreaGioco(int pipein);
int Menu(int *nnemici,int *vproiettili);
void Opzioni(int *nnemici,int *vproiettili);
int proiettili();
int nemici();
void stampasprite(int y,int x,char c,int n);
void cancellasprite(int y,int x,char c,int n);

/* Struttura adoperata per veicolare le coordinate*/
struct position {
  char c; 	/* Identificatore dell'entità che invia i dati */
  int  x;	 /* Coordinata X */
  int  y;	 /* Coordinata Y */
  int  id;  /* Numero dell elemento */
};
