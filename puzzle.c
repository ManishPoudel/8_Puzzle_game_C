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

int main(){ 
    init();
    int j=1;
    moverandom();

    for(int i=0;j;i++){
        printscrn();
        j=tomove();
        if(gamecheck()){
            printf("\n You Won ");
            break;
        }
    }
    getch();
    getch();
    return 0; 
}

void moverandom(){
    for(int i=0;i<(60);i++){
        int m=(rand()%4)+1;
        move(m);
    }
    return;
}

void init(){
    srand((unsigned)time(NULL));
    return;
}

int gamecheck(){
    char ch='1';
    for(int i=0;i<NXN && ch<'9';i++){
        for(int j=0;j<NXN && ch<'9';j++){
            if(puzz[i][j]==ch){
                ch++;
            }else{
                return 0;
            }
        }
    }
    return 1;
}

void move(int dir){
    char temp=0;
    switch (dir)
    {
    case 2/* constant-expression */:
        /* code */
        if((ptr->y)-1 <0){return;}
        temp=puzz[(ptr->y)-1][ptr->x];
        puzz[(ptr->y)-1][ptr->x]=puzz[ptr->y][ptr->x];
        puzz[ptr->y][ptr->x]=temp;
        ptr->y-=1;
        break;
    case 1 :
        if((ptr->y)+1 >2){return;}
        temp=puzz[ptr->y+1][ptr->x];
        puzz[(ptr->y)+1][ptr->x]=puzz[ptr->y][ptr->x];
        puzz[ptr->y][ptr->x]=temp;
        ptr->y+=1;
        break;
    case 4:
        if((ptr->x)-1 <0){return;}
        temp=puzz[ptr->y][(ptr->x)-1];
        puzz[ptr->y][(ptr->x)-1]=puzz[ptr->y][ptr->x];
        puzz[ptr->y][ptr->x]=temp;
        ptr->x-=1;
        break;
    case 3:
        if((ptr->x)+1 >2){return;}
        temp=puzz[ptr->y][(ptr->x)+1];
        puzz[ptr->y][(ptr->x)+1]=puzz[ptr->y][ptr->x];
        puzz[ptr->y][ptr->x]=temp;
        ptr->x+=1;
    default:
        break;
    }
    return;
}

int tomove(){
    char ch;
    ch=_getch();
    if(kbhit()){
        switch (_getch())
        {
        case 72/* constant-expression */:
            move(FORWARD);
            break;
        case 80:
            move(BACKWARD);
            break;
        case 75:
            move(LEFT);
            break;
        case 77:
            move(RIGHT);
            break;
        default:
            return 0;
            break;
        }
    }else{
        return 0;
    }
    printscrn();
    return 1;
}

void printscrn(){
    system("cls");
    printf("\n  ****************\n");
    for(int i=0;i<NXN;i++){
        for(int j=0;j<NXN;j++){
            printf("    %c ",puzz[i][j]);
        }
        printf("\n");
    }
    printf("\n  ****************\n");
}