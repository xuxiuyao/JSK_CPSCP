/*
 * status.h
 *
 * Created: 2015/1/31 15:26:31
 *  Author: USER 
 */ 


#ifndef STATUS_H_
#define STATUS_H_

typedef enum{
	_CAM_480,
	_CAM_1020,
	_CAM_3310,
	_CAM_6300,
	_CAM_7500 = 0x05,
	_CAM_MODE_MAX,
}CAM_MODE;

typedef enum{
	_CAM_SD,
	_CAM_HD,
	_CAM_RES_MAX,
}CAM_RES;

typedef enum{
	_FOCUS_MODE_AUTO,
	_FOCUS_MODE_MANUAL,
	_FOCUS_MODE_TOTAL,
}FOCUS_MODE;

// typedef enum{
// 	_DISPLAY_MODE_OFF,
// 	_DISPLAY_MODE_ON,
// 	_DISPLAY_MODE_TOTAL,
// }DISPLAY_MODE;
// 
// typedef enum{
// 	_TIME_MODE_OFF,
// 	_TIME_MODE_ON,
// 	_TIME_MODE_TOTAL,
// }TIME_MODE;
// 
// typedef enum{
// 	_STILL_MODE_OFF,
// 	_STILL_MODE_ON,
// 	_STILL_MODE_TOTAL,
// }STILL_MODE;

typedef enum{
	_WHITE_MODE_NORMAL,
	_WHITE_MODE_FA,
	_WHITE_MODE_FB,
	_WHITE_MODE_TOTAL,
}WHITE_MODE;

typedef enum{
	_GREEN_MODE_NORMAL = 0,
	_GREEN_MODE_G1	   = 1,
	_GREEN_MODE_G2     = 2,
	_GREEN_MODE_G3     = 3,
	_GREEN_MODE_TOTAL,
}GREEN_MODE;

typedef enum{
	_ZOOM_MODE_GRADING,			//
	_ZOOM_MODE_STEPLESS,
	_ZOOM_MODE_TOTAL,
}ZOOM_MODE;

typedef enum{
	_FLIP_MODE_NORMAL,
	_FLIP_MODE_ON,
	_FLIP_MODE_OFF,
	_MIRROR_MODE_ON,
	_MIRROR_MODE_OFF,
	_FLIP_MODE_TOTAL,
}FLIP_MODE;

typedef enum{
	_TITLE_COLOR_WHITE	= 0X00,
	_TITLE_COLOR_YELLOW = 0X01,
	_TITLE_COLOR_VIOLET = 0X02,
	_TITLE_COLOR_RED	= 0X03,
	_TITLE_COLOR_CYAN	= 0X04,
	_TITLE_COLOR_GREEN	= 0X05,
	_TITLE_COLOR_BLUE	= 0X06,
	_TITLE_COLOR_TOTLE	= 0XFF,
}TITLE_COLOR;

typedef enum{
	_TITLE_BLINK_OFF	= 0X00,
	_TITLE_BLINK_ON		= 0X01,
	_TITLE_BLINK_TOTLE,
}TITLE_BLINK;

typedef enum{
	_WB_MODE_NORMAL = 0X00,
	_WB_MODE_AUTO	= 0X01,
	_WB_MODE_MANUAL_R = 0X02,
	_WB_MODE_MANUAL_B = 0X03,
	_WB_MODE_TOTLE,
}WB_MODE;

typedef struct{
	uint8_t uiTitleVPos;
	uint8_t uiTitleHPos;
	TITLE_COLOR TitleColor;
	TITLE_BLINK TitleBlink;
}TITLE_DISPLAY;

typedef enum{
	_DISPLAY_NULL = 0x00,
	_DISPLAY_ZOOM	= 0x01,
	_DISPLAY_WHITE = 0x02,
	_DISPLAY_FILTER = 0x04,
	_DISPLAY_STILL	= 0x08,
	_DISPLAY_EM	= 0x10,
	_DISPLAY_FOCUS	= 0x20,
	_DISPLAY_FOCUS_END	= 0x40,
	_DISPLAY_FOCUS_OOR	= 0x80,
	_DISPLAY_ALL	= 0xFF,
}DISPLAY_FLAG;

typedef struct{
	uint16_t uiCamID;
	CAM_MODE uiModeID;
	uint16_t uiFocusPosMax;
	uint8_t uiRGain;
	uint8_t uiRGainCurrent;
	uint8_t uiBGain;
	uint8_t uiBGainCurrent;
	uint8_t uiXRate;
	uint8_t uiXRateShow;
	uint8_t uiMF;
	uint8_t uiMFShow;
	TITLE_DISPLAY titleDis;
	uint8_t uiApertureGain;
	FOCUS_MODE FocusMode;
	uint16_t uiZoomPos;
	uint16_t uiFocusPos;
	bool bStartFar;
	bool bStartZoomOut;
	bool bStartNear;
	bool bStartZoomIn;
	bool bIsDisplay;
	uint8_t uiDisplayFlag;
	bool bIsTime;
	bool bIsStill;
	bool bShowVersion;
	WHITE_MODE WhiteMode;
	GREEN_MODE GreenMode;
	ZOOM_MODE ZoomMode;
	FLIP_MODE FlipMode;
	WB_MODE WBMode;
}STATUS_CMD;

typedef struct{
	uint8_t uiProductModel[10];
	uint8_t uiMajorVer;
	uint8_t uiMinorVer;
	//?
}PRODUCT_INFO;

extern STATUS_CMD g_stStatusCmd;
extern PRODUCT_INFO g_stProductInfo;


extern void StatusInit(STATUS_CMD* Cmd);
extern void ProductInfoInit(PRODUCT_INFO* info);

#endif /* STATUS_H_ */