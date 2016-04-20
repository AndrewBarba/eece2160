#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <time.h>
#include <unistd.h>
#include "Wiimote.h"

Wiimote::Wiimote() {
	this->fd = open("/dev/input/event0", O_RDONLY);
  if (this->fd == -1) {
    std::cerr << "Error: Could not open event file - forgot sudo?\n";
		exit(1);
  }
}

AccelerationEvent Wiimote::readAccelerationEvent() {

	struct AccelerationEvent accEvent;

	// Read a packet of 32 bytes from Wiimote
	char buffer[32];
	read(fd, buffer, 32);

	// Extract code (byte 10) and value (byte 12) from packet
	accEvent.code = buffer[10];
	accEvent.acc = * (short *) (buffer + 12);

	return accEvent;
}

Wiimote::~Wiimote() {
	close(this->fd);
}
