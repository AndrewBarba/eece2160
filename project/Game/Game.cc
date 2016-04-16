#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include "Game.h"

Game::Game(int width, int height) {
  this->width = width;
  this->height = height;
  this->score = 0;
  this->paddle = new Paddle(0, width);
  this->ball = new Ball(width / 2, 0.0, 4.0, 4.0);
}

int Game::getScore() {
  return this->score;
}

void Game::next(float vx) {

  // Move paddle
  this->paddle->move(vx);

  // Move ball
  this->ball->move();

  // Check for x collision
  if (this->ball->getX() < 0 || this->ball->getX() > this->width) {
    this->ball->collideX();
  }

  // Check for y collision
  if (this->ball->getY() < 0) {
    this->ball->collideY();
  }

  // Check for paddle collision
  if (this->ball->getY() <= this->height && this->ball->getY() >= this->height - 2.0 && this->ball->getX() >= this->paddle->getX() && this->ball->getX() <= this->paddle->getX() + this->paddle->getWidth()) {
    this->ball->collideY();
    this->score += 1;
  }
}

void Game::render() {
  std::cout << "render... " << this->score << "\n";
}

Game::~Game() {
  std::cout << "Game Over. Final Score: " << this->score;
}
