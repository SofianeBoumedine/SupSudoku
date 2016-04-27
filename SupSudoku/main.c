#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "data.h"
#include "menu.h"
#include "initialization.h"

int main()
{
    system("COLOR 2E");
    HANDLE wHnd;    // Handle to write to the console.

    // Set up the handles for reading/writing:
    wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
    // Change the window title:
    SetConsoleTitle("SupSudoku");
    // Set up the required window size:
    SMALL_RECT windowSize = {0, 0, 70, 56};
    SetConsoleWindowInfo(wHnd, 1, &windowSize);
    // Change the console window size:
        // Create a COORD to hold the buffer size:
    COORD bufferSize = {10, 10};
    SetConsoleScreenBufferSize(wHnd, bufferSize);
    // Exit

    int board[9][9];
    int level=choseLvl();
    init(board, level);

    return 0;
}
