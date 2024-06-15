#include <iostream>
#include "gameBoard.h"

int main() {
    gameBoard board(0);
    board.setBoardEmpty();
    board.debugSetTile(19,2, false,RED);
    board.debugSetTile(11,6, false,YELLOW);
    board.debugDisplay();
    return 0;
}
