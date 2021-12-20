#include "puzzsup.h"

int siyu=0;
struct position *ptrptr1=&space;

int main(){ 
    printf("Enter your squire puzzles size: N By N :\n");
    printf("Minimum 2. Maximum is 5.\n");
    fflush(stdin);
    scanf("%d",&siyu);
    if(siyu<2 || siyu>5){
        printf("Invalid option. Press any key.");
        getchar();
        return 0;
    }
    makepuzzle();
    init();
    int j=1;
    moverandom();

    for(int i=0;j;i++){
        printscrn();
        j=tomove();
        if(gamecheck()){
            printf("\n YOU WON \n");
            break;
        }
    }
    return 0; 
}

void makepuzzle(){
    char alp='A';
    for(int i=0;i<siyu;i++){
        for(int j=0;j<siyu;j++){
            puzz[i][j]=alp++;
        }
    }
    puzz[siyu-1][siyu-1]=' ';
    ptrptr1->x=siyu-1;
    ptrptr1->y=siyu-1;
    return;
}


void moverandom(){
    for(int i=0;i<100;i++){
        int m=(rand()%(4))+1;
        move(m);
    }
    return;
}

void init(){
    srand((unsigned)time(NULL));
    return;
}

int gamecheck(){
    char ch='A';
    for(int i=0,k=1;i<siyu;i++){
        for(int j=0;j<siyu;j++){
            k++;
            if(puzz[i][j]==ch){
                ch++;
                if(k==(siyu*siyu)){
                    ch=' ';
                }
            }else{
                return 0;
            }
        }
    }
    printscrn();
    return 1;
}

void move(int dir){
    char temp=0;
    switch (dir)
    {
    case 2:
        if((ptrptr1->y)-1 <0){return;}
        temp=puzz[(ptrptr1->y)-1][ptrptr1->x];
        puzz[(ptrptr1->y)-1][ptrptr1->x]=puzz[ptrptr1->y][ptrptr1->x];
        puzz[ptrptr1->y][ptrptr1->x]=temp;
        ptrptr1->y-=1;
        break;
    case 1 :
        if((ptrptr1->y)+1 >siyu-1){return;}
        temp=puzz[ptrptr1->y+1][ptrptr1->x];
        puzz[(ptrptr1->y)+1][ptrptr1->x]=puzz[ptrptr1->y][ptrptr1->x];
        puzz[ptrptr1->y][ptrptr1->x]=temp;
        ptrptr1->y+=1;
        break;
    case 4:
        if((ptrptr1->x)-1 <0){return;}
        temp=puzz[ptrptr1->y][(ptrptr1->x)-1];
        puzz[ptrptr1->y][(ptrptr1->x)-1]=puzz[ptrptr1->y][ptrptr1->x];
        puzz[ptrptr1->y][ptrptr1->x]=temp;
        ptrptr1->x-=1;
        break;
    case 3:
        if((ptrptr1->x)+1 >siyu-1){return;}
        temp=puzz[ptrptr1->y][(ptrptr1->x)+1];
        puzz[ptrptr1->y][(ptrptr1->x)+1]=puzz[ptrptr1->y][ptrptr1->x];
        puzz[ptrptr1->y][ptrptr1->x]=temp;
        ptrptr1->x+=1;
    default:
        break;
    }
    printscrn();
    return;
}

int tomove(){
    enableRawMode();
    char ch;
    ch=readkeys();
    printf("%c",ch);
        switch (ch)
        {
        case 'A':
            move(FORWARD);
            break;
        case 'B':
            move(BACKWARD);
            break;
        case 'D':
            move(LEFT);
            break;
        case 'C':
            move(RIGHT);
            break;
        case 'q':
            return 0;
            break;
        }
    return 1;
}

void printscrn(){
    system("clear");
    printf("Press q to exit\n");
    printf("\n  *************************\n");
    for(int i=0;i<siyu;i++){
        for(int j=0;j<siyu;j++){
            printf("    %c ",puzz[i][j]);
        }
        printf("\n");
    }
    printf("\n  *************************\n");
    return;
}