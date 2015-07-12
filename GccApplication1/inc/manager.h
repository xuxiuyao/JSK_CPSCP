/*
 * message.h
 *
 * Created: 2015/1/25 21:08:05
 *  Author: Administrator
 */ 


#ifndef MESSAGE_H_
#define MESSAGE_H_




#if(_CCD_TYPE_CODE==_CCD_7500)
#define _G1_R_GAIN	100
#define _G2_R_GAIN	80
#define _G3_R_GAIN	60
#else
#define _G1_R_GAIN	0xC1
#define _G2_R_GAIN	0xA8
#define _G3_R_GAIN	0x78
#endif


extern void CMessageHandle(void);
extern void InitCamera(void);
#if(_FOCUS_OOR_TIPS == 1)
extern void CFocusOutOfRangeHandle(void);
#endif
extern void CReleaseKeyMessageHandle(void);
extern void WhiteBalanceHandle(void);
extern void SetWhiteModeNormal(void);
extern void SetWhiteModeFA(void);
extern void SetWhiteModeFB(void);
extern void SetFilterG1(void);
extern void SetFilterG2(void);
extern void SetFilterG3(void);
extern void SaveRBGainValue(void);
extern void UnSaveRBGainValue(void);
extern void SetMirrorOn(void);
extern void SetMirrorOff(void);
extern void SetFlipOn(void);
extern void SetFlipOff(void);

#endif /* MESSAGE_H_ */


