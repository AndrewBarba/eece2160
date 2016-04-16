#include "Paddle.h"

Paddle::Paddle(float x, float width) {
  this->x = x;
  this->width = width;
}

float Paddle::getX() {
  return this->x;
}

float Paddle::getWidth() {
  return this->width;
}

void Paddle::move(float vx) {
  this->x += vx;
}

Paddle::~Paddle() {
  // dealloc
}
