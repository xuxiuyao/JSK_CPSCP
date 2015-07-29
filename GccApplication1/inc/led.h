/*
 * led.h
 *
 * Created: 2015/1/23 13:39:17
 *  Author: ÐíÐÞÒ«
 */ 


#ifndef LED_H_
#define LED_H_


extern void LedInit(void);
extern void LedOn(void);
extern void LedOff(void);
extern void LedFlashing(uint8_t times);
extern void BlueLightOn(void);
extern void BlueLightOff(void);
extern void WhiteLightOn(void);
extern void WhiteLightOff(void);

#endif /* LED_H_ */