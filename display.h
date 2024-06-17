//
// Created by hubert on 6/16/24.
//

#ifndef FTXUI_TEST_DISPLAY_H
#define FTXUI_TEST_DISPLAY_H
#include "gameBoard.h"
#include <cstdio>                 // for getchar
#include <ftxui/dom/elements.hpp>  // for operator|, size, Element, text, hcenter, Decorator, Fit, WIDTH, hflow, window, EQUAL, GREATER_THAN, HEIGHT, bold, border, dim, LESS_THAN
#include <ftxui/screen/screen.hpp>  // for Full, Screen
#include <string>  // for allocator, char_traits, operator+, to_string, string
#include <cmath>

#include "ftxui/dom/node.hpp"      // for Render
#include "ftxui/screen/color.hpp"
#include "ftxui/screen/color_info.hpp"

class display {
    gameBoard &game;

public:
    //======//Debug//======//
    explicit display(gameBoard &game);




    //======//Elements//======//
    static ftxui::Element heldPieceDisplay(enum color pieceColor, bool isHoldingPiece);
    static ftxui::Element gameInfoDisplay(unsigned int level, float levelProgress, unsigned int score, unsigned short lines);
    ftxui::Element gameBoardDisplay();
    static ftxui::Element nextPiecesDisplay(std::vector<enum color> nextColors);

    //======//Display//======//
    void gameDisplay();
};


#endif //FTXUI_TEST_DISPLAY_H
