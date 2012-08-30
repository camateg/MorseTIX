#ifndef MorseTIX_H
#define MorseTIX_H

#include "Arduino.h"

class MorseTIX {
public:
	MorseTIX(byte pin, byte duration, byte freq);
	~MorseTIX();
	void dit();
	void dah();
	void send(char *stringToSend);
	void pause(int s);

private:
	void on();
	void off();
	void wspace();
	void lspace();
	byte _pin;
	byte _duration;
	byte _freq;
};

#endif
