#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "data.h"
#include "menu.h"




void showBoard(int board[9][9]){
    printf("\n   A B C|D E F|G H I");
    printf("\n  +-----+-----+-----+\n");
    int i, j;
    for(i=1; i<10; ++i){
        printf("%d |", i);
        for(j=1; j<10; ++j){
            if(j!=1){
                printf("|");
            }
            if(board[i-1][j-1] != 0){
                printf("%d", board[i-1][j-1]);
            }else{
                printf(".");
            }
        }
        printf("|\n");
        if (i%3 == 0){
            printf("  +-----+-----+-----+\n");
        }
    }
}

void display(int board[9][9]){
    showBoard(board);
}
