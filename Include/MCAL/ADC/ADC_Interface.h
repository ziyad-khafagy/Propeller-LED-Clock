/*
 * ADC_Interface.h
 *
 *  Created on: Oct 6, 2023
 *      Author: user
 */

#ifndef INCLUDE_MCAL_ADC_ADC_INTERFACE_H_
#define INCLUDE_MCAL_ADC_ADC_INTERFACE_H_

typedef enum{
 ADC0,
 ADC1,
 ADC2,
 ADC3,
 ADC4,
 ADC5,
 ADC6,
 ADC7,
 ADC_0_0_10,
 ADC_1_0_10,
 ADC_0_0_200,
 ADC_1_0_200,
 ADC_2_2_10,
 ADC_3_2_10,
 ADC_2_2_200,
 ADC_3_2_200
}ADC_CHANNELS;

u16 MADC_u16GetDigitalValue (ADC_CHANNELS A_AdcChannel);
void MADC_voidInit (void);

#endif /* INCLUDE_MCAL_ADC_ADC_INTERFACE_H_ */
