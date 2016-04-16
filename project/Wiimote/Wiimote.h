#include "../ZedBoard/ZedBoard.h"

class Wiimote {

	int fd;

public:

	ZedBoard *zb;

	Wiimote(ZedBoard *zb);

	void listen();

	virtual void accelerationEvent(int code, short acc);

	~Wiimote();
};
