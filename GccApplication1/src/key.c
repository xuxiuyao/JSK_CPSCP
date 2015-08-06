/*
 * key.c
 *
 * Created: 2015/1/23 01:04:14
 *  Author: ÐíÐÞÒ«
 */ 
#include "include.h"
//--------------------------------------------------
// Global Variables
//--------------------------------------------------
uint8_t g_ucKeyControl = 0;
uint8_t g_ucKeyMessage = 0;
uint16_t g_ucKeyStatePrev = 0;
uint16_t g_ucKeyStateCurr = 0;
bool g_ucWideKeyPress = false;
bool g_ucWideKeyRelease = false;
bool g_ucTeleKeyPress = false;
bool g_ucTeleKeyRelease = false;
//--------------------------------------------------
// Description  : Key GPIO init
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void KeyInit(void)
{
	DDRB = 0x38;
	PORTB = 0xFF;
	#if(_LED_PIN == _LED_D5)
	DDRC = 0x00;
	PORTC = 0xFF;
	#elif(_LED_PIN == _LED_C5)
	PORTC = 0xdF;
	DDRC = 0x20;
	#endif

	DDRD = 0xEA;
	PORTD = 0xFF;
}
//--------------------------------------------------
// Description  : Key handler
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void CKeyHandle(void)
{
	//static uint8_t uiKeyCount = 0;
	g_ucKeyMessage = _NONE_KEY_MESSAGE;
	
	if(CKeyScanReady())
	{
		g_ucKeyStatePrev = g_ucKeyStateCurr;
		g_ucKeyStateCurr = CKeyScan();

		// You can set a key as repeatable like this
		if((_WIDE_KEY_MASK == g_ucKeyStateCurr || _TELE_KEY_MASK == g_ucKeyStateCurr)&&(g_stStatusCmd.ZoomMode == _ZOOM_MODE_GRADING || g_stStatusCmd.FocusMode == _FOCUS_MODE_MANUAL))
		{
			//if (uiKeyCount++>1)
			{
				//uiKeyCount = 0;
				SET_KEYREPEATENABLE();
			}
// 			else
// 			{
// 				CLR_KEYREPEATENABLE();
// 			}			
		}
		else
		{
			//uiKeyCount = 0;
			CLR_KEYREPEATENABLE();
		}

		CKeyMessageProc();

	}
}
//--------------------------------------------------
// Description  : Key scan process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
#if(_KEY_NUM == _KEY_MODE_8KEY_STD)
uint16_t CKeyScan(void)
{
	uint16_t ucKeyState = 0;
	uint8_t valB;
	uint8_t valC;
	uint8_t valD;
	uint8_t ScanCount = 4;
	
	
	
	do 
	{
		valB = PINB;
		valC = PINC;
		valD = PIND;
		
		if(!(valB & KEY_MASK_AF))
		{
			ucKeyState = ucKeyState | _AF_KEY_MASK;
		}

		if(!(valD & KEY_MASK_WIDE))
		{
			ucKeyState = ucKeyState | _WIDE_KEY_MASK;
			
			#ifdef _DEBUG_PRINTF
			MyPrintf("press Far key\r\n");
			#endif
		}
		/*
		else
		{
			if(g_ucWideKeyPress)
			{
				g_ucWideKeyPress = false;
				g_ucWideKeyRelease = true;
				#ifdef _DEBUG_PRINTF
				MyPrintf("Wide key release!!\r\n");
				#endif
				//break;
			}
		}
		*/

		if(!(valB & KEY_MASK_DISPLAY))
		{
			ucKeyState = ucKeyState | _DISPLAY_KEY_MASK;
			#ifdef _DEBUG_PRINTF
			//MyPrintf("press Display key\r\n");
			#endif
		}

		if(!(valC & KEY_MASK_TELE))
		{
			ucKeyState = ucKeyState | _TELE_KEY_MASK;
			
			#ifdef _DEBUG_PRINTF
			//MyPrintf("press Near key\r\n");
			#endif
		}
		/*
		else
		{
			if(g_ucTeleKeyPress)
			{
				g_ucTeleKeyPress = false;
				g_ucTeleKeyRelease = true;
				#ifdef _DEBUG_PRINTF
				MyPrintf("Tele key release!!\r\n");
				#endif
				//break;
			}

		}
		*/

		if(!(valB & KEY_MASK_TIME))
		{
			ucKeyState = ucKeyState | _TIME_KEY_MASK;
		}
		
		if(!(valD & KEY_MASK_WHITE))
		{
			ucKeyState = ucKeyState | _WHITE_KEY_MASK;
		}
		
		if(!(valB & KEY_MASK_FREEZE))
		{
			ucKeyState = ucKeyState | _FREEZE_KEY_MASK;
		}
		
		if(!(valB & KEY_MASK_FILTER))
		{
			ucKeyState = ucKeyState | _FILTER_KEY_MASK;
		}
		_delay_ms(10);
	} while (ScanCount--);

	if(ucKeyState & _WIDE_KEY_MASK)
	{
		g_ucWideKeyPress = true;
	}

	if(ucKeyState & _TELE_KEY_MASK)
	{
		g_ucTeleKeyPress = true;
	}

	if(ucKeyState != 0)
	{
		CLR_KEYSCANREADY();
		CLR_KEYSCANSTART();
	}

	return ucKeyState;
}
#elif(_KEY_NUM == _KEY_MODE_6KEY_STD)
uint16_t CKeyScan(void)
{
	uint16_t ucKeyState = 0;
	uint8_t valB;
	uint8_t valC;
	uint8_t valD;
	uint8_t ScanCount = 4;
	
	valB = PINB;
	valC = PINC;
	valD = PIND;
	
	do 
	{
		if(!(valB & KEY_MASK_FREEZE))
		{
			ucKeyState = ucKeyState | _FREEZE_KEY_MASK;
		}

		if(!(valD & KEY_MASK_DISPLAY))
		{
			ucKeyState = ucKeyState | _DISPLAY_KEY_MASK;
			#ifdef _DEBUG_PRINTF
			//MyPrintf("press Display key\r\n");
			#endif
		}
		

		if(!(valB & KEY_MASK_WIDE))
		{
			ucKeyState = ucKeyState | _WIDE_KEY_MASK;
			#ifdef _DEBUG_PRINTF
			MyPrintf("press Far key\r\n");
			#endif
		}
		else
		{
			if(g_ucWideKeyPress)
			{
				g_ucWideKeyPress = false;
				g_ucWideKeyRelease = true;
				#ifdef _DEBUG_PRINTF
				MyPrintf("Wide key release!!\r\n");
				#endif
			}
		}

		if(!(valC & KEY_MASK_TELE))
		{
			ucKeyState = ucKeyState | _TELE_KEY_MASK;
			
			#ifdef _DEBUG_PRINTF
			//MyPrintf("press Near key\r\n");
			#endif
		}
		else
		{
			if(g_ucTeleKeyPress)
			{
				g_ucTeleKeyPress = false;
				g_ucTeleKeyRelease = true;
				#ifdef _DEBUG_PRINTF
				MyPrintf("Tele key release!!\r\n");
				#endif
			}
		}
		
		if(!(valB & KEY_MASK_AF))
		{
			ucKeyState = ucKeyState | _AF_KEY_MASK;
		}
		
		if(!(valB & KEY_MASK_FILTER))
		{
			ucKeyState = ucKeyState | _FILTER_KEY_MASK;
		}
		_delay_ms(10);
	} while (ScanCount--);

	if(ucKeyState & _WIDE_KEY_MASK)
	{
		g_ucWideKeyPress = true;
	}

	if(ucKeyState & _TELE_KEY_MASK)
	{
		g_ucTeleKeyPress = true;
	}

	if(ucKeyState != 0)
	{
		CLR_KEYSCANREADY();
		CLR_KEYSCANSTART();
	}

	return ucKeyState;
}
#elif(_KEY_NUM == _KEY_MODE_6KEY_EM)
uint16_t CKeyScan(void)
{
	uint16_t ucKeyState = 0;
	uint8_t valB;
	uint8_t valC;
	uint8_t valD;
	uint8_t ScanCount = 4;
	
	valB = PINB;
	valC = PINC;
	valD = PIND;
	
	do 
	{
		if(!(valB & KEY_MASK_FREEZE))
		{
			ucKeyState = ucKeyState | _FREEZE_KEY_MASK;
		}

		if(!(valD & KEY_MASK_DISPLAY))
		{
			ucKeyState = ucKeyState | _DISPLAY_KEY_MASK;
			#ifdef _DEBUG_PRINTF
			//MyPrintf("press Display key\r\n");
			#endif
		}
		

		if(!(valB & KEY_MASK_WIDE))
		{
			ucKeyState = ucKeyState | _WIDE_KEY_MASK;
			#ifdef _DEBUG_PRINTF
			MyPrintf("press Far key\r\n");
			#endif
		}
		else
		{
			if(g_ucWideKeyPress)
			{
				g_ucWideKeyPress = false;
				g_ucWideKeyRelease = true;
				#ifdef _DEBUG_PRINTF
				MyPrintf("Wide key release!!\r\n");
				#endif
			}
		}

		if(!(valC & KEY_MASK_TELE))
		{
			ucKeyState = ucKeyState | _TELE_KEY_MASK;
			
			#ifdef _DEBUG_PRINTF
			//MyPrintf("press Near key\r\n");
			#endif
		}
		else
		{
			if(g_ucTeleKeyPress)
			{
				g_ucTeleKeyPress = false;
				g_ucTeleKeyRelease = true;
				#ifdef _DEBUG_PRINTF
				MyPrintf("Tele key release!!\r\n");
				#endif
			}
		}
		
		if(!(valB & KEY_MASK_EM))
		{
			ucKeyState = ucKeyState | _EM_KEY_MASK;
		}
		
		if(!(valB & KEY_MASK_FILTER))
		{
			ucKeyState = ucKeyState | _FILTER_KEY_MASK;
		}
		_delay_ms(10);
	} while (ScanCount--);

	if(ucKeyState & _WIDE_KEY_MASK)
	{
		g_ucWideKeyPress = true;
	}

	if(ucKeyState & _TELE_KEY_MASK)
	{
		g_ucTeleKeyPress = true;
	}

	if(ucKeyState != 0)
	{
		CLR_KEYSCANREADY();
		CLR_KEYSCANSTART();
	}

	return ucKeyState;
}
#endif
//--------------------------------------------------
// Description  : Set flag for key scan
// Input Value  : None
// Output Value : Key scan flag
//--------------------------------------------------
bool CKeyScanReady(void)
{
	if(GET_KEYSCANSTART() && GET_KEYSCANREADY())
	{
		return true;
	}
	else if(!GET_KEYSCANSTART())
	{
		SET_KEYSCANSTART();
		CTimerReactiveTimerEvent(MSEC(KEY_DEBOUNCE_TIME), CKeyScanReadyTimerEvent);
	}
	return false;
}
//--------------------------------------------------
// Description  : Key message translation
// Input Value  : ucKeyMask     --> Key mask
//                ucKeyMsg      --> Key message
// Output Value : None
//--------------------------------------------------
void CKeyMessageConvert(uint16_t ucKeyMask, uint8_t ucKeyMsg)
{
	if((g_ucKeyStatePrev ^ g_ucKeyStateCurr) & ucKeyMask)
	{
		g_ucKeyMessage = ucKeyMsg;
		#ifdef _DEBUG_PRINTF
		//MyPrintf("Current key num is: S%d\r\n",g_ucKeyMessage + 1);
		#endif
	}
	else
	{
		if(GET_KEYREPEATENABLE())
		{
			if(GET_KEYREPEATSTART())
			{
				if((g_stStatusCmd.FocusMode == _FOCUS_MODE_MANUAL))
				{
					
					if(g_ucKeyStateCurr == _WIDE_KEY_MASK&& g_stStatusCmd.bStartFar== false)
					{
						g_stStatusCmd.bStartFar = true;
						g_ucKeyMessage = ucKeyMsg;
					}
					else if(g_ucKeyStateCurr == _TELE_KEY_MASK&& g_stStatusCmd.bStartNear== false)
					{
						g_stStatusCmd.bStartNear = true;
						g_ucKeyMessage = ucKeyMsg;
					}

				}
				else
					g_ucKeyMessage = ucKeyMsg;
				//CLR_KEYREPEATSTART();
			}
			else
			{
				CTimerActiveTimerEvent(MSEC(KEY_REPEAT_START_TIME), CKeyRepeatEnableTimerEvent);
			}
		}
	}
}
//--------------------------------------------------
// Description  : Key scan ready timer event
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void CKeyScanReadyTimerEvent(void)
{
	SET_KEYSCANREADY();
}
//--------------------------------------------------
// Description  : Key repeat enable timer event
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void CKeyRepeatEnableTimerEvent(void)
{
	SET_KEYREPEATSTART();
}
//--------------------------------------------------
// Description  : Convert keypad status into key message
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void CKeyMessageProc(void)
{
	switch(g_ucKeyStateCurr)
	{
		case _AF_KEY_MASK:
			CKeyMessageConvert(_AF_KEY_MASK, _AF_KEY_MESSAGE);
		break;

		case _WIDE_KEY_MASK:
			CKeyMessageConvert(_WIDE_KEY_MASK, _WIDE_KEY_MESSAGE);
		break;

		case _DISPLAY_KEY_MASK:
			CKeyMessageConvert(_DISPLAY_KEY_MASK, _DISPLAY_KEY_MESSAGE);
		break;

		case _TELE_KEY_MASK:
			CKeyMessageConvert(_TELE_KEY_MASK, _TELE_KEY_MESSAGE);
		break;
		
		case _TIME_KEY_MASK:
			CKeyMessageConvert(_TIME_KEY_MASK, _TIME_KEY_MESSAGE);
		break;
		
		case _WHITE_KEY_MASK:
			CKeyMessageConvert(_WHITE_KEY_MASK, _WHITE_KEY_MESSAGE);
		break;
		
		case _FREEZE_KEY_MASK:
			CKeyMessageConvert(_FREEZE_KEY_MASK, _FREEZE_KEY_MESSAGE);
		break;
		
		case _FILTER_KEY_MASK:
			CKeyMessageConvert(_FILTER_KEY_MASK, _FILTER_KEY_MESSAGE);
		break;

		case _EM_KEY_MASK:
			CKeyMessageConvert(_EM_KEY_MASK, _EM_KEY_MESSAGE);
		break;
		
		case _AWB_KEY_MASK:
			CKeyMessageConvert(_AWB_KEY_MASK, _AWB_KEY_MESSAGE);
		break;
		
		case _MWB_KEY_MASK:
			CKeyMessageConvert(_MWB_KEY_MASK, _MWB_KEY_MESSAGE);
		break;
		
		case _RB_SWITCH_KEY_MASK:
			CKeyMessageConvert(_RB_SWITCH_KEY_MASK, _RB_SWITCH_KEY_MESSAGE);
		break;
#ifdef _TIME_DISPLAY_TO_EM
		case _TIME_DISPALY_EM_MASK:
			CKeyMessageConvert(_TIME_DISPALY_EM_MASK, _TIME_DISPLAY_EM_MESSAGE);
		break;	
#endif		
		default:
		CLR_KEYREPEATSTART();
		CTimerCancelTimerEvent(CKeyRepeatEnableTimerEvent);
		break;
	}
}
