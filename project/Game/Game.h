#include "../Ball/Ball.h"
#include "../Paddle/Paddle.h"

class Game {

  int width;

  int height;

  int score;

  bool gameOver;

  Paddle *paddle;

  Ball *ball;

public:

  /**
   * Public constructor
   *
   * @param {int} width - width of board
   * @param {int} height - height of board
   * @param {int} pwidth - width of the paddle
   */
  Game(int width, int height, int pwidth);

  /**
   * Destructor
   */
  ~Game();

  /**
   * Is the game over?
   */
  bool isGameOver();

  /**
   * Return current game score
   *
   * @return {int}
   */
  int getScore();

  /**
   * Return private x position of paddle
   *
   * @param {float} vx - update game state. moves the underlying paddle by a given x velocity
   */
  void next(float vx);

  /**
   * Render the board to std out
   */
  void render();
};
