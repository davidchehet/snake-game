#include <iostream>
#include <raylib.h>

int main()
{
    InitWindow(800, 600, "Raylib + Clang test");
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("It works!", 320, 280, 20, BLACK);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}