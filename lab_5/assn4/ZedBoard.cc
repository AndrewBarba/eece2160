#include "ZedBoard.h"

ZedBoard::ZedBoard() {
  this->fd = open("/dev/mem", O_RDWR);
  this->ptr = (char *) mmap(
    NULL,
    gpio_size,
    PROT_READ | PROT_WRITE,
    MAP_SHARED,
    this->fd,
    gpio_address);
}

ZedBoard::~ZedBoard() {
  munmap(this->ptr, gpio_size);
  close(this->fd);
}

void ZedBoard::registerWrite(int offset, int value) {
  * (int *) (this->ptr + offset) = value;
}

int ZedBoard::registerRead(int offset) {
  return * (int *) (this->ptr + offset);
}

void ZedBoard::setLedNumber(int value) {
  this->registerWrite(gpio_led1_offset, value % 2);
  this->registerWrite(gpio_led2_offset, (value / 2) % 2);
  this->registerWrite(gpio_led3_offset, (value / 4) % 2);
  this->registerWrite(gpio_led4_offset, (value / 8) % 2);
  this->registerWrite(gpio_led5_offset, (value / 16) % 2);
  this->registerWrite(gpio_led6_offset, (value / 32) % 2);
  this->registerWrite(gpio_led7_offset, (value / 64) % 2);
  this->registerWrite(gpio_led8_offset, (value / 128) % 2);
}

void ZedBoard::setLedState(int led_index, int state) {
  int led;

  switch (led_index) {
  case 0:
  	led = gpio_led1_offset;
  	break;
  case 1:
  	led = gpio_led2_offset;
    break;
  case 2:
  	led = gpio_led3_offset;
  	break;
  case 3:
    led = gpio_led4_offset;
    break;
  case 4:
    led = gpio_led5_offset;
    break;
  case 5:
    led = gpio_led6_offset;
    break;
  case 6:
    led = gpio_led7_offset;
    break;
  case 7:
    led = gpio_led8_offset;
    break;
  }

  this->registerWrite(led, state);
}
