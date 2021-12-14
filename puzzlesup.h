#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#define FORWARD 1
#define BACKWARD 2
#define LEFT 3
#define RIGHT 4
#define NXN 3
#define SI 9

struct position{
    int x;
    int y;
};

struct position space={2,2};
struct position *ptr=&space;

char puzz[NXN][NXN]={{'1','2','3',},
                    {'4','5','6',},
                    {'7','8',' '}};
void printscrn();
int tomove();
void move(int dir);
int swap(int y,int x,int y2,int x2);
int suffel(struct position space);
int gamecheck();
void init();
void moverandom();