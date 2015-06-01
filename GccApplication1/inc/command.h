/*
 * command.h
 *
 * Created: 2015/1/23 14:05:04
 *  Author: Administrator
 */ 


#ifndef COMMAND_H_
#define COMMAND_H_

#define REPAY_HEAD	0x90
#define REPAY_TAIL	0xFF

#define REPLY_ACK_BUF_LENGTH 3
#define REPLY_COMPLETION_BUF_LENGTH 16
#define REPLY_ERROR_BUF_LENGTH 4

typedef enum{
	_CMD_TYPE_COMMAND = 0x01,
	_CMD_TYPE_INQUIRY = 0x09,
	_CMD_TYPE_CANCLE = 0x21,
	_CMD_TYPE_TOTAL = 0xFF,
}CMD_TYPE;

typedef enum{
	_CMD_DES_INTERFACE = 0x00,
	_CMD_DES_CAMERA = 0x04,
	_CMD_DES_PAN_TILT = 0x06,
	_CMD_DES_TOTAL = 0xFF,
}CMD_DES;
	
typedef enum{
	_CMD_STATUS_ACK,
	_CMD_STATUS_FINISH,
	_CMD_STATUS_TOTAL,
}CMD_STATUS;

typedef enum{
	_CMD_REPLY_ACK = 0x40,
	_CMD_REPLY_COMPLETION = 0x50,
	_CMD_REPLY_ERROR = 0x60,
	_CMD_REPLY_TOTAL = 0xFF,
}CMD_REPLY;

typedef struct{
	uint8_t* pCmd;
	uint8_t CmdLen;
	CMD_TYPE CmdType;
	CMD_STATUS CmdStatus;
	CMD_REPLY CmdReply;
	uint8_t RecBufAck[REPLY_ACK_BUF_LENGTH];
	uint8_t RecBufCompletion[REPLY_COMPLETION_BUF_LENGTH];
	uint8_t RecBufError[REPLY_ERROR_BUF_LENGTH];
	uint8_t InquiryResult[REPLY_COMPLETION_BUF_LENGTH];
	uint8_t InquiryResultLength;
}CAM_CMD;

typedef enum{
	//CAM_Power_On,
	//CAM_Power_Off,
	CAM_Zoom_Stop,
	//CAM_Zoom_STele,
	//CAM_Zoom_SWide,
	CAM_Zoom_VTele,
	CAM_Zoom_VWide,
	CAM_Zoom_Direct,
	CAM_DZoom_Direct,
	CAM_Focus_Stop,
	CAM_Focus_SFar,
	CAM_Focus_SNear,
	CAM_Focus_Auto,
	CAM_Focus_Manual,
	//CAM_Focus_OPT,
	CAM_Normal_AF,
	CAM_Zoom_Focus,
	CAM_WB_ATW,
	CAM_WB_Maunal,
	CAM_RGain_Up,
	CAM_RGain_Down,
	CAM_RGain_Direct,
	CAM_BGain_Up,
	CAM_BGain_Down,
	CAM_BGain_Direct,
	CAM_Aperture_Reset,
	CAM_Aperture_Direct,
	//CAM_LR_Reverse_On,
	//CAM_LR_Reverse_Off,
	CAM_Freeze_On,
	CAM_Freeze_Off,
	CAM_PicEffectOff,
	CAM_PicEffectBW,
	CAM_Flip_On,
	CAM_Flip_Off,
	CAM_Mirror_On,
	CAM_Mirror_Off,
	CAM_Get_Type,//Get Cam type, sony or BLOSSOM
	CAM_Title_Set1,
	CAM_Title_Set2,
	CAM_Title_Set3,
	CAM_Title_Clear,
	CAM_Title_On,
	CAM_Title_Off,
	#if(_CCD_TYPE_CODE == _CCD_7500)
	CAM_Video_BW,
	CAM_Video_Color,
	CAM_Video_Sharpness_Direct,
	CAM_DZoom_Limit,
	#endif
	CAM_SAVEAV_on,
	
	CAM_ZoomPos_Inq,
	CAM_FocusPos_Inq,
	CAM_WBmode_Inq,
	CAM_RGain_Inq,
	CAM_BGain_Inq,
	CAM_ID_Inq,
	CAM_Version_Inq,
	
	CAM_Total,
}CAM_CMD_LIST;

