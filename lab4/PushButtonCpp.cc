#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
// Physical base address of GPIO
const unsigned gpio_address = 0x400d0000;
// Length of memory-mapped IO window
const unsigned gpio_size = 0xff;
const int gpio_led1_offset = 0x12C; // Offset for LED1
const int gpio_led2_offset = 0x130; // Offset for LED2
const int gpio_led3_offset = 0x134; // Offset for LED3
const int gpio_led4_offset = 0x138; // Offset for LED4
const int gpio_led5_offset = 0x13C; // Offset for LED5
const int gpio_led6_offset = 0x140; // Offset for LED6
const int gpio_led7_offset = 0x144; // Offset for LED7
const int gpio_led8_offset = 0x148; // Offset for LED8
const int gpio_pbtnl_offset = 0x16C; // Offset for left push button
const int gpio_pbtnr_offset = 0x170; // Offset for right push button
const int gpio_pbtnu_offset = 0x174; // Offset for up push button
const int gpio_pbtnd_offset = 0x178; // Offset for down push button
const int gpio_pbtnc_offset = 0x17C; // Offset for center push button

/**
 * Class representing a single ZedBoard. Allows simple read and write operations
 */
class ZedBoard {

  char *ptr;
  int fd;

  public:

    /**
     * Public constructor
     *
     * @param {char} ptr - Base address returned by 'mmap'
     * @param {int} fd - File descriptor passed by reference, where the result of function 'open' will be stored
     */
    ZedBoard(char * ptr, int fd) {
      this->ptr = ptr;
      this->fd = fd;
    }

    /**
     * Destructor
     */
    ~ZedBoard() {
      munmap(this->ptr, gpio_size);
      close(this->fd);
    }

    /**
     * Set a value to a given register
     *
     * @param {int} offset - Offset where device is mapped
     * @param {int} value - Value to be written
     */
    void registerWrite(int offset, int value) {
      * (int *) (this->ptr + offset) = value;
    }

    /**
     * Read a value from a register
     *
     * @param {int} offset - Offset where device is mapped
     */
    int registerRead(int offset) {
      return * (int *) (this->ptr + offset);
    }

    /**
     * Show lower 8 bits of integer value on LEDs
     *
     * @param {int} value - Value to show on LEDs
     */
    void setLedNumber(int value) {
      this->registerWrite(gpio_led1_offset, value % 2);
      this->registerWrite(gpio_led2_offset, (value / 2) % 2);
      this->registerWrite(gpio_led3_offset, (value / 4) % 2);
      this->registerWrite(gpio_led4_offset, (value / 8) % 2);
      this->registerWrite(gpio_led5_offset, (value / 16) % 2);
      this->registerWrite(gpio_led6_offset, (value / 32) % 2);
      this->registerWrite(gpio_led7_offset, (value / 64) % 2);
      this->registerWrite(gpio_led8_offset, (value / 128) % 2);
    }

    /**
     * Set the state of the LED with the given index.
     *
     * @parem {int} led_index - LED index between 0 and 7
     * @param {int} state - Turn on (1) or off (0)
     */
    void setLedState(int led_index, int state) {
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
};

/**
 * Initialize general-purpose I/O
 * - Opens access to physical memory /dev/mem
 * - Maps memory at offset 'gpio_address' into virtual address space
 *
 * @param fd File descriptor passed by reference, where the result
 * of function 'open' will be stored.
 * @return Address to virtual memory which is mapped to physical,
 * or MAP_FAILED on error.
 */
char *Initialize(int *fd) {
  *fd = open( "/dev/mem", O_RDWR);
  return (char *) mmap(
    NULL,
    gpio_size,
    PROT_READ | PROT_WRITE,
    MAP_SHARED,
    *fd,
    gpio_address);
}

int main() {

  // Initialize
  int fd;
  char *ptr = Initialize(&fd);

  // Check error
  if (ptr == MAP_FAILED) {
    perror("Mapping I/O memory failed - Did you run with 'sudo'?\n");
    return -1;
  }

  // Allocate zedboard on the heap
  ZedBoard *zboard = new ZedBoard(ptr, fd);

  int current = 0;
  int up = 0;
  int right = 0;
  int down = 0;
  int left = 0;
  int center = 0;

  while (1) {
    int _up = zboard->registerRead(gpio_pbtnu_offset);
    int _right = zboard->registerRead(gpio_pbtnr_offset);
    int _down = zboard->registerRead(gpio_pbtnd_offset);
    int _left = zboard->registerRead(gpio_pbtnl_offset);
    int _center = zboard->registerRead(gpio_pbtnc_offset);

    if (up != _up) {
      up = _up;
      if (_up == 1) current++;
    }

    if (down != _down) {
      down = _down;
      if (_down == 1) current--;
    }

    if (right != _right) {
      right = _right;
      if (_right == 1) current /= 2;
    }

    if (left != _left) {
      left = _left;
      if (_left == 1) current *= 2;
    }

    if (center != _center) {
      center = _center;
      if (_center == 1) current = 0;
    }

    zboard->setLedNumber(current);
  }

  // Free memory
  delete zboard;

  // Exit cleanly
  return 0;
}
