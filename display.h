//
// Created by hubert on 6/16/24.
//

#ifndef FTXUI_TEST_GAMEDEBUGDISPLAY_H
#define FTXUI_TEST_GAMEDEBUGDISPLAY_H
#include "gameBoard.h"
#include <cstdio>                 // for getchar
#include <ftxui/dom/elements.hpp>  // for operator|, size, Element, text, hcenter, Decorator, Fit, WIDTH, hflow, window, EQUAL, GREATER_THAN, HEIGHT, bold, border, dim, LESS_THAN
#include <ftxui/screen/screen.hpp>  // for Full, Screen
#include <string>  // for allocator, char_traits, operator+, to_string, string


#include "ftxui/dom/node.hpp"      // for Render
#include "ftxui/screen/color.hpp"

class gameDebugDisplay {
    gameBoard &game;

public:
    //======//Debug//======//
    explicit gameDebugDisplay(gameBoard &game);


    //======//Elements//======//
    static ftxui::Element heldPieceDisplay(enum color pieceColor);
    static ftxui::Element gameInfoDisplay(unsigned int level, float levelProgress, unsigned int score, unsigned short lines);
    static ftxui::Element gameBoardDisplay();

    //======//Display//======//
    static void gameDisplay();
};


#endif //FTXUI_TEST_GAMEDEBUGDISPLAY_H
