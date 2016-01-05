# Blinky on a breadboard

We've seen how to blink the built-in LED, but the great thing about dev kits is that they allow us to add new sensors and peripherals. Let's use an external LED instead.

## The hardware

Get a breadboard, a 220 ohm resistor (or something close to 220 ohm), and two wires. 

To know how we should connect everything together we need to take a look at the pinout of the board. Normally, this is listed on the board's page on the mbed website (for example, here is the [FRDM-K64F pinout](https://www.mbed.com/en/development/hardware/boards/nxp/frdm_k64f/)). You can also do an image search for '[board-name] pinout'.

![Finding pinouts with your favourite search engine](assets/bb01.png)

For the LED sample we just need a ground pin and a digital pin, so note down the digital pin you're using (on the image below I wired it up to an FRDM-K64F on pin PTB23) and set up the circuit.

![Sketch of a LED wired up on a breadboard](assets/bb-sketch-led.png)

![LED wired up on a breadboard](assets/bb02.png)

*Black wire running from GND to the short leg of the LED. Orange wire running from PTB23 via a resistor to the long leg of the LED.*

## Changing the code

Now we need to configure the LED in our Blinky code to no longer reference `LED1`. 

Change the blinky function to:

```
static void blinky(void) {
    static DigitalOut led(PTB23);
    led = !led;
    printf("LED = %d \r\n",led.read());
}
```

Now the LED on the breadboard blinks, rather than the LED on the board.

## Adding a button

Since we have the breadboard ready anyway, we can also change this program to toggle the LED when a button is being pressed, rather than every 500ms.

First we need to take another digital pin (in my case PTA2), and wire the button up on the breadboard. Make sure to also have a pull-down resistor to ground. 

![Sketch of a button and a LED on a breadboard](assets/bb-sketch-btn.png)

Now we can configure PTA2 as an [`InterruptIn`](https://developer.mbed.org/handbook/InterruptIn) pin and get notified when the button gets pressed or released. Change 'source/app.cpp' to read:

```cpp
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
    
    // when we press the button the circuit closes, and turns the LED on
    button.rise(&led_on);
    // when we release the button the circuit opens again, turning the LED off
    button.fall(&led_off);
}
```

![Button and a LED on a breadboard](assets/bb03.gif)
