#include "Arduino.h"
#include "MorseTIX.h"

#define LED_OUT 13

char morseLib[48][6] = {
                        { 1,2,0,0,0,0 }, //a
                        { 2,1,1,1,0,0 }, //b
                        { 2,1,2,1,0,0 }, //c
                        { 2,1,1,0,0,0 }, //d
                        { 1,0,0,0,0,0 }, //e
                        { 1,1,2,1,0,0 }, //f
                        { 2,2,1,0,0,0 }, //g
                        { 1,1,1,1,0,0 }, //h
                        { 1,1,0,0,0,0 }, //i
                        { 1,2,2,2,0,0 }, //j
                        { 2,1,2,0,0,0 }, //k
                        { 1,2,1,1,0,0 }, //l
                        { 2,2,0,0,0,0 }, //m
                        { 2,1,0,0,0,0 }, //n
                        { 2,2,2,0,0,0 }, //o
                        { 1,2,2,1,0,0 }, //p
                        { 2,2,1,2,0,0 }, //q
                        { 1,2,1,0,0,0 }, //r
                        { 1,1,1,0,0,0 }, //s
                        { 2,0,0,0,0,0 }, //t
                        { 1,1,2,0,0,0 }, //u
                        { 1,1,1,2,0,0 }, //v
                        { 1,2,2,0,0,0 }, //w
                        { 2,1,1,2,0,0 }, //x
                        { 2,1,2,2,0,0 }, //y
                        { 2,2,1,1,0,0 }, //z

                        { 0,0,0,0,0,0 }, // <space>

                        { 1,1,1,1,1,0 }, //0
                        { 1,2,2,2,2,0 }, //1
                        { 1,1,2,2,2,0 }, //2
                        { 1,1,1,2,2,0 }, //3
                        { 1,1,1,1,2,0 }, //4
                        { 1,1,1,1,1,0 }, //5
                        { 2,1,1,1,1,0 }, //6
                        { 2,2,1,1,1,0 }, //7
                        { 2,2,2,1,1,0 }, //8
                        { 2,2,2,2,1,0 }, //9
                   };


MorseTIX::MorseTIX(byte pin, byte duration, byte freq, char mode)
{
	pinMode(pin,OUTPUT);
	pinMode(LED_OUT, OUTPUT);
	_pin = pin;
	_duration = duration;
	_freq = freq;
	_mode = mode;
}

void MorseTIX::on()
{
	if(_mode == 'a') {
		analogWrite(_pin, _freq);
	} else {
		digitalWrite(_pin, HIGH);
	}
	digitalWrite(LED_OUT, HIGH);
}

void MorseTIX::off()
{
	if(_mode == 'a') {
		analogWrite(_pin, 0);
	} else {
		digitalWrite(_pin, LOW);
	}
	digitalWrite(LED_OUT, LOW);
}


void MorseTIX::lspace() {
  delay(_duration * 2.5);
}

void MorseTIX::wspace() {
  delay(_duration * 7);
}

void MorseTIX::dit()
{
	on();
	delay(_duration);
	off();
	delay(_duration);
}

void MorseTIX::dah()
{
	on();
	delay(_duration * 5);
	off();
	delay(_duration);
}

void MorseTIX::pause(int s)
{
	delay(s * 1000);
}
void MorseTIX::send(char* t)
{
        int x;
        byte y;
	int tl = strlen(t);
        for(x=0;x<tl;x++) {
                char charNo = t[x];
                char offset;

                if(charNo == 32) {
                        offset = 0;
                        wspace();
                } else if (charNo >= 65 && charNo <= 90) {
                        offset = 65;
                } else if (charNo >= 48 && charNo <= 57) {
                        offset = 21;
                }

                if(offset) {
                  for(y=0;y<6;y++) {
                          if(morseLib[charNo-offset][y] == 1) {
                                  dit();
                          } else if (morseLib[charNo-offset][y] == 2) {
                                  dah();
                          }
                          lspace();
                  }
               }
        }

}






/*
 *	Destructor
 */

MorseTIX::~MorseTIX()
{

}
