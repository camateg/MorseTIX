#include <MorseTIX.h>

MorseTIX morse(9,40,100);

void setup(){}

void loop() {
  morse.send("SOS SOS");
  morse.pause(3);
}
