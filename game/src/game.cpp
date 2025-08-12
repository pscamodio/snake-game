#include "game.h"
#include "scenes/menu/menu.h"
#include "scenes/scene.h"
#include <raylib.h>

Game::Game()
{
    // Initialize the window with settings
    InitWindow(m_settings.screenWidth, m_settings.screenHeight, m_settings.windowTitle);
    SetWindowState(FLAG_WINDOW_RESIZABLE);
    m_currentScene = std::make_unique<Menu>();
}

Game::~Game()
{
    CloseWindow();
}

void Game::run()
{
    while (!WindowShouldClose())
    {
        this->changeSceneIfNeeded();
        m_settings.screenWidth = GetScreenWidth();
        m_settings.screenHeight = GetScreenHeight();
        BeginDrawing();
        ClearBackground(RAYWHITE);
        m_currentScene->update(*this, GetFrameTime());
        m_currentScene->render(*this);
        EndDrawing();
    }
}

void Game::queueSceneChange(std::unique_ptr<Scene> newScene)
{
    m_nextScene.swap(newScene);
}

void Game::changeSceneIfNeeded()
{
    if (m_nextScene)
    {
        m_currentScene.swap(m_nextScene);
        m_nextScene.reset();
    }
}

auto Game::settings() const -> const Settings &
{
    return m_settings;
}
