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


constexpr unsigned short BOARD_HEIGHT = 21;
constexpr unsigned short BOARD_WIDTH = 10;
const unsigned short PIECE_SEGMENTS = 4;

class gameBoard {
    gameTile board[BOARD_HEIGHT][BOARD_WIDTH];
    piece currentPiece;
    bool isHoldingPiece;
    enum color heldPiece;
    std::vector<enum color> nextPieces;
    unsigned short level;
    unsigned short clearedLines;
    unsigned int score;
    float levelProgress;
    bool isScoringTypeFixed;
    bool heldPieceThisTurn;

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
    void updateLevelProgress();
    int movePiece(short dy, short dx);
    int holdPiece();
    int clearLines();
    int rotatePiece(int degrees);

    //======//Helpers//======//
    bool movePieceUp();
    bool canPlacePiece();
    unsigned short sumUpTo(unsigned  short x);
    std::vector<unsigned short > findCompleteLines();
    bool isTileViable(int y, int x);

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
