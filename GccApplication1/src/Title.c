/*
 * Title.c
 *
 * Created: 2015/2/6 16:07:43
 *  Author: USER
 */ 
#include "include.h"

#if(_CCD_TYPE_CODE == _CCD_7500)
uint8_t uiNumberTable[16] = {0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x41,0x42,0x43,0x44,0x45,0x46};
#else
uint8_t uiNumberTable[16] = {0x27,0x1e,0x1f,0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x00,0x01,0x02,0x03,0x04,0x05};
#endif
bool g_bTitle1Change = false;
bool g_bTitle2Change = false;


void SetTitle2(void)
{
	uint8_t i = 0;
	uint8_t j = 0;
	#if(_CCD_TYPE_CODE == _CCD_7500)
	uint8_t uiTitle[10] = {0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20};//space
	#else
	uint8_t uiTitle[10] = {0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b};//space
	#endif

	#if(_EM_KEY == 1)
	// if display EM flip
	if (g_stStatusCmd.FlipMode == _FLIP_MODE_ON)
	{
	/*
		#if(_KEY_NUM == _KEY_MODE_6KEY_EM)

			#if(_CCD_TYPE_CODE == _CCD_7500)
			uiTitle[5] = 'E'; //
			uiTitle[6] = '/'; //
			uiTitle[7] = 'F'; //


			#else
			uiTitle[5] = 0x04; //E
			uiTitle[6] = 0x4E; ///
			uiTitle[7] = 0x05; //F

			#endif
		#else
			*/
			#if(_CCD_TYPE_CODE == _CCD_7500)
			uiTitle[5] = 'F'; //
			uiTitle[6] = 'L'; //
			uiTitle[7] = 'I'; //
			uiTitle[8] = 'P'; //
			uiTitle[9] = ' '; //

			#else
			uiTitle[5] = 0x05; //F
			uiTitle[6] = 0x0B; //L
			uiTitle[7] = 0x08; //I
			uiTitle[8] = 0x0F; //P
			uiTitle[9] = 0x1b; // 
			#endif
		//#endif

	}
	else if(g_stStatusCmd.FlipMode == _MIRROR_MODE_ON)
	{
	/*
		#if(_KEY_NUM == _KEY_MODE_6KEY_EM)
			
			#if(_CCD_TYPE_CODE == _CCD_7500)
			uiTitle[5] = 'E'; //
			uiTitle[6] = '/'; //
			uiTitle[7] = 'M'; //

			#else
			uiTitle[5] = 0x04; //E
			uiTitle[6] = 0x4E; ///
			uiTitle[7] = 0x0C; //M
			#endif
		#else
			*/
			#if(_CCD_TYPE_CODE == _CCD_7500)
			uiTitle[5] = 'I'; //
			uiTitle[6] = 'M'; //
			uiTitle[7] = 'A'; //
			uiTitle[8] = 'G'; //
			uiTitle[9] = 'E'; //
			#else
			uiTitle[5] = 0x08; //I
			uiTitle[6] = 0x0C; //M
			uiTitle[7] = 0x00; //A
			uiTitle[8] = 0x06; //G
			uiTitle[9] = 0x04; //E
			#endif
		//#endif

	}
	#endif
	
	// if display X08

	if ((true == g_stStatusCmd.bIsDisplay)&&(_DISPLAY_ZOOM& g_stStatusCmd.uiDisplayFlag))
	{
		i = (g_stStatusCmd.uiXRate+1)/10;
		j = (g_stStatusCmd.uiXRate+1)%10;
		#if(_CCD_TYPE_CODE == _CCD_7500)
		uiTitle[1] = 'X'; //0x58
		#else
		uiTitle[1] = 0x17; //X
		#endif
		uiTitle[2] = uiNumberTable[i];
		uiTitle[3] = uiNumberTable[j];
		g_stStatusCmd.uiXRateShow = g_stStatusCmd.uiXRate;
	}
	else
	{

	}
		
	// if display MF-0
	if ((_FOCUS_MODE_MANUAL == g_stStatusCmd.FocusMode)&&(_DISPLAY_FOCUS& g_stStatusCmd.uiDisplayFlag))
	{
		if (g_stStatusCmd.uiMF>=0)
		{
			
			#if(_CCD_TYPE_CODE == _CCD_7500)
			uiTitle[5] = 'M'; //0x4D
			uiTitle[6] = 'F'; //0x46
			uiTitle[7] = '-'; //0x2D
			#else
			uiTitle[5] = 0x0c; //M
			uiTitle[6] = 0x05; //F
			uiTitle[7] = 0x4f; //-
			#endif
			uiTitle[8] = uiNumberTable[g_stStatusCmd.uiMF];
			g_stStatusCmd.uiMFShow = g_stStatusCmd.uiMF;
		}
		else
		{
			//error
		}
	}
	else
	{

	}
	
	
	// if display still
	if ((true == g_stStatusCmd.bIsStill)&&(_DISPLAY_STILL& g_stStatusCmd.uiDisplayFlag))
	{
			#if(_CCD_TYPE_CODE == _CCD_7500)
			uiTitle[5] = 'S'; //
			uiTitle[6] = 'T'; //
			uiTitle[7] = 'I'; //
			uiTitle[8] = 'L'; //
			uiTitle[9] = 'L'; //
			#else
			uiTitle[5] = 0x12; //S
			uiTitle[6] = 0x13; //T
			uiTitle[7] = 0x08; //I
			uiTitle[8] = 0x0B; //L
			uiTitle[9] = 0x0B; //L
			#endif
		
	}
	else
	{
		#if 0//(_KEY_NUM == _KEY_MODE_6KEY_EM)
		#if(_CCD_TYPE_CODE == _CCD_7500)
		uiTitle[5] = ' '; //
		uiTitle[6] = ' '; //
		uiTitle[7] = ' '; //
		uiTitle[8] = ' '; //
		uiTitle[9] = ' '; //
		#else
		uiTitle[5] = 0x1b; //I
		uiTitle[6] = 0x1b; //M
		uiTitle[7] = 0x1b; //A
		uiTitle[8] = 0x1b; //G
		uiTitle[9] = 0x1b; //E
		#endif
		g_stStatusCmd.titleDis.uiTitleVPos = 0x0a;
		g_stStatusCmd.titleDis.uiTitleHPos = 0x01;
		g_stStatusCmd.titleDis.TitleColor = _TITLE_COLOR_YELLOW;
		g_stStatusCmd.titleDis.TitleBlink = _TITLE_BLINK_OFF;
		CAM_SetTitleSet1(g_stStatusCmd.titleDis);
		_delay_ms(300);
		#endif
	}

	// if display WB
	if (g_stStatusCmd.WBMode == _WB_MODE_AUTO)
	{
		#if(_CCD_TYPE_CODE == _CCD_7500)
		uiTitle[0] = 'W'; //0x57
		uiTitle[1] = ':'; //0x3A
		uiTitle[2] = 'A'; //0x41
		uiTitle[3] = 'D'; //0x44
		uiTitle[4] = 'J'; //0x4A
		uiTitle[5] = '-'; //0x2D
		uiTitle[6] = 'A'; //0x41
		uiTitle[7] = 'T'; //0x54
		uiTitle[8] = 'W'; //0x57
		#else
		uiTitle[0] = 0x16; //W
		uiTitle[1] = 0x4A; //:
		uiTitle[2] = 0x00; //A
		uiTitle[3] = 0x03; //D
		uiTitle[4] = 0x09; //J
		uiTitle[5] = 0x4F; //-
		uiTitle[6] = 0x00; //A
		uiTitle[7] = 0x13; //T
		uiTitle[8] = 0x16; //W
		#endif
	}
	else if(g_stStatusCmd.WBMode == _WB_MODE_MANUAL_B || g_stStatusCmd.WBMode == _WB_MODE_MANUAL_R)
	{
		#if(_CCD_TYPE_CODE == _CCD_7500)
		uiTitle[0] = 'W'; //0x57
		uiTitle[1] = ':'; //0x3A
		uiTitle[2] = 'A'; //0x41
		uiTitle[3] = 'D'; //0x44
		uiTitle[4] = 'J'; //0x4A
		uiTitle[5] = '-'; //0x2D
		uiTitle[6] = 'M'; //0x4D
		uiTitle[7] = 'A'; //0x41
		uiTitle[8] = 'N'; //0x4E
		#else
		uiTitle[0] = 0x16; //W
		uiTitle[1] = 0x4A; //:
		uiTitle[2] = 0x00; //A
		uiTitle[3] = 0x03; //D
		uiTitle[4] = 0x09; //J
		uiTitle[5] = 0x4F; //-
		uiTitle[6] = 0x0C; //M
		uiTitle[7] = 0x00; //A
		uiTitle[8] = 0x0D; //N
		#endif
	}

	
	
	#if(_CCD_TYPE_CODE == _CCD_7500)
	_delay_ms(100);
	#endif

		CAM_SetTitleSet2(g_stStatusCmd.titleDis.uiTitleVPos, uiTitle);
	#if(_CCD_TYPE_CODE == _CCD_7500)
	_delay_ms(100);
	#endif
}

