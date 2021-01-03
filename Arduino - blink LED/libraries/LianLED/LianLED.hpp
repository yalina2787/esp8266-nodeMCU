#include "Arduino.h"

class LianLED{
private:
    int pin;
    long lastMillis;
    int onMillis = 500;
    int offMillis = 1000;
    int status = 0; // 0:off 1:on

public:
    LianLED();
    void attach(int _pin);
    void write(bool on);
    void update();
    void blink(int _onMillis, int _offMillis);
};