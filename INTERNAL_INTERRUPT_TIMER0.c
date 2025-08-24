#include<p18f4580.h>
#define led  PORTCbits.RC0
void ext_interrupt();
//#define dir_led TRISDbits.RD0



void main()
{	

//T0CON=0X07;
	//dir_led=0;
	TRISCbits.RC0=0;
	RCONbits.IPEN=0;
	INTCON=0XE0;
	T0CON=0X87;
	TMR0H=0XFE;
	TMR0L=0X79;
	led=0;
	while(1)
	{

	}
}
#pragma code ext_interrupt=0x08   ///ext_interruptis a function name and 0x08 is a priority
#pragma interrupt ext_interrupt   ///
void ext_interrupt()
{
	TMR0H=0XFE;
	TMR0L=0X79;

	led=~led;
	INTCONbits.TMR0IF=0;


}