void SetTitle3(void)
{
	uint8_t i = 0;
	uint8_t j = 0;
	static uint8_t ucMinuteCnt = 0;
	static uint8_t ucSecondCnt = 0;
	#if(_CCD_TYPE_CODE == _CCD_7500)
	uint8_t uiTitle[10] = {0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20};//space
	#else
	uint8_t uiTitle[10] = {0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b};//space
	#endif

	//if display focus end
	if((_FOCUS_MODE_MANUAL == g_stStatusCmd.FocusMode)&&(_DISPLAY_FOCUS& g_stStatusCmd.uiDisplayFlag)&&(_DISPLAY_FOCUS_END& g_stStatusCmd.uiDisplayFlag))
	{
		#if(_CCD_TYPE_CODE == _CCD_7500)
			uiTitle[1] = 'E'; //0x46
			uiTitle[2] = 'N'; //0x41
			uiTitle[3] = 'D'; //0x41
			#else
			uiTitle[1] = 0x04; //E
			uiTitle[2] = 0x0D; //N
			uiTitle[3] = 0x03; //D
			#endif
	}

	// if display White
	if ((true == g_stStatusCmd.bIsDisplay)&&(_DISPLAY_WHITE& g_stStatusCmd.uiDisplayFlag))
	{
		if (_WHITE_MODE_FA == g_stStatusCmd.WhiteMode)
		{
			#if(_CCD_TYPE_CODE == _CCD_7500)
			uiTitle[1] = 'F'; //0x46
			uiTitle[2] = 'A'; //0x41
			uiTitle[3] = ' '; //0x41
			#else
			uiTitle[1] = 0x05; //F
			uiTitle[2] = 0x00; //A
			uiTitle[3] = 0x1B; //A
			#endif
		}
		else if (_WHITE_MODE_FB == g_stStatusCmd.WhiteMode)
		{
			#if(_CCD_TYPE_CODE == _CCD_7500)
			uiTitle[1] = 'F'; //0x46
			uiTitle[2] = 'B'; //0x42
			#else
			uiTitle[1] = 0x05; //F
			uiTitle[2] = 0x01; //B
			uiTitle[3] = 0x1B; //A
			#endif
		} 
		else
		{
		}
	}

	//if display filter
	if ((g_stStatusCmd.FilterMode !=_FILTER_MODE_NORMAL)&&((_DISPLAY_FILTER& g_stStatusCmd.uiDisplayFlag)||(_DISPLAY_WHITE& g_stStatusCmd.uiDisplayFlag)))
	{
		if(g_stStatusCmd.FilterMode<=_FILTER_MODE_G3)
		{
			#if(_CCD_TYPE_CODE == _CCD_7500)
			uiTitle[1] = 'G'; //0x47
			uiTitle[2] = uiNumberTable[(uint8_t)g_stStatusCmd.FilterMode]; //
			uiTitle[3] = ' '; //A
			#else
			uiTitle[1] = 0x06; //G
			uiTitle[2] = uiNumberTable[(uint8_t)g_stStatusCmd.FilterMode]; //
			uiTitle[3] = 0x1B; //A
			#endif
		}
		else if(g_stStatusCmd.FilterMode==_FILTER_MODE_FA)
		{
			#if(_CCD_TYPE_CODE == _CCD_7500)
			uiTitle[1] = 'F'; //0x46
			uiTitle[2] = 'A'; //0x41
			uiTitle[3] = ' '; //0x41
			#else
			uiTitle[1] = 0x05; //F
			uiTitle[2] = 0x00; //A
			uiTitle[3] = 0x1B; //A
			#endif
		}
		else if(g_stStatusCmd.FilterMode==_FILTER_MODE_FB)
		{
			#if(_CCD_TYPE_CODE == _CCD_7500)
			uiTitle[1] = 'F'; //0x46
			uiTitle[2] = 'B'; //0x42
			#else
			uiTitle[1] = 0x05; //F
			uiTitle[2] = 0x01; //B
			uiTitle[3] = 0x1B; //A
			#endif
		}
	}
	
	// if display Green
	if ((true == g_stStatusCmd.bIsDisplay)&&(_DISPLAY_FILTER& g_stStatusCmd.uiDisplayFlag))
	{
		if (g_stStatusCmd.GreenMode==_GREEN_MODE_G1 || g_stStatusCmd.GreenMode==_GREEN_MODE_G2 || g_stStatusCmd.GreenMode==_GREEN_MODE_G3)
		{
			#if(_CCD_TYPE_CODE == _CCD_7500)
			uiTitle[1] = 'G'; //0x47
			uiTitle[2] = uiNumberTable[(uint8_t)g_stStatusCmd.GreenMode]; //
			uiTitle[3] = ' '; //A
			#else
			uiTitle[1] = 0x06; //G
			uiTitle[2] = uiNumberTable[(uint8_t)g_stStatusCmd.GreenMode]; //
			uiTitle[3] = 0x1B; //A
			#endif
		}
		else
		{
		}
	}
	
	// if display Time
	if (true == g_stStatusCmd.bIsTime)
	{
		if (true != g_stStatusCmd.bIsStill)
		{
			ucMinuteCnt = g_ucMinuteCnt;
			ucSecondCnt = g_ucSecondCnt;
		}
		i = ucMinuteCnt/10;
		j = ucMinuteCnt%10;
		uiTitle[5] = uiNumberTable[i];
		uiTitle[6] = uiNumberTable[j];
		#if(_CCD_TYPE_CODE == _CCD_7500)
		uiTitle[7] = ':'; //:
		#else
		uiTitle[7] = 0x4a; //:
		#endif
		i = ucSecondCnt/10;
		j = ucSecondCnt%10;
		uiTitle[8] = uiNumberTable[i];
		uiTitle[9] = uiNumberTable[j];
	}
	else
	{
		ucMinuteCnt = 0;
		ucSecondCnt = 0;
	}

	// if display WB
	if(g_stStatusCmd.WBMode != _WB_MODE_NORMAL)
	{
		#if(_CCD_TYPE_CODE == _CCD_7500)
		uiTitle[0] = 'R'; //0x52
		uiTitle[1] = ':'; //0x3A
		#else
		uiTitle[0] = 0x11; //R
		uiTitle[1] = 0x4A; //:
		#endif
		uiTitle[2] = uiNumberTable[g_stStatusCmd.uiRGain/100]; 
		uiTitle[3] = uiNumberTable[(g_stStatusCmd.uiRGain/10)%10]; 
		uiTitle[4] = uiNumberTable[g_stStatusCmd.uiRGain%10]; 
		#if(_CCD_TYPE_CODE == _CCD_7500)
		uiTitle[5] = 'B'; //0x42
		uiTitle[6] = ':'; //0x3A
		#else
		uiTitle[5] = 0x01; //B
		uiTitle[6] = 0x4A; //:
		#endif
		uiTitle[7] = uiNumberTable[g_stStatusCmd.uiBGain/100]; 
		uiTitle[8] = uiNumberTable[(g_stStatusCmd.uiBGain/10)%10]; 
		uiTitle[9] = uiNumberTable[g_stStatusCmd.uiBGain%10]; 
	}
	
	if (false == g_bTitle2Change && true == g_stStatusCmd.bIsStill)
		return;
	
	CAM_SetTitleSet3(g_stStatusCmd.titleDis.uiTitleVPos, uiTitle);
}

