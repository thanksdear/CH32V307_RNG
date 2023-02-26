#ifndef __MUSIC_CONTROL_
#define __MUSIC_CONTROL
#include "ch32v30x.h"
#include "debug.h"
void  MUSIC_PLAY(void);//音乐播放
void  MUSIC_PAUSE(void);//音乐暂停
void  MUSIC_LAST(void);//上一首
void  MUSIC_NEXT(void);//下一首
void  MUSIC_ADD(void);//声音加
void  MUSIC_Decrease(void);//声音减
void  MUSIC_LEVER(u8 lever);
void  MUSIC_INIT(void);
void  MUSIC_SOUND_UP(u8 initial_value,u8 target_value);
void  MUSIC_SOUND_DOWN(u8 initial_value,u8 target_value);
#endif
