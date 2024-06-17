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
    bool isHoldingPiece;
    enum color heldPiece;
    std::vector<enum color> nextPieces;
    unsigned short level;
    unsigned short clearedLines;
    unsigned int score;

public:
    gameBoard(unsigned short level);

    //======//Debug//======//
    void debugDisplay();
    void debugSetTile(int y, int x, bool empty, enum color color);

    //======//Functions//======//
    void setBoardEmpty();
    void generateNextPiece();
    int spawnCurrentPiece(enum color pieceColor);

    //======//Getters//======//
    bool isEmpty(int y, int x);
    enum color getColor(int y, int x);
    unsigned short getLevel() const;
    unsigned short getClearedLines() const;
    unsigned int getScore() const;
    enum color getHeldColor() const;
    bool getIsHoldingPiece() const;
    std::vector<enum color> getNextPieces() const;

};


#endif //TETRIS_GAMEBOARD_H
