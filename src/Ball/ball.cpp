#include "Ball/ball.h"
#include "Colors.h"
#include "scoreSystem.h"

Ball::Ball(const Vector2 &position, const Vector2 &velocity, const int &radius) {
    initBall(position, velocity, radius);
}

void Ball::initBall(const Vector2 &position, const Vector2 &velocity, const int &radius) {
    setPosition(position);
    setVelocity(velocity);
    setRadius(radius);

    scoreSystem = new ScoreSystem();
}
void Ball::drawBall() {
    DrawCircleV(getPosition(), getRadius(), BLACK);
    DrawCircleV(getPosition(), getRadius() / 1.5 , RED);
    DrawCircleV(getPosition(), getRadius() / 3, BLACK);
}

void Ball::hitSurface() {
    // if ball's (y position +- scale) goes below or higher than the screen's vertical bounds then it hits the walls

    if ((position.y + radius) >= static_cast<float>(GetScreenHeight()) || position.y < 0) {
        velocity.y *= -1;
    }



}

void Ball::hitGoal() {
    // if ball's (x position +- radius) goes further than the screen then its Goal

    if ((position.x + radius) >= static_cast<float>(GetScreenWidth())) {
        scoreSystem->addPlayerScore();
        stopBall();
    }
    else if ((position.x - radius) <= 0 ) {
        scoreSystem->addCpuScore();
        stopBall();
    }
}

void Ball::updateMovement() {
    position.x += velocity.x;
    position.y += velocity.y;

    drawBall();
    hitSurface();
    hitGoal();
}

void Ball::stopBall() {
    setVelocity({0,0});

    resetBall();
}

void Ball::resetBall() {
}
