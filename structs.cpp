//
// Created by hubert on 6/15/24.
//

#include "structs.h"

//============//gameTile//============//

gameTile::gameTile() {
    isEmpty = true;
    tileColor = RED;
}

//============//Position//============//

position::position(unsigned short y, unsigned short x):
x(x), y(y) {

}

//============//Piece//============//

piece::piece() {
    pos1 = nullptr;
    pos2 = nullptr;
    pos3 = nullptr;
    pos4 = nullptr;
}


piece::piece(position *pos1, position *pos2, position *pos3, position *pos4, enum color color):
        pos1(pos1), pos2(pos2), pos3(pos3), pos4(pos4), pieceColor(color) {

}

