/*
 * message.c
 *
 * Created: 2015/1/25 21:07:52
 *  Author: Administrator
 */ 
#include "include.h"


uint16_t  g_u16FocusEnding = 0;
uint8_t g_u8FocusGetMaxCount = 0;


#if(_MAX_RATE == 40)
	#if(_CCD_TYPE_CODE == _CCD_480)//Right
	uint16_t uiFocusLimitTable[_MAX_RATE] = 
	{
		0x9000,0x9000,0x9000,0x9000,0x9000,0x9000,0x9000,0x9000,0x9000,0x9000,
		0x9000,0x9000,0x9000,0x9000,0x9000,0x9000,0x9000,0x9000,0x9000,0x9000,
		0x9000,0x9000,0x9000,0x9000,0x9000,0x9000,0x9000,0x9000,0x9000,0x9000,
		0x9000,0x9000,0x9000,0x9000,0x9000,0x9000,0x9000,0x9000,0x9000,0x9000,

	};
	#elif(_CCD_TYPE_CODE == _CCD_1020)//Right
	uint16_t uiFocusLimitTable[_MAX_RATE] = 
	{
		0x9000,0x9000,0x9000,0x9000,0x9000,0x9000,0x9000,0x9000,0x9000,0x9000,
		0x9000,0x9000,0x9000,0x9000,0x9000,0x9000,0x9000,0x9000,0x9000,0x9000,
		0x9000,0x9000,0x9000,0x9000,0x9000,0x9000,0x9000,0x9000,0x9000,0x9000,
		0x9000,0x9000,0x9000,0x9000,0x9000,0x9000,0x9000,0x9000,0x9000,0x9000,
	};
	#elif(_CCD_TYPE_CODE == _CCD_3300)//Right
	uint16_t uiFocusLimitTable[_MAX_RATE] = 
	{
		0x9000,0x9000,0x9000,0x9000,0x8000,0x8000,0x7000,0x7000,0x7000,0x7000,
		0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,
		0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,
		0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,
	};
	#elif(_CCD_TYPE_CODE == _CCD_6300)//Right
	uint16_t uiFocusLimitTable[_MAX_RATE] = 
	{
		0x9000,0x9000,0x9000,0x9000,0x8000,0x8000,0x7000,0x7000,0x7000,0x7000,
		0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,
		0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,
		0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,
	};
	#elif(_CCD_TYPE_CODE == _CCD_7500)//不知道参数，暂用6300
	uint16_t uiFocusLimitTable[_MAX_RATE] = 
	{
		0x9000,0x9000,0x9000,0x9000,0x8000,0x8000,0x7000,0x7000,0x7000,0x7000,
		0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,
		0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,
		0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,
	};
	#endif
#elif(_MAX_RATE == 52)
	#if(_CCD_TYPE_CODE == _CCD_480)//Right    DVC10000读出
	uint16_t uiFocusLimitTable[_MAX_RATE] = 
	{
		0x9000,0x9000,0x9000,0x9000,0x8000,0x8000,0x7000,0x7000,0x7000,0x7000,
		0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,
		0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,
		0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,
		0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,
		0x7000,0x7000,
	};
	#elif(_CCD_TYPE_CODE == _CCD_3300)//copy from 480
	uint16_t uiFocusLimitTable[_MAX_RATE] = 
	{
		0x9000,0x9000,0x9000,0x9000,0x8000,0x8000,0x7000,0x7000,0x7000,0x7000,
		0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,
		0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,
		0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,
		0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,
		0x7000,0x7000,
	};
	#elif(_CCD_TYPE_CODE == _CCD_6300)//copy from 480
	uint16_t uiFocusLimitTable[_MAX_RATE] = 
	{
		0x9000,0x9000,0x9000,0x9000,0x8000,0x8000,0x7000,0x7000,0x7000,0x7000,
		0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,
		0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,
		0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,
		0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,
		0x7000,0x7000,
	};
	#elif(_CCD_TYPE_CODE == _CCD_7500)//copy from 480
	uint16_t uiFocusLimitTable[_MAX_RATE] = 
	{
		0x9000,0x9000,0x9000,0x9000,0x8000,0x8000,0x7000,0x7000,0x7000,0x7000,
		0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,
		0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,
		0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,
		0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,0x7000,
		0x7000,0x7000,
	};
	#endif
#endif

