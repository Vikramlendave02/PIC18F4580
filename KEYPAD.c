#include <p18f4580.h> // Include header file for PIC18F4580 microcontroller

// Define control lines for LCD connected to PORTC pins
#define RS PORTCbits.RC0  // Register Select: 0 = command, 1 = data
#define RW PORTCbits.RC1  // Read/Write: 0 = write, 1 = read
#define E  PORTCbits.RC2  // Enable pin for LCD

// Function declarations
void data(char dt);      // Function to send data to LCD
void cmd(char cm);       // Function to send command to LCD
void delay(int a);       // Function to create delay
void string(const rom char* str);

void main()
{
	int i;
	ADCON1=0X0F;
	TRISB=0XF0;
	
	
    TRISC = 0x00;  // Set PORTC as output (for RS, RW, E)
    TRISD = 0x00;  // Set PORTD as output (for sending data/commands to LCD)

    // LCD initialization sequence
    cmd(0x08);     // Display OFF
    cmd(0x01);     // Clear display
    cmd(0x80);     // Set cursor to beginning of first line
    cmd(0x38);     // 8-bit mode, 2-line display, 5x7 matrix
    cmd(0x0e);     // Display ON, cursor ON

    while(1)
    {
	PORTB=0XFE;
	if(PORTB==0XeE)
	{
		while(PORTB==0XeE)
		{
			data('7');

		}
	}	
PORTB=0Xde;
	if(PORTB==0Xde)
	{
		while(PORTB==0Xde)
		{
			data('8');

		}
	}	
PORTB=0Xbe;
	if(PORTB==0Xbe)
	{
		while(PORTB==0XbE)
		{
			data('9');

		}
	}	



//char *str="Vikram";
	//	string("vikram");
       // data('V'); // Display character 'V' continuously on LCD
        // This will repeatedly send 'V' without clearing or moving the cursor
    }

    // The below code is commented out and unused
    // PORTD = 0xFF;
    // int str[] = {"hello!"};
}

// Function to send command to LCD
void cmd(char cm)
{
    PORTD = cm;  // Place command on data lines
    RS = 0;      // RS = 0 for command
    RW = 0;      // RW = 0 for write
    E = 1;       // Enable pulse to latch the command
    delay(100);  // Wait for LCD to process
    E = 0;       // End enable pulse
}

// Function to introduce delay
void delay(int a)
{
    int i, j;
    for(i = 0; i < a; i++)
    {
        for(j = 0; j < 100; j++)
        {
            // Simple nested loop delay
        }
    }
}

// Function to send data (character) to LCD
void data(char dt)
{
    PORTD = dt;  // Place data on data lines
    RS = 1;      // RS = 1 for data
    RW = 0;      // RW = 0 for write
    E = 1;       // Enable pulse to latch the data
    delay(100);  // Wait for LCD to process
    E = 0;       // End enable pulse
}
void string(const rom char* str)
{
	while(*str != '\0')
	{
		data(*str);
		*str++;
	}

}