extern CAM_CMD g_stCameraCmd;
extern uint16_t uiZoomRatioTable[_MAX_RATE];

extern void CommandInit(CAM_CMD* Cmd);
extern void CommandHandle(void);
//extern void CAM_SetPowerOn(void);
//extern void CAM_SetPowerOff(void);
extern void CAM_SetZoomStop(void);
// extern void CAM_SetZoomSTele(void);
// extern void CAM_SetZoomSWide(void);
extern void CAM_SetZoomVTele(void);
extern void CAM_SetZoomVWide(void);
extern void CAM_SetZoomDirect(void);
extern void CAM_SetDZoomDirect(void);
extern void CAM_SetStopFocus(void);
extern void CAM_SetSFarFocus(void);
extern void CAM_SetSNearFocus(void);
extern void CAM_SetAutoFocus(void);
extern void CAM_SetManualFocus(void);
//extern void CAM_SetOPTFocus(void);
extern void CAM_SetNormalAF(void);
extern void CAM_SetZoomFocus(void);
extern void CAM_SetWBATW(void);
extern void CAM_SetWBMaunal(void);
extern void CAM_SetRGainUp(void);
extern void CAM_SetRGainDown(void);
extern void CAM_SetRGainDirect(uint8_t uiRGain);
extern void CAM_SetBGainUp(void);
extern void CAM_SetBGainDown(void);
extern void CAM_SetBGainDirect(uint8_t uiBGain);
extern void CAM_SetApertureReset(void);
extern void CAM_SetApertureDirect(void);
//extern void CAM_SetLRReverseOn(void);
//extern void CAM_SetLRReverseOff(void);
extern void CAM_SetFreezeOn(void);
extern void CAM_SetFreezeOff(void);
extern void CAM_SetPicEffectOff(void);
extern void CAM_SetPicEffectBW(void);
extern void CAM_SetFlipOn(void);
extern void CAM_SetFlipOff(void);
extern void CAM_SetMirrorOn(void);
extern void CAM_SetMirrorOff(void);
extern void CAM_SetTitleSet1(TITLE_DISPLAY titleDis);
extern void CAM_SetTitleSet2(uint8_t LineNum, uint8_t* uiTitle);
extern void CAM_SetTitleSet3(uint8_t LineNum, uint8_t* uiTitle);
extern void CAM_SetTitleClear(void);
extern void CAM_SetTitleOn(void);
extern void CAM_SetTitleOff(void);
#if(_CCD_TYPE_CODE == _CCD_7500)

extern void CAM_SetVideoBW(void);
extern void CAM_SetVideoColor(void);
extern void CAM_SetSharpnessDefault(void);
extern void CAM_SetSharpnessDirect(void);
extern void CAM_SetDZoomLimit(void);
#endif
extern void CAM_SetSAVEAVOn(void);
extern void CAM_InqZoomPos(void);
extern void CAM_InqFocusPos(void);
extern void CAM_InqWBmode(void);
extern void CAM_InqRGain(void);
extern void CAM_InqBGain(void);
extern void CAM_InqID(void);
extern void CAM_InqVersion(void);
extern void CommandLoadBuf(CMD_REPLY replyType, CAM_CMD* Cmd, uint8_t* Buf, uint8_t BufLen);
extern void GetInquiryResult(CAM_CMD* Cmd);
extern uint16_t GetCameraId(void);
extern uint16_t GetZoomPos(void);
extern uint16_t GetFocusPos(void);
extern uint16_t GetCameraVersion(void);
extern uint8_t GetWBmode(void);
extern uint8_t GetRGain(void);
extern uint8_t GetBGain(void);
extern bool IsBLOSSOM(void);
#endif /* COMMAND_H_ */
