

main: main.o Wiimote.o
	g++ main.o Wiimote.o -o main

main.o: main.cc Wiimote.h
	g++ -c main.cc

Wiimote.o: Wiimote.cc Wiimote.h
	g++ -c Wiimote.cc

clean:
	rm *.o main