#if(_CCD_TYPE_CODE == _CCD_7500)
#define _INIT_DELAY			70
#else
#define _INIT_DELAY			10
#endif 
void InitCamera(void)
{

	#if(_CCD_TYPE_CODE == _CCD_7500)
	LedFlashing(60);//7500->30s
	#elif(_CCD_TYPE_CODE == _CCD_480)
	_delay_ms(500);//480->2s
	LedFlashing(9);//
	#elif(_CCD_TYPE_CODE == _CCD_3300)
	_delay_ms(1000);//480->2s
	LedFlashing(14);//6300,3300->8s   
	#else
	_delay_ms(1000);//480->2s
	LedFlashing(24);//6300,3300->8s   
	#endif
	while(1)
	{		
		LedOff();
		#if(_CCD_TYPE_CODE != _CCD_7500)
		CAM_InqID();
		_delay_ms(_INIT_DELAY * 5);
		GetInquiryResult(&g_stCameraCmd);
	
		GetCameraId();
		
		//if (_CAMARA_ID == g_stStatusCmd.uiCamID)
		#endif
		{
			CAM_SetTitleClear();
			_delay_ms(_INIT_DELAY*5);
			CAM_SetTitleOn();
			_delay_ms(_INIT_DELAY*5);
			
			if(g_stStatusCmd.bShowVersion)
			{
				TITLE_DISPLAY titleDis;
				titleDis.uiTitleVPos = 0x01;
				#if(_CCD_TYPE_CODE == _CCD_480)
				titleDis.uiTitleHPos = 0x01;
				#else
				titleDis.uiTitleHPos = 0x05;
				#endif
				titleDis.TitleColor = _TITLE_COLOR_VIOLET;
				titleDis.TitleBlink = _TITLE_BLINK_OFF;
				CAM_SetTitleSet1(titleDis);
				_delay_ms(_INIT_DELAY*5);
				
				ShowProductInfo(titleDis.uiTitleVPos);
				
				LedFlashing(10);
				
				CAM_SetTitleClear();
				_delay_ms(_INIT_DELAY*5);
			}

			CAM_SetTitleSet1(g_stStatusCmd.titleDis);

			_delay_ms(_INIT_DELAY*5);

			CAM_SetTitleOn();
			_delay_ms(_INIT_DELAY*5);
			LedOn();
			

			CAM_SetWBMaunal(); //必须设置为手动白平衡模式，才能够使用工厂设置的R,B值

			_delay_ms(_INIT_DELAY*5);
			//Inq R Gain
			CAM_InqRGain();
			_delay_ms(_INIT_DELAY*5);
			GetInquiryResult(&g_stCameraCmd);
			g_stStatusCmd.uiRGain = GetRGain();
			g_stStatusCmd.uiRGainCurrent = g_stStatusCmd.uiRGain;
			
			
			
			//Inq B Gain
			CAM_InqBGain();
			_delay_ms(_INIT_DELAY*5);
			GetInquiryResult(&g_stCameraCmd);
			g_stStatusCmd.uiBGain = GetBGain();
			g_stStatusCmd.uiBGainCurrent = g_stStatusCmd.uiBGain;
			_delay_ms(_INIT_DELAY*2);



			
			//set auto focus
			CAM_SetAutoFocus();
			
			_delay_ms(_INIT_DELAY*5);
			LedOff();
			#if(_CCD_TYPE_CODE != _CCD_7500)
			//set AF normal 
			CAM_SetNormalAF();
			#else
			CAM_SetDZoomLimit();
			#endif


			
			_delay_ms(_INIT_DELAY*5);
			CAM_SetSAVEAVOn();
			_delay_ms(_INIT_DELAY*5);
			
			CAM_SetZoomDirect();	
			LedFlashing(2);
			break;
		}
	}
}

uint8_t GetMfRateByPos(void)
{
	uint8_t uiMF = 0;

	uiMF =g_stStatusCmd.uiFocusPos/_FOCUS_POS_MIN; //(g_stStatusCmd.uiFocusPos -_FOCUS_POS_MIN) /((uiFocusLimitTable[g_stStatusCmd.uiXRate] -_FOCUS_POS_MIN) /7) + 1;

	return uiMF;
}

uint8_t GetXRateByPos(void)
{
	uint8_t uiXRate = 0;
	for (uiXRate=0; uiXRate<_MAX_RATE;uiXRate++)
	{
		if (g_stStatusCmd.uiZoomPos <= uiZoomRatioTable[uiXRate])
		{
			break;
		}
	}
	if(g_stStatusCmd.uiZoomPos == uiZoomRatioTable[uiXRate])
		return uiXRate;
	else
		return (uiXRate > 0)?uiXRate-1:uiXRate;
}

void ProcessAF(void)
{
	switch(g_stStatusCmd.FocusMode)
	{
		case _FOCUS_MODE_AUTO:
		{
			CAM_SetManualFocus();
			g_stStatusCmd.FocusMode = _FOCUS_MODE_MANUAL;
			//g_stStatusCmd.bIsDisplay = true;
			if((g_stStatusCmd.FlipMode == _FLIP_MODE_NORMAL)||(g_stStatusCmd.FlipMode == _FLIP_MODE_OFF)||(g_stStatusCmd.FlipMode == _MIRROR_MODE_OFF))
				g_stStatusCmd.uiDisplayFlag |= _DISPLAY_FOCUS;
			_delay_ms(50);
			CAM_InqFocusPos();
			_delay_ms(50);
			GetInquiryResult(&g_stCameraCmd);
			g_stStatusCmd.uiFocusPos = GetFocusPos();
			g_stStatusCmd.uiMF = GetMfRateByPos();
			#ifdef _DEBUG_PRINTF
			//MyPrintf("Manual focus!");
			#endif
			#if(_EM_KEY == 1)
			g_stStatusCmd.titleDis.uiTitleVPos = 0x01;
			g_stStatusCmd.titleDis.uiTitleHPos = 0x01;
			g_stStatusCmd.titleDis.TitleColor = _TITLE_COLOR_VIOLET;
			g_stStatusCmd.titleDis.TitleBlink = _TITLE_BLINK_ON;
			CAM_SetTitleSet1(g_stStatusCmd.titleDis);
			#if(_CCD_TYPE_CODE == _CCD_7500)
			_delay_ms(100);
			#endif
			#endif
	
		}
		break;
		case _FOCUS_MODE_MANUAL:
		{
			CAM_SetAutoFocus();
			g_stStatusCmd.FocusMode = _FOCUS_MODE_AUTO;
			g_stStatusCmd.uiDisplayFlag &= ~_DISPLAY_FOCUS;
			g_stStatusCmd.uiDisplayFlag &= ~_DISPLAY_FOCUS_END;
			g_bTitle2Change = true;
			#ifdef _DEBUG_PRINTF
			//MyPrintf("Auto focus!");
			#endif
#if(_EM_KEY == 1)
			g_stStatusCmd.titleDis.uiTitleVPos = 0x0a;
			g_stStatusCmd.titleDis.uiTitleHPos = 0x01;
			g_stStatusCmd.titleDis.TitleColor = _TITLE_COLOR_YELLOW;
			g_stStatusCmd.titleDis.TitleBlink = _TITLE_BLINK_OFF;
			CAM_SetTitleSet1(g_stStatusCmd.titleDis);
			#if(_CCD_TYPE_CODE == _CCD_7500)
			_delay_ms(100);
			#endif
#endif
		}
		break;
		default:
		//error
		break;
	}
	
	g_bTitle1Change = true;
		
	return;
}

