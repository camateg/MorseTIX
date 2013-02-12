#include <MorseTIX.h>

MorseTIX morse(9,60,100,'d');

void setup(){}

void loop() {
  morse.send("CQ CQ CQ DE KB3TIX K");
  morse.pause(3);
}
