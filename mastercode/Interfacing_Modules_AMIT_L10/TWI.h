/*
* TWI.h
*
* Created: 2/20/2021 8:57:04 PM
*  Author: karim
*/


#ifndef TWI_H_
#define TWI_H_

#include "TWI_CONFIG.h"

void TWI_MASTER_Init(void);
void TWI_SLAVE_Init(void);

void TWI_START_Condition(void);
void TWI_RESTART_Condition(void);

void TWI_SLAVE_WRITE_Data(Uint8t address);
void TWI_SLAVE_READ_Data(Uint8t address);

void TWI_TRANSMIT_Data(Uint8t data);
Uint8t TWI_RECEIVE_Data(void);

void TWI_STOP_Condition(void);

#endif /* TWI_H_ */