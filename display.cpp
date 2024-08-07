//
// Created by hubert on 6/16/24.
//

#include "display.h"
#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/component/component.hpp"


display::display(gameBoard &game): game(game) {

}

//============//Elements//============//
ftxui::Element display::heldPieceDisplay(enum color pieceColor, bool isHoldingPiece) {
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
            case CYAN:
                pieceShape = vbox(
                        separatorEmpty(),
                        separatorEmpty(),
                        bgcolor(Color::Cyan, text("        "))
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
            case BLUE:
                pieceShape = vbox(
                        separatorEmpty(),
                        hbox(text(" "),bgcolor(Color::Blue, text("    "))),
                        hbox(text(" "),bgcolor(Color::Blue, text("  "))),
                        hbox(text(" "),bgcolor(Color::Blue, text("  ")))
                );
        }
        return window(text("HOLD") | hcenter | bold,
                      pieceShape | hcenter ) |
                      size(WIDTH, EQUAL, 12) | size(HEIGHT, EQUAL, 7);
    };
    if(isHoldingPiece){
        return makeBoxHold(pieceColor);
    }else return window(text("HOLD") | hcenter | bold,
                        separatorEmpty() )|
                 size(WIDTH, EQUAL, 12) | size(HEIGHT, EQUAL, 7);
}


