#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "data.h"
#include "menu.h"
#include "display.h"
#include "game.h"

int canBePlaced(int board[9][9], int X, int Y, int number){
    int XStart = (X/3) * 3;
    int YStart = (Y/3) * 3;
    int i;
    for(i=0; i<9; ++i){
        if(board[X][i] == number){
            return 0;
        }
        if(board[i][Y] == number){
            return 0;
        }
        if(board[XStart + (i%3)][YStart + (i/3)] == number){
            return 0;
        }
    }
    return 1;
}

int solveBoard(int board[9][9], int X, int Y){
    int i;
    if(X<9 && Y<9){
        if(board[X][Y] != 0){
            if(Y+1<9){
                return solveBoard(board, X, Y+1);
            }else if(X+1<9){
                return solveBoard(board, X+1, 0);
            }else{
                return 1;
            }
        }else{
            for(i=0; i<9; ++i){
                if(canBePlaced(board, X, Y, i+1)){
                    board[X][Y] = i+1;
                    if(Y+1<9){
                        if(solveBoard(board, X, Y +1)){
                            return 1;
                        }else{
                            board[X][Y] = 0;
                        }
                    }else if(X+1<9){
                        if(solveBoard(board, X+1, 0)){
                            return 1;
                        }else{
                            board[X][Y] = 0;
                        }
                    }else{
                        return 1;
                    }
                }
            }
        }
        return 0;
        }else{
            return 1;
        }
}

void swap(int *a, int *b){
        int temp = *a;
        *a = *b;
        *b = temp;
}
void shuffle(int board[9][9]){
    struct Numbers numbers = {{1, 2, 3, 4, 5, 6, 7, 8, 9}};
    time_t timer;
    srand (time(&timer));
    int i,j;
    for (i = 8; i > 0; i--){
        int j = rand() % (i+1);
        swap(&numbers.num[i], &numbers.num[j]);
    }

    for(j=0; j <= 8; j++){
        board[0][j] = numbers.num[j];
    }
    for(i=1; i <= 8; i++){
        for(j=0; j <= 8; j++){
            board[i][j]=0;
        }
    }
}

void init(int board[9][9], int level){
    shuffle(board);
    solveBoard(board, 0, 0);
    //display(board);
    game(board, level);
}
