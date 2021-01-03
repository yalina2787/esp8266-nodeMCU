#include "Arduino.h"

class LianLED{
private:
    int pin;
public:
    LianLED();
    void attach(int _pin);
    void write(bool on);
};