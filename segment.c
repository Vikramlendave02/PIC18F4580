#include<p18f4580.h>
void delay(int a)
{
	int i,j;
	for(i=0;i<a;i++)
	{
		for(j=0;j<100;j++)
		{
		}
	}

}
int main()
{
	int i;
	
	int ARR[10]={0X3F,0X06,0X5B,0X4F,0X66,0X6D,0X7D,0X07,0X7F,0X67};
	TRISC=0X00;
	while(1)
	{
		for(i=0;i<10;i++)
		{
			PORTC=ARR[i];
		      delay(500);
		}
	


	}
}