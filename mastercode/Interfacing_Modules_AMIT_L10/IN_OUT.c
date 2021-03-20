/*
* IN_OUT.c
*
* Created: 1/9/2021 8:59:29 PM
*  Author: karim
*/

#include "IN_OUT.h"


/*Buzzer functions*/
void BUZZER_Init(void)
{
	SET_BIT(DDRA, 3);
}
void BUZZER_ON(void)
{
	SET_BIT(PORTA, 3);
}
void BUZZER_OFF(void)
{
	CLR_BIT(PORTA, 3);
}
void BUZZER_TGL(void)
{
	TGL_BIT(PORTA, 3);
}
/*Relay functions*/
void RELAY_Init(void)
{
	SET_BIT(DDRA, 2);
}
void RELAY_ON(void)
{
	SET_BIT(PORTA, 2);
}
void RELAY_OFF(void)
{
	CLR_BIT(PORTA, 2);
}
void RELAY_TGL(void)
{
	TGL_BIT(PORTA, 2);
}