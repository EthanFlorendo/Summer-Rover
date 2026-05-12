#include <avr/io.h>
#include <util/delay.h>

/* Arduino Mega pin 13 = PB7 on ATmega2560 */
#define LED_BIT  PB7
#define LED_DDR  DDRB
#define LED_PORT PORTB

#define DOT_MS   200.0
#define DASH_MS  600.0
#define SYM_GAP  200.0
#define LET_GAP  600.0
#define WORD_GAP 1400.0

static inline void led_on(void)  { LED_PORT |=  (1 << LED_BIT); }
static inline void led_off(void) { LED_PORT &= ~(1 << LED_BIT); }

static void dot(void) {
    led_on();  _delay_ms(DOT_MS);
    led_off(); _delay_ms(SYM_GAP);
}

static void dash(void) {
    led_on();  _delay_ms(DASH_MS);
    led_off(); _delay_ms(SYM_GAP);
}

/* S = · · ·   O = — — — */
static void sos(void) {
    dot(); dot(); dot();
    _delay_ms(LET_GAP);
    dash(); dash(); dash();
    _delay_ms(LET_GAP);
    dot(); dot(); dot();
}

int main(void) {
    LED_DDR |= (1 << LED_BIT);

    for (;;) {
        sos();
        _delay_ms(WORD_GAP);
    }
}