void ProcessDisplay(void)
{
	if (true == g_stStatusCmd.bIsDisplay)
	{
		g_stStatusCmd.bIsDisplay = false;
		g_stStatusCmd.uiDisplayFlag &= ~_DISPLAY_ZOOM;
		g_stStatusCmd.uiDisplayFlag &= ~_DISPLAY_FILTER;
		g_stStatusCmd.uiDisplayFlag &= ~_DISPLAY_WHITE;
		#if(_EM_KEY == 1)
		g_stStatusCmd.bIsTime = false;
		g_bTitle2Change = true;
		#endif	
	}
	else
	{
		g_stStatusCmd.bIsDisplay = true;
		g_stStatusCmd.uiDisplayFlag |= _DISPLAY_ZOOM;
		g_stStatusCmd.uiDisplayFlag |= _DISPLAY_FILTER;
		g_stStatusCmd.uiDisplayFlag |= _DISPLAY_WHITE;
		#if(_EM_KEY == 1)
		g_stStatusCmd.bIsTime = true;
		g_bTitle2Change = true;

		g_stStatusCmd.titleDis.uiTitleVPos = 0x0a;
		g_stStatusCmd.titleDis.uiTitleHPos = 0x01;
		g_stStatusCmd.titleDis.TitleColor = _TITLE_COLOR_YELLOW;
		g_stStatusCmd.titleDis.TitleBlink = _TITLE_BLINK_OFF;
		CAM_SetTitleSet1(g_stStatusCmd.titleDis);
		#if(_CCD_TYPE_CODE == _CCD_7500)
		_delay_ms(100);
		#endif
		
		#endif	
	}
	
	g_bTitle1Change = true;
	if (_WHITE_MODE_NORMAL != g_stStatusCmd.WhiteMode || _GREEN_MODE_NORMAL != g_stStatusCmd.GreenMode )
	g_bTitle2Change = true;
	
	return;
}

void ProcessWide(void) //zoom out / Far
{
	if(g_stStatusCmd.WBMode == _WB_MODE_NORMAL)
	{
		switch(g_stStatusCmd.FocusMode)
		{
			case _FOCUS_MODE_AUTO:
			{		
				if (_ZOOM_MODE_GRADING == g_stStatusCmd.ZoomMode)
				{
					#if(_CCD_TYPE_CODE == _CCD_7500)
					g_stStatusCmd.bStartFar = false;

					if (g_stStatusCmd.uiXRate>0)
					{
						
						g_stStatusCmd.uiXRate --;
						if(g_stStatusCmd.uiXRate < 15)
							CAM_SetZoomDirect();
						else
							CAM_SetDZoomDirect();
					}
					else
					{
						break;
					}

					#else
					g_stStatusCmd.bStartFar = false;
					
					if (g_stStatusCmd.uiXRate>0)
					{
						g_stStatusCmd.uiXRate --;
						
					}
					else
					{
						break;
					}

					CAM_SetZoomDirect();
					#endif
				} 
				else
				{
					CAM_InqZoomPos();
					_delay_ms(150);
					GetInquiryResult(&g_stCameraCmd);
					g_stStatusCmd.uiZoomPos = GetZoomPos();
					g_stStatusCmd.uiXRate = GetXRateByPos();
					
					if (g_stStatusCmd.uiZoomPos > uiZoomRatioTable[0])
					{
						#ifdef _DEBUG_PRINTF
						MyPrintf("Execute Zoom Far\r\n");
						#endif
						
						CAM_SetZoomVWide();
						
						g_stStatusCmd.bStartZoomOut= true;
					}


				}
				
				#if(_WIDE_TELE_SET_DISPLAY == 1)
				g_stStatusCmd.bIsDisplay = true;
				#endif
				g_bTitle1Change = true;
				g_stStatusCmd.uiDisplayFlag |= _DISPLAY_ZOOM;

			}
			break;
			case _FOCUS_MODE_MANUAL:
			{
				//CAM_InqFocusPos();
				//_delay_ms(100);
				//GetInquiryResult(&g_stCameraCmd);
				//g_stStatusCmd.uiFocusPos = GetFocusPos();
				//g_stStatusCmd.uiMF = GetMfRateByPos();
				
				//if (g_stStatusCmd.uiFocusPos >_FOCUS_POS_MIN)
				{
					#ifdef _DEBUG_PRINTF
					MyPrintf("Execute Focus Far\r\n");
					#endif
					
					CAM_SetSFarFocus();
					
					g_stStatusCmd.bStartFar = true;

				} 
				
				#if(_WIDE_TELE_SET_DISPLAY == 1)
				g_stStatusCmd.bIsDisplay = true;
				#endif
				g_bTitle1Change = true;
				//g_stStatusCmd.uiDisplayFlag |= _DISPLAY_FOCUS;
			}
			break;
			default:
			//error
			break;
		}
		
	}
	else if(g_stStatusCmd.WBMode == _WB_MODE_MANUAL_R)
	{
		if(g_stStatusCmd.uiRGain > 1)
		{
			g_stStatusCmd.uiRGain -= 1;
			CAM_SetRGainDirect(g_stStatusCmd.uiRGain);
			g_bTitle2Change = true;
		}
	}
	else if(g_stStatusCmd.WBMode == _WB_MODE_MANUAL_B)
	{
		if(g_stStatusCmd.uiBGain > 1)
		{
			g_stStatusCmd.uiBGain -= 1;
			CAM_SetBGainDirect(g_stStatusCmd.uiBGain);
			g_bTitle2Change = true;
		}
	}
	
	
	
	return;
}

