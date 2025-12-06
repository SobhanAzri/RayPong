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
      speed(inputSpeed),
      baseSpeed(inputSpeed) { }

    virtual ~Board() = default;

    virtual void drawBoard();
    virtual void updatePosition() = 0;
    virtual void limitMovement();

    [[nodiscard]] inline Rectangle getMainBody() const { return mainBody; }
    [[nodiscard]] inline Vector2 getPosition() const { return position; }

    inline void setMoveUp(bool canMove) { bCanMoveUp = canMove;}
    inline void setMoveDown(bool canMove) {bCanMoveDown = canMove;}
    [[nodiscard]] bool canMoveUp() const { return bCanMoveUp;}
    [[nodiscard]] bool canMoveDown() const { return bCanMoveDown;}

    inline void setSpeed(const float &newSpeed) { speed = newSpeed; }
    [[nodiscard]] inline float getSpeed() const { return speed; }
    [[nodiscard]] inline float getBaseSpeed() const { return baseSpeed; }

protected:
    Rectangle mainBody;

    Vector2 position = {0,0};
    Vector2 scale = {0,0};
    float baseSpeed = 0;
    float speed = 0;

    bool bCanMoveUp = true;
    bool bCanMoveDown = true;
};

#endif //RAYPONG_BOARD_H