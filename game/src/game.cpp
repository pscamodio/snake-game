#include "game.h"
#include <raylib.h>

Game::Game()
{
    // Initialize the window with settings
    InitWindow(m_settings.screenWidth, m_settings.screenHeight, m_settings.windowTitle);
    SetWindowState(FLAG_WINDOW_RESIZABLE);
}

Game::~Game()
{
    CloseWindow();
}

void Game::run()
{
    while (!WindowShouldClose())
    {
        m_settings.screenWidth = GetScreenWidth();
        m_settings.screenHeight = GetScreenHeight();
        BeginDrawing();
        ClearBackground(RAYWHITE);
        // Draw game content here
        EndDrawing();
    }
}
