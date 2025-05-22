/*
 * ADC_Program.c
 *
 *  Created on: Oct 6, 2023
 *      Author: user
 */

#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"

#include "../Include/MCAL/ADC/ADC_Interface.h"
#include "../Include/MCAL/ADC/ADC_Private.h"
#include "../Include/MCAL/ADC/ADC_Cfg.h"

void MADC_voidInit (void)
{
	// Select AVCC with external capacitor at AREF
	SET_BIT(ADMUX,6);
	CLR_BIT(ADMUX,7);

	//RIGHT Adjustment
	CLR_BIT(ADMUX,5);
	//Disable Auto Trigger
	SET_BIT(ADCSRA,5);
	//Select CLK/64
	CLR_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);
	//ENABLE ADC
	SET_BIT(ADCSRA,7);
}

u16 MADC_u16GetDigitalValue(ADC_CHANNELS A_AdcChannel)
{
	u16 local_u16DigitalValue =0;
	if (A_AdcChannel < 32)
	{
	//Clear the channel 5-bits
	ADMUX &= ADC_CHANNEL_MASK;
	//Select channel
	ADMUX |= A_AdcChannel;
	//Start conversion
	SET_BIT(ADCSRA,6);
	//Polling on ADC complete flag
	while(GET_BIT(ADCSRA,4) == 0);
	//clear INT, flag
	SET_BIT(ADCSRA,4);
	// Read conversion
	local_u16DigitalValue = ADCLH;
	}
	return local_u16DigitalValue;
}