void ProcessTele(void) //zoom in / Near
{
	if(g_stStatusCmd.WBMode == _WB_MODE_NORMAL)
	{
		switch(g_stStatusCmd.FocusMode)
		{
			case _FOCUS_MODE_AUTO:
			{			
				if (_ZOOM_MODE_GRADING == g_stStatusCmd.ZoomMode)
				{
					#if(_CCD_TYPE_CODE == _CCD_7500)
					g_stStatusCmd.bStartFar = false;

					if (g_stStatusCmd.uiXRate<_MAX_RATE-1)
					{
						
						g_stStatusCmd.uiXRate ++;
						if(g_stStatusCmd.uiXRate >14)
							CAM_SetDZoomDirect();
						else
							CAM_SetZoomDirect();
					}
					else
					{
						break;
					}
					#else
					g_stStatusCmd.bStartNear = false;					
					if (g_stStatusCmd.uiXRate<_MAX_RATE-1)
					{
						g_stStatusCmd.uiXRate ++;
					}
					else
					{
						break;
					}

					CAM_SetZoomDirect();
					#endif
				}
				else
				{
					CAM_InqZoomPos();
					_delay_ms(150);
					GetInquiryResult(&g_stCameraCmd);
					g_stStatusCmd.uiZoomPos = GetZoomPos();
					g_stStatusCmd.uiXRate = GetXRateByPos();
					
					if (g_stStatusCmd.uiZoomPos < uiZoomRatioTable[_MAX_RATE-1])
					{
						#ifdef _DEBUG_PRINTF
						MyPrintf("Execute Zoom Near\r\n");
						#endif
						
						CAM_SetZoomVTele();
						
						g_stStatusCmd.bStartZoomIn= true;
					}


				}
				
				#if(_WIDE_TELE_SET_DISPLAY == 1)
				g_stStatusCmd.bIsDisplay = true;
				#endif
				g_bTitle1Change = true;
				g_stStatusCmd.uiDisplayFlag |= _DISPLAY_ZOOM;
			}
			break;
			case _FOCUS_MODE_MANUAL:
			{
				//CAM_InqFocusPos();
				//_delay_ms(150);
				//GetInquiryResult(&g_stCameraCmd);
				//g_stStatusCmd.uiFocusPos = GetFocusPos();
				//g_stStatusCmd.uiMF = GetMfRateByPos();

				//if (g_stStatusCmd.uiFocusPos < uiFocusLimitTable[g_stStatusCmd.uiXRate])
				{
					#ifdef _DEBUG_PRINTF
					MyPrintf("Execute Focus Near\r\n");
					#endif
					
					CAM_SetSNearFocus();
					
					g_stStatusCmd.bStartNear = true;
				}
				
				#if(_WIDE_TELE_SET_DISPLAY == 1)
				g_stStatusCmd.bIsDisplay = true;
				#endif
				g_bTitle1Change = true;
				//g_stStatusCmd.uiDisplayFlag |= _DISPLAY_FOCUS;
			}
			break;
			default:
			//error
			break;
		}
		

	}
	else if(g_stStatusCmd.WBMode == _WB_MODE_MANUAL_R)
	{
		if(g_stStatusCmd.uiRGain < 255)
		{
			g_stStatusCmd.uiRGain += 1;
			CAM_SetRGainDirect(g_stStatusCmd.uiRGain);
			g_bTitle2Change = true;
		}
	}
	else if(g_stStatusCmd.WBMode == _WB_MODE_MANUAL_B)
	{
		if(g_stStatusCmd.uiBGain < 255)
		{
			g_stStatusCmd.uiBGain += 1;
			CAM_SetBGainDirect(g_stStatusCmd.uiBGain);
			g_bTitle2Change = true;
		}
	}
	
	return;
}

void ProcessTime(void)
{
	/*
	switch(g_stStatusCmd.FlipMode)
	{
		case _FLIP_MODE_NORMAL:
		case _MIRROR_MODE_OFF:
		{
			CAM_SetFlipOn();
			g_stStatusCmd.FlipMode = _FLIP_MODE_ON;
		}
		break;
		case _FLIP_MODE_ON:
		{
			CAM_SetFlipOff();
			g_stStatusCmd.FlipMode = _FLIP_MODE_OFF;
		}
		break;
		case _FLIP_MODE_OFF:
		{
			CAM_SetMirrorOn();
			g_stStatusCmd.FlipMode = _MIRROR_MODE_ON;
		}
		break;
		case _MIRROR_MODE_ON:
		{
			CAM_SetMirrorOff();
			g_stStatusCmd.FlipMode = _MIRROR_MODE_OFF;
		}
		break;
		default:
		//error
		break;
	}
	*/
	
	if (true == g_stStatusCmd.bIsTime)
	{
		g_stStatusCmd.bIsTime = false;
	} 
	else
	{
		g_stStatusCmd.bIsTime = true;
	}
	
	g_bTitle2Change = true;
	
	return;
}

void ProcessWhite(void)
{
	if(g_stStatusCmd.WBMode == _WB_MODE_NORMAL)
	{
		if (_GREEN_MODE_NORMAL == g_stStatusCmd.GreenMode)
		{
			switch(g_stStatusCmd.WhiteMode)
			{
				case _WHITE_MODE_NORMAL:
				{
					SetWhiteModeFA();
				}
				break;
				case _WHITE_MODE_FA:
				{
					SetWhiteModeFB();
				}
				break;
				case _WHITE_MODE_FB:
				{
					SetWhiteModeNormal();
				}
				break;
				default:
				//error
				break;
			}
		}
		else
		{
			CAM_SetRGainDirect(g_stStatusCmd.uiRGainCurrent);
			g_stStatusCmd.GreenMode = _GREEN_MODE_NORMAL;
			g_stStatusCmd.WhiteMode = _WHITE_MODE_NORMAL;
			_delay_ms(100);
		}
		
		g_bTitle2Change = true;

	}
	else
	{
		UnSaveRBGainValue();
	}
	
	return;
}

