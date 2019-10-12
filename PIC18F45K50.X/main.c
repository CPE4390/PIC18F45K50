#include <xc.h>
#include "LCD.h"

void main(void) {
    int count = 0;
    
    //Initialize oscillator settings
    OSCTUNE = 0x80; //3X PLL ratio mode selected
    OSCCON = 0x70; //Switch to 16MHz HFINTOSC
    OSCCON2 = 0x10; //Enable PLL, SOSC, PRI OSC drivers turned off
    while (OSCCON2bits.PLLRDY != 1); //Wait for PLL lock
    ACTCON = 0x90; //Enable active clock tuning for USB operation

    LCDInit();
    lprintf(0, "PIC18F45K50");
    while (1) {
        lprintf(1, "%d", count);
        ++count;
        __delay_ms(1000);
    }
}
