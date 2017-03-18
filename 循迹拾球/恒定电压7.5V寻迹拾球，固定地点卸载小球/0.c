#include<reg52.h>
#define uint unsigned int

sbit P16=P1^6; 	//负极 左电机
sbit P17=P1^7;	//正极 左电机
sbit P20=P2^0;	//正极 右电机 
sbit P21=P2^1;	//负极 右电机  
sbit LED1=P2^2;	//左边的led灯亮
sbit LED2=P2^3;	//中间的led灯亮
sbit LED3=P2^4;	//右边的led灯亮
sbit yi=P1^0;  	//右边数第1个红外对管
sbit er=P1^1;  	//右边数第2个红外对管
sbit san=P1^2;  //右边数第3个红外对管
sbit si=P1^3;  	//右边数第4个红外对管
sbit light=P1^4;//光电开关
sbit P26=P2^6;
sbit P27=P2^7;

void delayms(uint xms)
{
	uint i,j;
	for(i=xms;i>0;i--)
		for(j=110;j>0;j--);
}

void left()	//左转(右电机转)
{
	P16=1;P17=1;P20=1;P21=0;
	delayms(10);
	P16=1;P17=1;P20=1;P21=1;
	LED1=0;	//左边的led灯亮
	delayms(10);
	LED1=1;
	delayms(5);


}

void go()	//前进
{
	P16=0;P17=1;P20=1;P21=0;
	delayms(25);
	P16=1;P17=1;P20=1;P21=1;
	LED1=0;LED2=0;LED3=0;	//三个灯全亮
	delayms(10);
	LED1=1;LED2=1;LED3=1;	//三个灯全灭
	delayms(5);
}

void right()	//右转(左电机转)
{
	P16=0;P17=1;P20=1;P21=1;
	delayms(10);
	P16=1;P17=1;P20=1;P21=1;
	LED3=0;	//右边的led灯亮
	delayms(10);
	LED3=1;
	delayms(5) ;	

	P16=0;P17=1;P20=1;P21=0;
	delayms(10);
	P16=1;P17=1;P20=1;P21=1;
	LED1=0;LED2=0;LED3=0;	//三个灯全亮
	delayms(10);
	LED1=1;LED2=1;LED3=1;	//三个灯全灭
	delayms(5);
}

void back()
{
	P16=1;P17=1;P20=1;P21=1;
	delayms(500);
	P16=1;P17=0;P20=0;P21=1;
	delayms(1000);
	while(1)
   	{
   		P16=1;P17=1;P20=1;P21=1;
   	}
}

void main(void)
{   
	while(1)
	{
		P26=1;
		P27=1;
		if(light==0)
		{
			P16=1;P17=1;P20=1;P21=0;  //左拐
			delayms(700);
			P16=1;P17=1;P20=1;P21=1;
			P16=0;P17=1;P20=1;P21=0;  //直行
			delayms(1000);
			P16=1;P17=1;P20=1;P21=1;
			P16=0;P17=1;P20=1;P21=1;  //右拐
			delayms(500);
			P16=1;P17=1;P20=1;P21=1;
			P16=0;P17=1;P20=1;P21=0;  //直行
			delayms(1500);
			P16=1;P17=1;P20=1;P21=1;
			P16=0;P17=1;P20=1;P21=1;  //右拐
			delayms(500);
			P16=1;P17=1;P20=1;P21=1;
			P16=0;P17=1;P20=1;P21=0;  //直行
			delayms(900);
			P16=1;P17=1;P20=1;P21=1;
			P16=1;P17=1;P20=1;P21=0;  //左拐
			delayms(700);
			P16=1;P17=1;P20=1;P21=1;	
		}
		if(light==1)
		{
			if(er==1&&san==0&&si==0)
			right();
			else if(yi==1&&san==0&&si==0)
			right();
			else if(san==1&&er==0&&yi==0)
			left();
			else if(si==1&&yi==0&&er==0)
			left();
			else if(yi==0&&er==1&&san==1)
			go();
			else if(si==0&&er==1&&san==1)
			go();
			else if(er==1&&san==1&&si==1)
			back();
			else if(yi==1&&er==1&&san==1)
			back();
			else
			go();
		}
	}
}