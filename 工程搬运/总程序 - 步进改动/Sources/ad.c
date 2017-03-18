#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include <mc9s12xs128.h>

void AD_init()
{
    ATD0CTL0=0x00;
  //  ATD0CTL1=0x10;//8位分辨率，采样前电容放电
 //   ATD0CTL1=0x00;//8位分辨率，采样前电容不放电
 //   ATD0CTL1=0x30;//10位分辨率，采样前电容放电
 //   ATD0CTL1=0x20;//10位分辨率，采样前电容不放电
      ATD0CTL1=0x50;//12位分辨率，采样前电容放电
 //   ATD0CTL1=0x40;//12位分辨率，采样前电容不放电
    ATD0CTL2=0x00;
    ATD0CTL3=0x88;//数据采样结果右对齐，采样长度为1
    ATD0CTL4=0x03;//采样时钟=80/（2+3*1）=10MHz
    
}

void AD_start(uchar channel)
{
    ATD0CTL5_Cx=channel;
}

uint result()
{
    uint data;
    while(!ATD0STAT0_SCF);
    data=ATD0DR0;
    return data;
}