void ProcessFilter(void)
{
	if(g_stStatusCmd.WBMode == _WB_MODE_NORMAL)
	{
		if(_WHITE_MODE_NORMAL != g_stStatusCmd.WhiteMode)
		{
			SetWhiteModeNormal();
		}
		
		switch(g_stStatusCmd.GreenMode)
		{
			#if(_KEY_NUM == 61)
				case _GREEN_MODE_NORMAL:
				{
					SetFilterG1();
				}
				break;
				case _GREEN_MODE_G1:
				{
					SetFilterG2();
				}
				break;
				case _GREEN_MODE_G2:
				{
					SetFilterG3();
				}
				break;
				case _GREEN_MODE_G3:
				{
					//设置RGain为120
					CAM_SetRGainDirect(g_stStatusCmd.uiRGain);
					g_stStatusCmd.GreenMode = _GREEN_MODE_NORMAL;
					g_stStatusCmd.bIsDisplay = true;
					#if(_EM_KEY == 1)
					g_stStatusCmd.bIsTime = true;
					g_bTitle2Change = true;
					#endif	
					g_bTitle1Change = true;
				}
				break;
			#else
				case _GREEN_MODE_NORMAL:
				case _GREEN_MODE_G3:
				{
					SetFilterG1();
				}
				break;
				case _GREEN_MODE_G1:
				{
					SetFilterG2();
				}
				break;
				case _GREEN_MODE_G2:
				{
					SetFilterG3();
				}
				break;
			#endif
			default:
			//error
			break;
		}
		
		g_bTitle2Change = true;
	}
	else
	{
		UnSaveRBGainValue();
	}
	
	return;
}

void ProcessFreeze(void)
{	
	if(g_stStatusCmd.WBMode == _WB_MODE_NORMAL)
	{
		if (true == g_stStatusCmd.bIsStill)
		{
			CAM_SetFreezeOff();
			g_stStatusCmd.bIsStill = false;
		} 
		else
		{
			CAM_SetFreezeOn();
			g_stStatusCmd.bIsStill = true;
			g_stStatusCmd.uiDisplayFlag |= _DISPLAY_STILL;
		}

		g_bTitle1Change = true;
	}
	else
	{
		SaveRBGainValue();
	}
	
	return;
}
void ProcessEM(void)
{

	switch(g_stStatusCmd.FlipMode)
	{
		case _FLIP_MODE_NORMAL:
		case _FLIP_MODE_OFF:
		{
			SetMirrorOn();
		}
		break;
		case _MIRROR_MODE_ON:
		{
			SetMirrorOff();
		}
		break;
		case _MIRROR_MODE_OFF:
		{
			SetFlipOn();
		}
		break;
		case _FLIP_MODE_ON:
		{
			SetFlipOff();
		}
		break;
		default:
		//error
		break;
	}


	g_bTitle1Change = true;
	g_bTitle2Change = true;
	
	return;
}
void ProcessAutoWB(void)
{
	if(g_stStatusCmd.WBMode == _WB_MODE_NORMAL)
	{
		LedFlashing(3);
					
		g_stStatusCmd.WBMode = _WB_MODE_AUTO;
		CAM_SetWBATW();

		//Inq R Gain
		CAM_InqRGain();
		_delay_ms(100);
		//USART_GetCommand(g_stCameraCmd.InquiryResult,&g_stCameraCmd.InquiryResultLength);
		GetInquiryResult(&g_stCameraCmd);
		g_stStatusCmd.uiRGain = GetRGain();

		//Inq B Gain
		CAM_InqBGain();
		_delay_ms(100);
		//USART_GetCommand(g_stCameraCmd.InquiryResult,&g_stCameraCmd.InquiryResultLength);
		GetInquiryResult(&g_stCameraCmd);
		g_stStatusCmd.uiBGain = GetBGain();

		//save current value in the buff
		eeprom_write_byte((uint8_t *)0x00,g_stStatusCmd.uiRGain);
		_delay_ms(200);
		eeprom_write_byte((uint8_t *)0x01,g_stStatusCmd.uiBGain);
		
		g_bTitle1Change = true;
	}
	return;
}

void ProcessManualWB(void)
{
	if(g_stStatusCmd.WBMode == _WB_MODE_NORMAL)
	{
		LedFlashing(3);
		g_stStatusCmd.WBMode = _WB_MODE_MANUAL_R;
		CAM_SetWBMaunal();

		//Inq R Gain
		CAM_InqRGain();
		_delay_ms(100);
		GetInquiryResult(&g_stCameraCmd);
		g_stStatusCmd.uiRGain = GetRGain();

		//Inq B Gain
		CAM_InqBGain();
		_delay_ms(100);
		GetInquiryResult(&g_stCameraCmd);
		g_stStatusCmd.uiBGain = GetBGain();

		//save current value in the buff
		eeprom_write_byte((uint8_t *)0x00,g_stStatusCmd.uiRGain);
		_delay_ms(300);
		eeprom_write_byte((uint8_t *)0x01,g_stStatusCmd.uiBGain);

		g_bTitle1Change = true;
		g_bTitle2Change = true;
	}
	return;
}

