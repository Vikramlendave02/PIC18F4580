/*#include<p18f4580.h>
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
#include<p18f4580.h>
#define led  PORTDbits.RD0
//#define dir_led TRISDbits.RD0
void delay();
void delay()
{
	TMR1H=0X85;//FOR 250 uS TIMER HEX VALUE IS 85ED
	TMR1L=0XED;
	T1CONbits.TMR1ON=1;
	PIR1bits.TMR1IF=0;
	while(PIR1bits.TMR1IF == 0);
	{
		T1CONbits.TMR1ON=0;
		PIR1bits.TMR1IF = 0;
	}

}
void main()
{	T1CON=0XF0;
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
}*/


#include <p18f4580.h>

#define led PORTCbits.RC0

// Function Prototypes
void timer1_init(void);
void interrupt_handler(void);

// Setup vector to jump to ISR
#pragma code high_vector=0x08
void high_vector(void) {
    _asm GOTO interrupt_handler _endasm
}

// Declare the ISR
#pragma interrupt interrupt_handler
void interrupt_handler(void) {
    if (PIR1bits.TMR1IF == 1) {
        TMR1H = 0x85; // Reload for 250us delay
        TMR1L = 0xED;
        led = ~led;  // Toggle LED
        PIR1bits.TMR1IF = 0; // Clear the interrupt flag
    }
}

void timer1_init(void) {
    T1CON = 0x31;         // Prescaler 8, Timer1 ON, Internal clock (Fosc/4)
    TMR1H = 0x85;         // Load high byte for 250us
    TMR1L = 0xED;         // Load low byte for 250us
    PIE1bits.TMR1IE = 1;  // Enable Timer1 interrupt
    PIR1bits.TMR1IF = 0;  // Clear Timer1 interrupt flag
    INTCONbits.PEIE = 1;  // Enable peripheral interrupts
    INTCONbits.GIE = 1;   // Enable global interrupts
}

void main(void) {
    ADCON1 = 0x0F;           // Make PORTA/PORTB digital
    TRISDbits.RD0 = 0;       // Set RD0 as output
    led = 0;                 // Initially turn LED off

    timer1_init();           // Configure Timer1

    while (1) {
        // Main loop does nothing. Timer1 interrupt handles the LED toggle.
    }
}
