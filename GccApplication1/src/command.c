/*
 * command.c
 *
 * Created: 2015/1/23 14:04:54
 *  Author: 许修耀
 * 要添加指令，首先添加枚举，然后添加指令数组即可。
 */ 

#include "include.h"

CAM_CMD g_stCameraCmd;

#if(_MAX_RATE == 40)
	#if(_CCD_TYPE_CODE == _CCD_480)//Right
	uint16_t uiZoomRatioTable[_MAX_RATE] = 
	{
		0x0000,0x1600,0x2100,0x2780,0x2c00,0x2f00,0x3230,0x3460,0x3670,0x3860,
		0x3930,0x3a70,0x3ba0,0x3cb0,0x3db0,0x3ea0,0x3f80,0x4000,0x4200,0x44b0,
		0x4760,0x4a10,0x4b80,0x4f00,0x5160,0x52a0,0x5410,0x5580,0x5700,0x58e0,
		0x5A00,0x5b00,0x5c00,0x5d00,0x5e00,0x5f00,0x6000,0x6100,0x6200,0x62ff
	};
	#elif(_CCD_TYPE_CODE == _CCD_1020)//Right
	uint16_t uiZoomRatioTable[_MAX_RATE] = 
	{
		0x0000,0x166F,0x1FF0,0x257D,0x2940,0x2C02,0x2E2B,0x2FEE,0x316A,0x32B2,
		0x33D4,0x34D9,0x35C8,0x36A4,0x3773,0x3836,0x38F0,0x39A0,0x3A49,0x3AE8,
		0x3B7F,0x3CC0,0x3C8E,0x3D06,0x3D73,0x3DD4,0x3E2C,0x3E7C,0x3EC2,0x3F00,
		0x3F38,0x3F68,0x3F94,0x3FBD,0x3FDF,0x4000,0x4200,0x4480,0x46E0,0x4A00,
	};
	#elif(_CCD_TYPE_CODE == _CCD_3300)//Right
	uint16_t uiZoomRatioTable[_MAX_RATE] = 
	{
		0x0000,0x1851,0x22BE,0x28F6,0x2d45,0x3086,0x3320,0x3549,0x371e,0x38b3,
		0x3a12,0x3b42,0x3c47,0x3d25,0x3ddf,0x3e7b,0x3efb,0x3f64,0x3fba,0x4000,
		0x4406,0x4700,0x4a08,0x4d00,0x4fe8,0x528a,0x5427,0x5580,0x56d0,0x5800,
		0x5920,0x5a30,0x5b38,0x5c36,0x5d30,0x5e30,0x5f26,0x6020,0x6118,0x6200,
	};
	#elif(_CCD_TYPE_CODE == _CCD_6300)//Right
	uint16_t uiZoomRatioTable[_MAX_RATE] = 
	{
		0x0000,0x1860,0x22C0,0x2900,0x2d50,0x3090,0x3320,0x3550,0x3740,0x3930,
		0x3AE0,0x3C10,0x3D30,0x3E20,0x3EF0,0x3FA0,0x4140,0x4480,0x4780,0x4A70,
		0x4D00,0x4F80,0x51B0,0x53A0,0x5530,0x5680,0x57A0,0x58A0,0x5990,0x5A70,
		0x5B30,0x5C00,0x5CA0,0x5D86,0x5E50,0x5F00,0x5FA0,0x6040,0x6120,0x6200,
	};
	#elif(_CCD_TYPE_CODE == _CCD_7500)//不知道参数，暂用6300
	uint16_t uiZoomRatioTable[_MAX_RATE] = 
	{
		0x0003,0x1970,0x2492,0x2848,0x2FB3,0x3258,0x3542,0x371D,0x38D6,0x3AD3,
		0x3CAE,0x3DBD,0x3ECD,0x3FBA,0x3FFC,0x1F00,0x2900,0x3200,0x3900,0x4200,
		0x4F00,0x5700,0x6100,0x6B00,0x7300,0x7A00,0x8100,0x8400,0x8700,0x8B00,
		0x8E00,0x9000,0x9400,0x9800,0x9A00,0x9E00,0xA100,0xA300,0xA600,0xA900,
	};
	#endif
#elif(_MAX_RATE == 52)
	#if(_CCD_TYPE_CODE == _CCD_480)//Right    DVC10000读出
	uint16_t uiZoomRatioTable[_MAX_RATE] = 
	{
		0x0000,0x1606,0x2151,0x2860,0x2CB5,0x3060,0x32D3,0x3545,0x3727,0x38A9,
		0x3A42,0x3B4B,0x3C85,0x3D75,0x3E4E,0x3EF7,0x3FA0,0x4000,0x4406,0x4700,
		0x4A08,0x4D00,0x4FE8,0x528A,0x5427,0x5580,0x56D0,0x5800,0x5920,0x5A30,
		0x5B38,0x5C36,0x5D30,0x5E30,0x5F26,0x6020,0x6118,0x6200,0x62D0,0x6380,
		0x6406,0x6490,0x6526,0x65B9,0x6650,0x6700,0x6798,0x6828,0x68B8,0x6940,
		0x69D0,0x6A70,
	};
	#elif(_CCD_TYPE_CODE == _CCD_3300)//copy from 480
	uint16_t uiZoomRatioTable[_MAX_RATE] = 
	{
		0x0000,0x1606,0x2151,0x2860,0x2CB5,0x3060,0x32D3,0x3545,0x3727,0x38A9,
		0x3A42,0x3B4B,0x3C85,0x3D75,0x3E4E,0x3EF7,0x3FA0,0x4000,0x4406,0x4700,
		0x4A08,0x4D00,0x4FE8,0x528A,0x5427,0x5580,0x56D0,0x5800,0x5920,0x5A30,
		0x5B38,0x5C36,0x5D30,0x5E30,0x5F26,0x6020,0x6118,0x6200,0x62D0,0x6380,
		0x6406,0x6490,0x6526,0x65B9,0x6650,0x6700,0x6798,0x6828,0x68B8,0x6940,
		0x69D0,0x6A70,
	};
	#elif(_CCD_TYPE_CODE == _CCD_6300)//copy from 480
	uint16_t uiZoomRatioTable[_MAX_RATE] = 
	{
		0x0000,0x1606,0x2151,0x2860,0x2CB5,0x3060,0x32D3,0x3545,0x3727,0x38A9,
		0x3A42,0x3B4B,0x3C85,0x3D75,0x3E4E,0x3EF7,0x3FA0,0x4000,0x4406,0x4700,
		0x4A08,0x4D00,0x4FE8,0x528A,0x5427,0x5580,0x56D0,0x5800,0x5920,0x5A30,
		0x5B38,0x5C36,0x5D30,0x5E30,0x5F26,0x6020,0x6118,0x6200,0x62D0,0x6380,
		0x6406,0x6490,0x6526,0x65B9,0x6650,0x6700,0x6798,0x6828,0x68B8,0x6940,
		0x69D0,0x6A70,
	};
	#elif(_CCD_TYPE_CODE == _CCD_7500)//copy from 480
	uint16_t uiZoomRatioTable[_MAX_RATE] = 
	{
		0x0000,0x1606,0x2151,0x2860,0x2CB5,0x3060,0x32D3,0x3545,0x3727,0x38A9,
		0x3A42,0x3B4B,0x3C85,0x3D75,0x3E4E,0x3EF7,0x3FA0,0x4000,0x4406,0x4700,
		0x4A08,0x4D00,0x4FE8,0x528A,0x5427,0x5580,0x56D0,0x5800,0x5920,0x5A30,
		0x5B38,0x5C36,0x5D30,0x5E30,0x5F26,0x6020,0x6118,0x6200,0x62D0,0x6380,
		0x6406,0x6490,0x6526,0x65B9,0x6650,0x6700,0x6798,0x6828,0x68B8,0x6940,
		0x69D0,0x6A70,
	};
	#endif
