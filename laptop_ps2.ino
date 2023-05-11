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

struct btn {
  uint8_t pin;
  char key;
  btn(uint8_t p, char k) {
    pin = p;
    key = k;
  }
  void setup() {
    pinMode(pin, INPUT_PULLUP);
  }
  uint16_t buf = 0;
  bool up = false;
  void loop() {
    buf = (buf << 1) | (digitalRead(pin) == LOW ? 1 : 0);
    switch ((buf << 1) | up) {
      case 0b11111111111111110:
        Keyboard.press(key);
        up = true;
        return;
      case 0b00000000000000001:
        Keyboard.release(key);
        up = false;
        return;
    }
  }
};
#define cnt 6
btn btns[cnt] = {
  { 13, KEY_LEFT_CTRL },
  { 12, KEY_LEFT_SHIFT },
  //{11, Fn},
  { 10, KEY_LEFT_ALT },
  { 9, KEY_RIGHT_CTRL },
  { 8, KEY_RIGHT_ALT },
  { 7, KEY_RIGHT_SHIFT },
};

int i;
void setup() {
  Keyboard.begin();
  // initialize the pins
  pinMode(irq_pin, INPUT_PULLUP);
  pinMode(DataPin, INPUT_PULLUP);
  auto irq_num = get_irq_num(irq_pin);
  if (irq_num < 255)
    attachInterrupt(irq_num, ps2interrupt, FALLING);
  for (i = 0; i < cnt; i++) btns[i].setup();
}
void loop() {
  delay(1);
  for (i = 0; i < cnt; i++) btns[i].loop();
}