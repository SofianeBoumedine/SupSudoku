#ifndef INITIALIZATION_H_INCLUDED
#define INITIALIZATION_H_INCLUDED

void init(int board[9][9], int level);
int canBePlaced(int board[9][9], int X, int Y, int number);
void shuffle(int board[9][9]);
int solveBoard(int board[9][9], int X, int Y);
#endif // INITIALIZATION_H_INCLUDED
