#include<p18f458.h>
#define led PORTCbits.RC0
#define dir_led TRISCbits.RC0 
void delay();
void main()
{
	T2CON=0X0A;
	dir_led=0;
	while(1)
	{
		led=0;
		delay();
		led=1;
		delay();
	}

}
void delay()
{
	TMR2=0X00;
	PR2=0X9c;
	T2CONbits.TMR2ON=1;
	PIR1bits.TMR2IF=0;
	while(PIR1bits.TMR2IF !=1);
	{
	T2CONbits.TMR2ON=0;
	PIR1bits.TMR2IF =0;
	}

	
}