#endif
/*-----------480标清 32倍，GC2000B读出-----------------------------
		0x0000,0x1606,0x2151,0x2800,0x2CA0,0x3000,0x32D0,0x3540,0x3720,0x38C0,
		0x3A38,0x3B7B,0x3CA8,0x3DA9,0x3EA0,0x3F60,0x4200,0x44B0,0x4760,0x4A10,
		0x4CB8,0x4F30,0x5190,0x5350,0x54F8,0x56a0,0x5810,0x5980,0x5AE0,0x5C20,
		0x5D50,0x5E70
*/
/*-----------3300高清40倍，AL106HD读出-----------\
0x0000,0x1851,0x22BE,0x28F6,0x2d45,0x3086,0x3320,0x3549,0x371e,0x38b3,
		0x3a12,0x3b42,0x3c47,0x3d25,0x3ddf,0x3e7b,0x3efb,0x3f64,0x3fba,0x4000,
		0x4406,0x4700,0x4a08,0x4d00,0x4fe8,0x528a,0x5427,0x5580,0x56d0,0x5800,
		0x5920,0x5a30,0x5b38,0x5c36,0x5d30,0x5e30,0x5f26,0x6020,0x6118,0x6200,
*/
/*-----------6300高清 40倍，GC8000B读出-----------\
0x0000,0x1860,0x22C0,0x2900,0x2d50,0x3090,0x3320,0x3550,0x3740,0x3930,
		0x3AE0,0x3C10,0x3D30,0x3E20,0x3EF0,0x3FA0,0x4140,0x4480,0x4780,0x4A70,
		0x4D00,0x4F80,0x51B0,0x53A0,0x5530,0x5680,0x57A0,0x58A0,0x5990,0x5A70,
		0x5B30,0x5C00,0x5CA0,0x5D86,0x5E50,0x5F00,0x5FA0,0x6040,0x6120,0x6200,
*/
/*-----------1020  40倍，LT-300读出------22，23倍异常-----\
0x0000,0x166F,0x1FF0,0x257D,0x2940,0x2C02,0x2E2B,0x2FEE,0x316A,0x32B2,
		0x33D4,0x34D9,0x35C8,0x36A4,0x3773,0x3836,0x38F0,0x39A0,0x3A49,0x3AE8,
		0x3B7F,0x3CC0,0x3C8E,0x3D06,0x3D73,0x3DD4,0x3E2C,0x3E7C,0x3EC2,0x3F00,
		0x3F38,0x3F68,0x3F94,0x3FBD,0x3FDF,0x4000,0x4200,0x4480,0x46E0,0x4A00,
*/

/*-----------480  52倍，DVC10000读出---------\
		0x0000,0x1606,0x2151,0x2860,0x2CB5,0x3060,0x32D3,0x3545,0x3727,0x38A9,
		0x3A42,0x3B4B,0x3C85,0x3D75,0x3E4E,0x3EF7,0x3FA0,0x4000,0x4406,0x4700,
		0x4A08,0x4D00,0x4FE8,0x528A,0x5427,0x5580,0x56D0,0x5800,0x5920,0x5A30,
		0x5B38,0x5C36,0x5D30,0x5E30,0x5F26,0x6020,0x6118,0x6200,0x62D0,0x6380,
		0x6406,0x6490,0x6526,0x65B9,0x6650,0x6700,0x6798,0x6828,0x68B8,0x6940,
		0x69D0,0x6A70,
*/

//.....................................................................Command List...................................................................//
//CAM_Power
// uint8_t tCmd_PowerOn[6]={0x81, 0x01, 0x04, 0x00, 0x02, 0xFF};		//Power On
// uint8_t tCmd_PowerOff[6]={0x81, 0x01, 0x04, 0x00, 0x03, 0xFF};		//Power Off
	
//CAM_Zoom
uint8_t tCmd_ZoomStop[6]={0x81, 0x01, 0x04, 0x07, 0x00, 0xFF};		//Zoom Stop
// uint8_t tCmd_ZoomSTele[6]={0x81, 0x01, 0x04, 0x07, 0x02, 0xFF};		//Tele(Standard)
// uint8_t tCmd_ZoomSWide[6]={0x81, 0x01, 0x04, 0x07, 0x03, 0xFF};		//Wide(Standard)

uint8_t tCmd_ZoomVTele[6]={0x81, 0x01, 0x04, 0x07, 0x23, 0xFF};		//Tele(Variable) {0x81, 0x01, 0x04, 0x07, 0x2p, 0xFF} p=0(low)to 7(high)
uint8_t tCmd_ZoomVWide[6]={0x81, 0x01, 0x04, 0x07, 0x33, 0xFF};		//Wide(Variable) {0x81, 0x01, 0x04, 0x07, 0x3p, 0xFF} p=0(low)to 7(high)
uint8_t tCmd_ZoomDirect[9]={0x81, 0x01, 0x04, 0x47, 0x00, 0x00, 0x00, 0x00, 0xFF};		//{0x81, 0x01, 0x04, 0x47, 0x0p, 0x0q, 0x0r, 0x0s, 0xFF} pqrs:Zoom Position
uint8_t tCmd_DZoomDirect[9]={0x81, 0x01, 0x04, 0x46, 0x00, 0x00, 0x00, 0x00, 0xFF};		//{0x81, 0x01, 0x04, 0x47, 0x0p, 0x0q, 0x0r, 0x0s, 0xFF} pq:DZoom Position
	
//CAM_Focus
uint8_t tCmd_StopFocus[6]={0x81, 0x01, 0x04, 0x08, 0x00, 0xFF};		//Stop Focus 
#if(_CCD_TYPE_CODE == _CCD_7500)
uint8_t tCmd_FocusSFar[6]={0x81, 0x01, 0x04, 0x08, 0x27, 0xFF};		//Far(Standard) Focus
uint8_t tCmd_FocusSNear[6]={0x81, 0x01, 0x04, 0x08, 0x37, 0xFF};	//Near(Standard) Focus
#else
#if(_CCD_TYPE_CODE == 480)
uint8_t tCmd_FocusSFar[6]={0x81, 0x01, 0x04, 0x08, 0x22, 0xFF};		//Far(Standard) Focus
uint8_t tCmd_FocusSNear[6]={0x81, 0x01, 0x04, 0x08, 0x32, 0xFF};	//Near(Standard) Focus
#else
uint8_t tCmd_FocusSFar[6]={0x81, 0x01, 0x04, 0x08, 0x23, 0xFF};		//Far(Standard) Focus
uint8_t tCmd_FocusSNear[6]={0x81, 0x01, 0x04, 0x08, 0x33, 0xFF};	//Near(Standard) Focus
#endif
#endif
uint8_t tCmd_AutoFocus[6]={0x81, 0x01, 0x04, 0x38, 0x02, 0xFF};		//Auto Focus 
uint8_t tCmd_ManualFocus[6]={0x81, 0x01, 0x04, 0x38, 0x03, 0xFF};	//Manual Focus 
//uint8_t tCmd_OPT[6]={0x81, 0x01, 0x04, 0x18, 0x01, 0xFF};			//One Push AF Trigger
	
