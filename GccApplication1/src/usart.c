/*
 * usart.c
 *
 * Created: 2015/1/9 16:05:10
 *  Author: 许修耀
 */ 
/******************************************************************
*注意： RXD    PD0
*       TXD    PD1
******************************************************************/

#include "include.h"


#define BAUD 9600
#define MYUBRR F_CPU/16/BAUD-1

//定义接收字符
volatile unsigned char rev_data;
unsigned char ReplyBuf[32];
bool ReplyHeadFoundA = false;
unsigned char ReplyLength = 0;
CMD_REPLY ReplyType = _CMD_REPLY_TOTAL;
//串口接收中断
ISR(USART_RX_vect)
{
	rev_data = UDR0;
	
	switch(rev_data)
	{
		case REPAY_HEAD:
			ReplyHeadFoundA = true;
			ReplyBuf[0] = rev_data;
			ReplyLength = 1;
		break;
		case REPAY_TAIL:
			
			if (ReplyHeadFoundA == true)
			{
				
				ReplyBuf[ReplyLength++] = rev_data;
				ReplyHeadFoundA = false;
				g_stCameraCmd.CmdReply = ReplyBuf[1];
				CommandLoadBuf(g_stCameraCmd.CmdReply, &g_stCameraCmd, ReplyBuf, ReplyLength);
				
			}
			else
			{
				// error found here, no head;

			}
		break;

		default:// data bytes
			if (ReplyHeadFoundA == true)
			{
				ReplyBuf[ ReplyLength++ ] = rev_data;
			}
		break;
	}
	
	//发送接收到的字符
	//USART_SendUChar(rev_data);

}

//--------------------------------------------------
// Description  : Init USART 
// Input Value  : ubrr -->baundrate
// Output Value : None
//--------------------------------------------------
void USART_Init( unsigned int ubrr)
{
	/* Set baud rate */
	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)ubrr;
	
	/* Enable receiver and transmitter */
	UCSR0B = (1<<RXCIE0)|(1<<RXEN0)|(1<<TXEN0);
	/* Set frame format: 8data, 1stop bit */
	UCSR0C = (1<<UCSZ01)|(1<<UCSZ00);
	
}

//--------------------------------------------------
// Description  : Init USART as MYUBRR
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void MY_USART_Init(void)
{
	USART_Init(MYUBRR);
}

//--------------------------------------------------
// Description  : Send a unsigned char 
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void USART_SendUChar( unsigned char data )
{
	/* Wait for empty transmit buffer */
	while ( !( UCSR0A & (1<<UDRE0)) )
	;
	/* Put data into buffer, sends the data */
	UDR0 = data;
}

//--------------------------------------------------
// Description  : Send a signed char
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void USART_SendChar( char data )
{
	/* Wait for empty transmit buffer */
	while ( !( UCSR0A & (1<<UDRE0)) )
	;
	/* Put data into buffer, sends the data */
	UDR0 = data;
}

//--------------------------------------------------
// Description  : Get a unsigned char from RX buffer
// Input Value  : None
// Output Value : None
//--------------------------------------------------
unsigned char USART_Receive( void )
{
	/* Wait for data to be received */
	while ( !(UCSR0A & (1<<RXC0)) )
	;
	/* Get and return received data from buffer */
	return UDR0;
}
//--------------------------------------------------
// Description  : Get a command array
// Input Value  : buf     --> command array
//                len      --> command length
// Output Value : None
//--------------------------------------------------
bool USART_GetCommand(uint8_t* buf, uint8_t* len)
{
	/* Wait for data to be received */
	while ( !(UCSR0A & (1<<RXC0)) )
	{
		LedFlashing(1);	
	}
	
	
	*len = 0;
	while (!(UCSR0A & (1<<UDRE0)))
	{
		buf[*len++] = UDR0;
	}
	return true;

}

//--------------------------------------------------
// Description  : Send a command array
// Input Value  : buf     --> command array
//                len      --> command length
// Output Value : None
//--------------------------------------------------
void USART_SendCmd(uint8_t* buf, uint8_t len)
{
	uint8_t i = 0;
	
	for (i = 0;i < len;i++)
	{
		USART_SendUChar(*buf);
		buf++;
		_delay_us(20);
	}
}

//--------------------------------------------------
// Description  : Send a format string
// Input Value  : fmt     --> string format
//                ...      --> option
// Output Value : None
//--------------------------------------------------
#ifdef _DEBUG_PRINTF

void MyPrintf(const char *fmt, ...)
{
	const char *s;
	int d;
	char c;
	char buf[6];
	va_list ap;

	va_start(ap, fmt);
	
	while (*fmt)
	{
		if (*fmt != '%')
		{
			USART_SendChar(*fmt++);
			continue;
		}
		switch (*++fmt)
		{
			// %s
			case 's':
			s = va_arg(ap, const char *);
			for ( ; *s; s++)
			{
				USART_SendChar(*s);
			}
			break;
			// %d
			case 'd':
			d = va_arg(ap, int);
			itoa(d, buf, 10);
			for (s = buf; *s; s++)
			{
				USART_SendChar(*s);
			}
			break;
			// %c
			case 'c':
			c = (char)va_arg(ap, int);
			USART_SendChar(c);
			break;
			default:
			USART_SendChar(*fmt);
			break;
		}
		fmt++;
	}
	
	va_end(ap);
}

#endif