/*
 * IN_OUT.h
 *
 * Created: 1/9/2021 8:59:21 PM
 *  Author: karim
 */ 


#ifndef IN_OUT_H_
#define IN_OUT_H_
/*Macros*/
#include "CPU_CONFIGURATION.h"
/*Buzzer functions*/
void BUZZER_Init(void);
void BUZZER_ON(void);
void BUZZER_OFF(void);
void BUZZER_TGL(void);
/*Relay functions*/
void RELAY_Init(void);
void RELAY_ON(void);
void RELAY_OFF(void);
void RELAY_TGL(void);

#endif /* IN_OUT_H_ */