

#define F_CPU 8000000
#include <util/delay.h>
#include "../LCD/LCD_Interface.h"
#include "../KeyPad/KeyPad_Interface.h"
#include "../DIO/DIO_Interface.h"
#define TCCR0	     (*(volatile unsigned char*)0x53)
#define TCNT0	     (*(volatile unsigned char*)0x52)
#define OCR0	     (*(volatile unsigned char*)0x5C)
#define TIMSK        (*(volatile unsigned char*)0x59)
#define SREG_REG     (*(volatile unsigned char*)0x5F)
#define TIFR         (*(volatile unsigned char*)0x58)
#define DDRB         (*(volatile unsigned char*)0x37)
#include "../ADC/ADC.h"
int main(void)
{
	u8 key;
	DIO_Init();
	LCD_Init();
	ADC_Init(VREF_AVCC,ADC_SCALER_64);
	
    while (1) 
    {
		
			key=ADC_Read(CH_0);
			LCD_WriteNumber(key);
	
    }
}

