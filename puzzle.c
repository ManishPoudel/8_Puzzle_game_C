#include "puzzsup.h"

int main(){ 
    printf("Enter your squire puzzles size: N By N :\n");
    printf("Minimum 2. Maximum is 5.\n");
    fflush(stdin);
    scanf("%d",&sizes);
    if(sizes<2 || sizes>5){
        printf("Invalid option. Press any key.");
        getch();
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
            printf("Enter any key twice to exit.");
            break;
        }
    }
    getch();
    getch();
    getch();
    return 0; 
}

void makepuzzle(){
    char alp='A';
    for(int i=0;i<sizes;i++){
        for(int j=0;j<sizes;j++){
            puzz[i][j]=alp++;
        }
    }
    puzz[sizes-1][sizes-1]=' ';
    ptr->x=sizes-1;
    ptr->y=sizes-1;
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
    for(int i=0,k=1;i<sizes;i++){
        for(int j=0;j<sizes;j++){
            k++;
            if(puzz[i][j]==ch){
                ch++;
                if(k==(sizes*sizes)){
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
        if((ptr->y)-1 <0){return;}
        temp=puzz[(ptr->y)-1][ptr->x];
        puzz[(ptr->y)-1][ptr->x]=puzz[ptr->y][ptr->x];
        puzz[ptr->y][ptr->x]=temp;
        ptr->y-=1;
        break;
    case 1 :
        if((ptr->y)+1 >sizes-1){return;}
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
        if((ptr->x)+1 >sizes-1){return;}
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
        case 72:
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
    return 1;
}

void printscrn(){
    system("cls");
    printf("\n  *************************\n");
    for(int i=0;i<sizes;i++){
        for(int j=0;j<sizes;j++){
            printf("    %c ",puzz[i][j]);
        }
        printf("\n");
    }
    printf("\n  *************************\n");
    return;
}