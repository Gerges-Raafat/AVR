
#ifndef ADC_H_
#define ADC_H_

#define  REFS0		7
#define  REFS1		8
#define  ADEN       8
#define  ADSC       7
#define ADLAR		5

#define ADMUX		(*(volatile u8*)0x27)
#define ADCSRA		(*(volatile u8*)0x26)
#define ADCH        (*(volatile u8*)0x25)
#define ADCL        (*(volatile u8*)0x24)
#define ADC			(*(volatile u8*)0x28)


typedef enum{
	VREF_AREF,
	VREF_AVCC,
	VREF_256	
	}ADC_Vref_type;

typedef enum{
	CH_0=0,
	CH_1,
	CH_2,
	CH_3,
	CH_4,
	CH_5,
	CH_6,
	CH_7
}ADC_Channel_type;

typedef enum{
	ADC_SCALER_2=1,
	ADC_SCALER_4,
	ADC_SCALER_8,
	ADC_SCALER_16,
	ADC_SCALER_32,
	ADC_SCALER_64,
	ADC_SCALER_128,
}ADC_Prescaler_type;

void ADC_Init(ADC_Vref_type vref,ADC_Prescaler_type scaler);
u16 ADC_Read(ADC_Channel_type ch);



#endif /* ADC_H_ */