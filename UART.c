/*#include<p18f4580.h>	
void main()
{
	TRISCbits.RC6=0;
	TRISCbits.RC7=1;
	TXSTA=0X24;
	RCSTA=0X90;
	SPBRG=0X19;
while(1)
{
	TXREG='A';
}
	
}*/




////TXREG.................................................................................................................................................................................................

#include<p18f4580.h>
void main()
{	
	char arr[6]="vikram";
	int i;
	TRISCbits.RC6=0;
	TRISCbits.RC7=1;
	TXSTA=0X24;
	RCSTA=0X90;
	SPBRG=129;
while(1)
{
	for(i=0;i<6;i++)
{
	TXREG=arr[i];
}
}	
}


///RXREG................................................................................................................................................................................

/*#include<p18f4580.h>
#define led PORTCbits.RC0
void main()
{
	int A;
	TRISCbits.RC0=0;
	TRISCbits.RC6=0;
	TRISCbits.RC7=1;
	TXSTA=0X24;
	RCSTA=0X90;
	SPBRG=0X19;
while(1)
{
	A=RCREG;
	while(PIR1bits.RCIF==0);

	switch(A)
	{
		case '1':
		led=1;
		break;
		case '0':
		led=0;
		break;
	}

PIR1bits.RCIF=0;

}
	
}
*/
