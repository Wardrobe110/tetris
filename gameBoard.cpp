//
// Created by hubert on 6/15/24.
//

#include "gameBoard.h"

gameBoard::gameBoard(unsigned short level): level(level) {

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


//============//Getters//============//
bool gameBoard::isEmpty(int y, int x) {
    return board[y][x].isEmpty;
}

enum color gameBoard::getColor(int y, int x) {
    return board[y][x].tileColor;
}
