#include "../Ball/Ball.h"
#include "../Paddle/Paddle.h"

class Game {

  // Width of the board
  int width;

  // Height of the board
  int height;

  // Current score
  int score;

  // The paddle controlled by Wiimote
  Paddle *paddle;

  // The ball
  Ball *ball;

public:

  // Constructor
  Game(int width, int height);

  // Getter for private score
  int getScore();

  // Moves the board state one position further in time
  // Pass in the acceleration of the paddle
  void next(float vx);

  // Renders the current state of the game to the console
  void render();

  ~Game();
};
