
#include <Arduino.h>
#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

void setup()
{
    Serial.begin(115200);
    SerialBT.begin("Homepea"); // 如果没有参数传入则默认是蓝牙名称是: "ESP32"
    SerialBT.setPin("1234");   // 蓝牙连接的配对码
    Serial.printf("BT initial ok and ready to pair. \r\n");
}

void loop()
{
    if (Serial.available())
    {
        SerialBT.write(Serial.read());
    }
    if (SerialBT.available())
    {
        Serial.write(SerialBT.read());
    }
    delay(1);
}