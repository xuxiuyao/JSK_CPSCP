/*
 * status.c
 *
 * Created: 2015/1/31 15:26:15
 *  Author: USER
 */ 

#include "include.h"

STATUS_CMD g_stStatusCmd;
PRODUCT_INFO g_stProductInfo;


void StatusInit(STATUS_CMD* Cmd)
{
	Cmd->uiCamID = 0;
	Cmd->uiFocusPosMax = 0x7000;
	Cmd->uiRGain = 0;
	Cmd->uiBGain = 0;
	Cmd->uiXRate = 7;
	Cmd->uiXRateShow = 0;//must diffrent with uiXRate!
	Cmd->uiMF = 0;
	Cmd->uiMFShow = 8;//must diffrent with uiMF!
	Cmd->titleDis.TitleColor = _TITLE_COLOR_YELLOW;
	Cmd->titleDis.TitleBlink = _TITLE_BLINK_OFF;
	Cmd->uiApertureGain = 0x0e;
	Cmd->FocusMode = _FOCUS_MODE_AUTO;
	Cmd->uiZoomPos = 0;
	Cmd->uiFocusPos = 0;
	Cmd->bStartFar = false;
	Cmd->bStartZoomOut= false;
	Cmd->bStartNear = false;
	Cmd->bStartZoomIn= false;
	Cmd->bIsDisplay = false;
	Cmd->uiDisplayFlag = _DISPLAY_NULL;
	Cmd->bIsTime = false;
	Cmd->bIsStill = false;
	#ifdef _ALWAYS_SHOW_VERSION
	Cmd->bShowVersion = true;
	#else
	Cmd->bShowVersion = false;
	#endif
	Cmd->WhiteMode = _WHITE_MODE_NORMAL;
	Cmd->GreenMode = _GREEN_MODE_NORMAL;
	Cmd->FilterMode = _FILTER_MODE_NORMAL;
	Cmd->ZoomMode = _ZOOM_MODE_GRADING;
	Cmd->FlipMode = _FLIP_MODE_NORMAL;
	Cmd->WBMode = _WB_MODE_NORMAL;
}

