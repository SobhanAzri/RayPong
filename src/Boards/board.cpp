//
// Created by nryxenon on 12/4/25.
//

#include "raylib.h"
#include "Boards/board.h"
#include "Colors.h"

void Board::drawBoard() {

    DrawRectangleRounded(
        Rectangle{position.x,position.y, scale.x, scale.y},
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
