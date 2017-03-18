#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include <mc9s12xs128.h>
#include"pwm.h"
#include"ad.h"
#include"stepmotor.h"
#include"colouridentity.h"
#include"duoji.h"

#define uint unsigned int 
#define uchar unsigned char

unsigned int xun11,xun12,xun13,xun14,xun21,xun22,xun31,xun32,xun4;
uchar num=0,flagxj,flagxj2=0;
uchar fj[3],fj_2[5],fj_3[5];

void delay(uint dt) 
{
    uint dt1,dt2,dt3,dt4;
    for(dt1=dt;dt>0;dt--)    
    {
        for(dt2=200;dt2>0;dt2--) 
        {
            for(dt3=200;dt3>0;dt3--) 
            {   
               for(dt4=2;dt4>0;dt4--);
            }
        }
    }    
}

void qianjin() 
{
    pwm1(70);
  	pwm3(0);
  	pwm4(70);
  	pwm5(0);
}
void houtui()
{
    pwm1(0);
  	pwm3(50);
  	pwm4(0);
  	pwm5(50);
}
void stop() 
{
    pwm1(0);
  	pwm3(0);
  	pwm4(0);
  	pwm5(0);
}
void zuozhuan() 
{
    pwm1(0);
  	pwm3(55);
  	pwm4(55);
  	pwm5(0);
}
 void youzhuan() 
{
    pwm1(55);
  	pwm3(0);
  	pwm4(0);
  	pwm5(55);
}
void turn_right() 
{
    pwm1(80);//80
  	pwm3(0);
  	pwm4(45);//35
  	pwm5(0);
}
void turn_right_fast() 
{
    pwm1(70);//80
  	pwm3(0);
  	pwm4(35);//35
  	pwm5(0);
}
void turn_right_slow()
{
    pwm1(70);//80
  	pwm3(0);
  	pwm4(55);//35
  	pwm5(0);
}
  
void turn_left() 
{
    pwm1(45); //35
  	pwm3(0);
  	pwm4(80); //80
  	pwm5(0);
}
  
