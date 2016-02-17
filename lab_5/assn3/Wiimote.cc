#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include "Wiimote.h"

Wiimote::Wiimote() {
	this->fd = open("/dev/input/event0", O_RDONLY);
  if (this->fd == -1) {
    std::cerr << "Error: Could not open event file - forgot sudo?\n";
		exit(1);
  }
}

void Wiimote::listen() {
	while (true) {

    // Read a packet of 32 bytes from Wiimote
    char buffer[32];
    read(fd, buffer, 32);

    // Extract code (byte 10) and value (byte 12) from packet
    int code = buffer[10];
    short acc = * (short *) (buffer + 12);
    this->accelerationEvent(code, acc);
  }
}

void Wiimote::accelerationEvent(int code, short acc) {
	std::cout << "Code = " << code << ", acceleration = " << acc << '\n';
}

Wiimote::~Wiimote() {
	close(this->fd);
}
