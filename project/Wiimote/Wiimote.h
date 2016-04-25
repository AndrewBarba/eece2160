#include "../ZedBoard/ZedBoard.h"

struct AccelerationEvent {
	int code;
	short acc;
};

class Wiimote {

	int fd;

public:

	/**
   * Public constructor
	 */
	Wiimote();

	/**
   * Destructor
	 */
	~Wiimote();

	/**
   * Read an event from accelerometer
	 */
	AccelerationEvent* readAccelerationEvent();
};
