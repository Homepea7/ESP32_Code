#include <Arduino.h>
#include "Motor.h"

/*
 * LEDC Chan to Group/Channel/Timer Mapping
** ledc: 0  => Group: 0, Channel: 0, Timer: 0
** ledc: 1  => Group: 0, Channel: 1, Timer: 0
** ledc: 2  => Group: 0, Channel: 2, Timer: 1
** ledc: 3  => Group: 0, Channel: 3, Timer: 1
** ledc: 4  => Group: 0, Channel: 4, Timer: 2
** ledc: 5  => Group: 0, Channel: 5, Timer: 2
** ledc: 6  => Group: 0, Channel: 6, Timer: 3
** ledc: 7  => Group: 0, Channel: 7, Timer: 3
** ledc: 8  => Group: 1, Channel: 0, Timer: 0
** ledc: 9  => Group: 1, Channel: 1, Timer: 0
** ledc: 10 => Group: 1, Channel: 2, Timer: 1
** ledc: 11 => Group: 1, Channel: 3, Timer: 1
** ledc: 12 => Group: 1, Channel: 4, Timer: 2
** ledc: 13 => Group: 1, Channel: 5, Timer: 2
** ledc: 14 => Group: 1, Channel: 6, Timer: 3
** ledc: 15 => Group: 1, Channel: 7, Timer: 3
*/

// 绑定的IO
const int Motor_PWM_PinA = 5;
const int Motor_PWM_PinB = 4;
const int Motor_INA1 = 19;
const int Motor_INA2 = 18;
const int Motor_INB1 = 16;
const int Motor_INB2 = 17;

// PWM的通道，共16个(0-15)，分为高低速两组，
// 高速通道(0-7): 80MHz时钟，低速通道(8-15): 1MHz时钟
// 0-15都可以设置，只要不重复即可，参考上面的列表
// 如果有定时器的使用，千万要避开!!!
const int Motor_channel_PWMA = 2;
const int Motor_channel_PWMB = 3;

// PWM频率，直接设置即可
int Motor_freq_PWM = 1000;

// PWM分辨率，取值为 0-20 之间，这里填写为10，那么后面的ledcWrite
// 这个里面填写的pwm值就在 0 - 2的10次方 之间 也就是 0-1024
int Motor_resolution_PWM = 10;

void Motor_Init(void)
{
    pinMode(Motor_INA1, OUTPUT);
    pinMode(Motor_INA2, OUTPUT);
    pinMode(Motor_INB1, OUTPUT);
    pinMode(Motor_INB2, OUTPUT);
    ledcSetup(Motor_channel_PWMA, Motor_freq_PWM, Motor_resolution_PWM); // 设置通道
    ledcSetup(Motor_channel_PWMB, Motor_freq_PWM, Motor_resolution_PWM); // 设置通道
    ledcAttachPin(Motor_PWM_PinA, Motor_channel_PWMA);                   //将 LEDC 通道绑定到指定 IO 口上以实现输出
    ledcAttachPin(Motor_PWM_PinB, Motor_channel_PWMB);
}

void PWM_SetDuty(uint16_t DutyA, uint16_t DutyB)
{
    ledcWrite(Motor_channel_PWMA, DutyA);
    ledcWrite(Motor_channel_PWMB, DutyB);
}

// 电机的控制程序，分别是左右两个轮子的占空比（0-1024）
void Motor_Control(int Cnt_L, int Cnt_R)
{
    if (Cnt_L >= 0) // 左轮正向转
    {
        digitalWrite(Motor_INA1, HIGH);
        digitalWrite(Motor_INA2, LOW);
        ledcWrite(Motor_channel_PWMA, Cnt_L);
    }
    else // 左轮反向转
    {
        digitalWrite(Motor_INA1, LOW);
        digitalWrite(Motor_INA2, HIGH);
        ledcWrite(Motor_channel_PWMA, -Cnt_L);
    }

    if (Cnt_R >= 0) // 右轮正向转
    {
        digitalWrite(Motor_INB1, HIGH);
        digitalWrite(Motor_INB2, LOW);
        ledcWrite(Motor_channel_PWMB, Cnt_R);
    }
    else // 右轮反向转
    {
        digitalWrite(Motor_INB1, LOW);
        digitalWrite(Motor_INB2, HIGH);
        ledcWrite(Motor_channel_PWMB, -Cnt_R);
    }
}
