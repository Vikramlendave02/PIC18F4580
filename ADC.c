#include <p18f4580.h>  // Include header file for PIC18F4580 microcontroller

// Define control lines for LCD connected to PORTC pins
#define RS PORTCbits.RC0  // Register Select: 0 = command, 1 = data
#define RW PORTCbits.RC1  // Read/Write: 0 = write, 1 = read
#define E  PORTCbits.RC2  // Enable pin for LCD

// Function declarations
void data(char dt);      // Function to send data to LCD
void cmd(char cm);       // Function to send command to LCD
void delay(int a);       // Function to create delay
void string(const rom char* str);  // Function to print a string to LCD
void lcd_init();         // Function to initialize the LCD
void display_adc_value(int adc_value); // Function to display ADC value

void main()
{
    int i;
    int arr[4];
    int adc_value;

    ADCON0 = 0x03;  // Select ADC channel 0 (AN0)
    ADCON1 = 0x0E;  // Configure analog pins
    ADCON2 = 0x88;  // Configure ADC conversion time

    TRISC = 0x00;  // Set PORTC as output (for RS, RW, E)
    TRISD = 0x00;  // Set PORTD as output (for sending data/commands to LCD)
    TRISA = 0xFF;  // Set PORTA as input (for analog input)
    
    lcd_init();  // Initialize the LCD

    while(1)
    {		lcd_init();
        ADCON0bits.GO = 1;  // Start the ADC conversion
        while(ADCON0bits.GO == 1);  // Wait until the conversion is complete
        adc_value = ((unsigned int)ADRESH << 8) | ADRESL;  // Combine high and low byte

        display_adc_value(adc_value);  // Display the ADC value on LCD
    }
}

// Function to initialize the LCD
void lcd_init()
{
    cmd(0x38);     // 8-bit mode, 2-line display, 5x7 matrix
    cmd(0x0e);     // Display ON, cursor ON
    cmd(0x01);     // Clear display
    cmd(0x80);     // Set cursor to beginning of first line
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

// Function to display ADC value on LCD
void display_adc_value(int adc_value)
{
    int i;
    int arr[4];

    // Convert the ADC value to an array of characters
    for(i = 0; i < 4; i++)
    {
        arr[i] = adc_value % 10 + 48;  // Convert each digit to ASCII
        adc_value = adc_value / 10;    // Move to the next digit
    }

    // Display the value on the LCD
    for(i = 3; i >= 0; i--)
    {
        data(arr[i]);  // Send each digit to the LCD
    }
}
