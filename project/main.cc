#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <time.h>
#include <unistd.h>
#include "Game/Game.h"

int main() {

  // Instantiate Game statically
  Game game(80, 80);

  while (1) {
    game.next(0.0);
    game.render();
    usleep(0.2 * 1000000);
  }

  return 0;
}
