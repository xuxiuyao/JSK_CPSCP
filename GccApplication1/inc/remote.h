/*
 * remote.h
 *
 * Created: 2015/1/14 17:23:46
 *  Author: ÐíÐÞÒ«
 */ 


#ifndef REMOTE_H_
#define REMOTE_H_

#define REMOTE_DEBOUNCE_TIME      10//unit:1ms

typedef enum{
	REMOTE_MASK_AF = 0x08,
	REMOTE_MASK_WIDE = 0x09,
	REMOTE_MASK_DISPLAY = 0x03,
	REMOTE_MASK_TELE = 0x06,
	REMOTE_MASK_TIME = 0x0C,
	REMOTE_MASK_WHITE = 0x04,
	REMOTE_MASK_FREEZE = 0x02,
	REMOTE_MASK_FILTER = 0x01,
	REMOTE_MASK_VT = 0x10,
	REMOTE_MASK_ALL = 0x0F,
}REMOTE_MASK;

//--------------------------------------------------
// Macro of Key Scan Ready Flag
//--------------------------------------------------
#define GET_REMOTESCANREADY()          (g_ucRemoteControl & _BIT0)
#define SET_REMOTESCANREADY()          (g_ucRemoteControl |= _BIT0)
#define CLR_REMOTESCANREADY()          (g_ucRemoteControl &= ~_BIT0)

//--------------------------------------------------
// Macro of Key Scan Start Flag
//--------------------------------------------------
#define GET_REMOTESCANSTART()          (g_ucRemoteControl & _BIT1)
#define SET_REMOTESCANSTART()          (g_ucRemoteControl |= _BIT1)
#define CLR_REMOTESCANSTART()          (g_ucRemoteControl &= ~_BIT1)

//--------------------------------------------------
// Macro of Key Repeat Start
//--------------------------------------------------
#define GET_REMOTEREPEATSTART()        (g_ucRemoteControl & _BIT2)
#define SET_REMOTEREPEATSTART()        (g_ucRemoteControl |= _BIT2)
#define CLR_REMOTEREPEATSTART()        (g_ucRemoteControl &= ~_BIT2)

//--------------------------------------------------
// Macro of Key Repeat Function Enable
// If you want to use repeat function, please set this flag. If not, please clear it.
//--------------------------------------------------
#define GET_REMOTEREPEATENABLE()       (g_ucRemoteControl & _BIT3)
#define SET_REMOTEREPEATENABLE()       (g_ucRemoteControl |= _BIT3)
#define CLR_REMOTEREPEATENABLE()       (g_ucRemoteControl &= ~_BIT3)


extern uint8_t g_ucRemoteMessage;
extern uint8_t g_ucRemoteStateCurr;
extern uint8_t g_ucRemoteStatePrev;
extern bool g_ucWideRemotePress;
extern bool g_ucWideRemoteRelease;
extern bool g_ucTeleRemotePress;
extern bool g_ucTeleRemoteRelease;
extern void RemoteInit(void);
extern void CRemoteHandle(void);
extern bool CRemoteScanReady(void);
extern uint8_t CRemoteScan(void);
extern void CRemoteScanReadyTimerEvent(void);
extern void CRemoteRepeatEnableTimerEvent(void);
extern void CRemoteMessageConvert(uint8_t ucRemoteMask, uint8_t ucRemoteMsg);
extern void CRemoteMessageProc(void);


#endif /* REMOTE_H_ */