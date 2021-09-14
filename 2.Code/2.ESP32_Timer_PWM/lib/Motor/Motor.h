#ifndef __MOTOR_H__
#define __MOTOR_H__

#include <Arduino.h>

void Motor_Init(void);
void PWM_SetDuty(uint16_t DutyA, uint16_t DutyB);
void Motor_Control(int Cnt_L, int Cnt_R);
void User_Robot_Task(void *SoccerRobot_Task);

#endif