//CAM_AFMode
uint8_t tCmd_NormalAF[6]={0x81, 0x01, 0x04, 0x57, 0x00, 0xFF};		//AF Movement Mode
	
//CAM_ZoomFocus
uint8_t tCmd_ZoomFocus[13]={0x81, 0x01, 0x04, 0x47, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF};  
//{0x81, 0x01, 0x04, 0x47, 0x0p, 0x0q, 0x0r, 0x0s, 0x0t, 0x0u, 0x0v, 0x0w, 0xFF} pqrs:Zoom Position, tuvw:Focus Position
	
//CAM_WB
uint8_t tCmd_WBATW[6]={0x81, 0x01, 0x04, 0x35, 0x04, 0xFF};		//Auto Tracing White Balance
uint8_t tCmd_WBManual[6]={0x81, 0x01, 0x04, 0x35, 0x05, 0xFF};	//Manual Control Mode
	
//CAM_RGain
uint8_t tCmd_RGainUp[6]={0x81, 0x01, 0x04, 0x03, 0x02, 0xFF};		//RGain Up
uint8_t tCmd_RGainDown[6]={0x81, 0x01, 0x04, 0x03, 0x03, 0xFF};		//RGain Down
uint8_t tCmd_RGainDirect[9]={0x81, 0x01, 0x04, 0x43, 0x00, 0x00, 0x00, 0x00, 0xFF};		//{0x81, 0x01, 0x04, 0x43, 0x00, 0x00, 0x0p, 0x0q, 0xFF} pq:R Gain

//CAM_BGain
uint8_t tCmd_BGainUp[6]={0x81, 0x01, 0x04, 0x04, 0x02, 0xFF};		//BGain Up
uint8_t tCmd_BGainDown[6]={0x81, 0x01, 0x04, 0x04, 0x03, 0xFF};		//BGain Down
uint8_t tCmd_BGainDirect[9]={0x81, 0x01, 0x04, 0x44, 0x00, 0x00, 0x00, 0x00, 0xFF};		//{0x81, 0x01, 0x04, 0x44, 0x00, 0x00, 0x0p, 0x0q, 0xFF} pq:B Gain

//CAM_Aperture
uint8_t tCmd_ApertureReset[6]={0x81, 0x01, 0x04, 0x02, 0x00, 0xFF};		//Aperture Reset
uint8_t tCmd_ApertureDirect[9]={0x81, 0x01, 0x04, 0x42, 0x00, 0x00, 0x00, 0x00, 0xFF};		//{0x81, 0x01, 0x04, 0x42, 0x00, 0x00, 0x0p, 0x0q, 0xFF} pq:Aperture Gain
	
//CAM_LR_Reverse
//uint8_t tCmd_LRReverseOn[6]={0x81, 0x01, 0x04, 0x61, 0x02, 0xFF};		//Mirror Image On
//uint8_t tCmd_LRReverseOff[6]={0x81, 0x01, 0x04, 0x61, 0x03, 0xFF};		//Mirror Image Off
	
//CAM_Freeze
uint8_t tCmd_FreezeOn[6]={0x81, 0x01, 0x04, 0x62, 0x02, 0xFF};		//Still Image On
uint8_t tCmd_FreezeOff[6]={0x81, 0x01, 0x04, 0x62, 0x03, 0xFF};		//Still Image Off
	
//CAM_PictureEffect
uint8_t tCmd_PicEffectOff[6]={0x81, 0x01, 0x04, 0x63, 0x00, 0xFF};		//Picture Effect Setting Off
uint8_t tCmd_PicEffectBW[6]={0x81, 0x01, 0x04, 0x63, 0x04, 0xFF};		//Picture Effect Setting B&W
	
//CAM_PictureFlip
uint8_t tCmd_FlipOn[6]={0x81, 0x01, 0x04, 0x66, 0x02, 0xFF};		//Picture Flip On
uint8_t tCmd_FlipOff[6]={0x81, 0x01, 0x04, 0x66, 0x03, 0xFF};		//Picture Flip Off
	
//CAM_Mirror
uint8_t tCmd_MirrorOn[6]={0x81, 0x01, 0x04, 0x61, 0x02, 0xFF};		//Mirror On
uint8_t tCmd_MirrorOff[6]={0x81, 0x01, 0x04, 0x61, 0x03, 0xFF};		//Mirror Off

//CAM Type get
uint8_t tCmd_TypeGet[6]={0x81, 0x09, 0x10, 0x01, 0xFF};		//Get Cam type, sony or BLOSSOM


#if(_CCD_TYPE_CODE == _CCD_480)    
//CAM_Title
uint8_t tCmd_TitleSet1[16]={0x81, 0x01, 0x04, 0x73, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF};		
//{0x81, 0x01, 0x04, 0x73, 0x00, 0xmm, 0xnn, 0xpp, 0xqq, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF} mm:Vposition,nn:Hposition,pp:Color,qq:Blink
uint8_t tCmd_TitleSet2[16]={0x81, 0x01, 0x04, 0x73, 0x01, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0xFF};
//{0x81, 0x01, 0x04, 0x73, 0x01, 0xmm, 0xnn, 0xpp, 0xqq, 0xrr, 0xss, 0xtt, 0xuu, 0xvv, 0xww, 0xFF} mnpqrstuvw:Setting of Display Characters(1st to 10st Character )
uint8_t tCmd_TitleSet3[16]={0x81, 0x01, 0x04, 0x73, 0x02, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0xFF};
//{0x81, 0x01, 0x04, 0x73, 0x02, 0xmm, 0xnn, 0xpp, 0xqq, 0xrr, 0xss, 0xtt, 0xuu, 0xvv, 0xww, 0xFF} mnpqrstuvw:Setting of Display Characters(11st to 20st Character )
uint8_t tCmd_TitleClear[6]={0x81, 0x01, 0x04, 0x74, 0x00, 0xFF};	//Title Setting Clear
uint8_t tCmd_TitleOn[6]={0x81, 0x01, 0x04, 0x74, 0x02, 0xFF};		//Title Display On
uint8_t tCmd_TitleOff[6]={0x81, 0x01, 0x04, 0x74, 0x03, 0xFF};		//Title Display Off	
#else



//CAM_Title
uint8_t tCmd_TitleSet1[16]={0x81, 0x01, 0x04, 0x73, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF};		
//{0x81, 0x01, 0x04, 0x73, 0x00, 0xmm, 0xnn, 0xpp, 0xqq, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF} mm:Vposition,nn:Hposition,pp:Color,qq:Blink
uint8_t tCmd_TitleSet2[16]={0x81, 0x01, 0x04, 0x73, 0x20, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0xFF};
//{0x81, 0x01, 0x04, 0x73, 0x01, 0xmm, 0xnn, 0xpp, 0xqq, 0xrr, 0xss, 0xtt, 0xuu, 0xvv, 0xww, 0xFF} mnpqrstuvw:Setting of Display Characters(1st to 10st Character )
uint8_t tCmd_TitleSet3[16]={0x81, 0x01, 0x04, 0x73, 0x30, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0xFF};
//{0x81, 0x01, 0x04, 0x73, 0x02, 0xmm, 0xnn, 0xpp, 0xqq, 0xrr, 0xss, 0xtt, 0xuu, 0xvv, 0xww, 0xFF} mnpqrstuvw:Setting of Display Characters(11st to 20st Character )
uint8_t tCmd_TitleClear[6]={0x81, 0x01, 0x04, 0x74, 0x1f, 0xFF};	//Title Setting Clear
uint8_t tCmd_TitleOn[6]={0x81, 0x01, 0x04, 0x74, 0x2f, 0xFF};		//Title Display On
uint8_t tCmd_TitleOff[6]={0x81, 0x01, 0x04, 0x74, 0x3f, 0xFF};		//Title Display Off	


