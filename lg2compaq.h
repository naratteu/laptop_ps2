#define KEY_MENU 0xED
char remap(uint8_t incoming, bool ex) {
  const uint16_t EX = 0xFF00;
  switch (incoming | (ex ? EX : 0)) {
    default: return ' ';
    case 21: return 'c';
    case 29: return 't';
    case 45: return ',';
    case 60: return 'y';
    case 67: return KEY_RETURN;
    case 121: return 'x';
    case 125: return 'z';
    case 117: return '.';
    case 108: return '\\';
    case 13: return KEY_ESC;
    case 88: return 'b';
    case 102: return '-';
    case 44: return KEY_END;
    case 53: return 'n';
    case 91: return KEY_F12;
    case 131: return KEY_INSERT;
    case 109: return KEY_CAPS_LOCK;
    case 116: return '`';
    case 107: return KEY_RIGHT_ARROW;
    case 28: return 'd';
    case 27: return '4';
    case 93: return ';';
    case 43: return 'k';
    case 59: return '7';
    case 66: return '[';
    case 75: return KEY_F6;
    case 90 | EX: return 's';
    case 122: return 'a';
    case 114: return 'l';
    case 105: return '=';
    case 118: return 'e';
    case 97: return 'r';
    case 120: return 'p';
    case 52: return 'i';
    case 51: return 'u';
    case 11: return KEY_MENU;
    case 117 | EX: return 'w';
    case 113: return 'q';
    case 112: return 'o';
    case 41: return KEY_DELETE;
    case 26: return KEY_F1;
    case 34: return 'g';
    case 90: return ']';
    case 42: return KEY_PAGE_DOWN;
    case 58: return 'h';
    case 65: return KEY_BACKSPACE;
    case 73: return KEY_DOWN_ARROW;
    case 124: return KEY_F3;
    case 74 | EX: return KEY_LEFT_GUI;
    case 119: return KEY_LEFT_ARROW;
    case 103: return '3';
    case 100: return 'f';
    case 7: return '0';
    case 50: return '8';
    case 49: return 'j';
    case 81: return KEY_F10;
    case 47 | EX: return KEY_HOME;
    case 107 | EX: return '2';
    case 123: return '1';
    case 116 | EX: return '9';
    case 114 | EX: return KEY_F9;
    case 14: return KEY_TAB;
    case 5: return 'v';
    case 1: return KEY_F8;
    case 46: return KEY_F7;
    case 54: return 'm';
    case 85: return KEY_F11;
    case 10: return ' ';
    case 108 | EX: return KEY_F4;
    case 125 | EX: return KEY_F2;
    case 113 | EX: return KEY_PAGE_UP;
    case 22: return KEY_F5;
    case 30: return '5';
    case 9: return '/';
    case 37: return '\'';
    case 61: return '6';
    case 62: return KEY_UP_ARROW;
  }
}
void on(uint8_t incoming) {
  static bool ex = false, up = false;
  switch (incoming) {
    case 224: ex = true; return;
    case 240: up = true; return;
  }
  if (up) Keyboard.release(remap(incoming, ex));
  else Keyboard.press(remap(incoming, ex));
  ex = up = false;
}