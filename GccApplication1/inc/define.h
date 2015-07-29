/*
 * define.h
 *
 * Created: 2015/1/13 23:05:05
 *  Author: ÐíÐÞÒ«
 */ 


#ifndef DEFINE_H_
#define DEFINE_H_


#define _SW_REG 1
#define _GC_5000B 3
#define _GC_3000E 6
#define _DVC_10000 7
#define _DVC_14000 8
#define _VC_100 13
#define _VC_200 14
#define _LT_300 15
#define _AL_106B 19
#define _AL_106 20
#define _AL_106HD 21
#define _INDIA_SD  24


#define _CCD_SONY 0x01
#define _CCD_7500 0x05

#define _CCD_SD		0x01
#define _CCD_HD		0x02

#define _MAX_ZOOM_PARA_NUM    2

//Define if white or filter key press set display on
#define _WIDE_TELE_SET_DISPLAY       0
#define _WHITE_SET_DISPLAY			1
#define _FILTER_SET_DISPLAY		1




//#define _DEBUG_PRINTF	
#if(_PRODUCT_TYPE_CODE == _SW_REG)
	#define _MAX_RATE 40
	#define _KEY_NUM  8
	#define _BLUE_LIGHT  0
	#define _CCD_TYPE_CODE   _CCD_SONY
	#define _MENU_V_POS	10
	#define _EM_KEY			1
	#define _CAPTURE_ENABLE   0
	#define _RESOLUTION_TYPE	_CCD_HD
	#define _FOCUS_OOR_TIPS	1
	#define _TIME_DISPLAY_TO_EM
#elif(_PRODUCT_TYPE_CODE == _GC_5000B)
	#define _MAX_RATE 40
	#define _KEY_NUM  8
	#define _BLUE_LIGHT  0
	#define _CCD_TYPE_CODE   _CCD_SONY
	#define _MENU_V_POS	10
	#define _EM_KEY			0
	#define _CAPTURE_ENABLE   0
	#define _RESOLUTION_TYPE	_CCD_HD
	#define _FOCUS_OOR_TIPS	0
#elif(_PRODUCT_TYPE_CODE == _GC_3000E)
	#define _MAX_RATE 40
	#define _KEY_NUM  8
	#define _BLUE_LIGHT  0
	#define _CCD_TYPE_CODE   _CCD_SONY
	#define _MENU_V_POS	10
	#define _EM_KEY			0
	#define _CAPTURE_ENABLE   0
	#define _RESOLUTION_TYPE	_CCD_SD
	#define _FOCUS_OOR_TIPS	0
#elif(_PRODUCT_TYPE_CODE == _DVC_10000)
	#define _MAX_RATE 52
	#define _KEY_NUM  61
	#define _BLUE_LIGHT  0
	#define _CCD_TYPE_CODE   _CCD_SONY
	#define _MENU_V_POS	10
	#define _EM_KEY			2
	#define _CAPTURE_ENABLE   0
	#define _RESOLUTION_TYPE	_CCD_SD
	#define _FOCUS_OOR_TIPS	0
#elif(_PRODUCT_TYPE_CODE == _DVC_14000)
	#define _MAX_RATE 52
	#define _KEY_NUM  8
	#define _BLUE_LIGHT  0
	#define _CCD_TYPE_CODE   _CCD_SONY
	#define _MENU_V_POS	10
	#define _EM_KEY			1
	#define _CAPTURE_ENABLE   1
	#define _RESOLUTION_TYPE	_CCD_SD
	#define _FOCUS_OOR_TIPS	0
#elif(_PRODUCT_TYPE_CODE == _VC_100)
	#define _MAX_RATE 40
	#define _KEY_NUM  8
	#define _BLUE_LIGHT  0
	#define _CCD_TYPE_CODE   _CCD_SONY
	#define _MENU_V_POS	10
	#define _EM_KEY			0
	#define _CAPTURE_ENABLE   0
	#define _RESOLUTION_TYPE	_CCD_SD
	#define _FOCUS_OOR_TIPS	0