#if(_CCD_TYPE_CODE == _CCD_7500)
//VIDEO color
uint8_t tCmd_VideoBW[6]={0x81, 0x01, 0x11, 0x11, 0x01, 0xFF};		//B&W
uint8_t tCmd_VideoColor[6]={0x81, 0x01, 0x11, 0x11, 0x02, 0xFF};		//Color

//VIDEO sharpness
uint8_t tCmd_SharpnessDirect[9]={0x81, 0x01, 0x11, 0x13, 0x00, 0x00, 0x00, 0x00, 0xFF};		//{0x81, 0x01, 0x11, 0x13, 0x00, 0x00, 0x0p, 0x0q, 0xFF} pq:sharpness Gain 0-16 Def=1

uint8_t tCmd_DZoomLimit[6]={0x81, 0x01, 0x04, 0x26, 0x05, 0xFF};		//

#endif

#endif
//.....................................................................Command List...................................................................//

//CAM_SAVEAV
uint8_t tCmd_SAVEAVOn[8]={0x81, 0x01, 0x04, 0x24, 0x56, 0x00, 0x01, 0xFF};		// On



//.....................................................................Inquiry Command List...........................................................//
//CAM_ZoomPosInq
uint8_t tCmd_ZoomPosInq[5]={0x81, 0x09, 0x04, 0x47, 0xFF};		//Command Packet
//Inquiry Packet: y0 50 0p 0q 0r 0s FF,  pqrs:Zoom Position

//CAM_FocusPosInq
uint8_t tCmd_FocusPosInq[5]={0x81, 0x09, 0x04, 0x48, 0xFF};		//Command Packet
//Inquiry Packet: y0 50 0p 0q 0r 0s FF,  pqrs:Focus Position

//CAM_RGainInq
uint8_t tCmd_WBmodeInq[5]={0x81, 0x09, 0x04, 0x35, 0xFF};		//Command Packet
//Inquiry Packet: y0 50 0x FF,  x:WB mode

//CAM_RGainInq
uint8_t tCmd_RGainInq[5]={0x81, 0x09, 0x04, 0x43, 0xFF};		//Command Packet
//Inquiry Packet: y0 50 00 00 0p 0q FF,  pq:R Gain

//CAM_BGainInq
uint8_t tCmd_BGainInq[5]={0x81, 0x09, 0x04, 0x44, 0xFF};		//Command Packet
//Inquiry Packet: y0 50 00 00 0p 0q FF,  pq:B Gain

//CAM_IDInq
uint8_t tCmd_IDInq[5]={0x81, 0x09, 0x04, 0x22, 0xFF};			//Command Packet
//Inquiry Packet: y0 50 0p 0q 0r 0s FF,  pqrs:Camera ID

//CAM_VersionInq
uint8_t tCmd_VersionInq[5]={0x81, 0x09, 0x00, 0x02, 0xFF};			//Command Packet
//Inquiry Packet: y0 50 00 20 mn pq rs tu vw FF,  mnpq:Model Code(04xx),rstu:ROM version,vw:Socket Number(=02)


//.....................................................................Inquiry Command List...........................................................//
	

	
const CAM_CMD AllCamCmd[]=
{
// 	{//Power on
// 		tCmd_PowerOn,
// 		6,
// 		_CMD_TYPE_COMMAND,
// 
// 	},
// 	
// 	{//Power off
// 		tCmd_PowerOff,
// 		6,
// 		_CMD_TYPE_COMMAND,
// 	},
	
	{
		tCmd_ZoomStop,
		6,
		_CMD_TYPE_COMMAND,
	},
// 	
// 	{
// 		tCmd_ZoomSTele,
// 		6,
// 		_CMD_TYPE_COMMAND,
// 	},
// 	
// 	{
// 		tCmd_ZoomSWide,
// 		6,
// 		_CMD_TYPE_COMMAND,
// 	},
	
	{
		tCmd_ZoomVTele,
		6,
		_CMD_TYPE_COMMAND,
	},
	
	{
		tCmd_ZoomVWide,
		6,
		_CMD_TYPE_COMMAND,
	},
	
	{
		tCmd_ZoomDirect,
		9,
		_CMD_TYPE_COMMAND,
	},

	{
		tCmd_DZoomDirect,
		9,
		_CMD_TYPE_COMMAND,
	},
	
	{
		tCmd_StopFocus,
		6,
		_CMD_TYPE_COMMAND,
	},
	
	{
		tCmd_FocusSFar,
		6,
		_CMD_TYPE_COMMAND,
	},
	
	{
		tCmd_FocusSNear,
		6,
		_CMD_TYPE_COMMAND,
	},
	
	{
		tCmd_AutoFocus,
		6,
		_CMD_TYPE_COMMAND,
	},
	
	{
		tCmd_ManualFocus,
		6,
		_CMD_TYPE_COMMAND,
	},
	
// 	{
// 		tCmd_OPT,
// 		6,
// 		_CMD_TYPE_COMMAND,
// 	},
	
	{
		tCmd_NormalAF,
		6,
		_CMD_TYPE_COMMAND,
	},
	
	{
		tCmd_ZoomFocus,
		13,
		_CMD_TYPE_COMMAND,
	},
	
 	{
 		tCmd_WBATW,
 		6,
 		_CMD_TYPE_COMMAND,
 	},
 	
 	{
 		tCmd_WBManual,
 		6,
 		_CMD_TYPE_COMMAND,
 	},
 	
 	{
 		tCmd_RGainUp,
 		6,
 		_CMD_TYPE_COMMAND,
 	},
 	
 	{
 		tCmd_RGainDown,
 		6,
 		_CMD_TYPE_COMMAND,
 	},
	
	{
		tCmd_RGainDirect,
		9,
		_CMD_TYPE_COMMAND,
	},
	
 	{
 		tCmd_BGainUp,
 		6,
 		_CMD_TYPE_COMMAND,
 	},
 	
 	{
 		tCmd_BGainDown,
 		6,
 		_CMD_TYPE_COMMAND,
 	},
	
	{
		tCmd_BGainDirect,
		9,
		_CMD_TYPE_COMMAND,
	},
	
	{
		tCmd_ApertureReset,
		6,
		_CMD_TYPE_COMMAND,
	},
	
	{
		tCmd_ApertureDirect,
		9,
		_CMD_TYPE_COMMAND,
	},
	
// 	{
// 		tCmd_LRReverseOn,
// 		6,
// 		_CMD_TYPE_COMMAND,
// 	},
// 	
// 	{
// 		tCmd_LRReverseOff,
// 		6,
// 		_CMD_TYPE_COMMAND,
// 	},
	
	{
		tCmd_FreezeOn,
		6,
		_CMD_TYPE_COMMAND,
	},
	
	{
		tCmd_FreezeOff,
		6,
		_CMD_TYPE_COMMAND,
	},
	
	{
		tCmd_PicEffectOff,
		6,
		_CMD_TYPE_COMMAND,
	},
	
	{
		tCmd_PicEffectBW,
		6,
		_CMD_TYPE_COMMAND,
	},
	
	{
		tCmd_FlipOn,
		6,
		_CMD_TYPE_COMMAND,
	},
	
	{
		tCmd_FlipOff,
		6,
		_CMD_TYPE_COMMAND,
	},
	
	{
		tCmd_MirrorOn,
		6,
		_CMD_TYPE_COMMAND,
	},
	
	{
		tCmd_MirrorOff,
		6,
		_CMD_TYPE_COMMAND,
	},

	{
		tCmd_TypeGet,
		5,
		_CMD_TYPE_COMMAND,
	},
	
	{
		tCmd_TitleSet1,
		16,
		_CMD_TYPE_COMMAND,
	},
	
	{
		tCmd_TitleSet2,
		16,
		_CMD_TYPE_COMMAND,
	},
	
	{
		tCmd_TitleSet3,
		16,
		_CMD_TYPE_COMMAND,
	},
	
	{
		tCmd_TitleClear,
		6,
		_CMD_TYPE_COMMAND,
	},
	
	{
		tCmd_TitleOn,
		6,
		_CMD_TYPE_COMMAND,
	},
	
	{
		tCmd_TitleOff,
		6,
		_CMD_TYPE_COMMAND,
	},
	#if(_CCD_TYPE_CODE == _CCD_7500)
	{
		tCmd_VideoBW,
		6,
		_CMD_TYPE_COMMAND,
	},
	
	{
		tCmd_VideoColor,
		6,
		_CMD_TYPE_COMMAND,
	},
	
	{
		tCmd_SharpnessDirect,
		9,
		_CMD_TYPE_COMMAND,
	},

	{
		tCmd_DZoomLimit,
		6,
		_CMD_TYPE_COMMAND,
	},
	#endif

	{
		tCmd_SAVEAVOn,
		8,
		_CMD_TYPE_COMMAND,
	},
	
	{
		tCmd_ZoomPosInq,
		5,
		_CMD_TYPE_INQUIRY,
	},
	
	{
		tCmd_FocusPosInq,
		5,
		_CMD_TYPE_INQUIRY,
	},

	{
		tCmd_WBmodeInq,
		5,
		_CMD_TYPE_INQUIRY,
	},
		
	{
		tCmd_RGainInq,
		5,
		_CMD_TYPE_INQUIRY,
	},
	
	{
		tCmd_BGainInq,
		5,
		_CMD_TYPE_INQUIRY,
	},
	
	{
		tCmd_IDInq,
		5,
		_CMD_TYPE_INQUIRY,
	},
	
	{
		tCmd_VersionInq,
		5,
		_CMD_TYPE_INQUIRY,
	}

};

