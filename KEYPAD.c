/*
 * KEYPAD.c
 *
 * Created: 30/01/2016 06:38:37 م
 *  Author: hossam
 */ 
#include "DIO.h"
#include "KEYPAD.h"

/*Local Symbols*/
#define KPD_COL_PORT 0x80u
#define KPD_ROW_PORT 0x90u
#define KPD_COL_MASK 0x70u
#define KPD_ROW_MASK 0x0fu
#define KPD_COL_PIN_NUM 4u
#define KPD_ROW_PIN_NUM 0u
/**************************************************/
void DIO_vidReadPortData(u8 col_port, u8 col_mask, u8* value_ptr)
{
    *(value_ptr) = (*(value_ptr)) >> KPD_COL_PIN_NUM;
}

void KPD_Init(void)
{
    DIO_vidWritePortDirection(KPD_COL_PORT,KPD_COL_MASK,0x00u);
	DIO_vidWritePortDirection(KPD_ROW_PORT,KPD_ROW_MASK,0xffu);
	DIO_vidWritePortData(KPD_ROW_PORT,KPD_ROW_MASK,0x00u);
	
}
void KPD_ReadVal(unsigned char* ValuePtr)
{
    static const unsigned char KeysLut[]= {'1' , '2' , '3' , '4' , '5' , '6','7' , '8' , '9','*' , '0' , '#'};
    unsigned char Rowdata;
	unsigned char ColData;
	unsigned char LoopTermnate = 0u;
	unsigned char value11;
	for(Rowdata = 0u ; ((Rowdata < 4u) && (LoopTermnate == 0u)) ; Rowdata ++)
	{

	    value11 = ((u8)1u<<Rowdata);
	    value11 = value11 << (KPD_ROW_PIN_NUM);
	    DIO_vidWritePortData(KPD_ROW_PORT, KPD_ROW_MASK, value11);


		DIO_vidReadPortData(KPD_COL_PORT, KPD_COL_MASK, &ColData);
		if(ColData != 0u)
		{
			*ValuePtr = KeysLut[(Rowdata*3u) + (ColData/2u)];
			LoopTermnate = 1u;
		}
		else
		{
			*ValuePtr = 0x6Eu;
		}
	}
}

