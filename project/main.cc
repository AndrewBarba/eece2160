#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <time.h>
#include <unistd.h>
#include "Game/Game.h"
#include "Wiimote/Wiimote.h"

int main() {

  // Instantiate ZedBoard statically
  ZedBoard zb;

  // Instantiate Wiimote statically
  Wiimote wii(&zb);

  // Instantiate Game statically
  Game game(160, 40);

  while (1) {

    // Update game
    game.next(0.0);

    // Render the board
    game.render();

    // Write score to ZedBoard
    zb.setLedNumber(game.getScore());

    // Sleep
    usleep(0.05 * 1000000);
  }

  return 0;
}
