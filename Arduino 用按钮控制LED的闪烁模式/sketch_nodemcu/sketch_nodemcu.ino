#include "Arduino.h"
#include "LianLED.hpp"


#define RED_LED 16 //定义引脚 16 的名称为红灯，相当于定义了红灯为常量
#define BLUE_LED 2
#define BUTTON 0 //Flash按钮，默认不接地（HIGH），按下后接地（LOW）


LianLED redLED;  //创建类 LianLED 的实例
LianLED blueLED;

int modeId = 0;
int lastButtonStatus = HIGH;

void setup() {
  pinMode(BUTTON, INPUT);
  redLED.attach(RED_LED);
  blueLED.attach(BLUE_LED);

  redLED.write(false);
  blueLED.write(false);

  //redLED.blink(100, 200);
}

void loop() {
  int button = digitalRead(BUTTON);
  if(lastButtonStatus == HIGH && button == LOW) { // 上次没按下， 这次按下
    modeId = (modeId + 1) % 4;
  }
  lastButtonStatus = button;
  
  blueLED.update();
  redLED.update();
  /*
  if (button == HIGH){
    redLED.blink(100, 200);
    blueLED.write(false);
  } else{
    redLED.blink(500, 2000);
    blueLED.write(true);
  }*/

  if(modeId == 0) {
    redLED.write(false);
    blueLED.write(false);
  } else if(modeId == 1) {
    redLED.blink(100, 200);
    blueLED.blink(100, 200);
  } else if(modeId == 2) {
    redLED.blink(500, 100);
    blueLED.blink(100, 500);
  } else if(modeId == 3) {
    redLED.blink(50, 50);
    blueLED.blink(50, 50);
  }
}
