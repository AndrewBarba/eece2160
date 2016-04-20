#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <time.h>
#include <unistd.h>
#include "Game/Game.h"
#include "Wiimote/Wiimote.h"

// Instantiate ZedBoard statically
ZedBoard zb;

// Instantiate Wiimote statically
Wiimote wii;

// Instantiate Game statically
Game game(160, 40, 10);

// Keep track of remote position
float position = 0.0;

/**
 * Listens for Wii button presses on a background thread
 */
void * listen(void * arg) {

  while (1) {

    // Read acceleration from wii remote
    struct AccelerationEvent accEvent = wii.readAccelerationEvent();

    // Update our position variable
    switch (accEvent.code) {
    case 105:
      position = accEvent.acc == 1 ? -5.0 : 0.0;
      break;
    case 106:
      position = accEvent.acc == 1 ? 5.0 : 0.0;
      break;
    }
  }

  return 0;
}

/**
 * Main function
 */
int main() {

  // Create a background thread to listen for button events
  pthread_t t1;
  pthread_create(&t1, NULL, listen, NULL);

  // Enter main run loop
  while (!game.isGameOver()) {

    // Update game and render screen
    game.next(position)->render();

    // Write score to ZedBoard
    zb.setLedNumber(game.getScore());

    // Sleep
    usleep(0.1 * 1000000);
  }

  return 0;
}
