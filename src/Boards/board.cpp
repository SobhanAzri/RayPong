//
// Created by nryxenon on 12/4/25.
//

#include "raylib.h"
#include "Boards/board.h"
#include "Ball/ball.h"

void Board::drawBoard() {

    mainBody = Rectangle{position.x,position.y,scale.x,scale.y};

        DrawRectangleRounded(
        mainBody,
        .25f,
        0,
        BLACK
        );
}

void Board::limitMovement() {
    if ((position.y >= 18))
        setMoveUp(true);
    else
        setMoveUp(false);

    if ((position.y + (scale.y)) <= static_cast<float>(GetScreenHeight() - 18))
        setMoveDown(true);
    else
        setMoveDown(false);
}
