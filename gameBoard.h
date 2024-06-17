//
// Created by hubert on 6/15/24.
//

#ifndef TETRIS_GAMEBOARD_H
#define TETRIS_GAMEBOARD_H

#include <vector>
#include "structs.h"
#include "iostream"
#include "iomanip"
#include "ftxui/screen/color.hpp"


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
    bool isEmpty(int y, int x);
    enum color getColor(int y, int x);
};


#endif //TETRIS_GAMEBOARD_H
