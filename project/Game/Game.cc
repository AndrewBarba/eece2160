#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include "Game.h"

Game::Game(int width, int height) {
  this->width = width;
  this->height = height;
  this->score = 0;
  this->gameOver = false;
  this->paddle = new Paddle(width / 2, 10.0);
  this->ball = new Ball(width / 2, 0.0, 1.0, 1.0);
}

bool Game::isGameOver() {
  return this->gameOver;
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
  if (this->ball->getY() <= this->height && this->ball->getY() >= this->height - 1.0 && this->ball->getX() >= this->paddle->getX() && this->ball->getX() <= this->paddle->getX() + this->paddle->getWidth()) {
    this->ball->collideY();
    this->score += 1;
  }

  // Check for game over
  if (this->ball->getY() > this->height) {
    this->gameOver = true;
  }
}

void Game::render() {
  for (int y = 0; y < this->height; y++) {
    for (int x = 0; x < this->width; x++) {
      if (this->ball->getX() == x && this->ball->getY() == y) {
        std::cout << "o";
      } else {
        std::cout << " ";
      }
    }
    std::cout << "\n";
  }

  for (int x = 0; x < this->width; x++) {
    if (this->paddle->getX() <= x && this->paddle->getX() + this->paddle->getWidth() >= x) {
      std::cout << "=";
    } else {
      std::cout << " ";
    }
  }

  std::cout << "\n";
}

Game::~Game() {
  std::cout << "Game Over. Final Score: " << this->score;
}
