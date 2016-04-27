#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "data.h"
#include "menu.h"
#include "initialization.h"
#include "display.h"



struct GameBoard setGameBoard(int board[9][9], int lvl){
    struct GameBoard gameBoard;
    int i, j;
    for (i = 0; i <= 8; i++) {
        for(j = 0; j <= 8; j++){
            gameBoard.gameBoard[i][j] = board[i][j];
        }
    }
    int hideNumber = rand() % 2;
    int hideCounter = 0;
    int lvlRange[3] = {31,35,49};
    while(hideCounter <= lvlRange[lvl-1]){
        for (i = 0; i <= 8; i++) {
            for(j = 0; j <= 8; j++){
                hideNumber = rand() % 2;
                if(hideCounter <= lvlRange[lvl-1] && hideNumber == 1){
                    if(gameBoard.gameBoard[i][j] != 0){
                        gameBoard.gameBoard[i][j] = 0;
                        hideCounter++;
                    }
                }
            }
        }
    }
    return gameBoard;
}

int checkWin(int board[9][9], struct GameBoard gameBoard){
    int win = 1;
    int i, j;
    for (i = 0; i <= 8; i++) {
        for(j = 0; j <= 8; j++){
            if(gameBoard.gameBoard[i][j] != board[i][j]){
                win = 0;
                break; break;
            }
        }
    }
    return win;
}

void game(int board[9][9], int lvl){
    struct GameBoard gameBoard;
    gameBoard = setGameBoard(board, lvl);
    display(gameBoard.gameBoard);
    struct Entry entry;

    nextTurn:
    entry = placeNumber();



    int X = 0;
    int Y = 0;
    if(entry.pos[0] == 'a' || entry.pos[0] == 'A'){
        X = entry.pos[1] - '0'; Y = 0;
    }
    if(entry.pos[0] == 'b' || entry.pos[0] == 'B'){
        X = entry.pos[1] - '0'; Y = 1;
    }
    if(entry.pos[0] == 'c' || entry.pos[0] == 'C'){
        X = entry.pos[1] - '0'; Y = 2;
    }
    if(entry.pos[0] == 'd' || entry.pos[0] == 'D'){
        X = entry.pos[1] - '0'; Y = 3;
    }
    if(entry.pos[0] == 'e' || entry.pos[0] == 'E'){
        X = entry.pos[1] - '0'; Y = 4;
    }
    if(entry.pos[0] == 'f' || entry.pos[0] == 'F'){
        X = entry.pos[1] - '0'; Y = 5;
    }
    if(entry.pos[0] == 'g' || entry.pos[0] == 'G'){
        X = entry.pos[1] - '0'; Y = 6;
    }
    if(entry.pos[0] == 'h' || entry.pos[0] == 'H'){
        X = entry.pos[1] - '0'; Y = 7;
    }
    if(entry.pos[0] == 'i' || entry.pos[0] == 'I'){
        X = entry.pos[1] - '0'; Y = 8;
    }
    X--;
    if(gameBoard.gameBoard[X][Y] == 0){
        entry.position.X = X;
        entry.position.Y = Y;
        gameBoard.gameBoard[entry.position.X][entry.position.Y] = entry.number;
        if(checkWin(board, gameBoard) != 1){
            display(gameBoard.gameBoard);
            goto nextTurn;
        }else{
            printf("Bravo, You Won The Game!!!");
        }
    }else{
        display(gameBoard.gameBoard);
        goto nextTurn;
    }
}