void ProcessSwitchRB(void)
{
	switch(g_stStatusCmd.WBMode)
	{
		case _WB_MODE_NORMAL:
		{
			LedFlashing(3);
			if (_ZOOM_MODE_GRADING == g_stStatusCmd.ZoomMode)
			{
				g_stStatusCmd.ZoomMode = _ZOOM_MODE_STEPLESS;
			} 
			else
			{
				CAM_SetZoomStop();
				g_stStatusCmd.bStartZoomIn= false;
				g_stStatusCmd.bStartZoomOut= false;
				g_stStatusCmd.ZoomMode = _ZOOM_MODE_GRADING;
			}	

		}
		break;
		case _WB_MODE_AUTO:
		break;
		case _WB_MODE_MANUAL_R:
			LedFlashing(3);
			g_stStatusCmd.WBMode = _WB_MODE_MANUAL_B;
		break;
		case _WB_MODE_MANUAL_B:
			LedFlashing(3);
			g_stStatusCmd.WBMode = _WB_MODE_MANUAL_R;
		break;
		default:
		break;
	}

	return;
}

void CMessageHandle(void)
{
	switch(g_ucKeyMessage)
	{
		case _AF_KEY_MESSAGE:
		ProcessAF();
		break;
		
		case _WIDE_KEY_MESSAGE:
		ProcessWide();
		break;
		
		case _DISPLAY_KEY_MESSAGE:
		ProcessDisplay();
		break;
		
		case _TELE_KEY_MESSAGE:
		ProcessTele();
		break;
		
		case _TIME_KEY_MESSAGE:
		#if(_KEY_NUM==8&&_EM_KEY==1)
		ProcessEM();
		#else
		ProcessTime();
		#endif
		break;
		
		case _WHITE_KEY_MESSAGE:
		ProcessWhite();
		break;
		
		case  _FILTER_KEY_MESSAGE:
		ProcessFilter();
		break;
		
		case _FREEZE_KEY_MESSAGE:
		ProcessFreeze();
		break;

		case _EM_KEY_MESSAGE:
		ProcessEM();
		break;
		
		case _AWB_KEY_MESSAGE:
		ProcessAutoWB();
		break;
		
		case _MWB_KEY_MESSAGE:
		ProcessManualWB();
		break;
		
		case _RB_SWITCH_KEY_MESSAGE:
		ProcessSwitchRB();
		break;
		
		default:
		break;
	}
	
	switch(g_ucRemoteMessage)
	{
		case _AF_KEY_MESSAGE:
		ProcessAF();
		break;
		
		case _WIDE_KEY_MESSAGE:
		ProcessWide();
		break;
		
		case _DISPLAY_KEY_MESSAGE:
		ProcessDisplay();
		break;
		
		case _TELE_KEY_MESSAGE:
		ProcessTele();
		break;
		
		case _TIME_KEY_MESSAGE:
		#if(_KEY_NUM==8&&_EM_KEY==1)
		ProcessEM();
		#else
		ProcessTime();
		#endif
		break;
		
		case _WHITE_KEY_MESSAGE:
		ProcessWhite();
		break;
		
		case  _FILTER_KEY_MESSAGE:
		ProcessFilter();
		break;
		
		case _FREEZE_KEY_MESSAGE:
		ProcessFreeze();
		break;
		
		default:
		break;
	}
	
	return;
}

