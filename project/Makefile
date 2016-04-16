

main: main.o Game.o Ball.o Paddle.o ZedBoard.o Wiimote.o
	g++ main.o Game.o Ball.o Paddle.o ZedBoard.o Wiimote.o -o main

main.o: main.cc Game/Game.h Wiimote/Wiimote.h
	g++ -c main.cc

Game.o: Game/Game.cc Game/Game.h Ball/Ball.h Paddle/Paddle.h
	g++ -c Game/Game.cc

Ball.o: Ball/Ball.cc Ball/Ball.h
	g++ -c Ball/Ball.cc

Paddle.o: Paddle/Paddle.cc Paddle/Paddle.h
	g++ -c Paddle/Paddle.cc

Wiimote.o: Wiimote/Wiimote.cc Wiimote/Wiimote.h ZedBoard/ZedBoard.h
	g++ -c Wiimote/Wiimote.cc

ZedBoard.o: ZedBoard/ZedBoard.cc ZedBoard/ZedBoard.h
	g++ -c ZedBoard/ZedBoard.cc

clean:
	rm *.o main
