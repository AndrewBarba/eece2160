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

class ZedBoard {
  char *ptr;
  int fd;

public:

  /**
   * Public constructor
   */
  ZedBoard();

  /**
   * Destructor
   */
  ~ZedBoard();

  /**
   * Set a value to a given register
   *
   * @param {int} offset - Offset where device is mapped
   * @param {int} value - Value to be written
   */
  void registerWrite(int offset, int value);

  /**
   * Read a value from a register
   *
   * @param {int} offset - Offset where device is mapped
   */
  int registerRead(int offset);

  /**
   * Show lower 8 bits of integer value on LEDs
   *
   * @param {int} value - Value to show on LEDs
   */
  void setLedNumber(int value);

  /**
   * Set the state of the LED with the given index.
   *
   * @parem {int} led_index - LED index between 0 and 7
   * @param {int} state - Turn on (1) or off (0)
   */
  void setLedState(int led_index, int state);
};
