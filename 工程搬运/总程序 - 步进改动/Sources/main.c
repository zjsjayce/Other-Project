#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include"busclock.h"
#include"pwm.h"
#include"ad.h"
#include"xunji.h"
#include"stepmotor.h"
#include"duoji.h"
#include"colouridentity.h"


void init_all() 
{
    SetBusCLK_80M();
    pwm1init();
    pwm3init();
    pwm4init();
    pwm5init();
    pwm7init();
    AD_init();
    DDRA=0XFF;
    DDRB=0XFF;
    DDRK=0xff;       
}

void main(void) 
{
    EnableInterrupts;
    init_all();
    duoji_0();    
    run();
    fenjian();
    fenjian2();
    while(1);
    
}