#if(_FOCUS_OOR_TIPS == 1)

void OORDisplay(void)
{
	TITLE_DISPLAY OORDis;
	OORDis.uiTitleHPos = 0x01;
	OORDis.uiTitleVPos = 0x09;
	OORDis.TitleColor = _TITLE_COLOR_YELLOW;
	OORDis.TitleBlink = _TITLE_BLINK_OFF;
	
	#if(_CCD_TYPE_CODE == _CCD_7500)
	uint8_t uiTitle[10] = {0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20};//space
	#else
	uint8_t uiTitle[10] = {0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b};//space
	#endif
	

	//if display focus OOR
	if((_FOCUS_MODE_AUTO == g_stStatusCmd.FocusMode)&&(_DISPLAY_FOCUS_OOR& g_stStatusCmd.uiDisplayFlag))
	{
		if(g_stStatusCmd.uiFocusPos == 0x1000)
		{
			#if(_CCD_TYPE_CODE == _CCD_7500)
			uiTitle[1] = 'T'; //0x46
			uiTitle[2] = 'O'; //0x41
			uiTitle[3] = 'O'; //0x41
			uiTitle[4] = ' '; //0x46
			uiTitle[5] = 'F'; //0x41
			uiTitle[6] = 'A'; //0x41
			uiTitle[7] = 'R'; //0x41
			
			#else
			uiTitle[1] = 0x13; 
			uiTitle[2] = 0x0e; 
			uiTitle[3] = 0x0e; 
			uiTitle[4] = 0x1b; 
			uiTitle[5] = 0x05; 
			uiTitle[6] = 0x00; 
			uiTitle[7] = 0x11; 
			#endif
		}
		else
		{
			
			#if(_CCD_TYPE_CODE == _CCD_7500)
			uiTitle[1] = 'T'; //0x46
			uiTitle[2] = 'O'; //0x41
			uiTitle[3] = 'O'; //0x41
			uiTitle[4] = ' '; //0x46
			uiTitle[5] = 'N'; //0x41
			uiTitle[6] = 'E'; //0x41
			uiTitle[7] = 'A'; //0x41
			uiTitle[8] = 'R'; //0x41
			
			#else
			uiTitle[1] = 0x13; //0x46
			uiTitle[2] = 0x0e; //0x41
			uiTitle[3] = 0x0e; //0x41
			uiTitle[4] = 0x1b; //0x46
			uiTitle[5] = 0x0d; //0x41
			uiTitle[6] = 0x04; //0x41
			uiTitle[7] = 0x00; //0x41
			uiTitle[8] = 0x11; //0x41
			#endif
		}
		
		
		
		CAM_SetTitleSet1(OORDis);
		CAM_SetTitleSet3(OORDis.uiTitleVPos, uiTitle);
		CAM_SetTitleOn(OORDis.uiTitleVPos);
	}
	else
	{
		CAM_SetTitleOff(OORDis.uiTitleVPos);
	}
	
}
#endif

