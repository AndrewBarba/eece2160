#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <time.h>
#include <unistd.h>
#include "Game/Game.h"
#include "Wiimote/Wiimote.h"

// Keep track of remote position
float position = 0.0;

// Background thread for Wii events
pthread_t wiithread;

/**
 * Listens for Wii button presses on a background thread
 */
void * listen(void * arg) {

  // Instantiate Wii
  Wiimote *wii = new Wiimote();

  while (1) {

    // Read acceleration from wii remote
    struct AccelerationEvent *accEvent = wii->readAccelerationEvent();

    // Update our position variable
    switch (accEvent->code) {
    case 105:
      position = accEvent->acc == 1 ? -5.0 : 0.0;
      break;
    case 106:
      position = accEvent->acc == 1 ? 5.0 : 0.0;
      break;
    }

    // Free memory
    delete accEvent;
  }

  delete wii;

  return 0;
}

/**
 * Main function
 */
int main() {

  // Instantiate ZedBoard
  ZedBoard *zb = new ZedBoard();

  // Instantiate game
  Game *game = new Game(160, 40, 10);

  // Create a background thread to listen for button events
  pthread_create(&wiithread, NULL, listen, NULL);

  // Enter main run loop
  while (!game->isGameOver()) {

    // Update game and render screen
    game->next(position)->render();

    // Write score to ZedBoard
    zb->setLedNumber(game->getScore());

    // Sleep
    usleep(0.1 * 1000000);
  }

  delete zb;

  delete game;

  return 0;
}
