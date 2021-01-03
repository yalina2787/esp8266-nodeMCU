#include "Arduino.h"
#include "LianLED.hpp"


#define RED_LED 16 //定义引脚 16 的名称为红灯，相当于定义了红灯为常量
#define BLUE_LED 2


LianLED redLED;  //创建类 LianLED 的实例
LianLED blueLED;

void setup() {
  redLED.attach(RED_LED);
  blueLED.attach(BLUE_LED);

  redLED.write(false);
  redLED.write(false);

  redLED.blink(100, 200);
}

void loop() {
  //redLED.write(true);
  blueLED.update();
  redLED.update();
}
