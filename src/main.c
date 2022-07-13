/*
 * main.c
 *
 *  Created on: Sep 5, 2021
 *      Author: Lenovo
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "STK_interface.h"
#include "NVIC_interface.h"
#include "ADC_interface.h"
#include "ADC_private.h"
volatile f32 VoltageInmv =0;
volatile f32 Current =0 ;
volatile DData ;
volatile u32 status = 0 , timing ;
void Task ()
{}
	void Task1 ( u16 Data )
	{
		if (status ==  0)
			{
				MSTK_voidSetIntervalSingle(100000 , Task );
				status = 1;}
			else
			{
			timing  = 	MSTK_u32GetElapsedTime();
			MSTK_voidStopTimer();
			status = 0 ;}
		VoltageInmv =     ((Data * 3.3 ) / (4096))*1000 - 1650.0 ;
	    Current 		 =     VoltageInmv / 20.0 ;}
	void main (void){
		/*	initialize clocks */
		RCC_voidInitSysClock();
		RCC_voidEnableClock(RCC_APB2 , 2);
		RCC_voidEnableClock(RCC_APB2 , 9);
		/*	initialize pins direction */
		DIO_voidSetPinDirection(PORTA , PIN0 , INPUT_ANALOG);
		/*	initialize other peripherals */
		NVIC_voidEnableInterrupt(18);
		MADC1_voidInit();
		MADC1_voidEnableInterrupt(Task1);
		while (1)
		{}}



	void ADC1_2_IRQHandler (void)
	{
//		CallBack ((u16)(MADC1 -> DR));
		DData = (u16)(MADC1 -> DR) ;
		if (status ==  0)
			{
				MSTK_voidSetIntervalSingle(100000 , Task );
				status = 1;
			}
			else
			{
			timing  = 	MSTK_u32GetElapsedTime();
			MSTK_voidStopTimer();
			status = 0 ;
			}

		VoltageInmv =     ((DData * 3.3 ) / (4096))*1000 - 1650.0 ;
	    Current 		 =     VoltageInmv / 20.0 ;
	    asm("NOP");
	}
