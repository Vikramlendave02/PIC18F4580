#include<p18f4580.h>
#define led  PORTDbits.RD0
//#define dir_led TRISDbits.RD0
void delay();
void delay()
{
	TMR0H=0XFE;
	TMR0L=0X79;
	T0CONbits.TMR0ON=1;
	INTCONbits.TMR0IF=0;
	while(INTCONbits.TMR0IF == 0);
	{
		T0CONbits.TMR0ON=0;
		INTCONbits.TMR0IF = 0;
	}

}
void main()
{	T0CON=0X07;
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