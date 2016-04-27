
#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED

struct Coordinates{
    int X, Y;
};

struct Entry{
    char pos[2];
    struct Coordinates position;
    int number;
};

struct Numbers{
    int num[9];
};

struct GameBoard{
    int gameBoard[9][9];
};
#endif // DATA_H_INCLUDED
