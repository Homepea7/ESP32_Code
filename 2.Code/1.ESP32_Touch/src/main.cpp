#include <Arduino.h>

// 定义外部中断的Mode
// 0: 无中断，读取Touch值
// 1：Touch中断，执行 TouchEvent()
// 2: 外部IO的中断
#define EXT_ISR_MODE 2

void TouchEvent()
{
    Serial.printf("Touch Event.\r\n");
}

void PinIntEvent()
{
    Serial.printf("PinInt Event.\r\n");
}

void setup()
{
    // put your setup code here, to run once:
    Serial.begin(115200);

#if 1 == EXT_ISR_MODE
    // Pin: T0(GPIO4), 函数指针:TouchEvent, 阈值: 40
    touchAttachInterrupt(T0, TouchEvent, 40);

#elif 2 == EXT_ISR_MODE
    pinMode(0, INPUT_PULLUP);
    attachInterrupt(0, PinIntEvent, FALLING);

#endif
}

void loop()
{
    // put your main code here, to run repeatedly:

#if 0 == EXT_ISR_MODE
    Serial.printf("touch:%d\r\n", touchRead(T0));
#endif

    delay(200);
}