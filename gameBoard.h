//
// Created by hubert on 6/15/24.
//

#ifndef TETRIS_GAMEBOARD_H
#define TETRIS_GAMEBOARD_H

#include <vector>
#include <cmath>
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
    float levelProgress;
    bool isScoringTypeFixed;

public:
    gameBoard(unsigned short level, bool scoringTypeFixed);

    //======//Debug//======//
    void debugDisplay();
    void debugSetTile(int y, int x, bool empty, enum color color);

    //======//Functions//======//
    void setBoardEmpty();
    void generateNextPiece();
    int spawnCurrentPiece(enum color pieceColor);
    void updateLevel();
    bool movePieceRight();  //1 - success; 0 - failure
    bool movePieceLeft();   //1 - success; 0 - failure
    bool movePieceDown();   //1 - success; 0 - failure
    bool holdPiece();       //1 - success; 0 - failure

    //======//Helpers//======//
    bool movePieceUp();
    bool canPlacePiece();
    void updateLevelProgress();

    //======//Getters//======//
    bool isEmpty(int y, int x);
    enum color getColor(int y, int x);
    unsigned short getLevel() const;
    unsigned short getClearedLines() const;
    unsigned int getScore() const;
    enum color getHeldColor() const;
    bool getIsHoldingPiece() const;
    std::vector<enum color> getNextPieces() const;
    float getLevelProgress() const;

};


#endif //TETRIS_GAMEBOARD_H
