/*
 * timer.h
 *
 * Created: 2015/1/22 16:58:23
 *  Author: ÐíÐÞÒ«
 */ 


#ifndef TIMER_H_
#define TIMER_H_

//--------------------------------------------------
// Definitions of Timer.c
//--------------------------------------------------
#define _MAX_EVENT_AMOUNT                       7
#define _INACTIVE_TIMER_EVENT                   0xFFFF
#define _INACTIVE_COUNTDOWN_EVENT               0xFF

//--------------------------------------------------
// Timer Struct
//--------------------------------------------------
struct CTimerEventTable
{
	uint32_t Time;
	void (*Event)(void);
};

extern void CTimerInit(uint8_t Index);
extern void CTimerHandle(void);
extern void CTimerActiveTimerEvent(uint32_t usTime, void (*Event)());
extern void CTimerReactiveTimerEvent(uint32_t usTime, void (*Event)());
extern void CTimerCancelTimerEvent(void (*Event)());
extern void CTimerInitialTimerEvent(void);
extern void CTimerDecreaseTimerCnt(void);


extern volatile uint8_t g_ucMinuteCnt;
extern volatile uint8_t g_ucSecondCnt;
extern volatile bool g_bTimerChange;

#endif /* TIMER_H_ */