#ifndef __MUSIC_CONTROL_
#define __MUSIC_CONTROL
#include "ch32v30x.h"
#include "debug.h"
void  MUSIC_PLAY(void);//���ֲ���
void  MUSIC_PAUSE(void);//������ͣ
void  MUSIC_LAST(void);//��һ��
void  MUSIC_NEXT(void);//��һ��
void  MUSIC_ADD(void);//������
void  MUSIC_Decrease(void);//������
void  MUSIC_LEVER(u8 lever);
void  MUSIC_INIT(void);
void  MUSIC_SOUND_UP(u8 initial_value,u8 target_value);
void  MUSIC_SOUND_DOWN(u8 initial_value,u8 target_value);
#endif
