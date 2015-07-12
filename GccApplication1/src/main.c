/*
 * GccApplication1.c
 *
 * Created: 2015/1/21 19:35:26
 *  Author: ÐíÐÞÒ«
 */ 
#include "include.h"

void SystemInit(void)
{
	//Initial T1 as 1ms counter
	CTimerInit(1);
	
	//Led IO initial
	LedInit();
	
	//Key IO initial
	KeyInit();
	
	//Initial event array
	CTimerInitialTimerEvent();
	
	//Initital remote IO as input IO
	RemoteInit();
	
	//Usart initial
	MY_USART_Init();
	
	//Interrupt enable
	sei();

}
void PowerDetect(void)
{
	//Detect key when power on
	if (CKeyScan() == _DISPLAY_KEY_MASK || CRemoteScan() == _DISPLAY_KEY_MASK)
	{
		g_ucKeyStateCurr = g_ucKeyStatePrev = _DISPLAY_KEY_MASK;
		g_ucRemoteStateCurr = g_ucRemoteStatePrev = _DISPLAY_KEY_MASK;
		g_stStatusCmd.bShowVersion = true;
		#ifdef _DEBUG_PRINTF
		MyPrintf("Power combo key is: S%d\r\n",g_ucKeyMessage + 1);
		#endif
	}
}
int main(void)
{	
	//System initial
	SystemInit();
	
	//Initial command struct
	CommandInit(&g_stCameraCmd);
	
	//Initial status struct
	StatusInit(&g_stStatusCmd);
	
	PowerDetect();
	
	ProductInfoInit(&g_stProductInfo);
	
	//Initial Camera
	InitCamera();
	
	while(1)
    {	
		//Key detect and set a key message
		CKeyHandle();
		
		//Event count down timer handler
		CTimerHandle();
		
		//Remote IO detect and set a remote message
		CRemoteHandle();
		
		//Key message and remote message handler
		CMessageHandle();

		#if(_FOCUS_OOR_TIPS == 1)
		//Focus out of range Handle
		CFocusOutOfRangeHandle();
		#endif
		
		//Release Key Message Handle
		CReleaseKeyMessageHandle();
		
		//Do something when command finished
		CommandHandle();

		//White balance handle
		WhiteBalanceHandle();
		
		if (true == g_bTimerChange || true == g_bTitle1Change || true == g_bTitle2Change)
		{
			_delay_ms(10);
			TitleHandle();
		}
        
    }
}