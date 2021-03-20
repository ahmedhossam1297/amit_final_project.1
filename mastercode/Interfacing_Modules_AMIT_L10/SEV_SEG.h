/*
 * SEV_SEG.h
 *
 * Created: 1/15/2021 7:34:00 PM
 *  Author: karim
 */ 


#ifndef SEV_SEG_H_
#define SEV_SEG_H_
/*
What should i write here!
1- Macros
2- User defined data types (Structure - Union - Enumeration)
3- Global variables (if Exist)
4- Functions prototypes
*/
#include "SEV_SEG_CONFIG.h"
void SEVSEG_Init(void);/*Initialization function of the module to define pin direction*/
void SEVSEG_ENB1(void);/*Enable first seven segment*/
void SEVSEG_DIS1(void);/*Disable first seven segment*/
void SEVSEG_ENB2(void);/*Enable second seven segment*/
void SEVSEG_DIS2(void);/*Disable second seven segment*/
void SEV_SEG_DISPLAY(Uint8t data);/*Display value from (0 -> 99)*/

#endif /* SEV_SEG_H_ */