// void CAM_SetPowerOn(void)
// {
// 	g_stCameraCmd = AllCamCmd[CAM_Power_On];
// 	USART_SendCmd(g_stCameraCmd.pCmd, g_stCameraCmd.CmdLen);
// }
// 
// void CAM_SetPowerOff(void)
// {
// 	g_stCameraCmd = AllCamCmd[CAM_Power_Off];
// 	USART_SendCmd(g_stCameraCmd.pCmd, g_stCameraCmd.CmdLen);
// }

void CAM_SetZoomStop(void)
{
	g_stCameraCmd = AllCamCmd[CAM_Zoom_Stop];
	USART_SendCmd(g_stCameraCmd.pCmd, g_stCameraCmd.CmdLen);
}
// 
// void CAM_SetZoomSTele(void)
// {
// 	g_stCameraCmd = AllCamCmd[CAM_Zoom_STele];
// 	USART_SendCmd(g_stCameraCmd.pCmd, g_stCameraCmd.CmdLen);
// }
// 
// void CAM_SetZoomSWide(void)
// {
// 	g_stCameraCmd = AllCamCmd[CAM_Zoom_SWide];
// 	USART_SendCmd(g_stCameraCmd.pCmd, g_stCameraCmd.CmdLen);
// }

void CAM_SetZoomVTele(void)
{
	g_stCameraCmd = AllCamCmd[CAM_Zoom_VTele];
	USART_SendCmd(g_stCameraCmd.pCmd, g_stCameraCmd.CmdLen);
}

void CAM_SetZoomVWide(void)
{
	g_stCameraCmd = AllCamCmd[CAM_Zoom_VWide];
	USART_SendCmd(g_stCameraCmd.pCmd, g_stCameraCmd.CmdLen);
}

void CAM_SetZoomDirect(void)
{
	g_stCameraCmd = AllCamCmd[CAM_Zoom_Direct];
	//9
	g_stStatusCmd.uiZoomPos = uiZoomRatioTable[g_stStatusCmd.uiXRate];
	
	g_stCameraCmd.pCmd[4] = (uiZoomRatioTable[g_stStatusCmd.uiXRate]&0xF000)/0x1000;
	g_stCameraCmd.pCmd[5] = (uiZoomRatioTable[g_stStatusCmd.uiXRate]&0x0F00)/0x100;
	g_stCameraCmd.pCmd[6] = (uiZoomRatioTable[g_stStatusCmd.uiXRate]&0x00F0)/0x10;
	g_stCameraCmd.pCmd[7] = (uiZoomRatioTable[g_stStatusCmd.uiXRate]&0x000F)/0x1;
	USART_SendCmd(g_stCameraCmd.pCmd, g_stCameraCmd.CmdLen);
	
	//_delay_ms(300);
}


void CAM_SetDZoomDirect(void)
{
	g_stCameraCmd = AllCamCmd[CAM_DZoom_Direct];
	//9
	g_stStatusCmd.uiZoomPos = uiZoomRatioTable[g_stStatusCmd.uiXRate];
	
	g_stCameraCmd.pCmd[4] = (uiZoomRatioTable[g_stStatusCmd.uiXRate]&0xF000)/0x1000;
	g_stCameraCmd.pCmd[5] = (uiZoomRatioTable[g_stStatusCmd.uiXRate]&0x0F00)/0x100;
	g_stCameraCmd.pCmd[6] = (uiZoomRatioTable[g_stStatusCmd.uiXRate]&0x00F0)/0x10;
	g_stCameraCmd.pCmd[7] = (uiZoomRatioTable[g_stStatusCmd.uiXRate]&0x000F)/0x1;
	USART_SendCmd(g_stCameraCmd.pCmd, g_stCameraCmd.CmdLen);
	
	//_delay_ms(300);
}


void CAM_SetStopFocus(void)
{
	g_stCameraCmd = AllCamCmd[CAM_Focus_Stop];
	USART_SendCmd(g_stCameraCmd.pCmd, g_stCameraCmd.CmdLen);
}

void CAM_SetSFarFocus(void)
{
	g_stCameraCmd = AllCamCmd[CAM_Focus_SFar];
	USART_SendCmd(g_stCameraCmd.pCmd, g_stCameraCmd.CmdLen);
}

void CAM_SetSNearFocus(void)
{
	g_stCameraCmd = AllCamCmd[CAM_Focus_SNear];
	USART_SendCmd(g_stCameraCmd.pCmd, g_stCameraCmd.CmdLen);
}

void CAM_SetAutoFocus(void)
{
	g_stCameraCmd = AllCamCmd[CAM_Focus_Auto];
	USART_SendCmd(g_stCameraCmd.pCmd, g_stCameraCmd.CmdLen);
	
	g_stStatusCmd.FocusMode = _FOCUS_MODE_AUTO;
}

