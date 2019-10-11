#include <xc.h>
#include "LCD.h"

void main(void) {
    int count = 0;
    LCDInit();
    lprintf (0, "PIC18F45K50");
    while (1) {
        lprintf(1, "%d", count);
        __delay_ms(1000);
    }
}
