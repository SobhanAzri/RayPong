//
// Created by nryxenon on 12/4/25.
//

#include "raylib.h"
#include "Boards/playerBoard.h"

void PlayerBoard::updatePosition() {

    if (IsKeyDown(KEY_UP) && canMoveUp())
        position.y -= speed;
    if (IsKeyDown(KEY_DOWN) && canMoveDown())
        position.y += speed;

    drawBoard();

    limitMovement();
}

void PlayerBoard::drawBoard() {
    Board::drawBoard();

    DrawRectangleRoundedLinesEx(
        Rectangle{position.x ,position.y, scale.x , scale.y},
        .75f,
        0,
        5,
        LIME
        );
}
