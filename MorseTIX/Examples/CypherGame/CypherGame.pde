#include <MorseTIX.h>

MorseTIX morse(9,65,120);

void setup(){
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop() {
  char *theText;
  
  byte x;
  char someLetter;
  char someString[5];
  for(x=0;x<=5;x++) {
     someLetter = random(25) + 65;
     //Serial.println(someLetter);
     someString[x] = someLetter;
  }  
  
  morse.send(someString);
  Serial.println(someString);
  morse.pause(2);
}
