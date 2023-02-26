#include "music_control.h"
void MUSIC_SendByte(uint16_t Byte)/////////////////
{
    USART_SendData(USART3,Byte);
    while(USART_GetFlagStatus(USART3,USART_FLAG_TXE)==RESET);  //不需要手动清零 再次写入TDR时会自动清零
}
void  MUSIC_PLAY(void)//音乐播放
{
    MUSIC_SendByte(0xAA);
    MUSIC_SendByte(0x02);
    MUSIC_SendByte(0x00);
    MUSIC_SendByte(0xAC);
}

void  MUSIC_PAUSE(void)//音乐暂停
{
    MUSIC_SendByte(0xAA);
    MUSIC_SendByte(0x03);
    MUSIC_SendByte(0x00);
    MUSIC_SendByte(0xAD);
}

void  MUSIC_LAST(void)//上一首
{
    MUSIC_SendByte(0xAA);
    MUSIC_SendByte(0x05);
    MUSIC_SendByte(0x00);
    MUSIC_SendByte(0xAF);
}

void  MUSIC_NEXT(void)//下一首
{
    MUSIC_SendByte(0xAA);
    MUSIC_SendByte(0x06);
    MUSIC_SendByte(0x00);
    MUSIC_SendByte(0xB0);
}

void  MUSIC_ADD(void)//声音加
{
    MUSIC_SendByte(0xAA);
    MUSIC_SendByte(0x14);
    MUSIC_SendByte(0x00);
    MUSIC_SendByte(0xBE);
}

void  MUSIC_Decrease(void)//声音减
{
    MUSIC_SendByte(0xAA);
    MUSIC_SendByte(0x15);
    MUSIC_SendByte(0x00);
    MUSIC_SendByte(0xBF);
}
void  MUSIC_LEVER(u8 lever)
{
    MUSIC_SendByte(0xAA);
    MUSIC_SendByte(0x13);
    MUSIC_SendByte(0x01);
    switch(lever)
    {
        case 0 :    MUSIC_SendByte(0x08);MUSIC_SendByte(0xC6);break;
        case 1 :    MUSIC_SendByte(0x0A);MUSIC_SendByte(0xC8);break;
        case 2 :    MUSIC_SendByte(0x0C);MUSIC_SendByte(0xCA);break;
        case 3 :    MUSIC_SendByte(0x0E);MUSIC_SendByte(0xCC);break;
        case 4 :    MUSIC_SendByte(0x10);MUSIC_SendByte(0xCE);break;
        case 5 :    MUSIC_SendByte(0x12);MUSIC_SendByte(0xD0);break;
        case 6 :    MUSIC_SendByte(0x14);MUSIC_SendByte(0xD2);break;
        case 7 :    MUSIC_SendByte(0x16);MUSIC_SendByte(0xD4);break;
        case 8 :    MUSIC_SendByte(0x18);MUSIC_SendByte(0xD6);break;
        case 9 :    MUSIC_SendByte(0x1A);MUSIC_SendByte(0xD8);break;
        case 10 :   MUSIC_SendByte(0x1C);MUSIC_SendByte(0xDA);break;
        case 11 :   MUSIC_SendByte(0x1E);MUSIC_SendByte(0xDC);break;
    }
}

void MUSIC_SOUND_UP(u8 initial_value,u8 target_value)
{
    u8 music_rex;
    for(music_rex=initial_value;music_rex<target_value+1;music_rex++)
    {
        MUSIC_LEVER(music_rex);
        Delay_Ms(200);
    }
}

void MUSIC_SOUND_DOWN(u8 initial_value,u8 target_value)
{
    u8 music_rex;
    for(music_rex=initial_value;music_rex>target_value;music_rex--)
    {
        MUSIC_LEVER(music_rex);
        Delay_Ms(200);
    }
}

void  MUSIC_INIT(void)
{
    MUSIC_PAUSE();//音乐播放
    MUSIC_SendByte(0xAA);//全部循环
    MUSIC_SendByte(0x18);
    MUSIC_SendByte(0x01);
    MUSIC_SendByte(0x00);
    MUSIC_SendByte(0xC3);

    MUSIC_LEVER(6);//初始声音lever5

    MUSIC_SendByte(0xAA);//初始循环10次
    MUSIC_SendByte(0x19);
    MUSIC_SendByte(0x02);
    MUSIC_SendByte(0x00);
    MUSIC_SendByte(0x0A);
    MUSIC_SendByte(0xCF);
}
