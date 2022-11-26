#include<stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include<time.h>

#define FORWARD 1   //With reference to character.
#define BACKWARD 2  //Not with respect to space.
#define LEFT 3
#define RIGHT 4
#define MAX 5



struct position{
    int x;
    int y;
};

static struct position space;
static char board[MAX][MAX];

// For taking input from keyboard.
void disableRawMode();
void enableRawMode();
char readkeys();

void suffelBoard();
void setBoard();
void printScrn();
int toMove();
void move(int dir);
int swap(int y, int x, int y2, int x2);
int suffel(struct position space);
int gameCheck();
void initRandom();
void moveRandom();
void makePuzzle();
