#ifndef RAYPONG_BALL_H
#define RAYPONG_BALL_H

#include "raylib.h"

class ScoreSystem; // i forward declared the Score System and i didnt include it in the header file

class Ball {
public:
    Ball() = default;
    Ball(const Vector2 &position, const Vector2 &velocity, const int &radius);
    ~Ball() = default;

    void initBall(const Vector2 &position, const Vector2 &velocity, const int &radius);
    void drawBall();

    void hitSurface();
    void hitGoal();

    void updateMovement();
    void stopBall();
    void resetBall();

    // Setters & Getters for Attributes

    inline void setPosition(const Vector2 &position) { this->position = position; }
    inline Vector2 getPosition() const {return this->position;};

    inline void setVelocity(const Vector2 &velocity) {
        this->velocity = velocity;
    }
    inline Vector2 getVelocity() const {return this->velocity;}

    inline void setRadius(const float &value) {radius = value;}
    inline float getRadius() const {return radius;}

protected:
    ScoreSystem *scoreSystem;

    Vector2 position;
    Vector2 velocity;
    float radius;

private:
};

#endif