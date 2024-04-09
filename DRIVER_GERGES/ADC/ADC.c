
#include "../Service/StdTypes.h"
#include "../Service/MemMap.h"
#include "../Service/Bit_Math.h"
#include "ADC.h"



void ADC_Init(ADC_Vref_type vref,ADC_Prescaler_type scaler)
{
	/* clock*/ 
	scaler=scaler&0x07; //00000111
	ADCSRA=ADCSRA&0xf8; //11111000
	ADCSRA=ADCSRA|scaler;
	/* volt ref */
	switch(vref)
	{
		case VREF_AREF:
		Clr_Bit(ADMUX,REFS0);
		Clr_Bit(ADMUX,REFS1);
		break;
		case VREF_AVCC:
		Set_Bit(ADMUX,REFS0);
		Clr_Bit(ADMUX,REFS1);
		break;
		case VREF_256:
		Set_Bit(ADMUX,REFS0);
		Set_Bit(ADMUX,REFS1);
		break;	
	}
	Clr_Bit(ADMUX,ADLAR);
	
	/* ADC ENABLE*/
	Set_Bit(ADCSRA,ADEN);
}

u16 ADC_Read(ADC_Channel_type channel)
{
	/* select ch using mux*/
	ADMUX=(ADMUX&0xE0);
	ADMUX=ADMUX|channel;
	/* start conversion*/
	Set_Bit(ADCSRA,ADSC);
	/*wait until end */
	while(Get_Bit(ADCSRA,ADSC));
	/* get reading from 2 registers*/
	return ADC;
	
}
