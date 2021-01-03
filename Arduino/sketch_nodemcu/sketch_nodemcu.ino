#include "Arduino.h"
#include "LianLED.hpp"


#define RED_LED 16
#define BLUE_LED 2


LianLED redLED;
LianLED blueLED;

void setup() {
  redLED.attach(RED_LED);
  blueLED.attach(BLUE_LED);
}

void loop() {
  redLED.write(true);
  blueLED.write(false);
}
