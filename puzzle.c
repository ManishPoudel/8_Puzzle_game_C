#include "puzzsup.h"

int boardSize = 0;
struct position *ptrS = &space; //Pointer to space in board.


int main(){
	setBoard();		// Make the board ready.
	
	suffelBoard();	//Suffel the ready made board randomly.

    int j = 1,i;
    for(i=0;j;i++){
        printScrn();
        j = toMove();
        if(gameCheck()){
            printf("\n PUZZLE SOLVED! \n");
            break;
        }
    }
    return 0;
}

void suffelBoard(){
    initRandom();
    moveRandom();
	return;
}
void setBoard(){
    printf("Enter your squire puzzles size: N By N :\n");
    printf("Minimum 2. Maximum is 5.\n");
    fflush(stdin);
    scanf("%d", &boardSize);
    if(boardSize < 2 || boardSize > 5){
        printf("Invalid option. Press any key.");
        getchar();
        return ;
	}
    makePuzzle();	// Make the puzzle board.
	return;
}

void makePuzzle(){
    char alp = 'A';
    for(int i = 0;i < boardSize;i++){
        for(int j = 0;j < boardSize;j++){
            board[i][j] = alp++;
        }
    }
    board[boardSize - 1][boardSize - 1] = ' ';
    ptrS->x = boardSize - 1;
    ptrS->y = boardSize - 1;
    return;
}


void moveRandom(){
    for(int i = 0;i < 100;i++){
        int m = (rand() % (4)) + 1;
        move(m);
    }
    return;
}

void initRandom(){
    srand((unsigned)time(NULL));
    return;
}

int gameCheck(){
    char ch = 'A';
    for(int i = 0, k = 1;i < boardSize;i++){
        for(int j = 0;j < boardSize;j++){
            k++;
            if(board[i][j] == ch){
                ch++;
                if(k == (boardSize * boardSize)){
                    ch = ' ';
                }
            } else{
                return 0;
            }
        }
    }
    printScrn();
    return 1;
}

void move(int dir){
    char temp = 0;
    switch(dir){
    case 2:
        if((ptrS->y) - 1 < 0){ return; }
        temp = board[(ptrS->y) - 1][ptrS->x];
        board[(ptrS->y) - 1][ptrS->x] = board[ptrS->y][ptrS->x];
        board[ptrS->y][ptrS->x] = temp;
        ptrS->y -= 1;
        break;
    case 1:
        if((ptrS->y) + 1 > boardSize - 1){ return; }
        temp = board[ptrS->y + 1][ptrS->x];
        board[(ptrS->y) + 1][ptrS->x] = board[ptrS->y][ptrS->x];
        board[ptrS->y][ptrS->x] = temp;
        ptrS->y += 1;
        break;
    case 4:
        if((ptrS->x) - 1 < 0){ return; }
        temp = board[ptrS->y][(ptrS->x) - 1];
        board[ptrS->y][(ptrS->x) - 1] = board[ptrS->y][ptrS->x];
        board[ptrS->y][ptrS->x] = temp;
        ptrS->x -= 1;
        break;
    case 3:
        if((ptrS->x) + 1 > boardSize - 1){ return; }
        temp = board[ptrS->y][(ptrS->x) + 1];
        board[ptrS->y][(ptrS->x) + 1] = board[ptrS->y][ptrS->x];
        board[ptrS->y][ptrS->x] = temp;
        ptrS->x += 1;
    default:
        break;
    }
    printScrn();
    return;
}

int toMove(){
    enableRawMode();
    char ch;
    ch = readkeys();
    switch(ch){
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

void printScrn(){
    system("clear");
    printf("Press q to exit\n");
    printf("\n  *************************\n");
    for(int i = 0;i < boardSize;i++){
        for(int j = 0;j < boardSize;j++){
            printf("    %c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n  *************************\n");
    return;
}
