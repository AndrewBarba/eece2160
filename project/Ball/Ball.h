
class Ball {

  float x;

  float y;

  float vx;

  float vy;

public:

  /**
   * Public constructor
   *
   * @param {float} x - starting x position of ball
   * @param {float} y - starting y position of ball
   * @param {float} vx - x velocity of ball. (+) down, (-) up.
   * @param {float} vy - y velocity of ball. (+) right, (-) left.
   */
  Ball(float x, float y, float vx, float vy);

  /**
   * Destructor
   */
  ~Ball();

  /**
   * Return private x position of ball
   *
   * @return {float}
   */
  float getX();

  /**
   * Return private y position of ball
   *
   * @return {float}
   */
  float getY();

  /**
   * Moves the ball 1 tick
   */
  void move();

  /**
   * Negates x velocity, simulating a collision
   */
  void collideX();

  /**
   * Negates y velocity, simulating a collision
   */
  void collideY();
};
