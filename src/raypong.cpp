#include "raylib.h"
#include "Boards/playerBoard.h"
#include "Ball/ball.h"


#define WINDOW_WIDTH GetMonitorWidth(0)
#define WINDOW_HEIGHT GetMonitorHeight(0)

void initializeWindow();
void drawField();

int main() {
    initializeWindow();

    Ball ball({static_cast<float>(WINDOW_WIDTH / 2), static_cast<float>(WINDOW_HEIGHT / 2)},
              {-10,10}, 15);

    Vector2 playerScale = {25,120};
    Vector2 playerPosition = {playerScale.x + 10 , static_cast<float>(WINDOW_HEIGHT / 2) };
    PlayerBoard playerBoard(playerPosition,playerScale,10);

    while (!WindowShouldClose()) {

        drawField();
        ball.updateMovement();
        playerBoard.updatePosition();
    }

    CloseWindow();

    return 0;
}

void initializeWindow() {
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "hello");
    ToggleFullscreen();
    SetTargetFPS(60);

}
void drawField() {
    BeginDrawing();

    ClearBackground(LIGHTGRAY);
    //DrawLine(WINDOW_WIDTH / 2, 0, WINDOW_WIDTH / 2, WINDOW_HEIGHT, WHITE);
    DrawCircleLines(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, 150, BLACK);
    DrawLine(WINDOW_WIDTH / 2 , 0 , WINDOW_WIDTH / 2 , WINDOW_HEIGHT, BLACK);

    EndDrawing();
}