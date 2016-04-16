#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include "Game.h"

Game::Game(int width, int height) {
  this->width = width;
  this->height = height;
  this->score = 0;
  this->paddle = new Paddle();
  this->ball = new Ball();
}

int Game::getScore() {
  return this->score;
}

void Game::next(float acc) {
  // do something
}

void Game::render() {
  std::cout << "render... " << this->score << "\n";
}

Game::~Game() {
  std::cout << "Game Over. Final Score: " << this->score;
}