#elif(_PRODUCT_TYPE_CODE == _VC_200)
	#define _MAX_RATE 40
	#define _KEY_NUM  8
	#define _BLUE_LIGHT  0
	#define _CCD_TYPE_CODE   _CCD_SONY
	#define _MENU_V_POS	10
	#define _EM_KEY			0
	#define _CAPTURE_ENABLE   0
	#define _RESOLUTION_TYPE	_CCD_HD
	#define _FOCUS_OOR_TIPS	0
#elif(_PRODUCT_TYPE_CODE == _LT_300)
	#define _MAX_RATE 40
	#define _KEY_NUM  8
	#define _BLUE_LIGHT  0
	#define _CCD_TYPE_CODE   _CCD_SONY
	#define _MENU_V_POS	10
	#define _EM_KEY			0
	#define _CAPTURE_ENABLE   0
	#define _RESOLUTION_TYPE	_CCD_SD
	#define _FOCUS_OOR_TIPS	0
#elif(_PRODUCT_TYPE_CODE == _AL_106B)
	#define _MAX_RATE 32
	#define _KEY_NUM  8
	#define _BLUE_LIGHT  0
	#define _CCD_TYPE_CODE   _CCD_SONY
	#define _MENU_V_POS	10
	#define _EM_KEY			0
	#define _CAPTURE_ENABLE   0
	#define _RESOLUTION_TYPE	_CCD_SD
	#define _FOCUS_OOR_TIPS	0
#elif(_PRODUCT_TYPE_CODE == _AL_106)
	#define _MAX_RATE 40
	#define _KEY_NUM  8
	#define _BLUE_LIGHT  0
	#define _CCD_TYPE_CODE   _CCD_SONY
	#define _MENU_V_POS	10
	#define _EM_KEY			0
	#define _CAPTURE_ENABLE   0
	#define _RESOLUTION_TYPE	_CCD_SD
	#define _FOCUS_OOR_TIPS	0
#elif(_PRODUCT_TYPE_CODE == _AL_106HD)
	#define _MAX_RATE 52
	#define _KEY_NUM  8
	#define _BLUE_LIGHT  1
	#define _CCD_TYPE_CODE   _CCD_SONY
	#define _MENU_V_POS	10
	#define _EM_KEY			0
	#define _CAPTURE_ENABLE   0
	#define _RESOLUTION_TYPE	_CCD_HD
	#define _FOCUS_OOR_TIPS	0
	#define _DOUBLE_LINE_INFO
#elif(_PRODUCT_TYPE_CODE == _INDIA_SD)
	#define _MAX_RATE 52
	#define _KEY_NUM  8
	#define _BLUE_LIGHT  0
	#define _CCD_TYPE_CODE   _CCD_SONY
	#define _MENU_V_POS	10
	#define _EM_KEY			1	
	#define _CAPTURE_ENABLE   0
	#define _RESOLUTION_TYPE	_CCD_SD
	#define _FOCUS_OOR_TIPS	0
#endif

#define _CAMARA_ID	0xfff4

#define _FOCUS_POS_1K 0X1000
#define _FOCUS_POS_2K 0X26DB
#define _FOCUS_POS_3K 0X3DB6
#define _FOCUS_POS_4K 0X5491
#define _FOCUS_POS_5K 0X6B6C
#define _FOCUS_POS_6K 0X8247
#define _FOCUS_POS_7K 0X9922
#define _FOCUS_POS_8K 0XB000

#define _FOCUS_POS_MIN	0x1000

//--------------------------------------------------
// Definitions of Bits
//--------------------------------------------------
#define _BIT0                           0x0001
#define _BIT1                           0x0002
#define _BIT2                           0x0004
#define _BIT3                           0x0008
#define _BIT4                           0x0010
#define _BIT5                           0x0020
#define _BIT6                           0x0040
#define _BIT7                           0x0080
#define _BIT8                           0x0100
#define _BIT9                           0x0200
#define _BIT10                          0x0400
#define _BIT11                          0x0800
#define _BIT12                          0x1000
#define _BIT13                          0x2000
#define _BIT14                          0x4000
#define _BIT15                          0x8000


#define SEC(x)                          (1000 * x)
#define MSEC(x)                          (x)

#endif /* DEFINE_H_ */