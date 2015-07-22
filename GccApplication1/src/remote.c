/*
 * remote.c
 *
 * Created: 2015/1/14 17:12:39
 *  Author: ÐíÐÞÒ«
 */ 
#include "include.h"
uint8_t g_ucValuePortC = 0;
uint8_t g_ucRemoteStateCurr = 0;
uint8_t g_ucRemoteControl = 0;
uint8_t g_ucRemoteMessage = 0;
uint8_t g_ucRemoteStatePrev = 0;
bool g_ucWideRemotePress = false;
bool g_ucWideRemoteRelease = false;
bool g_ucTeleRemotePress = false;
bool g_ucTeleRemoteRelease = false;

void RemoteInit(void) 
{
	PORTC |= ((1<<PINC4)|(1<<PINC3  )|(1<<PINC2)|(1<<PINC1)|(1<<PINC0));
	DDRC &= !((1<<DDRC4)|(1<<DDRC3)|(1<<DDRC2)|(1<<DDRC1)|(1<<DDRC0));
}
//--------------------------------------------------
// Description  : Remote handler
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void CRemoteHandle(void)
{
	//static uint8_t uiRemoteCount = 0;
	g_ucRemoteMessage = _NONE_KEY_MESSAGE;
	
	if(CRemoteScanReady())
	{
		g_ucRemoteStatePrev = g_ucRemoteStateCurr;
		g_ucRemoteStateCurr = CRemoteScan();

		// You can set a Remote as repeatable like this
		if((_WIDE_KEY_MASK == g_ucRemoteStateCurr || _TELE_KEY_MASK == g_ucRemoteStateCurr)&&(g_stStatusCmd.ZoomMode == _ZOOM_MODE_GRADING || g_stStatusCmd.FocusMode == _FOCUS_MODE_MANUAL))
		{
			//if (uiRemoteCount++>1)
			{
				//uiRemoteCount = 0;
				SET_REMOTEREPEATENABLE();
			}
// 			else
// 			{
// 				CLR_REMOTEREPEATENABLE();
// 			}
		}
		else
		{
			//uiRemoteCount = 0;
			CLR_REMOTEREPEATENABLE();
		}

		CRemoteMessageProc();

	}
}

//--------------------------------------------------
// Description  : Set flag for Remote scan
// Input Value  : None
// Output Value : Remote scan flag
//--------------------------------------------------
bool CRemoteScanReady(void)
{
	if(GET_REMOTESCANSTART() && GET_REMOTESCANREADY())
	{
		return true;
	}
	else if(!GET_REMOTESCANSTART())
	{
		// Wait 0.02 sec in order to keep the Remotepad debounce
		SET_REMOTESCANSTART();
		CTimerReactiveTimerEvent(MSEC(REMOTE_DEBOUNCE_TIME), CRemoteScanReadyTimerEvent);
	}
	return false;
}

//--------------------------------------------------
// Description  : Remote scan process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
uint8_t CRemoteScan(void)
{
	uint8_t ucRemoteState = 0;
	uint8_t valC;



	valC = PINC;
	
	if ((valC & REMOTE_MASK_VT))
	{
		valC &= REMOTE_MASK_ALL;
		/*
		if (REMOTE_MASK_WIDE == valC)
		{
			ucRemoteState = ucRemoteState | _WIDE_KEY_MASK;
		}
		else
		{
			if(g_ucWideRemotePress)
			{
				g_ucWideRemotePress= false;
				g_ucWideRemoteRelease= true;
				#ifdef _DEBUG_PRINTF
				MyPrintf("Wide Remote release!!\r\n");
				#endif
			}
		}
		
		if (REMOTE_MASK_TELE == valC)
		{
			ucRemoteState = ucRemoteState | _TELE_KEY_MASK;
		}
		else
		{
			if(g_ucTeleRemotePress)
			{
				g_ucTeleRemotePress= false;
				g_ucTeleRemoteRelease= true;
				#ifdef _DEBUG_PRINTF
				MyPrintf("Tele Remote release!!\r\n");
				#endif
			}
		}
*/
		switch(valC)
		{
			case REMOTE_MASK_AF:
				ucRemoteState = ucRemoteState | _AF_KEY_MASK;
			break;
 			case REMOTE_MASK_WIDE:
 				ucRemoteState = ucRemoteState | _WIDE_KEY_MASK;
 			break;
			case REMOTE_MASK_DISPLAY:
				ucRemoteState = ucRemoteState | _DISPLAY_KEY_MASK;
			break;
 			case REMOTE_MASK_TELE:
 				ucRemoteState = ucRemoteState | _TELE_KEY_MASK;
 			break;
			case REMOTE_MASK_TIME:
				ucRemoteState = ucRemoteState | _TIME_KEY_MASK;
			break;
			case REMOTE_MASK_WHITE:
				ucRemoteState = ucRemoteState | _WHITE_KEY_MASK;
			break;
			case REMOTE_MASK_FREEZE:
				ucRemoteState = ucRemoteState | _FREEZE_KEY_MASK;
			break;
			case REMOTE_MASK_FILTER:
				ucRemoteState = ucRemoteState | _FILTER_KEY_MASK;
			break;
			default:
			break;
		}

	}


	#ifdef _DEBUG_PRINTF
	//MyPrintf("remote mask is: %d\r\n",valC);
	#endif

	if(ucRemoteState & _WIDE_KEY_MASK)
	{
		g_ucWideRemotePress = true;
	}

	if(ucRemoteState & _TELE_KEY_MASK)
	{
		g_ucTeleRemotePress = true;
	}
	
	if(ucRemoteState != 0)
	{
		CLR_REMOTESCANREADY();
		CLR_REMOTESCANSTART();
	}

	return ucRemoteState;
}
//--------------------------------------------------
// Description  : Remote scan ready timer event
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void CRemoteScanReadyTimerEvent(void)
{
	SET_REMOTESCANREADY();
}
//--------------------------------------------------
// Description  : Remote repeat enable timer event
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void CRemoteRepeatEnableTimerEvent(void)
{
	SET_REMOTEREPEATSTART();
}


