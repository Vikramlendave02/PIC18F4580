#include <p18f4580.h>

// Define control lines for LCD connected to PORTC pins
#define RS PORTCbits.RC0  // Register Select
#define E  PORTCbits.RC2  // Enable pin

// Function declarations
void data(char dt);      // Function to send data to LCD
void cmd(char cm);       // Function to send command to LCD
void delay(int a);       // Function to create delay
void string(const rom char* str);

void main()
{
    TRISC = 0x00;  // Set PORTC as output (for RS, RW, E)
    TRISD = 0x0F;  // Set PORTD as output (for sending data/commands to LCD)

    // LCD initialization sequence
    cmd(0x02);     // Initialize in 4-bit mode
    cmd(0x08);     // Display OFF
    cmd(0x01);     // Clear display
    cmd(0x80);     // Set cursor to beginning of first line
    cmd(0x28);     // 8-bit mode, 2-line display, 5x7 matrix
    cmd(0x0e);     // Display ON, cursor ON

    while(1)
    {
        string("vikram");  // Display "vikram" on the LCD
    }
}

// Function to send command to LCD
void cmd(char cm)
{
    int temp;
    temp = (cm & 0xf0);
    PORTD = temp;  // Place command on data lines
    RS = 0;        // RS = 0 for command
    E = 1;         // Enable pulse to latch the command
    delay(100);    // Wait for LCD to process
    E = 0;         // End enable pulse

    temp = (cm & 0x0f);
    temp = temp << 4;
    PORTD = temp;
    E = 1;         // Enable pulse to latch the command
    delay(100);    // Wait for LCD to process
    E = 0;
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
    int temp;
    temp = (dt & 0xf0);
    PORTD = temp;  // Place data on data lines
    RS = 1;        // RS = 1 for data
    E = 1;         // Enable pulse to latch the data
    delay(100);    // Wait for LCD to process
    E = 0;         // End enable pulse

    temp = (dt & 0x0f);
    temp = temp << 4;
    PORTD = temp;
    E = 1;         // Enable pulse to latch the data
    delay(100);    // Wait for LCD to process
    E = 0;
}

// Function to send a string to LCD
void string(const rom char* str)
{
    while (*str != '\0')
    {
        data(*str++);
    }
}
