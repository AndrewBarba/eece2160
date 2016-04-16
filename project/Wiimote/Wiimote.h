#include "../ZedBoard/ZedBoard.h"

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
   * Start listening for acc events
	 */
	void listen();

	/**
   * Notify of acc event
	 */
	void accelerationEvent(int code, short acc);
};