void ProductInfoInit(PRODUCT_INFO* info)
{
	for (uint8_t i=0;i<10;i++)
	{
		#if(_CCD_TYPE_CODE == _CCD_7500)
		info->uiProductModel[i] = 0x20;//space
		info->uiProductModel2[i] = 0x20;//space
		#else
		info->uiProductModel[i] = 0x1b;
		info->uiProductModel2[i] = 0x1b;
		#endif
	}
#if(_CCD_TYPE_CODE == _CCD_7500)
#if(_PRODUCT_TYPE_CODE == _GC_5000B)
	info->uiProductModel[0] = 'G';//G
	info->uiProductModel[1] = 'C';//C
	info->uiProductModel[2] = '-';//-
	info->uiProductModel[3] = '5';// 5
	info->uiProductModel[4] = '0';//0
	info->uiProductModel[5] = '0';//0
	info->uiProductModel[6] = '0';//0
	info->uiProductModel[7] = 'B';//B
	info->uiMajorVer = 2;
	info->uiMinorVer = 5;
#elif(_PRODUCT_TYPE_CODE == _GC_3000E)
	info->uiProductModel[0] = 'G';//G
	info->uiProductModel[1] = 'C';//C
	info->uiProductModel[2] = '-';//-
	info->uiProductModel[3] = '3';// 3
	info->uiProductModel[4] = '0';//0
	info->uiProductModel[5] = '0';//0
	info->uiProductModel[6] = '0';//0
	info->uiProductModel[7] = 'E';//E
	info->uiMajorVer = 2;
	info->uiMinorVer = 5;
#elif(_PRODUCT_TYPE_CODE == _DVC_10000)
	info->uiProductModel[0] = 'D';//D
	info->uiProductModel[1] = 'V';//V
	info->uiProductModel[2] = 'C';//C
	info->uiProductModel[3] = '1';// 1
	info->uiProductModel[4] = '0';//0
	info->uiProductModel[5] = '0';//0
	info->uiProductModel[6] = '0';//0
	info->uiProductModel[7] = '0';//0
	info->uiMajorVer = 2;
	info->uiMinorVer = 5;
#elif(_PRODUCT_TYPE_CODE == _DVC_14000)
	info->uiProductModel[0] = 'D';//D
	info->uiProductModel[1] = 'V';//V
	info->uiProductModel[2] = 'C';//C
	info->uiProductModel[3] = '1';// 1
	info->uiProductModel[4] = '4';// 4
	info->uiProductModel[5] = '0';//0
	info->uiProductModel[6] = '0';//0
	info->uiProductModel[7] = '0';//0
	info->uiMajorVer = 2;
	info->uiMinorVer = 5;
#elif(_PRODUCT_TYPE_CODE == _VC_100)
	info->uiProductModel[0] = 'V';//V
	info->uiProductModel[1] = 'C';//C
	info->uiProductModel[2] = '-';//-
	info->uiProductModel[3] = '1';// 1
	info->uiProductModel[4] = '0';//0
	info->uiProductModel[5] = '0';//0
	//info->uiProductModel[6] = 0x27;//0
	//info->uiProductModel[7] = 0x01;//B
	info->uiMajorVer = 2;
	info->uiMinorVer = 5;
#elif(_PRODUCT_TYPE_CODE == _VC_200)
	info->uiProductModel[0] = 'V';//V
	info->uiProductModel[1] = 'C';//C
	info->uiProductModel[2] = '-';//-
	info->uiProductModel[3] = '2';// 2
	info->uiProductModel[4] = '0';//0
	info->uiProductModel[5] = '0';//0
	//info->uiProductModel[6] = 0x27;//0
	//info->uiProductModel[7] = 0x01;//B
	info->uiMajorVer = 2;
	info->uiMinorVer = 3;
#elif(_PRODUCT_TYPE_CODE == _LT_300)
	info->uiProductModel[0] = 'L';//L
	info->uiProductModel[1] = 'T';//T
	info->uiProductModel[2] = '-';//-
	info->uiProductModel[3] = '3';// 3
	info->uiProductModel[4] = '0';//0
	info->uiProductModel[5] = '0';//0
	//info->uiProductModel[6] = 0x27;//0
	//info->uiProductModel[7] = 0x01;//B
	info->uiMajorVer = 2;
	info->uiMinorVer = 5;
#elif(_PRODUCT_TYPE_CODE == _AL_106B)
	info->uiProductModel[0] = 'A';//A
	info->uiProductModel[1] = 'L';//L
	info->uiProductModel[2] = '-';//-
	info->uiProductModel[3] = '1';// 1
	info->uiProductModel[4] = '0';//0
	info->uiProductModel[5] = '6';//6
	info->uiProductModel[6] = 'B';//B
	//info->uiProductModel[7] = 0x01;//B
	info->uiMajorVer = 2;
	info->uiMinorVer = 5;
#elif(_PRODUCT_TYPE_CODE == _AL_106)
	info->uiProductModel[0] = 'A';//A
	info->uiProductModel[1] = 'L';//L
	info->uiProductModel[2] = '-';//-
	info->uiProductModel[3] = '1';// 1
	info->uiProductModel[4] = '0';//0
	info->uiProductModel[5] = '6';//6
	//info->uiProductModel[6] = 0x27;//0
	//info->uiProductModel[7] = 0x01;//B
	info->uiMajorVer = 2;
	info->uiMinorVer = 5;
#elif(_PRODUCT_TYPE_CODE == _AL_106HD)
	info->uiProductModel[0] = 'A';//A
	info->uiProductModel[1] = 'L';//L
	info->uiProductModel[2] = '-';//-
	info->uiProductModel[3] = '1';// 1
	info->uiProductModel[4] = '0';//0
	info->uiProductModel[5] = '6';//6
	info->uiProductModel[6] = 'H';//H
	info->uiProductModel[7] = 'D';//D
	info->uiMajorVer = 2;
	info->uiMinorVer = 5;
#elif(_PRODUCT_TYPE_CODE == _INDIA_SD)
	info->uiProductModel[0] = 'I';//D
	info->uiProductModel[1] = 'N';//V
	info->uiProductModel[2] = 'D';//C
	info->uiProductModel[3] = 'I';// 1
	info->uiProductModel[4] = 'A';// 4
	info->uiProductModel[5] = ' ';//0
	info->uiProductModel[6] = 'A';//0
	info->uiProductModel[7] = ' ';//0
	info->uiProductModel[8] = 'S';//0
	info->uiProductModel[8] = 'D';//0
	info->uiMajorVer = 1;
	info->uiMinorVer = 0;	
#endif
#else
#if(_PRODUCT_TYPE_CODE == _SW_REG)
	info->uiProductModel[0] = 0x06;//G
	info->uiProductModel[1] = 0x02;//C
	info->uiProductModel[2] = 0x1B;//
	info->uiProductModel[3] = 0x07;//H
	info->uiProductModel[4] = 0x03;//D 
	//info->uiProductModel[5] = 0x07;//H
	//info->uiProductModel[6] = 0x03;//D
	//info->uiProductModel[7] = 0x01;//B
	info->uiMajorVer = 1;
	info->uiMinorVer = 0;
#elif(_PRODUCT_TYPE_CODE == _GC_5000B)
	info->uiProductModel[0] = 0x06;//G
	info->uiProductModel[1] = 0x02;//C
	info->uiProductModel[2] = 0x1B;//
	info->uiProductModel[3] = 0x07;//H
	info->uiProductModel[4] = 0x03;//D 
	//info->uiProductModel[5] = 0x07;//H
	//info->uiProductModel[6] = 0x03;//D
	//info->uiProductModel[7] = 0x01;//B
	info->uiMajorVer = 1;
	info->uiMinorVer = 0;
#elif(_PRODUCT_TYPE_CODE == _GC_3000E)
	info->uiProductModel[0] = 0x06;//G
	info->uiProductModel[1] = 0x02;//C
	info->uiProductModel[2] = 0x1b;//
	info->uiProductModel[3] = 0x12;//S
	info->uiProductModel[4] = 0x03;//D
	//info->uiProductModel[5] = 0x27;//0
	//info->uiProductModel[6] = 0x27;//0
	//info->uiProductModel[7] = 0x04;//E
	info->uiMajorVer = 1;
	info->uiMinorVer = 0;
#elif(_PRODUCT_TYPE_CODE == _DVC_10000)

	info->uiProductModel[2] = 0x01;//B
	info->uiProductModel[3] = 0x4B;//'
	info->uiProductModel[4] = 0x0E;//O
	info->uiProductModel[5] = 0x11;//R
	info->uiProductModel[6] = 0x19;//Z
	info->uiProductModel[7] = 0x04;//E

	info->uiProductModel2[0] = 0x03;//D
	info->uiProductModel2[1] = 0x15;//V
	info->uiProductModel2[2] = 0x02;//C
	info->uiProductModel2[3] = 0x4f;// 1
	info->uiProductModel2[4] = 0x1e;//0
	info->uiProductModel2[5] = 0x27;//0
	info->uiProductModel2[6] = 0x27;//0
	info->uiProductModel2[7] = 0x27;//0
	info->uiProductModel2[8] = 0x27;//0
	
	info->uiMajorVer = 1;
	info->uiMinorVer = 0;
#elif(_PRODUCT_TYPE_CODE == _DVC_14000)
	info->uiProductModel[0] = 0x03;//D
	info->uiProductModel[1] = 0x15;//V
	info->uiProductModel[2] = 0x02;//C
	info->uiProductModel[3] = 0x1e;// 1
	info->uiProductModel[4] = 0x21;//0
	info->uiProductModel[5] = 0x27;//0
	info->uiProductModel[6] = 0x27;//0
	info->uiProductModel[7] = 0x27;//0
	info->uiProductModel[8] = 0x06;//G
	info->uiProductModel[9] = 0x02;//C
	info->uiMajorVer = 1;
	info->uiMinorVer = 0;
#elif(_PRODUCT_TYPE_CODE == _VC_100)
	info->uiProductModel[0] = 0x15;//V
	info->uiProductModel[1] = 0x02;//C
	info->uiProductModel[2] = 0x4f;//-
	info->uiProductModel[3] = 0x1E;// 1
	info->uiProductModel[4] = 0x27;//0
	info->uiProductModel[5] = 0x27;//0
	info->uiProductModel[6] = 0x1B;// 
	info->uiProductModel[7] = 0x06;//G
	info->uiProductModel[8] = 0x02;//C
	info->uiMajorVer = 1;
	info->uiMinorVer = 0;
#elif(_PRODUCT_TYPE_CODE == _VC_200)
	info->uiProductModel[0] = 0x15;//V
	info->uiProductModel[1] = 0x02;//C
	info->uiProductModel[2] = 0x4f;//-
	info->uiProductModel[3] = 0x1F;// 2
	info->uiProductModel[4] = 0x27;//0
	info->uiProductModel[5] = 0x27;//0
	info->uiProductModel[6] = 0x07;// H
	info->uiProductModel[7] = 0x03;//D

	info->uiMajorVer = 1;
	info->uiMinorVer = 0;
#elif(_PRODUCT_TYPE_CODE == _LT_300)
	info->uiProductModel[0] = 0x0B;//L
	info->uiProductModel[1] = 0x13;//T
	info->uiProductModel[2] = 0x4f;//-
	info->uiProductModel[3] = 0x20;// 3
	info->uiProductModel[4] = 0x27;//0
	info->uiProductModel[5] = 0x27;//0
	info->uiProductModel[6] = 0x1B;// 
	info->uiProductModel[7] = 0x06;//G
	info->uiProductModel[8] = 0x02;//C
	info->uiMajorVer = 1;
	info->uiMinorVer = 0;
#elif(_PRODUCT_TYPE_CODE == _AL_106B)
	info->uiProductModel[0] = 0x00;//A
	info->uiProductModel[1] = 0x0B;//L
	info->uiProductModel[2] = 0x4f;//-
	info->uiProductModel[3] = 0x1E;// 1
	info->uiProductModel[4] = 0x27;//0
	info->uiProductModel[5] = 0x23;//6
	info->uiProductModel[6] = 0x01;//B
	info->uiProductModel[7] = 0x1B;// 
	info->uiProductModel[8] = 0x06;//G
	info->uiProductModel[9] = 0x02;//C

	info->uiMajorVer = 1;
	info->uiMinorVer = 0;
#elif(_PRODUCT_TYPE_CODE == _AL_106)
	info->uiProductModel[0] = 0x00;//A
	info->uiProductModel[1] = 0x0B;//L
	info->uiProductModel[2] = 0x4f;//-
	info->uiProductModel[3] = 0x1E;// 1
	info->uiProductModel[4] = 0x27;//0
	info->uiProductModel[5] = 0x23;//6
	info->uiProductModel[6] = 0x1B;// 
	info->uiProductModel[7] = 0x06;//G
	info->uiProductModel[8] = 0x02;//C

	info->uiMajorVer = 1;
	info->uiMinorVer = 0;
#elif(_PRODUCT_TYPE_CODE == _AL_106HD)
	info->uiProductModel[3] = 0x0C;//M
	info->uiProductModel[4] = 0x04;//E
	info->uiProductModel[5] = 0x03;//D
	info->uiProductModel[6] = 0x06;// G
	info->uiProductModel[7] = 0x18;// Y
	info->uiProductModel[8] = 0x0D;//N
	//info->uiProductModel[6] = 0x00;//0
	//info->uiProductModel[7] = 0x27;//0
	//info->uiProductModel[8] = 0x12;//0
	//info->uiProductModel[9] = 0x03;//0

	info->uiProductModel2[0] = 0x00;//A
	info->uiProductModel2[1] = 0x0B;//L
	info->uiProductModel2[2] = 0x4f;//-
	info->uiProductModel2[3] = 0x1E;// 1
	info->uiProductModel2[4] = 0x27;//0
	info->uiProductModel2[5] = 0x23;//6
	//info->uiProductModel2[6] = 0x00;//0
	//info->uiProductModel2[7] = 0x27;//0
	//info->uiProductModel2[8] = 0x12;//0
	//info->uiProductModel2[9] = 0x03;//0

	info->uiMajorVer = 1;
	info->uiMinorVer = 0;
#elif(_PRODUCT_TYPE_CODE == _INDIA_SD)
	info->uiProductModel[0] = 0x08;//I
	info->uiProductModel[1] = 0x0D;//N
	info->uiProductModel[2] = 0x03;//D
	info->uiProductModel[3] = 0x08;// I
	info->uiProductModel[4] = 0x00;// A
	//info->uiProductModel[5] = 0x27;//0
	info->uiProductModel[6] = 0x00;//0
	//info->uiProductModel[7] = 0x27;//0
	info->uiProductModel[8] = 0x12;//0
	info->uiProductModel[9] = 0x03;//0
	info->uiMajorVer = 1;
	info->uiMinorVer = 0;	
#endif
#endif
	
}