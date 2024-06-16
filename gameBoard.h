//
// Created by hubert on 6/15/24.
//

#ifndef TETRIS_GAMEBOARD_H
#define TETRIS_GAMEBOARD_H
#include "structs.h"
#include "iostream"
#include "iomanip"


class gameBoard {
    gameTile board[21][10];
    piece currentPiece;
    piece heldPiece;
    unsigned short level;
    int score;

public:
    gameBoard(unsigned short level);

    //======//Debug//======//
    void debugDisplay();
    void debugSetTile(int y, int x, bool empty, enum color color);

    //======//Functions//======//
    void setBoardEmpty();

    //======//Getters//======//
    inline bool isEmpty(int y, int x);
    inline enum color getColor(int y, int x);
};


#endif //TETRIS_GAMEBOARD_H
