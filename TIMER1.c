#include<p18f4580.h>
#define led  PORTDbits.RD0
//#define dir_led TRISDbits.RD0
void delay();
void delay()
{
	TMR1H=0X85;//FOR 250 uS TIMER HEX VALUE IS 85ED
	TMR1L=0XED;
	T1CONbits.TMR1ON=1;
	PIR1bits.TMR1IF=0;
	while(PIR1bits.TMR1IF == 0);
	{
		T1CONbits.TMR1ON=0;
		PIR1bits.TMR1IF = 0;
	}

}
void main()
{	T1CON=0XF0;
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