void CAM_SetManualFocus(void)
{
	g_stCameraCmd = AllCamCmd[CAM_Focus_Manual];
	USART_SendCmd(g_stCameraCmd.pCmd, g_stCameraCmd.CmdLen);
	
	g_stStatusCmd.FocusMode = _FOCUS_MODE_MANUAL;
}

// void CAM_SetOPTFocus(void)
// {
// 	g_stCameraCmd = AllCamCmd[CAM_Focus_OPT];
// 	USART_SendCmd(g_stCameraCmd.pCmd, g_stCameraCmd.CmdLen);
// }

void CAM_SetNormalAF(void)
{
	g_stCameraCmd = AllCamCmd[CAM_Normal_AF];
	USART_SendCmd(g_stCameraCmd.pCmd, g_stCameraCmd.CmdLen);
}

void CAM_SetZoomFocus(void)
{
	g_stCameraCmd = AllCamCmd[CAM_Zoom_Focus];
	//13
	USART_SendCmd(g_stCameraCmd.pCmd, g_stCameraCmd.CmdLen);
}

void CAM_SetWBATW(void)
{
	g_stCameraCmd = AllCamCmd[CAM_WB_ATW];
	USART_SendCmd(g_stCameraCmd.pCmd, g_stCameraCmd.CmdLen);
}

void CAM_SetWBMaunal(void)
{
	g_stCameraCmd = AllCamCmd[CAM_WB_Maunal];
	USART_SendCmd(g_stCameraCmd.pCmd, g_stCameraCmd.CmdLen);
}

void CAM_SetRGainUp(void)
{
	g_stCameraCmd = AllCamCmd[CAM_RGain_Up];
	USART_SendCmd(g_stCameraCmd.pCmd, g_stCameraCmd.CmdLen);
}

void CAM_SetRGainDown(void)
{
	g_stCameraCmd = AllCamCmd[CAM_RGain_Down];
	USART_SendCmd(g_stCameraCmd.pCmd, g_stCameraCmd.CmdLen);
}

void CAM_SetRGainDirect(uint8_t uiRGain)
{
	g_stCameraCmd = AllCamCmd[CAM_RGain_Direct];
	//9
	g_stCameraCmd.pCmd[6] = uiRGain/0x10;
	g_stCameraCmd.pCmd[7] = uiRGain%0x10;
	USART_SendCmd(g_stCameraCmd.pCmd, g_stCameraCmd.CmdLen);
}

void CAM_SetBGainUp(void)
{
	g_stCameraCmd = AllCamCmd[CAM_BGain_Up];
	USART_SendCmd(g_stCameraCmd.pCmd, g_stCameraCmd.CmdLen);
}

void CAM_SetBGainDown(void)
{
	g_stCameraCmd = AllCamCmd[CAM_BGain_Down];
	USART_SendCmd(g_stCameraCmd.pCmd, g_stCameraCmd.CmdLen);
}

void CAM_SetBGainDirect(uint8_t uiBGain)
{
	g_stCameraCmd = AllCamCmd[CAM_BGain_Direct];
	//9
	g_stCameraCmd.pCmd[6] = uiBGain/0x10;
	g_stCameraCmd.pCmd[7] = uiBGain%0x10;
	USART_SendCmd(g_stCameraCmd.pCmd, g_stCameraCmd.CmdLen);
}

void CAM_SetApertureReset(void)
{
	g_stCameraCmd = AllCamCmd[CAM_Aperture_Reset];
	USART_SendCmd(g_stCameraCmd.pCmd, g_stCameraCmd.CmdLen);
}

void CAM_SetApertureDirect(void)
{
	g_stCameraCmd = AllCamCmd[CAM_Aperture_Direct];
	//9
	g_stCameraCmd.pCmd[6] = g_stStatusCmd.uiApertureGain/0x10;
	g_stCameraCmd.pCmd[7] = g_stStatusCmd.uiApertureGain%0x10;
	USART_SendCmd(g_stCameraCmd.pCmd, g_stCameraCmd.CmdLen);
}

// void CAM_SetLRReverseOn(void)
// {
// 	g_stCameraCmd = AllCamCmd[CAM_LR_Reverse_On];
// 	USART_SendCmd(g_stCameraCmd.pCmd, g_stCameraCmd.CmdLen);
// }
// 
// void CAM_SetLRReverseOff(void)
// {
// 	g_stCameraCmd = AllCamCmd[CAM_LR_Reverse_Off];
// 	USART_SendCmd(g_stCameraCmd.pCmd, g_stCameraCmd.CmdLen);
// }

void CAM_SetFreezeOn(void)
{
	g_stCameraCmd = AllCamCmd[CAM_Freeze_On];
	USART_SendCmd(g_stCameraCmd.pCmd, g_stCameraCmd.CmdLen);
}

void CAM_SetFreezeOff(void)
{
	g_stCameraCmd = AllCamCmd[CAM_Freeze_Off];
	USART_SendCmd(g_stCameraCmd.pCmd, g_stCameraCmd.CmdLen);
}

void CAM_SetPicEffectOff(void)
{
	g_stCameraCmd = AllCamCmd[CAM_PicEffectOff];
	USART_SendCmd(g_stCameraCmd.pCmd, g_stCameraCmd.CmdLen);
}

void CAM_SetPicEffectBW(void)
{
	g_stCameraCmd = AllCamCmd[CAM_PicEffectBW];
	USART_SendCmd(g_stCameraCmd.pCmd, g_stCameraCmd.CmdLen);
}

void CAM_SetFlipOn(void)
{
	g_stCameraCmd = AllCamCmd[CAM_Flip_On];
	USART_SendCmd(g_stCameraCmd.pCmd, g_stCameraCmd.CmdLen);
}

void CAM_SetFlipOff(void)
{
	g_stCameraCmd = AllCamCmd[CAM_Flip_Off];
	USART_SendCmd(g_stCameraCmd.pCmd, g_stCameraCmd.CmdLen);
}

void CAM_SetMirrorOn(void)
{
	g_stCameraCmd = AllCamCmd[CAM_Mirror_On];
	USART_SendCmd(g_stCameraCmd.pCmd, g_stCameraCmd.CmdLen);
}

void CAM_SetMirrorOff(void)
{
	g_stCameraCmd = AllCamCmd[CAM_Mirror_Off];
	USART_SendCmd(g_stCameraCmd.pCmd, g_stCameraCmd.CmdLen);
}

void CAM_SetTitleSet1(TITLE_DISPLAY titleDis)
{
	g_stCameraCmd = AllCamCmd[CAM_Title_Set1];
	//16
	#if(_CCD_TYPE_CODE == _CCD_480)
	g_stCameraCmd.pCmd[5] = titleDis.uiTitleVPos;
    #else
	g_stCameraCmd.pCmd[4] = 0x10;
        g_stCameraCmd.pCmd[4] |= titleDis.uiTitleVPos;
    #endif
	g_stCameraCmd.pCmd[6] = titleDis.uiTitleHPos;
	g_stCameraCmd.pCmd[7] = titleDis.TitleColor;
	g_stCameraCmd.pCmd[8] = titleDis.TitleBlink;
	USART_SendCmd(g_stCameraCmd.pCmd, g_stCameraCmd.CmdLen);
}

