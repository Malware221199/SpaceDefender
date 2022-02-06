Spacedefender: Main.o Menu.o Opzioni.o Alieni.o Giocatore.o Bullet.o AreaGioco.o Grafica.o
	cc -o Spacedefender Main.o Menu.o Opzioni.o Alieni.o Giocatore.o Bullet.o AreaGioco.o Grafica.o -lncursesw

Main.o: Main.c Utility.h
	cc -c -o Main.o Main.c -lncursesw

Menu.o: Menu.c Utility.h
	cc -c -o Menu.o Menu.c -lncursesw

Opzioni.o: Opzioni.c Utility.h
	cc -c -o Opzioni.o Opzioni.c -lncursesw

Alieni.o: Alieni.c Utility.h
	cc -c -o Alieni.o Alieni.c -lncursesw

Giocatore.o: Giocatore.c Utility.h
	cc -c -o Giocatore.o Giocatore.c -lncursesw

Bullet.o: Bullet.c Utility.h
	cc -c -o Bullet.o Bullet.c -lncursesw	

AreaGioco.o: AreaGioco.c Utility.h
	cc -c -o AreaGioco.o AreaGioco.c -lncursesw

Grafica.o: Grafica.c Grafica.h
	cc -c -o Grafica.o Grafica.c -lncursesw
	
clean:
	rm Spacedefender
	rm *.o

dependencies:
	sudo -S apt-get -y install libncursesw5-dev



