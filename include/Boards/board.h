#ifndef RAYPONG_BOARD_H
#define RAYPONG_BOARD_H

#include "raylib.h"

class Ball; // forward decleration of Ball class

// i wrote this abstract class and i will make my player and cpu boards inherit from this class

class Board {
public:
    Board() = default;

    Board(const Vector2 &inputPosition, const Vector2 &inputScale, const float &inputSpeed)
    : position(inputPosition),
      scale(inputScale),
      speed(inputSpeed) {}

    virtual ~Board() = default;

    virtual void drawBoard();
    virtual void updatePosition() = 0;
    virtual void limitMovement();

    inline void setMoveUp(bool canMove) { bCanMoveUp = canMove;}
    inline void setMoveDown(bool canMove) {bCanMoveDown = canMove;}
    [[nodiscard]] bool canMoveUp() const { return bCanMoveUp;}
    [[nodiscard]] bool canMoveDown() const { return bCanMoveDown;}

protected:
    Vector2 position = {0,0};
    Vector2 scale = {0,0};
    float speed = 0;

    bool bCanMoveUp = true;
    bool bCanMoveDown = true;
};

#endif //RAYPONG_BOARD_H