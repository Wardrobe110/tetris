//
// Created by hubert on 6/15/24.
//

#include "gameBoard.h"

gameBoard::gameBoard(unsigned short level): level(level) {
    score = 0;
    clearedLines = 0;
    nextPieces.resize(3);
    isHoldingPiece = false;
}

//============//Debug//============//

void gameBoard::debugDisplay() {
    std::cout<<"     ";
    for(int i = 0; i < 10; i++){
        std::cout<<" "<<i<<"  ";
    }
    std::cout<<std::endl;
    for(int i = 0; i < 21; i++){
        std::cout<<std::setw(2)<<i<<"  |";
        for(int j = 0; j < 10; j++){
            //Could probably make it into separate function
            if(isEmpty(i,j)){
                std::cout<<"   ";
            }else{
                std::cout<<"[";
                switch (getColor(i,j)) {
                    case RED:
                        std::cout<<"R";
                        break;
                    case WHITE:
                        std::cout<<"W";
                        break;
                    case YELLOW:
                        std::cout<<"Y";
                        break;
                    case GREEN:
                        std::cout<<"G";
                        break;
                    case BLUE:
                        std::cout<<"B";
                        break;
                    case VIOLET:
                        std::cout<<"V";
                        break;
                    case CYAN:
                        std::cout<<"C";
                        break;
                }
                std::cout<<"]";
            }
            std::cout<<"|";
        }
        std::cout<<std::endl;
    }
}

void gameBoard::debugSetTile(int y, int x, bool empty, enum color color) {
    board[y][x].isEmpty = empty;
    board[y][x].tileColor = color;
}

//============//Functions//============//
void gameBoard::setBoardEmpty() {
    for(int i = 0; i < 21; i++){
        for(int j = 0; j < 10; j++) {
            board[i][j].isEmpty = true;
        }
    }
}

void gameBoard::generateNextPiece() {
    nextPieces[0] = nextPieces [1];
    nextPieces[1] = nextPieces [2];
    switch (rand()%7) {
        case 0:
            nextPieces[2] = RED;
            break;
        case 1:
            nextPieces[2] = WHITE;
            break;
        case 2:
            nextPieces[2] = YELLOW;
            break;
        case 3:
            nextPieces[2] = GREEN;
            break;
        case 4:
            nextPieces[2] = CYAN;
            break;
        case 5:
            nextPieces[2] = BLUE;
            break;
        case 6:
            nextPieces[2] = VIOLET;
            break;
    }
}

int gameBoard::spawnCurrentPiece(enum color pieceColor) {
    switch(pieceColor){
        case RED:
            nextPieces[2] = RED;
            break;
        case WHITE:
            nextPieces[2] = WHITE;
            break;
        case YELLOW:
            currentPiece.positions[0] = position(1,4);
            currentPiece.positions[1] = position(1,5);
            currentPiece.positions[2] = position(2,4);
            currentPiece.positions[3] = position(2,5);
            break;
        case GREEN:
            nextPieces[2] = GREEN;
            break;
        case CYAN:
            nextPieces[2] = CYAN;
            break;
        case BLUE:
            nextPieces[2] = BLUE;
            break;
        case VIOLET:
            nextPieces[2] = VIOLET;
            break;
    }



    //All good
    for(int i = 0; i < 4; i++){
        board[currentPiece.positions[i].y][currentPiece.positions[i].x].tileColor = pieceColor;
        board[currentPiece.positions[i].y][currentPiece.positions[i].x].isEmpty = false;
    }
    return 0;
}


//============//Getters//============//
bool gameBoard::isEmpty(int y, int x) {
    return board[y][x].isEmpty;
}

enum color gameBoard::getColor(int y, int x) {
    return board[y][x].tileColor;
}

unsigned short gameBoard::getLevel() const {
    return level;
}

unsigned short gameBoard::getClearedLines() const {
    return clearedLines;
}

unsigned int gameBoard::getScore() const {
    return score;
}

enum color gameBoard::getHeldColor() const {
    return heldPiece;
}

bool gameBoard::getIsHoldingPiece() const {
    return isHoldingPiece;
}

std::vector<enum color> gameBoard::getNextPieces() const {
    return nextPieces;
}





