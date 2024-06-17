//
// Created by hubert on 6/16/24.
//

#include "gameDebugDisplay.h"
#include "ftxui/component/screen_interactive.hpp"


gameDebugDisplay::gameDebugDisplay(gameBoard &game): game(game) {

}

ftxui::Element gameDebugDisplay::heldPieceDisplay(enum color pieceColor) {
    using namespace ftxui;
    auto makeBoxHold = [](enum color pieceColor) {
        auto pieceShape = vbox();
        switch(pieceColor){
            case RED:
                pieceShape = vbox(
                        separatorEmpty(),
                        hbox(text("   "),bgcolor(Color::Red, text("  "))),
                        hbox(text(" "),bgcolor(Color::Red, text("    "))),
                        hbox(text(" "),bgcolor(Color::Red, text("  ")))
                );
                break;
            case WHITE:
                pieceShape = vbox(
                        separatorEmpty(),
                        hbox(text(" "),bgcolor(Color::White, text("    "))),
                        hbox(text("   "),bgcolor(Color::White, text("  "))),
                        hbox(text("   "),bgcolor(Color::White, text("  ")))
                );
                break;
            case YELLOW:
                pieceShape = vbox(
                        separatorEmpty(),
                        separatorEmpty(),
                        hbox(text(" "),bgcolor(Color::Yellow, text("    "))),
                        hbox(text(" "),bgcolor(Color::Yellow, text("    ")))
                );
                break;
            case GREEN:
                pieceShape = vbox(
                        separatorEmpty(),
                        hbox(text(" "),bgcolor(Color::Green, text("  "))),
                        hbox(text(" "),bgcolor(Color::Green, text("    "))),
                        hbox(text("   "),bgcolor(Color::Green, text("  ")))
                );
                break;
            case BLUE:
                pieceShape = vbox(
                        separatorEmpty(),
                        separatorEmpty(),
                        bgcolor(Color::Blue, text("        "))
                );
                break;
            case VIOLET:
                pieceShape = vbox(
                        separatorEmpty(),
                        hbox(text(" "),bgcolor(Color::Magenta, text("  "))),
                        hbox(text(" "),bgcolor(Color::Magenta, text("    "))),
                        hbox(text(" "),bgcolor(Color::Magenta, text("  ")))
                );
                break;
        }
        return window(text("HOLD") | hcenter | bold,
                      pieceShape | hcenter ) |
                      size(WIDTH, EQUAL, 12) | size(HEIGHT, EQUAL, 7);
    };
    return makeBoxHold(pieceColor);

}

ftxui::Element gameDebugDisplay::gameInfoDisplay(unsigned int level, float levelProgress, unsigned int score, unsigned short lines) {
    using namespace ftxui;

    return hbox({
        separatorEmpty(),
        separatorEmpty(),
        vbox({
            window(text("LEVEL") | hcenter | bold,
                   text(std::to_string(level)) | hcenter ) |
                   size(WIDTH, EQUAL, 8) | size(HEIGHT, EQUAL, 3),
            hbox({
                separatorEmpty(),
                separatorEmpty(),
                separatorEmpty(),
                hbox({
                    //No clue how to make it wider
                    gaugeUp(levelProgress) | size(WIDTH, EQUAL, 5),
                    gaugeUp(levelProgress) | size(WIDTH, EQUAL, 5)
                })|  border | size(WIDTH, EQUAL, 4) | size(HEIGHT, EQUAL, 15),
            })| size(WIDTH, EQUAL, 8),
            separatorEmpty(),
            window(text("SCORE") | hcenter | bold,text(std::to_string(score))
                   | hcenter ) | size(WIDTH, EQUAL, 8) | size(HEIGHT, EQUAL, 3),
            window(text("LINES") | hcenter | bold,text(std::to_string(lines))
            | hcenter ) |size(WIDTH, EQUAL, 10) | size(HEIGHT, EQUAL, 3),
        })
    });

}

ftxui::Element gameDebugDisplay::gameBoardDisplay() {
    return ftxui::Element();
}

//============//Display//============//
void gameDebugDisplay::gameDisplay() {
    using namespace ftxui;
    /*
    auto pieceDisplayTest = hbox({
        heldPieceDisplay(RED),
        heldPieceDisplay(WHITE),
        heldPieceDisplay(YELLOW),
        heldPieceDisplay(GREEN),
        heldPieceDisplay(BLUE),
        heldPieceDisplay(VIOLET),
    });
    */

    auto result = vbox({
        heldPieceDisplay(RED),
        separatorEmpty(),
        gameInfoDisplay(1, 0.8, 420, 69)
    });


    auto screen = Screen::Create(Dimension::Full(), Dimension::Fit(result));
    Render(screen, result);
    screen.Print();
}