void turn_left_fast() 
{
    pwm1(35); //35
  	pwm3(0);
  	pwm4(70); //80
  	pwm5(0);
}
void turn_left_slow() 
{
    pwm1(55); //35
  	pwm3(0);
  	pwm4(70); //80
  	pwm5(0);
}
void qidong_zuo(uchar sudu) 
{
    pwm1(0);
  	pwm3(80);
  	pwm4(80);
  	pwm5(0);
  	delay(sudu);
    stop();
 }
 void qidong_you(uchar sudu) 
{
    pwm1(80);
  	pwm3(0);
  	pwm4(0);
  	pwm5(80);
  	delay(sudu);
    stop();
 }
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++ѭ������++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void xun_ji2() 
{
    AD_start(0);
    xun12=result();
    AD_start(1);
    xun13=result();
    if(xun12>600) 
    {
        PORTB_PB0=0;
        turn_left();
        
    }
    else if(xun13>600)
    {       
        PORTB_PB0=0;
        turn_right();
    } 
    else 
    {
        PORTB_PB0=1;
        qianjin();
    } 
    
}
void xun_ji4() 
{
    AD_start(8);
    xun11=result();
    AD_start(0);
    xun12=result();
    AD_start(1);
    xun13=result();
    AD_start(9);
    xun14=result();
    if(xun11>250||xun12>600) //350 650
    {
        PORTB_PB0=0;
        turn_left();
        
    }
    else if(xun13>600||xun14>480)
    {       
        PORTB_PB0=0;
        turn_right();
    } 
    else 
    {
        PORTB_PB0=1;
        qianjin();
    } 
    
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++���ߺ���++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
uchar shuxian11(uchar xian)
{   
   // flagxj2=0;     
    AD_start(8);     
    xun11=result();
    if(xun11>=280) 
    {    
        num++;
        flagxj=0;        
        while(!flagxj) 
        {
            AD_start(8);     
            xun11=result();
            if(xun11<220)
                flagxj=1;
        }
    }
    if(num==xian) 
    {   
          flagxj2=1;
          num=0;
    }
    return flagxj2;
} 
uchar shuxian14(uchar xian)
{   
   // flagxj2=0;     
    AD_start(9);     
    xun14=result();
    if(xun14>=700) 
    {    
        num++;
        flagxj=0;        
        while(!flagxj) 
        {
            AD_start(9);     
            xun14=result();
            if(xun14<500)
                flagxj=1;
        }
    }
    if(num==xian) 
    {   
          flagxj2=1;
          num=0;
    }
    return flagxj2;
}

uchar shuxian21(uchar xian)
{   
    //flagxj2=0;     
    AD_start(10);     
    xun21=result();
    if(xun21>=480) //450
    {    
        num++;
        flagxj=0;        
        while(!flagxj) 
        {
            AD_start(10);     
            xun21=result();
            if(xun21<300)
                flagxj=1;
        }
    }
    if(num==xian) 
    {   
          flagxj2=1;
          num=0;
    }
    return flagxj2;
} 
uchar shuxian31(uchar xian)
{        
    AD_start(12);     
    xun31=result();
    if(xun31>=700) 
    {    
        num++;
        flagxj=0;        
        while(!flagxj) 
        {
            AD_start(12);     
            xun31=result();
            if(xun31<430)
                flagxj=1;
        }
    }
    if(num==xian) 
    {   
          flagxj2=1;
          num=0;
    }
    return flagxj2;
} 
uchar shuxian32(uchar xian)
{        
    AD_start(13);     
    xun32=result();
    if(xun32>=600) 
    {    
        num++;
        flagxj=0;        
        while(!flagxj) 
        {
            AD_start(13);     
            xun32=result();
            if(xun32<400)
                flagxj=1;
        }
    }
    if(num==xian) 
    {   
          flagxj2=1;
          num=0;
    }
    return flagxj2;
}
uchar shuxian22(uchar xian)
{        
    AD_start(11);     
    xun22=result();
    if(xun22>=1500) 
    {    
        num++;
        flagxj=0;        
        while(!flagxj) 
        {
            AD_start(11);     
            xun22=result();
            if(xun22<1100)
                flagxj=1;
        }
    }
    if(num==xian) 
    {   
          flagxj2=1;
          num=0;
    }
    return flagxj2;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++����һȡ����++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void run() 
{
    flagxj2=0;
    while(!shuxian31(6)) //������  
    {
        xun_ji2();
    }     
    
    stop(); 
    delay(50);
    flagxj2=0;
    while(!shuxian21(2)) //��ת90��
    {
        uchar i=0;
        if(i==0)
        {
            zuozhuan();
            i=1;
        }
    }
    youzhuan();
    delay(17);
    stop();
    delay(20);
    flagxj2=0;
    while(!shuxian21(2)) //��A
    {
        xun_ji4();
    }
    stop();
    delay(40);
    duoji_90();
    delay(40);
    
    onestep_ni();        //ȡ��
    delay(30);   
    colour_init();
    delay(30); 
    fj[0]=colour_identity();
    TSCR2_TOI=0;
    TIE_C1I=0;
    
    delay(30);       
    onestep_ni();
    delay(20);
    flagxj2=0;
    while(!shuxian21(2)) // ��ת180��
    {
        uchar i=0;
        if(i==0)
        {
            zuozhuan();
            i=1;
        }
    } 
    youzhuan();
    delay(17); 
    stop();
    delay(30);
    houtui();
    delay(30);
    stop();
    delay(50);
    duoji_0();
    delay(30);
    flagxj2=0;
    while(!shuxian32(1)) //��E
    {
        xun_ji4();
    }
    flagxj2=0;
    while(!shuxian21(5)) //��E
    {
        xun_ji2();
    }
 
    stop();
    delay(30);
    duoji_90();   
    delay(30);            //ȡ��
    onestep_ni();
    delay(10);
    colour_init();
    delay(30); 
    fj[1]=colour_identity();
    TSCR2_TOI=0;
    TIE_C1I=0;
    
    onestep_ni();
    flagxj2=0;
    while(!shuxian21(2)) // ��ת180��
    {
        uchar i=0;
        if(i==0)
        {
            zuozhuan();
            i=1;
        }
    }
    youzhuan();
    delay(17);
    
    stop();
    delay(20);
    houtui();
    delay(30);
    stop();
    delay(30);
    duoji_0();
    delay(10);
    flagxj2=0;
    qianjin();
    while(!shuxian32(1))// ������
    {
        xun_ji4();
    }
    flagxj2=0;
    while(!shuxian32(2))// ������
    {
        xun_ji2();
    }
    stop();
    delay(50);
     flagxj2=0;
    while(!shuxian22(2)) //��ת90��
    {
        uchar i=0;
        if(i==0)
        {
            youzhuan();
            i=1;
        }
    }
    zuozhuan();
    delay(17); 
    stop();
    delay(20);
    flagxj2=0;
    while(!shuxian22(2))//��C 
    {
        xun_ji4();
    }
     stop();
     delay(20);
     duoji_90();
     delay(20);
     
     onestep_ni();
     delay(10);
     colour_init();
     delay(30); 
     fj[2]=colour_identity();
    TSCR2_TOI=0;
    TIE_C1I=0;
    onestep_ni();
    delay(20);
    flagxj2=0;
    while(!shuxian21(2)) //��ת180
    {
        uchar i=0;
        if(i==0)
        {
            zuozhuan();
            i=1;
        }
    } 
    stop();
    delay(20);
    houtui();
    delay(30);
    stop();
    delay(50);
    flagxj2=0;
    qianjin();
    while(!shuxian32(1)) //������
    {
        xun_ji4();
    }
    flagxj2=0;
    while(!shuxian32(2)) //������
    {
        xun_ji2();
    } 
      stop();
      duoji_0();
      delay(50);
      
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++����һ������++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void fenjian() 
{
    flagxj2=0;
    while(!shuxian22(1+fj[2])) //��ת�ŵ�һ����
    {
        uchar i=0;
        if(i==0)
        {
            youzhuan();
            i=1;
        }
    }
    zuozhuan();
    delay(17);
    stop();
    delay(20);
    onestep_shun();            //ת����    
    delay(20);
    flagxj2=0;
    while(!shuxian11(1))       //��ͷ
    {
        xun_ji4();
    }
    flagxj2=0;
    while(!shuxian31(1))       //��ͷ
    {
        xun_ji4();
    }
    flagxj2=0;
    while(!shuxian14(1))        //��ͷ
    {
        xun_ji2();
    }
    stop();
    delay(50);
    onestep_shun();
    delay(50);
    houtui();                   //����
    delay(80);
    stop();
    delay(30);
    flagxj2=0;
    qidong_zuo(30);             //������ת
    while(!shuxian21(2))        //��ת180��
    {
        uchar i=0;
        if(i==0)
        {
            zuozhuan();
            i=1;
        }
    }                            //�ƶ�
    youzhuan();
    delay(17);
    stop();
    delay(50);
    houtui();
    delay(50);
    stop();
    delay(50);
    flagxj2=0;
    while(!shuxian32(1))        //������
    {
        xun_ji4();
    } 
    flagxj2=0;
    while(!shuxian32(2))        //������
    {
        xun_ji2();
    } 
    stop();
    delay(50); 
    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++                         
    if(fj[1]-fj[2]>=0)                     //��ת�ŵ�2����
    {
        flagxj2=0;
        while(!shuxian21(4-(fj[1]-fj[2]))) //��ת
        {
            uchar i=0;
            if(i==0)
            {
                zuozhuan();
                i=1;
            }
        }
        youzhuan();
        delay(17);
        stop();
        delay(50);
        onestep_shun();                    //ת����
        delay(20);
        flagxj2=0;
        while(!shuxian14(1))              //��ͷ
        {
            xun_ji4();
        }
        flagxj2=0;
        while(!shuxian32(1))              //��ͷ
        {
            xun_ji4();
        }
        flagxj2=0;
        while(!shuxian14(1))              //��ͷ
        {
            xun_ji2();
        }
        stop();
        delay(50);
        onestep_shun();
        delay(50);
        houtui();                         //����
        delay(80);
        stop();
        delay(30);
        flagxj2=0;
        qidong_zuo(30);                  //������ת
        while(!shuxian21(2))             //��ת180��
        {
            uchar i=0;
            if(i==0)
            {
                zuozhuan();
                i=1;
            }
        }
        youzhuan();
        delay(17);
        stop();
        delay(50);
        houtui();
        delay(50);
        stop();
        delay(50);
        flagxj2=0;
        while(!shuxian32(1))             //������
        {
            xun_ji4();
        } 
        flagxj2=0;
        while(!shuxian32(2))             //������
        {
            xun_ji2();
        } 
        stop();
        delay(50);              
    } 
    else 
    {
        flagxj2=0;
        while(!shuxian22(4+(fj[1]-fj[2]))) //��ת�ŵڶ�����
        {
            uchar i=0;
            if(i==0)
            {
                youzhuan();
                i=1;
            }
        }
        zuozhuan();
        delay(17);
        stop();
        delay(20);
        onestep_shun();                    //ת���ڶ�����
        delay(20);
        flagxj2=0;
        while(!shuxian11(1))               //��ͷ
        {
            xun_ji4();
        }
        flagxj2=0;
        while(!shuxian31(1))               //��ͷ
        {
            xun_ji4();
        }
        flagxj2=0;
        while(!shuxian14(1))               //��ͷ
        {
            xun_ji2();
        }
        stop();
        delay(50);
        onestep_shun();
        delay(50);
        houtui();                          //����
        delay(80);
        stop();
        delay(50);
        flagxj2=0;
        qidong_zuo(30);                    //������ת
        while(!shuxian21(2))               //��ת180��
        {
            uchar i=0;
            if(i==0)
            {
                zuozhuan();
                i=1;
            }
        }
        youzhuan();
        delay(17);
        stop();
        delay(30);
        houtui();
        delay(50);
        stop();
        delay(50);
        flagxj2=0;
        while(!shuxian32(1))               //������
        {
            xun_ji4();
        } 
        flagxj2=0;
        while(!shuxian32(2))               //������
        {
            xun_ji2();
        } 
        stop();
        delay(50);          
    }
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    if(fj[0]-fj[1]>=0)                       //��ת�ŵ�3����
    {
        flagxj2=0;
        while(!shuxian21(4-(fj[0]-fj[1])))   //��ת
        {
            uchar i=0;
            if(i==0)
            {
                zuozhuan();
                i=1;
            }
        }
        youzhuan();
        delay(17);
        stop();                               //����һ��
        delay(50);                          
        onestep_shun();                        //ת����������
        
        delay(50);
        flagxj2=0;
        while(!shuxian14(1))                 //��ͷ
        {
            xun_ji4();
        }
        flagxj2=0;
        while(!shuxian32(1))                 //��ͷ
        {
            xun_ji4();
        }
        flagxj2=0;
        while(!shuxian14(1))                 //��ͷ
        {
            xun_ji2();
        }
        stop();
        delay(50);
        onestep_shun();
        delay(50);
        houtui();                            //����
        delay(80);
        stop();
        delay(50);
        flagxj2=0;
        qidong_zuo(30);                      //������ת
        while(!shuxian21(2))                 //��ת180��
        {
            uchar i=0;
            if(i==0)
            {
                zuozhuan();
                i=1;
            }
        }
        youzhuan();
        delay(17);
        stop();
        delay(50);
        houtui();
        delay(50);
        stop();
        delay(50);
        flagxj2=0;
        while(!shuxian32(1))                 //������
        {
            xun_ji4();
        } 
        flagxj2=0;
        while(!shuxian32(2))                 //������
        {
            xun_ji2();
        } 
        stop();
        delay(50);              
    } 
    else 
    {
        flagxj2=0;
        while(!shuxian22(4+(fj[0]-fj[1])))    //��ת�ų���������
        {
            uchar i=0;
            if(i==0)
            {
                youzhuan();
                i=1;
            }
        }
        zuozhuan();
        delay(17);
        stop();
        delay(50);
        onestep_shun();                       //ת����������
        onestep_shun();
        delay(50);
        flagxj2=0;
        while(!shuxian11(1))                 //��ͷ
        {
            xun_ji4();
        }
        flagxj2=0;
        while(!shuxian31(1))                 //��ͷ
        {
            xun_ji4();
        }
        flagxj2=0;
        while(!shuxian14(1))                 //��ͷ
        {
            xun_ji2();
        }
        stop();
        delay(50);
        houtui();                            //����
        delay(80);
        stop();
        delay(30);
        flagxj2=0;
        qidong_zuo(30);                      //������ת
        while(!shuxian21(2))                 //��ת180��
        {
            uchar i=0;
            if(i==0)
            {
                zuozhuan();
                i=1;
            }
        }
        youzhuan();
        delay(17);
        stop();
        delay(30);
        houtui();
        delay(50);
        stop();
        delay(50);
        flagxj2=0;
        while(!shuxian32(1))                 //������
        {
            xun_ji4();
        } 
        flagxj2=0;
        while(!shuxian32(2)) 
        {
            xun_ji2();
        } 
        stop();
        delay(50);          
    }
      
} 
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++�����ȡ����++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void fenjian2() 
{   
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++�������һ��ȡ��++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    if(6-fj[0]>=4) 
    {
        flagxj2=0;
        while(!shuxian22(6-fj[0]-4))         //�ص�������
        {
            uchar i=0;
            if(i==0)
            {
                youzhuan();
                i=1;
            }
        } 
        stop();
        delay(30);
        flagxj2=0;
        while(!shuxian21(3))                 //��ͷ
        {
             xun_ji4();
        }     
    } 
    else
    {
        flagxj2=0;
        while(!shuxian21(4-(6-fj[0])))       //�ص�������
        {
            uchar i=0;
            if(i==0)
            {
                zuozhuan();
                i=1;
            }
        } 
        stop();
        delay(30);
        flagxj2=0;
        while(!shuxian22(1))                 //��ͷ
        {
             xun_ji4();
        }
        flagxj2=0;
        while(!shuxian32(2))                 //��ͷ
        {
             xun_ji4();
        }         
    }                                       //��G
    stop();
    delay(50);
    duoji_90();
    delay(30); 
    flagxj2=0;
    while(!shuxian31(2))                 //����
    {
        uchar i=0;
        if(i==0)
        {
            houtui();
        }
    }
    stop();
    delay(50);
    duoji_0();                            //�򿪵���
    delay(100); 
    flagxj2=0;
    while(!shuxian31(2))                 //��һ��ǰ��
    {
         xun_ji4();
    } 
    stop();    
    delay(10);     
    onestep_ni();                         //ȡ��
    delay(30);   
    colour_init();
    delay(10); 
    fj_2[0]=colour_identity();
    TSCR2_TOI=0;
    TIE_C1I=0;    
    delay(10);       
    onestep_ni();
    delay(30);
    duoji_90();                          //�رյ��� 
    delay(30);
    flagxj2=0;
    while(!shuxian31(2))                 //�ڶ�������
    {
        uchar i=0;
        if(i==0)
        {
            houtui();
        }
    }
    stop();
    duoji_0();                            //�򿪵���
    delay(100); 
    flagxj2=0;
    while(!shuxian31(2))                 //�ڶ���ǰ��
    {
         xun_ji4();
    } 
    stop();
    delay(10);     
    onestep_ni();                         //ȡ��
    delay(30);   
    colour_init();
    delay(10); 
    fj_2[1]=colour_identity();
    TSCR2_TOI=0;
    TIE_C1I=0;    
    delay(10);       
    onestep_ni();
    delay(20);
    duoji_90();                          //�رյ��� 
    delay(20);
    flagxj2=0;
    while(!shuxian31(2))                 //����������
    {
        uchar i=0;
        if(i==0)
        {
            houtui();
        }
    }
    stop();
    duoji_0();                            //�򿪵���
    delay(100); 
    flagxj2=0;
    while(!shuxian31(2))                 //������ǰ��
    {
         xun_ji4();
    }
    stop();    
    delay(10);     
    onestep_ni();                        //ȡ��
    delay(30);   
    colour_init();
    delay(10); 
    fj_2[2]=colour_identity();
    TSCR2_TOI=0;
    TIE_C1I=0;    
    delay(10);       
    onestep_ni();
    delay(30);
    duoji_90();                          //�رյ��� 
    delay(30);
    flagxj2=0;
    while(!shuxian31(2))                 //���ĸ�����
    {
        uchar i=0;
        if(i==0)
        {
            houtui();
        }
    }
    stop();
    duoji_0();                            //�򿪵���
    delay(100); 
    flagxj2=0;
    while(!shuxian31(2))                 //���ĸ�ǰ��
    {
         xun_ji4();
    } 
     stop();    
    delay(10);     
    onestep_ni();                         //ȡ��
    delay(30);   
    colour_init();
    delay(10); 
    fj_2[3]=colour_identity();
    TSCR2_TOI=0;
    TIE_C1I=0;    
    delay(10);       
    onestep_ni();
    delay(30);
    duoji_90();                          //�رյ��� 
    delay(30);
    flagxj2=0;
    while(!shuxian31(2))                 //���������
    {
        uchar i=0;
        if(i==0)
        {
            houtui();
        }
    }
    stop();
    duoji_0();                            //�򿪵���
    delay(100); 
    flagxj2=0;
    while(!shuxian31(2))                 //�����ǰ��
    {
         xun_ji4();
    } 
    stop();
    duoji_90();                          //�رյ��� 
    delay(30);
    delay(10);     
    onestep_ni();                         //ȡ��
    delay(30);   
    colour_init();
    delay(10); 
    fj_2[4]=colour_identity();
    TSCR2_TOI=0;
    TIE_C1I=0;    
    delay(10);       
    //onestep_ni();
    delay(100);
    flagxj2=0;
    while(!shuxian31(1))                 
    {
        uchar i=0;
        if(i==0)
        {
            houtui();
        }
    }
    flagxj2=0;
    while(!shuxian21(1))                 
    {
        uchar i=0;
        if(i==0)
        {
            houtui();
        }
    }
    flagxj2=0;
    qidong_zuo(30);                      //������ת
    while(!shuxian21(2))                 //��ת180��
    {
         uchar i=0;
         if(i==0)
         {
              zuozhuan();
                i=1;
          }
     }
     youzhuan();
     delay(17);
     stop();
     delay(50);
     flagxj2=0;
     while(!shuxian22(1))                 
     {
          uchar i=0;
          if(i==0)
          {
              xun_ji4();
          }
     } 
     flagxj2=0;
     while(!shuxian32(2))                 
     {
          uchar i=0;
          if(i==0)
          {
              xun_ji2();
          }
     }                                      //ȡ�����
     stop();
     duoji_0();
     delay(50);                        
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++�������һ�η���++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
     if(fj_2[0]>=2)                                     //�ŵ�һ����
     {
        flagxj2=0;
        while(!shuxian22(fj_2[0]-2)) //��ת�ŵ�һ����
        {
            uchar i=0;
            if(i==0)
            {
                youzhuan();
                i=1;
            }
        }
        zuozhuan();
        delay(17);
        stop();
        delay(50);
        flagxj2=0;
        while(!shuxian11(1))       //��ͷ
        {
            xun_ji4();
        }
        flagxj2=0;
        while(!shuxian31(1))       //��ͷ
        {
            xun_ji4();
        }
        flagxj2=0;
        while(!shuxian14(1))        //��ͷ
        {
            xun_ji2();
        }
        stop();
        delay(50);
        onestep_ni();
        houtui();                   //����
        delay(80);
        stop();
        delay(30);
        flagxj2=0;
        qidong_zuo(30);             //������ת
        while(!shuxian21(2))        //��ת180��
        {
            uchar i=0;
            if(i==0)
            {
                zuozhuan();
                i=1;
            }
        }                            //�ƶ�
        youzhuan();
        delay(17);
        stop();
        delay(50);
        houtui();
        delay(50);
        stop();
        delay(50);
        flagxj2=0;
        while(!shuxian32(1))        //������
        {
            xun_ji4();
        } 
        flagxj2=0;
        while(!shuxian32(2))        //������
        {
            xun_ji2();
        } 
        stop();
        delay(50);              
     } 
     else
     {
          flagxj2=0;
          while(!shuxian21(1)) //��ת
          {
              uchar i=0;
              if(i==0)
              {
                  zuozhuan();
                  i=1;
              }
          }
          youzhuan();
          delay(17);
          stop();
          delay(50);
          flagxj2=0;
          while(!shuxian14(1))              //��ͷ
          {
              xun_ji4();
          }
          flagxj2=0;
          while(!shuxian32(1))              //��ͷ
          {
              xun_ji4();
          }
          flagxj2=0;
          while(!shuxian14(1))              //��ͷ
          {
              xun_ji2();
          }
          stop();
          delay(50);
          onestep_ni();
          delay(50);
          houtui();                         //����
          delay(80);
          stop();
          delay(30);
          flagxj2=0;
          qidong_zuo(30);                  //������ת
          while(!shuxian21(2))             //��ת180��
          {
              uchar i=0;
              if(i==0)
              {
                  zuozhuan();
                  i=1;
              }
          }
          youzhuan();
          delay(17);
          stop();
          delay(50);
          houtui();
          delay(50);
          stop();
          delay(50);
          flagxj2=0;
          while(!shuxian32(1))             //������
          {
              xun_ji4();
          } 
          flagxj2=0;
          while(!shuxian32(2))             //������
          {
              xun_ji2();
          } 
          stop();
          delay(50);              
     }
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
     if(fj_2[1]-fj_2[0]>=0)                     //�������ת�ŵ�2����
     {
        flagxj2=0;
        while(!shuxian21(4-(fj_2[1]-fj_2[0]))) //��ת
        {
            uchar i=0;
            if(i==0)
            {
                zuozhuan();
                i=1;
            }
        }
        youzhuan();
        delay(17);
        stop();
        delay(50);
        onestep_ni();                    //ת����
        delay(20);
        flagxj2=0;
        while(!shuxian14(1))              //��ͷ
        {
            xun_ji4();
        }
        flagxj2=0;
        while(!shuxian32(1))              //��ͷ
        {
            xun_ji4();
        }
        flagxj2=0;
        while(!shuxian14(1))              //��ͷ
        {
            xun_ji2();
        }
        stop();
        delay(50);
        onestep_ni();
        delay(50);
        houtui();                         //����
        delay(80);
        stop();
        delay(30);
        flagxj2=0;
        qidong_zuo(30);                  //������ת
        while(!shuxian21(2))             //��ת180��
        {
            uchar i=0;
            if(i==0)
            {
                zuozhuan();
                i=1;
            }
        }
        youzhuan();
        delay(17);
        stop();
        delay(50);
        houtui();
        delay(50);
        stop();
        delay(50);
        flagxj2=0;
        while(!shuxian32(1))             //������
        {
            xun_ji4();
        } 
        flagxj2=0;
        while(!shuxian32(2))             //������
        {
            xun_ji2();
        } 
        stop();
        delay(50);              
    } 
    else 
    {
        flagxj2=0;
        while(!shuxian22(4+(fj_2[1]-fj_2[0]))) //��ת�ŵڶ�����
        {
            uchar i=0;
            if(i==0)
            {
                youzhuan();
                i=1;
            }
        }
        zuozhuan();
        delay(17);
        stop();
        delay(20);
        onestep_ni();                    //ת���ڶ�����
        
        delay(20);
        flagxj2=0;
        while(!shuxian11(1))               //��ͷ
        {
            xun_ji4();
        }
        flagxj2=0;
        while(!shuxian31(1))               //��ͷ
        {
            xun_ji4();
        }
        flagxj2=0;
        while(!shuxian14(1))               //��ͷ
        {
            xun_ji2();
        }
        stop();
        delay(50);
        onestep_ni();
        delay(50);
        houtui();                          //����
        delay(80);
        stop();
        delay(50);
        flagxj2=0;
        qidong_zuo(30);                    //������ת
        while(!shuxian21(2))               //��ת180��
        {
            uchar i=0;
            if(i==0)
            {
                zuozhuan();
                i=1;
            }
        }
        youzhuan();
        delay(17);
        stop();
        delay(30);
        houtui();
        delay(50);
        stop();
        delay(50);
        flagxj2=0;
        while(!shuxian32(1))               //������
        {
            xun_ji4();
        } 
        flagxj2=0;
        while(!shuxian32(2))               //������
        {
            xun_ji2();
        } 
        stop();
        delay(50);          
    }
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
     if(fj_2[2]-fj_2[1]>=0)                     //�������ת�ŵ�3����
     {
        flagxj2=0;
        while(!shuxian21(4-(fj_2[2]-fj_2[1]))) //��ת
        {
            uchar i=0;
            if(i==0)
            {
                zuozhuan();
                i=1;
            }
        }
        youzhuan();
        delay(17);
        stop();
        delay(50);
        onestep_ni();                    //ת����
        //onestep_ni();
        delay(20);
        flagxj2=0;
        while(!shuxian14(1))              //��ͷ
        {
            xun_ji4();
        }
        flagxj2=0;
        while(!shuxian32(1))              //��ͷ
        {
            xun_ji4();
        }
        flagxj2=0;
        while(!shuxian14(1))              //��ͷ
        {
            xun_ji2();
        }
        stop();
        delay(50);
        onestep_ni(); 
        delay(50);
        houtui();                         //����
        delay(80);
        stop();
        delay(30);
        flagxj2=0;
        qidong_zuo(30);                  //������ת
        while(!shuxian21(2))             //��ת180��
        {
            uchar i=0;
            if(i==0)
            {
                zuozhuan();
                i=1;
            }
        }
        youzhuan();
        delay(17);
        stop();
        delay(50);
        houtui();
        delay(50);
        stop();
        delay(50);
        flagxj2=0;
        while(!shuxian32(1))             //������
        {
            xun_ji4();
        } 
        flagxj2=0;
        while(!shuxian32(2))             //������
        {
            xun_ji2();
        } 
        stop();
        delay(50);              
    } 
    else 
    {
        flagxj2=0;
        while(!shuxian22(4+(fj_2[2]-fj_2[1]))) //��ת�ŵ�3����
        {
            uchar i=0;
            if(i==0)
            {
                youzhuan();
                i=1;
            }
        }
        zuozhuan();
        delay(17);
        stop();
        delay(20);
        onestep_ni();                    //ת����3����
        //onestep_ni();
        delay(20);
        flagxj2=0;
        while(!shuxian11(1))               //��ͷ
        {
            xun_ji4();
        }
        flagxj2=0;
        while(!shuxian31(1))               //��ͷ
        {
            xun_ji4();
        }
        flagxj2=0;
        while(!shuxian14(1))               //��ͷ
        {
            xun_ji2();
        }
        stop();
        delay(50);
        onestep_ni();
        delay(50);
        houtui();                          //����
        delay(80);
        stop();
        delay(50);
        flagxj2=0;
        qidong_zuo(30);                    //������ת
        while(!shuxian21(2))               //��ת180��
        {
            uchar i=0;
            if(i==0)
            {
                zuozhuan();
                i=1;
            }
        }
        youzhuan();
        delay(17);
        stop();
        delay(30);
        houtui();
        delay(50);
        stop();
        delay(50);
        flagxj2=0;
        while(!shuxian32(1))               //������
        {
            xun_ji4();
        } 
        flagxj2=0;
        while(!shuxian32(2))               //������
        {
            xun_ji2();
        } 
        stop();
        delay(50);          
    }
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
     if(fj_2[3]-fj_2[2]>=0)                     //�������ת�ŵ�4����
     {
        flagxj2=0;
        while(!shuxian21(4-(fj_2[3]-fj_2[2]))) //��ת
        {
            uchar i=0;
            if(i==0)
            {
                zuozhuan();
                i=1;
            }
        }
        youzhuan();
        delay(17);
        stop();
        delay(50);
        onestep_ni();                    //ת����
        //onestep_ni();
        delay(20);
        flagxj2=0;
        while(!shuxian14(1))              //��ͷ
        {
            xun_ji4();
        }
        flagxj2=0;
        while(!shuxian32(1))              //��ͷ
        {
            xun_ji4();
        }
        flagxj2=0;
        while(!shuxian14(1))              //��ͷ
        {
            xun_ji2();
        }
        stop();
        delay(50);
        onestep_ni();
        delay(50);
        houtui();                         //����
        delay(80);
        stop();
        delay(30);
        flagxj2=0;
        qidong_zuo(30);                  //������ת
        while(!shuxian21(2))             //��ת180��
        {
            uchar i=0;
            if(i==0)
            {
                zuozhuan();
                i=1;
            }
        }
        youzhuan();
        delay(17);
        stop();
        delay(50);
        houtui();
        delay(50);
        stop();
        delay(50);
        flagxj2=0;
        while(!shuxian32(1))             //������
        {
            xun_ji4();
        } 
        flagxj2=0;
        while(!shuxian32(2))             //������
        {
            xun_ji2();
        } 
        stop();
        delay(50);              
    } 
    else 
    {
        flagxj2=0;
        while(!shuxian22(4+(fj_2[3]-fj_2[2]))) //��ת�ŵ�4����
        {
            uchar i=0;
            if(i==0)
            {
                youzhuan();
                i=1;
            }
        }
        zuozhuan();
        delay(17);
        stop();
        delay(20);
        onestep_ni();                    //ת����4����
        //onestep_ni();
        delay(20);
        flagxj2=0;
        while(!shuxian11(1))               //��ͷ
        {
            xun_ji4();
        }
        flagxj2=0;
        while(!shuxian31(1))               //��ͷ
        {
            xun_ji4();
        }
        flagxj2=0;
        while(!shuxian14(1))               //��ͷ
        {
            xun_ji2();
        }
        stop();
        delay(50);
        onestep_ni();
        delay(50);
        houtui();                          //����
        delay(80);
        stop();
        delay(50);
        flagxj2=0;
        qidong_zuo(30);                    //������ת
        while(!shuxian21(2))               //��ת180��
        {
            uchar i=0;
            if(i==0)
            {
                zuozhuan();
                i=1;
            }
        }
        youzhuan();
        delay(17);
        stop();
        delay(30);
        houtui();
        delay(50);
        stop();
        delay(50);
        flagxj2=0;
        while(!shuxian32(1))               //������
        {
            xun_ji4();
        } 
        flagxj2=0;
        while(!shuxian32(2))               //������
        {
            xun_ji2();
        } 
        stop();
        delay(50);          
    }
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
     if(fj_2[4]-fj_2[3]>=0)                     //�������ת�ŵ�5����
     {
        flagxj2=0;
        while(!shuxian21(4-(fj_2[4]-fj_2[3]))) //��ת
        {
            uchar i=0;
            if(i==0)
            {
                zuozhuan();
                i=1;
            }
        }
        youzhuan();
        delay(17);
        stop();
        delay(50);
        onestep_ni();                    //ת����
        //onestep_ni();
        delay(20);
        flagxj2=0;
        while(!shuxian14(1))              //��ͷ
        {
            xun_ji4();
        }
        flagxj2=0;
        while(!shuxian32(1))              //��ͷ
        {
            xun_ji4();
        }
        flagxj2=0;
        while(!shuxian14(1))              //��ͷ
        {
            xun_ji2();
        }
        stop();
        delay(50);
        onestep_ni();
        delay(50);
        houtui();                         //����
        delay(80);
        stop();
        delay(30);
        flagxj2=0;
        qidong_zuo(30);                  //������ת
        while(!shuxian21(2))             //��ת180��
        {
            uchar i=0;
            if(i==0)
            {
                zuozhuan();
                i=1;
            }
        }
        youzhuan();
        delay(17);
        stop();
        delay(50);
        houtui();
        delay(50);
        stop();
        delay(50);
        flagxj2=0;
        while(!shuxian32(1))             //������
        {
            xun_ji4();
        } 
        flagxj2=0;
        while(!shuxian32(2))             //������
        {
            xun_ji2();
        } 
        stop();
        delay(50);              
    } 
    else 
    {
        flagxj2=0;
        while(!shuxian22(4+(fj_2[4]-fj_2[3]))) //��ת�ŵ�5����
        {
            uchar i=0;
            if(i==0)
            {
                youzhuan();
                i=1;
            }
        }
        zuozhuan();
        delay(17);
        stop();
        delay(20);
        onestep_ni();                    //ת����5����
        //onestep_ni();
        delay(20);
        flagxj2=0;
        while(!shuxian11(1))               //��ͷ
        {
            xun_ji4();
        }
        flagxj2=0;
        while(!shuxian31(1))               //��ͷ
        {
            xun_ji4();
        }
        flagxj2=0;
        while(!shuxian14(1))               //��ͷ
        {
            xun_ji2();
        }
        stop();
        delay(50);
        onestep_ni();
        delay(50);
        houtui();                          //����
        delay(80);
        stop();
        delay(50);
        flagxj2=0;
        qidong_zuo(30);                    //������ת
        while(!shuxian21(2))               //��ת180��
        {
            uchar i=0;
            if(i==0)
            {
                zuozhuan();
                i=1;
            }
        }
        youzhuan();
        delay(17);
        stop();
        delay(30);
        houtui();
        delay(50);
        stop();
        delay(50);
        flagxj2=0;
        while(!shuxian32(1))               //������
        {
            xun_ji4();
        } 
        flagxj2=0;
        while(!shuxian32(2))               //������
        {
            xun_ji2();
        } 
        stop();
        delay(50);          
    }
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++������ڶ���ȡ��++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    if(8-fj_2[4]>=4) 
    {
        flagxj2=0;
        while(!shuxian22(8-fj_2[4]-4))         //�ص�������
        {
            uchar i=0;
            if(i==0)
            {
                youzhuan();
                i=1;
            }
        } 
        stop();
        delay(30);
        flagxj2=0;
        while(!shuxian21(3))                 //��ͷ
        {
             xun_ji4();
        }     
    } 
    else
    {
        flagxj2=0;
        while(!shuxian21(4-(8-fj_2[4])))       //�ص�������
        {
            uchar i=0;
            if(i==0)
            {
                zuozhuan();
                i=1;
            }
        } 
        stop();
        delay(30);
        flagxj2=0;
        while(!shuxian22(1))                 //��ͷ
        {
             xun_ji4();
        }
        flagxj2=0;
        while(!shuxian32(2))                 //��ͷ
        {
             xun_ji4();
        }         
    }                                       //��F
    stop();
    delay(50);
    duoji_90();
    delay(30); 
    flagxj2=0;
    while(!shuxian31(2))                 //����
    {
        uchar i=0;
        if(i==0)
        {
            houtui();
        }
    }
    stop();
    delay(50);
    duoji_0();                            //�򿪵���
    delay(100); 
    flagxj2=0;
    while(!shuxian31(2))                 //��һ��ǰ��
    {
         xun_ji4();
    } 
    stop();    
    delay(10);     
    onestep_ni();                         //ȡ��
    delay(30);   
    colour_init();
    delay(10); 
    fj_3[0]=colour_identity();
    TSCR2_TOI=0;
    TIE_C1I=0;    
    delay(10);       
    onestep_ni();
    delay(30);
    duoji_90();                          //�رյ��� 
    delay(30);
    flagxj2=0;
    while(!shuxian31(2))                 //�ڶ�������
    {
        uchar i=0;
        if(i==0)
        {
            houtui();
        }
    }
    stop();
    duoji_0();                            //�򿪵���
    delay(100); 
    flagxj2=0;
    while(!shuxian31(2))                 //�ڶ���ǰ��
    {
         xun_ji4();
    } 
    stop();
    delay(10);     
    onestep_ni();                         //ȡ��
    delay(30);   
    colour_init();
    delay(10); 
    fj_3[1]=colour_identity();
    TSCR2_TOI=0;
    TIE_C1I=0;    
    delay(10);       
    onestep_ni();
    delay(20);
    duoji_90();                          //�رյ��� 
    delay(20);
    flagxj2=0;
    while(!shuxian31(2))                 //����������
    {
        uchar i=0;
        if(i==0)
        {
            houtui();
        }
    }
    stop();
    duoji_0();                            //�򿪵���
    delay(100); 
    flagxj2=0;
    while(!shuxian31(2))                 //������ǰ��
    {
         xun_ji4();
    }
    stop();    
    delay(10);     
    onestep_ni();                        //ȡ��
    delay(30);   
    colour_init();
    delay(10); 
    fj_3[2]=colour_identity();
    TSCR2_TOI=0;
    TIE_C1I=0;    
    delay(10);       
    onestep_ni();
    delay(30);
    duoji_90();                          //�رյ��� 
    delay(30);
    flagxj2=0;
    while(!shuxian31(2))                 //���ĸ�����
    {
        uchar i=0;
        if(i==0)
        {
            houtui();
        }
    }
    stop();
    duoji_0();                            //�򿪵���
    delay(100); 
    flagxj2=0;
    while(!shuxian31(2))                 //���ĸ�ǰ��
    {
         xun_ji4();
    } 
     stop();    
    delay(10);     
    onestep_ni();                         //ȡ��
    delay(30);   
    colour_init();
    delay(10); 
    fj_3[3]=colour_identity();
    TSCR2_TOI=0;
    TIE_C1I=0;    
    delay(10);       
    onestep_ni();
    delay(30);
    duoji_90();                          //�رյ��� 
    delay(30);
    flagxj2=0;
    while(!shuxian31(2))                 //���������
    {
        uchar i=0;
        if(i==0)
        {
            houtui();
        }
    }
    stop();
    duoji_0();                            //�򿪵���
    delay(100); 
    flagxj2=0;
    while(!shuxian31(2))                 //�����ǰ��
    {
         xun_ji4();
    } 
    stop();
   // duoji_90();                          //�رյ��� 
    delay(30);
    delay(10);     
    onestep_ni();                         //ȡ��
    delay(30);   
    colour_init();
    delay(10); 
    fj_3[4]=colour_identity();
    TSCR2_TOI=0;
    TIE_C1I=0;    
    delay(10);       
    //onestep_ni();
    delay(100);
    flagxj2=0;
    while(!shuxian31(1))                 
    {
        uchar i=0;
        if(i==0)
        {
            houtui();
        }
    }
    flagxj2=0;
    while(!shuxian21(1))                 
    {
        uchar i=0;
        if(i==0)
        {
            houtui();
        }
    }
    flagxj2=0;
    qidong_zuo(30);                      //������ת
    while(!shuxian21(2))                 //��ת180��
    {
         uchar i=0;
         if(i==0)
         {
              zuozhuan();
                i=1;
          }
     }
     youzhuan();
     delay(17);
     stop();
     delay(50);
     flagxj2=0;
     while(!shuxian22(1))                 
     {
          uchar i=0;
          if(i==0)
          {
              xun_ji4();
          }
     } 
     flagxj2=0;
     while(!shuxian32(2))                 
     {
          uchar i=0;
          if(i==0)
          {
              xun_ji2();
          }
     }                                      //ȡ�����
     stop();
     duoji_0();
     delay(50);
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++�������2�η���++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
     if(fj_3[0]<=4)                                     //�ŵ�һ����
     {
        flagxj2=0;
        while(!shuxian22(4-fj_3[0])) //��ת�ŵ�һ����
        {
            uchar i=0;
            if(i==0)
            {
                zuozhuan();
                i=1;
            }
        }
        youzhuan();
        delay(17);
        stop();
        delay(50);
        flagxj2=0;
        while(!shuxian14(1))       //��ͷ
        {
            xun_ji4();
        }
        flagxj2=0;
        while(!shuxian31(1))       //��ͷ
        {
            xun_ji4();
        }
        flagxj2=0;
        while(!shuxian14(1))        //��ͷ
        {
            xun_ji2();
        }
        stop();
        delay(50);
        onestep_ni();
        delay(50);
        houtui();                   //����
        delay(80);
        stop();
        delay(30);
        flagxj2=0;
        qidong_zuo(30);             //������ת
        while(!shuxian21(2))        //��ת180��
        {
            uchar i=0;
            if(i==0)
            {
                zuozhuan();
                i=1;
            }
        }                            //�ƶ�
        youzhuan();
        delay(17);
        stop();
        delay(50);
        houtui();
        delay(50);
        stop();
        delay(50);
        flagxj2=0;
        while(!shuxian32(1))        //������
        {
            xun_ji4();
        } 
        flagxj2=0;
        while(!shuxian32(2))        //������
        {
            xun_ji2();
        } 
        stop();
        delay(50);              
     } 
     else
     {
          flagxj2=0;
          while(!shuxian21(1)) //��ת
          {
              uchar i=0;
              if(i==0)
              {
                  youzhuan();
                  i=1;
              }
          }
          zuozhuan();
          delay(17);
          stop();
          delay(50);
          flagxj2=0;
          while(!shuxian11(1))              //��ͷ
          {
              xun_ji4();
          }
          flagxj2=0;
          while(!shuxian32(1))              //��ͷ
          {
              xun_ji4();
          }
          flagxj2=0;
          while(!shuxian14(1))              //��ͷ
          {
              xun_ji2();
          }
          stop();
          delay(50);
          onestep_ni();
          delay(50);
          houtui();                         //����
          delay(80);
          stop();
          delay(30);
          flagxj2=0;
          qidong_zuo(30);                  //������ת
          while(!shuxian21(2))             //��ת180��
          {
              uchar i=0;
              if(i==0)
              {
                  zuozhuan();
                  i=1;
              }
          }
          youzhuan();
          delay(17);
          stop();
          delay(50);
          houtui();
          delay(50);
          stop();
          delay(50);
          flagxj2=0;
          while(!shuxian32(1))             //������
          {
              xun_ji4();
          } 
          flagxj2=0;
          while(!shuxian32(2))             //������
          {
              xun_ji2();
          } 
          stop();
          delay(50);              
     }
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
     if(fj_3[1]-fj_3[0]>=0)                     //�������ת�ŵ�2����
     {
        flagxj2=0;
        while(!shuxian21(4-(fj_3[1]-fj_3[0]))) //��ת
        {
            uchar i=0;
            if(i==0)
            {
                zuozhuan();
                i=1;
            }
        }
        youzhuan();
        delay(17);
        stop();
        delay(50);
        onestep_ni();                    //ת����
        //onestep_ni();
        delay(20);
        flagxj2=0;
        while(!shuxian14(1))              //��ͷ
        {
            xun_ji4();
        }
        flagxj2=0;
        while(!shuxian32(1))              //��ͷ
        {
            xun_ji4();
        }
        flagxj2=0;
        while(!shuxian14(1))              //��ͷ
        {
            xun_ji2();
        }
        stop();
        delay(50);
        onestep_ni();
        delay(50);
        houtui();                         //����
        delay(80);
        stop();
        delay(30);
        flagxj2=0;
        qidong_zuo(30);                  //������ת
        while(!shuxian21(2))             //��ת180��
        {
            uchar i=0;
            if(i==0)
            {
                zuozhuan();
                i=1;
            }
        }
        youzhuan();
        delay(17);
        stop();
        delay(50);
        houtui();
        delay(50);
        stop();
        delay(50);
        flagxj2=0;
        while(!shuxian32(1))             //������
        {
            xun_ji4();
        } 
        flagxj2=0;
        while(!shuxian32(2))             //������
        {
            xun_ji2();
        } 
        stop();
        delay(50);              
    } 
    else 
    {
        flagxj2=0;
        while(!shuxian22(4+(fj_3[1]-fj_3[0]))) //��ת�ŵڶ�����
        {
            uchar i=0;
            if(i==0)
            {
                youzhuan();
                i=1;
            }
        }
        zuozhuan();
        delay(17);
        stop();
        delay(20);
        onestep_ni();                    //ת���ڶ�����
        //onestep_ni();
        delay(20);
        flagxj2=0;
        while(!shuxian11(1))               //��ͷ
        {
            xun_ji4();
        }
        flagxj2=0;
        while(!shuxian31(1))               //��ͷ
        {
            xun_ji4();
        }
        flagxj2=0;
        while(!shuxian14(1))               //��ͷ
        {
            xun_ji2();
        }
        stop();
        delay(50);
        onestep_ni();
        delay(50);
        houtui();                          //����
        delay(80);
        stop();
        delay(50);
        flagxj2=0;
        qidong_zuo(30);                    //������ת
        while(!shuxian21(2))               //��ת180��
        {
            uchar i=0;
            if(i==0)
            {
                zuozhuan();
                i=1;
            }
        }
        youzhuan();
        delay(17);
        stop();
        delay(30);
        houtui();
        delay(50);
        stop();
        delay(50);
        flagxj2=0;
        while(!shuxian32(1))               //������
        {
            xun_ji4();
        } 
        flagxj2=0;
        while(!shuxian32(2))               //������
        {
            xun_ji2();
        } 
        stop();
        delay(50);          
    }
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
     if(fj_3[2]-fj_3[1]>=0)                     //�������ת�ŵ�3����
     {
        flagxj2=0;
        while(!shuxian21(4-(fj_3[2]-fj_3[1]))) //��ת
        {
            uchar i=0;
            if(i==0)
            {
                zuozhuan();
                i=1;
            }
        }
        youzhuan();
        delay(17);
        stop();
        delay(50);
        onestep_ni();                    //ת����
        //onestep_ni();
        delay(20);
        flagxj2=0;
        while(!shuxian14(1))              //��ͷ
        {
            xun_ji4();
        }
        flagxj2=0;
        while(!shuxian32(1))              //��ͷ
        {
            xun_ji4();
        }
        flagxj2=0;
        while(!shuxian14(1))              //��ͷ
        {
            xun_ji2();
        }
        stop();
        delay(50);
        onestep_ni();
        delay(50);
        houtui();                         //����
        delay(80);
        stop();
        delay(30);
        flagxj2=0;
        qidong_zuo(30);                  //������ת
        while(!shuxian21(2))             //��ת180��
        {
            uchar i=0;
            if(i==0)
            {
                zuozhuan();
                i=1;
            }
        }
        youzhuan();
        delay(17);
        stop();
        delay(50);
        houtui();
        delay(50);
        stop();
        delay(50);
        flagxj2=0;
        while(!shuxian32(1))             //������
        {
            xun_ji4();
        } 
        flagxj2=0;
        while(!shuxian32(2))             //������
        {
            xun_ji2();
        } 
        stop();
        delay(50);              
    } 
    else 
    {
        flagxj2=0;
        while(!shuxian22(4+(fj_3[2]-fj_3[1]))) //��ת�ŵ�3����
        {
            uchar i=0;
            if(i==0)
            {
                youzhuan();
                i=1;
            }
        }
        zuozhuan();
        delay(17);
        stop();
        delay(20);
        onestep_ni();                    //ת����3����
        //onestep_ni();
        delay(20);
        flagxj2=0;
        while(!shuxian11(1))               //��ͷ
        {
            xun_ji4();
        }
        flagxj2=0;
        while(!shuxian31(1))               //��ͷ
        {
            xun_ji4();
        }
        flagxj2=0;
        while(!shuxian14(1))               //��ͷ
        {
            xun_ji2();
        }
        stop();
        delay(50);
        onestep_ni();
        delay(50);
        houtui();                          //����
        delay(80);
        stop();
        delay(50);
        flagxj2=0;
        qidong_zuo(30);                    //������ת
        while(!shuxian21(2))               //��ת180��
        {
            uchar i=0;
            if(i==0)
            {
                zuozhuan();
                i=1;
            }
        }
        youzhuan();
        delay(17);
        stop();
        delay(30);
        houtui();
        delay(50);
        stop();
        delay(50);
        flagxj2=0;
        while(!shuxian32(1))               //������
        {
            xun_ji4();
        } 
        flagxj2=0;
        while(!shuxian32(2))               //������
        {
            xun_ji2();
        } 
        stop();
        delay(50);          
    }
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
     if(fj_3[3]-fj_3[2]>=0)                     //�������ת�ŵ�4����
     {
        flagxj2=0;
        while(!shuxian21(4-(fj_3[3]-fj_3[2]))) //��ת
        {
            uchar i=0;
            if(i==0)
            {
                zuozhuan();
                i=1;
            }
        }
        youzhuan();
        delay(17);
        stop();
        delay(50);
        onestep_ni();                    //ת����
        //onestep_ni();
        delay(20);
        flagxj2=0;
        while(!shuxian14(1))              //��ͷ
        {
            xun_ji4();
        }
        flagxj2=0;
        while(!shuxian32(1))              //��ͷ
        {
            xun_ji4();
        }
        flagxj2=0;
        while(!shuxian14(1))              //��ͷ
        {
            xun_ji2();
        }
        stop();
        delay(50);
        onestep_ni();
        delay(50);  
        houtui();                         //����
        delay(80);
        stop();
        delay(30);
        flagxj2=0;
        qidong_zuo(30);                  //������ת
        while(!shuxian21(2))             //��ת180��
        {
            uchar i=0;
            if(i==0)
            {
                zuozhuan();
                i=1;
            }
        }
        youzhuan();
        delay(17);
        stop();
        delay(50);
        houtui();
        delay(50);
        stop();
        delay(50);
        flagxj2=0;
        while(!shuxian32(1))             //������
        {
            xun_ji4();
        } 
        flagxj2=0;
        while(!shuxian32(2))             //������
        {
            xun_ji2();
        } 
        stop();
        delay(50);              
    } 
    else 
    {
        flagxj2=0;
        while(!shuxian22(4+(fj_3[3]-fj_3[2]))) //��ת�ŵ�4����
        {
            uchar i=0;
            if(i==0)
            {
                youzhuan();
                i=1;
            }
        }
        zuozhuan();
        delay(17);
        stop();
        delay(20);
        onestep_ni();                    //ת����4����
        //onestep_ni();
        delay(20);
        flagxj2=0;
        while(!shuxian11(1))               //��ͷ
        {
            xun_ji4();
        }
        flagxj2=0;
        while(!shuxian31(1))               //��ͷ
        {
            xun_ji4();
        }
        flagxj2=0;
        while(!shuxian14(1))               //��ͷ
        {
            xun_ji2();
        }
        stop();
        delay(50);
        onestep_ni();
        delay(50);
        houtui();                          //����
        delay(80);
        stop();
        delay(50);
        flagxj2=0;
        qidong_zuo(30);                    //������ת
        while(!shuxian21(2))               //��ת180��
        {
            uchar i=0;
            if(i==0)
            {
                zuozhuan();
                i=1;
            }
        }
        youzhuan();
        delay(17);
        stop();
        delay(30);
        houtui();
        delay(50);
        stop();
        delay(50);
        flagxj2=0;
        while(!shuxian32(1))               //������
        {
            xun_ji4();
        } 
        flagxj2=0;
        while(!shuxian32(2))               //������
        {
            xun_ji2();
        } 
        stop();
        delay(50);          
    }
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
     if(fj_3[4]-fj_3[3]>=0)                     //�������ת�ŵ�5����
     {
        flagxj2=0;
        while(!shuxian21(4-(fj_3[4]-fj_3[3]))) //��ת
        {
            uchar i=0;
            if(i==0)
            {
                zuozhuan();
                i=1;
            }
        }
        youzhuan();
        delay(17);
        stop();
        delay(50);
        onestep_ni();                    //ת����
        //onestep_ni();
        delay(20);
        flagxj2=0;
        while(!shuxian14(1))              //��ͷ
        {
            xun_ji4();
        }
        flagxj2=0;
        while(!shuxian32(1))              //��ͷ
        {
            xun_ji4();
        }
        flagxj2=0;
        while(!shuxian14(1))              //��ͷ
        {
            xun_ji2();
        }
        stop();
        delay(50);
        onestep_ni();
        delay(50);
        houtui();                         //����
        delay(80);
        stop();
        delay(30);
        flagxj2=0;
        qidong_zuo(30);                  //������ת
        while(!shuxian21(2))             //��ת180��
        {
            uchar i=0;
            if(i==0)
            {
                zuozhuan();
                i=1;
            }
        }
        youzhuan();
        delay(17);
        stop();
        delay(50);
        houtui();
        delay(50);
        stop();
        delay(50);
        flagxj2=0;
        while(!shuxian32(1))             //������
        {
            xun_ji4();
        } 
        flagxj2=0;
        while(!shuxian32(2))             //������
        {
            xun_ji2();
        } 
        stop();
        delay(50);              
    } 
    else 
    {
        flagxj2=0;
        while(!shuxian22(4+(fj_3[4]-fj_3[3]))) //��ת�ŵ�5����
        {
            uchar i=0;
            if(i==0)
            {
                youzhuan();
                i=1;
            }
        }
        zuozhuan();
        delay(17);
        stop();
        delay(20);
        onestep_ni();                    //ת����5����
        //onestep_ni();
        delay(20);
        flagxj2=0;
        while(!shuxian11(1))               //��ͷ
        {
            xun_ji4();
        }
        flagxj2=0;
        while(!shuxian31(1))               //��ͷ
        {
            xun_ji4();
        }
        flagxj2=0;
        while(!shuxian14(1))               //��ͷ
        {
            xun_ji2();
        }
        stop();
        delay(50);
        onestep_ni();
        delay(50);
        houtui();                          //����
        delay(80);
        stop();
        delay(50);
        flagxj2=0;
        qidong_zuo(30);                    //������ת
        while(!shuxian21(2))               //��ת180��
        {
            uchar i=0;
            if(i==0)
            {
                zuozhuan();
                i=1;
            }
        }
        youzhuan();
        delay(17);
        stop();
        delay(30);
        houtui();
        delay(50);
        stop();
        delay(50);
        flagxj2=0;
        while(!shuxian32(1))               //������
        {
            xun_ji4();
        } 
        flagxj2=0;
        while(!shuxian32(2))               //������
        {
            xun_ji2();
        } 
        stop();
        delay(50);          
    }
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++����������ɷ��س�����+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ 
    if(7-fj_3[4]>=4) 
    {
        flagxj2=0;
        while(!shuxian22(7-fj_3[4]-4))         //�ص�������
        {
            uchar i=0;
            if(i==0)
            {
                youzhuan();
                i=1;
            }
        } 
        stop();
        delay(30);
        flagxj2=0;
        while(!shuxian21(3))                 //��ͷ
        {
             xun_ji4();
        }     
    } 
    else
    {
        flagxj2=0;
        while(!shuxian21(4-(7-fj_3[4])))       //�ص�������
        {
            uchar i=0;
            if(i==0)
            {
                zuozhuan();
                i=1;
            }
        } 
        stop();
        delay(30);
        flagxj2=0;
        while(!shuxian22(1))                 //��ͷ
        {
             xun_ji4();
        }
        flagxj2=0;
        while(!shuxian32(2))                 //��ͷ
        {
             xun_ji4();
        }         
    }                                       //��F
    stop();
    delay(50);                       
              

}

   
  