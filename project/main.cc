#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <time.h>
#include <unistd.h>
#include "Game/Game.h"

int main() {

  // Instantiate Game statically
  Game game(160, 40);

  while (1) {
    game.next(0.0);
    game.render();
    usleep(0.05 * 1000000);
  }

  return 0;
}
