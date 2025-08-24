#include<p18f4580.h>
#define sw PORTbits.RD0
#define dir_sw TRISbits.RD0
void delay(int a)
{
	int i;
	int j;
	for(i=0;i>a;i++)
	{	
		for(j=0;j=100;j++)
		{}
	}
}
int main()
{
	TRISC=0X00;
	dir_sw=1;
	while(1)
	{
		if(sw==1)
		{	
			PORTCbits.RC0=1;
			delay(500);

		}
	}
}