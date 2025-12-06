#include "Ball/ball.h"

#include <random>
#include "raylib.h"
#include "scoreSystem.h"
#include "Boards/board.h"
#include "Boards/cpuBoard.h"

Ball::Ball(const Vector2 &position, const Vector2 &velocity, const int &radius, Board *playerBoard, CPUBoard *cpuBoard) {
    initBall(position, velocity, radius, playerBoard, cpuBoard);
}

void Ball::initBall(const Vector2 &position, const Vector2 &velocity, const int &radius, Board *playerBoard, CPUBoard *cpuBoard) {
    setPosition(position);
    setVelocity(velocity);
    setRadius(radius);

    this->playerBoard = playerBoard;
    this->cpuBoard = cpuBoard;

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

    if (CheckCollisionCircleRec(position,radius,cpuBoard->getMainBody()))
        velocity.x *= -1;
    else if (CheckCollisionCircleRec(position,radius,playerBoard->getMainBody()))
        velocity.x *= -1;

    // if (position.x + radius == cpuBoard->getMainBody().x - cpuBoard->getMainBody().width) {
    //     if (position.y >= cpuBoard->getMainBody().y || position.y <= cpuBoard->getMainBody().y + cpuBoard->getMainBody().height)
    //         velocity.x *= -1;
    // }
    // if (position.x - radius == playerBoard->getMainBody().x + playerBoard->getMainBody().width) {
    //     // if (position.y >= playerBoard->getMainBody().y || position.y <= playerBoard->getMainBody().y + playerBoard->getMainBody().height)
    //          velocity.x *= -1;
    // }

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
    setPosition({position.x + velocity.x, position.y + velocity.y});

    drawBall();

   // if (cpuBoard->canFollowTarget())
        cpuBoard->setTargetPosition(getPosition().y);

    hitSurface();
    hitGoal();
}

void Ball::stopBall() {
    setVelocity({0,0});

    cpuBoard->setFollowTarget(false);
    cpuBoard->setSpeed(0);

    resetBall();
}

void Ball::resetBall() {

    std::random_device randomGenerator;

    setPosition({static_cast<float>(GetScreenWidth() / 2),static_cast<float>(GetScreenHeight() / 2)});
    setVelocity({static_cast<float>(randomGenerator() % 10) + 10 , static_cast<float>(randomGenerator() % 10) + 10});

    cpuBoard->setFollowTarget(true);
    cpuBoard->setSpeed(cpuBoard->getBaseSpeed());
}