void CAM_SetTitleSet2(uint8_t LineNum, uint8_t* uiTitle)
{
	g_stCameraCmd = AllCamCmd[CAM_Title_Set2];
#if(_CCD_TYPE_CODE == _CCD_480)

#else
g_stCameraCmd.pCmd[4] = 0x20;
    g_stCameraCmd.pCmd[4] |= LineNum;
#endif
	for (uint8_t i = 0; i<10; i++)
	{
		g_stCameraCmd.pCmd[5+i]=uiTitle[i];
	}
	
	USART_SendCmd(g_stCameraCmd.pCmd, g_stCameraCmd.CmdLen);
}

void CAM_SetTitleSet3(uint8_t LineNum, uint8_t* uiTitle)
{
	g_stCameraCmd = AllCamCmd[CAM_Title_Set3];
    #if(_CCD_TYPE_CODE == _CCD_480)

#else
g_stCameraCmd.pCmd[4] = 0x30;
    g_stCameraCmd.pCmd[4] |= LineNum;
#endif
	for (uint8_t i = 0; i<10; i++)
	{
		g_stCameraCmd.pCmd[5+i]=uiTitle[i];
	}
	USART_SendCmd(g_stCameraCmd.pCmd, g_stCameraCmd.CmdLen);
}

void CAM_SetTitleClear(void)
{
	g_stCameraCmd = AllCamCmd[CAM_Title_Clear];
	USART_SendCmd(g_stCameraCmd.pCmd, g_stCameraCmd.CmdLen);
}

void CAM_SetTitleOn(void)
{
	g_stCameraCmd = AllCamCmd[CAM_Title_On];
	USART_SendCmd(g_stCameraCmd.pCmd, g_stCameraCmd.CmdLen);
}

void CAM_SetTitleOff(void)
{
	g_stCameraCmd = AllCamCmd[CAM_Title_Off];
	USART_SendCmd(g_stCameraCmd.pCmd, g_stCameraCmd.CmdLen);
}


#if(_CCD_TYPE_CODE == _CCD_7500)

void CAM_SetVideoBW(void)
{
	g_stCameraCmd = AllCamCmd[CAM_Video_BW];
	USART_SendCmd(g_stCameraCmd.pCmd, g_stCameraCmd.CmdLen);
}

void CAM_SetVideoColor(void)
{
	g_stCameraCmd = AllCamCmd[CAM_Video_Color];
	USART_SendCmd(g_stCameraCmd.pCmd, g_stCameraCmd.CmdLen);
}

void CAM_SetSharpnessDefault(void)
{
	g_stCameraCmd = AllCamCmd[CAM_Video_Sharpness_Direct];

	g_stCameraCmd.pCmd[6] = 0x00;
	g_stCameraCmd.pCmd[7] = 0x08;
	USART_SendCmd(g_stCameraCmd.pCmd, g_stCameraCmd.CmdLen);
}

void CAM_SetSharpnessDirect(void)
{
	g_stCameraCmd = AllCamCmd[CAM_Video_Sharpness_Direct];

	g_stCameraCmd.pCmd[6] = g_stStatusCmd.uiApertureGain/0x10;
	g_stCameraCmd.pCmd[7] = g_stStatusCmd.uiApertureGain%0x10;
	USART_SendCmd(g_stCameraCmd.pCmd, g_stCameraCmd.CmdLen);
}
void CAM_SetDZoomLimit(void)
{
	g_stCameraCmd = AllCamCmd[CAM_DZoom_Limit];
	USART_SendCmd(g_stCameraCmd.pCmd, g_stCameraCmd.CmdLen);
}
#endif

void CAM_SetSAVEAVOn(void)
{
	g_stCameraCmd = AllCamCmd[CAM_SAVEAV_on];
	USART_SendCmd(g_stCameraCmd.pCmd, g_stCameraCmd.CmdLen);
}

void CAM_GetType(void)
{
	g_stCameraCmd = AllCamCmd[CAM_Get_Type];
	USART_SendCmd(g_stCameraCmd.pCmd, g_stCameraCmd.CmdLen);
}

void CAM_InqZoomPos(void)
{
	g_stCameraCmd = AllCamCmd[CAM_ZoomPos_Inq];
	USART_SendCmd(g_stCameraCmd.pCmd, g_stCameraCmd.CmdLen);
}

void CAM_InqFocusPos(void)
{
	g_stCameraCmd = AllCamCmd[CAM_FocusPos_Inq];
	USART_SendCmd(g_stCameraCmd.pCmd, g_stCameraCmd.CmdLen);
}

void CAM_InqWBmode(void)
{
	g_stCameraCmd = AllCamCmd[CAM_WBmode_Inq];
	USART_SendCmd(g_stCameraCmd.pCmd, g_stCameraCmd.CmdLen);
}

void CAM_InqRGain(void)
{
	g_stCameraCmd = AllCamCmd[CAM_RGain_Inq];
	USART_SendCmd(g_stCameraCmd.pCmd, g_stCameraCmd.CmdLen);
}

void CAM_InqBGain(void)
{
	g_stCameraCmd = AllCamCmd[CAM_BGain_Inq];
	USART_SendCmd(g_stCameraCmd.pCmd, g_stCameraCmd.CmdLen);
}

void CAM_InqID(void)
{
	g_stCameraCmd = AllCamCmd[CAM_ID_Inq];
	USART_SendCmd(g_stCameraCmd.pCmd, g_stCameraCmd.CmdLen);
}

void CAM_InqVersion(void)
{
	g_stCameraCmd = AllCamCmd[CAM_Version_Inq];
	USART_SendCmd(g_stCameraCmd.pCmd, g_stCameraCmd.CmdLen);
}

bool IsBLOSSOM(void)
{
	bool codeRight = false;
	bool lenRight = false;

	if (4==g_stCameraCmd.InquiryResultLength)
		lenRight = true;

	if((g_stCameraCmd.InquiryResult[0] == 0x90)&&(g_stCameraCmd.InquiryResult[1] == 0x50)&&((g_stCameraCmd.InquiryResult[2] == 0x02)||(g_stCameraCmd.InquiryResult[2] == 0x03)))
		codeRight = true;

	return (lenRight&&codeRight);
}

uint16_t GetCameraId(void)
{
	uint16_t uiID = 0;
	if (4==g_stCameraCmd.InquiryResultLength)
	{
		uiID = (g_stCameraCmd.InquiryResult[0]&0x0F)*0x1000;
		uiID += (g_stCameraCmd.InquiryResult[1]&0x0F)*0x100;
		uiID += (g_stCameraCmd.InquiryResult[2]&0x0F)*0x10;
		uiID += (g_stCameraCmd.InquiryResult[3]&0x0F)*0x1;
	}
	g_stStatusCmd.uiCamID = uiID;
	return uiID;
}

uint16_t GetZoomPos(void)
{
	uint16_t uiPos = 0;
	if (4==g_stCameraCmd.InquiryResultLength)
	{
		uiPos = (g_stCameraCmd.InquiryResult[0]&0x0F)*0x1000;
		uiPos += (g_stCameraCmd.InquiryResult[1]&0x0F)*0x100;
		uiPos += (g_stCameraCmd.InquiryResult[2]&0x0F)*0x10;
		uiPos += (g_stCameraCmd.InquiryResult[3]&0x0F)*0x1;
	}
	
	return uiPos;
}

