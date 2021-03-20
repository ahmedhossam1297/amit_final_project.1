/*
* Interfacing_Modules_AMIT_L10.c
*
* Created: 1/8/2021 9:48:21 PM
* Author : karim
*/

#include "LED.h"
#include "SPI.h"
#include "UART.h"

/*
extern Uint32t NUM_OVF;
extern Uint32t NUM_CTC;
extern Uint32t INITIAL_VALUE;
*/

int main(void)
{
	UART_Init();
	LED0_Init();
	LED1_Init();
	LED2_Init();
	SPI_Init();
	SPI_SlaveSelect(1);
	char data;
	while (1) /*Super loop - Infinite loop*/
	{	/*	
		if(UART_Receive()=='A')
		{
			SPI_Transmit('A');
			_delay_ms(100);
		}
		else if(UART_Receive()=='B')
		{
			SPI_Transmit('B');
			_delay_ms(100);
		}
		else if(UART_Receive()=='C')
		{
			SPI_Transmit('C');
			_delay_ms(100);
		}
	*/
		
		data = UART_Receive();
		SPI_Transmit(data);
		_delay_ms(250);
		
	}
}
/*
int main(void)
{
	UART_Init();
	LED0_Init();	
	UART_Transmit('B');
	while (1) 
	{
		
		if(UART_Recieve()=='B')
		{
			LED0_TGL();
			_delay_ms(250);
		}
		UART_Transmit('B');
	}
}
*/
/*
ISR(TIMER0_OVF_vect)
{
	static Uint32t cnt = 0;
	cnt++;
	if(cnt == NUM_OVF)
	{
		LED0_ON();
		cnt = 0;
		TCNT0 = INITIAL_VALUE;
	}
}


ISR(TIMER0_COMP_vect)
{
static Uint32t cntr = 0;
cntr++;
if(cntr == NUM_CTC)
{
LED0_TGL();
cntr = 0;
}
}
*/
/*
ISR(INT0_vect)
{
LED0_TGL();
}
*/
/*
#include "LCD.h"
#include "KEYPAD.h"

int main(void)
{
Uint8t btn = 0;
LCD_Init();
KEYPAD_Init();
LCD_WRITE_STR("Welcome");
_delay_ms(250);
LCD_CLEAR();
_delay_ms(100);
while (1)
{
btn = KEYPAD_READ();
if(btn != 0)
{
//LCD_CLEAR();
if(btn == 'C')
{
LCD_CLEAR();
}
else
{
LCD_WRITE_DTA(btn);
_delay_ms(10);
btn = 0;
}
}
}
}

int main(void)
{
Uint16t data = 0;
LCD_Init();
ADC_Init(ADC1);
LCD_WRITE_STR("Welcome");
_delay_ms(1000);
LCD_CLEAR();
while (1)
{
data = ADC_Read();
if(data != 0)
{
LCD_WRITE_NBR(data);
_delay_ms(250);
LCD_CLEAR();
data = 0;
}
}
}
*/

/*
int main(void)
{
LED0_Init();
UART_Init();
UART_Transmit('a');
while (1)
{

if(UART_Receive() == 'a')
{
LED0_TGL();
_delay_ms(250);
}
UART_Transmit('a');
}
}

*/