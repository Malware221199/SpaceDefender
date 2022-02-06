Spacedefender: Main.o Menu.o Opzioni.o AreaGioco.o Grafica.o
	cc -o Spacedefender Main.o Menu.o Opzioni.o AreaGioco.o Grafica.o -lncursesw -pthread

Main.o: Main.c Utility.h
	cc -c -o Main.o Main.c -lncursesw -pthread

Menu.o: Menu.c Utility.h
	cc -c -o Menu.o Menu.c -lncursesw -pthread

Opzioni.o: Opzioni.c Utility.h
	cc -c -o Opzioni.o Opzioni.c -lncursesw -pthread

AreaGioco.o: AreaGioco.c Utility.h
	cc -c -o AreaGioco.o AreaGioco.c -lncursesw -pthread

Grafica.o: Grafica.c Grafica.h
	cc -c -o Grafica.o Grafica.c -lncursesw -pthread
	
clean:
	rm Spacedefender
	rm *.o

dependencies:
	sudo -S apt-get -y install libncursesw5-dev



