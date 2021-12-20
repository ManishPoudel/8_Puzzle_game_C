#include "puzzsup.h"

struct termios orig_termios;

void disableRawMode() {
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

void enableRawMode() {
  tcgetattr(STDIN_FILENO, &orig_termios);
  //atexit(disableRawMode);

  struct termios raw = orig_termios;
  raw.c_lflag &= ~(ECHO | ICANON);

  tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

char readkeys(){
  char c;
  while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q') {
    if (1) {
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
    }else{
      return 'c';
    }
  } else {
    return c;
  }
  }
}


/* int initialize() {
  enableRawMode();

    /* switch (c)
    {
    case 'w':
      printf("entered w\n");
      break;
    case 's':
      printf("entered s\n");
    break;
    default:
      break;
    } 
    */

//   return 0;
// } */