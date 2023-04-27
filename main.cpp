#include "mbed.h"

// Defines objects for the analog inputs and PWM outputs
AnalogIn pot1(p19);     // Potentiometer 1 input on pin p19
AnalogIn pot2(p20);     // Potentiometer 2 input on pin p20
PwmOut red(p23);        // Red LED output on pin p23
PwmOut green(p24);      // Green LED output on pin p24

// Create object for serial communication over USB
Serial pc(USBTX, USBRX);    

// Main loop 
int main() {
    
    while(1) {
        // Read the analog values of the pots and invert them (higher voltage = brighter LED)
        float red_val = 1.0 - pot1.read();    // Invert value of pot1
        float green_val = 1.0 - pot2.read();  // Invert value of pot2
        
        // Set output of the red and green LEDs using PWM
        red.write(red_val);        // Set the brightness of red LED
        green.write(green_val);    // Set the brightness of green LED
        
        // Print the potentiometer values to the serial monitor
        pc.printf("Potentiometer values - Red: %f, Green: %f\r\n", pot1.read(), pot2.read());
        // The "\r\n" at the end of the string moves the cursor to the beginning of the next line
        
        // Wait for 50ms before repeating the loop
        wait(0.05);
    }
}