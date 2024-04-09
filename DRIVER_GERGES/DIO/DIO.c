

#include "../Servies/StdTypes.h"
#include "../Servies/MemMap.h"

#include "DIO_Interface.h"
#include "DIO_Private.h"
#include "../Servies/Bit_Math.h"

void DIO_Init(void)
{
	DIO_Pin_type i;
	for (i=PINA0;i<TOTAL_PINS;i++)
	{
		DIO_InitPin(i,PinsStatusArray[i]);
	}
}



static void DIO_InitPin(DIO_Pin_type pin,DIO_PinStatus_type status)
{
	DIO_Port_type port =pin/8;
	u8 pin_num=pin%8;
	
	switch(status)
	{
		case OUTPUT:
		switch(port)
		{
			case PA:
			Set_Bit( DDRA,pin_num);
			Clr_Bit(PORTA,pin_num);
			break;
			case PB:
			Set_Bit( DDRB,pin_num);
			Clr_Bit(PORTB,pin_num);
			break;
			case PC:
			Set_Bit( DDRC,pin_num);
			Clr_Bit(PORTC,pin_num);
			break;
			case PD:
			Set_Bit( DDRD,pin_num);
			Clr_Bit(PORTD,pin_num);
			break;		
		}
		break;
		case INFREE:
		switch(port)
		{
			case PA:
			Clr_Bit(DDRA,pin_num);
			Clr_Bit(PORTA,pin_num);
			break;
			case PB:
			Clr_Bit(DDRB,pin_num);
			Clr_Bit(PORTB,pin_num);
			break;
			case PC:
			Clr_Bit(DDRC,pin_num);
			Clr_Bit(PORTC,pin_num);
			break;
			case PD:
			Clr_Bit(DDRD,pin_num);
			Clr_Bit(PORTD,pin_num);
			break;
		}
		break;
		
		case INPULL:
		switch(port)
		{
			case PA:
			Clr_Bit(DDRA,pin_num);
			Set_Bit(PORTA,pin_num);
			break;
			case PB:
			Clr_Bit(DDRB,pin_num);
			Set_Bit(PORTB,pin_num);
			break;
			case PC:
			Clr_Bit(DDRC,pin_num);
			Set_Bit(PORTC,pin_num);
			break;
			case PD:
			Clr_Bit(DDRD,pin_num);
			Set_Bit(PORTD,pin_num);
			break;
		}
		break;
	}
}



void DIO_WritePin(DIO_Pin_type pin,DIO_PinVoltage_type volt)
{
	DIO_Port_type port =pin/8;
	u8 pin_num=pin%8;
	
	
	if (volt==HIGH)
	{
		switch(port)
		{
			case PA:
			
			Set_Bit(PORTA,pin_num);
			break;
			case PB:
			
			Set_Bit(PORTB,pin_num);
			break;
			case PC:
			
			Set_Bit(PORTC,pin_num);
			break;
			case PD:
			
			Set_Bit(PORTD,pin_num);
			break;
		}
		
	}
	else if (volt==LOW)
	{
		switch(port)
		{
			case PA:
			
			Clr_Bit(PORTA,pin_num);
			break;
			case PB:
			
			Clr_Bit(PORTB,pin_num);
			break;
			case PC:
			
			Clr_Bit(PORTC,pin_num);
			break;
			case PD:
			
			Clr_Bit(PORTD,pin_num);
			break;
		}
	}
	else
	{
		/* do nothing */
	}
	
}

DIO_PinVoltage_type DIO_ReadPin(DIO_Pin_type pin)
{
	DIO_Port_type port =pin/8;
	u8 pin_num=pin%8;
	DIO_PinVoltage_type volt=LOW;
	
	switch(port)
	{
		case PA:
		
		volt=Get_Bit(PINA,pin_num);
		break;
		case PB:
		
		volt=Get_Bit(PINB,pin_num);
		break;
		case PC:
		
		volt=Get_Bit(PINC,pin_num);
		break;
		case PD:
		
		volt=Get_Bit(PIND,pin_num);
		break;
	}
	
	return volt;
}

void DIO_WritePort(DIO_Port_type port,u8 value)
{
	switch(port)
	{
		case PA:
		PORTA=value;
		
		break;
		case PB:
		PORTB=value;
		break;
		case PC:
		PORTC=value;
		break;
		case PD:
		PORTD=value;
		break;
	}
	
	
	
}




// Error_t DIO_ReadPin(DIO_Port_type port,u8 pin_num,DIO_PinVoltage_type*Pvolt)
// {
// 	if (Pvolt==NULLPTR)
// 	{
// 		return NULL_PTR_ERROR;
// 	}
// 	else if ((port>PD)||(pin_num>7))
// 	{
// 	 return OUT_OF_RANGE;	
// 	}
// 	else
// 	{
// 		switch(port)
// 		{
// 			case PA:
// 			
// 			*Pvolt=READ_BIT(PINA,pin_num);
// 			break;
// 			case PB:
// 			
// 			*Pvolt=READ_BIT(PINB,pin_num);
// 			break;
// 			case PC:
// 			
// 			*Pvolt=READ_BIT(PINC,pin_num);
// 			break;
// 			case PD:
// 			
// 			*Pvolt=READ_BIT(PIND,pin_num);
// 			break;
// 		}
// 		return OK;
// 	}
// }



