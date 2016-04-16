

main: main.o Game.o Ball.o Paddle.o
	g++ main.o Game.o Ball.o Paddle.o -o main

main.o: main.cc Game/Game.h
	g++ -c main.cc

Game.o: Game/Game.cc Game/Game.h Ball/Ball.h Paddle/Paddle.h
	g++ -c Game/Game.cc

Ball.o: Ball/Ball.cc Ball/Ball.h
	g++ -c Ball/Ball.cc

Paddle.o: Paddle/Paddle.cc Paddle/Paddle.h
	g++ -c Paddle/Paddle.cc

clean:
	rm *.o main
