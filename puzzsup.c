#include "puzzsup.h"

struct termios orig_termios;

void disableRawMode() {
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

void enableRawMode() {
  // atexit(disableRawMode);
  tcgetattr(STDIN_FILENO, &orig_termios);
  atexit(disableRawMode);

  struct termios raw = orig_termios;
  raw.c_lflag &= ~(ICANON);

  tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

char readkeys(){
  char c;
  while (read(STDIN_FILENO, &c, 1) == 1) {
    char seq[3];
    read(STDIN_FILENO, &seq[0], 1);
    read(STDIN_FILENO, &seq[1], 1);
    if (seq[0] == '[') {
      switch (seq[1]) {
        case 'A': return 'A';
        case 'B': return 'B';
        case 'C': return 'C';
        case 'D': return 'D';
      }
  } else {
    return c;
  }
  }
}
