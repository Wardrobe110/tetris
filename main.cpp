#include <iostream>
#include "gameBoard.h"
#include "gameDebugDisplay.h"

int main() {
    gameBoard board(0);
    board.setBoardEmpty();
    board.debugSetTile(19,2, false,RED);
    board.debugSetTile(11,6, false,YELLOW);
    //board.debugDisplay();
    gameDebugDisplay display(board);
    display.gameDisplay();

    return 0;
}
