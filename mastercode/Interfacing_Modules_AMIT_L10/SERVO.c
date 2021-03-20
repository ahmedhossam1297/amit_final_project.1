/*
* SERVO.c
*
* Created: 2/19/2021 8:55:41 PM
*  Author: karim
*/

#include "SERVO.h"

void SERVO_Init(void)
{
	TIMER1_FASTPWM_ICR_Init();
	TIMER1_FASTPWM_ICR_START();
}
void SERVO_ANGLE(Uint8t angle)
{
	TIMER1_FASTPWM_ICR_SETDUTY(angle);
}