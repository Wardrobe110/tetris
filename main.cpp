#include <iostream>
#include "gameBoard.h"
#include "display.h"

int main() {
    srand(time(0));
    gameBoard board(1,0);
    display display(board);

    for(int i = 0; i < 3; i++){
        board.generateNextPiece();
    }
    //board.generateNextPiece();
    board.setBoardEmpty();
    //board.debugSetTile(2,5, false,RED);
    //board.debugSetTile(1,5, false,RED);
    //board.debugDisplay();
    board.spawnCurrentPiece(CYAN);
    //display.gameDisplay();
    display.runGameTest();


    /*
    board.debugSetTile(19,2, false,RED);
    board.debugSetTile(20,2, false,BLUE);
    //board.debugSetTile(1,5, false,RED);
    board.debugSetTile(1,1, false,RED);
    //board.debugSetTile(3,5, false,RED);

    for(int i = 0; i < BOARD_WIDTH; i++){
        board.debugSetTile(15,i, false, YELLOW);
    }

    for(int i = 0; i < BOARD_WIDTH; i++){
        board.debugSetTile(18,i, false, CYAN);
    }

    display.gameDisplay();
    board.rotatePiece(-90);
    display.gameDisplay();
    for(int i = 0; i < 6; i++){
        board.movePiece(0,1);
    }
    display.gameDisplay();
    board.rotatePiece(90);
    //board.holdPiece();
    /*
    std::cout<<board.movePiece(1,0);
    display.gameDisplay();
    board.movePiece(1,0);
    //board.holdPiece();
    display.gameDisplay();
     */
    //std::cout<<board.clearLines();

    //display.gameDisplay();

    /*
    std::cout<<board.movePieceLeft();
    //board.movePieceLeft();
    //board.movePieceLeft();
    board.updateLevel();
    board.updateLevel();
    board.updateLevel();
    board.updateLevel();
    board.updateLevel();
    board.updateLevelProgress();
    board.debugDisplay();
    std::cout<<board.movePieceLeft();

    std::cout<<board.movePieceLeft();
    std::cout<<board.movePieceLeft();
    std::cout<<board.movePieceLeft();
     */
    /*
    board.debugSetTile(1,1, false,CYAN);
    board.debugSetTile(2,1, false,CYAN);
    board.debugSetTile(1,9, false,CYAN);
    board.debugSetTile(1,7, false,CYAN);
    board.debugSetTile(1,3, false,CYAN);
    board.debugSetTile(1,5, false,CYAN);
    board.debugSetTile(11,6, false,YELLOW);
     */
    //board.debugDisplay();
    //display display(board);
    //display.gameDisplay();
}
