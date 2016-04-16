
class Ball {

  // Position
  float x;
  float y;

  // Velocity
  float vx;
  float vy;

public:

  Ball(float x, float y, float vx, float vy);

  float getX();

  float getY();

  void move();

  void collideX();

  void collideY();

  ~Ball();
};
