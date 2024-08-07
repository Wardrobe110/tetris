//
// Created by hubert on 6/15/24.
//


#include "gameBoard.h"

gameBoard::gameBoard(bool scoringTypeFixed):isScoringTypeFixed(scoringTypeFixed) {
    score = 0;
    clearedLines = 0;
    //nextPieces.resize(7);
    isHoldingPiece = false;
    levelProgress = 0;
    heldPieceThisTurn = false;
}

//============//Debug//============//

void gameBoard::debugDisplay() {
    std::cout<<"     ";
    for(int i = 0; i < BOARD_WIDTH; i++){
        std::cout<<" "<<i<<"  ";
    }
    std::cout<<std::endl;
    for(int i = 0; i < BOARD_HEIGHT; i++){
        std::cout<<std::setw(2)<<i<<"  |";
        for(int j = 0; j < BOARD_WIDTH; j++){
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
void gameBoard::resetBoard(unsigned short lvl) {
    for(int i = 0; i < BOARD_HEIGHT; i++){
        for(int j = 0; j < BOARD_WIDTH; j++) {
            board[i][j].isEmpty = true;
        }
    }

    level = lvl;
    score = 0;
    isHoldingPiece = false;
    levelProgress = 0;
    heldPieceThisTurn = false;
    nextPieces = generateColorVector();
    spawnCurrentPiece(nextPieces[0]);
    generateNextPiece();
}

void gameBoard::generateNextPiece() {
    if(nextPieces.size() < 8){
        std::vector<enum color> moreColors;
        moreColors = generateColorVector();
        nextPieces.insert(nextPieces.end(), moreColors.begin(), moreColors.end());
    }

    nextPieces.erase(nextPieces.begin());
}

int gameBoard::spawnCurrentPiece(enum color pieceColor) {

    currentPiece.pieceColor = pieceColor;
    switch(pieceColor){
        case RED:
            currentPiece.positions[0] = position(1,3);
            currentPiece.positions[1] = position(2,4);
            currentPiece.positions[2] = position(2,5);
            currentPiece.positions[3] = position(1,4);
            currentPiece.originX = 4.0;
            currentPiece.originY = 2.0;
            break;
        case WHITE:
            currentPiece.positions[0] = position(2,3);
            currentPiece.positions[1] = position(2,4);
            currentPiece.positions[2] = position(2,5);
            currentPiece.positions[3] = position(1,5);
            currentPiece.originX = 4.0;
            currentPiece.originY = 2.0;
            break;
        case YELLOW:
            currentPiece.positions[0] = position(1,4);
            currentPiece.positions[1] = position(1,5);
            currentPiece.positions[2] = position(2,4);
            currentPiece.positions[3] = position(2,5);
            currentPiece.originX = 4.5;
            currentPiece.originY = 1.5;
            break;
        case GREEN:
            currentPiece.positions[0] = position(2,3);
            currentPiece.positions[1] = position(2,4);
            currentPiece.positions[2] = position(1,5);
            currentPiece.positions[3] = position(1,4);
            currentPiece.originX = 4.0;
            currentPiece.originY = 2.0;
            break;
        case CYAN:
            currentPiece.positions[0] = position(2,3);
            currentPiece.positions[1] = position(2,4);
            currentPiece.positions[2] = position(2,5);
            currentPiece.positions[3] = position(2,6);
            currentPiece.originX = 4.5;
            currentPiece.originY = 2.5;
            break;
        case BLUE:
            currentPiece.positions[0] = position(2,3);
            currentPiece.positions[1] = position(2,4);
            currentPiece.positions[2] = position(2,5);
            currentPiece.positions[3] = position(1,3);
            currentPiece.originX = 4.0;
            currentPiece.originY = 2.0;
            break;
        case VIOLET:
            currentPiece.positions[0] = position(2,3);
            currentPiece.positions[1] = position(2,4);
            currentPiece.positions[2] = position(2,5);
            currentPiece.positions[3] = position(1,4);
            currentPiece.originX = 4.0;
            currentPiece.originY = 2.0;
            break;
    }

    //Check if you can spawn it
    while(canPlacePiece() == false){
        if(movePieceUp() == false) {
            return -1;
        }
    }

    //All good
    for(int i = 0; i < PIECE_SEGMENTS; i++){
        board[currentPiece.positions[i].y][currentPiece.positions[i].x].tileColor = pieceColor;
        board[currentPiece.positions[i].y][currentPiece.positions[i].x].isEmpty = false;
    }
    heldPieceThisTurn = false;
    return 0;
}

void gameBoard::updateLevel() {
    if(isScoringTypeFixed){
        //TODO FIX IT
        if(clearedLines%10 == 0) level++;
        //levelProgress = (clearedLines%10)/10;
    }else{
        if(clearedLines - 5*(sumUpTo(level - 1))>= 5 * level and clearedLines <= 600) level++;
        //levelProgress = clearedLines - 5*(sumUpTo(level - 1))/5 * level;
    }
}

void gameBoard::updateLevelProgress() {
    if(isScoringTypeFixed){
        levelProgress = (clearedLines%10) / 10.0;
    }else{
        levelProgress = (static_cast<float>(clearedLines - 5 * sumUpTo(level - 1))) / (5.0 * level);
    }
}

int gameBoard::movePiece(short dy, short dx) {
    bool pieceFlag = false;

    //Check if you can move piece
    if(dy < 0) return false;
    for(int i = 0; i < PIECE_SEGMENTS; i++){
        pieceFlag = false;

        if(isTileViable(currentPiece.positions[i].y + dy, currentPiece.positions[i].x + dx) == false) return -1;

        if(!isEmpty(currentPiece.positions[i].y + dy, currentPiece.positions[i].x + dx)){
            for(int j = 0; j < PIECE_SEGMENTS; j++){
                if(currentPiece.positions[j].y == currentPiece.positions[i].y + dy and currentPiece.positions[j].x == currentPiece.positions[i].x + dx){
                    pieceFlag = true;
                    break;
                }
            }
            if(pieceFlag == false) return -1;
        }
    }


    //Move piece
    for(int i = 0; i < PIECE_SEGMENTS; i++){
        board[currentPiece.positions[i].y][currentPiece.positions[i].x].isEmpty = true;
        currentPiece.positions[i].x += dx;
        currentPiece.positions[i].y += dy;
    }
    currentPiece.originX += dx;
    currentPiece.originY += dy;

    for(int i = 0; i < PIECE_SEGMENTS; i++){
        board[currentPiece.positions[i].y][currentPiece.positions[i].x].isEmpty = false;
        board[currentPiece.positions[i].y][currentPiece.positions[i].x].tileColor = currentPiece.pieceColor;
    }

    return 0;
}

void gameBoard::hardDrop() {
    //TODO IDK SEEMS BAD
    while(movePiece(1,0) == 0);
}

int gameBoard::holdPiece() {
    if(heldPieceThisTurn) return -1;

    for(int i = 0; i < PIECE_SEGMENTS; i++){
        board[currentPiece.positions[i].y][currentPiece.positions[i].x].isEmpty = true;
    }

    if(isHoldingPiece){
        enum color tmp;
        tmp = getHeldColor();
        heldPiece = currentPiece.pieceColor;
        spawnCurrentPiece(tmp);
    }else{
        heldPiece = currentPiece.pieceColor;
        spawnCurrentPiece(getNextPieces()[0]);
        generateNextPiece();
        isHoldingPiece = true;
    }
    heldPieceThisTurn = true;
    return 0;
}

int gameBoard::clearLines() {
    std::vector<unsigned short> indexes;
    indexes = findCompleteLines();

    if(indexes.size() == 0) return -1;

    unsigned short scoreMult[4] = {1,3,5,8};

    score += scoreMult[(indexes.size()-1)] * 100;

    for(int i = 0; i < indexes.size(); i++){
        for(int k = indexes[i]; k > 0; k--){
            for(int l = 0; l < BOARD_WIDTH; l++){
                board[k][l] = board[k-1][l];
            }
        }
        clearedLines++;
    }


    return 0;
}

int gameBoard::rotatePiece(int degrees) {
    //TODO ADD WALL BOUNCING
    // LOW PRIORITY!!!
    std::vector<position> newPositions;
    float x0 = 0, y0 = 0, pi = 3.1415926;;
    float newX = 0, newY = 0;
    int intX = 0, intY = 0;
    double radians = pi/180 * degrees;

    for(int i = 0; i < PIECE_SEGMENTS; i++){
        x0 = currentPiece.positions[i].x - currentPiece.originX;
        y0 = currentPiece.positions[i].y - currentPiece.originY;

        newX = x0 * cos(radians) - y0 * sin(radians);
        newY = x0 * sin(radians) + y0 * cos(radians);

        newX += currentPiece.originX;
        newY += currentPiece.originY;

        intX = roundl(newX);
        intY = roundl(newY);

        if(isTileViable(intY, intX) == false) return -1;

        newPositions.emplace_back(intY,intX);
    }

    for(int i = 0; i < PIECE_SEGMENTS; i++){
        board[currentPiece.positions[i].y][currentPiece.positions[i].x].isEmpty = true;
    }

    currentPiece.positions = newPositions;

    for(int i = 0; i < PIECE_SEGMENTS; i++){
        board[currentPiece.positions[i].y][currentPiece.positions[i].x].tileColor = currentPiece.pieceColor;
        board[currentPiece.positions[i].y][currentPiece.positions[i].x].isEmpty = false;
    }

    return 0;
}

int gameBoard::processGame() {
    clearLines();
    updateLevel();
    updateLevelProgress();
    if(spawnCurrentPiece(nextPieces[0]) == -1) return -1;
    generateNextPiece();

    return 0;
}

//============//Helpers//============//
bool gameBoard::movePieceUp() {
    for(int i = 0; i < PIECE_SEGMENTS; i++){

        if(currentPiece.pieceColor == CYAN and currentPiece.positions[i].y == 1){
            return false;
        }
        if(currentPiece.positions[i].y == 0){
            return false;
        }
    }

    for(int i = 0; i < PIECE_SEGMENTS; i++){
        currentPiece.positions[i].y -= 1;
    }
    currentPiece.originY -=1;
    return true;
}

bool gameBoard::canPlacePiece() {
    for(int i = 0; i < PIECE_SEGMENTS; i++){
        if(!isEmpty(currentPiece.positions[i].y, currentPiece.positions[i].x)){
            return false;
        }
    }
    return true;
}

unsigned short gameBoard::sumUpTo(unsigned short x) {
    int y = 0;
    for(int i = 1; i <= x; i++){
        y += i;
    }
    return  y;
}

std::vector<unsigned short> gameBoard::findCompleteLines() {
    std::vector<unsigned short> fullLineIndexes;
    bool lineFullFlag = true;

    for(int i = 1; i < BOARD_HEIGHT; i++){
        lineFullFlag = true;
        for(int j = 0; j < BOARD_WIDTH; j++){
            if(isEmpty(i,j)){
                lineFullFlag = false;
                break;
            }
        }

        if(lineFullFlag){
            fullLineIndexes.push_back(i);
        }
    }

    return fullLineIndexes;
}

bool gameBoard::isTileViable(int y, int x) {
    if(x < 0 or x > 9) return false;
    if(y < 0 or y > 20) return false;

    bool isPartPieceFlag = false;

    if(isEmpty(y,x) == false){
        for(int i = 0; i < PIECE_SEGMENTS; i++){
            if(x == currentPiece.positions[i].x and y == currentPiece.positions[i].y){
                isPartPieceFlag = true;
                break;
            }
        }
        if(isPartPieceFlag == false) return false;
    }


    return true;
}

std::vector<enum color> gameBoard::generateColorVector() {
    std::vector<enum color> shuffledColors;
    std::vector<enum color> possibleColors = {RED, WHITE, YELLOW, GREEN, BLUE, VIOLET, CYAN};
    int index = 0;

    for(int i = 6; i >= 0; i--){
        //randomize index from i+1;
        index = rand()%(i + 1);
        //push form possible colors to shuffled colors;
        shuffledColors.emplace_back(possibleColors[index]);
        //rm form possible colors
        possibleColors.erase(possibleColors.begin() + index);
    }

    return shuffledColors;
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

float gameBoard::getLevelProgress() const {
    return levelProgress;
}







