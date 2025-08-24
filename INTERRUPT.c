#include<p18f4580.h>
#define led PORTCbits.RC0
void ext_interrupt(void);
void main()
{
int i;
TRISCbits.RC0=0;////led is output device
ADCON1=0x0f;///port b and port a use as a digital
RCONbits.IPEN=0;
INTCON=0x90;

while(1)
{

}
}
#pragma code ext_interrupt=0x08   ///ext_interruptis a function name and 0x08 is a priority
#pragma interrupt ext_interrupt   ///
void ext_interrupt()
{
while(INTCONbits.INT0IF==1)
{
led=~led;
INTCONbits.INT0IF=0;

}
}