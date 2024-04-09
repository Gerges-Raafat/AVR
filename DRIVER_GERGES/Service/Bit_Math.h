 /***********************************************************************************
 * Author 	  : Hesham Ahmed													   *
 * Date   	  : 30/4/2023														   *
 * File name  : Bit_Math.h												 		   *
 * Description: This File Contain the Function Like Macro to Create Bit Mask 	   *
 * Version    :  01																   *
 ***********************************************************************************/

#ifndef COMMAN_BIT_MATH_H_
#define COMMAN_BIT_MATH_H_

#define Set_Bit(Reg,Bit)   Reg|=(1<<Bit)

#define Clr_Bit(Reg,Bit)   Reg&=~(1<<Bit)

#define Tog_Bit(Reg,Bit)   Reg^=(1<<Bit)

#define Get_Bit(Reg,Bit)   ((Reg>>Bit)&0x01)

#endif /* COMMAN_BIT_MATH_H_ */
