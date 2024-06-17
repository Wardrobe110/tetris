//
// Created by hubert on 6/15/24.
//

#ifndef TETRIS_STRUCTS_H
#define TETRIS_STRUCTS_H

#include <vector>

enum color{
    RED,
    WHITE,  //Typically orange
    YELLOW,
    GREEN,
    BLUE,
    VIOLET,
    CYAN
};

struct gameTile{
    bool isEmpty;
    color tileColor;

    gameTile();
};

struct position{
    unsigned short x;
    unsigned short y;

    position();
    explicit position(unsigned short y, unsigned short x);
};

struct piece {
    std::vector<position> positions;
    color pieceColor;

    piece();
    //explicit piece(position pos1, position pos2, position pos3, position pos4, enum color bro);
};


#endif //TETRIS_STRUCTS_H
