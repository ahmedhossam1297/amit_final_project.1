/*
* TIMER0.c
*
* Created: 2/6/2021 8:41:30 PM
*  Author: karim
*/

#include "TIMER0.h"

Uint32t NUM_OVF = 0;
Uint32t NUM_CTC = 0;
Uint32t INITIAL_VALUE = 0;

void TIMER0_INIT(void)
{
	/*Choose mode of operation*/
	#if WAVE_GENERATION_MODE == NORMAL_MODE
	CLR_BIT(TCCR0, WGM01);CLR_BIT(TCCR0, WGM00);
	#elif WAVE_GENERATION_MODE == CTC_MODE
	SET_BIT(TCCR0, WGM01);CLR_BIT(TCCR0, WGM00);
	#endif
	/*Enable peripheral interrupt*/
	//SET_BIT(TIMSK, TOIE0);
	SET_BIT(TIMSK, OCIE0);
	/*Enable Global interrupt*/
	sei();
	//SET_BIT(SREG, 7);
}
void TIMER0_START(void)
{
	#if TIMER0_PRESCALER == PRE_CLK1024
	SET_BIT(TCCR0, CS02);CLR_BIT(TCCR0, CS01);SET_BIT(TCCR0, CS00);
	#endif
}
void TIMER0_STOP(void)
{
	/*
	TICK = 1 * P / Fosc
	if P = 0
	Tick = 0
	*/
	CLR_BIT(TCCR0, CS02);CLR_BIT(TCCR0, CS01);CLR_BIT(TCCR0, CS00);
}
void TIMER0_OVF_SETDELAY(Uint32t delay)
{
	#if WAVE_GENERATION_MODE == NORMAL_MODE
	Uint8t Tick = (1 * 1024) / 16;
	Uint32t Total_Tick = (delay * 1000) / Tick;
	NUM_OVF = Total_Tick / 256;
	INITIAL_VALUE = 256 - (Total_Tick % 256);
	TCNT0 = INITIAL_VALUE;
	NUM_OVF++;//Round-up
	#endif
}
void TIMER0_CTC_SETDELAY(Uint32t delay, Uint8t ocr)
{
	Uint8t Tick = (1 * 1024) / 16;
	Uint32t Total_Tick = (delay * 1000) / Tick;
	OCR0 = ocr;
	NUM_CTC = Total_Tick / OCR0;
	NUM_CTC++;//Round-up
}
void TIMER0_FASTPWM_Init(void)
{
	/*Define direction*/
	SET_BIT(DDRB, PB3);
	/*Choose fast PWM mode wave generation*/
	SET_BIT(TCCR0, WGM01);SET_BIT(TCCR0, WGM00);
	/*Choose inverting or non inverting*/
	#if PWM_MODE == NON_INVERTING
	SET_BIT(TCCR0, COM01);CLR_BIT(TCCR0, COM00);
	#elif PWM_MODE == INVERTING
	SET_BIT(TCCR0, COM01);SET_BIT(TCCR0, COM00);
	#else
	#warning "Wrong Mode"
	#endif
}
void TIMER0_FASTPWM_START(void)
{
	SET_BIT(TCCR0, CS02);CLR_BIT(TCCR0, CS01);CLR_BIT(TCCR0, CS00);
}
void TIMER0_FASTPWM_SETDUTY(Uint8t dutycycle)
{
	/*Choose inverting or non inverting*/
	#if PWM_MODE == NON_INVERTING
	OCR0 = ((256 * dutycycle) / 100) - 1;
	#elif PWM_MODE == INVERTING
	OCR0 = 256 - (((256 * dutycycle) / 100) - 1);
	#else
	#warning "Wrong Mode"
	#endif
}