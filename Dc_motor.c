#include<p18f4580.h>
#define in1 PORTCbits.RC0
#define in2 PORTCbits.RC1
#define EN1 PORTCbits.RC2
#define in3 PORTCbits.RC3
#define in4 PORTCbits.RC4
#define EN2 PORTCbits.RC5
#define DIR_SW TRISDbits.RD0 
#define SW PORTDbits.RD0


void delay(int a)
{
	int i,j;
	for(i=0;i<a;i++)
	{
		for(j=0;j<100;j++)
		{}
	}
}
int main()
{	
	TRISC=0X00;
	DIR_SW=0;
	while(1)
	{
		if(SW==1)
		{	EN1=1;
			in1=0;
			in2=1;
			
			
		}
else if(SW==0)
{
			in3=1;
			in4=0;
			EN2=1;
}
		else 
		{
			EN1=1;
			EN2=1;
		}
	
		
	}
}