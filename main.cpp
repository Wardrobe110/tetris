#include <iostream>
#include "gameBoard.h"
#include "display.h"

int main() {
    srand(time(0));
    gameBoard board(10,1);
    for(int i = 0; i < 3; i++){
        board.generateNextPiece();
    }
    //board.generateNextPiece();
    board.setBoardEmpty();
    //board.debugSetTile(2,5, false,RED);
    //board.debugSetTile(1,5, false,RED);
    board.debugDisplay();
    std::cout<<board.spawnCurrentPiece(VIOLET);
    board.debugSetTile(19,2, false,RED);
    board.debugSetTile(20,2, false,BLUE);
    board.debugSetTile(1,7, false,RED);
    board.debugDisplay();
    board.movePieceRight();
    //board.movePieceLeft();
    //board.movePieceLeft();

    board.debugDisplay();
    board.movePieceRight();
    /*
    board.debugSetTile(1,1, false,CYAN);
    board.debugSetTile(2,1, false,CYAN);
    board.debugSetTile(1,9, false,CYAN);
    board.debugSetTile(1,7, false,CYAN);
    board.debugSetTile(1,3, false,CYAN);
    board.debugSetTile(1,5, false,CYAN);
    board.debugSetTile(11,6, false,YELLOW);
     */
    board.debugDisplay();
    //display display(board);
    //display.gameDisplay();
    return 0;
}
