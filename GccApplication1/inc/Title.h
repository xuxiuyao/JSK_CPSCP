/*
 * Title.h
 *
 * Created: 2015/2/6 16:08:02
 *  Author: USER
 */ 


#ifndef TITLE_H_
#define TITLE_H_

extern bool g_bTitle1Change;
extern bool g_bTitle2Change;

extern void SetTitle2(void);
extern void SetTitle3(void);
#if(_FOCUS_OOR_TIPS == 1)
extern void OORDisplay(void);
#endif

extern void TitleHandle(void);
extern void ShowProductInfo(unsigned char  LineNum);
#ifdef _ALWAYS_SHOW_COMP_TYPE
extern void AlsoShowVersion(unsigned char LineNum);
#endif


#endif /* TITLE_H_ */
