

main: main.o Wiimote.o ZedBoard.o
	g++ main.o Wiimote.o ZedBoard.o -o main

main.o: main.cc Wiimote.h ZedBoard.h
	g++ -c main.cc

Wiimote.o: Wiimote.cc Wiimote.h
	g++ -c Wiimote.cc

ZedBoard.o: ZedBoard.cc ZedBoard.h
	g++ -c ZedBoard.cc

clean:
	rm *.o main
