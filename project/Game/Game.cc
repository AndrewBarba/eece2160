#include <iostream>
#include "Game.h"

float RandomFloat(float a, float b) {
  srand(time(NULL));
  float random = ((float)rand()) / (float)RAND_MAX;
  float diff = b - a;
  float r = random * diff;
  return a + r;
}

Game::Game(int width, int height, int pwidth) {
  this->width = width;
  this->height = height;
  this->score = 0;
  this->gameOver = false;
  this->paddle = new Paddle(width / 2, pwidth);
  this->ball = new Ball(
    RandomFloat(1, width - 1),
    1.0,
    RandomFloat(1.0, 4.0),
    1.0);
}

bool Game::isGameOver() {
  return this->gameOver;
}

int Game::getScore() {
  return this->score;
}

Game* Game::next(float vx) {

  float w = this->width;
  float h = this->height;
  float bx = this->ball->getX();
  float by = this->ball->getY();
  float px = this->paddle->getX();
  float pw = this->paddle->getWidth();
  bool falling = this->ball->isFalling();
  bool leading = this->ball->isLeading();

  // Move paddle
  this->paddle->move(vx);

  // Move ball
  this->ball->move();

  // Check for left collision
  if (bx <= 0 && !leading) {
    this->ball->collideX();
  }

  // Check for right collision
  if (bx >= w && leading) {
    this->ball->collideX();
  }

  // Check for top collision
  if (by <= 0 && !falling) {
    this->ball->collideY();
  }

  // Check for paddle collision
  if (falling && by >= h - 1 && bx >= px && bx <= px + pw) {
    this->ball->collideY();
    this->score += 1;
  }

  // Check for game over
  if (by > h + 4.0) {
    this->gameOver = true;
  }

  return this;
}

Game* Game::render() {

  // Clear the screen
  for (int y = 0; y < 100; y++) {
    std::cout << "\n";
  }

  // Render board and ball
  for (int y = 0; y < this->height; y++) {
    for (int x = 0; x < this->width; x++) {
      if ((int)this->ball->getX() == x && (int)this->ball->getY() == y) {
        std::cout << "o";
      } else if (x == 0 || x == width - 1) {
        std::cout << "|";
      } else if (y == 0) {
        std::cout << "-";
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

  // End screen
  std::cout << "\n";

  return this;
}

Game::~Game() {
  std::cout << "\n\n" << "GAME OVER" << "\n\n" << "Final Score: " << this->score << "\n\n";
}
