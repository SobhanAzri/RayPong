#ifndef RAYPONG_BALL_H
#define RAYPONG_BALL_H

#include "raylib.h"
#include "Boards/cpuBoard.h"

class ScoreSystem; // i forward declared the Score System and i didnt include it in the header file
class Board;
class CPUBoard;

class Ball {
public:
    Ball() = default;
    Ball(const Vector2 &position, const Vector2 &velocity, const int &radius, Board *playerBoard, CPUBoard *cpuBoard);
    ~Ball() = default;

    void initBall(const Vector2 &position, const Vector2 &velocity, const int &radius, Board *playerBoard, CPUBoard *cpuBoard);
    void drawBall();

    void hitSurface();
    void hitGoal();

    void updateMovement();
    void stopBall();
    void resetBall();

    // Setters & Getters for Attributes

    inline void setPosition(const Vector2 &position) { this->position = position; }
    [[nodiscard]] Vector2 getPosition() const {return this->position;};

    inline void setVelocity(const Vector2 &velocity) {
        this->velocity = velocity;
    }
    [[nodiscard]] Vector2 getVelocity() const {return this->velocity;}

    inline void setRadius(const float &value) {radius = value;}
    [[nodiscard]] inline float getRadius() const {return radius;}

protected:
    ScoreSystem *scoreSystem;

    Board *playerBoard;
    CPUBoard *cpuBoard;

    Vector2 position;
    Vector2 velocity;
    float radius;

private:
};

#endif