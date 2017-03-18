#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include <mc9s12xs128.h>
#define uchar unsigned char


void pwm1init()     //80MHz
{
    PWMPOL_PPOL1=1; //起始输出为高电平
    PWMCLK_PCLK1=1;//通道0时钟选择为SA
    PWMPRCLK_PCKA0=0; //时钟A分频为5MHZ
     PWMPRCLK_PCKA1=1; //时钟A分频为5MHZ
      PWMPRCLK_PCKA2=1; //时钟A分频为5MHZ
    PWMCAE_CAE1=0;//输出为左对齐输出
    PWMSCLA=50;//输入时钟SA为10khz=A/2*PWMSCLA
    PWMPER1=100;//T=0.01S=输入时钟周期
    PWMDTY1=0;
    PWME_PWME1=1;//输出为100hz,占空比80%    
}
void pwm1(uchar a) 
{
    PWMDTY1=a;
    //PWME_PWME1=1;//输出为100Hz，T=0.01S,占空比20%
}
  
void pwm3init()
{
    PWMPOL_PPOL3=1;  //起始输出为高电平
    PWMCLK_PCLK3=1; //通道0时钟选择为SB
    PWMPRCLK_PCKB0=0; //时钟B为5MHz
     PWMPRCLK_PCKB1=1; //时钟B为5MHz 
      PWMPRCLK_PCKB2=1; //时钟B为5MHz
    PWMCAE_CAE3=0; //输出为左对齐
    PWMSCLB=50;//SB为10KHz
    PWMPER3=100;
    PWMDTY3=0;
    PWME_PWME3=1;   
}
void pwm3(uchar a)
{
    PWMDTY3=a;
    //PWME_PWME3=1;//输出为100hz,占空比40%
}
  
void pwm4init()     //80MHz
{
    PWMPOL_PPOL4=1; //起始输出为高电平
    PWMCLK_PCLK4=1;//通道0时钟选择为SA
    PWMPRCLK_PCKA0=0; //时钟A分频为5MHZ
     PWMPRCLK_PCKA1=1; //时钟A分频为5MHZ
      PWMPRCLK_PCKA2=1; //时钟A分频为5MHZ
    PWMCAE_CAE4=0;//输出为左对齐输出
    PWMSCLA=50;//输入时钟SA为10khz=A/2*PWMSCLA
    PWMPER4=100;//T=0.01S
    PWMDTY4=0;
    PWME_PWME4=1;//输出为100hz,占空比80%  
}
void pwm4(uchar a)
{
    PWMDTY4=a;
    //PWME_PWME4=1;//输出为100Hz，T=0.01S,占空比50%  
}
  
void pwm5init()     //80MHz
{
    PWMPOL_PPOL5=1; //起始输出为高电平
    PWMCLK_PCLK5=1;//通道0时钟选择为SA
    PWMPRCLK_PCKA0=0; //时钟A分频为5MHZ
     PWMPRCLK_PCKA1=1; //时钟A分频为5MHZ
      PWMPRCLK_PCKA2=1; //时钟A分频为5MHZ
    PWMCAE_CAE5=0;//输出为左对齐输出
    PWMSCLA=50;//输入时钟SA为10khz=A/2*PWMSCLA
    PWMPER5=100;//T=0.01S=输入时钟周期*100
    PWMDTY5=0;
    PWME_PWME5=1;//输出为100hz,占空比80% 
}
void pwm5(uchar a) 
{
    PWMDTY5=a;
    //PWME_PWME5=1;//输出为100Hz，T=0.01S,占空比60%  
}
  
void pwm7init()
{
    PWMPOL_PPOL7=1;  //起始输出为高电平
    PWMCLK_PCLK7=1; //通道0时钟选择为SB
    PWMPRCLK_PCKB0=0; //时钟B为5MHz
     PWMPRCLK_PCKB1=0; //时钟B为5MHz 
      PWMPRCLK_PCKB2=1; //时钟B为5MHz
    PWMCAE_CAE7=0; //输出为左对齐
    PWMSCLB=250;//SB为10KHz
    PWMPER7=100;
    PWMDTY7=0;
    PWME_PWME7=1;//输出为100hz,占空比80%
}
void pwm7(uchar a)
{
    PWMDTY7=a;
   // PWME_PWME7=1;//输出为100hz,占空比80%
}
  