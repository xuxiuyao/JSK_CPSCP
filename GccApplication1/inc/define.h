/*
 * define.h
 *
 * Created: 2015/1/13 23:05:05
 *  Author: ÐíÐÞÒ«
 */ 


#ifndef DEFINE_H_
#define DEFINE_H_



#define _GC_3000B 1
#define _GC_3000B_C 2
#define _GC_5000B 3
#define _GC_8000B 4
#define _GC_2000B 5
#define _GC_3000E 6
#define _DVC_10000 7
#define _DVC_14000 8
#define _DVC_14000HD 9
#define _DVC_20000HD 10
#define _BMW 11
#define _NEWTECH 12
#define _VC_100 13
#define _VC_200 14
#define _LT_300 15
#define _LT_350 16
#define _LT_300P 17
#define _LT_300HD 18
#define _AL_106B 19
#define _AL_106 20
#define _AL_106HD 21
#define _COLPO_HD2 22
#define _ARETE_AR_20K 23


#define _CCD_480 0x01
#define _CCD_1020 0x02
#define _CCD_3300 0x03
#define _CCD_6300 0x04
#define _CCD_7500 0x05

//Define if white or filter key press set display on
#define _WIDE_TELE_SET_DISPLAY       0
#define _WHITE_SET_DISPLAY			1
#define _FILTER_SET_DISPLAY		1

//#define _PRODUCT_TYPE_CODE  _VC_200
//#define _GC_3000E
//#define _GC_5000B
//#define _GC_8000B

//#define _DEBUG_PRINTF	

#if(_PRODUCT_TYPE_CODE == _GC_3000B)
	#define _MAX_RATE 40
	#define _KEY_NUM  8
	#define _BLUE_LIGHT  0
	#define _CCD_TYPE_CODE   _CCD_480
	#define _MENU_V_POS	10
	#define _EM_KEY			0
#elif(_PRODUCT_TYPE_CODE == _GC_3000B_C)
	#define _MAX_RATE 40
	#define _KEY_NUM  8
	#define _BLUE_LIGHT  0
	#define _CCD_TYPE_CODE   _CCD_3300
	#define _MENU_V_POS	10
	#define _EM_KEY			0
#elif(_PRODUCT_TYPE_CODE == _GC_5000B)
	#define _MAX_RATE 40
	#define _KEY_NUM  8
	#define _BLUE_LIGHT  0
	#define _CCD_TYPE_CODE   _CCD_480
	#define _MENU_V_POS	10
	#define _EM_KEY			0
#elif(_PRODUCT_TYPE_CODE == _GC_8000B)
	#define _MAX_RATE 40
	#define _KEY_NUM  8
	#define _BLUE_LIGHT  0
	#define _CCD_TYPE_CODE   _CCD_3300
	#define _MENU_V_POS	10
	#define _EM_KEY			0
#elif(_PRODUCT_TYPE_CODE == _GC_2000B)
	#define _MAX_RATE 32
	#define _KEY_NUM  60
	#define _BLUE_LIGHT  0
	#define _CCD_TYPE_CODE   _CCD_480
	#define _MENU_V_POS	10
	#define _EM_KEY			0
#elif(_PRODUCT_TYPE_CODE == _GC_3000E)
	#define _MAX_RATE 40
	#define _KEY_NUM  8
	#define _BLUE_LIGHT  0
	#define _CCD_TYPE_CODE   _CCD_480
	#define _MENU_V_POS	10
	#define _EM_KEY			0
#elif(_PRODUCT_TYPE_CODE == _DVC_10000)
	#define _MAX_RATE 52
	#define _KEY_NUM  61
	#define _BLUE_LIGHT  0
	#define _CCD_TYPE_CODE   _CCD_480
	#define _MENU_V_POS	10
	#define _EM_KEY			2
#elif(_PRODUCT_TYPE_CODE == _DVC_14000)
	#define _MAX_RATE 52
	#define _KEY_NUM  8
	#define _BLUE_LIGHT  0
	#define _CCD_TYPE_CODE   _CCD_480
	#define _MENU_V_POS	10
	#define _EM_KEY			1
#elif(_PRODUCT_TYPE_CODE == _DVC_14000HD)
	#define _MAX_RATE 52
	#define _KEY_NUM  8
	#define _BLUE_LIGHT  0
	#define _CCD_TYPE_CODE   _CCD_3300
	#define _MENU_V_POS	10
	#define _EM_KEY			1
