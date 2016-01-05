#include "mbed-drivers/mbed.h"

static DigitalOut led(PTB23);

static void led_on(void) {
    led = true;    
    printf("LED = %d \r\n", led.read());
}

static void led_off(void) {
    led = false;
    printf("LED = %d \r\n", led.read());
}

void app_start(int, char**) {
    static InterruptIn button(PTA2);
    
    // when we press the button the circuit closes, and put the led on
    button.rise(&led_on);
    // when we release the button the circuit opens again, put it off
    button.fall(&led_off);
}