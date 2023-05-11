#include "Keyboard.h"
#include "int_pins.h"
#include "lg2compaq.h"

const uint8_t DataPin = 3, irq_pin = 2;

// The ISR for the external interrupt
void ps2interrupt() {
  static uint8_t bitcount = 0, incoming = 0;
  static uint32_t prev_ms = 0;

  uint8_t val = digitalRead(DataPin);
  uint32_t now_ms = millis();
  if (now_ms - prev_ms > 250)
    bitcount = incoming = 0;
  prev_ms = now_ms;
  uint8_t n = bitcount - 1;
  if (n < 8)
    incoming |= (val << n);
  if (++bitcount == 11) {
    on(incoming);
    bitcount = incoming = 0;
  }
}

void setup() {
  Keyboard.begin();
  // initialize the pins
  pinMode(irq_pin, INPUT_PULLUP);
  pinMode(DataPin, INPUT_PULLUP);
  auto irq_num = get_irq_num(irq_pin);
  if (irq_num < 255) {
    attachInterrupt(irq_num, ps2interrupt, FALLING);
  }
}
void loop() {
}