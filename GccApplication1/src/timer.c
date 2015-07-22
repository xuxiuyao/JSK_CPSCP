/*
 * timer.c
 *
 * Created: 2015/1/22 16:58:13
 *  Author: ÐíÐÞÒ«
 */ 
#include "include.h"
#define TimeInterval (0xFFFF-1000) + 1//1ms = 8M / 8 * 10000

//--------------------------------------------------
// Global Variables
//--------------------------------------------------
struct CTimerEventTable g_stTimerEvent[_MAX_EVENT_AMOUNT];
uint32_t g_ucTimer1Cnt = 0;
bool g_bTimer1Ctrl = false;
volatile bool g_bTimerChange = false;

volatile uint8_t g_ucMinuteCnt = 0;
volatile uint8_t g_ucSecondCnt = 0;

//--------------------------------------------------
// Description  : Timer initial for TC1
// Input Value  : Timer index
// Output Value : None
//--------------------------------------------------
void CTimerInit(uint8_t Index)
{
	if (Index == 1)
	{
		TCNT1 = TimeInterval;
		
		TIMSK1 |= (1 << TOIE1);//Enable T1 int
		
		TCCR1B |= (1 << CS11);//T1 normal, div=8
		
	}

}


ISR(TIMER1_OVF_vect)
{
	TCNT1 = TimeInterval;
	
	if (true == g_stStatusCmd.bIsTime)
	{
		g_ucTimer1Cnt ++;
		if (g_ucTimer1Cnt%1000==0)
		{
			g_bTimerChange = true;
			g_ucTimer1Cnt = 0;
			g_ucSecondCnt ++;
			if (g_ucSecondCnt%60==0)
			{
				g_bTimerChange = true;
				g_ucSecondCnt = 0;
				g_ucMinuteCnt ++;
				if (g_ucMinuteCnt%60==0)
					g_ucMinuteCnt = 0;
			}
		}
	}
	else
	{
		g_ucTimer1Cnt = 0;
		g_ucSecondCnt = 0;
		g_ucMinuteCnt = 0;
	}

	if((PIND & KEY_MASK_WIDE)&&(g_ucWideKeyPress))
	{
		g_ucWideKeyPress = false;
		g_ucWideKeyRelease = true;
	}

	if((PINC & KEY_MASK_TELE)&&(g_ucTeleKeyPress))
	{
		g_ucTeleKeyPress = false;
		g_ucTeleKeyRelease = true;

	}

	g_ucValuePortC = PINC;
	if((!(g_ucValuePortC & REMOTE_MASK_VT))&&g_ucWideRemotePress)
	{
		g_ucWideRemotePress= false;
		g_ucWideRemoteRelease= true;
	}

	if((!(g_ucValuePortC & REMOTE_MASK_VT))&&g_ucTeleRemotePress)
	{
		g_ucTeleRemotePress= false;
		g_ucTeleRemoteRelease= true;
	}
	
	if (!g_bTimer1Ctrl)
	{
		CTimerDecreaseTimerCnt();
	}

}

//--------------------------------------------------
// Description  : Check if it's time to execute events
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void CTimerHandle(void)
{
	uint8_t ucTimerEventCnt = 0;

	for(ucTimerEventCnt = 0; ucTimerEventCnt < _MAX_EVENT_AMOUNT; ucTimerEventCnt++)
	{
		if(g_stTimerEvent[ucTimerEventCnt].Time == 0)
		{
			g_bTimer1Ctrl = true;
			g_stTimerEvent[ucTimerEventCnt].Time = _INACTIVE_TIMER_EVENT;
			g_bTimer1Ctrl = false;
			(*g_stTimerEvent[ucTimerEventCnt].Event)();
		}
	}
}

