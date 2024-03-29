﻿#include "Basic_Types.h"
#include "BLMGR.h"
#include "UART_Drv.h"
#include "UART_LCFG.h"
#include "PWM.h"
#include "GPT.h"

u32 main(void)
{
    u32 Count= 0u;
    u32 start = 0u;
    u32 Count2 = 0u;
 


GPT_Timer30msInit(&Cyclic30ms);
    
    BLMGR_BluetoothInit();
    BLMGR_SetReceiver(ROLE_MAPP);


    PWM_Init();
    sei();
    PWM_SetSpeed(25u);


    while(1)
    {
        Count2 = (Count2 + 1u) % (20u);
        Count2 /= (4u);
        BLMGR_SetBattLevel((u8)Count2);

        _delay_ms(100u);
        Count ++;
        if(start == 0u)
        {
                    if(Count > 5u)
                    {
                        BLMGR_StartDevice();

                        start = 1u;
                    }
        }
    }
}


void Cyclic30ms(void)
{
	static u8 TimeoutCounter = 0u;
	TimeoutCounter ++;
	if(TimeoutCounter == 10u)
	{
		BLMGR_BluetoothStateMachine();
		TimeoutCounter = 0u;
		
		
	}
}
