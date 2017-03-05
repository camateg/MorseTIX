MorseTIX
========

An Arduino library to aid in sending Morse code.

Usage:

    #include <MorseTIX.h>
    # byte pin: which pin to output
    # byte duration: dit duration in ms
    # byte frequency: analog frequency to output
    # char mode: 'a' for analog, 'd' for digital

    MorseTIX morse(pin,duration,freqeuncy,mode);

    void setup(){}

    void loop() {
      morse.send("SOS SOS");
      morse.pause(3);
    }