//--------------------------------------------------
// Description  : Decrease timer counts while 10ms Interrupt is up
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void CTimerDecreaseTimerCnt(void)
{
	uint8_t ucTimerDecCnt = 0;

	for(ucTimerDecCnt = 0; ucTimerDecCnt < _MAX_EVENT_AMOUNT; ucTimerDecCnt++)
	{
		if((g_stTimerEvent[ucTimerDecCnt].Time != _INACTIVE_TIMER_EVENT) && (g_stTimerEvent[ucTimerDecCnt].Time != 0))
		{
			g_stTimerEvent[ucTimerDecCnt].Time--;
		}
	}
}


//--------------------------------------------------
// Description  : Set up a timer for an event. If the event is exist,
//                this function is ignored and do not change the executing time.
// Input Value  : usTime    --> Unit in 10ms, range in 0.01 ~ 655.3 sec
//                Event     --> Execute Event while timeup
// Output Value : None
//--------------------------------------------------
void CTimerActiveTimerEvent(uint32_t usTime, void (*Event)())
{
	uint8_t ucTimerEventCnt = 0;

	for(ucTimerEventCnt = 0; ucTimerEventCnt < _MAX_EVENT_AMOUNT; ucTimerEventCnt++)
	{
		if((g_stTimerEvent[ucTimerEventCnt].Time != _INACTIVE_TIMER_EVENT) && (g_stTimerEvent[ucTimerEventCnt].Event == Event))
		{
			return;
		}
	}

	for(ucTimerEventCnt = 0; ucTimerEventCnt < _MAX_EVENT_AMOUNT; ucTimerEventCnt++)
	{
		if(g_stTimerEvent[ucTimerEventCnt].Time == _INACTIVE_TIMER_EVENT)
		{
			g_bTimer1Ctrl = true;
			g_stTimerEvent[ucTimerEventCnt].Time = usTime;
			g_bTimer1Ctrl = false;
			g_stTimerEvent[ucTimerEventCnt].Event = Event;
			break;
		}
	}
}

//--------------------------------------------------
// Description  : Reactive a timer for an event. If the event is exist,
//                this function will reset the executing time and restart.
// Input Value  : usTime    --> Unit in 10ms, range in 0.01 ~ 655.3 sec
//                Event     --> Execute Event while timeup
// Output Value : None
//--------------------------------------------------
void CTimerReactiveTimerEvent(uint32_t usTime, void (*Event)())
{
	uint8_t ucTimerEventCnt = 0;

	for(ucTimerEventCnt = 0; ucTimerEventCnt < _MAX_EVENT_AMOUNT; ucTimerEventCnt++)
	{
		if((g_stTimerEvent[ucTimerEventCnt].Time != _INACTIVE_TIMER_EVENT) && (g_stTimerEvent[ucTimerEventCnt].Event == Event))
		{
			g_bTimer1Ctrl = true;
			g_stTimerEvent[ucTimerEventCnt].Time = usTime;
			g_bTimer1Ctrl = false;
			return;
		}
	}

	CTimerActiveTimerEvent(usTime, Event);
}


//--------------------------------------------------
// Description  : Cancel an event
// Input Value  : Event     --> Event which we want to cancel
// Output Value : None
//--------------------------------------------------
void CTimerCancelTimerEvent(void (*Event)())
{
	uint8_t ucTimerEventCnt = 0;

	for(ucTimerEventCnt = 0; ucTimerEventCnt < _MAX_EVENT_AMOUNT; ucTimerEventCnt++)
	{
		if(g_stTimerEvent[ucTimerEventCnt].Event == Event)
		{
			g_bTimer1Ctrl = true;
			g_stTimerEvent[ucTimerEventCnt].Time = _INACTIVE_TIMER_EVENT;
			g_bTimer1Ctrl = false;

		}
	}

}


//--------------------------------------------------
// Description  : Initial timer and events. We have to run this function at firmware startup
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void CTimerInitialTimerEvent(void)
{
	uint8_t ucTimerEventCnt = 0;

	for(ucTimerEventCnt = 0; ucTimerEventCnt < _MAX_EVENT_AMOUNT; ucTimerEventCnt++)
	{
		g_stTimerEvent[ucTimerEventCnt].Time = _INACTIVE_TIMER_EVENT;
	}
}