ftxui::Element display::gameInfoDisplay(unsigned int level, float levelProgress, unsigned int score, unsigned short lines) {
    using namespace ftxui;

    return hbox({
        //eparatorEmpty(),
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

ftxui::Element display::gameBoardDisplay() {
    using namespace ftxui;
    const char *block = "    ";
    std::vector<Element> elementsLine;
    std::vector<Element> elementsGrid;

    for(int i = 1; i < 21; i++) {
        for (int j = 0; j < 10; j++) {
            if (game.isEmpty(i, j)) {
                elementsLine.emplace_back(text(block));
            } else {
                switch (game.getColor(i, j)) {
                    case RED:
                        elementsLine.emplace_back(bgcolor(Color::Red, text(block)));
                        break;
                    case WHITE:
                        elementsLine.emplace_back(bgcolor(Color::White, text(block)));
                        break;
                    case YELLOW:
                        elementsLine.emplace_back(bgcolor(Color::Yellow, text(block)));
                        break;
                    case GREEN:
                        elementsLine.emplace_back(bgcolor(Color::Green, text(block)));
                        break;
                    case BLUE:
                        elementsLine.emplace_back(bgcolor(Color::Blue, text(block)));
                        break;
                    case VIOLET:
                        elementsLine.emplace_back(bgcolor(Color::Violet, text(block)));
                        break;
                    case CYAN:
                        elementsLine.emplace_back(bgcolor(Color::Cyan, text(block)));
                        break;
                }
            }
        }
        elementsGrid.emplace_back(hbox(elementsLine) | size(HEIGHT, EQUAL, 2));
        //elementsGrid.emplace_back(hbox(elementsLine));
        elementsLine.clear();
    }
    return vbox(elementsGrid) | border | size(WIDTH, EQUAL, 42) | size(HEIGHT, EQUAL, 42);
}

ftxui::Element display::nextPiecesDisplay(std::vector<enum color> nextColors) {
    using namespace ftxui;
    std::vector<Element> piece;
    std::vector<Element> piecesCol;
    //enum color colors[3] = {VIOLET, YELLOW, WHITE};
    for(int i = 0; i < 3; i++){
        piece.emplace_back(separatorEmpty());
        switch(nextColors[i]){
            case RED:
                piece.emplace_back(hbox(text("     "),bgcolor(Color::Red, text("  "))));
                piece.emplace_back(hbox(text("   "),bgcolor(Color::Red, text("    "))));
                piece.emplace_back(hbox(text("   "),bgcolor(Color::Red, text("  "))));
                break;
            case WHITE:
                piece.emplace_back(hbox(text("   "),bgcolor(Color::White, text("    "))));
                piece.emplace_back(hbox(text("     "),bgcolor(Color::White, text("  "))));
                piece.emplace_back(hbox(text("     "),bgcolor(Color::White, text("  "))));
                break;
            case YELLOW:
                piece.emplace_back(separatorEmpty());
                piece.emplace_back(hbox(text("   "),bgcolor(Color::Yellow, text("    "))));
                piece.emplace_back(hbox(text("   "),bgcolor(Color::Yellow, text("    "))));
                break;
            case GREEN:
                piece.emplace_back(hbox(text("   "),bgcolor(Color::Green, text("  "))));
                piece.emplace_back(hbox(text("   "),bgcolor(Color::Green, text("    "))));
                piece.emplace_back(hbox(text("     "),bgcolor(Color::Green, text("  "))));
                break;
            case CYAN:
                piece.emplace_back(separatorEmpty());
                piece.emplace_back(hbox(text(" "),bgcolor(Color::Cyan, text("        "))));
                piece.emplace_back(separatorEmpty());
                break;
            case VIOLET:
                piece.emplace_back(hbox(text("   "),bgcolor(Color::Magenta, text("  "))));
                piece.emplace_back(hbox(text("   "),bgcolor(Color::Magenta, text("    "))));
                piece.emplace_back(hbox(text("   "),bgcolor(Color::Magenta, text("  "))));
                break;
            case BLUE:
                piece.emplace_back(hbox(text("   "),bgcolor(Color::Blue, text("    "))));
                piece.emplace_back(hbox(text("   "),bgcolor(Color::Blue, text("  "))));
                piece.emplace_back(hbox(text("   "),bgcolor(Color::Blue, text("  "))));
                break;
        }
        piece.emplace_back(separatorEmpty());
        piecesCol.emplace_back(vbox(piece));
        piece.clear();
    }


    return window(text("NEXT") | hcenter | bold,
                  vbox(piecesCol)) |
           size(WIDTH, EQUAL, 12) | size(HEIGHT, EQUAL, 17);
}

//============//Display//============//
std::shared_ptr<ftxui::Node> display::gameDisplay() {
    using namespace ftxui;

    auto info = vbox({
        separatorEmpty(),
        separatorEmpty(),
        separatorEmpty(),
        heldPieceDisplay(game.getHeldColor(), game.getIsHoldingPiece()),
        separatorEmpty(),
        gameInfoDisplay(game.getLevel(), game.getLevelProgress(), game.getScore(), game.getClearedLines())
    });

    auto board= vbox({
        gameBoardDisplay()
    });

    auto next = vbox({
        separatorEmpty(),
        separatorEmpty(),
        separatorEmpty(),
        nextPiecesDisplay(game.getNextPieces()),
    });

    auto result = hbox({
        separatorEmpty(),
        info,
        separatorEmpty(),
        separatorEmpty(),
        separatorEmpty(),
        board,
        separatorEmpty(),
        separatorEmpty(),
        separatorEmpty(),
        next,
    });

    return result;

}

void display::runGameTest() {
    using namespace ftxui;
    auto screen = ScreenInteractive::TerminalOutput();

    auto renderer = Renderer([=] { return gameDisplay(); });
    renderer |= CatchEvent([&](Event event) {
        //Quit
        if (event == Event::Character('q')) {
            screen.ExitLoopClosure()();
            return true;
        }
        //Movement
        if (event == Event::ArrowDown){
            game.movePiece(1,0);
            return true;
        }
        if (event == Event::ArrowRight){
            game.movePiece(0,1);
            return true;
        }
        if (event == Event::ArrowLeft){
            game.movePiece(0,-1);
            return true;
        }
        if (event == Event::Character(' ')){
            game.hardDrop();
            game.processGame();
            return true;
        }
        //Rotation
        if (event == Event::ArrowUp){
            game.rotatePiece(90);
            return true;
        }
        if (event == Event::Character('z')) {
            game.rotatePiece(-90);
            return true;
        }
        //Hold
        if (event == Event::Character('c')) {
            game.holdPiece();
            return true;
        }


        return false;
    });
    screen.Loop(renderer);
}



