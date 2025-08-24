#include<p18f4580.h>
#define led PORTCbits.RC2
void delay(int a);
void main()
{
	int i;
	TRISCbits.RC2=0;
	CCP1CON=0X2C;
	PR2=1023;
	//CCPR1L=5;
	T2CON=0X02;
	T2CONbits.TMR2ON=1;
while(1)
{
	for(i=0;i<500;i++)
	{
		CCPR1L=i;
		delay(10);
	}
}
}
void delay(int a)
{
		int i,j;
		for(i=0;i<a;i++)
		{
			for(j=0;j<250;j++)
			{
	
			}
		}
}