#include <iostream>
#include <raylib.h>

using namespace std;

// R, G, B, Transparency
Color green = {173, 204, 96, 255};
Color darkGreen = {43, 51, 24, 255};

// Set Up a Grid
int cellSize = 30;
int cellCount = 25;

// Snake Class

// Food Class
class Food
{
public:
    Vector2 position;
    Texture2D texture;

    // Constructor
    Food()
    {
        Image image = LoadImage("graphics/food.png");
        texture = LoadTextureFromImage(image);
        UnloadImage(image); // Frees memory
        position = GenerateRandomPos();
    }

    // Destructor
    ~Food()
    {
        UnloadTexture(texture);
    }

    void Draw()
    {
        DrawTexture(texture, position.x * cellSize, position.y * cellSize, WHITE);
    }

    Vector2 GenerateRandomPos()
    {
        float x = GetRandomValue(0, cellCount - 1);
        float y = GetRandomValue(0, cellCount - 1);

        return Vector2{x, y};
    }
};

int main () 
{
    cout << "Starting the game..." << endl;

    // Create Game Window
    InitWindow(cellSize * cellCount, cellSize * cellCount, "Retro Snake");
    SetTargetFPS(60);

    Food food = Food();

    // Game Loop
    while (WindowShouldClose() == false)
    {
        BeginDrawing();

        ClearBackground(green);
        food.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}