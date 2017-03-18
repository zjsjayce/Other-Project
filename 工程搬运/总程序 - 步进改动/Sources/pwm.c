#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include <mc9s12xs128.h>
#define uchar unsigned char


void pwm1init()     //80MHz
{
    PWMPOL_PPOL1=1; //��ʼ���Ϊ�ߵ�ƽ
    PWMCLK_PCLK1=1;//ͨ��0ʱ��ѡ��ΪSA
    PWMPRCLK_PCKA0=0; //ʱ��A��ƵΪ5MHZ
     PWMPRCLK_PCKA1=1; //ʱ��A��ƵΪ5MHZ
      PWMPRCLK_PCKA2=1; //ʱ��A��ƵΪ5MHZ
    PWMCAE_CAE1=0;//���Ϊ��������
    PWMSCLA=50;//����ʱ��SAΪ10khz=A/2*PWMSCLA
    PWMPER1=100;//T=0.01S=����ʱ������
    PWMDTY1=0;
    PWME_PWME1=1;//���Ϊ100hz,ռ�ձ�80%    
}
void pwm1(uchar a) 
{
    PWMDTY1=a;
    //PWME_PWME1=1;//���Ϊ100Hz��T=0.01S,ռ�ձ�20%
}
  
void pwm3init()
{
    PWMPOL_PPOL3=1;  //��ʼ���Ϊ�ߵ�ƽ
    PWMCLK_PCLK3=1; //ͨ��0ʱ��ѡ��ΪSB
    PWMPRCLK_PCKB0=0; //ʱ��BΪ5MHz
     PWMPRCLK_PCKB1=1; //ʱ��BΪ5MHz 
      PWMPRCLK_PCKB2=1; //ʱ��BΪ5MHz
    PWMCAE_CAE3=0; //���Ϊ�����
    PWMSCLB=50;//SBΪ10KHz
    PWMPER3=100;
    PWMDTY3=0;
    PWME_PWME3=1;   
}
void pwm3(uchar a)
{
    PWMDTY3=a;
    //PWME_PWME3=1;//���Ϊ100hz,ռ�ձ�40%
}
  
void pwm4init()     //80MHz
{
    PWMPOL_PPOL4=1; //��ʼ���Ϊ�ߵ�ƽ
    PWMCLK_PCLK4=1;//ͨ��0ʱ��ѡ��ΪSA
    PWMPRCLK_PCKA0=0; //ʱ��A��ƵΪ5MHZ
     PWMPRCLK_PCKA1=1; //ʱ��A��ƵΪ5MHZ
      PWMPRCLK_PCKA2=1; //ʱ��A��ƵΪ5MHZ
    PWMCAE_CAE4=0;//���Ϊ��������
    PWMSCLA=50;//����ʱ��SAΪ10khz=A/2*PWMSCLA
    PWMPER4=100;//T=0.01S
    PWMDTY4=0;
    PWME_PWME4=1;//���Ϊ100hz,ռ�ձ�80%  
}
void pwm4(uchar a)
{
    PWMDTY4=a;
    //PWME_PWME4=1;//���Ϊ100Hz��T=0.01S,ռ�ձ�50%  
}
  
void pwm5init()     //80MHz
{
    PWMPOL_PPOL5=1; //��ʼ���Ϊ�ߵ�ƽ
    PWMCLK_PCLK5=1;//ͨ��0ʱ��ѡ��ΪSA
    PWMPRCLK_PCKA0=0; //ʱ��A��ƵΪ5MHZ
     PWMPRCLK_PCKA1=1; //ʱ��A��ƵΪ5MHZ
      PWMPRCLK_PCKA2=1; //ʱ��A��ƵΪ5MHZ
    PWMCAE_CAE5=0;//���Ϊ��������
    PWMSCLA=50;//����ʱ��SAΪ10khz=A/2*PWMSCLA
    PWMPER5=100;//T=0.01S=����ʱ������*100
    PWMDTY5=0;
    PWME_PWME5=1;//���Ϊ100hz,ռ�ձ�80% 
}
void pwm5(uchar a) 
{
    PWMDTY5=a;
    //PWME_PWME5=1;//���Ϊ100Hz��T=0.01S,ռ�ձ�60%  
}
  
void pwm7init()
{
    PWMPOL_PPOL7=1;  //��ʼ���Ϊ�ߵ�ƽ
    PWMCLK_PCLK7=1; //ͨ��0ʱ��ѡ��ΪSB
    PWMPRCLK_PCKB0=0; //ʱ��BΪ5MHz
     PWMPRCLK_PCKB1=0; //ʱ��BΪ5MHz 
      PWMPRCLK_PCKB2=1; //ʱ��BΪ5MHz
    PWMCAE_CAE7=0; //���Ϊ�����
    PWMSCLB=250;//SBΪ10KHz
    PWMPER7=100;
    PWMDTY7=0;
    PWME_PWME7=1;//���Ϊ100hz,ռ�ձ�80%
}
void pwm7(uchar a)
{
    PWMDTY7=a;
   // PWME_PWME7=1;//���Ϊ100hz,ռ�ձ�80%
}
  