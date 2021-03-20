/*
* SEV_SEG.c
*
* Created: 1/15/2021 7:34:10 PM
*  Author: karim
*/
#include "SEV_SEG.h"

void SEVSEG_Init(void)/*Initialization function of the module to define pin direction*/
{
	/*Command port pins*/
	DIO_SetPin_Direction(SEVSEG_CMD_PORT, SEVSEG_EN1, SEVSEG_OUTPUT);
	DIO_SetPin_Direction(SEVSEG_CMD_PORT, SEVSEG_EN2, SEVSEG_OUTPUT);
	/*Data port pins*/
	DIO_SetPin_Direction(SEVSEG_DTA_PORT, SEVSEG_DTA0_A, SEVSEG_OUTPUT);
	DIO_SetPin_Direction(SEVSEG_DTA_PORT, SEVSEG_DTA1_B, SEVSEG_OUTPUT);
	DIO_SetPin_Direction(SEVSEG_DTA_PORT, SEVSEG_DTA2_C, SEVSEG_OUTPUT);
	DIO_SetPin_Direction(SEVSEG_DTA_PORT, SEVSEG_DTA3_D, SEVSEG_OUTPUT);
}
void SEVSEG_ENB1(void)/*Enable first seven segment*/
{
	DIO_SetPin_Value(SEVSEG_CMD_PORT, SEVSEG_EN1, SEVSEG_HIGH);
}
void SEVSEG_DIS1(void)/*Disable first seven segment*/
{
	DIO_SetPin_Value(SEVSEG_CMD_PORT, SEVSEG_EN1, SEVSEG_LOW);
}
void SEVSEG_ENB2(void)/*Enable second seven segment*/
{
	DIO_SetPin_Value(SEVSEG_CMD_PORT, SEVSEG_EN2, SEVSEG_HIGH);
}
void SEVSEG_DIS2(void)/*Disable second seven segment*/
{
	DIO_SetPin_Value(SEVSEG_CMD_PORT, SEVSEG_EN2, SEVSEG_LOW);
}
void SEV_SEG_DISPLAY(Uint8t data)/*Display value from (0 -> 99)*/
{
	/*POV*/
	/*
	19
	10 -> tenth
	9 -> unit
	*/
	int data0 = data % 10;/*First number in units*/
	int data1 = data / 10;/*Second number in tenth*/
	SEVSEG_ENB1();
	SEVSEG_DIS2();
	PORTA = (data0 << 4) | (PORTA & 0x0F);
	_delay_ms(10);
	SEVSEG_DIS1();
	SEVSEG_ENB2();
	PORTA = (data1 << 4) | (PORTA & 0x0F);
	_delay_ms(10);
}