/*
 * TIMER1.c
 *
 * Created: 2/12/2021 10:33:48 PM
 *  Author: karim
 */ 
#include "TIMER1.h"


void TIMER1_FASTPWM_ICR_Init(void)
{
	/*Define direction for OC1 pin*/
	SET_BIT(DDRD, 5);
	/*Choose mode of operation*/
	SET_BIT(TCCR1B, WGM13);SET_BIT(TCCR1A, WGM12);SET_BIT(TCCR1A, WGM11);CLR_BIT(TCCR1A, WGM10);
	/*Choose non inverting mode*/
	SET_BIT(TCCR1A, COM1A1);CLR_BIT(TCCR1A, COM1A0);
	/*Change new top*/
	ICR1 = 1250;
}
void TIMER1_FASTPWM_ICR_SETDUTY(Uint8t dutycycle)
{
	OCR1A = ((dutycycle * 1250) / 100) - 1;
}
void TIMER1_FASTPWM_ICR_START(void)
{
	/*Choose prescaler 256*/
	SET_BIT(TCCR1B, CS12);CLR_BIT(TCCR1B, CS11);CLR_BIT(TCCR1B, CS10);
}