void TitleHandle(void)
{
	if (true == g_bTitle1Change)
	{
		g_bTitle1Change = false;
		SetTitle2();
		_delay_ms(10);
	}
	if (true == g_bTimerChange || true == g_bTitle2Change)
	{
		SetTitle3();		
		#if(_FOCUS_OOR_TIPS == 1)
		OORDisplay();
		#endif
		g_bTimerChange = false;
		g_bTitle2Change = false;
	}

}

void ShowProductInfo(unsigned char LineNum)
{
	uint8_t i,j,k,l,m;
	#if(_CCD_TYPE_CODE == _CCD_7500)
	uint8_t uiTitle[10] = {0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20};//space
	#else
	uint8_t uiTitle[10] = {0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b};//space
	#endif
		
	//uint16_t uiModelCode = GetCameraVersion();
	
	//Product Model
	CAM_SetTitleSet2(LineNum, g_stProductInfo.uiProductModel);
	
	_delay_ms(30);

	#ifdef _SHOW_COMPANY
	CAM_SetTitleSet3(LineNum, g_stProductInfo.uiProductModel2);
	#ifdef _DOUBLE_LINE_INFO
	if(g_stStatusCmd.uiModeID == _CAM_3310)
	{
		uiTitle[2] = 0x07;
		uiTitle[3] = 0x03;
		uiTitle[4] = 0x1b;
		uiTitle[5] = 0x1e;
		uiTitle[6] = 0x4c;
		uiTitle[7] = 0x21;
		uiTitle[8] = 0x20;
		uiTitle[9] = 0x0c;
	}
	else if(g_stStatusCmd.uiModeID == _CAM_6300)
	{
		uiTitle[2] = 0x07;
		uiTitle[3] = 0x03;
		uiTitle[4] = 0x1b;
		uiTitle[5] = 0x20;
		uiTitle[6] = 0x4c;
		uiTitle[7] = 0x1f;
		uiTitle[8] = 0x24;
		uiTitle[9] = 0x0c;
	}
		

	CAM_SetTitleSet2(LineNum+1, uiTitle);

		uiTitle[0] = 0x1b;
		uiTitle[1] = 0x0f;
		uiTitle[2] = 0x08;
		uiTitle[3] = 0x17;
		uiTitle[4] = 0x04;
		uiTitle[5] = 0x0b;
		uiTitle[6] = 0x12;
		uiTitle[7] = 0x1b;
		uiTitle[8] = 0x1b;
		uiTitle[9] = 0x1b;
	CAM_SetTitleSet3(LineNum+1, uiTitle);
	#endif

	
	#else
	#ifdef _GC_SHOW_BEHIND
	m=0;
	uiTitle[m++] = 0x06;
	uiTitle[m++] = 0x02;
	#else
	m = 2;
	#endif
	//Control Software Version
	#if(_CCD_TYPE_CODE == _CCD_7500)
	uiTitle[m++] = 'V';//0x56
	#else
	uiTitle[m++] = 0x15;//V
	#endif
	i = g_stProductInfo.uiMajorVer/10;
	j = g_stProductInfo.uiMajorVer%10;
	if (i>0)
	{
		uiTitle[m++] = uiNumberTable[i];
	}	
	uiTitle[m++] = uiNumberTable[j];
	#if(_CCD_TYPE_CODE == _CCD_7500)
	uiTitle[m++] = '.';//0x2E
	#else
	uiTitle[m++] = 0x4c;//.
	#endif
	
	i = g_stProductInfo.uiMinorVer/10;
	j = g_stProductInfo.uiMinorVer%10;
	uiTitle[m++] = uiNumberTable[i];
	uiTitle[m++] = uiNumberTable[j];	
	
	//Camera Model
	#if(_CCD_TYPE_CODE == _CCD_7500)
	uiTitle[m++] = ' ';//0x2E
	#else
	uiTitle[m++] = 0x1b;//-
	#endif
	switch(g_stStatusCmd.uiModeID)
	{
		case _CAM_480:
			uiTitle[m++] = 0x21;//-
			uiTitle[m++] = 0x25;//-
			break;
		case _CAM_1020:
			uiTitle[m++] = 0x1e;//-
			uiTitle[m++] = 0x27;//-
			break;
		case _CAM_3310:
			uiTitle[m++] = 0x20;//-
			uiTitle[m++] = 0x20;//-
			break;
		case _CAM_6300:
			uiTitle[m++] = 0x23;//-
			uiTitle[m++] = 0x20;//-
			break;
		case _CAM_7500:
			uiTitle[m++] = 0x24;//-
			uiTitle[m++] = 0x22;//-
			break;
	}
	
	//i = (uiModelCode&0xF000)/0x1000;
	//j = (uiModelCode&0x0F00)/0x100;
	//k = (uiModelCode&0x00F0)/0x10;
	//l = (uiModelCode&0x000F)/0x1;
	//uiTitle[6] = uiNumberTable[i];
	//uiTitle[7] = uiNumberTable[j];
	//uiTitle[8] = uiNumberTable[k];
	//uiTitle[9] = uiNumberTable[l];
	
	CAM_SetTitleSet3(LineNum, uiTitle);
	#endif
}

