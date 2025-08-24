#include<p18f4580.h>
#define s1 PORTDbits.RD0 // on and off
#define s2 PORTDbits.RD0
#define dir_s1 TRISDbits.RD0 // input output
#define dir_s2 TRISDbits.RD1

void delay (int a);
int main()
{
int temp;
int i;
dir_s1=0; 
dir_s2=0;
TRISC=0X00; 
TRISD=0x00;
	while(1)
	{
		
		int arr[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x67};
		for(i=0;i<100;i++)
		{
			s1=1;
			s2=0;
			temp=i/10;
			PORTC=arr[temp];
			delay(100);

			s1=0;
			s2=1;
			temp=i%10;
			PORTC=arr[temp];
			delay(100);
		}
	}
}
void delay(int a)
{
	int i,j;
	for(i=0;i<a;i++)
	{
		for(j=0;j<100;j++)
		{}
	}
}