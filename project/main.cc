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
  Wiimote wii;

  // Instantiate Game statically
  Game game(160, 40, 10);

  // Keep track of remote position
  float position = 0.0;

  while (!game.isGameOver()) {

    // Read acceleration from wii remote
    struct AccelerationEvent accEvent = wii.readAccelerationEvent();

    // Update position
    if (accEvent.code == 3) {
      position += accEvent.acc;
    }

    // Update game
    game.next(position / 4.0);

    // Render the board
    game.render();

    // Write score to ZedBoard
    zb.setLedNumber(game.getScore());

    // Sleep
    usleep(0.1 * 1000000);
  }

  return 0;
}
