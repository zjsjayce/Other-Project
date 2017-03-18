#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include <mc9s12xs128.h>

void AD_init()
{
    ATD0CTL0=0x00;
  //  ATD0CTL1=0x10;//8λ�ֱ��ʣ�����ǰ���ݷŵ�
 //   ATD0CTL1=0x00;//8λ�ֱ��ʣ�����ǰ���ݲ��ŵ�
 //   ATD0CTL1=0x30;//10λ�ֱ��ʣ�����ǰ���ݷŵ�
 //   ATD0CTL1=0x20;//10λ�ֱ��ʣ�����ǰ���ݲ��ŵ�
      ATD0CTL1=0x50;//12λ�ֱ��ʣ�����ǰ���ݷŵ�
 //   ATD0CTL1=0x40;//12λ�ֱ��ʣ�����ǰ���ݲ��ŵ�
    ATD0CTL2=0x00;
    ATD0CTL3=0x88;//���ݲ�������Ҷ��룬��������Ϊ1
    ATD0CTL4=0x03;//����ʱ��=80/��2+3*1��=10MHz
    
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