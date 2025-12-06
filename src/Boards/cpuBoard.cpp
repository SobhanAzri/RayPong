//
// Created by nryxenon on 12/4/25.
//

#include "Boards/cpuBoard.h"

void CPUBoard::updatePosition() {

    trackPosition();
    drawBoard();
    limitMovement();
}

void CPUBoard::drawBoard() {
    Board::drawBoard();

    DrawRectangleRoundedLinesEx(
        Rectangle{position.x ,position.y, scale.x , scale.y},
        .75f,
        0,
        5,
        PINK
        );
}

void CPUBoard::trackPosition() {
    if ((position.y + scale.y / 2) > targetPositionY && canMoveUp())
        position.y -= speed;
    else if ((position.y + scale.y / 2) < targetPositionY && canMoveDown())
        position.y += speed;
}

void CPUBoard::setTargetPosition(const float &target) {
    if (followTargetPosition == true)
    {this->targetPositionY = target;}
}
