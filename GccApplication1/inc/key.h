/*
 * key.h
 *
 * Created: 2015/1/23 01:04:14
 *  Author: 许修耀
 */ 


#ifndef KEY_H_
#define KEY_H_

#define KEY_DEBOUNCE_TIME      100//unit:1ms
#define KEY_REPEAT_START_TIME      300//unit:1ms
#define KEY_PRESS_INTERVAL 80//unit:1ms
#define KEY_REPEAT_INTERVAL 1000//unit:1ms

//--------------------------------------------------
// Definitions of Key Mask
//--------------------------------------------------
#define _AF_KEY_MASK             0x01
#define _WIDE_KEY_MASK           0x02
#define _DISPLAY_KEY_MASK        0x04
#define _TELE_KEY_MASK           0x08
#define _TIME_KEY_MASK           0x10
#define _WHITE_KEY_MASK          0x20
#define _FREEZE_KEY_MASK         0x40
#define _FILTER_KEY_MASK         0x80
#define _EM_KEY_MASK		0x100

#define _AWB_KEY_MASK       (_DISPLAY_KEY_MASK | _WIDE_KEY_MASK)	//自动白平衡 同时按住“显示”键和“缩小”键，进入自动白平衡
#define _MWB_KEY_MASK       (_DISPLAY_KEY_MASK | _TELE_KEY_MASK)	//手动白平衡 同时按住“放大”和“显示”键，进入手动白平衡
#define _RB_SWITCH_KEY_MASK       (_WIDE_KEY_MASK | _TELE_KEY_MASK)	//同时按住“放大”和“缩小”键切换R、B选择
#ifdef _TIME_DISPLAY_TO_EM
#define _TIME_DISPALY_EM_MASK 		(_DISPLAY_KEY_MASK | _TIME_KEY_MASK)
#endif
//--------------------------------------------------
// Definitions of Key Message
//--------------------------------------------------
typedef enum{
	_AF_KEY_MESSAGE,
	_WIDE_KEY_MESSAGE,
	_DISPLAY_KEY_MESSAGE,
	_TELE_KEY_MESSAGE,
	_TIME_KEY_MESSAGE,
	_WHITE_KEY_MESSAGE,
	_FREEZE_KEY_MESSAGE,
	_FILTER_KEY_MESSAGE,
	_EM_KEY_MESSAGE,
	_AWB_KEY_MESSAGE,
	_MWB_KEY_MESSAGE,
	_RB_SWITCH_KEY_MESSAGE,
	_TIME_DISPLAY_EM_MESSAGE,
	_NONE_KEY_MESSAGE,
}KEY_MESSAGE;
#define _KEY_AMOUNT                 8

//--------------------------------------------------
// Macro of Key Scan Ready Flag
//--------------------------------------------------
#define GET_KEYSCANREADY()          (g_ucKeyControl & _BIT0)
#define SET_KEYSCANREADY()          (g_ucKeyControl |= _BIT0)
#define CLR_KEYSCANREADY()          (g_ucKeyControl &= ~_BIT0)

//--------------------------------------------------
// Macro of Key Scan Start Flag
//--------------------------------------------------
#define GET_KEYSCANSTART()          (g_ucKeyControl & _BIT1)
#define SET_KEYSCANSTART()          (g_ucKeyControl |= _BIT1)
#define CLR_KEYSCANSTART()          (g_ucKeyControl &= ~_BIT1)

//--------------------------------------------------
// Macro of Key Repeat Start
//--------------------------------------------------
#define GET_KEYREPEATSTART()        (g_ucKeyControl & _BIT2)
#define SET_KEYREPEATSTART()        (g_ucKeyControl |= _BIT2)
#define CLR_KEYREPEATSTART()        (g_ucKeyControl &= ~_BIT2)

//--------------------------------------------------
// Macro of Key Repeat Function Enable
// If you want to use repeat function, please set this flag. If not, please clear it.
//--------------------------------------------------
#define GET_KEYREPEATENABLE()       (g_ucKeyControl & _BIT3)
#define SET_KEYREPEATENABLE()       (g_ucKeyControl |= _BIT3)
#define CLR_KEYREPEATENABLE()       (g_ucKeyControl &= ~_BIT3)

#if(_KEY_NUM == 8)

typedef enum{
	KEY_MASK_AF = 0x80,
	KEY_MASK_WIDE = 0x10,
	KEY_MASK_DISPLAY=0x04,
	KEY_MASK_TELE = 0x20,
	KEY_MASK_TIME = 0x40,
	KEY_MASK_WHITE = 0x04,
	KEY_MASK_FREEZE=0x01,
	KEY_MASK_FILTER=0x02,
}KEY_MASK;

#elif(_KEY_NUM == 60)

typedef enum{
	KEY_MASK_FREEZE = 0x80,
	KEY_MASK_DISPLAY = 0x10,
	KEY_MASK_WIDE=0x04,
	KEY_MASK_TELE = 0x04,
	KEY_MASK_AF = 0x40,
	KEY_MASK_FILTER=0x02,
}KEY_MASK;
#elif(_KEY_NUM == 61)

typedef enum{
	KEY_MASK_FREEZE = 0x80,
	KEY_MASK_DISPLAY = 0x10,
	KEY_MASK_WIDE=0x04,
	KEY_MASK_TELE = 0x04,
	KEY_MASK_EM = 0x40,
	KEY_MASK_FILTER=0x02,
}KEY_MASK;
#endif

extern uint8_t g_ucKeyControl;
extern uint16_t g_ucKeyStatePrev;
extern uint16_t g_ucKeyStateCurr;
extern uint8_t g_ucKeyMessage;
extern bool g_ucWideKeyPress;
extern bool g_ucWideKeyRelease;
extern bool g_ucTeleKeyPress;
extern bool g_ucTeleKeyRelease;
extern void KeyInit(void);
extern void CKeyHandle(void);
extern void CKeyInitial(void);
extern bool CKeyScanReady(void);
extern void CKeyScanReadyTimerEvent(void);
extern void CKeyRepeatEnableTimerEvent(void);
extern void CKeyMessageConvert(uint16_t ucKeyMask, uint8_t ucKeyMsg);
extern uint16_t CKeyScan(void);
extern void CKeyMessageProc(void);



#endif /* KEY_H_ */
