#include<p18f4580.h>
int delay(int a)
{
	int i;
	int j;

	for(i=0;i<a;i++)
	{
		for(j=0;j<100;j++)
		{}
	}
}
int main()
{
	while (1)
	{
		TRISC=0x00;
		PORTC=0X0F;
		//
		delay(500);
		//TRISC=0xff;
		PORTC=0XF0;
	//	PORTCbits.RC0=0;
	delay(500);
	}
}