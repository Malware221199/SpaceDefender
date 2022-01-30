#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <unistd.h>
#include "Grafica.h"


#define	UP			65		/* Cursore sopra */
#define DW			66		/* Cursore sotto */
#define	SX 			68		/* Cursore sinistra */
#define DX			67		/* Cursore destra */
#define SPC			32		/* Cursore spazio */
#define ENTER		10	  /* Cursore invio */
#define	MAXX		80		/* Dimensione dello schermo di output (colonne) */
#define MAXY		20		/* Dimensione dello schermo di output (righe)   */
#define DELAYV 	80000	    /* Ritardo nel movimento delle navicelle nemiche veloce */
#define DELAYM 	100000	    /* Ritardo nel movimento delle navicelle nemiche medio */
#define DELAYL 	120000	    /* Ritardo nel movimento delle navicelle nemiche lento */

/*Funzioni adoperate */
void Alieni(int pipeout);
void Giocatore(int pipeout);
void AreaGioco(int pipein);
int Menu(int *nnemici,int *vproiettili);
void Opzioni(int *nnemici,int *vproiettili);
int proiettili();
int nemici();

/* Struttura adoperata per veicolare le coordinate*/
struct position {
  char c; 	/* Identificatore dell'entità che invia i dati */
  int  x;	 /* Coordinata X */
  int  y;	 /* Coordinata Y */
};

srand(time(NULL)); /* Inizializza generatore di numeri casuali */
