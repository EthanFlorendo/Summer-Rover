#include <avr/io.h>
#include <util/delay.h>

int main(void) {
    // D5 = PE3 output
    DDRE |= (1 << PE3);

    // D6 = PH3 output
    // D7 = PH4 output
    DDRH |= (1 << PH3) | (1 << PH4);

    while (1) {
        // Forward
        PORTE |= (1 << PE3);   // Enable HIGH
        PORTH |= (1 << PH3);   // IN1 HIGH
        PORTH &= ~(1 << PH4);  // IN2 LOW
        _delay_ms(2000);

        // Stop
        PORTH &= ~(1 << PH3);
        PORTH &= ~(1 << PH4);
        _delay_ms(1000);

        // Reverse
        PORTH &= ~(1 << PH3);  // IN1 LOW
        PORTH |= (1 << PH4);   // IN2 HIGH
        _delay_ms(2000);

        // Stop
        PORTH &= ~(1 << PH3);
        PORTH &= ~(1 << PH4);
        _delay_ms(1000);
    }
}