void CReleaseKeyMessageHandle(void)
{
	uint8_t XRate = 1;
	uint8_t CurrentFocus = 0;
	
	bool bDoZoomAndFocusStop = false;
	
	if(g_ucWideKeyRelease)
	{
		g_ucWideKeyRelease = false;
		bDoZoomAndFocusStop = true;
	}
	else if(g_ucTeleKeyRelease)
	{
		g_ucTeleKeyRelease = false;
		bDoZoomAndFocusStop = true;
	}

	if(_FOCUS_MODE_MANUAL == g_stStatusCmd.FocusMode && (true == g_stStatusCmd.bStartFar|| true == g_stStatusCmd.bStartNear))
	{
		
		if(bDoZoomAndFocusStop||(g_stStatusCmd.uiFocusPos >= _FOCUS_POS_8K&&true == g_stStatusCmd.bStartNear))
		{
			#ifdef _DEBUG_PRINTF
			MyPrintf("Stop Focus\r\n");
			#endif
			//Tune the manual focus, temporary measure, need solved.

			if(g_stStatusCmd.uiXRate<3)
				_delay_ms(1);
			else if(g_stStatusCmd.uiXRate<4)
				_delay_ms(50);
			else if(g_stStatusCmd.uiXRate<7)
				_delay_ms(80);
			else if(g_stStatusCmd.uiXRate<10)
				_delay_ms(200);
			else
				_delay_ms(350);

			//temporary measure, need solved.
			CAM_SetStopFocus();
			g_stStatusCmd.bStartFar = false;
			g_stStatusCmd.bStartNear = false;

			_delay_ms(50);
		
		}
		CAM_InqFocusPos();
		_delay_ms(150);
		GetInquiryResult(&g_stCameraCmd);
		g_stStatusCmd.uiFocusPos = GetFocusPos();
		if(g_u16FocusEnding != g_stStatusCmd.uiFocusPos)
		{
			g_u16FocusEnding = g_stStatusCmd.uiFocusPos;
			g_u8FocusGetMaxCount = 0;
			if(g_stStatusCmd.uiDisplayFlag&_DISPLAY_FOCUS_END)
			{
				g_stStatusCmd.uiDisplayFlag &= ~_DISPLAY_FOCUS_END;
				g_bTitle2Change = true;
			}

		}
		else
		{
			g_u8FocusGetMaxCount++;
			if(g_u8FocusGetMaxCount > 1)
			{
				if(!(g_stStatusCmd.uiDisplayFlag&_DISPLAY_FOCUS_END))
				{
					g_stStatusCmd.uiDisplayFlag |= _DISPLAY_FOCUS_END;
					g_bTitle2Change = true;
				}
			}
		}
		g_stStatusCmd.uiMF = GetMfRateByPos();
		
		if(g_stStatusCmd.uiMF != g_stStatusCmd.uiMFShow)
			g_bTitle1Change = true;
		else
			g_bTitle1Change = false;
	}
	else if (_ZOOM_MODE_STEPLESS == g_stStatusCmd.ZoomMode && (true == g_stStatusCmd.bStartZoomIn|| true == g_stStatusCmd.bStartZoomOut))
	{
		

		if(bDoZoomAndFocusStop||(g_stStatusCmd.uiZoomPos >= uiZoomRatioTable[_MAX_RATE-1]&&true == g_stStatusCmd.bStartZoomIn))
		{
			#ifdef _DEBUG_PRINTF
			MyPrintf("Stop Zoom\r\n");
			#endif
			#if(_CCD_TYPE_CODE == _CCD_480)
			_delay_ms(50);
			#else
			_delay_ms(150);
			#endif
			CAM_SetZoomStop();
			g_stStatusCmd.bStartZoomIn= false;
			g_stStatusCmd.bStartZoomOut= false;

			_delay_ms(50);
		}
		CAM_InqZoomPos();
		_delay_ms(150);
		GetInquiryResult(&g_stCameraCmd);
		g_stStatusCmd.uiZoomPos = GetZoomPos();
		g_stStatusCmd.uiXRate = GetXRateByPos();
		
		if(g_stStatusCmd.uiXRate != g_stStatusCmd.uiXRateShow)
			g_bTitle1Change = true;
		else
			g_bTitle1Change = false;

		
	}

	return;
}
void WhiteBalanceHandle(void)
{
	switch(g_stStatusCmd.WBMode)
	{
		case _WB_MODE_AUTO:
			//Inq R Gain
			CAM_InqRGain();
			_delay_ms(30);
			//USART_GetCommand(g_stCameraCmd.InquiryResult,&g_stCameraCmd.InquiryResultLength);
			GetInquiryResult(&g_stCameraCmd);
			g_stStatusCmd.uiRGain = GetRGain();
			
			//Inq B Gain
			CAM_InqBGain();
			_delay_ms(30);
			//USART_GetCommand(g_stCameraCmd.InquiryResult,&g_stCameraCmd.InquiryResultLength);
			GetInquiryResult(&g_stCameraCmd);
			g_stStatusCmd.uiBGain = GetBGain();


			//show RB
			g_bTitle2Change = true;
		break;
		default:
		break;
	}
}
void SetWhiteModeNormal(void)
{
#if(_CCD_TYPE_CODE == _CCD_7500)
	CAM_SetVideoColor();
	_delay_ms(100);
	CAM_SetSharpnessDefault();

#else
	CAM_SetPicEffectOff();
	_delay_ms(100);
	CAM_SetApertureReset();

#endif
	
	g_stStatusCmd.WhiteMode = _WHITE_MODE_NORMAL;
}
void SetWhiteModeFA(void)
{
#if(_CCD_TYPE_CODE == _CCD_7500)
	CAM_SetSharpnessDirect();
	_delay_ms(100);
#else
	CAM_SetApertureDirect();
#endif
	g_stStatusCmd.WhiteMode = _WHITE_MODE_FA;
	#if(_WHITE_SET_DISPLAY == 1)
	g_stStatusCmd.bIsDisplay = true;
	
	#endif
	g_stStatusCmd.uiDisplayFlag |= _DISPLAY_WHITE;
	g_stStatusCmd.uiDisplayFlag |= _DISPLAY_ZOOM;
	g_bTitle1Change = true;
}

void SetWhiteModeFB(void)
{
#if(_CCD_TYPE_CODE == _CCD_7500)
	CAM_SetVideoBW();
	_delay_ms(100);
#else
	CAM_SetPicEffectBW();
#endif
	g_stStatusCmd.WhiteMode = _WHITE_MODE_FB;
	#if(_WHITE_SET_DISPLAY == 1)
	g_stStatusCmd.bIsDisplay = true;
	
	#endif
	g_stStatusCmd.uiDisplayFlag |= _DISPLAY_WHITE;
	g_stStatusCmd.uiDisplayFlag |= _DISPLAY_ZOOM;
	g_bTitle1Change = true;
}
void SetFilterG1(void)
{

//设置RGain为193
	CAM_SetRGainDirect(_G1_R_GAIN);
	g_stStatusCmd.GreenMode = _GREEN_MODE_G1;
	#if(_FILTER_SET_DISPLAY == 1)
	g_stStatusCmd.bIsDisplay = true;
	
	#endif
	g_stStatusCmd.uiDisplayFlag |= _DISPLAY_FILTER;
	g_stStatusCmd.uiDisplayFlag |= _DISPLAY_ZOOM;
	g_bTitle1Change = true;
	#if(_CCD_TYPE_CODE == _CCD_7500)
	_delay_ms(100);
	#endif
}
void SetFilterG2(void)
{
//设置RGain为168
	CAM_SetRGainDirect(_G2_R_GAIN);
	g_stStatusCmd.GreenMode = _GREEN_MODE_G2;
	#if(_FILTER_SET_DISPLAY == 1)
	g_stStatusCmd.bIsDisplay = true;
	
	#endif
	g_stStatusCmd.uiDisplayFlag |= _DISPLAY_FILTER;
	g_stStatusCmd.uiDisplayFlag |= _DISPLAY_ZOOM;
	g_bTitle1Change = true;
		#if(_CCD_TYPE_CODE == _CCD_7500)
	_delay_ms(100);
	#endif

}
void SetFilterG3(void)
{
//设置RGain为120
	CAM_SetRGainDirect(_G3_R_GAIN);
	g_stStatusCmd.GreenMode = _GREEN_MODE_G3;
	#if(_FILTER_SET_DISPLAY == 1)
	g_stStatusCmd.bIsDisplay = true;
	
	#endif
	g_stStatusCmd.uiDisplayFlag |= _DISPLAY_FILTER;
	g_stStatusCmd.uiDisplayFlag |= _DISPLAY_ZOOM;
	g_bTitle1Change = true;
	#if(_CCD_TYPE_CODE == _CCD_7500)
	_delay_ms(100);
	#endif


}
void SaveRBGainValue(void)
{
	CAM_SetWBMaunal();
	g_stStatusCmd.WBMode = _WB_MODE_NORMAL;
	CAM_SetRGainDirect(g_stStatusCmd.uiRGain);
	eeprom_write_byte((uint8_t *)0x00,g_stStatusCmd.uiRGain);
	_delay_ms(200);
	CAM_SetBGainDirect(g_stStatusCmd.uiBGain);
	eeprom_write_byte((uint8_t *)0x01,g_stStatusCmd.uiBGain);
	g_bTitle1Change = true;
	g_bTitle2Change = true;
	_delay_ms(200);
}
void UnSaveRBGainValue(void)
{
	CAM_SetWBMaunal();
	g_stStatusCmd.WBMode = _WB_MODE_NORMAL;
	g_stStatusCmd.uiRGain = eeprom_read_byte((uint8_t *)0x00);
	g_stStatusCmd.uiBGain = eeprom_read_byte((uint8_t *)0x01);
	CAM_SetRGainDirect(g_stStatusCmd.uiRGain);
	_delay_ms(100);
	CAM_SetBGainDirect(g_stStatusCmd.uiBGain);
	g_bTitle1Change = true;
	g_bTitle2Change = true;
	_delay_ms(100);
}

