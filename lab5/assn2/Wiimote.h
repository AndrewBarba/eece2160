
class Wiimote {
	int fd;

public:

	Wiimote();

	void listen();

	void buttonEvent(int code, int value);

	~Wiimote();
};
 
