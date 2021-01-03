#include "LianLED.hpp"

// 构造函数，初始化成员属性
LianLED::LianLED()
{
    // 初始化引脚pin为255，表示未绑定具体引脚
    pin = 255;
    lastMillis = millis();
}

// 绑定引脚函数, 输入参数为_pin，表示引脚编号（一般为0～32）
void LianLED::attach(int _pin)
{
    // 更新私有属性pin，以备后面需要
    pin = _pin;
    // 设置引脚模式为输出
    pinMode(pin, OUTPUT);
}

// 写LED状态，输入参数为on，表示LED是亮（true）还是熄灭（false）
void LianLED::write(bool on)
{
    if(pin != 255)
    {
        if(on)
        {
            // 写已绑定的引脚为LOW（亮）
            digitalWrite(pin, LOW);
        }
        else
        {
            // 写已绑定的引脚为HIGH（暗）
            digitalWrite(pin, HIGH);
        }
    }
}

void LianLED::update()
{
    long currMillis = millis();
    long duration = currMillis - lastMillis;

    if(status == 0) {
        if(duration >= offMillis) {
            status = 1;
            write(true);
            lastMillis = currMillis;
        }
    } else {
        if(duration >= onMillis) {
            status = 0;
            write(false);
            lastMillis = currMillis;
        }
    }
}

void LianLED::blink(int _onMillis, int _offMillis) {
    onMillis = _onMillis;
    offMillis = _offMillis;
}