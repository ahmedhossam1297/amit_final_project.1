/*
* SEV_SEG_CONFIG.h
*
* Created: 1/15/2021 7:33:50 PM
*  Author: karim
*/


#ifndef SEV_SEG_CONFIG_H_
#define SEV_SEG_CONFIG_H_

/*
What should i do here !
1- Macros needed
2- Renaming of ports needed
3- Renaming of pins needed
4- States
*/
#include "CPU_CONFIGURATION.h"

/*Renaming for ports*/
#define SEVSEG_CMD_PORT     DIO_PORTB
#define SEVSEG_DTA_PORT     DIO_PORTA
/*Renaming for pins*/
#define SEVSEG_EN1          DIO_PIN1
#define SEVSEG_EN2          DIO_PIN2

#define SEVSEG_DTA0_A       DIO_PIN4
#define SEVSEG_DTA1_B       DIO_PIN5
#define SEVSEG_DTA2_C       DIO_PIN6
#define SEVSEG_DTA3_D       DIO_PIN7

#define SEVSEG_OUTPUT       DIO_PIN_OUTPUT
#define SEVSEG_HIGH         DIO_PIN_HIGH
#define SEVSEG_LOW          DIO_PIN_LOW
#endif /* SEV_SEG_CONFIG_H_ */