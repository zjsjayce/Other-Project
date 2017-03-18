#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include <mc9s12xs128.h>
void SetBusCLK_8M() 
{    
    CLKSEL = 0X00;          //disengage PLL to system 
    PLLCTL_PLLON = 1;   //turn on PLL 
    SYNR = 0x02;                         
    REFDV = 0x05;  
    POSTDIV = 0x00;          //pllclock=2*osc*(1+SYNR)/(1+REFDV)=16MHz; 
    _asm(nop);                     //BUS CLOCK=8M 
    _asm(nop); 
    while(!(CRGFLG_LOCK == 1));   //when pll is steady ,then use it; 
    CLKSEL_PLLSEL = 1;                  //engage PLL to system;  
}

void SetBusCLK_12M() 
{    
    CLKSEL = 0X00;          //disengage PLL to system 
    PLLCTL_PLLON = 1;   //turn on PLL 
    SYNR = 0x02;                         
    REFDV = 0x03;  
    POSTDIV = 0x00;          //pllclock=2*osc*(1+SYNR)/(1+REFDV)=24MHz; 
    _asm(nop);                     //BUS CLOCK=12M 
    _asm(nop); 
    while(!(CRGFLG_LOCK == 1));   //when pll is steady ,then use it; 
    CLKSEL_PLLSEL = 1;                  //engage PLL to system;  
}

void SetBusCLK_24M() 
{    
    CLKSEL = 0X00;          //disengage PLL to system 
    PLLCTL_PLLON = 1;   //turn on PLL 
    SYNR = 0xc0 | 0x02;                         
    REFDV = 0xc0 | 0x01;  
    POSTDIV = 0x00;          //pllclock=2*osc*(1+SYNR)/(1+REFDV)=48MHz; 
    _asm(nop);                     //BUS CLOCK=24M 
    _asm(nop); 
    while(!(CRGFLG_LOCK == 1));   //when pll is steady ,then use it; 
    CLKSEL_PLLSEL = 1;                  //engage PLL to system;  
}

void SetBusCLK_48M() 
{    
    CLKSEL = 0X00;          //disengage PLL to system 
    PLLCTL_PLLON = 1;   //turn on PLL 
    SYNR = 0xc0 | 0x05;                         
    REFDV = 0xc0 | 0x01;  
    POSTDIV = 0x00;          //pllclock=2*osc*(1+SYNR)/(1+REFDV)=96MHz; 
    _asm(nop);                     //BUS CLOCK=48M 
    _asm(nop); 
    while(!(CRGFLG_LOCK == 1));   //when pll is steady ,then use it; 
    CLKSEL_PLLSEL = 1;                  //engage PLL to system;  
} 

  void SetBusCLK_80M()
{   
	CLKSEL=0X00;				//disengage PLL to system
	PLLCTL_PLLON=1;			//turn on PLL
	SYNR =0xc0 | 0x09;                        
	REFDV=0x80 | 0x01; 
	POSTDIV=0x00;       //pllclock=2*osc*(1+SYNR)/(1+REFDV)=160MHz;
	_asm(nop);                //BUS CLOCK=80M
	_asm(nop);
	while(!(CRGFLG_LOCK==1));	  //when pll is steady ,then use it;
	CLKSEL_PLLSEL =1;		               //engage PLL to system; 
}
