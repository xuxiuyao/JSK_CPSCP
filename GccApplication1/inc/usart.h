/*
 * usart.h
 *
 * Created: 2015/1/13 17:58:39
 *  Author: ÐíÐÞÒ«
 */ 


#ifndef USART_H_
#define USART_H_


extern void MY_USART_Init(void);
extern void USART_SendUChar( unsigned char data );
extern void USART_SendChar( char data );
extern unsigned char USART_Receive( void );
extern bool USART_GetCommand(uint8_t* buf, uint8_t* len);
extern void USART_SendCmd(uint8_t* buf, uint8_t len);
extern void MyPrintf(const char *fmt, ...);

#endif /* USART_H_ */