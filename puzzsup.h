#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#define FORWARD 1   //With reference to character.
#define BACKWARD 2  //Not with respect to space.
#define LEFT 3
#define RIGHT 4
#define MAX 5

int sizes=0;

struct position{
    int x;
    int y;
};

struct position space;
struct position *ptr=&space;
char puzz[MAX][MAX];

void printscrn();
int tomove();
void move(int dir);
int swap(int y,int x,int y2,int x2);
int suffel(struct position space);
int gamecheck();
void init();
void moverandom();
void makepuzzle();