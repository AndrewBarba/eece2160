
class Wiimote {
	int fd;

public:

	Wiimote();

	void listen();

	virtual void accelerationEvent(int code, short acc);

	~Wiimote();
};
