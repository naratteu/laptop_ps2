// interrupt pins for known boards

// Teensy and maybe others automatically define this info
#if !defined(CORE_INT0_PIN) && !defined(CORE_INT1_PIN) && !defined(CORE_INT2_PIN)&& !defined(CORE_INT3_PIN)

// Arduino Mega
#if defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__) // Arduino Mega
  #define CORE_INT0_PIN  2
  #define CORE_INT1_PIN  3
  #define CORE_INT2_PIN  21
  #define CORE_INT3_PIN  20
  #define CORE_INT4_PIN  19
  #define CORE_INT5_PIN  18

// Arduino Due (untested)
#elif defined(__SAM3X8E__) 
  #define CORE_INT_EVERY_PIN
  #ifndef PROGMEM
  #define PROGMEM
  #endif
  #ifndef pgm_read_byte
  #define pgm_read_byte(addr) (*(const unsigned char *)(addr))
  #endif

// Arduino Leonardo (untested)
#elif defined(__AVR_ATmega32U4__) && !defined(CORE_TEENSY)
  #define CORE_INT0_PIN  3
  #define CORE_INT1_PIN  2
  #define CORE_INT2_PIN  0
  #define CORE_INT3_PIN  1

// Sanguino (untested)
#elif defined(__AVR_ATmega644P__) || defined(__AVR_ATmega644__) // Sanguino
  #define CORE_INT0_PIN  10
  #define CORE_INT1_PIN  11
  #define CORE_INT2_PIN  2

// Chipkit Uno32 (untested)
#elif defined(__PIC32MX__) && defined(_BOARD_UNO_)
  #define CORE_INT0_PIN  38
  #define CORE_INT1_PIN  2
  #define CORE_INT2_PIN  7
  #define CORE_INT3_PIN  8
  #define CORE_INT4_PIN  35

// Chipkit Mega32 (untested)
#elif defined(__PIC32MX__) && defined(_BOARD_MEGA_)
  #define CORE_INT0_PIN  3
  #define CORE_INT1_PIN  2
  #define CORE_INT2_PIN  7
  #define CORE_INT3_PIN  21
  #define CORE_INT4_PIN  20

// http://hlt.media.mit.edu/?p=1229
#elif defined(__AVR_ATtiny45__) || defined(__AVR_ATtiny85__)
  #define CORE_INT0_PIN  2

#elif defined(__AVR_ATtiny84__)
  #define CORE_INT0_PIN  8

//ESP8266 - NodeMCU 0.9 (ESP-12 Module) / NodeMCU 1.0 (ESP-12E Module)
#elif defined(ESP8266)
  #define CORE_INT_EVERY_PIN

//ESP32 support
#elif defined(ESP32)
  #define CORE_INT_EVERY_PIN

//STM32F1 support
#elif defined(__STM32F1__)
  #define CORE_INT_EVERY_PIN

// Arduino Uno, Duemilanove, LilyPad, Mini, Fio, etc...
#else
  #define CORE_INT0_PIN  2
  #define CORE_INT1_PIN  3

#endif
#endif

uint8_t get_irq_num(uint8_t irq_pin) {
#ifdef CORE_INT_EVERY_PIN
  return irq_pin;
#else
  switch (irq_pin) {
#ifdef CORE_INT0_PIN
    case CORE_INT0_PIN: return 0;
#endif
#ifdef CORE_INT1_PIN
    case CORE_INT1_PIN: return 1;
#endif
#ifdef CORE_INT2_PIN
    case CORE_INT2_PIN: return 2;
#endif
#ifdef CORE_INT3_PIN
    case CORE_INT3_PIN: return 3;
#endif
#ifdef CORE_INT4_PIN
    case CORE_INT4_PIN: return 4;
#endif
#ifdef CORE_INT5_PIN
    case CORE_INT5_PIN: return 5;
#endif
#ifdef CORE_INT6_PIN
    case CORE_INT6_PIN: return 6;
#endif
#ifdef CORE_INT7_PIN
    case CORE_INT7_PIN: return 7;
#endif
#ifdef CORE_INT8_PIN
    case CORE_INT8_PIN: return 8;
#endif
#ifdef CORE_INT9_PIN
    case CORE_INT9_PIN: return 9;
#endif
#ifdef CORE_INT10_PIN
    case CORE_INT10_PIN: return 10;
#endif
#ifdef CORE_INT11_PIN
    case CORE_INT11_PIN: return 11;
#endif
#ifdef CORE_INT12_PIN
    case CORE_INT12_PIN: return 12;
#endif
#ifdef CORE_INT13_PIN
    case CORE_INT13_PIN: return 13;
#endif
#ifdef CORE_INT14_PIN
    case CORE_INT14_PIN: return 14;
#endif
#ifdef CORE_INT15_PIN
    case CORE_INT15_PIN: return 15;
#endif
#ifdef CORE_INT16_PIN
    case CORE_INT16_PIN: return 16;
#endif
#ifdef CORE_INT17_PIN
    case CORE_INT17_PIN: return 17;
#endif
#ifdef CORE_INT18_PIN
    case CORE_INT18_PIN: return 18;
#endif
#ifdef CORE_INT19_PIN
    case CORE_INT19_PIN: return 19;
#endif
#ifdef CORE_INT20_PIN
    case CORE_INT20_PIN: return 20;
#endif
#ifdef CORE_INT21_PIN
    case CORE_INT21_PIN: return 21;
#endif
#ifdef CORE_INT22_PIN
    case CORE_INT22_PIN: return 22;
#endif
#ifdef CORE_INT23_PIN
    case CORE_INT23_PIN: return 23;
#endif
  }
#endif
  return 255;
}