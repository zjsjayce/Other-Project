#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include <mc9s12xs128.h>
//#define A PORTB_PB2
//#define B PORTB_PB4
//#define C PORTB_PB6
//#define D PORTB_PB7
 
uchar stepmotor_shun[8]={0xfb,0xeb,0xef,0xaf,0xbf,0x3f,0x7f,0x7b};//正向，顺时针转动
uchar stepmotor_ni[8]={0x7b,0x7f,0x3f,0xbf,0xaf,0xef,0xeb,0xfb};  //反向，逆时针转动
  
void stepm_delay(uint ms)
{
    uint t_delay,t1_delay;
    uchar t2_delay;
    for(t_delay=ms;t_delay>0;t_delay--) 
    {
        for(t1_delay=400;t1_delay>0;t1_delay--) 
        {
             for(t2_delay=200;t2_delay>0;t2_delay--);         
        }    
    }
}

void onestep_ni() 
{
    unsigned char is1,is2;
    DDRB=0XFF;  
    for(is1=51;is1>0;is1--) 
    {

        for(is2=0;is2<8;is2++) 
        {
             PORTB=stepmotor_ni[is2];
             stepm_delay(2);
        }
    }    
}
void onestep_shun() 
{
    unsigned char is1,is2;
    DDRB=0XFF;  
    for(is1=51;is1>0;is1--) 
    {

        for(is2=0;is2<8;is2++) 
        {
             PORTB=stepmotor_shun[is2];
             stepm_delay(2);
        }
    }    
}
  