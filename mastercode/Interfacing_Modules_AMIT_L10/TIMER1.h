/*
 * TIMER1.h
 *
 * Created: 2/12/2021 10:34:05 PM
 *  Author: karim
 */ 


#ifndef TIMER1_H_
#define TIMER1_H_

#include "TIMER1_CONFIG.h"

void TIMER1_FASTPWM_ICR_Init(void);
void TIMER1_FASTPWM_ICR_SETDUTY(Uint8t dutycycle);
void TIMER1_FASTPWM_ICR_START(void);

#endif /* TIMER1_H_ */