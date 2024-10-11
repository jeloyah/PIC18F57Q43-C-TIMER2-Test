#include <xc.h>
#include "timer2.h"

/* Config Timer2 */
void TIMER2_Initialize(void)
{
	/* Timer2 disabled; prescaler=1:128; no postscaler */
	T2CON = 0x70;
    
    /* Fosc/4 as source clock (16 MHz)*/
	T2CLKCON = 0x01;   
}

void TIMER2_Delay(void)
{
    
    /* Timer2 counter start at 0x00h and end at 0xFF*/
    
    /* Timer2 enabled */
	T2CON |= 0x80; 
                 
    /* Wait for TMR2IF = 1 */
    while ((PIR3 & 0x08) != 0x08)
          ;
        
    /* Clear TMR2IF bit */
    PIR3 &= 0xF7;
             
    /* Timer2 disabled */
	T2CON &= 0x7F;
}