/*
 * LCD_Cfg.h
 *
 * Created: 31/03/2023 14:43:31
 *  Author: lenovo
 */ 


#ifndef LCD_CFG_H_
#define LCD_CFG_H_




#define _4_BIT   0
#define _8_BIT   1

/* _4_BIT OR _8_BIT*/
#define  LCD_MODE  _4_BIT 	



#define  RS   PINB1
#define  EN   PINB0

#define  D7   PINA7
#define  D6   PINB7
#define  D5   PIND7
#define  D4   PINA2

#define LCD_PORT  PA





#endif /* LCD_CFG_H_ */