uint16_t GetFocusPos(void)
{
	uint16_t uiPos = 0;
	if (4==g_stCameraCmd.InquiryResultLength)
	{
		uiPos = (g_stCameraCmd.InquiryResult[0]&0x0F)*0x1000;
		uiPos += (g_stCameraCmd.InquiryResult[1]&0x0F)*0x100;
		uiPos += (g_stCameraCmd.InquiryResult[2]&0x0F)*0x10;
		uiPos += (g_stCameraCmd.InquiryResult[3]&0x0F)*0x1;
	}
	
	return uiPos;
}

uint16_t GetCameraVersion(void)
{
	//uint16_t uiVenderID=0;
	uint16_t uiModelCode=0;
	//uint16_t uiRomVer=0;
	//uint8_t uiSocketNum=0;
	if (7==g_stCameraCmd.InquiryResultLength)
	{
		//uiVenderID = g_stCameraCmd.InquiryResult[0]*0x100;
		//uiVenderID += g_stCameraCmd.InquiryResult[1];
		uiModelCode = g_stCameraCmd.InquiryResult[2]*0x100;
		uiModelCode += g_stCameraCmd.InquiryResult[3];
		//uiRomVer = g_stCameraCmd.InquiryResult[4]*0x100;
		//uiRomVer += g_stCameraCmd.InquiryResult[5];
		//uiSocketNum = g_stCameraCmd.InquiryResult[6];
		
#ifdef _DEBUG_PRINTF
		//MyPrintf("uiVenderID=%s,uiModelCode=%s,uiRomVer=%s,uiSocketNum=%s\n",uiVenderID,uiModelCode,uiRomVer,uiSocketNum );
#endif
	}
	
	return uiModelCode;
}

uint8_t GetWBmode(void)
{
	uint8_t WBmode = 0;
	if (1==g_stCameraCmd.InquiryResultLength)
	{
		WBmode = g_stCameraCmd.InquiryResult[0]; 

		#ifdef _DEBUG_PRINTF
		//MyPrintf("WBmode is: %d",WBmode );
		#endif
	}
	
	return WBmode;
}

uint8_t GetRGain(void)
{
	uint8_t uiGain = 0;
	if (4==g_stCameraCmd.InquiryResultLength)
	{
		uiGain = (g_stCameraCmd.InquiryResult[2]&0x0F)*0x10; 
		uiGain += (g_stCameraCmd.InquiryResult[3]&0x0F)*0x1;
		
		#ifdef _DEBUG_PRINTF
		//MyPrintf("uiGain is: %d",uiGain );
		#endif
	}
	
	#ifdef _DEBUG_PRINTF
	//MyPrintf("GetRGain:g_stCameraCmd.InquiryResultLength is: %d",g_stCameraCmd.InquiryResultLength );
	#endif
	return uiGain;
}

uint8_t GetBGain(void)
{
	uint8_t uiGain = 0;
	if (4==g_stCameraCmd.InquiryResultLength)
	{
		uiGain = (g_stCameraCmd.InquiryResult[2]&0x0F)*0x10;
		uiGain += (g_stCameraCmd.InquiryResult[3]&0x0F)*0x1;
		#ifdef _DEBUG_PRINTF
		//MyPrintf("uiGain is: %d",uiGain );
		#endif
	}
	
	#ifdef _DEBUG_PRINTF
	//MyPrintf("GetBGain:g_stCameraCmd.InquiryResultLength is: %d",g_stCameraCmd.InquiryResultLength );
	#endif
	
	return uiGain;
}

void CommandInit(CAM_CMD* Cmd)
{
	uint8_t i = 0;
	Cmd->pCmd = NULL;
	Cmd->CmdLen = 0;
	Cmd->CmdType = _CMD_TYPE_TOTAL;
	Cmd->CmdStatus = _CMD_STATUS_TOTAL;
	Cmd->CmdReply = _CMD_REPLY_TOTAL;
	for (i = 0; i < REPLY_ACK_BUF_LENGTH; i++)
	{
		Cmd->RecBufAck[i] = 0;
	}
	
	for (i = 0; i < REPLY_COMPLETION_BUF_LENGTH; i++)
	{
		Cmd->RecBufCompletion[i] = 0;
	}
	
	for (i = 0; i < REPLY_ERROR_BUF_LENGTH; i++)
	{
		Cmd->RecBufError[i] = 0;
	}
	
	for (i = 0; i < REPLY_COMPLETION_BUF_LENGTH; i++)
	{
		Cmd->InquiryResult[i] = 0;
	}
	Cmd->InquiryResultLength = 0;
}

void CommandHandle(void)
{
	if(g_stCameraCmd.CmdStatus == _CMD_STATUS_FINISH)
	{
		switch(g_stCameraCmd.CmdType)
		{
			case _CMD_TYPE_COMMAND:
				if ((g_stCameraCmd.CmdReply & _CMD_REPLY_COMPLETION) == _CMD_REPLY_COMPLETION)
				{
					//Action done
					#ifdef _DEBUG_PRINTF
					//MyPrintf("Cmd done!\r\n");
					#endif
				} 
				else if ((g_stCameraCmd.CmdReply & _CMD_REPLY_ERROR) == _CMD_REPLY_ERROR)
				{
					//Error
					#ifdef _DEBUG_PRINTF
					//MyPrintf("Cmd error!\r\n");
					#endif
				}
				
			break;
			case _CMD_TYPE_INQUIRY:
				if ((g_stCameraCmd.CmdReply & _CMD_REPLY_COMPLETION) == _CMD_REPLY_COMPLETION)
				{
					//Action done
					GetInquiryResult(&g_stCameraCmd);
					#ifdef _DEBUG_PRINTF
					MyPrintf("Inquiry done!\r\n");
					#endif
				}
				else if ((g_stCameraCmd.CmdReply & _CMD_REPLY_ERROR) == _CMD_REPLY_ERROR)
				{
					//Error
					#ifdef _DEBUG_PRINTF
					//MyPrintf("Inquiry error!\r\n");
					#endif
				}
			break;
			case _CMD_TYPE_CANCLE:

			break;
			default:
				
			break;
		}
		g_stCameraCmd.CmdStatus = _CMD_STATUS_TOTAL;
	}
}

void CommandLoadBuf(CMD_REPLY replyType, CAM_CMD* Cmd, uint8_t* Buf, uint8_t BufLen)
{
	uint8_t i=0;
	
	
	switch(replyType & 0xf0)
	{
		case  _CMD_REPLY_ACK:
			for (i=0;i<BufLen;i++)
			{
				Cmd->RecBufAck[i] = Buf[i];
			}
			Cmd->CmdStatus = _CMD_STATUS_ACK;
			
		break;
		case  _CMD_REPLY_COMPLETION:
			for (i=0;i<BufLen;i++)
			{
				Cmd->RecBufCompletion[i] = Buf[i];
			}
			Cmd->CmdStatus = _CMD_STATUS_FINISH;
			
		break;
		case  _CMD_REPLY_ERROR:
			for (i=0;i<BufLen;i++)
			{
				Cmd->RecBufError[i] = Buf[i];
			}
			Cmd->CmdStatus = _CMD_STATUS_FINISH;
		break;
		default:
		break;
	}
}

void GetInquiryResult(CAM_CMD* Cmd)
{
	uint8_t i = 0;
	uint8_t j = 0;
	
	for (i = 2; i < REPLY_COMPLETION_BUF_LENGTH; i++)
	{
		if (Cmd->RecBufCompletion[i] != REPAY_TAIL)
		{
			Cmd->InquiryResult[j++] = Cmd->RecBufCompletion[i];
		}
		else
		{
			break;
		}
		
	}
	
	Cmd->InquiryResultLength = j;
}