void SetMirrorOn(void)
{
	CAM_SetMirrorOn();
	g_stStatusCmd.FlipMode = _MIRROR_MODE_ON;
	g_stStatusCmd.bIsDisplay = true;
	g_stStatusCmd.uiDisplayFlag |= _DISPLAY_EM;
	g_stStatusCmd.uiDisplayFlag |= _DISPLAY_ZOOM;
	g_stStatusCmd.uiDisplayFlag &= ~_DISPLAY_FOCUS;
	g_stStatusCmd.bIsTime = true;

	#if(_KEY_NUM == 61)
	g_stStatusCmd.titleDis.TitleColor = _TITLE_COLOR_CYAN;
	#else
	g_stStatusCmd.titleDis.TitleColor = _TITLE_COLOR_VIOLET;
	#endif
	
	g_stStatusCmd.titleDis.uiTitleVPos = 0x01;
	g_stStatusCmd.titleDis.uiTitleHPos = 0x01;
	
	g_stStatusCmd.titleDis.TitleBlink = _TITLE_BLINK_ON;
	CAM_SetTitleSet1(g_stStatusCmd.titleDis);
	#if(_CCD_TYPE_CODE == _CCD_7500)
	_delay_ms(100);
	#endif
}
void SetMirrorOff(void)
{
	CAM_SetMirrorOff();
	g_stStatusCmd.FlipMode = _MIRROR_MODE_OFF;
	g_stStatusCmd.bIsDisplay = false;
	g_stStatusCmd.uiDisplayFlag &=~ _DISPLAY_EM;
	g_stStatusCmd.uiDisplayFlag &= ~_DISPLAY_ZOOM;
	g_stStatusCmd.bIsTime = false;

	g_stStatusCmd.titleDis.uiTitleVPos = 0x0a;
	g_stStatusCmd.titleDis.uiTitleHPos = 0x01;
	g_stStatusCmd.titleDis.TitleColor = _TITLE_COLOR_YELLOW;
	g_stStatusCmd.titleDis.TitleBlink = _TITLE_BLINK_OFF;
	CAM_SetTitleSet1(g_stStatusCmd.titleDis);
	#if(_CCD_TYPE_CODE == _CCD_7500)
	_delay_ms(100);
	#endif

}
void SetFlipOn(void)
{
	CAM_SetFlipOn();
	g_stStatusCmd.FlipMode = _FLIP_MODE_ON;
	g_stStatusCmd.bIsDisplay = true;
	g_stStatusCmd.uiDisplayFlag |= _DISPLAY_EM;
	g_stStatusCmd.uiDisplayFlag |= _DISPLAY_ZOOM;
	g_stStatusCmd.uiDisplayFlag &= ~_DISPLAY_FOCUS;
	g_stStatusCmd.bIsTime = true;

	#if(_KEY_NUM == 61)
	g_stStatusCmd.titleDis.TitleColor = _TITLE_COLOR_CYAN;
	#else
	g_stStatusCmd.titleDis.TitleColor = _TITLE_COLOR_VIOLET;
	#endif
	
	g_stStatusCmd.titleDis.uiTitleVPos = 0x01;
	g_stStatusCmd.titleDis.uiTitleHPos = 0x01;
	
	g_stStatusCmd.titleDis.TitleBlink = _TITLE_BLINK_ON;
	CAM_SetTitleSet1(g_stStatusCmd.titleDis);
	#if(_CCD_TYPE_CODE == _CCD_7500)
	_delay_ms(100);
	#endif

}
void SetFlipOff(void)
{
	CAM_SetFlipOff();
	g_stStatusCmd.FlipMode = _FLIP_MODE_OFF;
	g_stStatusCmd.bIsDisplay = false;
	g_stStatusCmd.uiDisplayFlag &=~ _DISPLAY_EM;
	g_stStatusCmd.uiDisplayFlag &= ~_DISPLAY_ZOOM;
	g_stStatusCmd.bIsTime = false;

	g_stStatusCmd.titleDis.uiTitleVPos = 0x0a;
	g_stStatusCmd.titleDis.uiTitleHPos = 0x01;
	g_stStatusCmd.titleDis.TitleColor = _TITLE_COLOR_YELLOW;
	g_stStatusCmd.titleDis.TitleBlink = _TITLE_BLINK_OFF;
	CAM_SetTitleSet1(g_stStatusCmd.titleDis);
	#if(_CCD_TYPE_CODE == _CCD_7500)
	_delay_ms(100);
	#endif

}

