#include<reg52.h>
#define uint unsigned int

sbit P16=P1^6; 	//���� ����
sbit P17=P1^7;	//���� ����
sbit P20=P2^0;	//���� �ҵ�� 
sbit P21=P2^1;	//���� �ҵ��  
sbit LED1=P2^2;	//��ߵ�led����
sbit LED2=P2^3;	//�м��led����
sbit LED3=P2^4;	//�ұߵ�led����
sbit yi=P1^0;  	//�ұ�����1������Թ�
sbit er=P1^1;  	//�ұ�����2������Թ�
sbit san=P1^2;  //�ұ�����3������Թ�
sbit si=P1^3;  	//�ұ�����4������Թ�
sbit light=P1^4;//��翪��
sbit P26=P2^6;
sbit P27=P2^7;

void delayms(uint xms)
{
	uint i,j;
	for(i=xms;i>0;i--)
		for(j=110;j>0;j--);
}

void left()	//��ת(�ҵ��ת)
{
	P16=1;P17=1;P20=1;P21=0;
	delayms(10);
	P16=1;P17=1;P20=1;P21=1;
	LED1=0;	//��ߵ�led����
	delayms(10);
	LED1=1;
	delayms(5);


}

void go()	//ǰ��
{
	P16=0;P17=1;P20=1;P21=0;
	delayms(25);
	P16=1;P17=1;P20=1;P21=1;
	LED1=0;LED2=0;LED3=0;	//������ȫ��
	delayms(10);
	LED1=1;LED2=1;LED3=1;	//������ȫ��
	delayms(5);
}

void right()	//��ת(����ת)
{
	P16=0;P17=1;P20=1;P21=1;
	delayms(10);
	P16=1;P17=1;P20=1;P21=1;
	LED3=0;	//�ұߵ�led����
	delayms(10);
	LED3=1;
	delayms(5) ;	

	P16=0;P17=1;P20=1;P21=0;
	delayms(10);
	P16=1;P17=1;P20=1;P21=1;
	LED1=0;LED2=0;LED3=0;	//������ȫ��
	delayms(10);
	LED1=1;LED2=1;LED3=1;	//������ȫ��
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
			P16=1;P17=1;P20=1;P21=0;  //���
			delayms(700);
			P16=1;P17=1;P20=1;P21=1;
			P16=0;P17=1;P20=1;P21=0;  //ֱ��
			delayms(1000);
			P16=1;P17=1;P20=1;P21=1;
			P16=0;P17=1;P20=1;P21=1;  //�ҹ�
			delayms(500);
			P16=1;P17=1;P20=1;P21=1;
			P16=0;P17=1;P20=1;P21=0;  //ֱ��
			delayms(1500);
			P16=1;P17=1;P20=1;P21=1;
			P16=0;P17=1;P20=1;P21=1;  //�ҹ�
			delayms(500);
			P16=1;P17=1;P20=1;P21=1;
			P16=0;P17=1;P20=1;P21=0;  //ֱ��
			delayms(900);
			P16=1;P17=1;P20=1;P21=1;
			P16=1;P17=1;P20=1;P21=0;  //���
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