#elif(_PRODUCT_TYPE_CODE == _DVC_20000HD)
	#define _MAX_RATE 52
	#define _KEY_NUM  8
	#define _BLUE_LIGHT  0
	#define _CCD_TYPE_CODE   _CCD_3300
	#define _MENU_V_POS	10
	#define _EM_KEY			0
#elif(_PRODUCT_TYPE_CODE == _BMW)
	#define _MAX_RATE 40
	#define _KEY_NUM  8
	#define _BLUE_LIGHT  0
	#define _CCD_TYPE_CODE   _CCD_480
	#define _MENU_V_POS	10
	#define _EM_KEY			0
#elif(_PRODUCT_TYPE_CODE == _NEWTECH)
	#define _MAX_RATE 40
	#define _KEY_NUM  8
	#define _BLUE_LIGHT  0
	#define _CCD_TYPE_CODE   _CCD_480
	#define _MENU_V_POS	10
	#define _EM_KEY			0
#elif(_PRODUCT_TYPE_CODE == _VC_100)
	#define _MAX_RATE 40
	#define _KEY_NUM  8
	#define _BLUE_LIGHT  0
	#define _CCD_TYPE_CODE   _CCD_480
	#define _MENU_V_POS	10
	#define _EM_KEY			0
#elif(_PRODUCT_TYPE_CODE == _VC_200)
	#define _MAX_RATE 40
	#define _KEY_NUM  8
	#define _BLUE_LIGHT  0
	#define _CCD_TYPE_CODE   _CCD_6300
	#define _MENU_V_POS	10
	#define _EM_KEY			0
#elif(_PRODUCT_TYPE_CODE == _LT_300)
	#define _MAX_RATE 40
	#define _KEY_NUM  8
	#define _BLUE_LIGHT  0
	#define _CCD_TYPE_CODE   _CCD_480
	#define _MENU_V_POS	10
	#define _EM_KEY			0
#elif(_PRODUCT_TYPE_CODE == _LT_350)
	#define _MAX_RATE 40
	#define _KEY_NUM  8
	#define _BLUE_LIGHT  0
	#define _CCD_TYPE_CODE   _CCD_480
	#define _MENU_V_POS	10
	#define _EM_KEY			0
#elif(_PRODUCT_TYPE_CODE == _LT_300P)
	#define _MAX_RATE 40
	#define _KEY_NUM  8
	#define _BLUE_LIGHT  0
	#define _CCD_TYPE_CODE   _CCD_480
	#define _MENU_V_POS	10
	#define _EM_KEY			0
#elif(_PRODUCT_TYPE_CODE == _LT_300HD)
	#define _MAX_RATE 40
	#define _KEY_NUM  8
	#define _BLUE_LIGHT  0
	#define _CCD_TYPE_CODE   _CCD_480
	#define _MENU_V_POS	10
	#define _EM_KEY			0
#elif(_PRODUCT_TYPE_CODE == _AL_106B)
	#define _MAX_RATE 40
	#define _KEY_NUM  8
	#define _BLUE_LIGHT  0
	#define _CCD_TYPE_CODE   _CCD_480
	#define _MENU_V_POS	10
	#define _EM_KEY			0
#elif(_PRODUCT_TYPE_CODE == _AL_106)
	#define _MAX_RATE 40
	#define _KEY_NUM  8
	#define _BLUE_LIGHT  0
	#define _CCD_TYPE_CODE   _CCD_480
	#define _MENU_V_POS	10
	#define _EM_KEY			0
#elif(_PRODUCT_TYPE_CODE == _AL_106HD)
	#define _MAX_RATE 40
	#define _KEY_NUM  8
	#define _BLUE_LIGHT  1
	#define _CCD_TYPE_CODE   _CCD_6300
	#define _MENU_V_POS	10
	#define _EM_KEY			0
#elif(_PRODUCT_TYPE_CODE == _COLPO_HD2)
	#define _MAX_RATE 40
	#define _KEY_NUM  8
	#define _BLUE_LIGHT  0
	#define _CCD_TYPE_CODE   _CCD_480
	#define _MENU_V_POS	10
	#define _EM_KEY			0
#elif(_PRODUCT_TYPE_CODE == _ARETE_AR_20K)
	#define _MAX_RATE 40
	#define _KEY_NUM  8
	#define _BLUE_LIGHT  0
	#define _CCD_TYPE_CODE   _CCD_480
	#define _MENU_V_POS	10
	#define _EM_KEY			0
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