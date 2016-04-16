
class Paddle {

  float x;

  float width;

public:

  /**
   * Public constructor
   *
   * @param {float} x - starting x position of paddle
   * @param {float} width - width of paddle. larger width is easier.
   */
  Paddle(float x, float width);

  /**
   * Destructor
   */
  ~Paddle();

  /**
   * Return private x position of paddle
   *
   * @return {float}
   */
  float getX();

  /**
   * Return private width of paddle
   *
   * @return {float}
   */
  float getWidth();

  /**
   * Moves the paddle by a given velocity
   *
   * @param {float} vx - x velocity to mav paddle. (+) right, (-) left.
   */
  void move(float vx);
};
