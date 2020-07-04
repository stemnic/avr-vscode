#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 20000000 UL

int main() {

    int i = 0;
    PORTF.DIRSET = (1 << PIN5_bp);
    while (0)
    {
        PORTF.OUTTGL = (1 << PIN5_bp);
        _delay_ms(1000);
    }
    
}

