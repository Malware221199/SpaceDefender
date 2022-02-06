Spacedefender: Main.o Menu.o Opzioni.o Alieni.o Giocatore.o Bullet.o AreaGioco.o Grafica.o
	cc -o Spacedefender Main.o Menu.o Opzioni.o Alieni.o Giocatore.o Bullet.o AreaGioco.o Grafica.o -lncursesw -pthread

Main.o: Main.c Utility.h
	cc -c -o Main.o Main.c -lncursesw -pthread

Menu.o: Menu.c Utility.h
	cc -c -o Menu.o Menu.c -lncursesw -pthread

Opzioni.o: Opzioni.c Utility.h
	cc -c -o Opzioni.o Opzioni.c -lncursesw -pthread

Alieni.o: Alieni.c Utility.h
	cc -c -o Alieni.o Alieni.c -lncursesw -pthread

Giocatore.o: Giocatore.c Utility.h
	cc -c -o Giocatore.o Giocatore.c -lncursesw -pthread

Bullet.o: Bullet.c Utility.h
	cc -c -o Bullet.o Bullet.c -lncursesw -pthread

AreaGioco.o: AreaGioco.c Utility.h
	cc -c -o AreaGioco.o AreaGioco.c -lncursesw -pthread

Grafica.o: Grafica.c Grafica.h
	cc -c -o Grafica.o Grafica.c -lncursesw -pthread
	
clean:
	rm Spacedefender
	rm *.o

dependencies:
	sudo -S apt-get -y install libncursesw5-dev



