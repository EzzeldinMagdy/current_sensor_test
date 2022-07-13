/******************************************************************************************/
/* Auther    : Ezzeldin magdy                                                             */
/* Version   : V01                                                                        */
/* Date      : 29 / 7 / 2021                                                              */
/******************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void RCC_voidEnableClock (u8 copy_u8BusId , u8 copy_u8PerId)
{
	if(copy_u8PerId <= 31)
	{
		switch (copy_u8BusId)
		{
			case RCC_AHB   : SET_BIT(RCC_AHBENR,copy_u8PerId);  break;
			case RCC_APB1  : SET_BIT(RCC_APB1ENR,copy_u8PerId); break;
			case RCC_APB2  : SET_BIT(RCC_APB2ENR,copy_u8PerId); break;
		/*  default    : return error                       break; */
		
		}   
	}       
	else    
	{       
		/* return error */
	}      
}           
void RCC_voidDisableClock (u8 copy_u8BusId , u8 copy_u8PerId)
{
	if(copy_u8PerId <= 31)
	{
		switch (copy_u8BusId)
		{
			case RCC_AHB   : CLR_BIT(RCC_AHBENR,copy_u8PerId);  break;
			case RCC_APB1  : CLR_BIT(RCC_APB1ENR,copy_u8PerId); break;
			case RCC_APB2  : CLR_BIT(RCC_APB2ENR,copy_u8PerId); break;
		/*  default    : return error                       break; */
		
		}   
	}       
	else    
	{       
		/* return error */
	}    	
}        
void RCC_voidInitSysClock (void)
{

		RCC_CFGR |= 0X00000000 ;

		RCC_CR   = 0X01000000 ; /* Enable PLL */
				RCC_CFGR = 0X00000002 ; /* PLL selected as system clock */


					 
}
