﻿/*
 * L3G4200D_Cfg.h
 *
 * Created: 24/09/2015 09:13:50 م
 *  Author: hossam
 */ 


#ifndef L3G4200D_CFG_H_
#define L3G4200D_CFG_H_
#include "Basic_Types.h"
#include "DIO.h"
#include "SPI.h"

#define ON          (1u)

/*SPI Communication Configuration*/
/*#define GYHD_INIT_SLAVE_SELECT() DIO_InitPortDirection(PB,1<<4,1<<4);\
                                DIO_WritePort(PB,1<<4,1<<4) */
void GYHD_Init_Slave_Select(void);

/*
#define GYHD_ACTIVATE_SLAVE_SELECT() DIO_WritePort(PB,~(1<<4),1<<4)
#define GYHD_DEACTIVATE_SLAVE_SELECT() DIO_WritePort(PB,(1<<4),(1<<4))
*/
void GYHD_Activate_Slave_Select(void);
void GYHD_DEActivate_Slave_Select(void);

/*Timeout Management Configuration*/
#define u8USE_DELAY (0x00u)
#define u8USE_TIMER (0x01u)

#define u8TIMEOUT_FUNCTION (u8USE_DELAY)

#if(u8TIMEOUT_FUNCTION == u8USE_DELAY)


/*#define u8START_TIME_OUT_MS(DELAY_MS,FLAG_PTR) _delay_ms(DELAY_MS);\
                                              *(FLAG_PTR) = 0x01
*/
void u8START_Time_Out_MS(u16 delay, u8* flag_ptr);

#else
#define u8START_TIME_OUT_MS(DELAY_MS,FLAG_PTR)
#endif

/*Self Axis Movement Detection Config*/
#define u8SELF_AXIS_MOV  (ON)



#endif /* L3G4200D_CFG_H_ */
