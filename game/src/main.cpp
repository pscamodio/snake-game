#include "settings.h"
#include <raylib.h>

int main()
{
    const auto settings = Settings{};
    InitWindow(settings.screenWidth, settings.screenHeight, settings.windowTitle);
    SetWindowState(FLAG_WINDOW_RESIZABLE);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        // Draw game content here
        EndDrawing();
    }
    return 0;
}
