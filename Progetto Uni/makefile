Spacedefender: Main.o Menu.o Alieni.o Giocatore.o AreaGioco.o Grafica.o
	cc -o Spacedefender Main.o Menu.o Alieni.o Giocatore.o AreaGioco.o Grafica.o -lncurses

Main.o: Main.c Utility.h
	cc -c -o Main.o Main.c -lncurses

Menu.o: Menu.c Utility.h
	cc -c -o Menu.o menu.c -lncurses

Alieni.o: Alieni.c Utility.h
	cc -c -o Alieni.o Alieni.c -lncurses

Giocatore.o: Giocatoreu.c Utility.h
	cc -c -o Giocatore.o Giocatore.c -lncurses

AreaGioco.o: AreaGioco.c Utility.h
	cc -c -o AreaGioco.o AreaGioco.c -lncurses

Grafica.o: Grafica.c Grafica.h
	cc -c -o Grafica.o Grafica.c -lncurses
	
clean:
	rm Spacedefender
	rm *.o



