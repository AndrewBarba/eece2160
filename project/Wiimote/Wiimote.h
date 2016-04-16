#include "../ZedBoard/ZedBoard.h"

struct AccelerationEvent {
	int code;
	short acc;
};

class Wiimote {

	int fd;

	ZedBoard *zb;

public:

	/**
   * Public constructor
	 *
	 * @param {ZedBoard} zb - reference to a ZedBoard instance
	 */
	Wiimote(ZedBoard *zb);

	/**
   * Destructor
	 */
	~Wiimote();

	/**
   * Read an event from accelerometer
	 */
	AccelerationEvent readAccelerationEvent();
};
