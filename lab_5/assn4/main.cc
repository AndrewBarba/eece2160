#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include "Wiimote.h"

class WiimoteToLed: public Wiimote {

public:

  WiimoteToLed(ZedBoard *zb): Wiimote(zb) {}

  void accelerationEvent(int code, short acc) {
  	if (code == 3) return;

    // Limit to [-100, 100]
    acc = fmax(acc, -100);
    acc = fmin(acc, 100);

    // Convert to number between 0 and 8
    int count = (int)((abs(acc) * 8) / 100);

    // Set LED's
    for (int x = 0; x < 8; x++) {
      int on = x < count;
      this->zb->setLedState(x, on);
    }
  }
};

int main() {

  // Instantiate ZedBoard object statically
  ZedBoard zed_board;

  // Instantiate WiimoteToLed object statically, passing a pointer to the
  // recently created ZedBoard object.
  WiimoteToLed wiimote_to_led(&zed_board);

  // Enter infinite loop listening to events. The overridden function
  // WiimoteToLed::AccelerationEvent() will be invoked when the user moves
  // the Wiimote.
  wiimote_to_led.listen();

  // Unreachable code, previous function has an infinite loop
  return 0;
}
