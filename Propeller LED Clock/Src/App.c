/*
  * App.c

 *
 *  Created on: Sep 26, 2023
 *      Author: user
 */
#include "../Include/LIB/STD_TYPES.h"
#include "../Include/LIB/BIT_MATH.h"
#include <util/delay.h>
#include "../Include/MCAL/DIO/DIO_Private.h"
#include "../Include/MCAL/GI/GI_private.h"
#include "../include/MCAL/TIMERS/TIMERS_Interface.h"
#include "../Include/MCAL/DIO/DIO_Interface.h"

#include "../Include/MCAL/GI/GI_interface.h"
#include "../Include/MCAL/ADC/ADC_Interface.h"
#include <avr/io.h>

#define F_CPU 8000000UL
#define HALL_SENSOR_PIN PA0




volatile unsigned long timer0_millis = 0;


void Timer0_CTC ()
{
    timer0_millis++;
}


u32 millis() {
    u32 m;
    u8 oldSREG = SREG;
    // Disable interrupts while we read timer0
   MGI_voidDisable ();
    m = timer0_millis;
    SREG = oldSREG;

    return m;
}


u16 n,k;
u32 past_time=0;

//starting time

u16 hours=12;
u16 minutes=15;
u16 seconds=0;

int main()
{

 MDIO_voidInit ();
 MTIMER0_voidInit ();
 MGI_voidEnable ();

if (hours == 12)
{
	hours=0;
}
while(1)
 {
 while (PINA & (1 << HALL_SENSOR_PIN));
  if (millis() - past_time >= 1000)
  {
	past_time = millis();
	seconds = seconds +1;
  if (seconds == 60)
	 {
		seconds = 0;
		minutes = minutes +1;
	 }
  if (minutes == 60)
	 {
		minutes = 0;
		hours = hours +1;
	 }
  if (hours == 12)
	 {
		hours = 0;
	 }
  }
  k=30;
  n=0;
  while(n<60)
  {
   SET_BIT(PORTD_REG,PIN7);
   if ((k==0) || (k==5) || (k==10) || (k==15) || (k==20) || (k==25) || (k==30) || (k==35) || (k==40) || (k==45) || (k==50) || (k==55))
   {
	SET_BIT(PORTD_REG,PIN6);
	SET_BIT(PORTD_REG,PIN5);
   }
   if ((k==0) || (k==15) || (k==30) || (k==45))
   {
	   SET_BIT(PORTD_REG,PIN4);
	   SET_BIT(PORTD_REG,PIN3);
   }
   // hours hand
   if((k == hours*5) || (( k == 0 ) && (hours == 0)))
   {
	   SET_BIT(PORTC_REG,PIN7);
	   SET_BIT(PORTC_REG,PIN6);
	   SET_BIT(PORTC_REG,PIN5);
	   SET_BIT(PORTC_REG,PIN4);
	   SET_BIT(PORTC_REG,PIN3);
	   SET_BIT(PORTC_REG,PIN2);
	   SET_BIT(PORTC_REG,PIN1);
   }
   // minutes hand
   if(k == minutes)
   {
	   SET_BIT(PORTC_REG,PIN7);
	   SET_BIT(PORTC_REG,PIN6);
	   SET_BIT(PORTC_REG,PIN5);
	   SET_BIT(PORTC_REG,PIN4);
	   SET_BIT(PORTC_REG,PIN3);
	   SET_BIT(PORTC_REG,PIN2);
	   SET_BIT(PORTC_REG,PIN1);
	   SET_BIT(PORTC_REG,PIN0);
	   SET_BIT(PORTD_REG,PIN0);
   }
   // seconds hand
   if(k == seconds)
   {
	   SET_BIT(PORTC_REG,PIN7);
	   SET_BIT(PORTC_REG,PIN6);
	   SET_BIT(PORTC_REG,PIN5);
	   SET_BIT(PORTC_REG,PIN4);
	   SET_BIT(PORTC_REG,PIN3);
	   SET_BIT(PORTC_REG,PIN2);
	   SET_BIT(PORTC_REG,PIN1);
	   SET_BIT(PORTC_REG,PIN0);
	   SET_BIT(PORTD_REG,PIN0);
	   SET_BIT(PORTD_REG,PIN1);
	   SET_BIT(PORTD_REG,PIN2);
   }
   _delay_us(140);
   MDIO_voidInit();
   SET_BIT(PORTC_REG,PIN7);
   _delay_us(600);
   n++;
   k++;
  }



while (GET_BIT(PORTA_REG,0) == 1);
 }
}




