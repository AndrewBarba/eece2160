
class Paddle {

  float x;

  float width;

public:

  Paddle(float x, float width);

  float getX();

  float getWidth();

  void move(float vx);

  ~Paddle();
};
