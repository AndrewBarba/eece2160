#include "Ball.h"

Ball::Ball(float x, float y, float vx, float vy) {
  this->x = x;
  this->y = y;
  this->vx = vx;
  this->vy = vy;
}

float Ball::getX() {
  return this->x;
}

float Ball::getY() {
  return this->y;
}

bool Ball::isFalling() {
  return this->vy > 0;
}

bool Ball::isLeading() {
  return this->vx > 0;
}

void Ball::move() {
  this->x += this->vx;
  this->y += this->vy;
}

void Ball::collideX() {
  this->vx *= -1;
}

void Ball::collideY() {
  this->vy *= -1;
}

Ball::~Ball() {
  // dealloc
}