//--------------------------------------------------
// Description  : Remote message translation
// Input Value  : ucRemoteMask     --> Remote mask
//                ucRemoteMsg      --> Remote message
// Output Value : None
//--------------------------------------------------
void CRemoteMessageConvert(uint8_t ucRemoteMask, uint8_t ucRemoteMsg)
{
	if((g_ucRemoteStatePrev ^ g_ucRemoteStateCurr) & ucRemoteMask)
	{
		g_ucRemoteMessage = ucRemoteMsg;
		#ifdef _DEBUG_PRINTF
		//MyPrintf("Current remote key num is: R%d\r\n",g_ucRemoteMessage + 1);
		#endif
	}
	else
	{
		if(GET_REMOTEREPEATENABLE())
		{
			if(GET_REMOTEREPEATSTART())
			{
				if((g_stStatusCmd.FocusMode == _FOCUS_MODE_MANUAL))
				{
					
					if(g_ucRemoteStateCurr == _WIDE_KEY_MASK&& g_stStatusCmd.bStartFar== false)
					{
						g_stStatusCmd.bStartFar = true;
						g_ucRemoteMessage = ucRemoteMsg;
					}
					else if(g_ucRemoteStateCurr == _TELE_KEY_MASK&& g_stStatusCmd.bStartNear== false)
					{
						g_stStatusCmd.bStartNear = true;
						g_ucRemoteMessage = ucRemoteMsg;
					}

				}
				else
					g_ucRemoteMessage = ucRemoteMsg;
				//CLR_REMOTEREPEATSTART();
			}
			else
			{
				CTimerActiveTimerEvent(MSEC(KEY_REPEAT_START_TIME), CRemoteRepeatEnableTimerEvent);
			}
		}
	}
}
//--------------------------------------------------
// Description  : Convert Remotepad status into Remote message
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void CRemoteMessageProc(void)
{
	switch(g_ucRemoteStateCurr)
	{
		case _AF_KEY_MASK:
		CRemoteMessageConvert(_AF_KEY_MASK, _AF_KEY_MESSAGE);
		break;

		case _WIDE_KEY_MASK:
		CRemoteMessageConvert(_WIDE_KEY_MASK, _WIDE_KEY_MESSAGE);
		break;

		case _DISPLAY_KEY_MASK:
		CRemoteMessageConvert(_DISPLAY_KEY_MASK, _DISPLAY_KEY_MESSAGE);
		break;

		case _TELE_KEY_MASK:
		CRemoteMessageConvert(_TELE_KEY_MASK, _TELE_KEY_MESSAGE);
		break;
		
		case _TIME_KEY_MASK:
		CRemoteMessageConvert(_TIME_KEY_MASK, _TIME_KEY_MESSAGE);
		break;
		
		case _WHITE_KEY_MASK:
		CRemoteMessageConvert(_WHITE_KEY_MASK, _WHITE_KEY_MESSAGE);
		break;
		
		case _FREEZE_KEY_MASK:
		CRemoteMessageConvert(_FREEZE_KEY_MASK, _FREEZE_KEY_MESSAGE);
		break;
		
		case _FILTER_KEY_MASK:
		CRemoteMessageConvert(_FILTER_KEY_MASK, _FILTER_KEY_MESSAGE);
		break;
		
		default:
		CLR_REMOTEREPEATSTART();
		CTimerCancelTimerEvent(CRemoteRepeatEnableTimerEvent);
		break;
	}
}