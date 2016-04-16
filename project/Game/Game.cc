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

  float w = this->width;
  float h = this->height;
  float bx = this->ball->getX();
  float by = this->ball->getY();
  float px = this->paddle->getX();
  float pw = this->paddle->getWidth();

  // Move paddle
  this->paddle->move(vx);

  // Move ball
  this->ball->move();

  // Check for side collision
  if (bx <= 0 || bx >= w) {
    this->ball->collideX();
  }

  // Check for top collision
  if (by <= 0) {
    this->ball->collideY();
  }

  // Check for paddle collision
  if (by == h && bx >= px && bx <= px + pw) {
    this->ball->collideY();
    this->score += 1;
  }

  // Check for game over
  if (by > h) {
    this->gameOver = true;
  }
}

void Game::render() {

  // Clear the screen
  for (int y = 0; y < 100; y++) {
    std::cout << "\n";
  }

  // Render board and ball
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

  // Render paddle under board
  for (int x = 0; x < this->width; x++) {
    if (this->paddle->getX() <= x && this->paddle->getX() + this->paddle->getWidth() >= x) {
      std::cout << "=";
    } else {
      std::cout << " ";
    }
  }
}

Game::~Game() {
  std::cout << "Game Over. Final Score: " << this->score;
}
