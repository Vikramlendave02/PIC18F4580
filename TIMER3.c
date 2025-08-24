#include<p18f4580.h>
#define led  PORTDbits.RD0
//#define dir_led TRISDbits.RD0
void delay();
void delay()
{
	TMR3H=0X3C;//FOR 250 uS TIMER HEX VALUE IS 85ED
	TMR3L=0XAF;
	T3CONbits.TMR3ON=1;
	PIR2bits.TMR3IF=0;
	while(PIR2bits.TMR3IF == 0);
	{
		T3CONbits.TMR3ON=0;
		PIR2bits.TMR3IF = 0;
	}

}
void main()
{	T3CON=0X80;
	//dir_led=0;
	TRISDbits.RD0=0;
	while(1)
	{
	//	dir_led=0;
		led=1;
		delay();
		led=0;
		delay();
	}
}